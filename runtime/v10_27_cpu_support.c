#include "jungle/cpu_v10_27_internal.h"

uint16_t js_v10_27_tsb(js_cpu65816_state *s, uint16_t a, uint16_t mem, unsigned width) {
    uint16_t mask = width == 8u ? 0x00FFu : 0xFFFFu;
    uint16_t overlap = (uint16_t)((a & mem) & mask);
    if (overlap == 0u) s->p |= JS_FLAG_Z;
    else s->p &= (uint8_t)~JS_FLAG_Z;
    return (uint16_t)((mem | a) & mask);
}
