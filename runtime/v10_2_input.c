#include <string.h>
#include "jungle/input_v10_2.h"

static uint8_t js_input_v10_2_bus(const js_input_v10_2 *in) {
    return in && in->open_bus ? *in->open_bus : 0u;
}

static void js_input_v10_2_latch(js_input_v10_2 *in) {
    in->shift_register[0] = (uint16_t)(in->physical_report[0] & 0x0FFFu);
    in->shift_register[1] = (uint16_t)(in->physical_report[1] & 0x0FFFu);
}

static void js_input_v10_2_set_effective(js_input_v10_2 *in) {
    uint8_t next = (uint8_t)((in->cpu_strobe | in->auto_strobe) & 1u);
    in->effective_strobe = next;
    if (next) js_input_v10_2_latch(in);
}

static uint8_t js_input_v10_2_serial(js_input_v10_2 *in, unsigned port) {
    uint8_t bit;
    if (port >= 2u) return 0u;
    if (in->effective_strobe) js_input_v10_2_latch(in);
    bit = (uint8_t)(in->shift_register[port] & 1u);
    if (!in->effective_strobe) {
        /* Authentic standard pads return one forever after their 16-bit report. */
        in->shift_register[port] = (uint16_t)((in->shift_register[port] >> 1u) | 0x8000u);
    }
    in->serial_reads++;
    return bit;
}

void js_input_v10_2_power_on(js_input_v10_2 *in, uint8_t *open_bus) {
    if (!in) return;
    memset(in, 0, sizeof(*in));
    in->open_bus = open_bus;
    js_input_v10_2_latch(in);
}

void js_input_v10_2_reset(js_input_v10_2 *in) {
    uint16_t p0, p1; uint8_t *open_bus;
    if (!in) return;
    p0=in->physical_report[0]; p1=in->physical_report[1]; open_bus=in->open_bus;
    memset(in,0,sizeof(*in));
    in->physical_report[0]=p0; in->physical_report[1]=p1; in->open_bus=open_bus;
    js_input_v10_2_latch(in);
}

void js_input_v10_2_set_report(js_input_v10_2 *in, unsigned port, uint16_t report) {
    if (!in || port >= 2u) return;
    in->physical_report[port]=(uint16_t)(report & 0x0FFFu);
    if (in->effective_strobe) js_input_v10_2_latch(in);
}

uint16_t js_input_v10_2_get_auto_data(const js_input_v10_2 *in, unsigned index) {
    return in && index < 4u ? in->auto_data[index] : 0u;
}

js_stop_reason js_input_v10_2_read8(void *opaque, uint16_t reg, uint8_t *value) {
    js_input_v10_2 *in=(js_input_v10_2 *)opaque;
    uint8_t ob;
    if (!in || !value) return JS_STOP_BUS_FAULT;
    ob=js_input_v10_2_bus(in);
    if (reg == 0x4016u) {
        *value=(uint8_t)((ob & 0xFCu) | js_input_v10_2_serial(in,0u));
        return JS_STOP_NONE;
    }
    if (reg == 0x4017u) {
        *value=(uint8_t)((ob & 0xE0u) | 0x1Cu | js_input_v10_2_serial(in,1u));
        return JS_STOP_NONE;
    }
    if (reg >= 0x4218u && reg <= 0x421Fu) {
        unsigned idx=(unsigned)((reg-0x4218u)>>1u);
        uint16_t data=in->auto_data[idx];
        *value=(uint8_t)(((reg & 1u) != 0u) ? (data>>8u) : data);
        return JS_STOP_NONE;
    }
    return JS_STOP_INPUT_UNAVAILABLE;
}

js_stop_reason js_input_v10_2_write8(void *opaque, uint16_t reg, uint8_t value) {
    js_input_v10_2 *in=(js_input_v10_2 *)opaque;
    if (!in) return JS_STOP_BUS_FAULT;
    if (reg != 0x4016u) return JS_STOP_INPUT_UNAVAILABLE;
    in->cpu_strobe=(uint8_t)(value & 1u);
    js_input_v10_2_set_effective(in);
    return JS_STOP_NONE;
}

void js_input_v10_2_autojoy_control(void *opaque, uint8_t enabled) {
    js_input_v10_2 *in=(js_input_v10_2 *)opaque;
    if (!in) return;
    in->auto_strobe=(uint8_t)(enabled ? 1u : 0u);
    js_input_v10_2_set_effective(in);
}

void js_input_v10_2_autojoy_step(void *opaque, unsigned step, uint8_t enabled) {
    js_input_v10_2 *in=(js_input_v10_2 *)opaque;
    if (!in) return;
    if (step == 0u) {
        js_input_v10_2_autojoy_control(in, enabled);
        return;
    }
    if (step == 1u) {
        if (enabled) memset(in->auto_data,0,sizeof(in->auto_data));
        return;
    }
    if (step == 2u) {
        js_input_v10_2_autojoy_control(in,0u);
        return;
    }
    if (step >= 3u && step <= 34u && enabled) {
        if (step & 1u) {
            in->sampled_serial[0]=js_input_v10_2_serial(in,0u);
            in->sampled_serial[1]=js_input_v10_2_serial(in,1u);
            in->sampled_serial[2]=0u;
            in->sampled_serial[3]=0u;
            in->autojoy_samples++;
        } else {
            for (unsigned i=0;i<4u;i++)
                in->auto_data[i]=(uint16_t)((in->auto_data[i]<<1u)|(in->sampled_serial[i]&1u));
        }
    }
}
