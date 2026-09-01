/* generated compact exact-context semantic templates - do not edit */
/* Exact key records select these templates; no ROM opcode is decoded. */
#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_v10_3_internal.h"
#include "jungle/cpu_v10_27_internal.h"
#include "jungle/cpu_v10_36_internal.h"
#include "jungle/cpu_v10_45_internal.h"
#include "jungle/cpu_dispatch_v10_100.h"
#include "jungle/status_v10_11.h"
#include "static_core_compact_generated.h"

static js_stop_reason js_compact_template_000(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x85u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        r = js_v05c_write_value(m, ea, p[2], 1, (uint16_t)(m->cpu.a & p[3]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],p[7]));
}

static js_stop_reason js_compact_template_001(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Du, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, (uint16_t)(m->cpu.a & p[5]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_002(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, p[3], 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,p[6]));
}

static js_stop_reason js_compact_template_003(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA5u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_004(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xF0u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[6],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_005(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xADu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],p[8]));
}

static js_stop_reason js_compact_template_006(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],0u));
}

static js_stop_reason js_compact_template_007(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBDu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],0u));
}

static js_stop_reason js_compact_template_008(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x20u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, p[3]);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_009(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xD0u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[6],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_00A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x29u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & p[3]) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,p[6]));
}

static js_stop_reason js_compact_template_00B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x18u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.p &= (uint8_t)~JS_FLAG_C;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],p[3],p[4],p[5]));
}

static js_stop_reason js_compact_template_00C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x0Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2]);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_00D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_ror(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2]);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_00E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x46u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_lsr(&m->cpu, value, p[2]);
        r = js_v05c_write_rmw_value(m, ea, p[2], 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_00F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x99u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, (uint16_t)(m->cpu.a & p[5]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_010(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x64u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        r = js_v05c_write_value(m, ea, p[2], 1, 0u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_011(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x4Cu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_012(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Cu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, 0u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],p[8]));
}

static js_stop_reason js_compact_template_013(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), p[3], 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,p[6]));
}

static js_stop_reason js_compact_template_014(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xABu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint8_t pulled = 0u;
        r = js_v05c_pull8(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        m->cpu.dbr = pulled;
        js_v05c_set_nz(&m->cpu, pulled, 8u);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],p[4]));
}

static js_stop_reason js_compact_template_015(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Fu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = p[4];
        r = js_v05c_write_value(m, ea, p[5], 0, (uint16_t)(m->cpu.a & p[6]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[7],p[8],0u,p[9],p[10]));
}

static js_stop_reason js_compact_template_016(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x09u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | p[3]) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_017(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x89u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), p[3], 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_018(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x36u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct_x(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 8u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_rol(&m->cpu, value, 8u);
        r = js_v05c_write_rmw_value(m, ea, 8u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,1u,0u));
}

static js_stop_reason js_compact_template_019(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Du, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, (uint16_t)(m->cpu.a & p[5]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_01A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x38u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.p |= JS_FLAG_C;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],p[4]));
}

static js_stop_reason js_compact_template_01B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x90u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_C) == 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[6],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_01C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC8u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_01D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA2u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, p[3], 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_01E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x69u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), p[3], 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,p[6]));
}

static js_stop_reason js_compact_template_01F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xAAu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, m->cpu.a, p[1], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_020(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x4Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2]);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_021(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x80u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],p[4],p[5],p[6]));
}

static js_stop_reason js_compact_template_022(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,p[3],0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_023(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xACu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, value, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],p[8]));
}

static js_stop_reason js_compact_template_024(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA6u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],0u));
}

static js_stop_reason js_compact_template_025(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Eu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, (uint16_t)(m->cpu.x & p[5]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_026(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC2u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint8_t old_p = m->cpu.p;
        m->cpu.p &= (uint8_t)~ p[0];
        js_v05c_normalize(&m->cpu, old_p);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_027(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA0u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, p[3], 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_028(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB0u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_C) != 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,p[4]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[5],0u,0u,p[4]));
}

static js_stop_reason js_compact_template_029(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBFu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (p[4] + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[5], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[5], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_02A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x65u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & p[3]), value, p[2]);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],p[7]));
}

static js_stop_reason js_compact_template_02B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xAEu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, value, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],p[8]));
}

static js_stop_reason js_compact_template_02C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xAFu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = p[4];
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[5], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[5], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_02D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA8u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, m->cpu.a, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_02E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE2u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint8_t old_p = m->cpu.p;
        m->cpu.p |= p[0];
        js_v05c_normalize(&m->cpu, old_p);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_02F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x48u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.a & 0xFFFFu)));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,p[3]));
}

static js_stop_reason js_compact_template_030(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA9u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, p[2], 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,1u,p[5]));
}

static js_stop_reason js_compact_template_031(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x22u, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push8(m, m->cpu.pbr);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, p[4]);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_032(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x04u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v10_27_tsb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_033(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE8u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_034(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB7u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_long_y(m, p[0], &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_035(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x30u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_N) != 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[6],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_036(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x1Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2], 1);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_037(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), p[3], 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_038(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x10u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_N) == 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],p[5]));
        }
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[6],0u,p[4],p[5]));
}

static js_stop_reason js_compact_template_039(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x68u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t pulled = 0u;
        r = js_v05c_pull16(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, pulled, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,p[3]));
}

static js_stop_reason js_compact_template_03A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Cu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        r = js_v05c_write_value(m, ea, p[4], 0, (uint16_t)(m->cpu.y & p[5]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_03B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE5u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_03C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xFAu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t pulled = 0u;
        r = js_v05c_pull16(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, pulled, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_03D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Du, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[4],0u,0u,0u));
}

static js_stop_reason js_compact_template_03E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x79u, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,0u,0u));
}

static js_stop_reason js_compact_template_03F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE6u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, p[2], 1);
        r = js_v05c_write_rmw_value(m, ea, p[2], 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_040(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xCDu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & p[5]), value, p[4]);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_041(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_042(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x49u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) ^ p[3]) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_043(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xDAu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.x & 0xFFFFu)));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_044(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x86u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],0u));
}

static js_stop_reason js_compact_template_045(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Eu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        r = js_v05c_write_value(m, ea, 16u, 0, 0u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_046(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xD9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_047(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x98u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_048(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, m->cpu.x, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_049(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_04A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xF4u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, (uint16_t)(p[3]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_04B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA4u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, value, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_04C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x8Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push8(m, (uint8_t)(m->cpu.dbr));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],p[4]));
}

static js_stop_reason js_compact_template_04D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x3Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2], -1);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_04E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xEBu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.a = (uint16_t)((m->cpu.a << 8) | (m->cpu.a >> 8));
        js_v05c_set_nz(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), 8u);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],p[4]));
}

static js_stop_reason js_compact_template_04F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xEDu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & p[5]), value, p[4]);
        js_v05c_write_a(&m->cpu, result, p[4], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_050(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC5u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & p[3]), value, p[2]);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_051(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t pulled = 0u;
        r = js_v05c_pull16(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, pulled, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_052(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x2Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t pulled = 0u;
        r = js_v05c_pull16(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        m->cpu.d = pulled;
        js_v05c_set_nz(&m->cpu, pulled, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_053(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x5Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.y & 0xFFFFu)));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_054(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC6u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, p[2], -1);
        r = js_v05c_write_rmw_value(m, ea, p[2], 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],p[6]));
}

static js_stop_reason js_compact_template_055(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x2Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_rol(&m->cpu, (uint16_t)(m->cpu.a & p[1]), p[2]);
        js_v05c_write_a(&m->cpu, result, p[2], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_056(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Du, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & p[5]), value, p[4]);
        js_v05c_write_a(&m->cpu, result, p[4], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_057(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBCu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_058(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x29u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0x00FFu) & p[2]) & 0x00FFu);
        js_v05c_write_a(&m->cpu, result, 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,1u,p[5]));
}

static js_stop_reason js_compact_template_059(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x49u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0x00FFu) ^ p[2]) & 0x00FFu);
        js_v05c_write_a(&m->cpu, result, 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,1u,0u));
}

static js_stop_reason js_compact_template_05A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x14u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_05B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Fu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (p[4] + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        r = js_v05c_write_value(m, ea, p[5], 0, (uint16_t)(m->cpu.a & p[6]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[7],p[8],0u,p[9],0u));
}

static js_stop_reason js_compact_template_05C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x84u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.y & 0xFFFFu));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,p[4],0u));
}

static js_stop_reason js_compact_template_05D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x5Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.d = m->cpu.a;
        js_v05c_set_nz(&m->cpu, m->cpu.d, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_05E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x06u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_asl(&m->cpu, value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,p[4]));
}

