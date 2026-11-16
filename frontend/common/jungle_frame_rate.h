#ifndef JUNGLE_FRAME_RATE_H
#define JUNGLE_FRAME_RATE_H
#include <stdint.h>
#include <stddef.h>
#define JUNGLE_NATIVE_FPS_NUMERATOR 39375000u
#define JUNGLE_NATIVE_FPS_DENOMINATOR 655171u
typedef struct JungleFrameClock {
    uint64_t deadline, base_ticks;
    uint32_t numerator, remainder_ticks, accumulator;
} JungleFrameClock;
static inline int jungle_frame_clock_init(JungleFrameClock *clock,
    uint64_t frequency, uint64_t now, int exact60) {
    uint32_t numerator=exact60?60u:JUNGLE_NATIVE_FPS_NUMERATOR;
    uint32_t denominator=exact60?1u:JUNGLE_NATIVE_FPS_DENOMINATOR;
    uint64_t scaled;
    if(!clock || !frequency || frequency>UINT64_MAX/denominator)return 0;
    scaled=frequency*denominator;
    clock->deadline=now;
    clock->base_ticks=scaled/numerator;
    clock->numerator=numerator;
    clock->remainder_ticks=(uint32_t)(scaled%numerator);
    clock->accumulator=0;
    return 1;
}
static inline void jungle_frame_clock_advance(JungleFrameClock *clock) {
    clock->deadline+=clock->base_ticks;
    clock->accumulator+=clock->remainder_ticks;
    if(clock->accumulator>=clock->numerator) {
        clock->deadline++;
        clock->accumulator-=clock->numerator;
    }
}
/* The guest still produces native-clock PCM. One guest field per exact60
   wall-clock tick produces this many source samples per real second. */
static inline double jungle_frame_rate_audio_source(double native_rate,
    int frame_locked, int exact60) {
    return frame_locked && exact60 ?
        native_rate*(60.0*JUNGLE_NATIVE_FPS_DENOMINATOR/JUNGLE_NATIVE_FPS_NUMERATOR) : native_rate;
}
#endif
