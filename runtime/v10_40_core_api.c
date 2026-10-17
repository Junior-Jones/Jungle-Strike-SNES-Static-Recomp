#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jungle/jungle_static_core.h"
#include "jungle/machine_v10_40.h"
#include "jungle/renderer_v10_40.h"
#include "jungle/status_v10_40.h"
#include "jungle/widescreen.h"

#define JS_V10_40_FRAME_STEP_LIMIT 5000000u
#define JS_V10_40_AUDIO_BATCH_FRAMES JS_V10_33_PCM_FIFO_FRAMES
#define JS_V10_40_SNAPSHOT_VERSION 1u

typedef struct js_snapshot_header_v10_40 {
    char magic[8];
    uint32_t version;
    uint32_t core_size;
    uint32_t smp_size;
    uint32_t reserved;
    uint64_t core_hash;
    uint64_t smp_hash;
} js_snapshot_header_v10_40;

struct JungleStaticCore {
    uint8_t *rom;
    size_t rom_size;
    js_machine_v10_40 machine;
    uint32_t frame_bgra[JUNGLE_STATIC_CORE_FRAME_WIDTH * JUNGLE_STATIC_CORE_FRAME_HEIGHT];
    uint32_t frame_work_bgra[JUNGLE_STATIC_CORE_FRAME_WIDTH * JUNGLE_STATIC_CORE_FRAME_HEIGHT];
    int16_t audio_batch[JS_V10_40_AUDIO_BATCH_FRAMES * 2u];
    uint8_t audio_known_batch[JS_V10_40_AUDIO_BATCH_FRAMES];
    size_t audio_batch_frames;
    uint64_t rendered_frame;
    uint16_t visible_scanlines_rendered;
    uint8_t render_resync_pending;
    uint8_t render_observer_synchronized;
    uint8_t machine_initialized;
    uint8_t frame_valid;
    uint8_t render_output_enabled;
    uint8_t ppu_active_violation_mask;
    uint64_t ppu_visible_scanlines;
    uint64_t ppu_active_scanlines;
    uint64_t ppu_forced_blank_scanlines;
    uint64_t ppu_brightness_zero_scanlines;
    uint64_t ppu_mode_scanlines[8];
    uint64_t ppu_mode_violation_scanlines;
    uint64_t ppu_bg3_priority_violation_scanlines;
    uint64_t ppu_tile_geometry_violation_scanlines;
    uint64_t ppu_mosaic_violation_scanlines;
    uint64_t ppu_setini_violation_scanlines;
    uint64_t ppu_obj_config_violation_scanlines;
    uint64_t ppu_color_path_violation_scanlines;
    uint64_t ppu_renderer_domain_violation_scanlines;
    js_stop_reason machine_stop;
    js_stop_reason renderer_stop;
    /* Presentation state is outside the original same-build snapshot payload. */
    JungleWideState *wide;
};
#define JS_CORE_SNAPSHOT_BYTES offsetof(JungleStaticCore, wide)

#define JS_PPU_AUDIT_MODE_V10_95          0x01u
#define JS_PPU_AUDIT_BG3_PRIORITY_V10_95  0x02u
#define JS_PPU_AUDIT_TILE_GEOMETRY_V10_95 0x04u
#define JS_PPU_AUDIT_MOSAIC_V10_95        0x08u
#define JS_PPU_AUDIT_SETINI_V10_95        0x10u
#define JS_PPU_AUDIT_OBJ_CONFIG_V10_95    0x20u
#define JS_PPU_AUDIT_COLOR_PATH_V10_95    0x40u

typedef struct js_sha256_ctx_v10_40 { uint32_t h[8]; uint64_t bits; uint8_t buf[64]; size_t used; } js_sha256_ctx_v10_40;
static const uint32_t js_sha_k_v10_40[64]={
0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u};
static uint32_t js_rotr32_v10_40(uint32_t x,unsigned n){return (x>>n)|(x<<(32u-n));}
static void js_sha_block_v10_40(js_sha256_ctx_v10_40 *c,const uint8_t *p){uint32_t w[64],a,b,d,e,f,g,h,t1,t2,cc;unsigned i;for(i=0;i<16u;i++)w[i]=((uint32_t)p[i*4u]<<24)|((uint32_t)p[i*4u+1u]<<16)|((uint32_t)p[i*4u+2u]<<8)|p[i*4u+3u];for(i=16u;i<64u;i++){uint32_t s0=js_rotr32_v10_40(w[i-15u],7)^js_rotr32_v10_40(w[i-15u],18)^(w[i-15u]>>3);uint32_t s1=js_rotr32_v10_40(w[i-2u],17)^js_rotr32_v10_40(w[i-2u],19)^(w[i-2u]>>10);w[i]=w[i-16u]+s0+w[i-7u]+s1;}a=c->h[0];b=c->h[1];cc=c->h[2];d=c->h[3];e=c->h[4];f=c->h[5];g=c->h[6];h=c->h[7];for(i=0;i<64u;i++){uint32_t s1=js_rotr32_v10_40(e,6)^js_rotr32_v10_40(e,11)^js_rotr32_v10_40(e,25);uint32_t ch=(e&f)^((~e)&g);t1=h+s1+ch+js_sha_k_v10_40[i]+w[i];uint32_t s0=js_rotr32_v10_40(a,2)^js_rotr32_v10_40(a,13)^js_rotr32_v10_40(a,22);uint32_t maj=(a&b)^(a&cc)^(b&cc);t2=s0+maj;h=g;g=f;f=e;e=d+t1;d=cc;cc=b;b=a;a=t1+t2;}c->h[0]+=a;c->h[1]+=b;c->h[2]+=cc;c->h[3]+=d;c->h[4]+=e;c->h[5]+=f;c->h[6]+=g;c->h[7]+=h;}
static void js_sha_init_v10_40(js_sha256_ctx_v10_40 *c){static const uint32_t iv[8]={0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u};memcpy(c->h,iv,sizeof(iv));c->bits=0;c->used=0;}
static void js_sha_update_v10_40(js_sha256_ctx_v10_40 *c,const uint8_t *p,size_t n){c->bits+=(uint64_t)n*8u;while(n){size_t take=64u-c->used;if(take>n)take=n;memcpy(c->buf+c->used,p,take);c->used+=take;p+=take;n-=take;if(c->used==64u){js_sha_block_v10_40(c,c->buf);c->used=0;}}}
static void js_sha_final_v10_40(js_sha256_ctx_v10_40 *c,uint8_t out[32]){unsigned i;c->buf[c->used++]=0x80u;if(c->used>56u){while(c->used<64u)c->buf[c->used++]=0;js_sha_block_v10_40(c,c->buf);c->used=0;}while(c->used<56u)c->buf[c->used++]=0;for(i=0;i<8u;i++)c->buf[c->used++]=(uint8_t)(c->bits>>(56u-i*8u));js_sha_block_v10_40(c,c->buf);for(i=0;i<8u;i++){out[i*4u]=(uint8_t)(c->h[i]>>24);out[i*4u+1u]=(uint8_t)(c->h[i]>>16);out[i*4u+2u]=(uint8_t)(c->h[i]>>8);out[i*4u+3u]=(uint8_t)c->h[i];}}
static void js_sha_hex_v10_40(const uint8_t *p,size_t n,char out[65]){static const char h[]="0123456789abcdef";uint8_t d[32];js_sha256_ctx_v10_40 c;unsigned i;js_sha_init_v10_40(&c);js_sha_update_v10_40(&c,p,n);js_sha_final_v10_40(&c,d);for(i=0;i<32u;i++){out[i*2u]=h[d[i]>>4];out[i*2u+1u]=h[d[i]&15u];}out[64]='\0';}

