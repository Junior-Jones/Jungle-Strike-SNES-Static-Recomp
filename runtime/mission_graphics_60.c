#include "jungle/mission_graphics_60.h"
#include <stdlib.h>
#include <string.h>

/* Host graphics commands replace only audited pure graphics kernels. The
   original call/prologue/epilogue, staging-buffer ownership and DMA waits stay
   native. Each atomic command costs two master clocks; the next native
   instruction retains normal interrupt arbitration. No game timers, fuel,
   movement, weapon logic or audio clock is accelerated. Unsupported inputs
   leave the entire machine untouched and continue through the native kernel. */
typedef struct Decoded {
    uint8_t bytes[65536];
    unsigned size,consumed;
    uint16_t eb,ef;
} Decoded;
static unsigned u16(const uint8_t *w,unsigned a){return w[a]|((unsigned)w[a+1]<<8);}
static void put16(uint8_t *w,unsigned a,unsigned n){w[a]=(uint8_t)n;w[a+1]=(uint8_t)(n>>8);}
static int source_byte(const js_machine_v10_40 *m, uint32_t source, unsigned *at, unsigned *value) {
    js_bus_mapping_v06c map;
    if (*at >= 65535 || source + *at >= 0x1000000u) return 0;
    map = js_bus_v06c_map(&m->bus.base, source + *at);
    if (!map.mapped || map.region != JS_BUS_REGION_ROM || map.physical_offset >= m->bus.base.rom_size) return 0;
    *value = m->bus.base.rom[map.physical_offset]; (*at)++; return 1;
}
static int emit(Decoded *d, unsigned value) {
    if (d->size >= 65535) return 0;
    d->bytes[d->size++] = (uint8_t)value; return 1;
}
static int copy_back(Decoded *d, unsigned distance, unsigned length) {
    unsigned i;
    if (!distance || distance > d->size) return 0;
    /* Read each byte AFTER earlier writes: overlapping forward copies matter. */
    for (i=0;i<length;i++) if (!emit(d,d->bytes[d->size-distance])) return 0;
    return 1;
}
static int decode_native_format(const js_machine_v10_40 *m, uint32_t source, Decoded *d) {
    unsigned at=0,cmd,n,i,a,b,distance,length;
    d->size=0;
    for (;;) {
        if (!source_byte(m,source,&at,&cmd)) return 0;
        if (!cmd) { d->consumed=at; return 1; }
        d->ef=(uint16_t)((d->ef&0xff00u)|cmd);
        if (cmd<0x40) {

            for(i=0;i<(cmd&63);i++) if(!source_byte(m,source,&at,&a)||!emit(d,a))return 0;
        } else if(cmd<0x50) {
            d->eb=(uint16_t)at;n=(cmd&15)+3;
            if(d->size<2)return 0;
            a=d->bytes[d->size-1];b=(a-d->bytes[d->size-2])&255;
            d->ef=(uint16_t)(a|(b<<8));
            for(i=0;i<n;i++){a=(a+b)&255;if(!emit(d,a))return 0;}
        } else if(cmd<0x60) {
            d->eb=(uint16_t)at;n=(cmd&15)+2;
            if(d->size<4)return 0;
            a=u16(d->bytes,d->size-2);b=(a-u16(d->bytes,d->size-4))&65535;
            d->ef=(uint16_t)b;
            for(i=0;i<n;i++){a=(a+b)&65535;if(!emit(d,a)||!emit(d,a>>8))return 0;}
        } else if(cmd<0x70) {
            d->eb=(uint16_t)at;n=(cmd&15)+3;
            if(!d->size)return 0;a=d->bytes[d->size-1];
            d->ef=(uint16_t)((d->ef&0xff00u)|a);
            for(i=0;i<n;i++)if(!emit(d,a))return 0;
        } else if(cmd<0x80) {
            d->eb=(uint16_t)at;n=(cmd&15)+2;
            if(d->size<2)return 0;a=u16(d->bytes,d->size-2);
            for(i=0;i<n;i++)if(!emit(d,a)||!emit(d,a>>8))return 0;
        } else if(cmd<0xc0) {
            d->eb=(uint16_t)at;
            if(!copy_back(d,(cmd&63)+3,3))return 0;
        } else if(cmd<0xe0) {

            if(!source_byte(m,source,&at,&a))return 0;d->eb=(uint16_t)at;
            distance=((cmd&3)<<8)+a+3;length=((cmd&0x1c)>>2)+4;
            if(!copy_back(d,distance,length))return 0;
        } else {

            if(!source_byte(m,source,&at,&a)||!source_byte(m,source,&at,&b))return 0;
            d->eb=(uint16_t)at;d->ef=(uint16_t)((d->ef&0xff00u)|b);
            distance=((cmd&31)<<8)+a+3;length=b+5;
            if(!copy_back(d,distance,length))return 0;
        }
    }
}

