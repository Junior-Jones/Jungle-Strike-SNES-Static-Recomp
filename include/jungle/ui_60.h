#ifndef JUNGLE_UI_60_H
#define JUNGLE_UI_60_H
#include "jungle/machine_v10_40.h"
#include "jungle/mission_batch_60.h"
#define JUNGLE_UI60_WIRE_BYTES (40u+JUNGLE_MISSION60_WIRE_BYTES+24u)
typedef struct JungleUi60State {
    uint64_t input_epoch;
    uint64_t last_dispatch_epoch;
    uint64_t map_animation_epoch;
    uint16_t previous_scene;
    uint8_t dispatch_armed;
    uint8_t map_clock_armed;
    uint8_t map_half_phase;
    uint8_t map_tick_advanced;
    uint32_t password_error_field;
    uint8_t password_error_armed;
    uint64_t gameover_tick_field;
    uint64_t gameover_reload_field;
    uint8_t gameover_clock_armed;
    JungleMission60State mission;
} JungleUi60State;
int jungle_ui60_graphics_context(const JungleUi60State *state,const js_machine_v10_40 *machine);
void jungle_ui60_after_instruction(JungleUi60State *state,
    js_machine_v10_40 *machine,uint8_t previous_bank,uint16_t previous_pc);
void jungle_ui60_encode(const JungleUi60State *state,uint8_t *wire);
int jungle_ui60_decode(JungleUi60State *state,const uint8_t *wire);
#endif
