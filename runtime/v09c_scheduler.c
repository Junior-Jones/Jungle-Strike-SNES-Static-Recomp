#include <string.h>
#include "jungle/scheduler_v09c.h"

static void js_v09c_log(js_scheduler_v09c *s, js_event_type_v09c type, uint16_t detail) {
    js_event_record_v09c *e;
    size_t index;
    if (!s || type == JS_EVENT_V09C_NONE) return;
    index = s->event_log_next;
    e = &s->event_log[index];
    e->master_clock = s->master_clock;
    e->scanline = s->scanline;
    e->hclock = s->hclock;
    e->field = s->field;
    e->type = (uint8_t)type;
    e->detail = detail;
    s->event_log_next = (index + 1u) % JS_V09C_EVENT_LOG_CAPACITY;
    if (s->event_log_count < JS_V09C_EVENT_LOG_CAPACITY) s->event_log_count++;
}

const js_event_record_v09c *js_scheduler_v09c_event_at(const js_scheduler_v09c *s, size_t logical_index) {
    size_t oldest;
    if (!s || logical_index >= s->event_log_count) return NULL;
    oldest = (s->event_log_next + JS_V09C_EVENT_LOG_CAPACITY - s->event_log_count) % JS_V09C_EVENT_LOG_CAPACITY;
    return &s->event_log[(oldest + logical_index) % JS_V09C_EVENT_LOG_CAPACITY];
}

static void js_v09c_sync_smp(js_scheduler_v09c *s, uint32_t master_delta) {
    uint64_t numerator, delta_half_ticks;
    if (!s || master_delta == 0u) return;

    /* The APU oscillator is an independent clock domain.  Advance the selected
       deterministic profile incrementally and preserve its residual phase
       instead of recomputing a zero-phase ratio from absolute S-CPU time. */
    numerator = (uint64_t)master_delta * (uint64_t)JS_V09C_SMP_HALF_TICK_RATIO_NUMERATOR
              + (uint64_t)s->smp_clock_remainder;
    delta_half_ticks = numerator / (uint64_t)JS_V09C_SMP_HALF_TICK_RATIO_DENOMINATOR;
    s->smp_clock_remainder = (uint32_t)(numerator % (uint64_t)JS_V09C_SMP_HALF_TICK_RATIO_DENOMINATOR);
    if (delta_half_ticks != 0u) {
        s->smp_target_cycle += delta_half_ticks;
        if (s->hooks.smp_sync) s->hooks.smp_sync(s->hooks.smp_opaque, s->smp_target_cycle);
    }
}

static void js_v09c_set_irq_flag(js_scheduler_v09c *s, int value) {
    uint8_t next = (uint8_t)(value && ((s->nmitimen & 0x30u) != 0u));
    if (s->irq_flag != next) {
        s->irq_flag = next;
        js_v09c_log(s, next ? JS_EVENT_V09C_IRQ_FLAG_SET : JS_EVENT_V09C_IRQ_FLAG_CLEAR, 0u);
    }
    if (!next) s->irq_line = 0u;
}

static void js_v09c_update_irq_level(js_scheduler_v09c *s) {
    int h_enabled = (s->nmitimen & 0x10u) != 0u;
    int v_enabled = (s->nmitimen & 0x20u) != 0u;
    uint8_t level;
    if (!h_enabled && !v_enabled) {
        s->irq_level = 0u;
        return;
    }
    level = (uint8_t)((!h_enabled || s->h_timer == s->h_counter) && (!v_enabled || s->v_timer == s->v_counter));
    if (!s->irq_level && level) s->irq_need_ticks = (uint8_t)((h_enabled && s->hclock == 6u) ? 3u : 2u);
    s->irq_level = level;
}