static uint64_t js_fnv_bytes_v10_40(const uint8_t *p,size_t n){uint64_t h=1469598103934665603ull;size_t i;for(i=0;i<n;i++){h^=p[i];h*=1099511628211ull;}return h;}
static uint64_t js_fnv_u16le_v10_40(const uint16_t *p,size_t n){uint64_t h=1469598103934665603ull;size_t i;for(i=0;i<n;i++){h^=(uint8_t)p[i];h*=1099511628211ull;h^=(uint8_t)(p[i]>>8);h*=1099511628211ull;}return h;}

static uint16_t js_input_to_serial_v10_40(uint16_t mask) {
    uint16_t r = 0u;
    if (mask & JUNGLE_BUTTON_B) r |= 1u << 0;
    if (mask & JUNGLE_BUTTON_Y) r |= 1u << 1;
    if (mask & JUNGLE_BUTTON_SELECT) r |= 1u << 2;
    if (mask & JUNGLE_BUTTON_START) r |= 1u << 3;
    if (mask & JUNGLE_BUTTON_UP) r |= 1u << 4;
    if (mask & JUNGLE_BUTTON_DOWN) r |= 1u << 5;
    if (mask & JUNGLE_BUTTON_LEFT) r |= 1u << 6;
    if (mask & JUNGLE_BUTTON_RIGHT) r |= 1u << 7;
    if (mask & JUNGLE_BUTTON_A) r |= 1u << 8;
    if (mask & JUNGLE_BUTTON_X) r |= 1u << 9;
    if (mask & JUNGLE_BUTTON_L) r |= 1u << 10;
    if (mask & JUNGLE_BUTTON_R) r |= 1u << 11;
    return r;
}

int jungle_core_inspect_rom(const void *data,size_t size,JungleCoreRomInfo *out){
    const uint8_t *rom=(const uint8_t*)data;char hash[65];
    if(!rom||!out||size!=JUNGLE_STATIC_CORE_ROM_SIZE)return 0;
    js_sha_hex_v10_40(rom,size,hash);if(strcmp(hash,JUNGLE_STATIC_CORE_ROM_SHA256)!=0)return 0;
    memset(out,0,sizeof(*out));out->file_size=size;out->canonical_rom_size=size;
    out->reset_vector=(uint16_t)(rom[0x7FFCu]|((uint16_t)rom[0x7FFDu]<<8));out->map_mode=rom[0x7FD5u];out->region_code=rom[0x7FD9u];
    memcpy(out->title,rom+0x7FC0u,21u);out->title[21]='\0';memcpy(out->sha256,hash,65u);return 1;
}

static void js_core_render_visible_scanline_v10_88(JungleStaticCore *c, uint16_t y) {
    js_rgb8_v10_28 line[JUNGLE_STATIC_CORE_FRAME_WIDTH];
    uint8_t saved_range_over;
    uint8_t saved_time_over;
    uint16_t x;
    js_stop_reason stop;

    if (!c || y >= JUNGLE_STATIC_CORE_FRAME_HEIGHT) return;
    if (y == 0u) {
        if (c->renderer_stop != JS_STOP_NONE &&
            c->renderer_stop != JS_STOP_V10_40_RENDERER_UNAVAILABLE) return;
        c->renderer_stop = JS_STOP_NONE;
        c->visible_scanlines_rendered = 0u;
    }
    if (c->renderer_stop != JS_STOP_NONE) return;
    if (c->visible_scanlines_rendered != y) {
        c->renderer_stop = JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;
        c->frame_valid = 0u;
        return;
    }

    /* Rendering is evidence/output only here.  The legacy compositor computes
       OBJ overflow as a side effect; preserve the machine-owned status bits so
       adding a framebuffer observer cannot perturb S-CPU-visible PPU state. */
    saved_range_over = c->machine.ppu.range_over;
    saved_time_over = c->machine.ppu.time_over;
    stop = js_renderer_v10_40_render_scanline(&c->machine.ppu, y, line);
    c->machine.ppu.range_over = saved_range_over;
    c->machine.ppu.time_over = saved_time_over;
    if (stop != JS_STOP_NONE) {
        c->renderer_stop = stop;
        c->frame_valid = 0u;
        return;
    }

    for (x = 0u; x < JUNGLE_STATIC_CORE_FRAME_WIDTH; ++x) {
        c->frame_work_bgra[(size_t)y * JUNGLE_STATIC_CORE_FRAME_WIDTH + x] =
            0xFF000000u | ((uint32_t)line[x].r << 16) |
            ((uint32_t)line[x].g << 8) | (uint32_t)line[x].b;
    }
    if(c->wide && c->wide->enabled) {
        stop=jungle_wide_scanline(c->wide,&c->machine,c->rom,c->rom_size,y,line);
        if(stop!=JS_STOP_NONE){c->renderer_stop=stop;c->frame_valid=0u;return;}
    }
    c->visible_scanlines_rendered++;
    if (c->visible_scanlines_rendered == JUNGLE_STATIC_CORE_FRAME_HEIGHT) {
        memcpy(c->frame_bgra, c->frame_work_bgra, sizeof(c->frame_bgra));
        if(c->wide && c->wide->enabled)
            jungle_wide_console(c->wide, &c->machine, c->frame_bgra);
        c->rendered_frame = c->machine.scheduler.frame_count + 1u;
        c->frame_valid = 1u;
    }
}

