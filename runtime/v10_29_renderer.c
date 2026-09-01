#include <string.h>
#include "jungle/renderer_v10_29.h"

static js_stop_reason js_v10_29_validate(const js_ppu_v09c *ppu, const void *out) {
    if (!ppu || !out) return JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_29_validate_source_configuration(const js_ppu_v09c *ppu) {
    if (!ppu) return JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
    int source_tile_geometry;
    source_tile_geometry =
        (ppu->layer[0].large_tiles == 1u && ppu->layer[1].large_tiles == 1u) ||
        (ppu->layer[0].large_tiles == 0u && ppu->layer[1].large_tiles == 0u);
    if (ppu->bg_mode != 1u || ppu->mode1_bg3_priority != 1u ||
        !source_tile_geometry ||
        ppu->layer[2].large_tiles != 0u || ppu->layer[3].large_tiles != 0u ||
        ppu->mosaic_enabled != 0u || ppu->mosaic_size != 1u)
        return JS_STOP_V10_29_RENDERER_SOURCE_CONFIG_MISMATCH;
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_29_mode1_layer_desc(const js_ppu_v09c *ppu,
                                                    unsigned layer,
                                                    js_bg_layer_desc_v10_29 *desc) {
    js_stop_reason stop = js_v10_29_validate(ppu, desc);
    if (stop != JS_STOP_NONE) return stop;
    if (layer >= 4u) return JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
    if (ppu->bg_mode != 1u) return JS_STOP_V10_29_RENDERER_UNSUPPORTED_MODE;
    memset(desc, 0, sizeof(*desc));
    if (layer == 0u || layer == 1u) {
        desc->active = 1u;
        desc->bpp = 4u;
        desc->palette_stride = 16u;
    } else if (layer == 2u) {
        desc->active = 1u;
        desc->bpp = 2u;
        desc->palette_stride = 4u;
    } else {
        return JS_STOP_NONE;
    }
    return js_renderer_v10_29_mode1_priority_slot(ppu, layer, 0u, &desc->priority_low_slot) == JS_STOP_NONE &&
           js_renderer_v10_29_mode1_priority_slot(ppu, layer, 1u, &desc->priority_high_slot) == JS_STOP_NONE
           ? JS_STOP_NONE : JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
}

js_stop_reason js_renderer_v10_29_mode1_priority_slot(const js_ppu_v09c *ppu,
                                                       unsigned layer,
                                                       uint8_t tile_priority,
                                                       uint8_t *slot) {
    js_stop_reason stop = js_v10_29_validate(ppu, slot);
    if (stop != JS_STOP_NONE) return stop;
    if (ppu->bg_mode != 1u) return JS_STOP_V10_29_RENDERER_UNSUPPORTED_MODE;
    if (layer >= 3u || tile_priority > 1u)
        return layer == 3u ? JS_STOP_V10_29_RENDERER_INACTIVE_LAYER
                           : JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;

    if (ppu->mode1_bg3_priority) {
        /* Front->back: 3H,S3,1H,2H,S2,1L,2L,S1,S0,3L. */
        static const uint8_t low[3] = {4u, 3u, 0u};
        static const uint8_t high[3] = {7u, 6u, 9u};
        *slot = tile_priority ? high[layer] : low[layer];
    } else {
        /* Front->back: S3,1H,2H,S2,1L,2L,S1,3H,S0,3L. */
        static const uint8_t low[3] = {5u, 4u, 0u};
        static const uint8_t high[3] = {8u, 7u, 2u};
        *slot = tile_priority ? high[layer] : low[layer];
    }
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_29_sample_mode1_bg(const js_ppu_v09c *ppu,
                                                  unsigned layer,
                                                  uint16_t screen_x,
                                                  uint16_t screen_y,
                                                  js_bg_pixel_v10_29 *sample) {
    js_bg_layer_desc_v10_29 desc;
    js_bg_coordinate_v10_28 coord;
    js_tilemap_entry_v10_28 entry;
    js_bg_character_v10_28 chr;
    uint8_t row[JS_V10_28_TILE_PIXELS];
    uint16_t raw;
    uint16_t cgram_index;
    js_stop_reason stop = js_v10_29_validate(ppu, sample);
    if (stop != JS_STOP_NONE) return stop;
    memset(sample, 0, sizeof(*sample));
    if (layer >= 4u) return JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
    if (ppu->mosaic_enabled & (uint8_t)(1u << layer))
        return JS_STOP_V10_29_RENDERER_MOSAIC_UNPROVED;

    stop = js_renderer_v10_29_mode1_layer_desc(ppu, layer, &desc);
    if (stop != JS_STOP_NONE) return stop;
    if (!desc.active) return JS_STOP_V10_29_RENDERER_INACTIVE_LAYER;

    stop = js_renderer_v10_28_bg_resolve_coordinate(ppu, layer, screen_x, screen_y, &coord);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_renderer_v10_28_read_vram_word(ppu, coord.tilemap_word_address, &raw);
    if (stop != JS_STOP_NONE) return stop;
    js_renderer_v10_28_decode_tilemap_entry(raw, &entry);
    stop = js_renderer_v10_28_bg_resolve_character(&entry, coord.logical_tile_pixels,
                                                    coord.fine_x, coord.fine_y, &chr);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_renderer_v10_28_decode_tile_row(ppu, ppu->layer[layer].chr_address,
                                              chr.tile_index, desc.bpp, chr.pixel_y, row);
    if (stop != JS_STOP_NONE) return stop;

    sample->layer = (uint8_t)layer;
    sample->bpp = desc.bpp;
    sample->palette = entry.palette;
    sample->color_index = row[chr.pixel_x];
    sample->tile_priority = entry.priority;
    sample->tilemap_word_address = coord.tilemap_word_address;
    sample->tilemap_raw = raw;
    sample->character_index = chr.tile_index;
    stop = js_renderer_v10_29_mode1_priority_slot(ppu, layer, entry.priority,
                                                  &sample->priority_slot);
    if (stop != JS_STOP_NONE) return stop;

    if (sample->color_index == 0u) {
        sample->transparent = 1u;
        return JS_STOP_NONE;
    }
    cgram_index = (uint16_t)((uint16_t)entry.palette * desc.palette_stride + sample->color_index);
    if (cgram_index >= 128u) return JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT;
    sample->cgram_index = cgram_index;
    stop = js_renderer_v10_28_read_cgram_color(ppu, cgram_index, &sample->bgr555);
    if (stop != JS_STOP_NONE) return stop;
    js_renderer_v10_28_bgr555_to_rgb8(sample->bgr555, &sample->rgb);
    return JS_STOP_NONE;
}
