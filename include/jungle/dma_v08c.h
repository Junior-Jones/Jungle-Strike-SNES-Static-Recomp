#ifndef JUNGLE_DMA_V08C_H
#define JUNGLE_DMA_V08C_H

#include <stdint.h>
#include "jungle/status.h"

#ifdef __cplusplus
extern "C" {
#endif

struct js_bus_v08c;
struct js_scheduler_v08c;

typedef enum js_dma_event_kind_v08c {
    JS_DMA_EVENT_V08C_MANUAL = 0,
    JS_DMA_EVENT_V08C_HDMA_INIT = 1,
    JS_DMA_EVENT_V08C_HDMA_LINE = 2
} js_dma_event_kind_v08c;

typedef struct js_dma_channel_v08c {
    uint16_t a_address;
    uint16_t transfer_size;
    uint16_t hdma_table_address;
    uint8_t a_bank;
    uint8_t b_address;
    uint8_t hdma_bank;
    uint8_t line_counter_repeat;
    uint8_t unused_register;
    uint8_t transfer_mode;
    uint8_t direction_b_to_a;
    uint8_t hdma_indirect;
    uint8_t unused_control;
    uint8_t decrement;
    uint8_t fixed;
    uint8_t dma_active;
    uint8_t hdma_finished;
    uint8_t hdma_do_transfer;
} js_dma_channel_v08c;

typedef struct js_dma_v08c {
    struct js_bus_v08c *bus;
    struct js_scheduler_v08c *scheduler;
    js_dma_channel_v08c channel[8];
    uint8_t hdma_enable_mask;
    uint8_t active_channel;
    uint8_t active_is_hdma;
    uint32_t clock_counter;
    uint64_t bytes_transferred;
    uint64_t manual_runs;
    uint64_t hdma_init_runs;
    uint64_t hdma_line_runs;
} js_dma_v08c;

void js_dma_v08c_init(js_dma_v08c *dma, struct js_bus_v08c *bus, struct js_scheduler_v08c *scheduler);
void js_dma_v08c_reset(js_dma_v08c *dma);
js_stop_reason js_dma_v08c_read8(void *opaque, uint16_t reg, uint8_t *value);
js_stop_reason js_dma_v08c_write8(void *opaque, uint16_t reg, uint8_t value);
js_stop_reason js_dma_v08c_scheduler_event(void *opaque, js_dma_event_kind_v08c kind, uint8_t channel_mask);

#ifdef __cplusplus
}
#endif
#endif
