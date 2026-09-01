#ifndef JUNGLE_MACHINE_V10_40_H
#define JUNGLE_MACHINE_V10_40_H
#include "jungle/machine_v09c.h"
#include "jungle/apu_v10_33.h"
#include "jungle/input_v10_2.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct js_machine_v10_40 {
  js_scheduler_v09c scheduler; js_bus_v09c bus; js_dma_v09c dma; js_ppu_v09c ppu; js_apu_v10_33 apu; js_input_v10_2 input; js_machine_v05c cpu_core;
  uint64_t nmi_entries,irq_entries,wai_wall_clocks,wram_vector_dispatches,wram_nmi_dispatches,wram_irq_dispatches;
} js_machine_v10_40;
js_stop_reason js_machine_v10_40_init(js_machine_v10_40*,const uint8_t*,size_t,js_bus_ports_v09c,js_scheduler_hooks_v09c);
void js_machine_v10_40_destroy(js_machine_v10_40*);
js_stop_reason js_machine_v10_40_reset(js_machine_v10_40*);
js_stop_reason js_machine_v10_40_step(js_machine_v10_40*);
js_stop_reason js_machine_v10_40_step_wram_vector(js_machine_v10_40*);
/* Remove host pointers from a raw same-build machine snapshot, then restore
   those connections after loading it into its owning core. */
void js_machine_v10_40_snapshot_sanitize(js_machine_v10_40 *machine);
void js_machine_v10_40_snapshot_rebind(
    js_machine_v10_40 *machine, const uint8_t *rom, size_t rom_size,
    void *ppu_opaque, js_scheduler_ppu_event_fn ppu_event);
#ifdef __cplusplus
}
#endif
#endif
