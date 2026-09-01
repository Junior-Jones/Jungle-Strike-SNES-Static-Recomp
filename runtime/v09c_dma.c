#include <string.h>
#include "jungle/dma_v09c.h"
#include "jungle/bus_v09c.h"
#include "jungle/scheduler_v09c.h"

static const uint8_t js_v09c_transfer_count[8] = { 1u, 2u, 2u, 4u, 4u, 4u, 2u, 4u };
static const uint8_t js_v09c_transfer_offset[8][4] = {
    {0u,0u,0u,0u}, {0u,1u,0u,1u}, {0u,0u,0u,0u}, {0u,0u,1u,1u},
    {0u,1u,2u,3u}, {0u,1u,0u,1u}, {0u,0u,0u,0u}, {0u,0u,1u,1u}
};

static void js_v09c_channel_power_on(js_dma_channel_v09c *c) {
    memset(c, 0, sizeof(*c));
    c->a_address = 0xFFFFu;
    c->transfer_size = 0xFFFFu;
    c->hdma_table_address = 0xFFFFu;
    c->a_bank = 0xFFu;
    c->b_address = 0xFFu;
    c->hdma_bank = 0xFFu;
    c->line_counter_repeat = 0xFFu;
    c->unused_register = 0xFFu;
    c->transfer_mode = 7u;
    c->direction_b_to_a = 1u;
    c->hdma_indirect = 1u;
    c->unused_control = 1u;
    c->decrement = 1u;
    c->fixed = 1u;
}

void js_dma_v09c_init(js_dma_v09c *dma, struct js_bus_v09c *bus, struct js_scheduler_v09c *scheduler) {
    unsigned i;
    if (!dma) return;
    memset(dma, 0, sizeof(*dma));
    dma->bus = bus;
    dma->scheduler = scheduler;
    dma->active_channel = 0xFFu;
    for (i = 0u; i < 8u; i++) js_v09c_channel_power_on(&dma->channel[i]);
}

void js_dma_v09c_reset(js_dma_v09c *dma) {
    unsigned i;
    if (!dma) return;
    dma->hdma_enable_mask = 0u;
    dma->active_channel = 0xFFu;
    dma->active_is_hdma = 0u;
    dma->clock_counter = 0u;
    for (i = 0u; i < 8u; i++) {
        /* CPU RESET clears manual-DMA activity but does not cold-power the
           channel register/internal HDMA file.  Frame HDMA initialization is
           the owner of HdmaFinished/DoTransfer, matching the pinned MesenCE
           controller and preventing RESET from becoming an implicit memset. */
        dma->channel[i].dma_active = 0u;
    }
}

static uint8_t js_v09c_control_value(const js_dma_channel_v09c *c) {
    return (uint8_t)((c->direction_b_to_a ? 0x80u : 0u) |
                     (c->hdma_indirect ? 0x40u : 0u) |
                     (c->unused_control ? 0x20u : 0u) |
                     (c->decrement ? 0x10u : 0u) |
                     (c->fixed ? 0x08u : 0u) |
                     (c->transfer_mode & 7u));
}

js_stop_reason js_dma_v09c_read8(void *opaque, uint16_t reg, uint8_t *value) {
    js_dma_v09c *dma = (js_dma_v09c *)opaque;
    js_dma_channel_v09c *c;
    unsigned ch, off;
    if (!dma || !value) return JS_STOP_DMA_UNAVAILABLE;
    if (reg < 0x4300u || reg > 0x437Fu) return JS_STOP_DMA_UNAVAILABLE;
    ch = (unsigned)((reg >> 4) & 7u);
    off = (unsigned)(reg & 0x0Fu);
    c = &dma->channel[ch];
    switch (off) {
        case 0x0u: *value = js_v09c_control_value(c); return JS_STOP_NONE;
        case 0x1u: *value = c->b_address; return JS_STOP_NONE;
        case 0x2u: *value = (uint8_t)c->a_address; return JS_STOP_NONE;
        case 0x3u: *value = (uint8_t)(c->a_address >> 8); return JS_STOP_NONE;
        case 0x4u: *value = c->a_bank; return JS_STOP_NONE;
        case 0x5u: *value = (uint8_t)c->transfer_size; return JS_STOP_NONE;
        case 0x6u: *value = (uint8_t)(c->transfer_size >> 8); return JS_STOP_NONE;
        case 0x7u: *value = c->hdma_bank; return JS_STOP_NONE;
        case 0x8u: *value = (uint8_t)c->hdma_table_address; return JS_STOP_NONE;
        case 0x9u: *value = (uint8_t)(c->hdma_table_address >> 8); return JS_STOP_NONE;
        case 0xAu: *value = c->line_counter_repeat; return JS_STOP_NONE;
        case 0xBu: case 0xFu: *value = c->unused_register; return JS_STOP_NONE;
        default:
            *value = dma->bus ? dma->bus->base.open_bus : 0u;
            return JS_STOP_NONE;
    }
}

