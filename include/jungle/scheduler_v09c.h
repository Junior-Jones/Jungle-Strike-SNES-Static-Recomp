#ifndef JUNGLE_SCHEDULER_V09C_H
#define JUNGLE_SCHEDULER_V09C_H

#include <stddef.h>
#include <stdint.h>
#include "jungle/status.h"
#include "jungle/dma_v09c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V09C_NTSC_MASTER_CLOCK_HZ 21477270u
/* Historical nominal specification retained for audit compatibility only.
   V10.87 no longer phase-locks the independent APU oscillator to this rate. */
#define JS_V09C_NOMINAL_AUDIO_SAMPLE_RATE 32000u
#define JS_V09C_NOMINAL_SMP_HALF_TICK_HZ 2048000u
#define JS_V09C_SMP_CLOCK_NUMERATOR JS_V09C_NOMINAL_SMP_HALF_TICK_HZ

/* V10.87 deterministic APU clock-domain profile.  The physical S-SMP uses an
   independent oscillator, so this is a reproducible project-selected profile,
   not a claim of one universal console ratio or starting phase.  The exact
   S-SMP owner consumes 2 half-ticks per processor cycle and the S-DSP consumes
   32 processor cycles per stereo PCM frame.  This rational therefore yields
   ~1,025,279.8698 S-SMP cycles/s and ~32,039.9959 PCM frames/s against the
   canonical 21,477,270-Hz NTSC master timeline. */
#define JS_V09C_AUDIO_CLOCK_PROFILE_NAME "ntsc-measured-32040"
#define JS_V09C_SMP_HALF_TICK_RATIO_NUMERATOR 31328u
#define JS_V09C_SMP_HALF_TICK_RATIO_DENOMINATOR 328125u
#define JS_V09C_NATIVE_AUDIO_SAMPLE_RATE 32040u
#define JS_V09C_BASE_LINE_CLOCKS 1364u
#define JS_V09C_BASE_FRAME_LINES 262u
#define JS_V09C_DEFAULT_VBLANK_START 225u
#define JS_V09C_EVENT_LOG_CAPACITY 128u

typedef enum js_event_type_v09c {
    JS_EVENT_V09C_NONE = 0,
    JS_EVENT_V09C_SCANLINE_START,
    JS_EVENT_V09C_DRAM_REFRESH_START,
    JS_EVENT_V09C_DRAM_REFRESH_END,
    JS_EVENT_V09C_HDMA_INIT,
    JS_EVENT_V09C_HDMA_REQUEST,
    JS_EVENT_V09C_HDMA_START,
    JS_EVENT_V09C_HDMA_END,
    JS_EVENT_V09C_DMA_REQUEST,
    JS_EVENT_V09C_DMA_START,
    JS_EVENT_V09C_DMA_END,
    JS_EVENT_V09C_NMI_FLAG_SET,
    JS_EVENT_V09C_NMI_FLAG_CLEAR,
    JS_EVENT_V09C_NMI_PENDING,
    JS_EVENT_V09C_IRQ_FLAG_SET,
    JS_EVENT_V09C_IRQ_FLAG_CLEAR,
    JS_EVENT_V09C_IRQ_LINE_ASSERT,
    JS_EVENT_V09C_AUTOJOY_STEP,
    JS_EVENT_V09C_FRAME_START
} js_event_type_v09c;

typedef struct js_event_record_v09c {
    uint64_t master_clock;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t detail;
    uint8_t field;
    uint8_t type;
} js_event_record_v09c;

typedef js_stop_reason (*js_scheduler_dma_event_fn)(void *opaque, js_dma_event_kind_v09c kind, uint8_t channel_mask);
typedef void (*js_scheduler_smp_sync_fn)(void *opaque, uint64_t target_cycle);
typedef void (*js_scheduler_autojoy_step_fn)(void *opaque, unsigned step, uint8_t enabled);
typedef enum js_scheduler_ppu_event_kind_v09c {
    JS_SCHEDULER_PPU_EVENT_V09C_FRAME_START = 0,
    JS_SCHEDULER_PPU_EVENT_V09C_VBLANK_START = 1,
    /* V10.88 framebuffer ownership: sample each 256-pixel visible row at
       H=1080, before the H=1104 HDMA request can prepare the next row. */
    JS_SCHEDULER_PPU_EVENT_V09C_VISIBLE_SCANLINE = 2
} js_scheduler_ppu_event_kind_v09c;

