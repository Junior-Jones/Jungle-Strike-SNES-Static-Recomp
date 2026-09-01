#include <string.h>
#include "jungle/apu_v10_33.h"
static js_stop_reason js_v10_33_dsp_write_hook(void *opaque,uint8_t reg,uint8_t value){return js_dsp_v10_33_write_register((js_dsp_v10_33*)opaque,reg,value);}
static js_stop_reason js_v10_33_dsp_read_hook(void *opaque,uint8_t reg,uint8_t *value){return js_dsp_v10_33_read_register((js_dsp_v10_33*)opaque,reg,value);}
static js_stop_reason js_v10_33_dsp_cycle_hook(void *opaque,uint32_t cycles){return js_dsp_v10_33_step_smp_cycles((js_dsp_v10_33*)opaque,cycles);}
int js_apu_v10_33_aram_known(const js_apu_v10_33 *a,uint16_t x){return a?((a->aram_known[x>>3u]&(uint8_t)(1u<<(x&7u)))!=0u):0;}
size_t js_apu_v10_33_known_byte_count(const js_apu_v10_33 *a){size_t n=0;unsigned i;if(!a)return 0;for(i=0;i<65536u;i++)if(js_apu_v10_33_aram_known(a,(uint16_t)i))n++;return n;}
js_stop_reason js_apu_v10_33_power_on(js_apu_v10_33 *a,js_scheduler_v09c *s){if(!a)return JS_STOP_V10_2_SMP_ALLOCATION;memset(a,0,sizeof(*a));a->scheduler=s;js_dsp_v10_33_power_on(&a->dsp,a->aram,a->aram_known);a->smp=js_smp_v10_2_create(a->aram,a->aram_known,a->cpu_to_smp,a->smp_to_cpu);if(!a->smp){a->last_stop=JS_STOP_V10_2_SMP_ALLOCATION;return a->last_stop;}js_smp_v10_2_set_dsp_hooks(a->smp,&a->dsp,js_v10_33_dsp_write_hook,js_v10_33_dsp_read_hook,js_v10_33_dsp_cycle_hook);js_smp_v10_2_power_on(a->smp);return JS_STOP_NONE;}
void js_apu_v10_33_destroy(js_apu_v10_33 *a){if(a&&a->smp){js_smp_v10_2_destroy(a->smp);a->smp=NULL;}}
void js_apu_v10_33_cpu_reset(js_apu_v10_33 *a){(void)a;}
void js_apu_v10_33_snapshot_rebind(js_apu_v10_33 *a,js_scheduler_v09c *s){if(!a||!a->smp)return;a->scheduler=s;a->dsp.aram=a->aram;a->dsp.aram_known=a->aram_known;js_smp_v10_2_set_dsp_hooks(a->smp,&a->dsp,js_v10_33_dsp_write_hook,js_v10_33_dsp_read_hook,js_v10_33_dsp_cycle_hook);}
void js_apu_v10_33_sync(void *o,uint64_t target){js_apu_v10_33 *a=(js_apu_v10_33*)o;if(!a||!a->smp||a->last_stop!=JS_STOP_NONE)return;a->synced_smp_ticks=target;a->sync_calls++;a->last_stop=js_smp_v10_2_run_to(a->smp,target);}
js_stop_reason js_apu_v10_33_read8(void *o,uint16_t reg,uint8_t *v){js_apu_v10_33 *a=(js_apu_v10_33*)o;unsigned p;if(!a||!v||reg<0x2140u||reg>0x2143u)return JS_STOP_APU_UNAVAILABLE;if(a->last_stop!=JS_STOP_NONE)return a->last_stop;p=reg&3u;*v=a->smp_to_cpu[p];a->cpu_reads++;return JS_STOP_NONE;}
js_stop_reason js_apu_v10_33_write8(void *o,uint16_t reg,uint8_t v){js_apu_v10_33 *a=(js_apu_v10_33*)o;unsigned p;if(!a||reg<0x2140u||reg>0x2143u)return JS_STOP_APU_UNAVAILABLE;if(a->last_stop!=JS_STOP_NONE)return a->last_stop;p=reg&3u;a->cpu_to_smp[p]=v;js_smp_v10_2_cpu_port_write(a->smp,p,v);a->cpu_writes++;return JS_STOP_NONE;}