static void js_v09c_irq_counter_tick(js_scheduler_v09c *s) {
    if (s->irq_need_ticks > 0u) {
        s->irq_need_ticks--;
        if (s->irq_need_ticks == 1u) js_v09c_set_irq_flag(s, 1);
        else if (s->irq_need_ticks == 0u) {
            s->irq_line = s->irq_flag;
            if (s->irq_line) js_v09c_log(s, JS_EVENT_V09C_IRQ_LINE_ASSERT, 0u);
        }
    }

    if (s->hclock > 10u) {
        s->h_counter++;
    } else if (s->hclock == 10u) {
        s->h_counter = 0u;
        if (s->scanline == s->vblank_start_scanline && s->hooks.ppu_event) {
            s->hooks.ppu_event(s->hooks.ppu_opaque, JS_SCHEDULER_PPU_EVENT_V09C_VBLANK_START);
        }
    } else if (s->hclock == 6u) {
        s->h_counter = 0u;
        if (s->scanline > 0u) s->v_counter++;
        if ((s->nmitimen & 0x80u) && s->scanline == s->vblank_start_scanline) {
            if (!s->nmi_pending) { s->nmi_pending = 1u; js_v09c_log(s, JS_EVENT_V09C_NMI_PENDING, 0u); }
        }
    } else if (s->hclock == 2u) {
        s->h_counter++;
        if (s->scanline == s->vblank_start_scanline) {
            if (!s->nmi_flag) {
                s->nmi_flag = 1u;
                js_v09c_log(s, JS_EVENT_V09C_NMI_FLAG_SET, 0u);
            }
        } else if (s->scanline == 0u) {
            if (s->nmi_flag) js_v09c_log(s, JS_EVENT_V09C_NMI_FLAG_CLEAR, 0u);
            s->nmi_flag = 0u;
            s->v_counter = 0u;
        }
    }
    js_v09c_update_irq_level(s);
}

static void js_v09c_process_autojoy(js_scheduler_v09c *s) {
    while (s->autojoy_next_clock != UINT64_MAX && s->master_clock >= s->autojoy_next_clock) {
        unsigned step = s->autojoy_step_index;
        uint8_t enabled = (uint8_t)((s->nmitimen & 0x01u) != 0u);
        js_v09c_log(s, JS_EVENT_V09C_AUTOJOY_STEP, (uint16_t)step);
        if (s->hooks.autojoy_step) s->hooks.autojoy_step(s->hooks.autojoy_opaque, step, enabled);
        if (step == 1u) {
            if (!enabled) {
                s->autojoy_disabled = 1u;
                s->autojoy_active = 0u;
            } else {
                s->autojoy_active = 1u;
            }
        } else if (step >= 34u) {
            s->autojoy_active = 0u;
            s->autojoy_disabled = 1u;
            s->autojoy_next_clock = UINT64_MAX;
            return;
        } else if (step >= 3u && !enabled) {
            s->autojoy_active = 0u;
            s->autojoy_disabled = 1u;
            s->autojoy_next_clock = UINT64_MAX;
            return;
        }
        s->autojoy_step_index++;
        s->autojoy_next_clock += 128u;
    }
}

static void js_v09c_schedule_autojoy_frame(js_scheduler_v09c *s) {
    uint64_t range_start = s->master_clock + 130u;
    uint64_t aligned = range_start + ((range_start & 0xFFu) ? (256u - (range_start & 0xFFu)) : 0u);
    s->autojoy_start_clock = aligned - 128u;
    s->autojoy_next_clock = s->autojoy_start_clock;
    s->autojoy_step_index = 0u;
    s->autojoy_disabled = 0u;
    s->autojoy_active = 0u;
}

