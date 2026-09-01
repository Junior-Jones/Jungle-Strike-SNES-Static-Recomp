#ifndef JUNGLE_RENDERER_V10_28_H
#define JUNGLE_RENDERER_V10_28_H

#include <stdint.h>
#include "jungle/ppu_v09c.h"
#include "jungle/status_v10_28.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V10_28_TILE_PIXELS 8u
#define JS_V10_28_BG_TILEMAP_SIDE 32u
#define JS_V10_28_BG_TILEMAP_WORDS 0x0400u
#define JS_V10_28_OBJ_COUNT 128u

typedef struct js_rgb8_v10_28 {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} js_rgb8_v10_28;

typedef struct js_tilemap_entry_v10_28 {
    uint16_t tile_index;
    uint8_t palette;
    uint8_t priority;
    uint8_t hflip;
    uint8_t vflip;
} js_tilemap_entry_v10_28;

typedef struct js_bg_coordinate_v10_28 {
    uint16_t world_x;
    uint16_t world_y;
    uint16_t map_width_pixels;
    uint16_t map_height_pixels;
    uint8_t logical_tile_pixels;
    uint8_t fine_x;
    uint8_t fine_y;
    uint8_t tile_x;
    uint8_t tile_y;
    uint16_t tilemap_word_address;
} js_bg_coordinate_v10_28;

typedef struct js_bg_character_v10_28 {
    uint16_t tile_index;
    uint8_t pixel_x;
    uint8_t pixel_y;
} js_bg_character_v10_28;

typedef struct js_obj_size_v10_28 {
    uint8_t width;
    uint8_t height;
} js_obj_size_v10_28;

typedef struct js_obj_record_v10_28 {
    int16_t x;
    uint8_t y;
    uint8_t tile_low;
    uint8_t name_select;
    uint8_t palette;
    uint8_t priority;
    uint8_t hflip;
    uint8_t vflip;
    uint8_t large;
    js_obj_size_v10_28 size;
} js_obj_record_v10_28;

/* Fail-closed reads against V09C known-byte authority. */
js_stop_reason js_renderer_v10_28_read_vram_byte(const js_ppu_v09c *ppu,
                                                  uint16_t byte_address,
                                                  uint8_t *value);
js_stop_reason js_renderer_v10_28_read_vram_word(const js_ppu_v09c *ppu,
                                                  uint16_t word_address,
                                                  uint16_t *value);
js_stop_reason js_renderer_v10_28_read_cgram_color(const js_ppu_v09c *ppu,
                                                    uint16_t color_index,
                                                    uint16_t *bgr555);
js_stop_reason js_renderer_v10_28_read_oam_byte(const js_ppu_v09c *ppu,
                                                 uint16_t byte_address,
                                                 uint8_t *value);

/* Palette and planar character primitives. */
void js_renderer_v10_28_bgr555_to_rgb8(uint16_t bgr555, js_rgb8_v10_28 *rgb);
js_stop_reason js_renderer_v10_28_decode_tile_row(const js_ppu_v09c *ppu,
                                                   uint16_t chr_base_word,
                                                   uint16_t tile_index,
                                                   uint8_t bpp,
                                                   uint8_t row,
                                                   uint8_t pixels[JS_V10_28_TILE_PIXELS]);

/* Standard BG tilemap and coordinate primitives; Mode 7/OPT remain later work. */
void js_renderer_v10_28_decode_tilemap_entry(uint16_t raw,
                                              js_tilemap_entry_v10_28 *entry);
js_stop_reason js_renderer_v10_28_bg_map_word_address(const js_ppu_v09c *ppu,
                                                       unsigned layer,
                                                       uint8_t tile_x,
                                                       uint8_t tile_y,
                                                       uint16_t *word_address);
js_stop_reason js_renderer_v10_28_bg_resolve_coordinate(const js_ppu_v09c *ppu,
                                                         unsigned layer,
                                                         uint16_t screen_x,
                                                         uint16_t screen_y,
                                                         js_bg_coordinate_v10_28 *coord);
js_stop_reason js_renderer_v10_28_bg_resolve_character(const js_tilemap_entry_v10_28 *entry,
                                                        uint8_t logical_tile_pixels,
                                                        uint8_t fine_x,
                                                        uint8_t fine_y,
                                                        js_bg_character_v10_28 *character);

/* OBJ/OAM decoding and character-table addressing only; no scanline evaluation yet. */
js_stop_reason js_renderer_v10_28_obj_size(uint8_t mode,
                                            uint8_t large,
                                            js_obj_size_v10_28 *size);
js_stop_reason js_renderer_v10_28_decode_obj(const js_ppu_v09c *ppu,
                                              uint8_t obj_index,
                                              js_obj_record_v10_28 *obj);
js_stop_reason js_renderer_v10_28_obj_tile_word_address(const js_ppu_v09c *ppu,
                                                         uint8_t tile_low,
                                                         uint8_t name_select,
                                                         uint8_t tile_x,
                                                         uint8_t tile_y,
                                                         uint16_t *word_address);

#ifdef __cplusplus
}
#endif
#endif