typedef void (*js_scheduler_ppu_event_fn)(void *opaque, js_scheduler_ppu_event_kind_v09c kind);

typedef struct js_scheduler_hooks_v09c {
    void *dma_opaque;
    js_scheduler_dma_event_fn dma_event;
    void *smp_opaque;
    js_scheduler_smp_sync_fn smp_sync;
    void *autojoy_opaque;
    js_scheduler_autojoy_step_fn autojoy_step;
    void *ppu_opaque;
    js_scheduler_ppu_event_fn ppu_event;
} js_scheduler_hooks_v09c;

typedef struct js_scheduler_v09c {
    uint64_t master_clock;
    uint64_t frame_count;
    uint64_t smp_target_cycle;
    uint32_t smp_clock_remainder;
    uint64_t autojoy_start_clock;
    uint64_t autojoy_next_clock;
    uint16_t hclock;
    uint16_t scanline;
    uint16_t h_counter;
    uint16_t v_counter;
    uint16_t h_timer;
    uint16_t v_timer;
    uint16_t dram_refresh_hclock;
    uint16_t line_clocks;
    uint16_t frame_lines;
    uint16_t vblank_start_scanline;
    uint32_t cpu_stall_clocks;
    uint32_t dma_refresh_stall_clocks;
    uint8_t field;
    uint8_t nmitimen;
    uint8_t nmi_flag;
    uint8_t irq_flag;
    uint8_t irq_line;
    uint8_t nmi_pending;
    uint8_t irq_need_ticks;
    uint8_t irq_level;
    uint8_t autojoy_active;
    uint8_t autojoy_disabled;
    uint8_t autojoy_step_index;
    uint8_t hdma_enable_mask;
    uint8_t dma_pending_mask;
    uint8_t hdma_init_pending;
    uint8_t hdma_line_pending;
    uint8_t dma_start_delay;
    uint8_t in_cpu_advance;
    uint8_t dma_advance_depth;
    uint8_t cpu_stall_kind;
    uint8_t ppu_overscan_pending;
    uint8_t ppu_overscan_latched;
    uint8_t ppu_interlace_pending;
    uint8_t ppu_interlace_latched;
    js_scheduler_hooks_v09c hooks;
    js_event_record_v09c event_log[JS_V09C_EVENT_LOG_CAPACITY];
    size_t event_log_count;
    size_t event_log_next;
} js_scheduler_v09c;

void js_scheduler_v09c_power_on(js_scheduler_v09c *s, js_scheduler_hooks_v09c hooks);
void js_scheduler_v09c_cpu_reset(js_scheduler_v09c *s);
js_stop_reason js_scheduler_v09c_advance_wall(js_scheduler_v09c *s, uint32_t clocks);
js_stop_reason js_scheduler_v09c_advance_cpu(js_scheduler_v09c *s, uint32_t active_clocks);
js_stop_reason js_scheduler_v09c_advance_dma(js_scheduler_v09c *s, uint32_t clocks);
js_stop_reason js_scheduler_v09c_cpu_cycle_begin(js_scheduler_v09c *s);
js_stop_reason js_scheduler_v09c_dma_transfer_boundary(js_scheduler_v09c *s);
void js_scheduler_v09c_write_nmitimen(js_scheduler_v09c *s, uint8_t value);
void js_scheduler_v09c_set_h_timer(js_scheduler_v09c *s, uint16_t value);
void js_scheduler_v09c_set_v_timer(js_scheduler_v09c *s, uint16_t value);
void js_scheduler_v09c_set_hdma_enable(js_scheduler_v09c *s, uint8_t mask);
void js_scheduler_v09c_request_dma(js_scheduler_v09c *s, uint8_t mask);
void js_scheduler_v09c_set_ppu_timing(js_scheduler_v09c *s, uint8_t overscan, uint8_t interlace);
uint8_t js_scheduler_v09c_read_rdnmi(js_scheduler_v09c *s, uint8_t open_bus);
uint8_t js_scheduler_v09c_read_timeup(js_scheduler_v09c *s, uint8_t open_bus);
uint8_t js_scheduler_v09c_read_hvbjoy(js_scheduler_v09c *s, uint8_t open_bus);
int js_scheduler_v09c_take_nmi(js_scheduler_v09c *s);
int js_scheduler_v09c_irq_asserted(const js_scheduler_v09c *s);
const js_event_record_v09c *js_scheduler_v09c_event_at(const js_scheduler_v09c *s, size_t logical_index);

#ifdef __cplusplus
}
#endif
#endif