static uint8_t js_core_ppu_active_violation_mask_v10_95(
    const js_ppu_v09c *ppu) {
    uint8_t mask = 0u;
    int small_bg12;
    uint16_t expected_obj_base;
    if (!ppu) return 0x7Fu;
    if (ppu->bg_mode != 1u) mask |= JS_PPU_AUDIT_MODE_V10_95;
    if (!ppu->mode1_bg3_priority)
        mask |= JS_PPU_AUDIT_BG3_PRIORITY_V10_95;
    if (ppu->layer[0].large_tiles != ppu->layer[1].large_tiles ||
        ppu->layer[2].large_tiles)
        mask |= JS_PPU_AUDIT_TILE_GEOMETRY_V10_95;
    if (ppu->mosaic_enabled)
        mask |= JS_PPU_AUDIT_MOSAIC_V10_95;
    if (ppu->external_sync || ppu->extbg || ppu->hires || ppu->overscan ||
        ppu->obj_interlace || ppu->screen_interlace)
        mask |= JS_PPU_AUDIT_SETINI_V10_95;
    small_bg12 = !ppu->layer[0].large_tiles && !ppu->layer[1].large_tiles;
    expected_obj_base = small_bg12 ? 0x0000u : 0x6000u;
    if (ppu->oam_mode != 0u || ppu->oam_base_address != expected_obj_base ||
        ppu->oam_address_offset != 0x1000u)
        mask |= JS_PPU_AUDIT_OBJ_CONFIG_V10_95;
    if (ppu->color_math_add_subscreen || ppu->direct_color)
        mask |= JS_PPU_AUDIT_COLOR_PATH_V10_95;
    return mask;
}

static void js_core_audit_visible_scanline_v10_95(JungleStaticCore *c) {
    const js_ppu_v09c *ppu;
    uint8_t mask;
    if (!c) return;
    ppu = &c->machine.ppu;
    ++c->ppu_visible_scanlines;
    ++c->ppu_mode_scanlines[ppu->bg_mode & 7u];
    if (ppu->forced_blank) {
        ++c->ppu_forced_blank_scanlines;
        return;
    }
    if (ppu->brightness == 0u) {
        ++c->ppu_brightness_zero_scanlines;
        return;
    }
    ++c->ppu_active_scanlines;
    mask = js_core_ppu_active_violation_mask_v10_95(ppu);
    c->ppu_active_violation_mask |= mask;
    if (!mask) return;
    ++c->ppu_renderer_domain_violation_scanlines;
    if (mask & JS_PPU_AUDIT_MODE_V10_95)
        ++c->ppu_mode_violation_scanlines;
    if (mask & JS_PPU_AUDIT_BG3_PRIORITY_V10_95)
        ++c->ppu_bg3_priority_violation_scanlines;
    if (mask & JS_PPU_AUDIT_TILE_GEOMETRY_V10_95)
        ++c->ppu_tile_geometry_violation_scanlines;
    if (mask & JS_PPU_AUDIT_MOSAIC_V10_95)
        ++c->ppu_mosaic_violation_scanlines;
    if (mask & JS_PPU_AUDIT_SETINI_V10_95)
        ++c->ppu_setini_violation_scanlines;
    if (mask & JS_PPU_AUDIT_OBJ_CONFIG_V10_95)
        ++c->ppu_obj_config_violation_scanlines;
    if (mask & JS_PPU_AUDIT_COLOR_PATH_V10_95)
        ++c->ppu_color_path_violation_scanlines;
}

static void js_core_reset_ppu_audit_v10_95(JungleStaticCore *c) {
    if (!c) return;
    c->ppu_active_violation_mask = 0u;
    c->ppu_visible_scanlines = 0u;
    c->ppu_active_scanlines = 0u;
    c->ppu_forced_blank_scanlines = 0u;
    c->ppu_brightness_zero_scanlines = 0u;
    memset(c->ppu_mode_scanlines, 0, sizeof(c->ppu_mode_scanlines));
    c->ppu_mode_violation_scanlines = 0u;
    c->ppu_bg3_priority_violation_scanlines = 0u;
    c->ppu_tile_geometry_violation_scanlines = 0u;
    c->ppu_mosaic_violation_scanlines = 0u;
    c->ppu_setini_violation_scanlines = 0u;
    c->ppu_obj_config_violation_scanlines = 0u;
    c->ppu_color_path_violation_scanlines = 0u;
    c->ppu_renderer_domain_violation_scanlines = 0u;
}

static void js_core_ppu_event_v10_88(void *opaque, js_scheduler_ppu_event_kind_v09c kind) {
    JungleStaticCore *c = (JungleStaticCore *)opaque;
    if (!c) return;
    js_ppu_v09c_scheduler_event(&c->machine.ppu, kind);
    if (kind == JS_SCHEDULER_PPU_EVENT_V09C_VISIBLE_SCANLINE)
        js_core_audit_visible_scanline_v10_95(c);
    if (kind == JS_SCHEDULER_PPU_EVENT_V09C_VISIBLE_SCANLINE &&
        c->render_output_enabled) {
        /* A single static CPU/DMA step can cross a frame boundary and retire
           after scanline 0 of the following frame.  If that step belonged to
           a headless catch-up frame, those early scanlines were intentionally
           not observed.  Match Mesen's continuous PPU ownership: discard the
           partial observer frame and resume at the next complete scanline 0. */
        if (c->render_resync_pending) {
            if (c->machine.scheduler.scanline != 0u) return;
            c->render_resync_pending = 0u;
        }
        js_core_render_visible_scanline_v10_88(c, c->machine.scheduler.scanline);
    }
}

static int js_core_reinit_v10_40(JungleStaticCore *c) {
    js_bus_ports_v09c ports;
    js_scheduler_hooks_v09c hooks;
    js_stop_reason s;
    if (!c || !c->rom) return 0;
    if (c->machine_initialized) js_machine_v10_40_destroy(&c->machine);
    memset(&ports,0,sizeof(ports));memset(&hooks,0,sizeof(hooks));memset(&c->machine,0,sizeof(c->machine));
    s=js_machine_v10_40_init(&c->machine,c->rom,c->rom_size,ports,hooks);c->machine_initialized=(uint8_t)(s==JS_STOP_NONE);
    if (s == JS_STOP_NONE) {
        c->machine.scheduler.hooks.ppu_opaque = c;
        c->machine.scheduler.hooks.ppu_event = js_core_ppu_event_v10_88;
    }
    js_core_reset_ppu_audit_v10_95(c);
    jungle_wide_invalidate(c->wide);
    c->machine_stop=s;c->renderer_stop=JS_STOP_V10_40_RENDERER_UNAVAILABLE;c->frame_valid=0u;c->render_output_enabled=1u;c->audio_batch_frames=0u;c->rendered_frame=0u;c->visible_scanlines_rendered=0u;c->render_resync_pending=0u;c->render_observer_synchronized=1u;
    return s==JS_STOP_NONE;
}

