#ifndef JUNGLE_RENDERER_V10_29_H
#define JUNGLE_RENDERER_V10_29_H

#include <stdint.h>
#include "jungle/renderer_v10_28.h"
#include "jungle/status_v10_29.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V10_29_SOURCE_BGMODE 0x39u
#define JS_V10_29_SOURCE_BGMODE_SMALL_BG12 0x09u
#define JS_V10_29_SOURCE_MOSAIC 0x00u
#define JS_V10_29_MODE1_ACTIVE_BG_COUNT 3u

typedef struct js_bg_layer_desc_v10_29 {
    uint8_t active;
    uint8_t bpp;
    uint8_t palette_stride;
    uint8_t priority_low_slot;
    uint8_t priority_high_slot;
} js_bg_layer_desc_v10_29;

typedef struct js_bg_pixel_v10_29 {
    uint8_t layer;
    uint8_t bpp;
    uint8_t palette;
    uint8_t color_index;
    uint8_t tile_priority;
    uint8_t priority_slot;
    uint8_t transparent;
    uint16_t tilemap_word_address;
    uint16_t tilemap_raw;
    uint16_t character_index;
    uint16_t cgram_index;
    uint16_t bgr555;
    js_rgb8_v10_28 rgb;
} js_bg_pixel_v10_29;

/* Exact source-reached phase guard proved from the CC50 PPU state block at A0:D7DB. */
js_stop_reason js_renderer_v10_29_validate_source_configuration(const js_ppu_v09c *ppu);

/* Mode-1 layer/depth and priority semantics. Layer is 0-based BG1..BG4. */
js_stop_reason js_renderer_v10_29_mode1_layer_desc(const js_ppu_v09c *ppu,
                                                    unsigned layer,
                                                    js_bg_layer_desc_v10_29 *desc);
js_stop_reason js_renderer_v10_29_mode1_priority_slot(const js_ppu_v09c *ppu,
                                                       unsigned layer,
                                                       uint8_t tile_priority,
                                                       uint8_t *slot);

/* Core-owned background sample. Color index zero remains transparent. */
js_stop_reason js_renderer_v10_29_sample_mode1_bg(const js_ppu_v09c *ppu,
                                                  unsigned layer,
                                                  uint16_t screen_x,
                                                  uint16_t screen_y,
                                                  js_bg_pixel_v10_29 *sample);

#ifdef __cplusplus
}
#endif
#endif