static void convert_tiles(uint8_t *bytes,unsigned size,uint8_t last[32]) {
    unsigned tile,row,x,plane;
    for(tile=0;tile<size;tile+=32) {
        uint8_t out[32]={0};
        for(row=0;row<8;row++)for(x=0;x<8;x++) {
            unsigned packed=bytes[tile+row*4+x/2];
            unsigned pixel=(x&1)?packed&15:packed>>4;
            for(plane=0;plane<4;plane++)
                out[(plane/2)*16+row*2+(plane&1)]|=(uint8_t)(((pixel>>plane)&1)<<(7-x));
        }
        memcpy(bytes+tile,out,32);memcpy(last,out,32);
    }
}


static int mission_type1(const js_machine_v10_40 *m){
    const uint8_t *w=m->bus.base.wram;
    uint32_t descriptor=u16(w,0xc25)|((uint32_t)w[0xc27]<<16);
    js_bus_mapping_v06c map=js_bus_v06c_map(&m->bus.base,descriptor+1u);
    uint8_t kind;
    if(u16(w,0xc0b)!=0x83fbu||!map.mapped||
       (map.region!=JS_BUS_REGION_ROM&&map.region!=JS_BUS_REGION_WRAM))return 0;
    return js_bus_v06c_peek8(&m->bus.base,descriptor+1u,&kind)==JS_STOP_NONE&&kind==1u;
}

static int gameover_source(uint32_t source){
    return source==0xb9e9ecu||source==0xb8c67bu||
           source==0xb9ec3cu||source==0xb9ee87u;
}
int jungle_mission60_gameover_context(const js_machine_v10_40 *m){
    const uint8_t *w;
    if(!m)return 0;
    w=m->bus.base.wram;
    return u16(w,0xc0b)==0x8276u&&u16(w,0xc95)==0x17u&&
           u16(w,0xc8d)==0x2eu&&u16(w,0xc8f)==0u&&
           u16(w,0xc99)==0xa409u&&u16(w,0xc9b)==0xa2u&&
           u16(w,0xc9f)==10u&&u16(w,0xca1)==5u;
}
static int graphics_context(const js_machine_v10_40 *m){
    const js_cpu65816_state *c=&m->cpu_core.cpu;
    const uint8_t *w=m->bus.base.wram;
    if(c->pc!=0xc755u&&mission_type1(m))return 1;
    /* The controller-selected Copilot portrait and its tilemap are native
       commands A970/AE92. Do not admit unrelated generic scene8276 scripts. */
    if(c->pc!=0xc755u&&u16(w,0xc0b)==0x8276u&&u16(w,0xc8d)==0u&&
       u16(w,0xc8f)==0x0fu&&u16(w,0xc0f)==0x92e2u&&
       (u16(w,0xc8b)==6u||u16(w,0xc8b)==12u))return 1;
    /* Four immutable fire frames in the genuine exhausted-lives screen.
       Require the literal native producer's saved return, not just a scene. */
    if(!jungle_mission60_gameover_context(m))return 0;
    if(c->pc==0xe450u){
        uint32_t source=((uint32_t)(c->a&255u)<<16)|c->x;
        return c->sp<=0x1ffcu&&u16(w,c->sp+1u)==0xc65bu&&
               w[c->sp+3u]==0xa0u&&(c->a>>8)==0x7eu&&
               c->y==0x5000u&&gameover_source(source);
    }
    if(c->pc==0xc755u){
        uint32_t source=u16(w,0xce3)|((uint32_t)w[0xce5]<<16);
        return c->sp<=0x1ff4u&&u16(w,c->sp+10u)==0xc67du&&
               w[c->sp+1u]==0xa0u&&u16(w,c->sp+2u)==0x0c00u&&
               u16(w,0xc11)==100u&&gameover_source(source);
    }
    return 0;
}