static js_stop_reason js_v09c_line_event(js_scheduler_v09c *s) {
    if (s->scanline == 0u) {
        uint16_t hdma_init = (uint16_t)(12u + (s->master_clock & 7u));
        if (s->hclock == hdma_init) {
            /* Hardware requests HDMA initialization here, but the DMA controller
               observes the shared one-CPU-cycle start delay before processing it. */
            s->hdma_init_pending = 1u;
            s->dma_start_delay = 1u;
            js_v09c_log(s, JS_EVENT_V09C_HDMA_INIT, s->hdma_enable_mask);
        }
    }
    if (s->hclock == s->dram_refresh_hclock) {
        if (s->dma_advance_depth != 0u) {
            s->dma_refresh_stall_clocks += 40u;
        } else {
            s->cpu_stall_clocks += 40u;
            s->cpu_stall_kind = 1u;
        }
        js_v09c_log(s, JS_EVENT_V09C_DRAM_REFRESH_START, 40u);
    }
    if (s->hclock == 1080u && s->scanline < 224u && s->hooks.ppu_event) {
        s->hooks.ppu_event(s->hooks.ppu_opaque, JS_SCHEDULER_PPU_EVENT_V09C_VISIBLE_SCANLINE);
    }
    if (s->hclock == 1104u && s->scanline < s->vblank_start_scanline && s->hdma_enable_mask != 0u) {
        s->hdma_line_pending = 1u;
        s->dma_start_delay = 1u;
        js_v09c_log(s, JS_EVENT_V09C_HDMA_REQUEST, s->hdma_enable_mask);
    }
    return JS_STOP_NONE;
}

static void js_v09c_latch_ppu_timing(js_scheduler_v09c *s) {
    if (!s) return;
    s->ppu_overscan_latched = s->ppu_overscan_pending;
    s->ppu_interlace_latched = s->ppu_interlace_pending;
    s->vblank_start_scanline = s->ppu_overscan_latched ? 240u : JS_V09C_DEFAULT_VBLANK_START;
    /* NTSC interlace adds one scanline on the even field.  Pixel weaving and
       framebuffer geometry remain the later renderer milestone. */
    s->frame_lines = (uint16_t)((s->ppu_interlace_latched && !s->field) ? 263u : JS_V09C_BASE_FRAME_LINES);
}

static void js_v09c_finish_scanline(js_scheduler_v09c *s) {
    uint16_t completed_scanline = s->scanline;
    s->hclock = 0u;
    s->scanline++;
    if (s->scanline >= s->frame_lines) {
        s->scanline = 0u;
        s->field ^= 1u;
        s->frame_count++;
        js_v09c_log(s, JS_EVENT_V09C_FRAME_START, 0u);
        if (s->hooks.ppu_event)
            s->hooks.ppu_event(s->hooks.ppu_opaque, JS_SCHEDULER_PPU_EVENT_V09C_FRAME_START);
    }

    /* SETINI timing is sampled after scanline 0 for the current frame, matching
       the PPU's frame-level overscan/interlace latch without implementing the
       renderer's pixel-output behavior. */
    if (completed_scanline == 0u) js_v09c_latch_ppu_timing(s);

    /* Scanline 240 is short on odd non-interlaced NTSC fields. */
    s->line_clocks = (uint16_t)((s->scanline == 240u && s->field && !s->ppu_interlace_latched)
                                  ? 1360u : JS_V09C_BASE_LINE_CLOCKS);
    s->dram_refresh_hclock = (uint16_t)(538u - (s->master_clock & 7u));
    js_v09c_log(s, JS_EVENT_V09C_SCANLINE_START, s->scanline);
    if (s->scanline == s->vblank_start_scanline) js_v09c_schedule_autojoy_frame(s);
}

static js_stop_reason js_v09c_tick2(js_scheduler_v09c *s) {
    js_stop_reason r;
    s->master_clock += 2u;
    s->hclock = (uint16_t)(s->hclock + 2u);

    r = js_v09c_line_event(s);
    if (r != JS_STOP_NONE) return r;

    if ((s->hclock & 3u) == 2u) js_v09c_irq_counter_tick(s);
    js_v09c_process_autojoy(s);
    js_v09c_sync_smp(s, 2u);

    if (s->hclock >= s->line_clocks) js_v09c_finish_scanline(s);
    return JS_STOP_NONE;
}

