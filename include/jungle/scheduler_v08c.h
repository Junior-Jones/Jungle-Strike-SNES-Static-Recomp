#ifndef JUNGLE_SCHEDULER_V08C_H
#define JUNGLE_SCHEDULER_V08C_H

#include <stddef.h>
#include <stdint.h>
#include "jungle/status.h"
#include "jungle/dma_v08c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V08C_NTSC_MASTER_CLOCK_HZ 21477270u
#define JS_V08C_SMP_CLOCK_NUMERATOR 2048000u
#define JS_V08C_BASE_LINE_CLOCKS 1364u
#define JS_V08C_BASE_FRAME_LINES 262u
#define JS_V08C_DEFAULT_VBLANK_START 225u
#define JS_V08C_EVENT_LOG_CAPACITY 128u

typedef enum js_event_type_v08c {
    JS_EVENT_V08C_NONE = 0,
    JS_EVENT_V08C_SCANLINE_START,
    JS_EVENT_V08C_DRAM_REFRESH_START,
    JS_EVENT_V08C_DRAM_REFRESH_END,
    JS_EVENT_V08C_HDMA_INIT,
    JS_EVENT_V08C_HDMA_REQUEST,
    JS_EVENT_V08C_HDMA_START,
    JS_EVENT_V08C_HDMA_END,
    JS_EVENT_V08C_DMA_REQUEST,
    JS_EVENT_V08C_DMA_START,
    JS_EVENT_V08C_DMA_END,
    JS_EVENT_V08C_NMI_FLAG_SET,
    JS_EVENT_V08C_NMI_FLAG_CLEAR,
    JS_EVENT_V08C_NMI_PENDING,
    JS_EVENT_V08C_IRQ_FLAG_SET,
    JS_EVENT_V08C_IRQ_FLAG_CLEAR,
    JS_EVENT_V08C_IRQ_LINE_ASSERT,
    JS_EVENT_V08C_AUTOJOY_STEP,
    JS_EVENT_V08C_FRAME_START
} js_event_type_v08c;

typedef struct js_event_record_v08c {
    uint64_t master_clock;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t detail;
    uint8_t field;
    uint8_t type;
} js_event_record_v08c;

typedef js_stop_reason (*js_scheduler_dma_event_fn)(void *opaque, js_dma_event_kind_v08c kind, uint8_t channel_mask);
typedef void (*js_scheduler_smp_sync_fn)(void *opaque, uint64_t target_cycle);
typedef void (*js_scheduler_autojoy_step_fn)(void *opaque, unsigned step, uint8_t enabled);

typedef struct js_scheduler_hooks_v08c {
    void *dma_opaque;
    js_scheduler_dma_event_fn dma_event;
    void *smp_opaque;
    js_scheduler_smp_sync_fn smp_sync;
    void *autojoy_opaque;
    js_scheduler_autojoy_step_fn autojoy_step;
} js_scheduler_hooks_v08c;

typedef struct js_scheduler_v08c {
    uint64_t master_clock;
    uint64_t frame_count;
    uint64_t smp_target_cycle;
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
    js_scheduler_hooks_v08c hooks;
    js_event_record_v08c event_log[JS_V08C_EVENT_LOG_CAPACITY];
    size_t event_log_count;
    size_t event_log_next;
} js_scheduler_v08c;

void js_scheduler_v08c_power_on(js_scheduler_v08c *s, js_scheduler_hooks_v08c hooks);
void js_scheduler_v08c_cpu_reset(js_scheduler_v08c *s);
js_stop_reason js_scheduler_v08c_advance_wall(js_scheduler_v08c *s, uint32_t clocks);
js_stop_reason js_scheduler_v08c_advance_cpu(js_scheduler_v08c *s, uint32_t active_clocks);
js_stop_reason js_scheduler_v08c_advance_dma(js_scheduler_v08c *s, uint32_t clocks);
js_stop_reason js_scheduler_v08c_cpu_cycle_begin(js_scheduler_v08c *s);
js_stop_reason js_scheduler_v08c_dma_transfer_boundary(js_scheduler_v08c *s);
void js_scheduler_v08c_write_nmitimen(js_scheduler_v08c *s, uint8_t value);
void js_scheduler_v08c_set_h_timer(js_scheduler_v08c *s, uint16_t value);
void js_scheduler_v08c_set_v_timer(js_scheduler_v08c *s, uint16_t value);
void js_scheduler_v08c_set_hdma_enable(js_scheduler_v08c *s, uint8_t mask);
void js_scheduler_v08c_request_dma(js_scheduler_v08c *s, uint8_t mask);
uint8_t js_scheduler_v08c_read_rdnmi(js_scheduler_v08c *s, uint8_t open_bus);
uint8_t js_scheduler_v08c_read_timeup(js_scheduler_v08c *s, uint8_t open_bus);
uint8_t js_scheduler_v08c_read_hvbjoy(js_scheduler_v08c *s, uint8_t open_bus);
int js_scheduler_v08c_take_nmi(js_scheduler_v08c *s);
int js_scheduler_v08c_irq_asserted(const js_scheduler_v08c *s);
const js_event_record_v08c *js_scheduler_v08c_event_at(const js_scheduler_v08c *s, size_t logical_index);

#ifdef __cplusplus
}
#endif
#endif
