#ifndef JUNGLE_BUS_V09C_H
#define JUNGLE_BUS_V09C_H

#include <stddef.h>
#include <stdint.h>
#include "jungle/bus.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Version 09C preserves the certified Version 06C mapping/base-machine state
   verbatim and places it on the Version 09C PPU-aware scheduler timeline. */
struct js_scheduler_v09c;
typedef js_bus_region_v06c js_bus_region_v09c;
typedef js_bus_mapping_v06c js_bus_mapping_v09c;
typedef js_component_port_v06c js_component_port_v09c;
typedef js_bus_ports_v06c js_bus_ports_v09c;
typedef js_math_unit_v06c js_math_unit_v09c;

typedef struct js_bus_v09c {
    js_bus_v06c base;
    struct js_scheduler_v09c *scheduler;
    uint64_t dma_read_count;
    uint64_t dma_write_count;
    uint64_t cpu_bus_cycles;
    uint64_t cpu_idle_cycles;
    uint8_t cpu_speed_clocks;
} js_bus_v09c;

js_stop_reason js_bus_v09c_init(js_bus_v09c *bus, const uint8_t *rom, size_t rom_size,
                                js_bus_ports_v09c ports, struct js_scheduler_v09c *scheduler);
void js_bus_v09c_snapshot_rebind(js_bus_v09c *bus, const uint8_t *rom,
                                 size_t rom_size, js_bus_ports_v09c ports,
                                 struct js_scheduler_v09c *scheduler);
void js_bus_v09c_reset(js_bus_v09c *bus);
js_bus_mapping_v09c js_bus_v09c_map(const js_bus_v09c *bus, uint32_t address);
unsigned js_bus_v09c_access_clocks(const js_bus_v09c *bus, uint32_t address);
js_stop_reason js_bus_v09c_peek8(const js_bus_v09c *bus, uint32_t address, uint8_t *value);
js_stop_reason js_bus_v09c_sample_reset_vector(const js_bus_v09c *bus, uint16_t *vector);
js_stop_reason js_bus_v09c_read8(js_bus_v09c *bus, uint32_t address, uint8_t *value);
js_stop_reason js_bus_v09c_write8(js_bus_v09c *bus, uint32_t address, uint8_t value);
js_stop_reason js_bus_v09c_idle_cycles(js_bus_v09c *bus, unsigned cycles);
js_stop_reason js_bus_v09c_dma_read8(js_bus_v09c *bus, uint32_t address, uint8_t for_bus_a, uint8_t *value);
js_stop_reason js_bus_v09c_dma_write8(js_bus_v09c *bus, uint32_t address, uint8_t for_bus_a, uint8_t value);
int js_bus_v09c_is_wram_address(const js_bus_v09c *bus, uint32_t address);

#ifdef __cplusplus
}
#endif
#endif
