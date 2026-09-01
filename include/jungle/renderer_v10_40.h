#ifndef JUNGLE_RENDERER_V10_40_H
#define JUNGLE_RENDERER_V10_40_H
#include "jungle/renderer_v10_30.h"
#ifdef __cplusplus
extern "C" {
#endif
/* Forced blank is independent of the later source-reached Mode-1 compositor domain. */
js_stop_reason js_renderer_v10_40_render_scanline(js_ppu_v09c *ppu,uint16_t y,
                                                   js_rgb8_v10_28 pixels[JS_V10_30_VISIBLE_WIDTH]);
#ifdef __cplusplus
}
#endif
#endif
