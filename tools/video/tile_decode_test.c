#include "jungle/renderer_v10_28.h"
#include "jungle/renderer_v10_30.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Independent original bit-by-bit decoder, retained as the test oracle. */
static js_stop_reason reference(const js_ppu_v09c *ppu, uint16_t chr,
                                uint16_t tile, uint8_t bpp, uint8_t row,
                                uint8_t out[8]) {
    unsigned pair, x;
    uint16_t base = (uint16_t)(((uint32_t)(chr & 32767u) << 1) + tile * (8u*bpp));
    memset(out, 0, 8);
    for (pair=0; pair<bpp/2u; pair++) {
        uint8_t lo,hi;
        uint16_t address=(uint16_t)(base+pair*16u+row*2u);
        js_stop_reason stop=js_renderer_v10_28_read_vram_byte(ppu,address,&lo);
        if(stop!=JS_STOP_NONE)return stop;
        stop=js_renderer_v10_28_read_vram_byte(ppu,(uint16_t)(address+1u),&hi);
        if(stop!=JS_STOP_NONE)return stop;
        for(x=0;x<8;x++) {
            out[x]|=(uint8_t)(((lo>>(7u-x))&1u)<<(pair*2u));
            out[x]|=(uint8_t)(((hi>>(7u-x))&1u)<<(pair*2u+1u));
        }
    }
    return JS_STOP_NONE;
}
static void write_byte(js_ppu_v09c *ppu, uint16_t address, uint8_t value) {
    uint16_t *word=&ppu->vram[address>>1];
    if(address&1u)*word=(uint16_t)((*word&255u)|((uint16_t)value<<8));
    else *word=(uint16_t)((*word&65280u)|value);
}
static int compare(js_ppu_v09c *ppu,uint16_t chr,uint16_t tile,uint8_t bpp,uint8_t row) {
    uint8_t a[8],b[8];
    js_stop_reason expected=reference(ppu,chr,tile,bpp,row,a);
    js_stop_reason actual=js_renderer_v10_28_decode_tile_row(ppu,chr,tile,bpp,row,b);
    return expected==actual && (actual!=JS_STOP_NONE || !memcmp(a,b,8));
}
static int prepared_rows(void) {
    static const unsigned masks[]={0,1,3,7,19,23};
    static const unsigned scrolls[]={0,7,8,15,511,1023};
    static const unsigned rows[]={0,7,8,15,209,219};
    js_ppu_v09c *fixture=(js_ppu_v09c*)calloc(1,sizeof(*fixture));
    js_ppu_v09c *slow=(js_ppu_v09c*)malloc(sizeof(*slow)),*fast=(js_ppu_v09c*)malloc(sizeof(*fast));
    unsigned large,mask,scroll,row,x,n,layer,cases=0;
    uint32_t seed=12345;
    if(!fixture||!slow||!fast)return 1;
    memset(fixture->vram_known,255,sizeof(fixture->vram_known));
    memset(fixture->cgram_known,255,sizeof(fixture->cgram_known));
    memset(fixture->oam_known,255,sizeof(fixture->oam_known));
    fixture->bg_mode=1;fixture->mode1_bg3_priority=1;fixture->brightness=15;fixture->mosaic_size=1;
    fixture->oam_address_offset=0x1000;
    for(n=0;n<32768;n++){seed=seed*1664525u+1013904223u;fixture->vram[n]=(uint16_t)seed;}
    for(n=0;n<256;n++)fixture->cgram[n]=(uint16_t)((n*313u)&32767u);
    for(n=0;n<128;n++) {
        fixture->oam[n*4]=(uint8_t)(n*13u);fixture->oam[n*4+1]=(uint8_t)(n*7u);
        fixture->oam[n*4+2]=(uint8_t)n;fixture->oam[n*4+3]=(uint8_t)(n*11u);
    }
    for(layer=0;layer<3;layer++) {
        fixture->layer[layer].tilemap_address=(uint16_t)(0x400u*(layer+1));
        fixture->layer[layer].chr_address=(uint16_t)(0x2000u+layer*0x1000u);
        fixture->layer[layer].double_width=1;fixture->layer[layer].double_height=1;
        for(n=0;n<2048;n++)fixture->vram[(fixture->layer[layer].tilemap_address+n)&32767u]=
            (uint16_t)((n&31u)|((n&7u)<<10)|((n&1u)<<13)|((n&2u)<<13)|((n&4u)<<13));
    }
    for(large=0;large<2;large++)for(mask=0;mask<6;mask++)
        for(scroll=0;scroll<6;scroll++)for(row=0;row<6;row++) {
            js_rgb8_v10_28 actual[256],expected[256];
            js_stop_reason a,b=JS_STOP_NONE;
            fixture->layer[0].large_tiles=fixture->layer[1].large_tiles=(uint8_t)large;
            fixture->oam_base_address=large?0x6000:0;
            fixture->main_screen_layers=(uint8_t)masks[mask];
            for(layer=0;layer<3;layer++){
                fixture->layer[layer].h_scroll=(uint16_t)scrolls[scroll];
                fixture->layer[layer].v_scroll=(uint16_t)(scrolls[scroll]+layer*7u);
            }
            /* Mutation between calls proves row caches do not survive a new row. */
            fixture->vram[0x2000u+row]=(uint16_t)(row*311u+scroll);
            *slow=*fixture;*fast=*fixture;
            a=js_renderer_v10_30_render_source_scanline(fast,(uint16_t)rows[row],actual);
            for(x=0;x<256;x++) {
                js_screen_pixel_v10_30 pixel;
                b=js_renderer_v10_30_render_source_pixel(slow,(uint16_t)x,(uint16_t)rows[row],&pixel);
                if(b!=JS_STOP_NONE)break;
                expected[x]=pixel.rgb;
            }
            if(a!=JS_STOP_NONE || a!=b || memcmp(actual,expected,sizeof(actual))) {
                fprintf(stderr,"Prepared mismatch large=%u mask=%u scroll=%u row=%u stops=%u/%u\n",large,masks[mask],scrolls[scroll],rows[row],a,b);return 1;
            }
            cases++;
        }
    /* Unknown character bytes remain unreachable when all layers are hidden. */
    memset(fixture->vram_known,0,sizeof(fixture->vram_known));
    fixture->main_screen_layers=0;*fast=*fixture;
    {js_rgb8_v10_28 output[256];if(js_renderer_v10_30_render_source_scanline(fast,0,output)!=JS_STOP_NONE)return 1;}
    free(fixture);free(slow);free(fast);
    printf("PASS %u prepared/uncached scanline cases: 8/16 tiles, flips, palettes, priorities, scroll wrap, HUD, OBJ and cache reset after VRAM changes\n",cases);
    return 0;
}
int main(void) {
    js_ppu_v09c *ppu=(js_ppu_v09c *)calloc(1,sizeof(*ppu));
    uint32_t seed=0x12345678u;
    unsigned n,bpp,pair;
    if(!ppu)return 1;
    memset(ppu->vram_known,255,sizeof(ppu->vram_known));
    for(n=0;n<65536u;n++) {
        ppu->vram[0]=(uint16_t)n;
        if(!compare(ppu,0,0,2,0))return 2;
    }
    for(bpp=2;bpp<=8;bpp*=2)
        for(n=0;n<16384u;n++) {
            uint16_t chr,tile,base;
            uint8_t row;
            seed=seed*1664525u+1013904223u;chr=(uint16_t)seed;
            seed=seed*1664525u+1013904223u;tile=(uint16_t)(seed&1023u);
            row=(uint8_t)((seed>>12)&7u);
            base=(uint16_t)(((uint32_t)(chr&32767u)<<1)+tile*(8u*bpp));
            for(pair=0;pair<bpp/2u;pair++) {
                seed=seed*1664525u+1013904223u;
                write_byte(ppu,(uint16_t)(base+pair*16u+row*2u),(uint8_t)seed);
                write_byte(ppu,(uint16_t)(base+pair*16u+row*2u+1u),(uint8_t)(seed>>8));
            }
            if(!compare(ppu,chr,tile,(uint8_t)bpp,row))return 3;
        }
    ppu->vram_known[0]=0;
    if(!compare(ppu,0,0,4,0))return 4;
    {
        uint8_t out[8];
        if(js_renderer_v10_28_decode_tile_row(ppu,0,0,3,0,out)!=JS_STOP_V10_28_RENDERER_UNSUPPORTED_FORMAT ||
           js_renderer_v10_28_decode_tile_row(ppu,0,0,4,8,out)!=JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT)return 5;
    }
    free(ppu);
    puts("PASS tile decoding: exhaustive 2bpp plane pairs, 49152 randomized 2/4/8bpp rows with VRAM wrap, unknown memory and invalid formats");
    return prepared_rows();
}
