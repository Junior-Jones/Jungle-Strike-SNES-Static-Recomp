#include "jungle/mission_batch_60.h"
#include "jungle/mission_graphics_60.h"
#include <string.h>

static unsigned word(const uint8_t *p){return p[0]|((unsigned)p[1]<<8);}
static void put16(uint8_t *p,unsigned v){p[0]=(uint8_t)v;p[1]=(uint8_t)(v>>8);}
static void put64(uint8_t *p,uint64_t v){unsigned i;for(i=0;i<8;i++)p[i]=(uint8_t)(v>>(8*i));}
static uint64_t get64(const uint8_t *p){unsigned i;uint64_t v=0;for(i=0;i<8;i++)v|=(uint64_t)p[i]<<(8*i);return v;}
static js_stop_reason out(js_machine_v10_40 *m,unsigned address,unsigned value){
    return js_bus_v09c_write8(&m->bus,address,(uint8_t)value);
}
static int copilot_context(const uint8_t *w){
    return word(w+0xc0b)==0x8276u&&word(w+0xc8d)==0u&&
        word(w+0xc8f)==0x0fu&&word(w+0xc0f)==0x92e2u;
}
static js_stop_reason transfer(js_machine_v10_40 *m,unsigned control,unsigned bank,
    unsigned source,unsigned destination,unsigned length,unsigned palette){
    unsigned j;
    const unsigned addresses[]={0x2116,0x2117,0x4370,0x4371,0x4372,0x4373,0x4374,0x4375,0x4376};
    unsigned values[]={destination,destination>>8,control,control>>8,
        source,source>>8,bank,length,length>>8};
    js_stop_reason stop;
    for(j=0;j<9;j++){stop=out(m,addresses[j],values[j]);if(stop)return stop;}
    if(control==0x2200){stop=out(m,0x2121,palette);if(stop)return stop;}
    stop=out(m,0x2115,0x80);if(stop)return stop;
    stop=out(m,0x420b,0x80);if(stop)return stop;
    for(j=0;j<8&&m->scheduler.dma_pending_mask;j++){
        stop=js_scheduler_v09c_cpu_cycle_begin(&m->scheduler);if(stop)return stop;
    }
    return m->scheduler.dma_pending_mask?JS_STOP_DMA_UNAVAILABLE:JS_STOP_NONE;
}
static void clear_packets(JungleMission60State *s){
    s->count=0;s->used=0;s->ready=0;s->active=0;s->draining=0;s->owner=0;s->publication_due=0;
    memset(s->packets,0,sizeof(s->packets));memset(s->bytes,0,sizeof(s->bytes));
}
static js_stop_reason commit(JungleMission60State *s,js_machine_v10_40 *m){
    uint8_t backup[JUNGLE_MISSION60_MAX_BYTES];
    unsigned i;js_stop_reason stop=JS_STOP_NONE;
    /* This boundary follows the native IRQ's forced-blank write. Defer rather
       than perform device work from an unsupported or busy bus context. */
    if((s->owner==2u&&!s->draining&&m->scheduler.frame_count<s->publication_due)||
       !m->ppu.forced_blank||m->scheduler.dma_pending_mask||
       m->scheduler.hdma_init_pending||m->scheduler.hdma_line_pending||
       m->dma.active_channel!=255u)return JS_STOP_NONE;
    memcpy(backup,m->bus.base.wram+0x8000,s->used);
    memcpy(m->bus.base.wram+0x8000,s->bytes,s->used);
    for(i=0;i<s->count;i++){
        const JungleMission60Packet *p=s->packets+i;
        unsigned source=0x8000u+p->offset;
        /* Original DMA owns byte clocks, refresh/HDMA arbitration, PPU ports
           and audio progress. No CPU instruction or game-time loop is run. */
        if(p->layout){
            unsigned row;
            stop=out(m,0x210b,p->palette);if(stop)goto restore;
            for(row=0;row<p->rows;row++){
                stop=transfer(m,0x1801u,0x7eu,source+row*p->columns*2u,
                    (uint16_t)(p->destination+row*32u),p->columns*2u,0);
                if(stop)goto restore;
            }
        }else{
            stop=transfer(m,p->control,0x7eu,source,p->destination,p->length,p->palette);
            if(stop)goto restore;
        }
        m->dma.channel[7].a_bank=p->bank;
        m->dma.channel[7].a_address=(uint16_t)(p->source+((p->control==0x1809u)?0u:p->length));
    }
restore:
    memcpy(m->bus.base.wram+0x8000,backup,s->used);
    if(stop==JS_STOP_NONE)clear_packets(s);
    return stop;
}

