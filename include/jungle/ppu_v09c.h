#ifndef JUNGLE_PPU_V09C_H
#define JUNGLE_PPU_V09C_H

#include <stdint.h>
#include "jungle/status_v09c.h"
#include "jungle/scheduler_v09c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V09C_VRAM_WORDS 0x8000u
#define JS_V09C_VRAM_BYTES (JS_V09C_VRAM_WORDS * 2u)
#define JS_V09C_CGRAM_WORDS 0x0100u
#define JS_V09C_CGRAM_BYTES (JS_V09C_CGRAM_WORDS * 2u)
#define JS_V09C_OAM_BYTES 0x0220u
#define JS_V09C_PPU_REG_COUNT 0x40u
#define JS_V09C_VALUE_BITMAP_BYTES 32u
#define JS_V09C_VRAM_KNOWN_BYTES ((JS_V09C_VRAM_BYTES + 7u) / 8u)
#define JS_V09C_CGRAM_KNOWN_BYTES ((JS_V09C_CGRAM_BYTES + 7u) / 8u)
#define JS_V09C_OAM_KNOWN_BYTES ((JS_V09C_OAM_BYTES + 7u) / 8u)

typedef enum js_ppu_vram_buffer_state_v09c {
    JS_V09C_VRAM_BUFFER_UNINITIALIZED = 0,
    JS_V09C_VRAM_BUFFER_VALID = 1,
    JS_V09C_VRAM_BUFFER_RENDERER_DEPENDENT = 2,
    JS_V09C_VRAM_BUFFER_PARTIAL = 3
} js_ppu_vram_buffer_state_v09c;

#define JS_V09C_VRAM_BUFFER_LOW_KNOWN 0x01u
#define JS_V09C_VRAM_BUFFER_HIGH_KNOWN 0x02u
#define JS_V09C_VRAM_BUFFER_BOTH_KNOWN 0x03u

typedef enum js_ppu_register_access_v09c {
    JS_PPU_REG_V09C_WRITE_STATE = 0,
    JS_PPU_REG_V09C_READ_STATUS = 1
} js_ppu_register_access_v09c;

typedef struct js_ppu_register_descriptor_v09c {
    const char *name;
    js_ppu_register_access_v09c access;
} js_ppu_register_descriptor_v09c;

typedef struct js_ppu_layer_v09c {
    uint16_t tilemap_address;
    uint16_t chr_address;
    uint16_t h_scroll;
    uint16_t v_scroll;
    uint8_t double_width;
    uint8_t double_height;
    uint8_t large_tiles;
} js_ppu_layer_v09c;

typedef struct js_ppu_window_v09c {
    uint8_t active_layers[6];
    uint8_t inverted_layers[6];
    uint8_t left;
    uint8_t right;
} js_ppu_window_v09c;

typedef struct js_ppu_mode7_v09c {
    int16_t matrix[4];
    int16_t h_scroll;
    int16_t v_scroll;
    int16_t center_x;
    int16_t center_y;
    uint8_t value_latch;
    uint8_t large_map;
    uint8_t fill_with_tile0;
    uint8_t horizontal_mirror;
    uint8_t vertical_mirror;
} js_ppu_mode7_v09c;

typedef struct js_ppu_v09c {
    /* Deterministic storage is separated from hardware-known-byte state. */
    uint16_t vram[JS_V09C_VRAM_WORDS];
    uint16_t cgram[JS_V09C_CGRAM_WORDS];
    uint8_t oam[JS_V09C_OAM_BYTES];
    uint8_t vram_known[JS_V09C_VRAM_KNOWN_BYTES];
    uint8_t cgram_known[JS_V09C_CGRAM_KNOWN_BYTES];
    uint8_t oam_known[JS_V09C_OAM_KNOWN_BYTES];

    js_scheduler_v09c *scheduler;
    const uint8_t *cpu_open_bus;
    const uint8_t *wrio;

    js_ppu_layer_v09c layer[4];
    js_ppu_window_v09c window[2];
    js_ppu_mode7_v09c mode7;

    uint16_t vram_address;
    uint16_t vram_read_buffer;
    uint16_t oam_ram_address;
    uint16_t internal_oam_address;
    uint16_t fixed_color;
    uint16_t horizontal_location;
    uint16_t vertical_location;
    uint16_t oam_base_address;
    uint16_t oam_address_offset;

    uint8_t vram_increment;
    uint8_t vram_remap;
    uint8_t vram_increment_on_high;
    uint8_t vram_read_buffer_state;
    uint8_t vram_read_buffer_known;
    uint8_t cgram_address;
    uint8_t cgram_write_buffer;
    uint8_t cgram_high_latch;
    uint8_t oam_write_buffer;
    uint8_t ppu1_open_bus;
    uint8_t ppu2_open_bus;
    uint8_t hv_scroll_latch;
    uint8_t h_scroll_latch;
    uint8_t forced_blank;
    uint8_t brightness;
    uint8_t oam_mode;
    uint8_t oam_priority;
    uint8_t bg_mode;
    uint8_t mode1_bg3_priority;
    uint8_t mosaic_size;
    uint8_t mosaic_enabled;
    uint8_t mask_logic[6];
    uint8_t window_mask_main;
    uint8_t window_mask_sub;
    uint8_t main_screen_layers;
    uint8_t sub_screen_layers;
    uint8_t color_math_clip_mode;
    uint8_t color_math_prevent_mode;
    uint8_t color_math_add_subscreen;
    uint8_t direct_color;
    uint8_t color_math_enabled;
    uint8_t color_math_subtract;
    uint8_t color_math_half;
    uint8_t external_sync;
    uint8_t extbg;
    uint8_t hires;
    uint8_t overscan;
    uint8_t obj_interlace;
    uint8_t screen_interlace;
    uint8_t time_over;
    uint8_t range_over;
    uint8_t location_latched;
    uint8_t h_location_toggle;
    uint8_t v_location_toggle;

    uint64_t register_reads[JS_V09C_PPU_REG_COUNT];
    uint64_t register_writes[JS_V09C_PPU_REG_COUNT];
    uint8_t observed_read_values[JS_V09C_PPU_REG_COUNT][JS_V09C_VALUE_BITMAP_BYTES];
    uint8_t observed_write_values[JS_V09C_PPU_REG_COUNT][JS_V09C_VALUE_BITMAP_BYTES];
} js_ppu_v09c;

void js_ppu_v09c_power_on(js_ppu_v09c *ppu, js_scheduler_v09c *scheduler,
                          const uint8_t *cpu_open_bus, const uint8_t *wrio);
void js_ppu_v09c_reset(js_ppu_v09c *ppu);
void js_ppu_v09c_scheduler_event(void *opaque, js_scheduler_ppu_event_kind_v09c kind);
js_stop_reason js_ppu_v09c_read8(void *opaque, uint16_t reg, uint8_t *value);
js_stop_reason js_ppu_v09c_write8(void *opaque, uint16_t reg, uint8_t value);
void js_ppu_v09c_set_sprite_flags(js_ppu_v09c *ppu, uint8_t range_over, uint8_t time_over);
int js_ppu_v09c_value_observed(const js_ppu_v09c *ppu, uint16_t reg,
                               int is_write, uint8_t value);
int js_ppu_v09c_vram_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address);
int js_ppu_v09c_cgram_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address);
int js_ppu_v09c_oam_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address);
uint16_t js_ppu_v09c_vram_word_address(const js_ppu_v09c *ppu);
const js_ppu_register_descriptor_v09c *js_ppu_v09c_register_descriptor(uint16_t reg);

#ifdef __cplusplus
}
#endif
#endif
