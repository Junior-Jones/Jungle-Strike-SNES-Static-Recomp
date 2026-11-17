#include "jungle/gameplay_lights_60.h"

static unsigned word(const uint8_t *w,unsigned a){return w[a]|((unsigned)w[a+1u]<<8);}
static unsigned blend(unsigned a,unsigned b,unsigned phase){
    unsigned shift,result=0;
    for(shift=0;shift<15u;shift+=5u){
        unsigned x=(a>>shift)&31u,y=(b>>shift)&31u;
        result|=((x*(8u-phase)+y*phase+4u)/8u)<<shift;
    }
    return result;
}
js_stop_reason jungle_gameplay_lights60_after_instruction(js_machine_v10_40 *m,
                                                        uint8_t bank,uint16_t pc){
    js_cpu65816_state *c;
    js_ppu_v09c *p;
    const js_dma_channel_v09c *dma;
    const uint8_t *rom;
    unsigned index,next,phase,i,colors[4];
    uint8_t address,buffer,latch,open1,open2;
    js_stop_reason stop;
    if(!m||bank!=0x80u||pc!=0x9085u)return JS_STOP_NONE;
    c=&m->cpu_core.cpu;p=&m->ppu;dma=&m->dma.channel[7];
    if(!m->cpu_core.rom_identity_ok||c->pbr!=0x80u||c->pc!=0x9088u||c->e||
       (c->p&JS_FLAG_M)||!(c->p&JS_FLAG_X)||c->d||c->dbr!=0x80u||
       c->waiting||c->stopped||m->scheduler.dma_pending_mask||
       m->dma.active_channel!=255u||dma->dma_active||dma->transfer_size||
       dma->a_bank!=0x80u||dma->b_address!=0x22u||dma->transfer_mode||
       dma->direction_b_to_a||dma->fixed||dma->decrement||
       p->cgram_address!=0x50u||p->cgram_high_latch||
       (!p->forced_blank&&m->scheduler.scanline<m->scheduler.vblank_start_scanline&&
        m->scheduler.scanline!=0u&&m->scheduler.hclock>=88u&&m->scheduler.hclock<1096u))return JS_STOP_NONE;
    index=word(m->bus.base.wram,0x89au);
    if(index&0x8000u)return JS_STOP_NONE;
    index&=6u;next=(index+2u)&6u;
    if(dma->a_address!=0x916bu+index||!m->bus.base.rom||m->bus.base.rom_size<0x1173u)return JS_STOP_NONE;
    phase=word(m->bus.base.wram,0x72u)&7u;
    if(!phase)return JS_STOP_NONE; /* Original colors remain exact at each anchor. */
    rom=m->bus.base.rom;
    for(i=0;i<4u;i++){
        unsigned at=0x1163u+index+2u*i,bt=0x1163u+next+2u*i;
        unsigned a=rom[at]|((unsigned)rom[at+1u]<<8);
        unsigned b=rom[bt]|((unsigned)rom[bt+1u]<<8);
        if((a|b)&0x8000u||p->cgram[0x4cu+i]!=a)return JS_STOP_NONE;
        colors[i]=blend(a,b,phase);
    }
    /* Native four-color DMA has already completed. This bounded graphics
       command adds intermediate colors, without changing its timing, source
       pointers, phase clock or any actor/timer state. Preserve device latches. */
    address=p->cgram_address;buffer=p->cgram_write_buffer;latch=p->cgram_high_latch;
    open1=p->ppu1_open_bus;open2=p->ppu2_open_bus;
    stop=js_ppu_v09c_write8(p,0x2121u,0x4cu);
    for(i=0;i<4u&&stop==JS_STOP_NONE;i++){
        stop=js_ppu_v09c_write8(p,0x2122u,(uint8_t)colors[i]);
        if(stop==JS_STOP_NONE)stop=js_ppu_v09c_write8(p,0x2122u,(uint8_t)(colors[i]>>8));
    }
    p->cgram_address=address;p->cgram_write_buffer=buffer;p->cgram_high_latch=latch;
    p->ppu1_open_bus=open1;p->ppu2_open_bus=open2;
    return stop;
}