JungleStaticCore *jungle_core_create(const void *data,size_t size){
    JungleCoreRomInfo info;JungleStaticCore *c;if(!jungle_core_inspect_rom(data,size,&info))return NULL;
    c=(JungleStaticCore*)calloc(1,sizeof(*c));if(!c)return NULL;c->rom=(uint8_t*)malloc(size);if(!c->rom){free(c);return NULL;}
    memcpy(c->rom,data,size);c->rom_size=size;if(!js_core_reinit_v10_40(c)){jungle_core_destroy(c);return NULL;}return c;
}
void jungle_core_destroy(JungleStaticCore *c){if(!c)return;if(c->machine_initialized)js_machine_v10_40_destroy(&c->machine);free(c->wide);free(c->rom);free(c);}
int jungle_core_power_on(JungleStaticCore *c){return js_core_reinit_v10_40(c);}
int jungle_core_reset(JungleStaticCore *c){js_stop_reason s;if(!c||!c->machine_initialized)return 0;s=js_machine_v10_40_reset(&c->machine);jungle_wide_invalidate(c->wide);js_core_reset_ppu_audit_v10_95(c);c->machine_stop=s;c->renderer_stop=JS_STOP_V10_40_RENDERER_UNAVAILABLE;c->frame_valid=0;c->audio_batch_frames=0;c->visible_scanlines_rendered=0u;c->render_resync_pending=0u;c->render_observer_synchronized=1u;return s==JS_STOP_NONE;}

static int js_core_run_frame_mode_v10_88(
    JungleStaticCore *c,uint16_t p1,uint16_t p2,int render_output,
    JungleCoreAudioProgressCallback audio_progress,void *progress_opaque){
    uint64_t target;unsigned steps=0;js_stop_reason s;
    if(!c||!c->machine_initialized||c->machine_stop!=JS_STOP_NONE)return 0;
    if(c->renderer_stop!=JS_STOP_NONE&&c->renderer_stop!=JS_STOP_V10_40_RENDERER_UNAVAILABLE)return 0;
    c->render_output_enabled=(uint8_t)(render_output!=0);
    js_input_v10_2_set_report(&c->machine.input,0u,js_input_to_serial_v10_40(p1));js_input_v10_2_set_report(&c->machine.input,1u,js_input_to_serial_v10_40(p2));
    target=c->machine.scheduler.frame_count+1u;
    /* A continuously enabled renderer already owns the partially completed
       next frame and must not discard it or advance an extra frame.  Resync is
       required only when a previous explicitly-headless API call caused the
       observer to miss part of the current frame. */
    if(render_output && !c->render_observer_synchronized &&
       (c->machine.scheduler.scanline!=0u ||
       c->machine.scheduler.hclock>=1080u)){
        c->render_resync_pending=1u;
        target++;
    }
    while(c->machine.scheduler.frame_count<target&&steps<JS_V10_40_FRAME_STEP_LIMIT){s=js_machine_v10_40_step(&c->machine);if(s!=JS_STOP_NONE){c->machine_stop=s;c->frame_valid=0;c->render_output_enabled=1u;return 0;}if(c->renderer_stop!=JS_STOP_NONE&&c->renderer_stop!=JS_STOP_V10_40_RENDERER_UNAVAILABLE){c->frame_valid=0;c->render_output_enabled=1u;return 0;}steps++;if(audio_progress&&js_dsp_v10_33_pcm_available(&c->machine.apu.dsp)>=128u)audio_progress(c,progress_opaque);}
    if(c->machine.scheduler.frame_count<target){c->machine_stop=JS_STOP_V10_40_FRAME_STEP_LIMIT;c->frame_valid=0;c->render_output_enabled=1u;return 0;}
    c->render_output_enabled=1u;
    c->render_observer_synchronized=(uint8_t)(render_output!=0);
    if(render_output&&(!c->frame_valid||c->rendered_frame<target)){c->renderer_stop=JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT;c->frame_valid=0;return 0;}
    return 1;
}
int jungle_core_run_frame(JungleStaticCore *c,uint16_t p1,uint16_t p2){return js_core_run_frame_mode_v10_88(c,p1,p2,1,NULL,NULL);}
int jungle_core_run_frame_streamed(JungleStaticCore *c,uint16_t p1,uint16_t p2,JungleCoreAudioProgressCallback progress,void *opaque){return js_core_run_frame_mode_v10_88(c,p1,p2,1,progress,opaque);}
int jungle_core_run_frame_headless(JungleStaticCore *c,uint16_t p1,uint16_t p2){return js_core_run_frame_mode_v10_88(c,p1,p2,0,NULL,NULL);}
int jungle_core_get_frame(const JungleStaticCore *c,JungleCoreFrame *out){if(!c||!out||!c->frame_valid)return 0;out->bgra_pixels=(c->wide&&c->wide->enabled&&c->wide->valid&&c->wide->active)?c->wide->pixels:c->frame_bgra;out->width=(c->wide&&c->wide->enabled&&c->wide->valid&&c->wide->active)?JUNGLE_WIDE_WIDTH:JUNGLE_STATIC_CORE_FRAME_WIDTH;out->height=(c->wide&&c->wide->enabled&&c->wide->valid&&c->wide->active)?JUNGLE_WIDE_HEIGHT:JUNGLE_STATIC_CORE_FRAME_HEIGHT;out->pitch_bytes=out->width*4u;out->frame_number=c->rendered_frame;return 1;}
int jungle_core_take_audio(JungleStaticCore *c,JungleCoreAudio *out){size_t avail,i,known=0u;if(!c||!out||!c->machine_initialized)return 0;avail=js_dsp_v10_33_pcm_available(&c->machine.apu.dsp);if(avail>JS_V10_40_AUDIO_BATCH_FRAMES)avail=JS_V10_40_AUDIO_BATCH_FRAMES;c->audio_batch_frames=js_dsp_v10_33_pcm_read_with_knownness(&c->machine.apu.dsp,c->audio_batch,c->audio_known_batch,avail);for(i=0;i<c->audio_batch_frames;i++)if(c->audio_known_batch[i])known++;out->interleaved_stereo=c->audio_batch;out->frame_known=c->audio_known_batch;out->frame_count=c->audio_batch_frames;out->known_frame_count=known;out->unknown_frame_count=c->audio_batch_frames-known;out->sample_rate=JUNGLE_STATIC_CORE_AUDIO_SAMPLE_RATE;return 1;}

