#include "jungle/ui_60.h"
#include "jungle/mission_graphics_60.h"
#include <string.h>

static uint16_t word(const uint8_t *p){return (uint16_t)(p[0]|((uint16_t)p[1]<<8));}
static void putword(uint8_t *p,uint16_t n){p[0]=(uint8_t)n;p[1]=(uint8_t)(n>>8);}
static void put64(uint8_t *p,uint64_t n){unsigned i;for(i=0;i<8;i++)p[i]=(uint8_t)(n>>(i*8));}
static uint64_t get64(const uint8_t *p){uint64_t n=0;unsigned i;for(i=0;i<8;i++)n|=(uint64_t)p[i]<<(i*8);return n;}
/* Literal script-list offsets and action tables from the native Options and
   Campaign/password editors. Other scripted screens retain their clocks. */
static int interactive_text_menu(const uint8_t *w){
    unsigned script=word(w+0xc8f),actions=word(w+0xc0f);
    return word(w+0xc0b)==0x8276u&&word(w+0xc8d)==0u&&
        ((script==0x12u&&actions==0x932au)||((script==9u||script==0x0fu)&&actions==0x92e2u));
}

int jungle_ui60_graphics_context(const JungleUi60State *s,const js_machine_v10_40 *m){
    const js_cpu65816_state *c;
    if(!s||!m||!s->dispatch_armed||
       s->previous_scene!=word(m->bus.base.wram+0xc0b)||
       (s->previous_scene!=0x834cu&&s->previous_scene!=0x83fbu&&!interactive_text_menu(m->bus.base.wram)))return 0;
    c=&m->cpu_core.cpu;
    if(c->pbr!=0xa0||c->e||(c->p&(JS_FLAG_M|JS_FLAG_X))||c->d!=0x0c00||
       c->waiting||c->stopped||m->scheduler.nmi_pending||
       (js_scheduler_v09c_irq_asserted(&m->scheduler)&&!(c->p&JS_FLAG_I))||
       m->bus.base.math.multiply_cycles_remaining||m->bus.base.math.divide_cycles_remaining)return 0;
    /* Only the audited tile-buffer clear and text/glyph construction. Native input,
       timers, actor work, waits, interrupts, device accesses and DMA retain
       their clocks. A minimum four-clock access preserves read sample timing. */
    if(c->dbr==0xa0u&&((c->pc>=0x91d2u&&c->pc<=0x91e4u)||
        (c->pc>=0xafd5u&&c->pc<=0xb0beu)||
        (c->pc>=0xb13fu&&c->pc<=0xb408u)))return 1;
    /* Map markers are a finite WRAM/ROM list walk and OAM-buffer builder.
       The native CB1 animation branches still advance persistent records on
       their original half-rate clock; only pure construction gets a smaller
       access budget. In particular 91FC/9223 pending-DMA waits stay native. */
    if(s->previous_scene==0x834cu&&m->cpu_core.rom_identity_ok){
        if((c->dbr==0xa0u||c->dbr==0x7eu)&&c->pc>=0x8998u&&c->pc<=0x8c27u)return 1;
        if((c->dbr==0x7eu||c->dbr==0xa1u)&&c->pc>=0xbe50u&&c->pc<=0xbf00u&&c->x<=0x100u)return 1;
    }
    return 0;
}