static int capture(JungleMission60State *s,js_machine_v10_40 *m){
    uint8_t temp[JUNGLE_MISSION60_MAX_BYTES];
    uint8_t *w=m->bus.base.wram;unsigned length=word(w+0xc39),i;
    JungleMission60Packet p;
    if(!(word(w+0xc85)&1u)||!length||(length&1u)||
       length>JUNGLE_MISSION60_MAX_BYTES-s->used||s->count>=JUNGLE_MISSION60_MAX_PACKETS||
       (word(w+0xc31)!=0x1801u&&word(w+0xc31)!=0x2200u&&!(s->owner==3u&&word(w+0xc31)==0x1809u)))return 0;
    memset(&p,0,sizeof(p));p.control=(uint16_t)word(w+0xc31);p.bank=w[0xc33];
    p.source=(uint16_t)word(w+0xc35);p.destination=(uint16_t)word(w+0xc37);
    p.length=(uint16_t)length;p.palette=(uint16_t)word(w+0xc3d);p.offset=s->used;
    for(i=0;i<length;i++){
        uint32_t address=((uint32_t)p.bank<<16)|(uint16_t)(p.source+(p.control==0x1809u?0u:i));
        js_bus_mapping_v06c map=js_bus_v06c_map(&m->bus.base,address);
        if(!map.mapped||(map.region!=JS_BUS_REGION_ROM&&map.region!=JS_BUS_REGION_WRAM)||
           js_bus_v06c_peek8(&m->bus.base,address,temp+i)!=JS_STOP_NONE)return 0;
    }
    s->packets[s->count++]=p;memcpy(s->bytes+s->used,temp,length);s->used+=(uint16_t)length;
    /* Exact shadow ownership of the original generic DMA consumer. */
    put16(w+0xc37,p.destination+length/2u);put16(w+0xc35,p.source+(p.control==0x1809u?0u:length));
    put16(w+0xc39,0);put16(w+0xc3b,length);put16(w+0xc85,word(w+0xc85)&~1u);
    return 1;
}

static int capture_rectangle(JungleMission60State *s,js_machine_v10_40 *m){
    uint8_t temp[JUNGLE_MISSION60_MAX_BYTES];uint8_t *w=m->bus.base.wram;
    unsigned columns=word(w+0xc45),rows=word(w+0xc47),length=columns*rows*2u,i;
    JungleMission60Packet p;
    /* Exactly the Copilot AE92 rectangles: one <=32-word plane, no native
       right-hand fill. Wider/fixed/filling rectangles remain native. */
    if((word(w+0xc85)&12u)!=12u||word(w+0xc49)!=0x1801u||
       !columns||columns>32u||!rows||rows>32u||
       length>JUNGLE_MISSION60_MAX_BYTES-s->used||s->count>=JUNGLE_MISSION60_MAX_PACKETS)return 0;
    memset(&p,0,sizeof(p));p.control=0x1801;p.bank=w[0xc3f];p.source=(uint16_t)word(w+0xc41);
    p.destination=(uint16_t)word(w+0xc43);p.length=(uint16_t)length;p.offset=s->used;
    p.palette=w[0xca9];p.layout=1;p.columns=(uint8_t)columns;p.rows=(uint8_t)rows;
    for(i=0;i<length;i++){
        uint32_t address=((uint32_t)p.bank<<16)|(uint16_t)(p.source+(p.control==0x1809u?0u:i));
        js_bus_mapping_v06c map=js_bus_v06c_map(&m->bus.base,address);
        if(!map.mapped||(map.region!=JS_BUS_REGION_ROM&&map.region!=JS_BUS_REGION_WRAM)||
           js_bus_v06c_peek8(&m->bus.base,address,temp+i)!=JS_STOP_NONE)return 0;
    }
    s->packets[s->count++]=p;memcpy(s->bytes+s->used,temp,length);s->used+=(uint16_t)length;
    put16(w+0xc41,p.source+length);put16(w+0xc43,p.destination+rows*32u);
    put16(w+0xc85,word(w+0xc85)&~4u);return 1;
}