int jungle_core_widescreen_enabled(const JungleStaticCore *c){return c&&c->wide?c->wide->enabled:0;}
int jungle_core_set_widescreen(JungleStaticCore *c,int enabled){
    if(!c)return 0;
    if(enabled&&!c->wide){c->wide=(JungleWideState*)calloc(1,sizeof(*c->wide));if(!c->wide)return 0;}
    if(c->wide){c->wide->enabled=enabled!=0;jungle_wide_invalidate(c->wide);}
    if(c->frame_valid)
        jungle_wide_restore_frame(c->wide,&c->machine,c->rom,c->rom_size,c->frame_bgra);
    return 1;
}
size_t jungle_core_snapshot_size(const JungleStaticCore *c){
    size_t smp_size;
    if(!c||!c->machine_initialized||!c->machine.apu.smp)return 0u;
    smp_size=js_smp_v10_2_snapshot_size();
    if(!smp_size||smp_size>SIZE_MAX-sizeof(js_snapshot_header_v10_40)-JS_CORE_SNAPSHOT_BYTES)return 0u;
    return sizeof(js_snapshot_header_v10_40)+JS_CORE_SNAPSHOT_BYTES+smp_size;
}

int jungle_core_save_snapshot(const JungleStaticCore *c,void *dst,size_t dst_size){
    js_snapshot_header_v10_40 header;
    JungleStaticCore *copy;
    uint8_t *bytes=(uint8_t*)dst;
    uint8_t *smp_bytes;
    size_t expected;
    size_t smp_size;
    if(!c||!dst)return 0;
    expected=jungle_core_snapshot_size(c);
    smp_size=js_smp_v10_2_snapshot_size();
    if(!expected||dst_size!=expected||JS_CORE_SNAPSHOT_BYTES>UINT32_MAX||smp_size>UINT32_MAX)return 0;
    copy=(JungleStaticCore*)malloc(sizeof(*copy));
    if(!copy)return 0;
    *copy=*c;
    copy->rom=NULL;
    memset(copy->audio_batch,0,sizeof(copy->audio_batch));
    memset(copy->audio_known_batch,0,sizeof(copy->audio_known_batch));
    copy->audio_batch_frames=0u;
    memset(copy->machine.apu.dsp.pcm_fifo,0,sizeof(copy->machine.apu.dsp.pcm_fifo));
    memset(copy->machine.apu.dsp.pcm_known_fifo,0,sizeof(copy->machine.apu.dsp.pcm_known_fifo));
    copy->machine.apu.dsp.pcm_read_index=0u;
    copy->machine.apu.dsp.pcm_write_index=0u;
    copy->machine.apu.dsp.pcm_count=0u;
    js_machine_v10_40_snapshot_sanitize(&copy->machine);
    smp_bytes=bytes+sizeof(header)+JS_CORE_SNAPSHOT_BYTES;
    if(!js_smp_v10_2_snapshot_save(c->machine.apu.smp,smp_bytes,smp_size)){
        free(copy);return 0;
    }
    memset(&header,0,sizeof(header));
    memcpy(header.magic,"JSSNAP10",8u);
    header.version=JS_V10_40_SNAPSHOT_VERSION;
    header.core_size=(uint32_t)JS_CORE_SNAPSHOT_BYTES;
    header.smp_size=(uint32_t)smp_size;
    header.core_hash=js_fnv_bytes_v10_40((const uint8_t*)copy,JS_CORE_SNAPSHOT_BYTES);
    header.smp_hash=js_fnv_bytes_v10_40(smp_bytes,smp_size);
    memcpy(bytes,&header,sizeof(header));
    memcpy(bytes+sizeof(header),copy,JS_CORE_SNAPSHOT_BYTES);
    free(copy);
    return 1;
}

int jungle_core_load_snapshot(JungleStaticCore *c,const void *src,size_t src_size){
    js_snapshot_header_v10_40 header;
    const uint8_t *bytes=(const uint8_t*)src;
    const JungleStaticCore *copy;
    const uint8_t *smp_bytes;
    js_smp_v10_2 *smp;
    uint8_t *rom;
    size_t rom_size;
    size_t expected;
    size_t smp_size;
    if(!c||!src||!c->machine_initialized||!c->machine.apu.smp)return 0;
    expected=jungle_core_snapshot_size(c);
    smp_size=js_smp_v10_2_snapshot_size();
    if(!expected||src_size!=expected||src_size<sizeof(header))return 0;
    memcpy(&header,bytes,sizeof(header));
    if(memcmp(header.magic,"JSSNAP10",8u)!=0||
       header.version!=JS_V10_40_SNAPSHOT_VERSION||
       header.core_size!=JS_CORE_SNAPSHOT_BYTES||header.smp_size!=smp_size)return 0;
    copy=(const JungleStaticCore*)(bytes+sizeof(header));
    smp_bytes=bytes+sizeof(header)+JS_CORE_SNAPSHOT_BYTES;
    if(header.core_hash!=js_fnv_bytes_v10_40((const uint8_t*)copy,JS_CORE_SNAPSHOT_BYTES)||
       header.smp_hash!=js_fnv_bytes_v10_40(smp_bytes,smp_size))return 0;
    if(!copy->machine_initialized||copy->rom!=NULL||copy->machine.apu.smp!=NULL)return 0;
    smp=c->machine.apu.smp;
    if(!js_smp_v10_2_snapshot_load(smp,smp_bytes,smp_size))return 0;
    rom=c->rom;
    rom_size=c->rom_size;
    memcpy(c,copy,JS_CORE_SNAPSHOT_BYTES);
    jungle_wide_invalidate(c->wide);
    c->rom=rom;
    c->rom_size=rom_size;
    c->machine.apu.smp=smp;
    js_machine_v10_40_snapshot_rebind(&c->machine,rom,rom_size,c,
                                      js_core_ppu_event_v10_88);
    c->audio_batch_frames=0u;
    if(c->frame_valid)
        jungle_wide_restore_frame(c->wide,&c->machine,c->rom,c->rom_size,c->frame_bgra);
    return 1;
}