static js_stop_reason js_compact_template_05F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE0u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), p[3], 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_060(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xCAu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, -1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_061(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0x86A1u,0u,0u,0u), JS_CTX(0x80u,0x86AFu,0u,0u,0u), JS_CTX(0x80u,0x86BDu,0u,0u,0u), JS_CTX(0x80u,0x86CBu,0u,0u,0u), JS_CTX(0x80u,0x86D6u,0u,0u,0u), JS_CTX(0x80u,0x86E1u,0u,0u,0u), JS_CTX(0x80u,0x86ECu,0u,0u,0u), JS_CTX(0x80u,0x86F7u,0u,0u,0u), JS_CTX(0x80u,0x8702u,0u,0u,0u), JS_CTX(0x80u,0x870Du,0u,0u,0u), JS_CTX(0x80u,0x8718u,0u,0u,0u), JS_CTX(0x80u,0x8723u,0u,0u,0u), JS_CTX(0x80u,0x872Eu,0u,0u,0u), JS_CTX(0x80u,0x8739u,0u,0u,0u), JS_CTX(0x80u,0x8744u,0u,0u,0u), JS_CTX(0x80u,0x874Fu,0u,0u,0u), JS_CTX(0x80u,0x8762u,0u,0u,0u), JS_CTX(0x80u,0x876Du,0u,0u,0u), JS_CTX(0x80u,0x8778u,0u,0u,0u), JS_CTX(0x80u,0x8783u,0u,0u,0u), JS_CTX(0x80u,0x8797u,0u,0u,0u), JS_CTX(0x80u,0x87A2u,0u,0u,0u), JS_CTX(0x80u,0x87ADu,0u,0u,0u), JS_CTX(0x80u,0x87C1u,0u,0u,0u), JS_CTX(0x80u,0x87CCu,0u,0u,0u), JS_CTX(0x80u,0x87D7u,0u,0u,0u), JS_CTX(0x80u,0x87E2u,0u,0u,0u), JS_CTX(0x80u,0x87F6u,0u,0u,0u), JS_CTX(0x80u,0x8801u,0u,0u,0u), JS_CTX(0x80u,0x880Cu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_062(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x0Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push16(m, (uint16_t)(m->cpu.d));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_063(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x05u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & p[3]) | value) & p[3]);
        js_v05c_write_a(&m->cpu, result, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_064(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x88u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, -1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_065(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xEEu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, p[4], 1);
        r = js_v05c_write_rmw_value(m, ea, p[4], 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],p[8]));
}

static js_stop_reason js_compact_template_066(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x54u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        int complete = 0;
        r = js_v10_45_block_move_iteration(m, p[1], p[0], 1, 0, &complete);
        if (r != JS_STOP_NONE) return r;
        if (complete) return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,0u,0u));
        const js_static_context_key repeat_key = JS_CTX(p[3],p[5],0u,0u,0u);
        if (!js_v05c_key_equal(js_v05c_key_from_cpu(&m->cpu), repeat_key)) return JS_STOP_UNPROVED_SUCCESSOR_CONTEXT;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_067(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBBu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v10_36_tyx(&m->cpu, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_068(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x66u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_ror(&m->cpu, value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_069(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xDFu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (p[4] + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[5], 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & p[6]), value, p[5]);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_06A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xEAu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],0u));
}

static js_stop_reason js_compact_template_06B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC9u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), p[2], 8u);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[3],0u,1u,0u));
}

static js_stop_reason js_compact_template_06C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x26u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_rol(&m->cpu, value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_06D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x0Du, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & p[5]) | value) & p[5]);
        js_v05c_write_a(&m->cpu, result, p[4], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[9]));
}

static js_stop_reason js_compact_template_06E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_06F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u), JS_CTX(p[1],p[5],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_070(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xCEu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, p[4], -1);
        r = js_v05c_write_rmw_value(m, ea, p[4], 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],0u));
}

static js_stop_reason js_compact_template_071(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xDDu, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_072(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(0x80u,p[3],0u,0u,0u), JS_CTX(0x80u,p[4],0u,0u,0u), JS_CTX(0x80u,p[5],0u,0u,0u), JS_CTX(0x80u,p[6],0u,0u,0u), JS_CTX(0x80u,p[7],0u,0u,0u), JS_CTX(0x80u,p[8],0u,0u,0u), JS_CTX(0x80u,p[9],0u,0u,0u), JS_CTX(0x80u,p[10],0u,0u,0u), JS_CTX(0x80u,p[11],0u,0u,0u), JS_CTX(0x80u,p[12],0u,0u,0u), JS_CTX(0x80u,p[13],0u,0u,0u), JS_CTX(0x80u,p[14],0u,0u,0u), JS_CTX(0x80u,p[15],0u,0u,0u), JS_CTX(0x80u,p[16],0u,0u,0u), JS_CTX(0x80u,p[17],0u,0u,0u), JS_CTX(0x80u,p[18],0u,0u,0u), JS_CTX(0x80u,p[19],0u,0u,0u), JS_CTX(0x80u,p[20],0u,0u,0u), JS_CTX(0x80u,p[21],0u,0u,0u), JS_CTX(0x80u,p[22],0u,0u,0u), JS_CTX(0x80u,p[23],0u,0u,0u), JS_CTX(0x80u,p[24],0u,0u,0u), JS_CTX(0x80u,p[25],0u,0u,0u), JS_CTX(0x80u,p[26],0u,0u,0u), JS_CTX(0x80u,p[27],0u,0u,0u), JS_CTX(0x80u,p[28],0u,0u,0u), JS_CTX(0x80u,p[29],0u,0u,0u), JS_CTX(0x80u,p[30],0u,0u,0u), JS_CTX(0x80u,p[31],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_073(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA2u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, p[2], 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,0u,1u));
}

static js_stop_reason js_compact_template_074(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA0u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, p[2], 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,0u,1u));
}

static js_stop_reason js_compact_template_075(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x40u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint8_t pulled_p = 0u, pcl = 0u, pch = 0u, bank = m->cpu.pbr;
        uint8_t old_p = m->cpu.p;
        r = js_v05c_pull8(m, &pulled_p); if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &pcl); if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &pch); if (r != JS_STOP_NONE) return r;
        if (!m->cpu.e) { r = js_v05c_pull8(m, &bank); if (r != JS_STOP_NONE) return r; }
        m->cpu.p = pulled_p;
        m->cpu.pc = (uint16_t)(pcl | ((uint16_t)pch << 8));
        if (!m->cpu.e) m->cpu.pbr = bank;
        js_v05c_normalize(&m->cpu, old_p);
    
        if (!js_v10_100_scpu_context_known(js_v05c_key_from_cpu(&m->cpu))) return JS_STOP_UNPROVED_INTERRUPT_REENTRY;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_076(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB1u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_y(m, p[0], &ea);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_077(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xFDu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[4],0u,0u,0u));
}

static js_stop_reason js_compact_template_078(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Fu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (p[4] + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,0u,0u));
}

static js_stop_reason js_compact_template_079(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(0x80u,p[3],0u,0u,0u), JS_CTX(0x80u,p[4],0u,0u,0u), JS_CTX(0x80u,p[5],0u,0u,0u), JS_CTX(0x80u,p[6],0u,0u,0u), JS_CTX(0x80u,p[7],0u,0u,0u), JS_CTX(0x80u,p[8],0u,0u,0u), JS_CTX(0x80u,p[9],0u,0u,0u), JS_CTX(0x80u,p[10],0u,0u,0u), JS_CTX(0x80u,p[11],0u,0u,0u), JS_CTX(0x80u,p[12],0u,0u,0u), JS_CTX(0x80u,p[13],0u,0u,0u), JS_CTX(0x80u,p[14],0u,0u,0u), JS_CTX(0x80u,p[15],0u,0u,0u), JS_CTX(0x80u,p[16],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_07A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x1Du, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[3], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & p[4]) | value) & p[4]);
        js_v05c_write_a(&m->cpu, result, p[3], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,p[7],0u));
}

static js_stop_reason js_compact_template_07B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0x86A1u,0u,0u,0u), JS_CTX(0x80u,0x86AFu,0u,0u,0u), JS_CTX(0x80u,0x86BDu,0u,0u,0u), JS_CTX(0x80u,0x86CBu,0u,0u,0u), JS_CTX(0x80u,0x86D6u,0u,0u,0u), JS_CTX(0x80u,0x86E1u,0u,0u,0u), JS_CTX(0x80u,0x86ECu,0u,0u,0u), JS_CTX(0x80u,0x86F7u,0u,0u,0u), JS_CTX(0x80u,0x8702u,0u,0u,0u), JS_CTX(0x80u,0x870Du,0u,0u,0u), JS_CTX(0x80u,0x8718u,0u,0u,0u), JS_CTX(0x80u,0x8723u,0u,0u,0u), JS_CTX(0x80u,0x872Eu,0u,0u,0u), JS_CTX(0x80u,0x8739u,0u,0u,0u), JS_CTX(0x80u,0x8744u,0u,0u,0u), JS_CTX(0x80u,0x874Fu,0u,0u,0u), JS_CTX(0x80u,0x8762u,0u,0u,0u), JS_CTX(0x80u,0x876Du,0u,0u,0u), JS_CTX(0x80u,0x8778u,0u,0u,0u), JS_CTX(0x80u,0x8783u,0u,0u,0u), JS_CTX(0x80u,0x8797u,0u,0u,0u), JS_CTX(0x80u,0x87A2u,0u,0u,0u), JS_CTX(0x80u,0x87ADu,0u,0u,0u), JS_CTX(0x80u,0x87C1u,0u,0u,0u), JS_CTX(0x80u,0x87CCu,0u,0u,0u), JS_CTX(0x80u,0x87D7u,0u,0u,0u), JS_CTX(0x80u,0x87E2u,0u,0u,0u), JS_CTX(0x80u,0x87F6u,0u,0u,0u), JS_CTX(0x80u,0x8801u,0u,0u,0u), JS_CTX(0x80u,0x880Cu,0u,0u,0u), JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(0x80u,p[3],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_07C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x68u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint8_t pulled = 0u;
        r = js_v05c_pull8(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, pulled, 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,1u,p[3]));
}

