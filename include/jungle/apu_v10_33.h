#ifndef JUNGLE_APU_V10_33_H
#define JUNGLE_APU_V10_33_H
#include <stddef.h>
#include <stdint.h>
#include "jungle/dsp_v10_33.h"
#include "jungle/scheduler_v09c.h"
#include "jungle/smp_v10_2.h"
#ifdef __cplusplus
extern "C" {
#endif
#define JS_V10_33_ARAM_SIZE 65536u
#define JS_V10_33_ARAM_KNOWN_SIZE 8192u
typedef struct js_apu_v10_33 {
    js_scheduler_v09c *scheduler;
    js_smp_v10_2 *smp;
    js_dsp_v10_33 dsp;
    uint8_t cpu_to_smp[4], smp_to_cpu[4];
    uint8_t aram[JS_V10_33_ARAM_SIZE], aram_known[JS_V10_33_ARAM_KNOWN_SIZE];
    uint64_t synced_smp_ticks, cpu_reads, cpu_writes, sync_calls;
    js_stop_reason last_stop;
} js_apu_v10_33;
js_stop_reason js_apu_v10_33_power_on(js_apu_v10_33 *apu, js_scheduler_v09c *scheduler);
void js_apu_v10_33_destroy(js_apu_v10_33 *apu);
void js_apu_v10_33_cpu_reset(js_apu_v10_33 *apu);
void js_apu_v10_33_snapshot_rebind(js_apu_v10_33 *apu,
                                   js_scheduler_v09c *scheduler);
void js_apu_v10_33_sync(void *opaque, uint64_t target_cycle);
js_stop_reason js_apu_v10_33_read8(void *opaque, uint16_t reg, uint8_t *value);
js_stop_reason js_apu_v10_33_write8(void *opaque, uint16_t reg, uint8_t value);
int js_apu_v10_33_aram_known(const js_apu_v10_33 *apu, uint16_t address);
size_t js_apu_v10_33_known_byte_count(const js_apu_v10_33 *apu);
#ifdef __cplusplus
}
#endif
#endif
