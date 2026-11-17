#ifndef JUNGLE_GAMEPLAY_60_H
#define JUNGLE_GAMEPLAY_60_H
#include "jungle/machine_v10_40.h"
/* Called after a successful native instruction, never during interrupt entry. */
int jungle_gameplay60_geometry_context(const js_machine_v10_40 *machine);
void jungle_gameplay60_after_instruction(js_machine_v10_40 *machine,
                                        uint8_t previous_bank,uint16_t previous_pc);
#endif