int jungle_core_status(const JungleStaticCore *c,JungleCoreStatus *out){js_smp_v10_2_state ss;const uint8_t *w;const js_ppu_v09c *p;if(!c||!out)return 0;memset(out,0,sizeof(*out));out->sealed_contexts=JUNGLE_STATIC_CORE_SEALED_CONTEXTS;out->production_contexts=JUNGLE_STATIC_CORE_PRODUCTION_CONTEXTS;out->production_rom_bytes=JUNGLE_STATIC_CORE_PRODUCTION_ROM_BYTES;out->immutable_data_bytes=JUNGLE_STATIC_CORE_IMMUTABLE_DATA_BYTES;out->sealed_not_production_contexts=JUNGLE_STATIC_CORE_SEALED_CONTEXTS>JUNGLE_STATIC_CORE_PRODUCTION_CONTEXTS?JUNGLE_STATIC_CORE_SEALED_CONTEXTS-JUNGLE_STATIC_CORE_PRODUCTION_CONTEXTS:0u;out->master_clock=c->machine.scheduler.master_clock;out->frame_number=c->machine.scheduler.frame_count;out->retired_scpu_instructions=c->machine.cpu_core.cpu.retired_instructions;out->scpu_pc=c->machine.cpu_core.cpu.pc;out->scpu_pbr=c->machine.cpu_core.cpu.pbr;if(c->machine.apu.smp){js_smp_v10_2_get_state(c->machine.apu.smp,&ss);out->smp_instructions=ss.instructions;out->smp_cycles=ss.executed_cycles;out->smp_pc=ss.pc;}out->dsp_phase_steps=c->machine.apu.dsp.phase_steps;out->pcm_frames_produced=c->machine.apu.dsp.pcm_frames_produced;out->pcm_known_frames_produced=c->machine.apu.dsp.pcm_known_frames_produced;out->pcm_unknown_frames_produced=c->machine.apu.dsp.pcm_unknown_frames_produced;out->pcm_hash=c->machine.apu.dsp.pcm_fnv1a64;out->pcm_hash_fully_known=(uint8_t)(c->machine.apu.dsp.pcm_unknown_frames_produced==0u);out->dsp_phase=c->machine.apu.dsp.phase;out->frame_valid=c->frame_valid;out->exact_pc_smp_aot=1u;out->exact_32_phase_sdsp=1u;out->interpreter_fallback_enabled=0u;out->machine_stop_code=(uint32_t)c->machine_stop;out->renderer_stop_code=(uint32_t)c->renderer_stop;out->player1_serial_report=c->machine.input.physical_report[0];out->player2_serial_report=c->machine.input.physical_report[1];out->autojoy1_report=c->machine.input.auto_data[0];out->autojoy2_report=c->machine.input.auto_data[1];w=c->machine.bus.base.wram;out->game_input_report=(uint16_t)(w[0x0C7Bu]|((uint16_t)w[0x0C7Cu]<<8u));out->game_input_transition=(uint16_t)(w[0x0C7Du]|((uint16_t)w[0x0C7Eu]<<8u));out->game_input_effective=(uint16_t)(w[0x0CD5u]|((uint16_t)w[0x0CD6u]<<8u));out->game_input_previous=(uint16_t)(w[0x0CD7u]|((uint16_t)w[0x0CD8u]<<8u));p=&c->machine.ppu;out->ppu_forced_blank=p->forced_blank;out->ppu_brightness=p->brightness;out->ppu_bg_mode=p->bg_mode;out->ppu_mode1_bg3_priority=p->mode1_bg3_priority;out->ppu_mosaic_enabled=p->mosaic_enabled;out->ppu_main_screen_layers=p->main_screen_layers;out->ppu_sub_screen_layers=p->sub_screen_layers;out->ppu_setini_flags=(uint8_t)((p->external_sync?1u:0u)|(p->extbg?2u:0u)|(p->hires?4u:0u)|(p->overscan?8u:0u)|(p->obj_interlace?16u:0u)|(p->screen_interlace?32u:0u));out->ppu_bg_large_tile_mask=(uint8_t)((p->layer[0].large_tiles?1u:0u)|(p->layer[1].large_tiles?2u:0u)|(p->layer[2].large_tiles?4u:0u)|(p->layer[3].large_tiles?8u:0u));out->ppu_direct_color=p->direct_color;out->ppu_color_math_add_subscreen=p->color_math_add_subscreen;out->ppu_active_violation_mask=c->ppu_active_violation_mask;out->ppu_visible_scanlines=c->ppu_visible_scanlines;out->ppu_active_scanlines=c->ppu_active_scanlines;out->ppu_forced_blank_scanlines=c->ppu_forced_blank_scanlines;out->ppu_brightness_zero_scanlines=c->ppu_brightness_zero_scanlines;memcpy(out->ppu_mode_scanlines,c->ppu_mode_scanlines,sizeof(out->ppu_mode_scanlines));out->ppu_mode_violation_scanlines=c->ppu_mode_violation_scanlines;out->ppu_bg3_priority_violation_scanlines=c->ppu_bg3_priority_violation_scanlines;out->ppu_tile_geometry_violation_scanlines=c->ppu_tile_geometry_violation_scanlines;out->ppu_mosaic_violation_scanlines=c->ppu_mosaic_violation_scanlines;out->ppu_setini_violation_scanlines=c->ppu_setini_violation_scanlines;out->ppu_obj_config_violation_scanlines=c->ppu_obj_config_violation_scanlines;out->ppu_color_path_violation_scanlines=c->ppu_color_path_violation_scanlines;out->ppu_renderer_domain_violation_scanlines=c->ppu_renderer_domain_violation_scanlines;memcpy(out->ppu_register_reads,p->register_reads,sizeof(out->ppu_register_reads));memcpy(out->ppu_register_writes,p->register_writes,sizeof(out->ppu_register_writes));memcpy(out->ppu_observed_read_values,p->observed_read_values,sizeof(out->ppu_observed_read_values));memcpy(out->ppu_observed_write_values,p->observed_write_values,sizeof(out->ppu_observed_write_values));return 1;}

static void js_format_context_v10_89(char *dst,size_t cap,
                                      js_static_context_key key){
    if(!dst||!cap)return;
    (void)snprintf(dst,cap,"%02X:%04X:E%uM%uX%u",(unsigned)key.pbr,
                   (unsigned)key.pc,(unsigned)key.e,(unsigned)key.m,
                   (unsigned)key.x);
}

static void js_append_context_v10_89(char *dst,size_t cap,
                                      js_static_context_key key,
                                      const char *separator){
    size_t used;
    char formatted[40];
    if(!dst||!cap)return;
    used=strlen(dst);
    if(used>=cap-1u)return;
    js_format_context_v10_89(formatted,sizeof(formatted),key);
    (void)snprintf(dst+used,cap-used,"%s%s",used&&separator?separator:"",
                   formatted);
}