js_stop_reason jungle_mission60_batch_after_instruction(JungleMission60State *s,
    js_machine_v10_40 *m,uint8_t bank,uint16_t pc,int enabled){
    js_cpu65816_state *c;uint8_t *w;
    if(!s||!m)return JS_STOP_NONE;
    if(!enabled){
        /* A state imported with the preference off must publish packets that
           were already acknowledged. Drain them before the next native one. */
        s->active=0;if(s->count){s->ready=1;s->draining=1;}
    }
    c=&m->cpu_core.cpu;w=m->bus.base.wram;
    if(bank!=0xa0u||c->pbr!=0xa0u||c->e||(c->p&(JS_FLAG_M|JS_FLAG_X))||
       c->d!=0xc00u||c->waiting||c->stopped)return JS_STOP_NONE;
    if(c->dbr!=0xa0u&&!(s->active&&s->owner==1u&&c->dbr==0xa2u))return JS_STOP_NONE;
    if(pc==0xd3ebu&&c->pc==0xd3edu&&s->ready&&s->count)return commit(s,m);
    if(!enabled)return JS_STOP_NONE;
    /* Copilot script offset4 and the literal Mission-page JSR at8421
       clear the same two VRAM regions through B5D6. Freeze both exact
       fixed-source commands before acknowledging either wait;
       publish this 4128-byte group at its own native blank IRQ. Portrait
       packets start on the following script pass, keeping each IRQ bounded. */
    if(((copilot_context(w)&&word(w+0xc8b)==4u)||
        (word(w+0xc0b)==0x83fbu&&c->sp<=0x1ffdu&&word(w+c->sp+1u)==0x8423u))&&
       c->dbr==0xa0u&&
       ((pc==0xb609u&&c->pc==0xb60bu)||(pc==0xb63au&&c->pc==0xb63cu))){
        unsigned first=pc==0xb609u;
        unsigned destination=word(w+0xc37);
        int exact=word(w+0xc31)==0x1809u&&word(w+0xc33)==0xa0u&&word(w+0xc35)==0xd81fu&&
            word(w+0xc39)==(first?32u:4096u)&&
            (destination==(first?0x4000u:0x5800u)||destination==(first?0x3000u:0x4800u));
        if(first&&!s->count&&exact){s->active=1;s->owner=3;s->draining=0;}
        if(s->active&&s->owner==3u){
            if(!exact||!capture(s,m)){s->active=0;s->draining=1;s->ready=(uint8_t)(s->count!=0);}
            else if(!first)s->ready=1;
        }
        return JS_STOP_NONE;
    }
    if(pc==0xa99au&&c->pc==0xcffau&&copilot_context(w)){
        if(s->count){s->ready=1;s->draining=1;s->active=0;return JS_STOP_NONE;}
        s->active=1;s->draining=0;s->owner=1;
    }
    if(s->active&&s->owner==1){
        if(pc==0xaef7u&&c->pc==0xaef9u){
            if(!capture_rectangle(s,m)){s->active=0;s->draining=1;s->ready=(uint8_t)(s->count!=0);}
        }else if((c->pc==0x9beeu&&pc!=0x9beeu)||(pc==0x9beeu&&c->pc==0x9bf0u)){
            if(s->count)s->ready=1;else s->active=0;
        }else if((pc==0xd10cu&&c->pc==0xd10eu)||(pc==0xd0e1u&&c->pc==0xd0e3u)){
            if(!capture(s,m)){s->active=0;s->draining=1;s->ready=(uint8_t)(s->count!=0);}
        }
        return JS_STOP_NONE;
    }
    if(pc==0xc648u&&c->pc==0xc64au&&jungle_mission60_gameover_context(m)){
        if(s->count){s->ready=1;s->draining=1;s->active=0;return JS_STOP_NONE;}
        s->active=1;s->draining=0;s->owner=2;
        /* Original CHAR DMA finishes at reload+2; its double-buffered tilemap
           and BG12NBA switch publish at reload+3. Keep that visible deadline
           while allowing the UI to process each intervening input epoch. */
        s->publication_due=m->scheduler.frame_count+3u;
    }
    if(s->active&&s->owner==2){
        if(pc==0xc6c4u&&c->pc==0xc6c6u){
            if(!capture(s,m)){s->active=0;s->draining=1;s->ready=(uint8_t)(s->count!=0);}
        }else if(pc==0xc72au&&c->pc==0xc72cu){
            if(!capture_rectangle(s,m)){s->active=0;s->draining=1;}
            s->ready=(uint8_t)(s->count!=0);
        }
        return JS_STOP_NONE;
    }
    if(word(w+0xc0b)!=0x83fbu)return JS_STOP_NONE;
    if(pc==0x858bu&&c->pc==0x8f4fu){
        uint32_t descriptor=word(w+0xc25)|((uint32_t)w[0xc27]<<16);
        if(s->count){s->ready=1;s->draining=1;s->active=0;return JS_STOP_NONE;}
        s->active=1;s->draining=0;s->owner=0;s->old_animation=(uint16_t)word(w+0xd62);
        s->animation_advanced=0;
        if(s->descriptor!=descriptor){s->descriptor=descriptor;s->animation_armed=0;}
    }
    if(!s->active)return JS_STOP_NONE;
    if(pc==0x9079u&&c->pc==0x907cu){
        if(s->animation_armed&&m->scheduler.frame_count<s->animation_due)
            put16(w+0xd62,s->old_animation);
        else{s->animation_advanced=1;s->animation_armed=1;s->animation_field=m->scheduler.frame_count;}
    }
    if((pc==0x903fu&&c->pc==0x9041u)||(pc==0x844du&&c->pc==0x844fu)){
        if(s->count){
            s->ready=1;
            if(s->animation_advanced){s->animation_period=(uint16_t)(s->count+1u);
                s->animation_due=s->animation_field+s->animation_period;}
        }else s->active=0;
        return JS_STOP_NONE;
    }
    if((pc==0xd10cu&&c->pc==0xd10eu)||(pc==0xd0e1u&&c->pc==0xd0e3u)||
       (pc==0x917cu&&c->pc==0x917eu)||(pc==0x919bu&&c->pc==0x919du)||
       (pc==0x91c8u&&c->pc==0x91cau)){
        if(!capture(s,m)){
            /* Keep the unsupported packet native. Older acknowledged packets
               publish first at the same IRQ, then the original consumer runs. */
            s->active=0;s->draining=1;s->ready=(uint8_t)(s->count!=0);
        }
    }
    return JS_STOP_NONE;
}