js_stop_reason js_dma_v09c_write8(void *opaque, uint16_t reg, uint8_t value) {
    js_dma_v09c *dma = (js_dma_v09c *)opaque;
    js_dma_channel_v09c *c;
    unsigned ch, off, i;
    if (!dma) return JS_STOP_DMA_UNAVAILABLE;
    if (reg == 0x420Bu) {
        for (i = 0u; i < 8u; i++) if ((value & (uint8_t)(1u << i)) != 0u) dma->channel[i].dma_active = 1u;
        return JS_STOP_NONE;
    }
    if (reg == 0x420Cu) {
        dma->hdma_enable_mask = value;
        return JS_STOP_NONE;
    }
    if (reg < 0x4300u || reg > 0x437Fu) return JS_STOP_DMA_UNAVAILABLE;
    ch = (unsigned)((reg >> 4) & 7u);
    off = (unsigned)(reg & 0x0Fu);
    c = &dma->channel[ch];
    switch (off) {
        case 0x0u:
            c->direction_b_to_a = (uint8_t)((value & 0x80u) != 0u);
            c->hdma_indirect = (uint8_t)((value & 0x40u) != 0u);
            c->unused_control = (uint8_t)((value & 0x20u) != 0u);
            c->decrement = (uint8_t)((value & 0x10u) != 0u);
            c->fixed = (uint8_t)((value & 0x08u) != 0u);
            c->transfer_mode = (uint8_t)(value & 7u);
            break;
        case 0x1u: c->b_address = value; break;
        case 0x2u: c->a_address = (uint16_t)((c->a_address & 0xFF00u) | value); break;
        case 0x3u: c->a_address = (uint16_t)(((uint32_t)c->a_address & 0x00FFu) | ((uint32_t)value << 8)); break;
        case 0x4u: c->a_bank = value; break;
        case 0x5u: c->transfer_size = (uint16_t)((c->transfer_size & 0xFF00u) | value); break;
        case 0x6u: c->transfer_size = (uint16_t)(((uint32_t)c->transfer_size & 0x00FFu) | ((uint32_t)value << 8)); break;
        case 0x7u: c->hdma_bank = value; break;
        case 0x8u: c->hdma_table_address = (uint16_t)((c->hdma_table_address & 0xFF00u) | value); break;
        case 0x9u: c->hdma_table_address = (uint16_t)(((uint32_t)c->hdma_table_address & 0x00FFu) | ((uint32_t)value << 8)); break;
        case 0xAu: c->line_counter_repeat = value; break;
        case 0xBu: case 0xFu: c->unused_register = value; break;
        default: break;
    }
    return JS_STOP_NONE;
}

static int js_v09c_has_active_manual(const js_dma_v09c *dma) {
    unsigned i;
    for (i = 0u; i < 8u; i++) if (dma->channel[i].dma_active) return 1;
    return 0;
}