int jungle_core_failure(const JungleStaticCore *c,JungleCoreFailure *out){
    const js_machine_v05c *cpu_core;
    js_stop_reason s;
    const char *proc;
    js_smp_v10_2_state ss;
    uint32_t i,start;
    if(!c||!out)return 0;
    memset(out,0,sizeof(*out));
    cpu_core=&c->machine.cpu_core;
    s=c->machine_stop!=JS_STOP_NONE?c->machine_stop:c->renderer_stop;
    if(s==JS_STOP_NONE||s==JS_STOP_V10_40_RENDERER_UNAVAILABLE)return 1;
    out->failed=1u;
    out->stop_code=(uint32_t)s;
    if((unsigned)s>=5200u&&(unsigned)s<=5204u)proc="S-DSP";
    else if((unsigned)s>=5040u&&(unsigned)s<=5048u)proc="S-SMP";
    else if((unsigned)s>=5070u&&(unsigned)s<=5094u)proc="PPU";
    else proc="S-CPU";
    (void)snprintf(out->processor,sizeof(out->processor),"%s",proc);
    if(strcmp(proc,"S-SMP")==0&&c->machine.apu.smp){
        js_smp_v10_2_get_state(c->machine.apu.smp,&ss);
        (void)snprintf(out->context,sizeof(out->context),"PC=%04X",ss.pc);
    }else{
        js_static_context_key current;
        current.pbr=c->machine.cpu_core.cpu.pbr;
        current.pc=c->machine.cpu_core.cpu.pc;
        current.e=c->machine.cpu_core.cpu.e;
        current.m=(uint8_t)((c->machine.cpu_core.cpu.p&JS_FLAG_M)!=0u);
        current.x=(uint8_t)((c->machine.cpu_core.cpu.p&JS_FLAG_X)!=0u);
        js_format_context_v10_89(out->context,sizeof(out->context),current);
    }
    (void)snprintf(out->reason,sizeof(out->reason),"%s",
                   js_stop_reason_name_v10_40(s));
    out->master_clock=c->machine.scheduler.master_clock;
    out->frame_number=c->machine.scheduler.frame_count;
    if(cpu_core->diagnostic_failure_valid){
        js_format_context_v10_89(out->source_context,
                                 sizeof(out->source_context),
                                 cpu_core->diagnostic_failure_source);
        js_format_context_v10_89(out->target_context,
                                 sizeof(out->target_context),
                                 cpu_core->diagnostic_failure_target);
        out->expected_context_count=cpu_core->diagnostic_expected_count;
        for(i=0u;i<cpu_core->diagnostic_expected_stored;i++)
            js_append_context_v10_89(out->expected_contexts,
                                     sizeof(out->expected_contexts),
                                     cpu_core->diagnostic_expected[i]," | ");
    }
    out->recent_context_count=cpu_core->diagnostic_trace_count;
    start=cpu_core->diagnostic_trace_count<JS_V05C_DIAGNOSTIC_TRACE_CAPACITY?
          0u:cpu_core->diagnostic_trace_next;
    for(i=0u;i<cpu_core->diagnostic_trace_count;i++){
        uint32_t slot=(start+i)%JS_V05C_DIAGNOSTIC_TRACE_CAPACITY;
        js_append_context_v10_89(out->recent_contexts,
                                 sizeof(out->recent_contexts),
                                 cpu_core->diagnostic_trace[slot]," -> ");
    }
    return 1;
}

