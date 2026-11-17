#ifndef JUNGLE_MISSION_GRAPHICS_60_H
#define JUNGLE_MISSION_GRAPHICS_60_H
#include "jungle/machine_v10_40.h"
/* Optional audited graphics commands for Mission type1, Copilot selection and
   the four GameOver fire frames. Native call/epilogue/DMA ownership remains.
   No game-state/resource memoization. Unsupported contexts stay native. */
/* Pure producer identity, independent of current kernel PC/registers/stack. */
int jungle_mission60_gameover_context(const js_machine_v10_40 *machine);
js_stop_reason jungle_mission60_after_instruction(js_machine_v10_40 *machine);
#endif
