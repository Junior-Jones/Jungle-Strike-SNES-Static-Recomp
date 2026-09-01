#ifndef JUNGLE_MACHINE_V08C_H
#define JUNGLE_MACHINE_V08C_H

#include "jungle/bus_v08c.h"
#include "jungle/cpu_dispatch_v08c.h"
#include "jungle/dma_v08c.h"
#include "jungle/scheduler_v08c.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private initialization seam for the scheduler-aware exact-context CPU target. */
js_stop_reason js_machine_v05c_init(js_machine_v05c *machine, const uint8_t *canonical_rom,
                                    size_t canonical_rom_size, js_v05c_bus bus);

typedef struct js_machine_v08c {
    js_scheduler_v08c scheduler;
    js_bus_v08c bus;
    js_dma_v08c dma;
    js_machine_v05c cpu_core;
    uint64_t nmi_entries;
    uint64_t irq_entries;
    uint64_t wai_wall_clocks;
} js_machine_v08c;

js_stop_reason js_machine_v08c_init(js_machine_v08c *machine, const uint8_t *canonical_rom,
                                    size_t canonical_rom_size, js_bus_ports_v08c ports,
                                    js_scheduler_hooks_v08c hooks);
js_stop_reason js_machine_v08c_reset(js_machine_v08c *machine);
js_stop_reason js_machine_v08c_step(js_machine_v08c *machine);

#ifdef __cplusplus
}
#endif
#endif