void js_scheduler_v09c_power_on(js_scheduler_v09c *s, js_scheduler_hooks_v09c hooks) {
    if (!s) return;
    memset(s, 0, sizeof(*s));
    s->hooks = hooks;
    s->line_clocks = JS_V09C_BASE_LINE_CLOCKS;
    s->frame_lines = JS_V09C_BASE_FRAME_LINES;
    s->vblank_start_scanline = JS_V09C_DEFAULT_VBLANK_START;
    s->ppu_overscan_pending = 0u;
    s->ppu_overscan_latched = 0u;
    s->ppu_interlace_pending = 0u;
    s->ppu_interlace_latched = 0u;
    s->h_timer = 0x01FFu;
    s->v_timer = 0x01FFu;
    s->dram_refresh_hclock = 538u;
    s->autojoy_next_clock = UINT64_MAX;
    js_v09c_log(s, JS_EVENT_V09C_SCANLINE_START, 0u);
}

void js_scheduler_v09c_cpu_reset(js_scheduler_v09c *s) {
    if (!s) return;
    /* CPU RESET does not rewind the master timeline.  Clear only reset-owned
       interrupt enables/pending CPU interrupt recognition; raster/field time,
       timer latches, auto-read epoch and external event history remain live. */
    s->nmitimen = 0u;
    s->nmi_pending = 0u;
    s->irq_need_ticks = 0u;
    s->irq_level = 0u;
    s->dma_pending_mask = 0u;
    s->hdma_init_pending = 0u;
    s->hdma_line_pending = 0u;
    s->dma_start_delay = 0u;
    js_v09c_set_irq_flag(s, 0);
}

static js_stop_reason js_v09c_run_cpu_stall(js_scheduler_v09c *s) {
    while (s->cpu_stall_clocks > 0u) {
        js_stop_reason r = js_v09c_tick2(s);
        if (r != JS_STOP_NONE) return r;
        if (s->cpu_stall_clocks >= 2u) s->cpu_stall_clocks -= 2u;
        else s->cpu_stall_clocks = 0u;
        if (s->cpu_stall_clocks == 0u) {
            if (s->cpu_stall_kind == 1u) js_v09c_log(s, JS_EVENT_V09C_DRAM_REFRESH_END, 0u);
            s->cpu_stall_kind = 0u;
        }
    }
    return JS_STOP_NONE;
}

js_stop_reason js_scheduler_v09c_advance_wall(js_scheduler_v09c *s, uint32_t clocks) {
    if (!s || (clocks & 1u)) return JS_STOP_TIMING_UNAVAILABLE;
    while (clocks != 0u) {
        uint32_t stall_before = s->cpu_stall_clocks;
        js_stop_reason r = js_v09c_tick2(s);
        if (r != JS_STOP_NONE) return r;
        clocks -= 2u;
        /* A stall created at this tick begins after the event edge, so do not
           consume its first two clocks until the next master-clock tick. */
        if (stall_before != 0u && s->cpu_stall_clocks >= 2u) {
            s->cpu_stall_clocks -= 2u;
            if (s->cpu_stall_clocks == 0u) {
                if (s->cpu_stall_kind == 1u) js_v09c_log(s, JS_EVENT_V09C_DRAM_REFRESH_END, 0u);
                s->cpu_stall_kind = 0u;
            }
        }
    }
    return JS_STOP_NONE;
}

js_stop_reason js_scheduler_v09c_advance_cpu(js_scheduler_v09c *s, uint32_t active_clocks) {
    if (!s || (active_clocks & 1u)) return JS_STOP_TIMING_UNAVAILABLE;
    s->in_cpu_advance = 1u;
    while (active_clocks != 0u) {
        js_stop_reason r;
        if (s->cpu_stall_clocks != 0u) {
            r = js_v09c_run_cpu_stall(s);
            if (r != JS_STOP_NONE) { s->in_cpu_advance = 0u; return r; }
        }
        r = js_v09c_tick2(s);
        if (r != JS_STOP_NONE) { s->in_cpu_advance = 0u; return r; }
        active_clocks -= 2u;
        if (s->cpu_stall_clocks != 0u) {
            r = js_v09c_run_cpu_stall(s);
            if (r != JS_STOP_NONE) { s->in_cpu_advance = 0u; return r; }
        }
    }
    s->in_cpu_advance = 0u;
    return JS_STOP_NONE;
}

