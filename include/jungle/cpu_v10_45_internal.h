#ifndef JUNGLE_CPU_V10_45_INTERNAL_H
#define JUNGLE_CPU_V10_45_INTERNAL_H
#include <stdint.h>
#include "jungle/cpu_dispatch_v08c.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Execute one architecturally atomic MVN/MVP byte iteration after the three
   instruction-stream bytes have already been fetched/guarded.  This helper is
   opcode-free: source/destination banks, direction and exact X-width are fixed
   by generated code for the selected static context.  It performs one data
   read, one data write and the two internal cycles in hardware order, updates
   DBR/X/Y/A, and reports whether the block move is complete (A == $FFFF).
   Instruction-boundary PC/successor handling remains in generated code. */
js_stop_reason js_v10_45_block_move_iteration(js_machine_v05c *m,
                                               uint8_t source_bank,
                                               uint8_t destination_bank,
                                               int increment,
                                               int index_is_8bit,
                                               int *complete);

#ifdef __cplusplus
}
#endif
#endif
