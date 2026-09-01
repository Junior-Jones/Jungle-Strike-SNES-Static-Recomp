#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_v10_45_internal.h"

js_stop_reason js_v10_45_block_move_iteration(js_machine_v05c *m,
                                               uint8_t source_bank,
                                               uint8_t destination_bank,
                                               int increment,
                                               int index_is_8bit,
                                               int *complete) {
    uint32_t source_address;
    uint32_t destination_address;
    uint8_t value = 0u;
    uint16_t delta;
    uint16_t mask;
    js_stop_reason stop;
    if (!m || !complete) return JS_STOP_BUS_FAULT;

    /* DBR changes before the data transfer and remains the destination bank. */
    m->cpu.dbr = destination_bank;
    source_address = ((uint32_t)source_bank << 16u) | (uint32_t)m->cpu.x;
    destination_address = ((uint32_t)destination_bank << 16u) | (uint32_t)m->cpu.y;

    stop = js_v05c_read8(m, source_address, &value);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_v05c_write8(m, destination_address, value);
    if (stop != JS_STOP_NONE) return stop;

    /* MVN/MVP are seven cycles per byte: three guarded fetch cycles + one
       source read + one destination write + two internal cycles. */
    stop = js_v05c_idle_cycles(m, 2u);
    if (stop != JS_STOP_NONE) return stop;

    delta = increment ? 1u : 0xFFFFu;
    mask = index_is_8bit ? 0x00FFu : 0xFFFFu;
    m->cpu.x = (uint16_t)((m->cpu.x + delta) & mask);
    m->cpu.y = (uint16_t)((m->cpu.y + delta) & mask);
    m->cpu.a = (uint16_t)(m->cpu.a - 1u);
    *complete = (m->cpu.a == 0xFFFFu);
    return JS_STOP_NONE;
}
