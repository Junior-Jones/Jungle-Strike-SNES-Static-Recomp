#include "jungle/presentation_snapshot.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define HEADER 32u
#define WATER 40u
static const unsigned char magic[8]={'J','S','P','R','E','S','0','1'};
static unsigned get32(const unsigned char *p){return (unsigned)p[0]|((unsigned)p[1]<<8)|((unsigned)p[2]<<16)|((unsigned)p[3]<<24);}
static void put32(unsigned char *p,unsigned v){unsigned i;for(i=0;i<4;i++)p[i]=(unsigned char)(v>>(8*i));}
static unsigned get16(const unsigned char *p){return p[0]|((unsigned)p[1]<<8);}
static void put16(unsigned char *p,unsigned v){p[0]=(unsigned char)v;p[1]=(unsigned char)(v>>8);}
static int boolean(int x){return x==0||x==1;}
static int zero(const void *p,size_t n){const unsigned char *b=p;while(n--)if(*b++)return 0;return 1;}
static void sanitize(JungleWideState *w){
    memset(&w->edge_ppu.scheduler,0,sizeof(w->edge_ppu.scheduler));
    memset(&w->edge_ppu.cpu_open_bus,0,sizeof(w->edge_ppu.cpu_open_bus));
    memset(&w->edge_ppu.wrio,0,sizeof(w->edge_ppu.wrio));
}
static int ppu_valid(const js_ppu_v09c *p){
    unsigned i,j;
#define B(f) if(!boolean(p->f))return 0
    B(vram_increment_on_high);B(cgram_high_latch);B(forced_blank);B(oam_priority);
    B(mode1_bg3_priority);B(color_math_add_subscreen);B(direct_color);
    B(color_math_subtract);B(color_math_half);B(external_sync);B(extbg);B(hires);
    B(overscan);B(obj_interlace);B(screen_interlace);B(time_over);B(range_over);
    B(location_latched);B(h_location_toggle);B(v_location_toggle);
    B(mode7.large_map);B(mode7.fill_with_tile0);B(mode7.horizontal_mirror);B(mode7.vertical_mirror);
#undef B
    if(p->brightness>15||p->oam_mode>7||p->bg_mode>7||p->mosaic_size>16||
       p->mosaic_enabled>15||p->vram_remap>3||p->vram_read_buffer_state>3||
       p->vram_read_buffer_known>3||p->color_math_clip_mode>3||p->color_math_prevent_mode>3||
       p->window_mask_main>31||p->window_mask_sub>31||p->main_screen_layers>31||
       p->sub_screen_layers>31||p->color_math_enabled>63||p->fixed_color>0x7fff)return 0;
    if(p->vram_increment!=0&&p->vram_increment!=1&&p->vram_increment!=32&&p->vram_increment!=128)return 0;
    for(i=0;i<4;i++)if(!boolean(p->layer[i].double_width)||!boolean(p->layer[i].double_height)||!boolean(p->layer[i].large_tiles))return 0;
    for(i=0;i<6;i++)if(p->mask_logic[i]>3)return 0;
    for(i=0;i<2;i++)for(j=0;j<6;j++)if(!boolean(p->window[i].active_layers[j])||!boolean(p->window[i].inverted_layers[j]))return 0;
    return 1;
}
static int wide_valid(const JungleWideState *w){
    unsigned i,j;
    if(!boolean(w->enabled)||!boolean(w->valid)||!boolean(w->active)||!boolean(w->work_active)||!boolean(w->console)||!boolean(w->foreground_ready))return 0;
    if(w->view_shift_x < -128||w->view_shift_x>128||w->render_shift_x < -128||w->render_shift_x>128||
       w->view_shift_y < -32||w->view_shift_y>32||w->render_shift_y < -32||w->render_shift_y>32||
       w->clip_left>w->clip_right||w->clip_right>512||w->work_scanlines>224||
       w->foreground_x < -1||w->foreground_x>65536||w->foreground_y < -1||w->foreground_y>65536)return 0;
    for(i=0;i<128;i++){
        if(w->sprite_seen[i]>1||w->sprite_x[i]<-192||w->sprite_x[i]>447||w->sprite_y[i]<-32||w->sprite_y[i]>255)return 0;
        for(j=0;j<4;j++)if(w->edge_sprite_pixels[i][j]>512u*288u)return 0;
    }
    for(i=0;i<64;i++)if(w->column_valid[i]>1||w->column_key[i]<0||w->column_key[i]>4094||
        (w->column_valid[i]&&((unsigned)w->column_key[i]&63u)!=i))return 0;
    for(i=0;i<16u*256u;i++)if(w->hud_mask[i]>1||w->work_hud_mask[i]>1)return 0;
    for(i=0;i<512u*288u;i++)if(w->pixel_object[i]>128)return 0;
    return ppu_valid(&w->edge_ppu);
}
static int water_valid(const JungleWater60Palette *w){
    unsigned i;
    if(w->phase>7||w->source_offset>8||(w->source_offset&1))return 0;
    for(i=0;i<5;i++)if(w->current_bgr555[i]>0x7fff||w->next_bgr555[i]>0x7fff)return 0;
    return 1;
}
size_t jungle_presentation_snapshot_size(int with_wide){return HEADER+WATER+(with_wide?sizeof(JungleWideState):0u);}
int jungle_presentation_snapshot_encode(const JungleWideState *wide,const JungleWater60Palette *water,int valid,void *wire,size_t size){
    unsigned char *b=wire,*p;JungleWideState *copy;unsigned i;
    if(!wire||!boolean(valid)||size!=jungle_presentation_snapshot_size(wide!=NULL)||
       (wide&&!wide_valid(wide))||(valid&&(!water||!water_valid(water))))return 0;
    /* Allocation failure leaves output untouched. Output must not alias water. */
    copy=wide?malloc(sizeof(*copy)):NULL;if(wide&&!copy)return 0;
    if(copy){memcpy(copy,wide,sizeof(*copy));sanitize(copy);}
    memset(b,0,size);memcpy(b,magic,8);put32(b+8,1);put32(b+12,(wide?1u:0u)|(valid?2u:0u));
    put32(b+16,wide?(unsigned)sizeof(*wide):0);put32(b+20,WATER);
    p=b+HEADER;if(copy){memcpy(p,copy,sizeof(*copy));p+=sizeof(*copy);free(copy);}
    if(valid)for(i=0;i<5;i++){
        put16(p+i*2,water->current_bgr555[i]);put16(p+10+i*2,water->next_bgr555[i]);
        p[20+i*3]=water->rgb8[i].r;p[21+i*3]=water->rgb8[i].g;p[22+i*3]=water->rgb8[i].b;
    }
    if(valid){p[35]=water->phase;put16(p+36,water->source_offset);}return 1;
}
int jungle_presentation_snapshot_decode(JunglePresentationSnapshot *out,const void *wire,size_t size){
    const unsigned char *b=wire,*p;JunglePresentationSnapshot temp={0};unsigned flags,i;
    if(!out||!wire||size<HEADER+WATER||memcmp(b,magic,8)||get32(b+8)!=1||!zero(b+24,8))return 0;
    flags=get32(b+12);if(flags&~3u||get32(b+16)!=((flags&1)?sizeof(JungleWideState):0)||get32(b+20)!=WATER||size!=jungle_presentation_snapshot_size(flags&1))return 0;
    p=b+HEADER;
    if(flags&1){
#define PTR(f) if(!zero(p+offsetof(JungleWideState,edge_ppu)+offsetof(js_ppu_v09c,f),sizeof(((js_ppu_v09c*)0)->f)))return 0
        PTR(scheduler);PTR(cpu_open_bus);PTR(wrio);
#undef PTR
        temp.wide=malloc(sizeof(*temp.wide));if(!temp.wide)return 0;
        memcpy(temp.wide,p,sizeof(*temp.wide));if(!wide_valid(temp.wide)){free(temp.wide);return 0;}p+=sizeof(*temp.wide);
    }
    temp.water_valid=(uint8_t)((flags>>1)&1);
    if(!zero(p+38,2)||(!temp.water_valid&&!zero(p,WATER))){free(temp.wide);return 0;}
    if(temp.water_valid){
        for(i=0;i<5;i++){
            temp.water.current_bgr555[i]=(uint16_t)get16(p+i*2);temp.water.next_bgr555[i]=(uint16_t)get16(p+10+i*2);
            temp.water.rgb8[i].r=p[20+i*3];temp.water.rgb8[i].g=p[21+i*3];temp.water.rgb8[i].b=p[22+i*3];
        }
        temp.water.phase=p[35];temp.water.source_offset=(uint16_t)get16(p+36);
        if(!water_valid(&temp.water)){free(temp.wide);return 0;}
    }
    jungle_presentation_snapshot_clear(out);*out=temp;return 1;
}
void jungle_presentation_snapshot_clear(JunglePresentationSnapshot *s){if(s){free(s->wide);memset(s,0,sizeof(*s));}}
void jungle_presentation_snapshot_apply(JunglePresentationSnapshot *s,JungleWideState **wide,js_machine_v10_40 *m,JungleWater60Palette *water,uint8_t *valid){
    int enabled;if(!s||!wide||!m||!water||!valid)return;
    enabled=*wide?(*wide)->enabled:0;
    if(s->wide){
        if(*wide)memcpy(*wide,s->wide,sizeof(**wide));else{*wide=s->wide;s->wide=NULL;}
        (*wide)->enabled=enabled;(*wide)->edge_ppu.scheduler=&m->scheduler;
        (*wide)->edge_ppu.cpu_open_bus=&m->bus.base.open_bus;(*wide)->edge_ppu.wrio=&m->bus.base.wrio;
    }else if(*wide)jungle_wide_invalidate(*wide);
    memcpy(water,&s->water,sizeof(*water));*valid=s->water_valid;
}