js_stop_reason jungle_mission60_after_instruction(js_machine_v10_40 *m){
    js_cpu65816_state *c;
    uint8_t *w;
    if(!m)return JS_STOP_NONE;
    c=&m->cpu_core.cpu;
    if(c->pbr!=0xa0u||(c->pc!=0xe450u&&c->pc!=0xd12fu&&c->pc!=0xc755u)||c->e||
       (c->p&(JS_FLAG_M|JS_FLAG_X|JS_FLAG_D))||c->waiting||c->stopped||
       m->scheduler.nmi_pending||
       (js_scheduler_v09c_irq_asserted(&m->scheduler)&&!(c->p&JS_FLAG_I))||
       m->scheduler.dma_pending_mask||m->scheduler.hdma_init_pending||
       m->scheduler.hdma_line_pending||m->scheduler.cpu_stall_clocks||
       m->bus.base.math.multiply_cycles_remaining||m->bus.base.math.divide_cycles_remaining||
       !graphics_context(m))return JS_STOP_NONE;
    w=m->bus.base.wram;
    if(c->pc==0xe450u){
        uint32_t source=((uint32_t)(c->a&255u)<<16)|c->x;
        unsigned destination=(((c->a>>8)&1u)<<16)|c->y;
        unsigned sum,dp=c->d;
        uint8_t flags;
        Decoded *d;
        /* The original absolute218x stores must address the WRAM port.
           The audited producers restore DBR=A0 before calling. */
        if(dp!=0xc00u||c->dbr!=0xa0u)return JS_STOP_NONE;
        d=(Decoded*)malloc(sizeof(*d));if(!d)return JS_STOP_NONE;
        d->eb=(uint16_t)u16(w,dp+0xeb);d->ef=(uint16_t)u16(w,dp+0xef);
        if(!decode_native_format(m,source,d)||destination+d->size>0x20000u||
           (unsigned)c->y+d->size>65535u||
           (destination<dp+0xf1u&&destination+d->size>dp+0xe3u)){
            free(d);return JS_STOP_NONE;
        }
        sum=(unsigned)c->y+d->size;
        flags=(uint8_t)(c->p&~(JS_FLAG_M|JS_FLAG_X|JS_FLAG_N|JS_FLAG_Z|JS_FLAG_C|JS_FLAG_V));
        if(!d->size)flags|=JS_FLAG_Z;if(d->size&0x8000u)flags|=JS_FLAG_N;
        if(sum>65535u)flags|=JS_FLAG_C;
        if(((c->y^sum)&(d->size^sum)&0x8000u)!=0)flags|=JS_FLAG_V;
        put16(w,dp+0xe3,c->x);w[dp+0xe5]=(uint8_t)c->a;
        put16(w,dp+0xe7,c->y);w[dp+0xe9]=(uint8_t)(0x7eu+((c->a>>8)&1u));
        memcpy(w+destination,d->bytes,d->size);
        put16(w,dp+0xeb,d->eb);put16(w,dp+0xed,d->size);put16(w,dp+0xef,d->ef);
        m->bus.base.wram_port_address=destination+d->size;
        c->x=(uint16_t)(c->x+d->consumed);c->y=(uint16_t)sum;c->a=(uint16_t)d->size;
        c->p=flags;c->pc=0xe480u;
        m->bus.base.open_bus=(uint8_t)(d->size>>8);m->bus.cpu_speed_clocks=8u;
        free(d);
    }else{
        unsigned size=u16(w,0x7a8)*32u,start=c->y,end=start+size;
        unsigned base=c->pc==0xc755u?0x5000u:0x8000u;
        uint8_t last[32],*converted,flags;
        if(c->d!=0x700u||c->dbr!=0x7eu||!size||
           end>65535u||base+end>0x10000u)return JS_STOP_NONE;
        if(c->pc==0xd12fu){
            /* HDMA/IRQ can prevent acceleration at the first tile. Every
               subsequent D12F is the same native boundary with Y advanced
               by32 and A8 holding the number of tiles still unconverted.
               Convert only that aligned suffix; earlier tiles stay intact. */
            if((start&31u)||end>0x8000u)return JS_STOP_NONE;
        }
        else if(c->x||start<100u||((start-100u)&31u)||
                end!=u16(w,0xced))return JS_STOP_NONE;
        converted=(uint8_t*)malloc(size);if(!converted)return JS_STOP_NONE;
        memcpy(converted,w+base+start,size);convert_tiles(converted,size,last);
        flags=(uint8_t)((c->p&~(JS_FLAG_M|JS_FLAG_X|JS_FLAG_N|JS_FLAG_Z|JS_FLAG_C|JS_FLAG_V))|JS_FLAG_Z);
        if((((end-32u)^end)&(32u^end)&0x8000u)!=0)flags|=JS_FLAG_V;
        memcpy(w+base+start,converted,size);memcpy(w+0x780,last,32);put16(w,0x7a8,0);
        c->a=c->y=(uint16_t)end;c->x=0x10u;c->p=flags;
        c->pc=(uint16_t)(base==0x5000u?0xc986u:0xd210u);
        m->bus.base.open_bus=3u;
        m->bus.cpu_speed_clocks=(uint8_t)js_bus_v06c_access_clocks(
            &m->bus.base,base==0x5000u?0xa0c982u:0xa0d20fu);
        free(converted);
    }
    c->retired_instructions++;
    return js_scheduler_v09c_advance_cpu(&m->scheduler,2u);
}