js_stop_reason js_scheduler_v09c_advance_dma(js_scheduler_v09c *s, uint32_t clocks) {
    if (!s || (clocks & 1u)) return JS_STOP_TIMING_UNAVAILABLE;
    s->dma_advance_depth++;
    while (clocks != 0u || s->dma_refresh_stall_clocks != 0u) {
        uint32_t refresh_before = s->dma_refresh_stall_clocks;
        js_stop_reason r = js_v09c_tick2(s);
        if (r != JS_STOP_NONE) { s->dma_advance_depth--; return r; }
        if (refresh_before != 0u) {
            if (s->dma_refresh_stall_clocks >= 2u) s->dma_refresh_stall_clocks -= 2u;
            else s->dma_refresh_stall_clocks = 0u;
            if (s->dma_refresh_stall_clocks == 0u) js_v09c_log(s, JS_EVENT_V09C_DRAM_REFRESH_END, 0u);
        } else if (clocks != 0u) {
            clocks -= 2u;
        }
    }
    s->dma_advance_depth--;
    return JS_STOP_NONE;
}

static js_stop_reason js_v09c_process_pending_dma(js_scheduler_v09c *s) {
    js_stop_reason r;
    if (!s) return JS_STOP_TIMING_UNAVAILABLE;
    if (s->dma_start_delay) {
        s->dma_start_delay = 0u;
        return JS_STOP_NONE;
    }
    if (s->hdma_line_pending) {
        uint8_t mask = s->hdma_enable_mask;
        s->hdma_line_pending = 0u;
        js_v09c_log(s, JS_EVENT_V09C_HDMA_START, mask);
        if (!s->hooks.dma_event) return JS_STOP_DMA_UNAVAILABLE;
        r = s->hooks.dma_event(s->hooks.dma_opaque, JS_DMA_EVENT_V09C_HDMA_LINE, mask);
        if (r != JS_STOP_NONE) return r;
        js_v09c_log(s, JS_EVENT_V09C_HDMA_END, mask);
        return JS_STOP_NONE;
    }
    if (s->hdma_init_pending) {
        uint8_t mask = s->hdma_enable_mask;
        s->hdma_init_pending = 0u;
        if (!s->hooks.dma_event) {
            /* With no HDMA channels, initialization has no bus transfer and no
               component state to mutate.  Preserve fail-closed behavior only
               when a real HDMA channel is enabled. */
            return mask ? JS_STOP_DMA_UNAVAILABLE : JS_STOP_NONE;
        }
        return s->hooks.dma_event(s->hooks.dma_opaque, JS_DMA_EVENT_V09C_HDMA_INIT, mask);
    }
    if (s->dma_pending_mask != 0u) {
        uint8_t mask = s->dma_pending_mask;
        s->dma_pending_mask = 0u;
        js_v09c_log(s, JS_EVENT_V09C_DMA_START, mask);
        if (!s->hooks.dma_event) return JS_STOP_DMA_UNAVAILABLE;
        r = s->hooks.dma_event(s->hooks.dma_opaque, JS_DMA_EVENT_V09C_MANUAL, mask);
        if (r != JS_STOP_NONE) return r;
        js_v09c_log(s, JS_EVENT_V09C_DMA_END, mask);
    }
    return JS_STOP_NONE;
}

js_stop_reason js_scheduler_v09c_cpu_cycle_begin(js_scheduler_v09c *s) {
    return js_v09c_process_pending_dma(s);
}

js_stop_reason js_scheduler_v09c_dma_transfer_boundary(js_scheduler_v09c *s) {
    return js_v09c_process_pending_dma(s);
}