static int js_diag_format_v10_40(const JungleStaticCore *c,char *dst,size_t cap){
    js_smp_v10_2_state ss;JungleCoreFailure failure;uint64_t wram,vr,cg,oam,aram,known,frameh;int n;if(!c)return -1;memset(&ss,0,sizeof(ss));memset(&failure,0,sizeof(failure));if(c->machine.apu.smp)js_smp_v10_2_get_state(c->machine.apu.smp,&ss);(void)jungle_core_failure(c,&failure);
    wram=js_fnv_bytes_v10_40(c->machine.bus.base.wram,sizeof(c->machine.bus.base.wram));vr=js_fnv_u16le_v10_40(c->machine.ppu.vram,JS_V09C_VRAM_WORDS);cg=js_fnv_u16le_v10_40(c->machine.ppu.cgram,JS_V09C_CGRAM_WORDS);oam=js_fnv_bytes_v10_40(c->machine.ppu.oam,JS_V09C_OAM_BYTES);aram=js_fnv_bytes_v10_40(c->machine.apu.aram,JS_V10_33_ARAM_SIZE);known=js_fnv_bytes_v10_40(c->machine.apu.aram_known,JS_V10_33_ARAM_KNOWN_SIZE);frameh=js_fnv_bytes_v10_40((const uint8_t*)c->frame_bgra,sizeof(c->frame_bgra));
    n=snprintf(dst,cap,
"{\n  \"schema\":\"JungleStrikeDiagnostic1.0.0\",\n  \"core_version\":\"1.1.0\",\n  \"authority\":{\"sealed_contexts\":27835,\"production_contexts\":28636,\"production_rom_bytes\":66177,\"immutable_data_bytes\":46386},\n  \"stop\":{\"machine\":%u,\"renderer\":%u},\n  \"failure_evidence\":{\"valid\":%s,\"stop_code\":%u,\"processor\":\"%s\",\"reason\":\"%s\",\"source\":\"%s\",\"target\":\"%s\",\"expected_count\":%u,\"expected\":\"%s\",\"recent_count\":%u,\"recent_oldest_to_newest\":\"%s\"},\n  \"scpu\":{\"pbr\":%u,\"pc\":%u,\"a\":%u,\"x\":%u,\"y\":%u,\"sp\":%u,\"d\":%u,\"dbr\":%u,\"p\":%u,\"e\":%u,\"retired\":%" PRIu64 "},\n  \"scheduler\":{\"master_clock\":%" PRIu64 ",\"frame\":%" PRIu64 ",\"scanline\":%u,\"hclock\":%u,\"smp_target\":%" PRIu64 ",\"audio_clock_profile\":\"%s\",\"audio_half_tick_ratio_numerator\":%u,\"audio_half_tick_ratio_denominator\":%u,\"audio_clock_remainder\":%u,\"audio_sample_rate\":%u},\n  \"smp\":{\"pc\":%u,\"instructions\":%" PRIu64 ",\"cycles\":%" PRIu64 ",\"aot_instructions\":%" PRIu64 ",\"stopped\":%u},\n  \"dsp\":{\"phase\":%u,\"phase_steps\":%" PRIu64 ",\"sample_steps\":%" PRIu64 ",\"pcm_frames\":%" PRIu64 ",\"pcm_known_frames\":%" PRIu64 ",\"pcm_unknown_frames\":%" PRIu64 ",\"pcm_hash\":\"%016" PRIx64 "\",\"pcm_hash_fully_known\":%s,\"last_stop\":%u,\"last_aram_phase\":%u,\"last_aram_address\":%u,\"last_aram_known\":%u,\"dir_latch\":%u,\"source_number\":%u,\"brr_next_address\":%u,\"brr_next_known\":%u,\"mvoll\":%d,\"mvolr\":%d,\"evoll\":%d,\"evolr\":%d,\"efb\":%d,\"flg\":%u,\"esa\":%u,\"edl\":%u,\"echo_known_flags\":%u},\n  \"input\":{\"port1_serial\":%u,\"port2_serial\":%u,\"auto0\":%u,\"auto1\":%u},\n  \"ppu\":{\"forced_blank\":%u,\"brightness\":%u,\"bg_mode\":%u,\"tm\":%u,\"ts\":%u,\"cgwsel_clip\":%u,\"cgwsel_prevent\":%u,\"cgwsel_subscreen\":%u,\"cgadsub\":%u},\n  \"hashes_fnv1a64\":{\"wram\":\"%016" PRIx64 "\",\"vram\":\"%016" PRIx64 "\",\"cgram\":\"%016" PRIx64 "\",\"oam\":\"%016" PRIx64 "\",\"aram\":\"%016" PRIx64 "\",\"aram_known\":\"%016" PRIx64 "\",\"frame_bgra\":\"%016" PRIx64 "\"},\n  \"frontend_boundary\":{\"exact_pc_smp_aot\":true,\"exact_32_phase_sdsp\":true,\"interpreter_fallback\":false,\"frame_valid\":%s,\"diagnostic_snapshot_restorable_save_state\":false}\n}\n",
(unsigned)c->machine_stop,(unsigned)c->renderer_stop,failure.failed?"true":"false",(unsigned)failure.stop_code,failure.processor,failure.reason,failure.source_context,failure.target_context,(unsigned)failure.expected_context_count,failure.expected_contexts,(unsigned)failure.recent_context_count,failure.recent_contexts,(unsigned)c->machine.cpu_core.cpu.pbr,(unsigned)c->machine.cpu_core.cpu.pc,(unsigned)c->machine.cpu_core.cpu.a,(unsigned)c->machine.cpu_core.cpu.x,(unsigned)c->machine.cpu_core.cpu.y,(unsigned)c->machine.cpu_core.cpu.sp,(unsigned)c->machine.cpu_core.cpu.d,(unsigned)c->machine.cpu_core.cpu.dbr,(unsigned)c->machine.cpu_core.cpu.p,(unsigned)c->machine.cpu_core.cpu.e,c->machine.cpu_core.cpu.retired_instructions,c->machine.scheduler.master_clock,c->machine.scheduler.frame_count,(unsigned)c->machine.scheduler.scanline,(unsigned)c->machine.scheduler.hclock,c->machine.scheduler.smp_target_cycle,JS_V09C_AUDIO_CLOCK_PROFILE_NAME,(unsigned)JS_V09C_SMP_HALF_TICK_RATIO_NUMERATOR,(unsigned)JS_V09C_SMP_HALF_TICK_RATIO_DENOMINATOR,(unsigned)c->machine.scheduler.smp_clock_remainder,(unsigned)JUNGLE_STATIC_CORE_AUDIO_SAMPLE_RATE,(unsigned)ss.pc,ss.instructions,ss.executed_cycles,ss.aot_instructions,(unsigned)ss.stopped,(unsigned)c->machine.apu.dsp.phase,c->machine.apu.dsp.phase_steps,c->machine.apu.dsp.sample_steps,c->machine.apu.dsp.pcm_frames_produced,c->machine.apu.dsp.pcm_known_frames_produced,c->machine.apu.dsp.pcm_unknown_frames_produced,c->machine.apu.dsp.pcm_fnv1a64,c->machine.apu.dsp.pcm_unknown_frames_produced?"false":"true",(unsigned)c->machine.apu.dsp.last_stop,(unsigned)c->machine.apu.dsp.last_aram_phase,(unsigned)c->machine.apu.dsp.last_aram_address,(unsigned)c->machine.apu.dsp.last_aram_known,(unsigned)c->machine.apu.dsp.dir_latch,(unsigned)c->machine.apu.dsp.source_number,(unsigned)c->machine.apu.dsp.brr_next_address,(unsigned)c->machine.apu.dsp.brr_next_known,(int)(int8_t)c->machine.apu.dsp.regs[0x0c],(int)(int8_t)c->machine.apu.dsp.regs[0x1c],(int)(int8_t)c->machine.apu.dsp.regs[0x2c],(int)(int8_t)c->machine.apu.dsp.regs[0x3c],(int)(int8_t)c->machine.apu.dsp.regs[0x0d],(unsigned)c->machine.apu.dsp.regs[0x6c],(unsigned)c->machine.apu.dsp.regs[0x6d],(unsigned)c->machine.apu.dsp.regs[0x7d],(unsigned)c->machine.apu.dsp.echo_enabled_latch,(unsigned)c->machine.input.physical_report[0],(unsigned)c->machine.input.physical_report[1],(unsigned)c->machine.input.auto_data[0],(unsigned)c->machine.input.auto_data[1],(unsigned)c->machine.ppu.forced_blank,(unsigned)c->machine.ppu.brightness,(unsigned)c->machine.ppu.bg_mode,(unsigned)c->machine.ppu.main_screen_layers,(unsigned)c->machine.ppu.sub_screen_layers,(unsigned)c->machine.ppu.color_math_clip_mode,(unsigned)c->machine.ppu.color_math_prevent_mode,(unsigned)c->machine.ppu.color_math_add_subscreen,(unsigned)c->machine.ppu.color_math_enabled,wram,vr,cg,oam,aram,known,frameh,c->frame_valid?"true":"false");return n;
}
size_t jungle_core_diagnostic_snapshot_size(const JungleStaticCore *c){int n=js_diag_format_v10_40(c,NULL,0);return n<0?0u:(size_t)n+1u;}
int jungle_core_save_diagnostic_snapshot(const JungleStaticCore *c,void *dst,size_t size){int n;if(!c||!dst)return 0;n=js_diag_format_v10_40(c,(char*)dst,size);return n>=0&&(size_t)n<size;}