static js_stop_reason js_compact_template_07D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x2Cu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & p[5]), value, p[4], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],p[8]));
}

static js_stop_reason js_compact_template_07E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, p[3], &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(p[4],p[5],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_07F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xFFu, p[0], 0x00u, 0x81u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (p[2] + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_080(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x48u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push8(m, (uint8_t)((uint16_t)(m->cpu.a & 0x00FFu)));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,1u,p[3]));
}

static js_stop_reason js_compact_template_081(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x4Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push8(m, (uint8_t)(m->cpu.pbr));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,p[3],p[4]));
}

static js_stop_reason js_compact_template_082(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x25u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & p[3]) & value) & p[3]);
        js_v05c_write_a(&m->cpu, result, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_083(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x83u, 0x01u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (uint16_t)(m->cpu.sp + 0x01u);
        r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_084(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x09u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0x00FFu) | p[2]) & 0x00FFu);
        js_v05c_write_a(&m->cpu, result, 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,1u,p[5]));
}

static js_stop_reason js_compact_template_085(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x5Cu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[4],0u,0u,0u));
}

static js_stop_reason js_compact_template_086(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xCFu, p[0], p[1], p[2] };
        r = js_v05c_guard_code(m, p[3], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = p[4];
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[5],p[6],0u,0u,0u));
}

static js_stop_reason js_compact_template_087(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x63u, 0x01u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (uint16_t)(m->cpu.sp + 0x01u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_088(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x82u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE46Cu,0u,1u,0u));
}

static js_stop_reason js_compact_template_089(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xF9u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[4], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & p[5]), value, p[4]);
        js_v05c_write_a(&m->cpu, result, p[4], 0);
        return js_v05c_finish_fixed(m, JS_CTX(p[6],p[7],0u,p[8],0u));
}

static js_stop_reason js_compact_template_08A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(p[2],p[3],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_08B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x95u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct_x(m, p[0]);
        r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_08C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u), JS_CTX(p[1],p[5],0u,0u,0u), JS_CTX(p[1],p[6],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_08D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x45u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) ^ value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(p[2],p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_08E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xDEu, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, 16u, -1);
        r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[3],p[4],0u,0u,0u));
}

static js_stop_reason js_compact_template_08F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x78u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.p |= JS_FLAG_I;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_090(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB2u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v10_3_addr_dir_ind(m, p[0], &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[2], 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, p[2], 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[3],0u,p[4],0u));
}

static js_stop_reason js_compact_template_091(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x74u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct_x(m, p[0]);
        r = js_v05c_write_value(m, ea, 16u, 1, 0u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_092(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xC0u, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), p[3], 16u);
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,p[6],0u));
}