void js_scheduler_v09c_write_nmitimen(js_scheduler_v09c *s, uint8_t value) {
    uint8_t old;
    if (!s) return;
    old = s->nmitimen;
    s->nmitimen = value;
    if (s->nmi_flag && (value & 0x80u) && !(old & 0x80u)) {
        s->nmi_pending = 1u;
        js_v09c_log(s, JS_EVENT_V09C_NMI_PENDING, 1u);
    }
    if ((value & 0x30u) == 0u) {
        s->irq_need_ticks = 0u;
        s->irq_level = 0u;
        js_v09c_set_irq_flag(s, 0);
    } else {
        js_v09c_update_irq_level(s);
    }
}

void js_scheduler_v09c_set_h_timer(js_scheduler_v09c *s, uint16_t value) {
    if (!s) return;
    s->h_timer = (uint16_t)(value & 0x01FFu);
    js_v09c_update_irq_level(s);
}

void js_scheduler_v09c_set_v_timer(js_scheduler_v09c *s, uint16_t value) {
    if (!s) return;
    s->v_timer = (uint16_t)(value & 0x01FFu);
    js_v09c_update_irq_level(s);
}

void js_scheduler_v09c_set_hdma_enable(js_scheduler_v09c *s, uint8_t mask) { if (s) s->hdma_enable_mask = mask; }
void js_scheduler_v09c_request_dma(js_scheduler_v09c *s, uint8_t mask) {
    if (s && mask) {
        s->dma_pending_mask |= mask;
        s->dma_start_delay = 1u;
        js_v09c_log(s, JS_EVENT_V09C_DMA_REQUEST, mask);
    }
}

void js_scheduler_v09c_set_ppu_timing(js_scheduler_v09c *s, uint8_t overscan, uint8_t interlace) {
    if (!s) return;
    s->ppu_overscan_pending = (uint8_t)(overscan != 0u);
    s->ppu_interlace_pending = (uint8_t)(interlace != 0u);
}

uint8_t js_scheduler_v09c_read_rdnmi(js_scheduler_v09c *s, uint8_t open_bus) {
    uint8_t value;
    if (!s) return (uint8_t)(0x02u | (open_bus & 0x70u));
    value = (uint8_t)((s->nmi_flag ? 0x80u : 0u) | 0x02u | (open_bus & 0x70u));
    if (s->nmi_flag && (s->hclock >= 6u || s->scanline != s->vblank_start_scanline)) {
        s->nmi_flag = 0u;
        js_v09c_log(s, JS_EVENT_V09C_NMI_FLAG_CLEAR, 0u);
    }
    return value;
}

uint8_t js_scheduler_v09c_read_timeup(js_scheduler_v09c *s, uint8_t open_bus) {
    uint8_t value;
    if (!s) return open_bus;
    value = (uint8_t)((s->irq_flag ? 0x80u : 0u) | (open_bus & 0x7Fu));
    if (s->irq_flag && s->irq_need_ticks == 0u) js_v09c_set_irq_flag(s, 0);
    return value;
}

uint8_t js_scheduler_v09c_read_hvbjoy(js_scheduler_v09c *s, uint8_t open_bus) {
    uint8_t vblank, hblank, autojoy;
    if (!s) return (uint8_t)(open_bus & 0x3Eu);
    js_v09c_process_autojoy(s);
    vblank = (uint8_t)(s->scanline >= s->vblank_start_scanline ? 0x80u : 0u);
    hblank = (uint8_t)((s->hclock >= 4u && s->hclock <= 1096u) ? 0u : 0x40u);
    autojoy = (uint8_t)(s->autojoy_active ? 0x01u : 0u);
    return (uint8_t)(vblank | hblank | autojoy | (open_bus & 0x3Eu));
}

int js_scheduler_v09c_take_nmi(js_scheduler_v09c *s) {
    if (!s || !s->nmi_pending) return 0;
    s->nmi_pending = 0u;
    return 1;
}

int js_scheduler_v09c_irq_asserted(const js_scheduler_v09c *s) { return s && s->irq_line; }