void jungle_ui60_encode(const JungleUi60State *s,uint8_t *w){
    memset(w,0,JUNGLE_UI60_WIRE_BYTES);
    w[0]=8;w[1]=s->dispatch_armed;w[2]=s->map_clock_armed;w[3]=s->map_half_phase;
    w[4]=s->map_tick_advanced;
    put64(w+8,s->input_epoch);put64(w+16,s->last_dispatch_epoch);
    put64(w+24,s->map_animation_epoch);
    w[32]=(uint8_t)s->previous_scene;w[33]=(uint8_t)(s->previous_scene>>8);
    w[34]=s->password_error_armed;
    {unsigned i;for(i=0;i<4;i++)w[35+i]=(uint8_t)(s->password_error_field>>(i*8));}
    jungle_mission60_batch_encode(&s->mission,w+40);
    {uint8_t *extra=w+40+JUNGLE_MISSION60_WIRE_BYTES;
     extra[0]=s->gameover_clock_armed;put64(extra+8,s->gameover_tick_field);
     put64(extra+16,s->gameover_reload_field);}
}
int jungle_ui60_decode(JungleUi60State *s,const uint8_t *w){
    unsigned i;
    if(w[0]!=8||w[1]>1||w[2]>1||w[3]>1||w[4]>1||w[34]>1||w[39])return 0;
    for(i=5;i<8;i++)if(w[i])return 0;
    memset(s,0,sizeof(*s));
    s->dispatch_armed=w[1];s->map_clock_armed=w[2];s->map_half_phase=w[3];
    s->map_tick_advanced=w[4];
    s->input_epoch=get64(w+8);s->last_dispatch_epoch=get64(w+16);
    s->map_animation_epoch=get64(w+24);s->previous_scene=word(w+32);
    s->password_error_armed=w[34];
    for(i=0;i<4;i++)s->password_error_field|=(uint32_t)w[35+i]<<(i*8);
    if(s->last_dispatch_epoch>s->input_epoch||s->map_animation_epoch>s->input_epoch)return 0;
    if(!s->password_error_armed&&s->password_error_field)return 0;
    {const uint8_t *extra=w+40+JUNGLE_MISSION60_WIRE_BYTES;
     if(extra[0]>1)return 0;for(i=1;i<8;i++)if(extra[i])return 0;
     s->gameover_clock_armed=extra[0];s->gameover_tick_field=get64(extra+8);
     s->gameover_reload_field=get64(extra+16);
     if(s->gameover_reload_field>s->gameover_tick_field||
        (!s->gameover_clock_armed&&(s->gameover_tick_field||s->gameover_reload_field)))return 0;}
    return jungle_mission60_batch_decode(&s->mission,w+40);
}

