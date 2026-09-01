#ifndef JUNGLE_INPUT_LATCH_H
#define JUNGLE_INPUT_LATCH_H

#include <stdint.h>

typedef struct JungleStrikeInputLatch {
    uint16_t held;
    uint16_t pending_press;
} JungleStrikeInputLatch;

void jungle_input_latch_reset(JungleStrikeInputLatch *latch);
void jungle_input_latch_press(JungleStrikeInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated);
void jungle_input_latch_release(JungleStrikeInputLatch *latch, uint16_t mask);
uint16_t jungle_input_latch_sample(const JungleStrikeInputLatch *latch);
void jungle_input_latch_consume(JungleStrikeInputLatch *latch, uint16_t sampled_mask);

#endif
