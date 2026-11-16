#include <string.h>
#include "jungle/renderer_v10_30.h"

static int js_v10_30_inside_window(uint16_t x, uint8_t left, uint8_t right) {
    return left <= right && x >= left && x <= right;
}

static int js_v10_30_window_masked(const js_ppu_v09c *ppu, unsigned layer, uint16_t x) {
    int enabled1, enabled2, value1, value2;
    unsigned logic;
    if (!ppu || layer >= 6u || x >= JS_V10_30_VISIBLE_WIDTH) return 0;
    enabled1 = ppu->window[0].active_layers[layer] != 0u;
    enabled2 = ppu->window[1].active_layers[layer] != 0u;
    value1 = js_v10_30_inside_window(x, ppu->window[0].left, ppu->window[0].right);
    value2 = js_v10_30_inside_window(x, ppu->window[1].left, ppu->window[1].right);
    if (ppu->window[0].inverted_layers[layer]) value1 = !value1;
    if (ppu->window[1].inverted_layers[layer]) value2 = !value2;
    if (!enabled1) return enabled2 ? value2 : 0;
    if (!enabled2) return value1;
    logic = ppu->mask_logic[layer] & 3u;
    if (logic == 0u) return value1 || value2;
    if (logic == 1u) return value1 && value2;
    if (logic == 2u) return value1 != value2;
    return value1 == value2;
}

static int js_v10_30_window_applies(uint8_t mode, int in_window) {
    mode &= 3u;
    if (mode == 0u) return 0;
    if (mode == 1u) return !in_window;
    if (mode == 2u) return in_window;
    return 1;
}


js_stop_reason js_renderer_v10_30_validate_source_display_configuration(const js_ppu_v09c *ppu) {
    js_stop_reason stop;
    if (!ppu) return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    stop=js_renderer_v10_29_validate_source_configuration(ppu);
    if (stop!=JS_STOP_NONE) return stop;
    if (ppu->external_sync || ppu->extbg || ppu->hires || ppu->overscan ||
        ppu->obj_interlace || ppu->screen_interlace) return JS_STOP_V10_30_RENDERER_SETINI_UNPROVED;
    {
        int small_bg12 = ppu->layer[0].large_tiles == 0u && ppu->layer[1].large_tiles == 0u;
        uint16_t expected_obj_base = small_bg12 ? 0x0000u : 0x6000u;
        if (ppu->oam_mode!=0u || ppu->oam_base_address!=expected_obj_base ||
            ppu->oam_address_offset!=0x1000u)
            return JS_STOP_V10_30_RENDERER_OBJ_CONFIG_UNPROVED;
        /* V10.81: TM is source-proved dynamic over the five hardware layer-enable
           bits.  The compositor below now owns BG1/BG2/BG3/OBJ on the main
           plane; BG4 is inactive in Mode 1.  Do not narrow TM merely to the
           two older observed profiles. */
    }
    /* V10.81: under the sealed source-required quotient CGWSEL never selects
       subscreen addition, pseudo-hires is disabled, and windows remain disabled.
       Therefore TS cannot affect the final visible pixel.  CGADSUB and COLDATA
       are consumed by the already-total component math below, including
       add/subtract, half and arbitrary fixed-color values.  Keep rejecting only
       color-window/direct-color/subscreen-add semantics that are not in the
       certified target quotient. */
    if (ppu->color_math_add_subscreen || ppu->direct_color)
        return JS_STOP_V10_30_RENDERER_SOURCE_CONFIG_MISMATCH;
    return JS_STOP_NONE;
}

uint8_t js_renderer_v10_30_obj_priority_slot(const js_ppu_v09c *ppu, uint8_t p) {
    static const uint8_t bg3_high[4]={1u,2u,5u,8u};
    static const uint8_t normal[4]={1u,3u,6u,9u};
    if (!ppu || p>3u) return 0u;
    return ppu->mode1_bg3_priority ? bg3_high[p] : normal[p];
}

static uint8_t js_v10_30_first_sprite(const js_ppu_v09c *ppu) {
    return ppu->oam_priority ? (uint8_t)((ppu->oam_ram_address >> 1u) & 0x7Fu) : 0u;
}

