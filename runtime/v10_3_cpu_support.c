#include "jungle/cpu_v10_3_internal.h"

static uint16_t js_v10_3_direct_addr(const js_cpu65816_state *s, uint16_t offset, int allow_wrap) {
    if (allow_wrap && s->e && ((s->d & 0x00FFu) == 0u))
        return (uint16_t)((s->d & 0xFF00u) | (offset & 0x00FFu));
    return (uint16_t)(s->d + offset);
}

js_stop_reason js_v10_3_addr_dir_ind(js_machine_v05c *m, uint8_t offset, uint32_t *effective) {
    uint16_t lo_addr, hi_addr;
    uint8_t lo=0u, hi=0u;
    js_stop_reason r;
    if (!m || !effective) return JS_STOP_BUS_FAULT;
    lo_addr=js_v10_3_direct_addr(&m->cpu,(uint16_t)offset,1);
    hi_addr=js_v10_3_direct_addr(&m->cpu,(uint16_t)offset+1u,1);
    r=js_v05c_read8(m,lo_addr,&lo); if (r!=JS_STOP_NONE) return r;
    r=js_v05c_read8(m,hi_addr,&hi); if (r!=JS_STOP_NONE) return r;
    *effective=((uint32_t)m->cpu.dbr<<16)|(uint16_t)(lo|((uint16_t)hi<<8));
    return JS_STOP_NONE;
}
