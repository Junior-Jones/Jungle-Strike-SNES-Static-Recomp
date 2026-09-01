#include <stddef.h>
#include <string.h>
#include "jungle/renderer_v10_28.h"

static uint8_t js_v10_28_expand5(uint8_t value) {
    return (uint8_t)((value << 3u) | (value >> 2u));
}

static js_stop_reason js_v10_28_validate_ppu_output(const js_ppu_v09c *ppu,
                                                     const void *output) {
    if (!ppu || !output) return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    return JS_STOP_NONE;
}

static int js_v10_28_known(const uint8_t *bits, uint32_t index) {
    return (bits[index >> 3u] & (uint8_t)(1u << (index & 7u))) != 0u;
}

js_stop_reason js_renderer_v10_28_read_vram_byte(const js_ppu_v09c *ppu,
                                                  uint16_t byte_address,
                                                  uint8_t *value) {
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, value);
    uint16_t word;
    if (stop != JS_STOP_NONE) return stop;
    if (!js_v10_28_known(ppu->vram_known, byte_address))
        return JS_STOP_PPU_UNINITIALIZED_MEMORY;
    word = ppu->vram[(uint16_t)(byte_address >> 1u)];
    *value = (byte_address & 1u) ? (uint8_t)(word >> 8u) : (uint8_t)word;
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_read_vram_word(const js_ppu_v09c *ppu,
                                                  uint16_t word_address,
                                                  uint16_t *value) {
    uint16_t address = (uint16_t)(word_address & 0x7FFFu);
    uint16_t low_byte = (uint16_t)(address << 1u);
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, value);
    if (stop != JS_STOP_NONE) return stop;
    if (!js_v10_28_known(ppu->vram_known, low_byte) ||
        !js_v10_28_known(ppu->vram_known, (uint16_t)(low_byte + 1u)))
        return JS_STOP_PPU_UNINITIALIZED_MEMORY;
    *value = ppu->vram[address];
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_read_cgram_color(const js_ppu_v09c *ppu,
                                                    uint16_t color_index,
                                                    uint16_t *bgr555) {
    uint16_t byte_address;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, bgr555);
    if (stop != JS_STOP_NONE) return stop;
    if (color_index >= JS_V09C_CGRAM_WORDS)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    byte_address = (uint16_t)(color_index << 1u);
    if (!js_v10_28_known(ppu->cgram_known, byte_address) ||
        !js_v10_28_known(ppu->cgram_known, (uint16_t)(byte_address + 1u)))
        return JS_STOP_PPU_UNINITIALIZED_MEMORY;
    *bgr555 = (uint16_t)(ppu->cgram[color_index] & 0x7FFFu);
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_read_oam_byte(const js_ppu_v09c *ppu,
                                                 uint16_t byte_address,
                                                 uint8_t *value) {
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, value);
    if (stop != JS_STOP_NONE) return stop;
    if (byte_address >= JS_V09C_OAM_BYTES)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    if (!js_v10_28_known(ppu->oam_known, byte_address))
        return JS_STOP_PPU_UNINITIALIZED_MEMORY;
    *value = ppu->oam[byte_address];
    return JS_STOP_NONE;
}

void js_renderer_v10_28_bgr555_to_rgb8(uint16_t bgr555, js_rgb8_v10_28 *rgb) {
    uint16_t color = (uint16_t)(bgr555 & 0x7FFFu);
    if (!rgb) return;
    rgb->r = js_v10_28_expand5((uint8_t)(color & 0x1Fu));
    rgb->g = js_v10_28_expand5((uint8_t)((color >> 5u) & 0x1Fu));
    rgb->b = js_v10_28_expand5((uint8_t)((color >> 10u) & 0x1Fu));
}

js_stop_reason js_renderer_v10_28_decode_tile_row(const js_ppu_v09c *ppu,
                                                   uint16_t chr_base_word,
                                                   uint16_t tile_index,
                                                   uint8_t bpp,
                                                   uint8_t row,
                                                   uint8_t pixels[JS_V10_28_TILE_PIXELS]) {
    uint16_t base_byte;
    uint16_t tile_bytes;
    uint8_t pair;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, pixels);
    if (stop != JS_STOP_NONE) return stop;
    if (row >= 8u) return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    if (bpp != 2u && bpp != 4u && bpp != 8u)
        return JS_STOP_V10_28_RENDERER_UNSUPPORTED_FORMAT;

    tile_bytes = (uint16_t)(8u * bpp);
    base_byte = (uint16_t)(((uint32_t)(chr_base_word & 0x7FFFu) << 1u) +
                           (uint32_t)tile_index * tile_bytes);
    memset(pixels, 0, JS_V10_28_TILE_PIXELS);

    for (pair = 0u; pair < (uint8_t)(bpp / 2u); ++pair) {
        uint16_t row_address = (uint16_t)(base_byte + (uint16_t)pair * 16u +
                                          (uint16_t)row * 2u);
        uint8_t plane0;
        uint8_t plane1;
        unsigned x;
        stop = js_renderer_v10_28_read_vram_byte(ppu, row_address, &plane0);
        if (stop != JS_STOP_NONE) return stop;
        stop = js_renderer_v10_28_read_vram_byte(ppu, (uint16_t)(row_address + 1u), &plane1);
        if (stop != JS_STOP_NONE) return stop;
        for (x = 0u; x < JS_V10_28_TILE_PIXELS; ++x) {
            unsigned bit = 7u - x;
            pixels[x] |= (uint8_t)(((plane0 >> bit) & 1u) << (pair * 2u));
            pixels[x] |= (uint8_t)(((plane1 >> bit) & 1u) << (pair * 2u + 1u));
        }
    }
    return JS_STOP_NONE;
}

