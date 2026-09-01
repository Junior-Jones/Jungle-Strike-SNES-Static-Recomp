#ifndef JUNGLE_BUS_H
#define JUNGLE_BUS_H

#include <stddef.h>
#include <stdint.h>
#include "jungle/status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JS_V06C_WRAM_SIZE 0x20000u
#define JS_V06C_ROM_SIZE  0x200000u
#define JS_V06C_ADDRESS_SPACE_SIZE 0x1000000u

typedef enum js_bus_region_v06c {
    JS_BUS_REGION_UNMAPPED = 0,
    JS_BUS_REGION_WRAM,
    JS_BUS_REGION_ROM,
    JS_BUS_REGION_SRAM,
    JS_BUS_REGION_PPU,
    JS_BUS_REGION_APU,
    JS_BUS_REGION_WRAM_PORT,
    JS_BUS_REGION_INPUT,
    JS_BUS_REGION_CPU_IO,
    JS_BUS_REGION_DMA,
    JS_BUS_REGION_COUNT
} js_bus_region_v06c;

typedef js_stop_reason (*js_component_read8_fn)(void *opaque, uint16_t reg, uint8_t *value);
typedef js_stop_reason (*js_component_write8_fn)(void *opaque, uint16_t reg, uint8_t value);

typedef struct js_component_port_v06c {
    void *opaque;
    js_component_read8_fn read8;
    js_component_write8_fn write8;
} js_component_port_v06c;

typedef struct js_bus_ports_v06c {
    js_component_port_v06c ppu;
    js_component_port_v06c apu;
    js_component_port_v06c dma;
    js_component_port_v06c input;
    js_component_port_v06c timing;
} js_bus_ports_v06c;

typedef struct js_math_unit_v06c {
    uint8_t multiplicand;
    uint8_t multiplier;
    uint16_t dividend;
    uint8_t divisor;
    uint16_t quotient;
    uint16_t remainder_or_product;
    uint32_t shift;
    uint8_t multiply_cycles_remaining;
    uint8_t divide_cycles_remaining;
} js_math_unit_v06c;

typedef struct js_bus_mapping_v06c {
    js_bus_region_v06c region;
    uint32_t physical_offset;
    uint8_t mapped;
    uint8_t writable;
} js_bus_mapping_v06c;

typedef struct js_bus_v06c {
    const uint8_t *rom;
    size_t rom_size;
    uint8_t wram[JS_V06C_WRAM_SIZE];

    /* External S-CPU data-bus latch. Internal A-bus registers do not replace it. */
    uint8_t open_bus;

    /* Base CPU-I/O latches. Their event effects belong to V07/V08/V11. */
    uint8_t nmitimen;
    uint8_t wrio;
    uint16_t htime;
    uint16_t vtime;
    uint8_t memsel;
    uint32_t wram_port_address;

    /* Sum of classified access costs only. This is deliberately not a scheduler
       master clock; V07 will place these costs on the global event timeline. */
    uint64_t access_clock_sum;
    uint64_t read_count;
    uint64_t write_count;
    uint64_t region_read_count[JS_BUS_REGION_COUNT];
    uint64_t region_write_count[JS_BUS_REGION_COUNT];
    uint64_t math_cpu_cycles_advanced;

    js_math_unit_v06c math;
    js_bus_ports_v06c ports;
} js_bus_v06c;

const char *js_bus_v06c_region_name(js_bus_region_v06c region);
js_stop_reason js_bus_v06c_init(js_bus_v06c *bus, const uint8_t *rom, size_t rom_size, js_bus_ports_v06c ports);
void js_bus_v06c_reset(js_bus_v06c *bus);
js_bus_mapping_v06c js_bus_v06c_map(const js_bus_v06c *bus, uint32_t address);
unsigned js_bus_v06c_access_clocks(const js_bus_v06c *bus, uint32_t address);

/* Side-effect-free and untimed. Component-owned ranges fail with their exact
   future-milestone reason rather than silently invoking runtime fallback logic. */
js_stop_reason js_bus_v06c_peek8(const js_bus_v06c *bus, uint32_t address, uint8_t *value);
js_stop_reason js_bus_v06c_sample_reset_vector(const js_bus_v06c *bus, uint16_t *vector);

js_stop_reason js_bus_v06c_read8(js_bus_v06c *bus, uint32_t address, uint8_t *value);
js_stop_reason js_bus_v06c_write8(js_bus_v06c *bus, uint32_t address, uint8_t value);

/* V06C owns the ALU's cycle-by-cycle state transition but not global placement
   of CPU cycles. Focused tests and V07 call this explicit seam. */
void js_bus_v06c_advance_cpu_cycles(js_bus_v06c *bus, unsigned cycles);

#ifdef __cplusplus
}
#endif
#endif