static int js_v10_30_vertical_row(const js_obj_record_v10_28 *obj, uint16_t y, uint8_t *row) {
    uint8_t r=(uint8_t)((uint8_t)y - obj->y);
    if (r>=obj->size.height) return 0;
    *row=r; return 1;
}

static int js_v10_30_horizontal_candidate(const js_obj_record_v10_28 *obj) {
    int x=obj->x, right=x+(int)obj->size.width;
    return x==-256 || (x<256 && right>0);
}

js_stop_reason js_renderer_v10_30_evaluate_obj_scanline(js_ppu_v09c *ppu, uint16_t screen_y,
                                                        js_obj_scanline_v10_30 *line) {
    js_obj_record_v10_28 obj;
    unsigned order;
    unsigned slivers=0u;
    js_stop_reason stop;
    if (!ppu || !line || screen_y>=JS_V10_30_VISIBLE_HEIGHT) return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    memset(line,0,sizeof(*line)); line->first_sprite=js_v10_30_first_sprite(ppu);
    for (order=0u;order<JS_V10_28_OBJ_COUNT;++order) {
        uint8_t idx=(uint8_t)((line->first_sprite+order)&0x7Fu), row;
        stop=js_renderer_v10_28_decode_obj(ppu,idx,&obj); if (stop!=JS_STOP_NONE) return stop;
        if (!js_v10_30_vertical_row(&obj,screen_y,&row) || !js_v10_30_horizontal_candidate(&obj)) continue;
        if (line->selected_count>=JS_V10_30_MAX_LINE_OBJS) { line->range_over=1u; break; }
        line->selected_indices[line->selected_count++]=idx;
    }
    /* Hardware fetches the selected 32 in reverse priority order; only onscreen slivers count,
       except X=-256 which counts every sliver. Retained mask uses onscreen left-to-right sliver positions. */
    for (int pos=(int)line->selected_count-1;pos>=0;--pos) {
        uint8_t idx=line->selected_indices[pos];
        unsigned s, count;
        stop=js_renderer_v10_28_decode_obj(ppu,idx,&obj); if (stop!=JS_STOP_NONE) return stop;
        count=(unsigned)obj.size.width/8u;
        for (s=0u;s<count;++s) {
            int sx=obj.x+(int)(s*8u);
            int count_this=(obj.x==-256) || (sx<256 && sx+8>0);
            if (!count_this) continue;
            if (slivers>=JS_V10_30_MAX_LINE_SLIVERS) { line->time_over=1u; continue; }
            line->retained_sliver_mask[pos]|=(uint8_t)(1u<<s); ++slivers;
        }
    }
    /* V09C explicitly reserves these status bits for the renderer.  Write the
       owned state directly so the focused renderer layer does not depend on the
       full historical PPU implementation library. */
    ppu->range_over=(uint8_t)(line->range_over!=0u);
    ppu->time_over=(uint8_t)(line->time_over!=0u);
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_30_sample_obj_pixel(const js_ppu_v09c *ppu,
                                                   const js_obj_scanline_v10_30 *line,
                                                   uint16_t screen_x, uint16_t screen_y,
                                                   js_obj_pixel_v10_30 *pixel) {
    unsigned pos; js_stop_reason stop; js_obj_record_v10_28 obj;
    if (!ppu || !line || !pixel || screen_x>=JS_V10_30_VISIBLE_WIDTH || screen_y>=JS_V10_30_VISIBLE_HEIGHT)
        return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    memset(pixel,0,sizeof(*pixel)); pixel->transparent=1u;
    for (pos=0u;pos<line->selected_count;++pos) {
        int local_x; uint8_t local_y, screen_sliver, px,py,tile_x,tile_y,row[8],color; uint16_t tile_word,cg;
        stop=js_renderer_v10_28_decode_obj(ppu,line->selected_indices[pos],&obj); if (stop!=JS_STOP_NONE) return stop;
        local_x=(int)screen_x-obj.x;
        if (local_x<0 || local_x>=(int)obj.size.width) continue;
        if (!js_v10_30_vertical_row(&obj,screen_y,&local_y)) continue;
        screen_sliver=(uint8_t)((unsigned)local_x>>3u);
        if ((line->retained_sliver_mask[pos]&(uint8_t)(1u<<screen_sliver))==0u) continue;
        px=(uint8_t)local_x; py=local_y;
        if (obj.hflip) px=(uint8_t)(obj.size.width-1u-px);
        if (obj.vflip) py=(uint8_t)(obj.size.height-1u-py);
        tile_x=(uint8_t)(px>>3u); tile_y=(uint8_t)(py>>3u);
        stop=js_renderer_v10_28_obj_tile_word_address(ppu,obj.tile_low,obj.name_select,tile_x,tile_y,&tile_word);
        if (stop!=JS_STOP_NONE) return stop;
        stop=js_renderer_v10_28_decode_tile_row(ppu,tile_word,0u,4u,(uint8_t)(py&7u),row);
        if (stop!=JS_STOP_NONE) return stop;
        color=row[px&7u]; if (!color) continue;
        cg=(uint16_t)(128u+(uint16_t)obj.palette*16u+color);
        pixel->transparent=0u; pixel->obj_index=line->selected_indices[pos]; pixel->palette=obj.palette;
        pixel->priority=obj.priority; pixel->priority_slot=js_renderer_v10_30_obj_priority_slot(ppu,obj.priority);
        pixel->color_index=color; pixel->screen_sliver=screen_sliver; pixel->cgram_index=cg;
        stop=js_renderer_v10_28_read_cgram_color(ppu,cg,&pixel->bgr555); if (stop!=JS_STOP_NONE) return stop;
        js_renderer_v10_28_bgr555_to_rgb8(pixel->bgr555,&pixel->rgb); return JS_STOP_NONE;
    }
    return JS_STOP_NONE;
}

static uint8_t js_v10_30_channel(uint16_t c,unsigned sh) { return (uint8_t)((c>>sh)&31u); }
static uint8_t js_v10_30_mix_ch(uint8_t a,uint8_t b,uint8_t sub,uint8_t half) {
    int v=sub ? (int)a-(int)b : (int)a+(int)b;
    if (v<0) v=0;
    if (v>31) v=31;
    if (half) v>>=1;
    return (uint8_t)v;
}
uint16_t js_renderer_v10_30_color_math(uint16_t main_color,uint16_t addend,uint8_t subtract,uint8_t half) {
    uint8_t r=js_v10_30_mix_ch(js_v10_30_channel(main_color,0),js_v10_30_channel(addend,0),subtract,half);
    uint8_t g=js_v10_30_mix_ch(js_v10_30_channel(main_color,5),js_v10_30_channel(addend,5),subtract,half);
    uint8_t b=js_v10_30_mix_ch(js_v10_30_channel(main_color,10),js_v10_30_channel(addend,10),subtract,half);
    return (uint16_t)(r|((uint16_t)g<<5u)|((uint16_t)b<<10u));
}
uint16_t js_renderer_v10_30_apply_brightness(uint16_t color,uint8_t brightness) {
    unsigned br=brightness&15u;
    uint8_t r=(uint8_t)((js_v10_30_channel(color,0)*br)/15u);
    uint8_t g=(uint8_t)((js_v10_30_channel(color,5)*br)/15u);
    uint8_t b=(uint8_t)((js_v10_30_channel(color,10)*br)/15u);
    return br ? (uint16_t)(r|((uint16_t)g<<5u)|((uint16_t)b<<10u)) : 0u;
}

static void js_v10_30_plane_backdrop(js_screen_plane_pixel_v10_30 *p,uint16_t c) {
    memset(p,0,sizeof(*p)); p->source=JS_PIXEL_V10_30_BACKDROP; p->priority_slot=0u; p->bgr555=c;
}
static void js_v10_30_consider_bg(js_screen_plane_pixel_v10_30 *dst,const js_bg_pixel_v10_29 *bg) {
    if (bg->transparent) return;
    if (dst->source==JS_PIXEL_V10_30_BACKDROP || bg->priority_slot>dst->priority_slot) {
        dst->source=(js_pixel_source_v10_30)bg->layer; dst->transparent=0u; dst->priority_slot=bg->priority_slot; dst->bgr555=bg->bgr555;
    }
}
static void js_v10_30_consider_obj(js_screen_plane_pixel_v10_30 *dst,const js_obj_pixel_v10_30 *obj) {
    if (obj->transparent) return;
    if (dst->source==JS_PIXEL_V10_30_BACKDROP || obj->priority_slot>dst->priority_slot) {
        dst->source=JS_PIXEL_V10_30_OBJ; dst->transparent=0u; dst->priority_slot=obj->priority_slot;
        dst->obj_palette=obj->palette; dst->bgr555=obj->bgr555;
    }
}
static int js_v10_30_math_enabled(const js_ppu_v09c *ppu,const js_screen_plane_pixel_v10_30 *p) {
    unsigned bit=(unsigned)p->source;
    if (bit>5u || !(ppu->color_math_enabled&(1u<<bit))) return 0;
    if (p->source==JS_PIXEL_V10_30_OBJ && p->obj_palette<4u) return 0;
    return 1;
}

static js_stop_reason js_v10_30_render_source_pixel_prepared(
    js_ppu_v09c *ppu, uint16_t x, uint16_t y, uint16_t backdrop,
    const js_obj_scanline_v10_30 *prepared_obj_line,
    js_screen_pixel_v10_30 *pixel) {
    js_stop_reason stop; js_bg_pixel_v10_29 bg; js_obj_pixel_v10_30 obj;
    if (!ppu || !pixel || x>=JS_V10_30_VISIBLE_WIDTH || y>=JS_V10_30_VISIBLE_HEIGHT)
        return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    memset(pixel,0,sizeof(*pixel)); pixel->brightness=ppu->brightness;
    if (ppu->forced_blank) { pixel->forced_blank=1u; pixel->main_pixel.source=JS_PIXEL_V10_30_BACKDROP; pixel->sub_pixel.source=JS_PIXEL_V10_30_BACKDROP; return JS_STOP_NONE; }
    js_v10_30_plane_backdrop(&pixel->main_pixel,backdrop); js_v10_30_plane_backdrop(&pixel->sub_pixel,backdrop);
    if ((ppu->main_screen_layers&0x01u) && !((ppu->window_mask_main&0x01u) && js_v10_30_window_masked(ppu,0u,x))) { stop=js_renderer_v10_29_sample_mode1_bg(ppu,0u,x,y,&bg); if (stop!=JS_STOP_NONE) return stop; js_v10_30_consider_bg(&pixel->main_pixel,&bg); }
    if ((ppu->main_screen_layers&0x02u) && !((ppu->window_mask_main&0x02u) && js_v10_30_window_masked(ppu,1u,x))) { stop=js_renderer_v10_29_sample_mode1_bg(ppu,1u,x,y,&bg); if (stop!=JS_STOP_NONE) return stop; js_v10_30_consider_bg(&pixel->main_pixel,&bg); }
    if ((ppu->main_screen_layers&0x04u) && !((ppu->window_mask_main&0x04u) && js_v10_30_window_masked(ppu,2u,x))) { stop=js_renderer_v10_29_sample_mode1_bg(ppu,2u,x,y,&bg); if (stop!=JS_STOP_NONE) return stop; js_v10_30_consider_bg(&pixel->main_pixel,&bg); }
    if (prepared_obj_line && (ppu->main_screen_layers&0x10u) && !((ppu->window_mask_main&0x10u) && js_v10_30_window_masked(ppu,4u,x))) { stop=js_renderer_v10_30_sample_obj_pixel(ppu,prepared_obj_line,x,y,&obj); if (stop!=JS_STOP_NONE) return stop; js_v10_30_consider_obj(&pixel->main_pixel,&obj); }
    if (ppu->color_math_add_subscreen && (ppu->sub_screen_layers&0x04u) && !((ppu->window_mask_sub&0x04u) && js_v10_30_window_masked(ppu,2u,x))) { stop=js_renderer_v10_29_sample_mode1_bg(ppu,2u,x,y,&bg); if (stop!=JS_STOP_NONE) return stop; js_v10_30_consider_bg(&pixel->sub_pixel,&bg); }
    {
        int color_window = js_v10_30_window_masked(ppu,5u,x);
        int clip = js_v10_30_window_applies(ppu->color_math_clip_mode,color_window);
        int prevent = js_v10_30_window_applies(ppu->color_math_prevent_mode,color_window);
        pixel->pre_brightness_bgr555=clip?0u:pixel->main_pixel.bgr555;
        if (!prevent && js_v10_30_math_enabled(ppu,&pixel->main_pixel)) {
            uint16_t addend=ppu->color_math_add_subscreen?pixel->sub_pixel.bgr555:ppu->fixed_color;
            pixel->pre_brightness_bgr555=js_renderer_v10_30_color_math(pixel->pre_brightness_bgr555,addend,ppu->color_math_subtract,ppu->color_math_half);
            pixel->color_math_applied=1u;
        }
    }
    pixel->final_bgr555=js_renderer_v10_30_apply_brightness(pixel->pre_brightness_bgr555,ppu->brightness);
    js_renderer_v10_28_bgr555_to_rgb8(pixel->final_bgr555,&pixel->rgb);
    return JS_STOP_NONE;
}

js_stop_reason js_renderer_v10_30_render_source_pixel(js_ppu_v09c *ppu,
                                                       uint16_t x,uint16_t y,
                                                       js_screen_pixel_v10_30 *pixel) {
    js_stop_reason stop;
    uint16_t backdrop = 0u;
    js_obj_scanline_v10_30 line;
    const js_obj_scanline_v10_30 *prepared_obj_line = NULL;
    if (!ppu || !pixel || x>=JS_V10_30_VISIBLE_WIDTH || y>=JS_V10_30_VISIBLE_HEIGHT)
        return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    stop=js_renderer_v10_30_validate_source_display_configuration(ppu);
    if (stop!=JS_STOP_NONE) return stop;
    if (!ppu->forced_blank) {
        stop=js_renderer_v10_28_read_cgram_color(ppu,0u,&backdrop);
        if (stop!=JS_STOP_NONE) return stop;
        if (ppu->main_screen_layers&0x10u) {
            stop=js_renderer_v10_30_evaluate_obj_scanline(ppu,y,&line);
            if (stop!=JS_STOP_NONE) return stop;
            prepared_obj_line=&line;
        }
    }
    return js_v10_30_render_source_pixel_prepared(
        ppu,x,y,backdrop,prepared_obj_line,pixel);
}

js_stop_reason js_renderer_v10_30_render_source_scanline(js_ppu_v09c *ppu, uint16_t y,
                                                          js_rgb8_v10_28 pixels[JS_V10_30_VISIBLE_WIDTH]) {
    js_stop_reason stop;
    uint16_t backdrop = 0u;
    uint16_t x;
    js_obj_scanline_v10_30 line;
    const js_obj_scanline_v10_30 *prepared_obj_line = NULL;
    if (!ppu || !pixels || y>=JS_V10_30_VISIBLE_HEIGHT)
        return JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
    stop=js_renderer_v10_30_validate_source_display_configuration(ppu);
    if (stop!=JS_STOP_NONE) return stop;
    if (!ppu->forced_blank) {
        stop=js_renderer_v10_28_read_cgram_color(ppu,0u,&backdrop);
        if (stop!=JS_STOP_NONE) return stop;
        /* Match Mesen's scanline ownership: OAM is evaluated once for the
           completed line, then the cached selection is sampled by each pixel.
           The old path rescanned and decoded all 128 OAM entries 256 times. */
        if (ppu->main_screen_layers&0x10u) {
            stop=js_renderer_v10_30_evaluate_obj_scanline(ppu,y,&line);
            if (stop!=JS_STOP_NONE) return stop;
            prepared_obj_line=&line;
        }
    }
    for (x=0u;x<JS_V10_30_VISIBLE_WIDTH;++x) {
        js_screen_pixel_v10_30 sample;
        stop=js_v10_30_render_source_pixel_prepared(
            ppu,x,y,backdrop,prepared_obj_line,&sample);
        if (stop!=JS_STOP_NONE) return stop;
        pixels[x]=sample.rgb;
    }
    return JS_STOP_NONE;
}