static js_stop_reason js_compact_template_093(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, p[2], &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x9342u,0u,0u,0u), JS_CTX(0xA0u,p[3],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_094(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xFEu, p[0], p[1] };
        r = js_v05c_guard_code(m, p[2], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_x(m, p[3]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_increment(&m->cpu, value, 16u, 1);
        r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(p[4],p[5],0u,0u,0u));
}

static js_stop_reason js_compact_template_095(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xCBu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = p[1];
        m->cpu.waiting = 1u;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_096(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u), JS_CTX(p[1],p[5],0u,0u,0u), JS_CTX(p[1],p[6],0u,0u,0u), JS_CTX(p[1],p[7],0u,0u,0u), JS_CTX(p[1],p[8],0u,0u,0u), JS_CTX(p[1],p[9],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_097(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,p[1],0u,0u,0u), JS_CTX(0xA0u,p[2],0u,0u,0u), JS_CTX(0xA0u,p[3],0u,0u,0u), JS_CTX(0xA0u,p[4],0u,0u,0u), JS_CTX(0xA0u,p[5],0u,0u,0u), JS_CTX(0xA0u,p[6],0u,0u,0u), JS_CTX(0xA0u,p[7],0u,0u,0u), JS_CTX(0xA0u,p[8],0u,0u,0u), JS_CTX(0xA0u,p[9],0u,0u,0u), JS_CTX(0xA0u,p[10],0u,0u,0u), JS_CTX(0xA0u,p[11],0u,0u,0u), JS_CTX(0xA0u,p[12],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_098(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(p[3],p[4],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_099(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x92u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v10_3_addr_dir_ind(m, p[0], &ea);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_write_value(m, ea, p[2], 0, (uint16_t)(m->cpu.a & p[3]));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[4],0u,p[5],0u));
}

static js_stop_reason js_compact_template_09A(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x0Fu, 0x1Cu, 0x19u, 0x00u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = 0x00191Cu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x81u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_09B(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v10_36_txy(&m->cpu, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_09C(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u), JS_CTX(p[1],p[5],0u,0u,0u), JS_CTX(p[1],p[6],0u,0u,0u), JS_CTX(p[1],p[7],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_09D(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(p[1],p[2],0u,0u,0u), JS_CTX(p[1],p[3],0u,0u,0u), JS_CTX(p[1],p[4],0u,0u,0u), JS_CTX(p[1],p[5],0u,0u,0u), JS_CTX(p[1],p[6],0u,0u,0u), JS_CTX(p[1],p[7],0u,0u,0u), JS_CTX(p[1],p[8],0u,0u,0u), JS_CTX(p[1],p[9],0u,0u,0u), JS_CTX(p[1],p[10],0u,0u,0u), JS_CTX(p[1],p[11],0u,0u,0u), JS_CTX(p[1],p[12],0u,0u,0u), JS_CTX(p[1],p[13],0u,0u,0u), JS_CTX(p[1],p[14],0u,0u,0u), JS_CTX(p[1],p[15],0u,0u,0u), JS_CTX(p[1],p[16],0u,0u,0u), JS_CTX(p[1],p[17],0u,0u,0u), JS_CTX(p[1],p[18],0u,0u,0u), JS_CTX(p[1],p[19],0u,0u,0u), JS_CTX(p[1],p[20],0u,0u,0u), JS_CTX(p[1],p[21],0u,0u,0u), JS_CTX(p[1],p[22],0u,0u,0u), JS_CTX(p[1],p[23],0u,0u,0u), JS_CTX(p[1],p[24],0u,0u,0u), JS_CTX(p[1],p[25],0u,0u,0u), JS_CTX(p[1],p[26],0u,0u,0u), JS_CTX(p[1],p[27],0u,0u,0u), JS_CTX(p[1],p[28],0u,0u,0u), JS_CTX(p[1],p[29],0u,0u,0u), JS_CTX(p[1],p[30],0u,0u,0u), JS_CTX(p[1],p[31],0u,0u,0u), JS_CTX(p[1],p[32],0u,0u,0u), JS_CTX(p[1],p[33],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_09E(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(0x80u,p[3],0u,0u,0u), JS_CTX(0x80u,p[4],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_09F(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xC495u,0u,0u,0u), JS_CTX(0x80u,0xC4A6u,0u,0u,0u), JS_CTX(0x80u,0xC4B7u,0u,0u,0u), JS_CTX(0x80u,0xC4C8u,0u,0u,0u), JS_CTX(0x80u,0xC4D9u,0u,0u,0u), JS_CTX(0x80u,0xC4EAu,0u,0u,0u), JS_CTX(0x80u,0xC4FBu,0u,0u,0u), JS_CTX(0x80u,0xC50Cu,0u,0u,0u), JS_CTX(0x80u,0xC51Du,0u,0u,0u), JS_CTX(0x80u,0xC52Bu,0u,0u,0u), JS_CTX(0x80u,0xC536u,0u,0u,0u), JS_CTX(0x80u,0xC541u,0u,0u,0u), JS_CTX(0x80u,0xC54Cu,0u,0u,0u), JS_CTX(0x80u,0xC557u,0u,0u,0u), JS_CTX(0x80u,0xC562u,0u,0u,0u), JS_CTX(0x80u,0xC56Du,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0A0(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x28u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint8_t pulled = 0u;
        r = js_v05c_pull8(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        uint8_t old_p = m->cpu.p;
        m->cpu.p = pulled;
        js_v05c_normalize(&m->cpu, old_p);
        m->cpu.pbr = 0xA2u; m->cpu.pc = p[1];
        const js_static_context_key allowed[] = { JS_CTX(0xA2u,p[1],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_SUCCESSOR_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0A1(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x67u, 0x08u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_long(m, 0x08u, &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A2(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x91u, 0x11u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_y(m, 0x11u, &ea);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A3(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xB5u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct_x(m, p[0]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A4(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Eu, p[0], 0x0Fu };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_ror(&m->cpu, value, 16u);
        r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A5(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x58u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.p &= (uint8_t)~JS_FLAG_I;
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A6(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x9Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.sp = m->cpu.x;
        if (m->cpu.e) m->cpu.sp = (uint16_t)(0x0100u | (m->cpu.sp & 0x00FFu));
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A7(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x08u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_push8(m, (uint8_t)(m->cpu.p));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA2u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0A8(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0x8765u,0u,0u,0u), JS_CTX(0x80u,0x8770u,0u,0u,0u), JS_CTX(0x80u,0x877Bu,0u,0u,0u), JS_CTX(0x80u,0x8786u,0u,0u,0u), JS_CTX(0x80u,0x879Au,0u,0u,0u), JS_CTX(0x80u,0x87A5u,0u,0u,0u), JS_CTX(0x80u,0x87B0u,0u,0u,0u), JS_CTX(0x80u,0x87C4u,0u,0u,0u), JS_CTX(0x80u,0x87CFu,0u,0u,0u), JS_CTX(0x80u,0x87DAu,0u,0u,0u), JS_CTX(0x80u,0x87E5u,0u,0u,0u), JS_CTX(0x80u,0x87F9u,0u,0u,0u), JS_CTX(0x80u,0x8804u,0u,0u,0u), JS_CTX(0x80u,0x880Fu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0A9(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(0x80u,p[2],0u,0u,0u), JS_CTX(0x80u,p[3],0u,0u,0u), JS_CTX(0x80u,p[4],0u,0u,0u), JS_CTX(0x80u,p[5],0u,0u,0u), JS_CTX(0x80u,p[6],0u,0u,0u), JS_CTX(0x80u,p[7],0u,0u,0u), JS_CTX(0x80u,p[8],0u,0u,0u), JS_CTX(0x80u,p[9],0u,0u,0u), JS_CTX(0x80u,p[10],0u,0u,0u), JS_CTX(0x80u,p[11],0u,0u,0u), JS_CTX(0x80u,p[12],0u,0u,0u), JS_CTX(0x80u,p[13],0u,0u,0u), JS_CTX(0x80u,p[14],0u,0u,0u), JS_CTX(0x80u,p[15],0u,0u,0u), JS_CTX(0x80u,p[16],0u,0u,0u), JS_CTX(0x80u,p[17],0u,0u,0u), JS_CTX(0x80u,p[18],0u,0u,0u), JS_CTX(0x80u,p[19],0u,0u,0u), JS_CTX(0x80u,p[20],0u,0u,0u), JS_CTX(0x80u,p[21],0u,0u,0u), JS_CTX(0x80u,p[22],0u,0u,0u), JS_CTX(0x80u,p[23],0u,0u,0u), JS_CTX(0x80u,p[24],0u,0u,0u), JS_CTX(0x80u,p[25],0u,0u,0u), JS_CTX(0x80u,p[26],0u,0u,0u), JS_CTX(0x80u,p[27],0u,0u,0u), JS_CTX(0x80u,p[28],0u,0u,0u), JS_CTX(0x80u,p[29],0u,0u,0u), JS_CTX(0x80u,p[30],0u,0u,0u), JS_CTX(0x80u,p[31],0u,0u,0u), JS_CTX(0x80u,p[32],0u,0u,0u), JS_CTX(0x80u,p[33],0u,0u,0u), JS_CTX(0x80u,p[34],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0AA(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,p[1],0u,0u,0u), JS_CTX(p[2],p[3],0u,0u,0u), JS_CTX(p[4],p[5],0u,0u,0u), JS_CTX(p[4],p[6],0u,0u,0u), JS_CTX(p[7],p[8],0u,0u,0u), JS_CTX(p[7],p[9],0u,0u,0u), JS_CTX(p[7],p[10],0u,0u,0u), JS_CTX(p[7],p[11],0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0AB(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x81u,0xD24Cu,0u,0u,0u), JS_CTX(0x81u,0xD25Du,0u,0u,0u), JS_CTX(0x81u,0xD26Eu,0u,0u,0u), JS_CTX(0x81u,0xD27Fu,0u,0u,0u), JS_CTX(0x81u,0xD290u,0u,0u,0u), JS_CTX(0x81u,0xE2F9u,0u,0u,0u), JS_CTX(0x81u,0xE337u,0u,0u,0u), JS_CTX(0x81u,0xEC64u,0u,0u,0u), JS_CTX(0x81u,0xECB5u,0u,0u,0u), JS_CTX(0x81u,0xECC9u,0u,0u,0u), JS_CTX(0x81u,0xEEBCu,0u,0u,0u), JS_CTX(0x81u,0xEED3u,0u,0u,0u), JS_CTX(0x81u,0xEEEAu,0u,0u,0u), JS_CTX(0x81u,0xEF01u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0AC(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x1Bu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint8_t old_p = m->cpu.p;
        m->cpu.sp = m->cpu.a;
        js_v05c_normalize(&m->cpu, old_p);
        return js_v05c_finish_fixed(m, JS_CTX(p[1],p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_0AD(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Au };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint8_t pulled = 0u;
        r = js_v05c_pull8(m, &pulled);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_y(&m->cpu, pulled, 8u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[1],0u,0u,1u));
}

static js_stop_reason js_compact_template_0AE(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xA7u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_long(m, p[0], &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[2],0u,0u,0u));
}

static js_stop_reason js_compact_template_0AF(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xF7u, 0xE7u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v05c_addr_dir_ind_long_y(m, 0xE7u, &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, p[1], 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & p[2]), value, p[1]);
        js_v05c_write_a(&m->cpu, result, p[1], 0);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[3],0u,p[4],0u));
}

static js_stop_reason js_compact_template_0B0(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xD2u, 0x2Du };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = 0u;
        r = js_v10_3_addr_dir_ind(m, 0x2Du, &ea);
        if (r != JS_STOP_NONE) return r;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0B1(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xE4u, 0x24u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, 0x24u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), value, 16u);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0B2(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x69u, p[0] };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), p[2], 8u);
        js_v05c_write_a(&m->cpu, result, 8u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0xA2u,p[3],0u,1u,0u));
}

static js_stop_reason js_compact_template_0B3(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBDu, p[0], 0x91u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((p[2] & 0xFF00u) != ((uint16_t)(p[2] + m->cpu.x) & 0xFF00u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_abs_x(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_a(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[3],0u,0u,1u));
}

static js_stop_reason js_compact_template_0B4(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x3Du, 0xBBu };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xBB3Du, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xB92Eu,0u,0u,0u), JS_CTX(0x80u,0xB947u,0u,0u,0u), JS_CTX(0x80u,0xBB5Fu,0u,0u,0u), JS_CTX(0x80u,0xBB61u,0u,0u,0u), JS_CTX(0x80u,0xBBAAu,0u,0u,0u), JS_CTX(0x80u,0xBBE6u,0u,0u,0u), JS_CTX(0x80u,0xBC26u,0u,0u,0u), JS_CTX(0x80u,0xBC82u,0u,0u,0u), JS_CTX(0x80u,0xBCA0u,0u,0u,0u), JS_CTX(0x80u,0xBCBEu,0u,0u,0u), JS_CTX(0x80u,0xBD02u,0u,0u,0u), JS_CTX(0x80u,0xBD97u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0B5(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x19u, p[0], 0x00u };
        r = js_v05c_guard_code(m, p[1], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, p[2]);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,p[3],0u,0u,0u));
}

static js_stop_reason js_compact_template_0B6(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x1Fu, 0xCAu, 0x0Du, 0xA0u };
        r = js_v05c_guard_code(m, p[0], expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,p[1],0u,0u,0u));
}

static js_stop_reason js_compact_template_0B7(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBAu };
        r = js_v05c_guard_code(m, 1048614u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, m->cpu.sp, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8027u,0u,0u,0u));
}

static js_stop_reason js_compact_template_0B8(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xD8u };
        r = js_v05c_guard_code(m, 4u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        m->cpu.p &= (uint8_t)~JS_FLAG_D;
        return js_v05c_finish_fixed(m, JS_CTX(0x00u,0x8005u,0u,1u,1u));
}

static js_stop_reason js_compact_template_0B9(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 1074255u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x82B9u,0u,0u,0u), JS_CTX(0xA0u,0x8304u,0u,0u,0u), JS_CTX(0xA0u,0x8371u,0u,0u,0u), JS_CTX(0xA0u,0x9B0Au,0u,0u,0u), JS_CTX(0xA0u,0xA45Cu,0u,0u,0u), JS_CTX(0xA0u,0xB4B9u,0u,0u,0u), JS_CTX(0xA0u,0xB533u,0u,0u,0u), JS_CTX(0xA0u,0xB7B0u,0u,0u,0u), JS_CTX(0xA0u,0xB852u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BA(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 1054838u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x98DEu,0u,0u,0u), JS_CTX(0xA0u,0x9916u,0u,0u,0u), JS_CTX(0xA0u,0x9934u,0u,0u,0u), JS_CTX(0xA0u,0x9940u,0u,0u,0u), JS_CTX(0xA0u,0x9A15u,0u,0u,0u), JS_CTX(0xA0u,0x9AD3u,0u,0u,0u), JS_CTX(0xA0u,0x9BFAu,0u,0u,0u), JS_CTX(0xA0u,0x9CA7u,0u,0u,0u), JS_CTX(0xA0u,0xA008u,0u,0u,0u), JS_CTX(0xA0u,0xA01Cu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BB(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 21623u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xD318u,0u,0u,0u), JS_CTX(0x80u,0xD320u,0u,0u,0u), JS_CTX(0x80u,0xD328u,0u,0u,0u), JS_CTX(0x80u,0xD330u,0u,0u,0u), JS_CTX(0x80u,0xD338u,0u,0u,0u), JS_CTX(0x80u,0xD340u,0u,0u,0u), JS_CTX(0x80u,0xD348u,0u,0u,0u), JS_CTX(0x80u,0xD350u,0u,0u,0u), JS_CTX(0x80u,0xD358u,0u,0u,0u), JS_CTX(0x80u,0xD360u,0u,0u,0u), JS_CTX(0x80u,0xD368u,0u,0u,0u), JS_CTX(0x80u,0xD370u,0u,0u,0u), JS_CTX(0x80u,0xD378u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BC(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 20493u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0x8765u,0u,0u,0u), JS_CTX(0x80u,0x8770u,0u,0u,0u), JS_CTX(0x80u,0x877Bu,0u,0u,0u), JS_CTX(0x80u,0x8786u,0u,0u,0u), JS_CTX(0x80u,0x879Au,0u,0u,0u), JS_CTX(0x80u,0x87A5u,0u,0u,0u), JS_CTX(0x80u,0x87B0u,0u,0u,0u), JS_CTX(0x80u,0x87C4u,0u,0u,0u), JS_CTX(0x80u,0x87CFu,0u,0u,0u), JS_CTX(0x80u,0x87DAu,0u,0u,0u), JS_CTX(0x80u,0x87E5u,0u,0u,0u), JS_CTX(0x80u,0x87F9u,0u,0u,0u), JS_CTX(0x80u,0x8804u,0u,0u,0u), JS_CTX(0x80u,0x880Fu,0u,0u,0u), JS_CTX(0x80u,0xCDA9u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BD(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 1054813u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x9419u,0u,0u,0u), JS_CTX(0xA0u,0x9423u,0u,0u,0u), JS_CTX(0xA0u,0x943Au,0u,0u,0u), JS_CTX(0xA0u,0x9444u,0u,0u,0u), JS_CTX(0xA0u,0x945Cu,0u,0u,0u), JS_CTX(0xA0u,0x9473u,0u,0u,0u), JS_CTX(0xA0u,0x9487u,0u,0u,0u), JS_CTX(0xA0u,0x949Du,0u,0u,0u), JS_CTX(0xA0u,0x94B9u,0u,0u,0u), JS_CTX(0xA0u,0x94D3u,0u,0u,0u), JS_CTX(0xA0u,0x94E7u,0u,0u,0u), JS_CTX(0xA0u,0x94FDu,0u,0u,0u), JS_CTX(0xA0u,0x9B6Du,0u,0u,0u), JS_CTX(0xA0u,0x9B8Cu,0u,0u,0u), JS_CTX(0xA0u,0x9BAEu,0u,0u,0u), JS_CTX(0xA0u,0x9BCDu,0u,0u,0u), JS_CTX(0xA0u,0x9C2Eu,0u,0u,0u), JS_CTX(0xA0u,0x9C59u,0u,0u,0u), JS_CTX(0xA0u,0x9FC4u,0u,0u,0u), JS_CTX(0xA0u,0x9FE2u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BE(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 21519u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xD298u,0u,0u,0u), JS_CTX(0x80u,0xD2A0u,0u,0u,0u), JS_CTX(0x80u,0xD2A8u,0u,0u,0u), JS_CTX(0x80u,0xD2B0u,0u,0u,0u), JS_CTX(0x80u,0xD2B8u,0u,0u,0u), JS_CTX(0x80u,0xD2C0u,0u,0u,0u), JS_CTX(0x80u,0xD2C8u,0u,0u,0u), JS_CTX(0x80u,0xD2D0u,0u,0u,0u), JS_CTX(0x80u,0xD2D8u,0u,0u,0u), JS_CTX(0x80u,0xD2E0u,0u,0u,0u), JS_CTX(0x80u,0xD2E8u,0u,0u,0u), JS_CTX(0x80u,0xD2F0u,0u,0u,0u), JS_CTX(0x80u,0xD2F8u,0u,0u,0u), JS_CTX(0x80u,0xD300u,0u,0u,0u), JS_CTX(0x80u,0xD308u,0u,0u,0u), JS_CTX(0x80u,0xD310u,0u,0u,0u), JS_CTX(0x80u,0xD318u,0u,0u,0u), JS_CTX(0x80u,0xD320u,0u,0u,0u), JS_CTX(0x80u,0xD328u,0u,0u,0u), JS_CTX(0x80u,0xD330u,0u,0u,0u), JS_CTX(0x80u,0xD338u,0u,0u,0u), JS_CTX(0x80u,0xD340u,0u,0u,0u), JS_CTX(0x80u,0xD348u,0u,0u,0u), JS_CTX(0x80u,0xD350u,0u,0u,0u), JS_CTX(0x80u,0xD358u,0u,0u,0u), JS_CTX(0x80u,0xD360u,0u,0u,0u), JS_CTX(0x80u,0xD368u,0u,0u,0u), JS_CTX(0x80u,0xD370u,0u,0u,0u), JS_CTX(0x80u,0xD378u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0BF(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x60u };
        r = js_v05c_guard_code(m, 12861u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 3u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0x86A1u,0u,0u,0u), JS_CTX(0x80u,0x86AFu,0u,0u,0u), JS_CTX(0x80u,0x86BDu,0u,0u,0u), JS_CTX(0x80u,0x86CBu,0u,0u,0u), JS_CTX(0x80u,0x86D6u,0u,0u,0u), JS_CTX(0x80u,0x86E1u,0u,0u,0u), JS_CTX(0x80u,0x86ECu,0u,0u,0u), JS_CTX(0x80u,0x86F7u,0u,0u,0u), JS_CTX(0x80u,0x8702u,0u,0u,0u), JS_CTX(0x80u,0x870Du,0u,0u,0u), JS_CTX(0x80u,0x8718u,0u,0u,0u), JS_CTX(0x80u,0x8723u,0u,0u,0u), JS_CTX(0x80u,0x872Eu,0u,0u,0u), JS_CTX(0x80u,0x8739u,0u,0u,0u), JS_CTX(0x80u,0x8744u,0u,0u,0u), JS_CTX(0x80u,0x874Fu,0u,0u,0u), JS_CTX(0x80u,0x8762u,0u,0u,0u), JS_CTX(0x80u,0x876Du,0u,0u,0u), JS_CTX(0x80u,0x8778u,0u,0u,0u), JS_CTX(0x80u,0x8783u,0u,0u,0u), JS_CTX(0x80u,0x8797u,0u,0u,0u), JS_CTX(0x80u,0x87A2u,0u,0u,0u), JS_CTX(0x80u,0x87ADu,0u,0u,0u), JS_CTX(0x80u,0x87C1u,0u,0u,0u), JS_CTX(0x80u,0x87CCu,0u,0u,0u), JS_CTX(0x80u,0x87D7u,0u,0u,0u), JS_CTX(0x80u,0x87E2u,0u,0u,0u), JS_CTX(0x80u,0x87F6u,0u,0u,0u), JS_CTX(0x80u,0x8801u,0u,0u,0u), JS_CTX(0x80u,0x880Cu,0u,0u,0u), JS_CTX(0x80u,0xB277u,0u,0u,0u), JS_CTX(0x80u,0xB28Fu,0u,0u,0u), JS_CTX(0x80u,0xB2BBu,0u,0u,0u), JS_CTX(0x80u,0xB2DCu,0u,0u,0u), JS_CTX(0x80u,0xB565u,0u,0u,0u), JS_CTX(0x80u,0xB58Eu,0u,0u,0u), JS_CTX(0x80u,0xB634u,0u,0u,0u), JS_CTX(0x80u,0xB8F1u,0u,0u,0u), JS_CTX(0x80u,0xBF53u,0u,0u,0u), JS_CTX(0x80u,0xBFD9u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0C0(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, 1074304u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x801Fu,0u,0u,0u), JS_CTX(0xA0u,0xB9A7u,0u,0u,0u), JS_CTX(0xA0u,0xC65Cu,0u,0u,0u), JS_CTX(0xA0u,0xD056u,0u,0u,0u), JS_CTX(0xA2u,0xA57Du,0u,0u,0u), JS_CTX(0xA2u,0xA5F4u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0C1(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, 48576u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x81u,0xD0EEu,0u,0u,0u), JS_CTX(0x81u,0xD3E3u,0u,0u,0u), JS_CTX(0x81u,0xD916u,0u,0u,0u), JS_CTX(0x81u,0xDC5Eu,0u,0u,0u), JS_CTX(0x81u,0xDE72u,0u,0u,0u), JS_CTX(0x81u,0xE365u,0u,0u,0u), JS_CTX(0x81u,0xE593u,0u,0u,0u), JS_CTX(0x81u,0xE8C2u,0u,0u,0u), JS_CTX(0x81u,0xEC9Bu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0C2(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Bu };
        r = js_v05c_guard_code(m, 31967u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 2u);
        if (r != JS_STOP_NONE) return r;
        uint16_t ret = 0u; uint8_t bank = 0u;
        r = js_v05c_pull16(m, &ret);
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_pull8(m, &bank);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = (uint16_t)(ret + 1u);
        m->cpu.pbr = bank;
        const js_static_context_key allowed[] = { JS_CTX(0x81u,0xB608u,0u,0u,0u), JS_CTX(0x81u,0xB612u,0u,0u,0u), JS_CTX(0x81u,0xB61Cu,0u,0u,0u), JS_CTX(0x81u,0xB626u,0u,0u,0u), JS_CTX(0x81u,0xB630u,0u,0u,0u), JS_CTX(0x81u,0xB63Au,0u,0u,0u), JS_CTX(0x81u,0xB644u,0u,0u,0u), JS_CTX(0x81u,0xB64Eu,0u,0u,0u), JS_CTX(0x81u,0xB658u,0u,0u,0u), JS_CTX(0x81u,0xB662u,0u,0u,0u), JS_CTX(0x81u,0xB66Cu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0C3(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xFBu };
        r = js_v05c_guard_code(m, 3u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint8_t old_p = m->cpu.p;
        uint8_t old_c = (uint8_t)((m->cpu.p & JS_FLAG_C) != 0u);
        uint8_t old_e = m->cpu.e;
        if (old_e) m->cpu.p |= JS_FLAG_C; else m->cpu.p &= (uint8_t)~JS_FLAG_C;
        m->cpu.e = old_c;
        js_v05c_normalize(&m->cpu, old_p);
        return js_v05c_finish_fixed(m, JS_CTX(0x00u,0x8004u,0u,1u,1u));
}

static js_stop_reason js_compact_template_0C4(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x50u, 0x1Du };
        r = js_v05c_guard_code(m, 1124424u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if (((m->cpu.p & JS_FLAG_V) == 0u)) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
            return js_v05c_finish_fixed(m, JS_CTX(0xA2u,0xA867u,0u,1u,0u));
        }
        return js_v05c_finish_fixed(m, JS_CTX(0xA2u,0xA84Au,0u,1u,0u));
}

static js_stop_reason js_compact_template_0C5(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x24u, 0x30u };
        r = js_v05c_guard_code(m, 12146u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct(m, 0x30u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 8u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), value, 8u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xAF74u,0u,1u,0u));
}

static js_stop_reason js_compact_template_0C6(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x15u, 0x7Eu };
        r = js_v05c_guard_code(m, 31549u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        if ((m->cpu.d & 0x00FFu) != 0u) {
            r = js_v05c_idle_cycles(m, 1u);
            if (r != JS_STOP_NONE) return r;
        }
        uint32_t ea = js_v05c_addr_direct_x(m, 0x7Eu);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xFB3Fu,0u,0u,0u));
}

static js_stop_reason js_compact_template_0C7(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x03u, 0x01u };
        r = js_v05c_guard_code(m, 1051419u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = (uint16_t)(m->cpu.sp + 0x01u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 1, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8B1Du,0u,0u,0u));
}

static js_stop_reason js_compact_template_0C8(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x98u, 0xFCu };
        r = js_v05c_guard_code(m, 64661u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xFC98u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0x81u,0xFCAAu,0u,0u,0u), JS_CTX(0x81u,0xFCB5u,0u,0u,0u), JS_CTX(0x81u,0xFE48u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0C9(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0xF7u, 0xAEu };
        r = js_v05c_guard_code(m, 12020u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xAEF7u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xAEFFu,0u,0u,0u), JS_CTX(0x80u,0xAF09u,0u,0u,0u), JS_CTX(0x80u,0xAF2Au,0u,0u,0u), JS_CTX(0x80u,0xAF43u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0CA(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x8Du, 0xE4u };
        r = js_v05c_guard_code(m, 1074314u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xE48Du, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0xE58Du,0u,0u,0u), JS_CTX(0xA0u,0xE5A6u,0u,0u,0u), JS_CTX(0xA0u,0xE5E0u,0u,0u,0u), JS_CTX(0xA0u,0xE622u,0u,0u,0u), JS_CTX(0xA0u,0xE64Bu,0u,0u,0u), JS_CTX(0xA0u,0xE679u,0u,0u,0u), JS_CTX(0xA0u,0xE6AAu,0u,0u,0u), JS_CTX(0xA0u,0xE6F4u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0CB(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0xC8u, 0xD0u };
        r = js_v05c_guard_code(m, 53445u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xD0C8u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0x81u,0xD0DAu,0u,0u,0u), JS_CTX(0x81u,0xD3CAu,0u,0u,0u), JS_CTX(0x81u,0xD902u,0u,0u,0u), JS_CTX(0x81u,0xDC4Au,0u,0u,0u), JS_CTX(0x81u,0xDE5Bu,0u,0u,0u), JS_CTX(0x81u,0xE351u,0u,0u,0u), JS_CTX(0x81u,0xE57Fu,0u,0u,0u), JS_CTX(0x81u,0xE8A9u,0u,0u,0u), JS_CTX(0x81u,0xEC87u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0CC(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0xC0u, 0xE4u };
        r = js_v05c_guard_code(m, 25789u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xE4C0u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0x80u,0xE503u,0u,0u,0u), JS_CTX(0x80u,0xE560u,0u,0u,0u), JS_CTX(0x80u,0xE5BDu,0u,0u,0u), JS_CTX(0x80u,0xE61Au,0u,0u,0u), JS_CTX(0x80u,0xE677u,0u,0u,0u), JS_CTX(0x80u,0xE6D4u,0u,0u,0u), JS_CTX(0x80u,0xE731u,0u,0u,0u), JS_CTX(0x80u,0xE78Eu,0u,0u,0u), JS_CTX(0x80u,0xE7EBu,0u,0u,0u), JS_CTX(0x80u,0xE848u,0u,0u,0u), JS_CTX(0x80u,0xE8A5u,0u,0u,0u), JS_CTX(0x80u,0xE902u,0u,0u,0u), JS_CTX(0x80u,0xE95Fu,0u,0u,0u), JS_CTX(0x80u,0xE9BCu,0u,0u,0u), JS_CTX(0x80u,0xEA19u,0u,0u,0u), JS_CTX(0x80u,0xEA76u,0u,0u,0u), JS_CTX(0x80u,0xEAD3u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0CD(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x1Cu, 0x73u, 0x00u };
        r = js_v05c_guard_code(m, 2563u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, 0x0073u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 8u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), value, 8u);
        r = js_v05c_write_rmw_value(m, ea, 8u, 0, value);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x8A06u,0u,1u,0u));
}

static js_stop_reason js_compact_template_0CE(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xBEu, 0x68u, 0x00u };
        r = js_v05c_guard_code(m, 21122u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, 0x0068u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        js_v05c_write_x(&m->cpu, value, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD285u,0u,0u,0u));
}

static js_stop_reason js_compact_template_0CF(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x39u, 0x12u, 0x00u };
        r = js_v05c_guard_code(m, 17071u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, 0x0012u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC2B2u,0u,0u,0u));
}

static js_stop_reason js_compact_template_0D0(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x59u, 0x12u, 0x00u };
        r = js_v05c_guard_code(m, 17066u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs_y(m, 0x0012u);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) ^ value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC2ADu,0u,0u,0u));
}

static js_stop_reason js_compact_template_0D1(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x4Cu, 0x5Cu, 0x9Cu };
        r = js_v05c_guard_code(m, 6896u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, (js_static_context_key){0x80u,0x9C5Cu,0u,0u,0u});
}

static js_stop_reason js_compact_template_0D2(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Cu, 0x0Bu, 0x0Cu };
        r = js_v05c_guard_code(m, 1048939u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_ind_target(m, 0x0C0Bu, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8171u,0u,0u,0u), JS_CTX(0xA0u,0x81F9u,0u,0u,0u), JS_CTX(0xA0u,0x8276u,0u,0u,0u), JS_CTX(0xA0u,0x8291u,0u,0u,0u), JS_CTX(0xA0u,0x834Cu,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D3(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Cu, 0x69u, 0x0Cu };
        r = js_v05c_guard_code(m, 1063110u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_ind_target(m, 0x0C69u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        const js_static_context_key allowed[] = { JS_CTX(0xA0u,0xB8CAu,0u,0u,0u), JS_CTX(0xA0u,0xB8EAu,0u,0u,0u), JS_CTX(0xA0u,0xB8FAu,0u,0u,0u), JS_CTX(0xA0u,0xB91Au,0u,0u,0u), JS_CTX(0xA0u,0xB941u,0u,0u,0u), JS_CTX(0xA0u,0xB942u,0u,0u,0u), JS_CTX(0xA0u,0xB957u,0u,0u,0u), JS_CTX(0xA0u,0xB977u,0u,0u,0u) };
        r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_DYNAMIC_TARGET);
        if (r != JS_STOP_NONE) return r;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D4(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x8Cu, 0xCAu };
        r = js_v05c_guard_code(m, 19081u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xCA8Cu, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        switch (target_pc) {
            case 0xCACEu: break;
            case 0xBA0Eu: break;
            case 0xB5ADu: break;
            case 0xB392u: break;
            case 0xB2B1u: break;
            case 0xB915u: break;
            case 0xB8A7u: break;
            case 0xB282u: break;
            case 0xB23Eu: break;
            case 0xB9D2u: break;
            case 0xB476u: break;
            case 0xB2BEu: break;
            case 0xB26Du: break;
            case 0xB3C5u: break;
            case 0xBF46u: break;
            case 0xB889u: break;
            case 0xB266u: break;
            case 0xB246u: break;
            case 0xBFCCu: break;
            case 0xB7BEu: break;
            case 0xB5CBu: break;
            case 0xB90Au: break;
            case 0xBE5Au: break;
            case 0xBEACu: break;
            case 0xB997u: break;
            case 0xB76Eu: break;
            case 0xB673u: break;
            case 0xBE02u: break;
            case 0xBF02u: break;
            case 0xB9F4u: break;
            case 0xC08Au: break;
            case 0xB46Bu: break;
            case 0xB58Bu: break;
            default: return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        }
        if (!js_v10_100_scpu_context_known(js_v05c_key_from_cpu(&m->cpu)))
            return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D5(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x31u, 0x95u };
        r = js_v05c_guard_code(m, 5422u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0x9531u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        switch (target_pc) {
            case 0x978Au: break;
            case 0x97E3u: break;
            case 0x9B7Eu: break;
            case 0x982Cu: break;
            case 0x98C5u: break;
            case 0x9AA0u: break;
            case 0x9653u: break;
            case 0x9AE1u: break;
            case 0x9553u: break;
            case 0x9571u: break;
            case 0x95D4u: break;
            case 0x96E5u: break;
            case 0x95A2u: break;
            case 0x95CBu: break;
            case 0x958Eu: break;
            case 0x957Au: break;
            default: return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        }
        if (!js_v10_100_scpu_context_known(js_v05c_key_from_cpu(&m->cpu)))
            return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D6(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x7Cu, 0x0Bu, 0xAEu };
        r = js_v05c_guard_code(m, 11784u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint16_t target_pc = 0u;
        r = js_v05c_read_abs_x_ind_target(m, 0xAE0Bu, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        switch (target_pc) {
            case 0xAE13u: break;
            case 0xAE4Cu: break;
            case 0xAE6Du: break;
            case 0xAE78u: break;
            default: return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        }
        if (!js_v10_100_scpu_context_known(js_v05c_key_from_cpu(&m->cpu)))
            return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D7(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x4Du, 0xFAu, 0x08u };
        r = js_v05c_guard_code(m, 28175u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = js_v05c_addr_abs(m, 0x08FAu);
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) ^ value) & 0xFFFFu);
        js_v05c_write_a(&m->cpu, result, 16u, 1);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xEE12u,0u,0u,0u));
}

static js_stop_reason js_compact_template_0D8(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Cu, 0x15u, 0x0Cu };
        uint16_t target_pc = 0u;
        r = js_v05c_guard_code(m, 1054186u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        r = js_v05c_read_abs_ind_target(m, 0x0C15u, &target_pc);
        if (r != JS_STOP_NONE) return r;
        m->cpu.pc = target_pc;
        switch (target_pc) {
            case 0x8D7Bu: break;
            case 0x925Au: break;
            case 0x9268u: break;
            case 0x95EEu: break;
            case 0x95F8u: break;
            case 0x95FFu: break;
            case 0x965Au: break;
            case 0x9685u: break;
            case 0x96BEu: break;
            case 0x96EDu: break;
            case 0x9760u: break;
            case 0x9804u: break;
            case 0x9828u: break;
            case 0x9877u: break;
            case 0x98C1u: break;
            case 0x99C9u: break;
            case 0x9A95u: break;
            case 0x9BEEu: break;
            case 0x9C8Fu: break;
            case 0x9CAFu: break;
            case 0xA0FBu: break;
            case 0xA108u: break;
            case 0xA612u: break;
            case 0xA6D1u: break;
            case 0xA853u: break;
            case 0xA970u: break;
            case 0xA9A1u: break;
            case 0xA9C7u: break;
            case 0xA9F2u: break;
            case 0xAA15u: break;
            case 0xAA3Bu: break;
            case 0xAB86u: break;
            case 0xABF0u: break;
            case 0xAC29u: break;
            case 0xAC5Du: break;
            case 0xAD2Eu: break;
            case 0xAD44u: break;
            case 0xAD4Fu: break;
            case 0xAD78u: break;
            case 0xAD93u: break;
            case 0xADC3u: break;
            case 0xADF9u: break;
            case 0xAE46u: break;
            case 0xAE92u: break;
            case 0xAEFAu: break;
            case 0xAF49u: break;
            case 0xAF6Au: break;
            case 0xB409u: break;
            case 0xB460u: break;
            case 0xB4D9u: break;
            case 0xB583u: break;
            case 0xB5D6u: break;
            case 0xB647u: break;
            case 0xB6B8u: break;
            case 0xB6CDu: break;
            case 0xB99Au: break;
            case 0xCC50u: break;
            case 0xCC79u: break;
            case 0xCCDEu: break;
            case 0xCD54u: break;
            case 0xCE52u: break;
            case 0xCE87u: break;
            default: return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        }
        if (!js_v10_100_scpu_context_known(js_v05c_key_from_cpu(&m->cpu)))
            return JS_STOP_UNPROVED_DYNAMIC_TARGET;
        m->cpu.retired_instructions++;
        return JS_STOP_NONE;
}

static js_stop_reason js_compact_template_0D9(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0x6Fu, 0x1Au, 0x0Du, 0xA0u };
        r = js_v05c_guard_code(m, 1124062u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = 0xA00D1Au;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0xA2u,0xA6E2u,0u,0u,0u));
}

static js_stop_reason js_compact_template_0DA(
        js_machine_v05c *m, const uint32_t *p) {
    (void)p;
        js_stop_reason r = JS_STOP_NONE;
        const uint8_t expected[] = { 0xEFu, 0x3Eu, 0x08u, 0x00u };
        r = js_v05c_guard_code(m, 6475u, expected, sizeof(expected));
        if (r != JS_STOP_NONE) return r;
        uint32_t ea = 0x00083Eu;
        uint16_t value = 0u;
        r = js_v05c_read_value(m, ea, 16u, 0, &value);
        if (r != JS_STOP_NONE) return r;
        uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
        js_v05c_write_a(&m->cpu, result, 16u, 0);
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x994Fu,0u,0u,0u));
}

js_stop_reason js_compact_scpu_execute(js_machine_v05c *m,
                                        uint16_t template_id,
                                        const uint32_t *p) {
    switch (template_id) {
        case 0x000u: return js_compact_template_000(m, p);
        case 0x001u: return js_compact_template_001(m, p);
        case 0x002u: return js_compact_template_002(m, p);
        case 0x003u: return js_compact_template_003(m, p);
        case 0x004u: return js_compact_template_004(m, p);
        case 0x005u: return js_compact_template_005(m, p);
        case 0x006u: return js_compact_template_006(m, p);
        case 0x007u: return js_compact_template_007(m, p);
        case 0x008u: return js_compact_template_008(m, p);
        case 0x009u: return js_compact_template_009(m, p);
        case 0x00Au: return js_compact_template_00A(m, p);
        case 0x00Bu: return js_compact_template_00B(m, p);
        case 0x00Cu: return js_compact_template_00C(m, p);
        case 0x00Du: return js_compact_template_00D(m, p);
        case 0x00Eu: return js_compact_template_00E(m, p);
        case 0x00Fu: return js_compact_template_00F(m, p);
        case 0x010u: return js_compact_template_010(m, p);
        case 0x011u: return js_compact_template_011(m, p);
        case 0x012u: return js_compact_template_012(m, p);
        case 0x013u: return js_compact_template_013(m, p);
        case 0x014u: return js_compact_template_014(m, p);
        case 0x015u: return js_compact_template_015(m, p);
        case 0x016u: return js_compact_template_016(m, p);
        case 0x017u: return js_compact_template_017(m, p);
        case 0x018u: return js_compact_template_018(m, p);
        case 0x019u: return js_compact_template_019(m, p);
        case 0x01Au: return js_compact_template_01A(m, p);
        case 0x01Bu: return js_compact_template_01B(m, p);
        case 0x01Cu: return js_compact_template_01C(m, p);
        case 0x01Du: return js_compact_template_01D(m, p);
        case 0x01Eu: return js_compact_template_01E(m, p);
        case 0x01Fu: return js_compact_template_01F(m, p);
        case 0x020u: return js_compact_template_020(m, p);
        case 0x021u: return js_compact_template_021(m, p);
        case 0x022u: return js_compact_template_022(m, p);
        case 0x023u: return js_compact_template_023(m, p);
        case 0x024u: return js_compact_template_024(m, p);
        case 0x025u: return js_compact_template_025(m, p);
        case 0x026u: return js_compact_template_026(m, p);
        case 0x027u: return js_compact_template_027(m, p);
        case 0x028u: return js_compact_template_028(m, p);
        case 0x029u: return js_compact_template_029(m, p);
        case 0x02Au: return js_compact_template_02A(m, p);
        case 0x02Bu: return js_compact_template_02B(m, p);
        case 0x02Cu: return js_compact_template_02C(m, p);
        case 0x02Du: return js_compact_template_02D(m, p);
        case 0x02Eu: return js_compact_template_02E(m, p);
        case 0x02Fu: return js_compact_template_02F(m, p);
        case 0x030u: return js_compact_template_030(m, p);
        case 0x031u: return js_compact_template_031(m, p);
        case 0x032u: return js_compact_template_032(m, p);
        case 0x033u: return js_compact_template_033(m, p);
        case 0x034u: return js_compact_template_034(m, p);
        case 0x035u: return js_compact_template_035(m, p);
        case 0x036u: return js_compact_template_036(m, p);
        case 0x037u: return js_compact_template_037(m, p);
        case 0x038u: return js_compact_template_038(m, p);
        case 0x039u: return js_compact_template_039(m, p);
        case 0x03Au: return js_compact_template_03A(m, p);
        case 0x03Bu: return js_compact_template_03B(m, p);
        case 0x03Cu: return js_compact_template_03C(m, p);
        case 0x03Du: return js_compact_template_03D(m, p);
        case 0x03Eu: return js_compact_template_03E(m, p);
        case 0x03Fu: return js_compact_template_03F(m, p);
        case 0x040u: return js_compact_template_040(m, p);
        case 0x041u: return js_compact_template_041(m, p);
        case 0x042u: return js_compact_template_042(m, p);
        case 0x043u: return js_compact_template_043(m, p);
        case 0x044u: return js_compact_template_044(m, p);
        case 0x045u: return js_compact_template_045(m, p);
        case 0x046u: return js_compact_template_046(m, p);
        case 0x047u: return js_compact_template_047(m, p);
        case 0x048u: return js_compact_template_048(m, p);
        case 0x049u: return js_compact_template_049(m, p);
        case 0x04Au: return js_compact_template_04A(m, p);
        case 0x04Bu: return js_compact_template_04B(m, p);
        case 0x04Cu: return js_compact_template_04C(m, p);
        case 0x04Du: return js_compact_template_04D(m, p);
        case 0x04Eu: return js_compact_template_04E(m, p);
        case 0x04Fu: return js_compact_template_04F(m, p);
        case 0x050u: return js_compact_template_050(m, p);
        case 0x051u: return js_compact_template_051(m, p);
        case 0x052u: return js_compact_template_052(m, p);
        case 0x053u: return js_compact_template_053(m, p);
        case 0x054u: return js_compact_template_054(m, p);
        case 0x055u: return js_compact_template_055(m, p);
        case 0x056u: return js_compact_template_056(m, p);
        case 0x057u: return js_compact_template_057(m, p);
        case 0x058u: return js_compact_template_058(m, p);
        case 0x059u: return js_compact_template_059(m, p);
        case 0x05Au: return js_compact_template_05A(m, p);
        case 0x05Bu: return js_compact_template_05B(m, p);
        case 0x05Cu: return js_compact_template_05C(m, p);
        case 0x05Du: return js_compact_template_05D(m, p);
        case 0x05Eu: return js_compact_template_05E(m, p);
        case 0x05Fu: return js_compact_template_05F(m, p);
        case 0x060u: return js_compact_template_060(m, p);
        case 0x061u: return js_compact_template_061(m, p);
        case 0x062u: return js_compact_template_062(m, p);
        case 0x063u: return js_compact_template_063(m, p);
        case 0x064u: return js_compact_template_064(m, p);
        case 0x065u: return js_compact_template_065(m, p);
        case 0x066u: return js_compact_template_066(m, p);
        case 0x067u: return js_compact_template_067(m, p);
        case 0x068u: return js_compact_template_068(m, p);
        case 0x069u: return js_compact_template_069(m, p);
        case 0x06Au: return js_compact_template_06A(m, p);
        case 0x06Bu: return js_compact_template_06B(m, p);
        case 0x06Cu: return js_compact_template_06C(m, p);
        case 0x06Du: return js_compact_template_06D(m, p);
        case 0x06Eu: return js_compact_template_06E(m, p);
        case 0x06Fu: return js_compact_template_06F(m, p);
        case 0x070u: return js_compact_template_070(m, p);
        case 0x071u: return js_compact_template_071(m, p);
        case 0x072u: return js_compact_template_072(m, p);
        case 0x073u: return js_compact_template_073(m, p);
        case 0x074u: return js_compact_template_074(m, p);
        case 0x075u: return js_compact_template_075(m, p);
        case 0x076u: return js_compact_template_076(m, p);
        case 0x077u: return js_compact_template_077(m, p);
        case 0x078u: return js_compact_template_078(m, p);
        case 0x079u: return js_compact_template_079(m, p);
        case 0x07Au: return js_compact_template_07A(m, p);
        case 0x07Bu: return js_compact_template_07B(m, p);
        case 0x07Cu: return js_compact_template_07C(m, p);
        case 0x07Du: return js_compact_template_07D(m, p);
        case 0x07Eu: return js_compact_template_07E(m, p);
        case 0x07Fu: return js_compact_template_07F(m, p);
        case 0x080u: return js_compact_template_080(m, p);
        case 0x081u: return js_compact_template_081(m, p);
        case 0x082u: return js_compact_template_082(m, p);
        case 0x083u: return js_compact_template_083(m, p);
        case 0x084u: return js_compact_template_084(m, p);
        case 0x085u: return js_compact_template_085(m, p);
        case 0x086u: return js_compact_template_086(m, p);
        case 0x087u: return js_compact_template_087(m, p);
        case 0x088u: return js_compact_template_088(m, p);
        case 0x089u: return js_compact_template_089(m, p);
        case 0x08Au: return js_compact_template_08A(m, p);
        case 0x08Bu: return js_compact_template_08B(m, p);
        case 0x08Cu: return js_compact_template_08C(m, p);
        case 0x08Du: return js_compact_template_08D(m, p);
        case 0x08Eu: return js_compact_template_08E(m, p);
        case 0x08Fu: return js_compact_template_08F(m, p);
        case 0x090u: return js_compact_template_090(m, p);
        case 0x091u: return js_compact_template_091(m, p);
        case 0x092u: return js_compact_template_092(m, p);
        case 0x093u: return js_compact_template_093(m, p);
        case 0x094u: return js_compact_template_094(m, p);
        case 0x095u: return js_compact_template_095(m, p);
        case 0x096u: return js_compact_template_096(m, p);
        case 0x097u: return js_compact_template_097(m, p);
        case 0x098u: return js_compact_template_098(m, p);
        case 0x099u: return js_compact_template_099(m, p);
        case 0x09Au: return js_compact_template_09A(m, p);
        case 0x09Bu: return js_compact_template_09B(m, p);
        case 0x09Cu: return js_compact_template_09C(m, p);
        case 0x09Du: return js_compact_template_09D(m, p);
        case 0x09Eu: return js_compact_template_09E(m, p);
        case 0x09Fu: return js_compact_template_09F(m, p);
        case 0x0A0u: return js_compact_template_0A0(m, p);
        case 0x0A1u: return js_compact_template_0A1(m, p);
        case 0x0A2u: return js_compact_template_0A2(m, p);
        case 0x0A3u: return js_compact_template_0A3(m, p);
        case 0x0A4u: return js_compact_template_0A4(m, p);
        case 0x0A5u: return js_compact_template_0A5(m, p);
        case 0x0A6u: return js_compact_template_0A6(m, p);
        case 0x0A7u: return js_compact_template_0A7(m, p);
        case 0x0A8u: return js_compact_template_0A8(m, p);
        case 0x0A9u: return js_compact_template_0A9(m, p);
        case 0x0AAu: return js_compact_template_0AA(m, p);
        case 0x0ABu: return js_compact_template_0AB(m, p);
        case 0x0ACu: return js_compact_template_0AC(m, p);
        case 0x0ADu: return js_compact_template_0AD(m, p);
        case 0x0AEu: return js_compact_template_0AE(m, p);
        case 0x0AFu: return js_compact_template_0AF(m, p);
        case 0x0B0u: return js_compact_template_0B0(m, p);
        case 0x0B1u: return js_compact_template_0B1(m, p);
        case 0x0B2u: return js_compact_template_0B2(m, p);
        case 0x0B3u: return js_compact_template_0B3(m, p);
        case 0x0B4u: return js_compact_template_0B4(m, p);
        case 0x0B5u: return js_compact_template_0B5(m, p);
        case 0x0B6u: return js_compact_template_0B6(m, p);
        case 0x0B7u: return js_compact_template_0B7(m, p);
        case 0x0B8u: return js_compact_template_0B8(m, p);
        case 0x0B9u: return js_compact_template_0B9(m, p);
        case 0x0BAu: return js_compact_template_0BA(m, p);
        case 0x0BBu: return js_compact_template_0BB(m, p);
        case 0x0BCu: return js_compact_template_0BC(m, p);
        case 0x0BDu: return js_compact_template_0BD(m, p);
        case 0x0BEu: return js_compact_template_0BE(m, p);
        case 0x0BFu: return js_compact_template_0BF(m, p);
        case 0x0C0u: return js_compact_template_0C0(m, p);
        case 0x0C1u: return js_compact_template_0C1(m, p);
        case 0x0C2u: return js_compact_template_0C2(m, p);
        case 0x0C3u: return js_compact_template_0C3(m, p);
        case 0x0C4u: return js_compact_template_0C4(m, p);
        case 0x0C5u: return js_compact_template_0C5(m, p);
        case 0x0C6u: return js_compact_template_0C6(m, p);
        case 0x0C7u: return js_compact_template_0C7(m, p);
        case 0x0C8u: return js_compact_template_0C8(m, p);
        case 0x0C9u: return js_compact_template_0C9(m, p);
        case 0x0CAu: return js_compact_template_0CA(m, p);
        case 0x0CBu: return js_compact_template_0CB(m, p);
        case 0x0CCu: return js_compact_template_0CC(m, p);
        case 0x0CDu: return js_compact_template_0CD(m, p);
        case 0x0CEu: return js_compact_template_0CE(m, p);
        case 0x0CFu: return js_compact_template_0CF(m, p);
        case 0x0D0u: return js_compact_template_0D0(m, p);
        case 0x0D1u: return js_compact_template_0D1(m, p);
        case 0x0D2u: return js_compact_template_0D2(m, p);
        case 0x0D3u: return js_compact_template_0D3(m, p);
        case 0x0D4u: return js_compact_template_0D4(m, p);
        case 0x0D5u: return js_compact_template_0D5(m, p);
        case 0x0D6u: return js_compact_template_0D6(m, p);
        case 0x0D7u: return js_compact_template_0D7(m, p);
        case 0x0D8u: return js_compact_template_0D8(m, p);
        case 0x0D9u: return js_compact_template_0D9(m, p);
        case 0x0DAu: return js_compact_template_0DA(m, p);
        default: return JS_STOP_UNKNOWN_STATIC_CONTEXT;
    }
}
