#include "jungle/gameplay_water_60.h"
#include "jungle/renderer_v10_30.h"
#include <string.h>

/* Native 903E publishes five palette-zero colors, but advances its circular
   source window only every eight physical fields. Interpolate their actual
   RGB8 output, because adjacent native RGB5 levels can differ by only one.
   The native palette, DMA, timing, CPU flags and game counters stay untouched. */
static unsigned word(const uint8_t *w,unsigned a){return w[a]|((unsigned)w[a+1u]<<8u);}
static uint8_t mix8(uint8_t a,uint8_t b,unsigned f){
    return (uint8_t)(((unsigned)a*(8u-f)+(unsigned)b*f+4u)/8u);
}
static js_rgb8_v10_28 blend(js_rgb8_v10_28 a,js_rgb8_v10_28 b,unsigned f){
    js_rgb8_v10_28 out;out.r=mix8(a.r,b.r,f);out.g=mix8(a.g,b.g,f);out.b=mix8(a.b,b.b,f);return out;
}
static int native_program(const js_machine_v10_40 *m){
    static const uint8_t bytes[]={0x8e,0x0b,0x42,0xa5,0x72,0x29,0x07,0x00,0xd0,0x1b};
    js_bus_mapping_v06c map=js_bus_v06c_map(&m->bus.base,0x80903eu);
    return map.mapped&&map.region==JS_BUS_REGION_ROM&&
        map.physical_offset+sizeof(bytes)<=m->bus.base.rom_size&&
        !memcmp(m->bus.base.rom+map.physical_offset,bytes,sizeof(bytes));
}
static int source_word(const js_machine_v10_40 *m,unsigned address,uint16_t *out){
    js_bus_mapping_v06c a,b;
    if(address<0x8000u||address>=0xffffu)return 0;
    a=js_bus_v06c_map(&m->bus.base,0x800000u|address);
    b=js_bus_v06c_map(&m->bus.base,0x800000u|(address+1u));
    if(!a.mapped||!b.mapped||a.region!=JS_BUS_REGION_ROM||b.region!=JS_BUS_REGION_ROM||
       a.physical_offset>=m->bus.base.rom_size||b.physical_offset>=m->bus.base.rom_size)return 0;
    *out=(uint16_t)(m->bus.base.rom[a.physical_offset]|((unsigned)m->bus.base.rom[b.physical_offset]<<8u));return 1;
}
int jungle_gameplay_water60_palette(const js_machine_v10_40 *m,JungleWater60Palette *out){
    JungleWater60Palette result;
    const uint8_t *w;
    unsigned base,phase,found=0,matches=0,i,next,ram_phase,irq;
    uint16_t colors[10];
    if(!m||!out||!m->cpu_core.rom_identity_ok||!m->bus.base.rom)return 0;
    w=m->bus.base.wram;base=word(w,0x8a0u);ram_phase=word(w,0x898u);irq=word(w,5u);
    if(w[4]!=0x5cu||w[7]!=0x80u||(irq!=0x90e2u&&irq!=0x89d6u)||
       ram_phase>8u||(ram_phase&1u)||
       (base!=0x9113u&&base!=0x9127u&&base!=0x913bu)||!native_program(m))return 0;
    for(i=0;i<10u;i++)if(!source_word(m,base+i*2u,&colors[i])||(colors[i]&0x8000u))return 0;
    for(i=0;i<5u;i++)if(!js_ppu_v09c_cgram_byte_known(&m->ppu,(uint16_t)((0x11u+i)*2u))||
        !js_ppu_v09c_cgram_byte_known(&m->ppu,(uint16_t)((0x11u+i)*2u+1u)))return 0;
    /* CGRAM is authoritative: 9060 advances RAM after the first palette DMA,
       so its source window can already name the NEXT phase at visible line0. */
    for(phase=0;phase<5u;phase++){
        for(i=0;i<5u;i++)if((m->ppu.cgram[0x11u+i]&0x7fffu)!=colors[phase+i])break;
        if(i==5u){found=phase;matches++;}
    }
    if(matches!=1u||!(found*2u==ram_phase||found*2u==(ram_phase?ram_phase-2u:8u)))return 0;
    memset(&result,0,sizeof(result));result.phase=(uint8_t)((word(w,0x72u)+7u)&7u);
    result.source_offset=(uint16_t)(found*2u);next=found==4u?0u:found+1u;
    for(i=0;i<5u;i++){
        js_rgb8_v10_28 a,b;
        result.current_bgr555[i]=colors[found+i];result.next_bgr555[i]=colors[next+i];
        js_renderer_v10_28_bgr555_to_rgb8(colors[found+i],&a);
        js_renderer_v10_28_bgr555_to_rgb8(colors[next+i],&b);
        result.rgb8[i]=blend(a,b,result.phase);
    }
    *out=result;return 1;
}
static int water_index(const JungleWater60Palette *p,unsigned index,uint16_t current){
    return index>=0x11u&&index<0x16u&&
        (current&0x7fffu)==p->current_bgr555[index-0x11u];
}
void jungle_gameplay_water60_shade(const JungleWater60Palette *p,const js_ppu_v09c *ppu,
                                   const js_screen_pixel_v10_30 *pixel,js_rgb8_v10_28 *out){
    uint16_t main_color,addend=0u,native_addend=0u,color;
    js_rgb8_v10_28 next;
    unsigned changed=0u,main_water=0u;
    if(!pixel||!out)return;
    *out=pixel->rgb;
    if(!p||!ppu||!p->phase||p->phase>7u||pixel->forced_blank)return;
    main_color=pixel->color_clipped?0u:pixel->main_pixel.bgr555;
    if(!pixel->color_clipped&&water_index(p,pixel->main_pixel.cgram_index,main_color)){
        uint16_t replacement=p->next_bgr555[pixel->main_pixel.cgram_index-0x11u];
        main_water=1u;changed|=replacement!=main_color;main_color=replacement;
    }
    if(pixel->color_math_applied){
        addend=ppu->color_math_add_subscreen?pixel->sub_pixel.bgr555:ppu->fixed_color;native_addend=addend;
        if(ppu->color_math_add_subscreen&&water_index(p,pixel->sub_pixel.cgram_index,addend)){
            uint16_t replacement=p->next_bgr555[pixel->sub_pixel.cgram_index-0x11u];
            changed|=replacement!=addend;addend=replacement;
        }
    }
    if(!changed)return;
    /* Add/subtract zero without halving is exactly the native identity.
       The black subscreen is common over water: reuse the once-per-field RGB8
       result rather than repeat RGB5 math/brightness/expansion per pixel. */
    if(main_water&&pixel->brightness==15u&&
       (!pixel->color_math_applied||(!ppu->color_math_half&&!addend&&!native_addend))){
        *out=p->rgb8[pixel->main_pixel.cgram_index-0x11u];return;
    }
    color=main_color;
    if(pixel->color_math_applied)
        color=js_renderer_v10_30_color_math(color,addend,ppu->color_math_subtract,ppu->color_math_half);
    color=js_renderer_v10_30_apply_brightness(color,pixel->brightness);
    js_renderer_v10_28_bgr555_to_rgb8(color,&next);
    *out=blend(pixel->rgb,next,p->phase);
}
