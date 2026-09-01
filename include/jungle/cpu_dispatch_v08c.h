#ifndef JUNGLE_CPU_DISPATCH_V08C_H
#define JUNGLE_CPU_DISPATCH_V08C_H
#include <stddef.h>
#include <stdint.h>
#include "jungle/status.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    JS_FLAG_C = 0x01,
    JS_FLAG_Z = 0x02,
    JS_FLAG_I = 0x04,
    JS_FLAG_D = 0x08,
    JS_FLAG_X = 0x10,
    JS_FLAG_M = 0x20,
    JS_FLAG_V = 0x40,
    JS_FLAG_N = 0x80
};

typedef struct js_static_context_key {
    uint8_t pbr;
    uint16_t pc;
    uint8_t e;
    uint8_t m;
    uint8_t x;
} js_static_context_key;

typedef struct js_cpu65816_state {
    uint16_t a;
    uint16_t x;
    uint16_t y;
    uint16_t sp;
    uint16_t d;
    uint8_t dbr;
    uint8_t pbr;
    uint16_t pc;
    uint8_t p;
    uint8_t e;
    uint8_t waiting;
    uint8_t stopped;
    uint64_t retired_instructions;
} js_cpu65816_state;

typedef js_stop_reason (*js_bus_read8_fn)(void *opaque, uint32_t address, uint8_t *value);
typedef js_stop_reason (*js_bus_write8_fn)(void *opaque, uint32_t address, uint8_t value);
typedef js_stop_reason (*js_bus_idle_cycles_fn)(void *opaque, unsigned cycles);

typedef struct js_v05c_bus {
    void *opaque;
    js_bus_read8_fn read8;
    js_bus_write8_fn write8;
    js_bus_idle_cycles_fn idle_cycles;
} js_v05c_bus;

#define JS_V05C_DIAGNOSTIC_TRACE_CAPACITY 32u
#define JS_V05C_DIAGNOSTIC_EXPECTED_CAPACITY 8u

typedef struct js_machine_v05c {
    js_cpu65816_state cpu;
    js_v05c_bus bus;
    const uint8_t *canonical_rom;
    size_t canonical_rom_size;
    uint8_t rom_identity_ok;
    js_static_context_key diagnostic_current_key;
    js_static_context_key diagnostic_failure_source;
    js_static_context_key diagnostic_failure_target;
    js_static_context_key diagnostic_expected[JS_V05C_DIAGNOSTIC_EXPECTED_CAPACITY];
    js_static_context_key diagnostic_trace[JS_V05C_DIAGNOSTIC_TRACE_CAPACITY];
    uint32_t diagnostic_trace_next;
    uint32_t diagnostic_trace_count;
    uint32_t diagnostic_expected_count;
    uint32_t diagnostic_expected_stored;
    uint32_t diagnostic_stop_code;
    uint8_t diagnostic_failure_valid;
} js_machine_v05c;

#define JS_V05C_KEY_CONST(PBR,PC,E,M,X) \
    ((((uint64_t)(PBR) & 0xFFu) << 24) | (((uint64_t)(PC) & 0xFFFFu) << 8) | \
     (((uint64_t)(E) & 1u) << 2) | (((uint64_t)(M) & 1u) << 1) | ((uint64_t)(X) & 1u))

uint64_t js_v05c_pack_key(js_static_context_key key);
js_static_context_key js_v05c_key_from_cpu(const js_cpu65816_state *cpu);
int js_v05c_key_equal(js_static_context_key a, js_static_context_key b);
int js_v05c_context_known(js_static_context_key key);
js_stop_reason js_static_dispatch_v05c(js_machine_v05c *machine, js_static_context_key key);
js_stop_reason js_static_step_v05c(js_machine_v05c *machine);

#ifdef __cplusplus
}
#endif
#endif
