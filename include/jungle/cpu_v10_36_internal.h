#ifndef JUNGLE_CPU_V10_36_INTERNAL_H
#define JUNGLE_CPU_V10_36_INTERNAL_H
#include "jungle/cpu_v08c_internal.h"
#ifdef __cplusplus
extern "C" {
#endif
void js_v10_36_txy(js_cpu65816_state *cpu, unsigned width);
void js_v10_36_tyx(js_cpu65816_state *cpu, unsigned width);
#ifdef __cplusplus
}
#endif
#endif