void jungle_mission60_batch_encode(const JungleMission60State *s,uint8_t *w){
    unsigned i;memset(w,0,JUNGLE_MISSION60_WIRE_BYTES);
    w[0]=s->active;w[1]=s->ready;w[2]=s->draining;w[3]=s->animation_armed;
    w[4]=s->animation_advanced;w[5]=s->count;put16(w+6,s->used);
    put16(w+8,s->old_animation);put16(w+10,s->animation_period);
    for(i=0;i<4;i++)w[12+i]=(uint8_t)(s->descriptor>>(8*i));
    put64(w+16,s->animation_due);put64(w+24,s->animation_field);
    w[32]=s->owner;put64(w+33,s->publication_due);
    for(i=0;i<s->count;i++){
        const JungleMission60Packet *p=s->packets+i;uint8_t *t=w+48+i*16;
        put16(t,p->control);put16(t+2,p->source);put16(t+4,p->destination);
        put16(t+6,p->length);put16(t+8,p->palette);put16(t+10,p->offset);t[12]=p->bank;
        t[13]=p->layout;t[14]=p->columns;t[15]=p->rows;
    }
    memcpy(w+48+16*JUNGLE_MISSION60_MAX_PACKETS,s->bytes,s->used);
}
int jungle_mission60_batch_decode(JungleMission60State *s,const uint8_t *w){
    unsigned i,total=0,payload=48+16*JUNGLE_MISSION60_MAX_PACKETS;
    if(w[0]>1||w[1]>1||w[2]>1||w[3]>1||w[4]>1||w[5]>JUNGLE_MISSION60_MAX_PACKETS||
       word(w+6)>JUNGLE_MISSION60_MAX_BYTES||word(w+10)>9||w[15]||
       (w[1]&&!w[5])||(w[4]&&!w[3]))return 0;
    if(w[32]>3)return 0;
    for(i=41;i<48;i++)if(w[i])return 0;
    memset(s,0,sizeof(*s));s->active=w[0];s->ready=w[1];s->draining=w[2];
    s->animation_armed=w[3];s->animation_advanced=w[4];s->count=w[5];
    s->used=(uint16_t)word(w+6);s->old_animation=(uint16_t)word(w+8);
    s->animation_period=(uint16_t)word(w+10);
    s->descriptor=(uint32_t)word(w+12)|((uint32_t)word(w+14)<<16);
    s->animation_due=get64(w+16);s->animation_field=get64(w+24);
    s->owner=w[32];s->publication_due=get64(w+33);
    if(s->publication_due&&s->owner!=2u)return 0;
    for(i=0;i<s->count;i++){
        const uint8_t *t=w+48+i*16;JungleMission60Packet *p=s->packets+i;
        p->control=(uint16_t)word(t);p->source=(uint16_t)word(t+2);p->destination=(uint16_t)word(t+4);
        p->length=(uint16_t)word(t+6);p->palette=(uint16_t)word(t+8);p->offset=(uint16_t)word(t+10);p->bank=t[12];
        p->layout=t[13];p->columns=t[14];p->rows=t[15];
        if((p->control!=0x1801u&&p->control!=0x2200u&&!(s->owner==3u&&p->control==0x1809u))||!p->length||(p->length&1u)||
           p->offset!=total||p->length>JUNGLE_MISSION60_MAX_BYTES-total||p->layout>1)return 0;
        if(p->control==0x1809u&&
           (p->layout||p->bank!=0xa0u||p->source!=0xd81fu||
            !((p->length==32u&&(p->destination==0x4000u||p->destination==0x3000u))||
              (p->length==4096u&&(p->destination==0x5800u||p->destination==0x4800u)))))return 0;
        if(p->layout){
            if((s->owner!=1&&s->owner!=2)||p->control!=0x1801u||p->palette>255u||!p->columns||p->columns>32u||
               !p->rows||p->rows>32u||p->length!=p->columns*p->rows*2u)return 0;
        }else if(p->columns||p->rows)return 0;
        total+=p->length;
    }
    if(total!=s->used)return 0;
    for(i=48+s->count*16;i<payload;i++)if(w[i])return 0;
    for(i=payload+s->used;i<JUNGLE_MISSION60_WIRE_BYTES;i++)if(w[i])return 0;
    memcpy(s->bytes,w+payload,s->used);return 1;
}
