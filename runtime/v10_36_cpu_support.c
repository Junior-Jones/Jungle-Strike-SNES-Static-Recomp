#include "jungle/cpu_v10_36_internal.h"

void js_v10_36_txy(js_cpu65816_state *cpu, unsigned width) {
    js_v05c_write_y(cpu, cpu->x, width, 1);
}

void js_v10_36_tyx(js_cpu65816_state *cpu, unsigned width) {
    js_v05c_write_x(cpu, cpu->y, width, 1);
}