static js_stop_reason js_v09c_advance(js_dma_v09c *dma, uint32_t clocks) {
    js_stop_reason r;
    if (!dma || !dma->scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    r = js_scheduler_v09c_advance_dma(dma->scheduler, clocks);
    if (r == JS_STOP_NONE) dma->clock_counter += clocks;
    return r;
}

static js_stop_reason js_v09c_sync_start(js_dma_v09c *dma) {
    uint32_t align;
    if (!dma || !dma->scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    align = 8u - (uint32_t)(dma->scheduler->master_clock & 7u);
    dma->clock_counter = 0u;
    return js_v09c_advance(dma, align);
}

static js_stop_reason js_v09c_sync_end(js_dma_v09c *dma) {
    uint32_t speed, rem, align;
    if (!dma || !dma->scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    speed = dma->bus && dma->bus->cpu_speed_clocks ? dma->bus->cpu_speed_clocks : 6u;
    rem = dma->clock_counter % speed;
    align = speed - rem;
    /* The shared hardware DMA clock counter is used only to choose end alignment;
       the final alignment itself does not feed back into that counter. */
    return js_scheduler_v09c_advance_dma(dma->scheduler, align);
}

static js_stop_reason js_v09c_copy_byte(js_dma_v09c *dma, uint32_t a_addr, uint16_t b_addr, uint8_t b_to_a) {
    uint8_t v = 0u;
    js_stop_reason r;
    if (!dma || !dma->bus) return JS_STOP_BUS_UNAVAILABLE;
    if (b_to_a) {
        if (b_addr == 0x2180u && js_bus_v09c_is_wram_address(dma->bus, a_addr)) {
            r = js_scheduler_v09c_advance_dma(dma->scheduler, 4u);
            if (r != JS_STOP_NONE) return r;
            r = js_bus_v09c_dma_write8(dma->bus, a_addr, 1u, 0xFFu);
        } else {
            r = js_bus_v09c_dma_read8(dma->bus, b_addr, 0u, &v);
            if (r == JS_STOP_NONE) r = js_bus_v09c_dma_write8(dma->bus, a_addr, 1u, v);
        }
    } else {
        if (b_addr == 0x2180u && js_bus_v09c_is_wram_address(dma->bus, a_addr)) {
            r = js_scheduler_v09c_advance_dma(dma->scheduler, 8u);
        } else {
            r = js_bus_v09c_dma_read8(dma->bus, a_addr, 1u, &v);
            if (r == JS_STOP_NONE) r = js_bus_v09c_dma_write8(dma->bus, b_addr, 0u, v);
        }
    }
    if (r == JS_STOP_NONE) dma->bytes_transferred++;
    return r;
}

static js_stop_reason js_v09c_run_manual(js_dma_v09c *dma, uint8_t mask) {
    unsigned ch;
    js_stop_reason r;
    (void)mask;
    r = js_v09c_sync_start(dma); if (r != JS_STOP_NONE) return r;
    r = js_v09c_advance(dma, 8u); if (r != JS_STOP_NONE) return r;
    /* A pending HDMA request may have arisen while synchronization/global
       overhead advanced the shared machine clock.  Match ProcessPendingTransfers(). */
    r = js_scheduler_v09c_dma_transfer_boundary(dma->scheduler); if (r != JS_STOP_NONE) return r;
    for (ch = 0u; ch < 8u; ch++) {
        js_dma_channel_v09c *c = &dma->channel[ch];
        uint32_t count, i;
        const uint8_t *offsets;
        if (!c->dma_active) continue;
        dma->active_channel = (uint8_t)ch;
        dma->active_is_hdma = 0u;
        r = js_v09c_advance(dma, 8u); if (r != JS_STOP_NONE) return r;
        r = js_scheduler_v09c_dma_transfer_boundary(dma->scheduler); if (r != JS_STOP_NONE) return r;
        offsets = js_v09c_transfer_offset[c->transfer_mode & 7u];
        count = c->transfer_size ? (uint32_t)c->transfer_size : 65536u;
        for (i = 0u; i < count && c->dma_active; i++) {
            uint16_t b = (uint16_t)(0x2100u | (uint8_t)(c->b_address + offsets[i & 3u]));
            uint32_t a = ((uint32_t)c->a_bank << 16) | c->a_address;
            r = js_v09c_copy_byte(dma, a, b, c->direction_b_to_a); if (r != JS_STOP_NONE) return r;
            dma->clock_counter += 8u;
            if (!c->fixed) c->a_address = (uint16_t)(c->a_address + (c->decrement ? (uint16_t)0xFFFFu : 1u));
            c->transfer_size = (uint16_t)(c->transfer_size - 1u);
            r = js_scheduler_v09c_dma_transfer_boundary(dma->scheduler); if (r != JS_STOP_NONE) return r;
        }
        c->dma_active = 0u;
    }
    dma->active_channel = 0xFFu;
    dma->manual_runs++;
    return js_v09c_sync_end(dma);
}

static js_stop_reason js_v09c_hdma_read_table(js_dma_v09c *dma, js_dma_channel_v09c *c, uint8_t *value) {
    uint32_t a = ((uint32_t)c->a_bank << 16) | c->hdma_table_address;
    js_stop_reason r = js_bus_v09c_dma_read8(dma->bus, a, 1u, value);
    if (r != JS_STOP_NONE) return r;
    /* ReadDma supplied the first four clocks. HDMA table fetches add another
       four while the shared DMA alignment counter records all eight. */
    r = js_scheduler_v09c_advance_dma(dma->scheduler, 4u);
    if (r == JS_STOP_NONE) dma->clock_counter += 8u;
    return r;
}

static js_stop_reason js_v09c_init_hdma(js_dma_v09c *dma, uint8_t mask) {
    unsigned i;
    int need_sync;
    js_stop_reason r;
    dma->hdma_enable_mask = mask;
    for (i = 0u; i < 8u; i++) {
        dma->channel[i].hdma_finished = 0u;
        dma->channel[i].hdma_do_transfer = 0u;
    }
    if (mask == 0u) return JS_STOP_NONE;
    need_sync = !js_v09c_has_active_manual(dma);
    if (need_sync) { r = js_v09c_sync_start(dma); if (r != JS_STOP_NONE) return r; }
    r = js_v09c_advance(dma, 8u); if (r != JS_STOP_NONE) return r;
    for (i = 0u; i < 8u; i++) {
        js_dma_channel_v09c *c = &dma->channel[i];
        c->hdma_do_transfer = 1u;
        if ((mask & (uint8_t)(1u << i)) == 0u) continue;
        c->hdma_table_address = c->a_address;
        c->dma_active = 0u;
        r = js_v09c_hdma_read_table(dma, c, &c->line_counter_repeat); if (r != JS_STOP_NONE) return r;
        c->hdma_table_address++;
        if (c->line_counter_repeat == 0u) c->hdma_finished = 1u;
        if (c->hdma_indirect) {
            uint8_t lo, hi = 0u;
            r = js_v09c_hdma_read_table(dma, c, &lo); if (r != JS_STOP_NONE) return r;
            c->hdma_table_address++;
            if (!c->hdma_finished) {
                r = js_v09c_hdma_read_table(dma, c, &hi); if (r != JS_STOP_NONE) return r;
                c->hdma_table_address++;
                c->transfer_size = (uint16_t)(lo | ((uint16_t)hi << 8));
            } else {
                c->transfer_size = (uint16_t)((uint16_t)lo << 8);
            }
        }
    }
    dma->hdma_init_runs++;
    if (need_sync) return js_v09c_sync_end(dma);
    return JS_STOP_NONE;
}

static js_stop_reason js_v09c_hdma_transfer(js_dma_v09c *dma, js_dma_channel_v09c *c, unsigned channel) {
    unsigned n = js_v09c_transfer_count[c->transfer_mode & 7u];
    unsigned i;
    const uint8_t *offsets = js_v09c_transfer_offset[c->transfer_mode & 7u];
    c->dma_active = 0u;
    dma->active_channel = (uint8_t)channel;
    dma->active_is_hdma = 1u;
    for (i = 0u; i < n; i++) {
        uint16_t b = (uint16_t)(0x2100u | (uint8_t)(c->b_address + offsets[i]));
        uint32_t a;
        js_stop_reason r;
        if (c->hdma_indirect) {
            a = ((uint32_t)c->hdma_bank << 16) | c->transfer_size;
            c->transfer_size++;
        } else {
            a = ((uint32_t)c->a_bank << 16) | c->hdma_table_address;
            c->hdma_table_address++;
        }
        r = js_v09c_copy_byte(dma, a, b, c->direction_b_to_a);
        if (r != JS_STOP_NONE) return r;
        dma->clock_counter += 8u;
    }
    return JS_STOP_NONE;
}

static int js_v09c_is_last_active_hdma(const js_dma_v09c *dma, unsigned channel, uint8_t mask) {
    unsigned i;
    for (i = channel + 1u; i < 8u; i++) {
        if ((mask & (uint8_t)(1u << i)) != 0u && !dma->channel[i].hdma_finished) return 0;
    }
    return 1;
}

static js_stop_reason js_v09c_run_hdma_line(js_dma_v09c *dma, uint8_t mask) {
    unsigned i;
    int need_sync;
    js_stop_reason r;
    uint8_t original_active_channel;
    uint8_t original_active_is_hdma;
    if (mask == 0u) return JS_STOP_NONE;
    original_active_channel = dma->active_channel;
    original_active_is_hdma = dma->active_is_hdma;
    need_sync = !js_v09c_has_active_manual(dma);
    if (need_sync) { r = js_v09c_sync_start(dma); if (r != JS_STOP_NONE) return r; }
    r = js_v09c_advance(dma, 8u); if (r != JS_STOP_NONE) return r;
    for (i = 0u; i < 8u; i++) {
        js_dma_channel_v09c *c = &dma->channel[i];
        if ((mask & (uint8_t)(1u << i)) == 0u || c->hdma_finished) continue;
        c->dma_active = 0u;
        if (c->hdma_do_transfer) {
            r = js_v09c_hdma_transfer(dma, c, i); if (r != JS_STOP_NONE) return r;
        }
    }
    for (i = 0u; i < 8u; i++) {
        js_dma_channel_v09c *c = &dma->channel[i];
        uint8_t next_counter;
        if ((mask & (uint8_t)(1u << i)) == 0u || c->hdma_finished) continue;
        c->line_counter_repeat--;
        c->hdma_do_transfer = (uint8_t)((c->line_counter_repeat & 0x80u) != 0u);
        r = js_v09c_hdma_read_table(dma, c, &next_counter); if (r != JS_STOP_NONE) return r;
        if ((c->line_counter_repeat & 0x7Fu) == 0u) {
            c->line_counter_repeat = next_counter;
            c->hdma_table_address++;
            if (c->hdma_indirect) {
                if (c->line_counter_repeat == 0u && js_v09c_is_last_active_hdma(dma, i, mask)) {
                    uint8_t hi;
                    r = js_v09c_hdma_read_table(dma, c, &hi); if (r != JS_STOP_NONE) return r;
                    c->hdma_table_address++;
                    c->transfer_size = (uint16_t)((uint16_t)hi << 8);
                } else {
                    uint8_t lo, hi;
                    r = js_v09c_hdma_read_table(dma, c, &lo); if (r != JS_STOP_NONE) return r;
                    c->hdma_table_address++;
                    r = js_v09c_hdma_read_table(dma, c, &hi); if (r != JS_STOP_NONE) return r;
                    c->hdma_table_address++;
                    c->transfer_size = (uint16_t)(lo | ((uint16_t)hi << 8));
                }
            }
            if (c->line_counter_repeat == 0u) c->hdma_finished = 1u;
            c->hdma_do_transfer = 1u;
        }
    }
    /* HDMA can interrupt a long manual DMA transfer at any byte boundary.
       Restore the controller's original active-channel identity so the
       interrupted manual channel remains the current owner when execution
       resumes.  This state is observable by diagnostics and by future
       component rendezvous even though the transfer data path is shared. */
    dma->active_channel = original_active_channel;
    dma->active_is_hdma = original_active_is_hdma;
    dma->hdma_line_runs++;
    if (need_sync) return js_v09c_sync_end(dma);
    return JS_STOP_NONE;
}

js_stop_reason js_dma_v09c_scheduler_event(void *opaque, js_dma_event_kind_v09c kind, uint8_t channel_mask) {
    js_dma_v09c *dma = (js_dma_v09c *)opaque;
    if (!dma) return JS_STOP_DMA_UNAVAILABLE;
    switch (kind) {
        case JS_DMA_EVENT_V09C_MANUAL: return js_v09c_run_manual(dma, channel_mask);
        case JS_DMA_EVENT_V09C_HDMA_INIT: return js_v09c_init_hdma(dma, channel_mask);
        case JS_DMA_EVENT_V09C_HDMA_LINE: return js_v09c_run_hdma_line(dma, channel_mask);
        default: return JS_STOP_DMA_UNAVAILABLE;
    }
}
