#ifndef JUNGLE_GAMEPLAY_LIGHTS_60_H
#define JUNGLE_GAMEPLAY_LIGHTS_60_H
#include "jungle/machine_v10_40.h"
/* Stateless interpolation of the native four-color gameplay light palette.
   Called only when experimental60 is enabled; native DMA/phase remain intact. */
js_stop_reason jungle_gameplay_lights60_after_instruction(js_machine_v10_40 *machine,
                                                        uint8_t previous_bank,
                                                        uint16_t previous_pc);
#endif
