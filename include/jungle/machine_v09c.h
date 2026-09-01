#ifndef JUNGLE_MACHINE_V09C_H
#define JUNGLE_MACHINE_V09C_H

#include "jungle/bus_v09c.h"
#include "jungle/cpu_dispatch_v08c.h"
#include "jungle/dma_v09c.h"
#include "jungle/ppu_v09c.h"
#include "jungle/scheduler_v09c.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private initialization seam for the scheduler-aware exact-context CPU target. */
js_stop_reason js_machine_v05c_init(js_machine_v05c *machine, const uint8_t *canonical_rom,
                                    size_t canonical_rom_size, js_v05c_bus bus);

typedef struct js_machine_v09c {
    js_scheduler_v09c scheduler;
    js_bus_v09c bus;
    js_dma_v09c dma;
    js_ppu_v09c ppu;
    js_machine_v05c cpu_core;
    uint64_t nmi_entries;
    uint64_t irq_entries;
    uint64_t wai_wall_clocks;
} js_machine_v09c;

/* The PPU port is machine-owned and is replaced by the V09C PPU.  Callers may
   still supply APU and input component ports for later milestones/testing. */
js_stop_reason js_machine_v09c_init(js_machine_v09c *machine, const uint8_t *canonical_rom,
                                    size_t canonical_rom_size, js_bus_ports_v09c ports,
                                    js_scheduler_hooks_v09c hooks);
js_stop_reason js_machine_v09c_reset(js_machine_v09c *machine);
js_stop_reason js_machine_v09c_step(js_machine_v09c *machine);

#ifdef __cplusplus
}
#endif
#endif