void js_renderer_v10_28_decode_tilemap_entry(uint16_t raw,
                                              js_tilemap_entry_v10_28 *entry) {
    if (!entry) return;
    entry->tile_index = (uint16_t)(raw & 0x03FFu);
    entry->palette = (uint8_t)((raw >> 10u) & 7u);
    entry->priority = (uint8_t)((raw >> 13u) & 1u);
    entry->hflip = (uint8_t)((raw >> 14u) & 1u);
    entry->vflip = (uint8_t)((raw >> 15u) & 1u);
}

js_stop_reason js_renderer_v10_28_bg_map_word_address(const js_ppu_v09c *ppu,
                                                       unsigned layer,
                                                       uint8_t tile_x,
                                                       uint8_t tile_y,
                                                       uint16_t *word_address) {
    const js_ppu_layer_v09c *bg;
    uint8_t width_tiles;
    uint8_t height_tiles;
    uint8_t screen_x;
    uint8_t screen_y;
    uint8_t screens_per_row;
    uint16_t screen_index;
    uint16_t address;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, word_address);
    if (stop != JS_STOP_NONE) return stop;
    if (layer >= 4u) return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    bg = &ppu->layer[layer];
    width_tiles = (uint8_t)(32u << (bg->double_width ? 1u : 0u));
    height_tiles = (uint8_t)(32u << (bg->double_height ? 1u : 0u));
    if (tile_x >= width_tiles || tile_y >= height_tiles)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    screen_x = (uint8_t)(tile_x >> 5u);
    screen_y = (uint8_t)(tile_y >> 5u);
    screens_per_row = bg->double_width ? 2u : 1u;
    screen_index = (uint16_t)(screen_x + screen_y * screens_per_row);
    address = (uint16_t)(bg->tilemap_address + screen_index * JS_V10_28_BG_TILEMAP_WORDS +
                         (uint16_t)(tile_y & 31u) * 32u + (uint16_t)(tile_x & 31u));
    *word_address = (uint16_t)(address & 0x7FFFu);
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_bg_resolve_coordinate(const js_ppu_v09c *ppu,
                                                         unsigned layer,
                                                         uint16_t screen_x,
                                                         uint16_t screen_y,
                                                         js_bg_coordinate_v10_28 *coord) {
    const js_ppu_layer_v09c *bg;
    uint16_t width_pixels;
    uint16_t height_pixels;
    uint8_t tile_pixels;
    uint16_t world_x;
    uint16_t world_y;
    uint8_t tile_x;
    uint8_t tile_y;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, coord);
    if (stop != JS_STOP_NONE) return stop;
    if (layer >= 4u) return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    bg = &ppu->layer[layer];
    tile_pixels = bg->large_tiles ? 16u : 8u;
    width_pixels = (uint16_t)((32u << (bg->double_width ? 1u : 0u)) * tile_pixels);
    height_pixels = (uint16_t)((32u << (bg->double_height ? 1u : 0u)) * tile_pixels);
    world_x = (uint16_t)(((uint32_t)screen_x + bg->h_scroll) & (uint32_t)(width_pixels - 1u));
    world_y = (uint16_t)(((uint32_t)screen_y + bg->v_scroll) & (uint32_t)(height_pixels - 1u));
    tile_x = (uint8_t)(world_x / tile_pixels);
    tile_y = (uint8_t)(world_y / tile_pixels);

    memset(coord, 0, sizeof(*coord));
    coord->world_x = world_x;
    coord->world_y = world_y;
    coord->map_width_pixels = width_pixels;
    coord->map_height_pixels = height_pixels;
    coord->logical_tile_pixels = tile_pixels;
    coord->fine_x = (uint8_t)(world_x & (uint16_t)(tile_pixels - 1u));
    coord->fine_y = (uint8_t)(world_y & (uint16_t)(tile_pixels - 1u));
    coord->tile_x = tile_x;
    coord->tile_y = tile_y;
    return js_renderer_v10_28_bg_map_word_address(ppu, layer, tile_x, tile_y,
                                                   &coord->tilemap_word_address);
}