void jungle_ui60_after_instruction(JungleUi60State *s,js_machine_v10_40 *m,
                                   uint8_t bank,uint16_t pc){
    js_cpu65816_state *c;
    const uint8_t *w;
    uint16_t scene;
    if(!s||!m||bank!=0xa0)return;
    c=&m->cpu_core.cpu;w=m->bus.base.wram;
    if(c->pbr!=0xa0||c->e||(c->p&(JS_FLAG_M|JS_FLAG_X)))return;
    if(pc==0xd704&&c->pc==0xd706&&c->d==0x0c00){s->input_epoch++;return;}
    scene=word(w+0xc0b);
    if(c->d==0x0c00u&&c->dbr==0xa0u&&jungle_mission60_gameover_context(m)){
        if(pc==0xadaau&&c->pc==0xadacu&&s->gameover_clock_armed){
            uint64_t field=m->scheduler.frame_count;
            /* This scripted fade shared the native artwork's blocked passes.
               Preserve its original walltime after making those passes live. */
            if(field==s->gameover_tick_field||field-s->gameover_reload_field<=2u){
                uint16_t value=word(w+0xc09);
                c->a=value;c->p&=(uint8_t)~(JS_FLAG_N|JS_FLAG_Z);
                if(!value)c->p|=JS_FLAG_Z;if(value&0x8000u)c->p|=JS_FLAG_N;
            }
        }
        if(pc==0xc648u&&c->pc==0xc64au){
            s->gameover_clock_armed=1;
            s->gameover_reload_field=s->gameover_tick_field=m->scheduler.frame_count;
        }else if(pc==0xc606u&&c->pc==0xc608u&&s->gameover_clock_armed){
            uint64_t field=m->scheduler.frame_count;
            /* Native decode/conversion holds A5=10 during the reload field
               and the next two fields. Preserve that artwork deadline while
               the rest of the screen continues to process every field.
               C60D is the original countdown-path RTS; the native JSR stack
               and the already executed LDA's flags remain authoritative. */
            if(field==s->gameover_tick_field||field-s->gameover_reload_field<=2u)
                c->pc=0xc60du;
            else s->gameover_tick_field=field;
        }
    }
    if(c->d==0x0c00u&&c->dbr==0xa0u&&interactive_text_menu(w)&&word(w+0xc8f)==9u){
        if(pc==0x9b14u&&c->pc==0x9b17u){
            s->password_error_armed=1;s->password_error_field=(uint32_t)m->scheduler.frame_count;
        }else if(pc==0x9aa8u&&c->pc==0x9aabu){
            /* A dirty redraw can revisit the handler in the same physical
               display field as the reload. Keep the original 180-field error
               duration instead of consuming a timer tick with that redraw. */
            if(s->password_error_armed&&s->password_error_field==(uint32_t)m->scheduler.frame_count){
                uint16_t value=(uint16_t)(word(w+0xd28)+1u);
                putword(m->bus.base.wram+0xd28,value);
                c->p&=(uint8_t)~(JS_FLAG_N|JS_FLAG_Z);
                if(!value)c->p|=JS_FLAG_Z;if(value&0x8000u)c->p|=JS_FLAG_N;
            }else{s->password_error_armed=1;s->password_error_field=(uint32_t)m->scheduler.frame_count;}
        }
    }
    if(pc==0x815d&&c->pc==0x815e&&c->d==0x0c00){
        s->last_dispatch_epoch=s->input_epoch;s->dispatch_armed=1;
        if(scene!=0x834c)s->map_clock_armed=0;
        if(!interactive_text_menu(w)||word(w+0xc8f)!=9u){s->password_error_armed=0;s->password_error_field=0;}
        if(!jungle_mission60_gameover_context(m)){
            s->gameover_clock_armed=0;s->gameover_tick_field=s->gameover_reload_field=0;
        }
        s->previous_scene=scene;
        return;
    }
    if(pc==0x8155&&c->pc==0x8158&&s->dispatch_armed&&
       (scene==0x834c||scene==0x83fb||interactive_text_menu(w)||
        (s->gameover_clock_armed&&jungle_mission60_gameover_context(m)))&&s->previous_scene==scene){
        /* One input/scene pass per actual controller-latch epoch. A completed
           Map upload already waited for that epoch; do not wait a second time.
           Keep original transfer ownership and never bypass a pending packet. */
        if(s->input_epoch==s->last_dispatch_epoch||(word(w+0xc85)&0x0405u))
            c->p|=JS_FLAG_Z;
        else c->p&=(uint8_t)~JS_FLAG_Z;
        return;
    }
    /* These two odd-clock branches advance persistent marker records. Holding
       CB1 for the extra redraw must not increment a record twice on that tick. */
    if(scene==0x834c&&c->d==0x0c00&&s->map_clock_armed&&!s->map_tick_advanced&&
       ((pc==0x8b06&&c->pc==0x8b09)||(pc==0x8cab&&c->pc==0x8cae))){
        c->p|=JS_FLAG_Z;return;
    }
    if(pc==0x8161&&c->pc==0x8162&&c->d==0x0c00&&scene==0x834c){
        uint64_t elapsed;
        uint16_t ticks;
        if(!s->map_clock_armed){s->map_clock_armed=1;s->map_half_phase=0;ticks=1;}
        else {
            elapsed=s->input_epoch-s->map_animation_epoch+s->map_half_phase;
            ticks=(uint16_t)(elapsed/2u);s->map_half_phase=(uint8_t)(elapsed&1u);
        }
        s->map_animation_epoch=s->input_epoch;
        s->map_tick_advanced=(uint8_t)(ticks!=0);
        c->a=(uint16_t)(word(w+0xcb1)+ticks);
        c->p&=(uint8_t)~(JS_FLAG_N|JS_FLAG_Z);
        if(!c->a)c->p|=JS_FLAG_Z;
        if(c->a&0x8000u)c->p|=JS_FLAG_N;
    }
}
