#include <stdio.h>

#include "jungle/jungle_static_core.h"
#include "jungle_input_latch.h"
#include "jungle_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const uint16_t frontend[] = {
        JUNGLE_INPUT_B, JUNGLE_INPUT_Y, JUNGLE_INPUT_SELECT,
        JUNGLE_INPUT_START, JUNGLE_INPUT_UP, JUNGLE_INPUT_DOWN,
        JUNGLE_INPUT_LEFT, JUNGLE_INPUT_RIGHT, JUNGLE_INPUT_A,
        JUNGLE_INPUT_X, JUNGLE_INPUT_L, JUNGLE_INPUT_R
    };
    static const uint16_t core[] = {
        JUNGLE_BUTTON_B, JUNGLE_BUTTON_Y, JUNGLE_BUTTON_SELECT,
        JUNGLE_BUTTON_START, JUNGLE_BUTTON_UP, JUNGLE_BUTTON_DOWN,
        JUNGLE_BUTTON_LEFT, JUNGLE_BUTTON_RIGHT, JUNGLE_BUTTON_A,
        JUNGLE_BUTTON_X, JUNGLE_BUTTON_L, JUNGLE_BUTTON_R
    };
    JungleStrikeInputLatch latch = { 0u, 0u };
    size_t index;

    for (index = 0u; index < sizeof(frontend) / sizeof(frontend[0]); ++index) {
        CHECK(frontend[index] == core[index]);
        jungle_input_latch_reset(&latch);
        jungle_input_latch_press(&latch, frontend[index], 0u, 0);
        CHECK(jungle_input_latch_sample(&latch) == frontend[index]);
        jungle_input_latch_release(&latch, frontend[index]);
        CHECK(jungle_input_latch_sample(&latch) == frontend[index]);
        jungle_input_latch_consume(&latch, frontend[index]);
        CHECK(jungle_input_latch_sample(&latch) == 0u);
    }

    jungle_input_latch_press(&latch, JUNGLE_INPUT_LEFT,
                             JUNGLE_INPUT_RIGHT, 0);
    jungle_input_latch_press(&latch, JUNGLE_INPUT_RIGHT,
                             JUNGLE_INPUT_LEFT, 0);
    CHECK((latch.held & (JUNGLE_INPUT_LEFT | JUNGLE_INPUT_RIGHT)) ==
          (JUNGLE_INPUT_LEFT | JUNGLE_INPUT_RIGHT));
    CHECK(latch.pending_press == JUNGLE_INPUT_RIGHT);
    jungle_input_latch_reset(&latch);
    CHECK(jungle_input_latch_sample(&latch) == 0u);

    puts("PASS all frontend/core button constants and keyboard press/release latch routes");
    return 0;
}