js_stop_reason js_renderer_v10_28_bg_resolve_character(const js_tilemap_entry_v10_28 *entry,
                                                        uint8_t logical_tile_pixels,
                                                        uint8_t fine_x,
                                                        uint8_t fine_y,
                                                        js_bg_character_v10_28 *character) {
    uint8_t x;
    uint8_t y;
    uint16_t tile;
    if (!entry || !character) return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    if (logical_tile_pixels != 8u && logical_tile_pixels != 16u)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    if (fine_x >= logical_tile_pixels || fine_y >= logical_tile_pixels)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;

    x = entry->hflip ? (uint8_t)(logical_tile_pixels - 1u - fine_x) : fine_x;
    y = entry->vflip ? (uint8_t)(logical_tile_pixels - 1u - fine_y) : fine_y;
    tile = entry->tile_index;
    if (logical_tile_pixels == 16u) {
        tile = (uint16_t)((tile + (uint16_t)(x >> 3u) +
                           ((uint16_t)(y >> 3u) << 4u)) & 0x03FFu);
    }
    character->tile_index = tile;
    character->pixel_x = (uint8_t)(x & 7u);
    character->pixel_y = (uint8_t)(y & 7u);
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_obj_size(uint8_t mode,
                                            uint8_t large,
                                            js_obj_size_v10_28 *size) {
    static const uint8_t sizes[8][4] = {
        { 8u, 8u, 16u, 16u },
        { 8u, 8u, 32u, 32u },
        { 8u, 8u, 64u, 64u },
        { 16u, 16u, 32u, 32u },
        { 16u, 16u, 64u, 64u },
        { 32u, 32u, 64u, 64u },
        { 16u, 32u, 32u, 64u },
        { 16u, 32u, 32u, 32u }
    };
    if (!size || mode >= 8u || large > 1u)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;
    size->width = sizes[mode][large ? 2u : 0u];
    size->height = sizes[mode][large ? 3u : 1u];
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_28_decode_obj(const js_ppu_v09c *ppu,
                                              uint8_t obj_index,
                                              js_obj_record_v10_28 *obj) {
    uint16_t base;
    uint16_t high_address;
    uint8_t xlow;
    uint8_t y;
    uint8_t tile;
    uint8_t attr;
    uint8_t high;
    uint8_t shift;
    uint16_t x9;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, obj);
    if (stop != JS_STOP_NONE) return stop;
    if (obj_index >= JS_V10_28_OBJ_COUNT)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;

    base = (uint16_t)obj_index * 4u;
    stop = js_renderer_v10_28_read_oam_byte(ppu, base, &xlow);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_renderer_v10_28_read_oam_byte(ppu, (uint16_t)(base + 1u), &y);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_renderer_v10_28_read_oam_byte(ppu, (uint16_t)(base + 2u), &tile);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_renderer_v10_28_read_oam_byte(ppu, (uint16_t)(base + 3u), &attr);
    if (stop != JS_STOP_NONE) return stop;
    high_address = (uint16_t)(512u + (obj_index >> 2u));
    stop = js_renderer_v10_28_read_oam_byte(ppu, high_address, &high);
    if (stop != JS_STOP_NONE) return stop;
    shift = (uint8_t)((obj_index & 3u) * 2u);
    x9 = (uint16_t)(xlow | ((uint16_t)((high >> shift) & 1u) << 8u));

    memset(obj, 0, sizeof(*obj));
    obj->x = (x9 & 0x0100u) ? (int16_t)(x9 - 512u) : (int16_t)x9;
    obj->y = y;
    obj->tile_low = tile;
    obj->name_select = (uint8_t)(attr & 1u);
    obj->palette = (uint8_t)((attr >> 1u) & 7u);
    obj->priority = (uint8_t)((attr >> 4u) & 3u);
    obj->hflip = (uint8_t)((attr >> 6u) & 1u);
    obj->vflip = (uint8_t)((attr >> 7u) & 1u);
    obj->large = (uint8_t)((high >> (shift + 1u)) & 1u);
    return js_renderer_v10_28_obj_size(ppu->oam_mode, obj->large, &obj->size);
}

js_stop_reason js_renderer_v10_28_obj_tile_word_address(const js_ppu_v09c *ppu,
                                                         uint8_t tile_low,
                                                         uint8_t name_select,
                                                         uint8_t tile_x,
                                                         uint8_t tile_y,
                                                         uint16_t *word_address) {
    uint8_t column;
    uint8_t row;
    uint8_t resolved_tile;
    uint32_t address;
    js_stop_reason stop = js_v10_28_validate_ppu_output(ppu, word_address);
    if (stop != JS_STOP_NONE) return stop;
    if (name_select > 1u || tile_x >= 16u || tile_y >= 16u)
        return JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT;

    column = (uint8_t)(((tile_low & 0x0Fu) + tile_x) & 0x0Fu);
    row = (uint8_t)((((tile_low >> 4u) + tile_y) & 0x0Fu) << 4u);
    resolved_tile = (uint8_t)(row | column);
    address = (uint32_t)ppu->oam_base_address +
              (name_select ? ppu->oam_address_offset : 0u) +
              (uint32_t)resolved_tile * 16u;
    *word_address = (uint16_t)(address & 0x7FFFu);
    return JS_STOP_NONE;
}
