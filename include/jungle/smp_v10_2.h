#ifndef JUNGLE_SMP_V10_2_H
#define JUNGLE_SMP_V10_2_H
#include <stddef.h>
#include <stdint.h>
#include "jungle/status_v10_2.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct js_smp_v10_2 js_smp_v10_2;
typedef js_stop_reason (*js_smp_v10_2_dsp_write_hook)(void *opaque, uint8_t reg, uint8_t value);
typedef js_stop_reason (*js_smp_v10_2_dsp_read_hook)(void *opaque, uint8_t reg, uint8_t *value);
typedef js_stop_reason (*js_smp_v10_2_dsp_cycle_hook)(void *opaque, uint32_t cycles);
typedef struct js_smp_v10_2_state {
  uint16_t pc; uint8_t a,x,y,sp,psw;
  uint64_t executed_cycles, instructions, aot_instructions;
  uint16_t fail_pc; uint8_t expected_opcode, actual_opcode;
  uint8_t code_sealed, iplrom_enable, stopped;
  uint8_t timer_enable_mask, dsp_addr;
  uint64_t code_write_barriers, unknown_reads, dsp_writes, dsp_reads, high_aram_writes;
} js_smp_v10_2_state;
js_smp_v10_2 *js_smp_v10_2_create(uint8_t *aram, uint8_t *known_mask,
                                   uint8_t *cpu_to_smp, uint8_t *smp_to_cpu);
void js_smp_v10_2_destroy(js_smp_v10_2 *smp);
void js_smp_v10_2_power_on(js_smp_v10_2 *smp);
void js_smp_v10_2_cpu_port_write(js_smp_v10_2 *smp, unsigned port, uint8_t value);
void js_smp_v10_2_set_dsp_hooks(js_smp_v10_2 *smp, void *opaque,
                                js_smp_v10_2_dsp_write_hook write_hook,
                                js_smp_v10_2_dsp_read_hook read_hook,
                                js_smp_v10_2_dsp_cycle_hook cycle_hook);
js_stop_reason js_smp_v10_2_run_to(js_smp_v10_2 *smp, uint64_t target_ticks_2mhz);
js_stop_reason js_smp_v10_2_last_stop(const js_smp_v10_2 *smp);
void js_smp_v10_2_get_state(const js_smp_v10_2 *smp, js_smp_v10_2_state *state);
/* Restorable, same-build S-SMP state used by the complete core snapshot.
   Host-owned memory and DSP callback pointers are excluded and rebound when
   the state is loaded. */
size_t js_smp_v10_2_snapshot_size(void);
int js_smp_v10_2_snapshot_save(const js_smp_v10_2 *smp,
                               void *destination, size_t capacity);
int js_smp_v10_2_snapshot_load(js_smp_v10_2 *smp,
                               const void *source, size_t size);
#ifdef __cplusplus
}
#endif
#endif
