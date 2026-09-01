#ifndef JUNGLE_INPUT_V10_2_H
#define JUNGLE_INPUT_V10_2_H
#include <stdint.h>
#include "jungle/status.h"
#ifdef __cplusplus
extern "C" {
#endif
/* Serial report order, bit 0 first on $4016/$4017:
   B,Y,Select,Start,Up,Down,Left,Right,A,X,L,R,0,0,0,0. */
typedef struct js_input_v10_2 {
    uint16_t physical_report[2];
    uint16_t shift_register[2];
    uint16_t auto_data[4];
    uint8_t sampled_serial[4];
    uint8_t cpu_strobe;
    uint8_t auto_strobe;
    uint8_t effective_strobe;
    uint8_t *open_bus;
    uint64_t serial_reads;
    uint64_t autojoy_samples;
} js_input_v10_2;

void js_input_v10_2_power_on(js_input_v10_2 *input, uint8_t *open_bus);
void js_input_v10_2_reset(js_input_v10_2 *input);
void js_input_v10_2_set_report(js_input_v10_2 *input, unsigned port, uint16_t serial_lsb_report);
uint16_t js_input_v10_2_get_auto_data(const js_input_v10_2 *input, unsigned index);
js_stop_reason js_input_v10_2_read8(void *opaque, uint16_t reg, uint8_t *value);
js_stop_reason js_input_v10_2_write8(void *opaque, uint16_t reg, uint8_t value);
void js_input_v10_2_autojoy_step(void *opaque, unsigned step, uint8_t enabled);
void js_input_v10_2_autojoy_control(void *opaque, uint8_t enabled);
#ifdef __cplusplus
}
#endif
#endif
