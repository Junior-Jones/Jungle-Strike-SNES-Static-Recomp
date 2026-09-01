#include <string.h>
#include "jungle/renderer_v10_40.h"
js_stop_reason js_renderer_v10_40_render_scanline(js_ppu_v09c *ppu,uint16_t y,
                                                   js_rgb8_v10_28 pixels[JS_V10_30_VISIBLE_WIDTH]) {
    if(!ppu||!pixels||y>=JS_V10_30_VISIBLE_HEIGHT) return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    if(ppu->forced_blank||ppu->brightness==0u){memset(pixels,0,sizeof(js_rgb8_v10_28)*JS_V10_30_VISIBLE_WIDTH);return JS_STOP_NONE;}
    return js_renderer_v10_30_render_source_scanline(ppu,y,pixels);
}
