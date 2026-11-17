/* Offline immutable-ROM alternate-vehicle closure. No runtime decoding. */
#include "static_core_compact_generated.h"
#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_v10_3_internal.h"
#include "jungle/cpu_v10_27_internal.h"
#include "jungle/cpu_v10_36_internal.h"
#include "jungle/cpu_v10_45_internal.h"
#include "jungle/cpu_dispatch_v10_100.h"
#include "jungle/status_v10_11.h"
#include "jungle/vehicle_closure.h"
/* 80:B055:E0M0X0 9CA80F STZ */
static js_stop_reason vehicle_body_0(js_machine_v05c *m) {
    /* 80:B055:E0M0X0 9CA80F STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xA8u, 0x0Fu };
    r = js_v05c_guard_code(m, 12373u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FA8u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB058u,0u,0u,0u));
}
/* 80:B058:E0M0X0 A608 LDX */
static js_stop_reason vehicle_body_1(js_machine_v05c *m) {
    /* 80:B058:E0M0X0 A608 LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0x08u };
    r = js_v05c_guard_code(m, 12376u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x08u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB05Au,0u,0u,0u));
}
/* 80:B05A:E0M0X0 9CA211 STZ */
static js_stop_reason vehicle_body_2(js_machine_v05c *m) {
    /* 80:B05A:E0M0X0 9CA211 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xA2u, 0x11u };
    r = js_v05c_guard_code(m, 12378u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A2u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB05Du,0u,0u,0u));
}
/* 80:B05D:E0M0X0 A576 LDA */
static js_stop_reason vehicle_body_3(js_machine_v05c *m) {
    /* 80:B05D:E0M0X0 A576 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x76u };
    r = js_v05c_guard_code(m, 12381u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x76u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB05Fu,0u,0u,0u));
}
/* 80:B05F:E0M0X0 C91400 CMP */
static js_stop_reason vehicle_body_4(js_machine_v05c *m) {
    /* 80:B05F:E0M0X0 C91400 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x14u, 0x00u };
    r = js_v05c_guard_code(m, 12383u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0014u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB062u,0u,0u,0u));
}
/* 80:B062:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_5(js_machine_v05c *m) {
    /* 80:B062:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 12386u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB067u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB064u,0u,0u,0u));
}
/* 80:B064:E0M0X0 CEA211 DEC */
static js_stop_reason vehicle_body_6(js_machine_v05c *m) {
    /* 80:B064:E0M0X0 CEA211 DEC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xCEu, 0xA2u, 0x11u };
    r = js_v05c_guard_code(m, 12388u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A2u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, -1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB067u,0u,0u,0u));
}
/* 80:B067:E0M0X0 9CE00F STZ */
static js_stop_reason vehicle_body_7(js_machine_v05c *m) {
    /* 80:B067:E0M0X0 9CE00F STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xE0u, 0x0Fu };
    r = js_v05c_guard_code(m, 12391u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FE0u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB06Au,0u,0u,0u));
}
/* 80:B06A:E0M0X0 A9C000 LDA */
static js_stop_reason vehicle_body_8(js_machine_v05c *m) {
    /* 80:B06A:E0M0X0 A9C000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xC0u, 0x00u };
    r = js_v05c_guard_code(m, 12394u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00C0u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB06Du,0u,0u,0u));
}
/* 80:B06D:E0M0X0 8DE20F STA */
static js_stop_reason vehicle_body_9(js_machine_v05c *m) {
    /* 80:B06D:E0M0X0 8DE20F STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xE2u, 0x0Fu };
    r = js_v05c_guard_code(m, 12397u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FE2u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB070u,0u,0u,0u));
}
/* 80:B070:E0M0X0 A9489B LDA */
static js_stop_reason vehicle_body_10(js_machine_v05c *m) {
    /* 80:B070:E0M0X0 A9489B LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x48u, 0x9Bu };
    r = js_v05c_guard_code(m, 12400u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x9B48u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB073u,0u,0u,0u));
}
/* 80:B073:E0M0X0 8DA411 STA */
static js_stop_reason vehicle_body_11(js_machine_v05c *m) {
    /* 80:B073:E0M0X0 8DA411 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xA4u, 0x11u };
    r = js_v05c_guard_code(m, 12403u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A4u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB076u,0u,0u,0u));
}
/* 80:B076:E0M0X0 A966BF LDA */
static js_stop_reason vehicle_body_12(js_machine_v05c *m) {
    /* 80:B076:E0M0X0 A966BF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x66u, 0xBFu };
    r = js_v05c_guard_code(m, 12406u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xBF66u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB079u,0u,0u,0u));
}
/* 80:B079:E0M0X0 851C STA */
static js_stop_reason vehicle_body_13(js_machine_v05c *m) {
    /* 80:B079:E0M0X0 851C STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Cu };
    r = js_v05c_guard_code(m, 12409u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Cu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB07Bu,0u,0u,0u));
}
/* 80:B07B:E0M0X0 AD7C11 LDA */
static js_stop_reason vehicle_body_14(js_machine_v05c *m) {
    /* 80:B07B:E0M0X0 AD7C11 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x7Cu, 0x11u };
    r = js_v05c_guard_code(m, 12411u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x117Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB07Eu,0u,0u,0u));
}
/* 80:B07E:E0M0X0 9D4E00 STA */
static js_stop_reason vehicle_body_15(js_machine_v05c *m) {
    /* 80:B07E:E0M0X0 9D4E00 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x4Eu, 0x00u };
    r = js_v05c_guard_code(m, 12414u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x004Eu);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB081u,0u,0u,0u));
}
/* 80:B081:E0M0X0 A572 LDA */
static js_stop_reason vehicle_body_16(js_machine_v05c *m) {
    /* 80:B081:E0M0X0 A572 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x72u };
    r = js_v05c_guard_code(m, 12417u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x72u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB083u,0u,0u,0u));
}
/* 80:B083:E0M0X0 290400 AND */
static js_stop_reason vehicle_body_17(js_machine_v05c *m) {
    /* 80:B083:E0M0X0 290400 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 12419u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x0004u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB086u,0u,0u,0u));
}
/* 80:B086:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_18(js_machine_v05c *m) {
    /* 80:B086:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 12422u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB08Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB088u,0u,0u,0u));
}
/* 80:B088:E0M0X0 4CBAAC JMP */
static js_stop_reason vehicle_body_19(js_machine_v05c *m) {
    /* 80:B088:E0M0X0 4CBAAC JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xBAu, 0xACu };
    r = js_v05c_guard_code(m, 12424u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xACBAu,0u,0u,0u));
}
/* 80:B08B:E0M0X0 A0157F LDY */
static js_stop_reason vehicle_body_20(js_machine_v05c *m) {
    /* 80:B08B:E0M0X0 A0157F LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x15u, 0x7Fu };
    r = js_v05c_guard_code(m, 12427u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x7F15u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB08Eu,0u,0u,0u));
}
/* 80:B08E:E0M0X0 4C48B1 JMP */
static js_stop_reason vehicle_body_21(js_machine_v05c *m) {
    /* 80:B08E:E0M0X0 4C48B1 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x48u, 0xB1u };
    r = js_v05c_guard_code(m, 12430u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB148u,0u,0u,0u));
}
/* 80:B091:E0M0X0 A608 LDX */
static js_stop_reason vehicle_body_22(js_machine_v05c *m) {
    /* 80:B091:E0M0X0 A608 LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0x08u };
    r = js_v05c_guard_code(m, 12433u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x08u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB093u,0u,0u,0u));
}
/* 80:B093:E0M0X0 AF760000 LDA */
static js_stop_reason vehicle_body_23(js_machine_v05c *m) {
    /* 80:B093:E0M0X0 AF760000 LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0x76u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 12435u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x000076u;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB097u,0u,0u,0u));
}
/* 80:B097:E0M0X0 C90400 CMP */
static js_stop_reason vehicle_body_24(js_machine_v05c *m) {
    /* 80:B097:E0M0X0 C90400 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 12439u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0004u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB09Au,0u,0u,0u));
}
/* 80:B09A:E0M0X0 D003 BNE */
static js_stop_reason vehicle_body_25(js_machine_v05c *m) {
    /* 80:B09A:E0M0X0 D003 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x03u };
    r = js_v05c_guard_code(m, 12442u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB09Fu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB09Cu,0u,0u,0u));
}
/* 80:B09C:E0M0X0 9CE00F STZ */
static js_stop_reason vehicle_body_26(js_machine_v05c *m) {
    /* 80:B09C:E0M0X0 9CE00F STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xE0u, 0x0Fu };
    r = js_v05c_guard_code(m, 12444u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FE0u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB09Fu,0u,0u,0u));
}
/* 80:B09F:E0M0X0 9CA211 STZ */
static js_stop_reason vehicle_body_27(js_machine_v05c *m) {
    /* 80:B09F:E0M0X0 9CA211 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xA2u, 0x11u };
    r = js_v05c_guard_code(m, 12447u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A2u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0A2u,0u,0u,0u));
}
/* 80:B0A2:E0M0X0 9CA411 STZ */
static js_stop_reason vehicle_body_28(js_machine_v05c *m) {
    /* 80:B0A2:E0M0X0 9CA411 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xA4u, 0x11u };
    r = js_v05c_guard_code(m, 12450u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A4u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0A5u,0u,0u,0u));
}
/* 80:B0A5:E0M0X0 A916C1 LDA */
static js_stop_reason vehicle_body_29(js_machine_v05c *m) {
    /* 80:B0A5:E0M0X0 A916C1 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x16u, 0xC1u };
    r = js_v05c_guard_code(m, 12453u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xC116u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0A8u,0u,0u,0u));
}
/* 80:B0A8:E0M0X0 851C STA */
static js_stop_reason vehicle_body_30(js_machine_v05c *m) {
    /* 80:B0A8:E0M0X0 851C STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Cu };
    r = js_v05c_guard_code(m, 12456u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Cu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0AAu,0u,0u,0u));
}
/* 80:B0AA:E0M0X0 A99105 LDA */
static js_stop_reason vehicle_body_31(js_machine_v05c *m) {
    /* 80:B0AA:E0M0X0 A99105 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x91u, 0x05u };
    r = js_v05c_guard_code(m, 12458u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0591u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0ADu,0u,0u,0u));
}
/* 80:B0AD:E0M0X0 8DB441 STA */
static js_stop_reason vehicle_body_32(js_machine_v05c *m) {
    /* 80:B0AD:E0M0X0 8DB441 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xB4u, 0x41u };
    r = js_v05c_guard_code(m, 12461u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x41B4u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0B0u,0u,0u,0u));
}
/* 80:B0B0:E0M0X0 A576 LDA */
static js_stop_reason vehicle_body_33(js_machine_v05c *m) {
    /* 80:B0B0:E0M0X0 A576 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x76u };
    r = js_v05c_guard_code(m, 12464u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x76u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0B2u,0u,0u,0u));
}
/* 80:B0B2:E0M0X0 C90400 CMP */
static js_stop_reason vehicle_body_34(js_machine_v05c *m) {
    /* 80:B0B2:E0M0X0 C90400 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 12466u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0004u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0B5u,0u,0u,0u));
}
/* 80:B0B5:E0M0X0 D044 BNE */
static js_stop_reason vehicle_body_35(js_machine_v05c *m) {
    /* 80:B0B5:E0M0X0 D044 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x44u };
    r = js_v05c_guard_code(m, 12469u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0B7u,0u,0u,0u));
}
/* 80:B0B7:E0M0X0 A536 LDA */
static js_stop_reason vehicle_body_36(js_machine_v05c *m) {
    /* 80:B0B7:E0M0X0 A536 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x36u };
    r = js_v05c_guard_code(m, 12471u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x36u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0B9u,0u,0u,0u));
}
/* 80:B0B9:E0M0X0 890100 BIT */
static js_stop_reason vehicle_body_37(js_machine_v05c *m) {
    /* 80:B0B9:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 12473u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0BCu,0u,0u,0u));
}
/* 80:B0BC:E0M0X0 F01D BEQ */
static js_stop_reason vehicle_body_38(js_machine_v05c *m) {
    /* 80:B0BC:E0M0X0 F01D BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x1Du };
    r = js_v05c_guard_code(m, 12476u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0DBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0BEu,0u,0u,0u));
}
/* 80:B0BE:E0M0X0 AD7841 LDA */
static js_stop_reason vehicle_body_39(js_machine_v05c *m) {
    /* 80:B0BE:E0M0X0 AD7841 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12478u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0C1u,0u,0u,0u));
}
/* 80:B0C1:E0M0X0 C9F2FF CMP */
static js_stop_reason vehicle_body_40(js_machine_v05c *m) {
    /* 80:B0C1:E0M0X0 C9F2FF CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xF2u, 0xFFu };
    r = js_v05c_guard_code(m, 12481u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0xFFF2u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0C4u,0u,0u,0u));
}
/* 80:B0C4:E0M0X0 F035 BEQ */
static js_stop_reason vehicle_body_41(js_machine_v05c *m) {
    /* 80:B0C4:E0M0X0 F035 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x35u };
    r = js_v05c_guard_code(m, 12484u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0C6u,0u,0u,0u));
}
/* 80:B0C6:E0M0X0 A90045 LDA */
static js_stop_reason vehicle_body_42(js_machine_v05c *m) {
    /* 80:B0C6:E0M0X0 A90045 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x45u };
    r = js_v05c_guard_code(m, 12486u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x4500u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0C9u,0u,0u,0u));
}
/* 80:B0C9:E0M0X0 18 CLC */
static js_stop_reason vehicle_body_43(js_machine_v05c *m) {
    /* 80:B0C9:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 12489u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0CAu,0u,0u,0u));
}
/* 80:B0CA:E0M0X0 6D7641 ADC */
static js_stop_reason vehicle_body_44(js_machine_v05c *m) {
    /* 80:B0CA:E0M0X0 6D7641 ADC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x6Du, 0x76u, 0x41u };
    r = js_v05c_guard_code(m, 12490u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4176u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0CDu,0u,0u,0u));
}
/* 80:B0CD:E0M0X0 8D7641 STA */
static js_stop_reason vehicle_body_45(js_machine_v05c *m) {
    /* 80:B0CD:E0M0X0 8D7641 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x76u, 0x41u };
    r = js_v05c_guard_code(m, 12493u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4176u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0D0u,0u,0u,0u));
}
/* 80:B0D0:E0M0X0 A90000 LDA */
static js_stop_reason vehicle_body_46(js_machine_v05c *m) {
    /* 80:B0D0:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 12496u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0D3u,0u,0u,0u));
}
/* 80:B0D3:E0M0X0 6D7841 ADC */
static js_stop_reason vehicle_body_47(js_machine_v05c *m) {
    /* 80:B0D3:E0M0X0 6D7841 ADC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x6Du, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12499u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0D6u,0u,0u,0u));
}
/* 80:B0D6:E0M0X0 8D7841 STA */
static js_stop_reason vehicle_body_48(js_machine_v05c *m) {
    /* 80:B0D6:E0M0X0 8D7841 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12502u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0D9u,0u,0u,0u));
}
/* 80:B0D9:E0M0X0 8020 BRA */
static js_stop_reason vehicle_body_49(js_machine_v05c *m) {
    /* 80:B0D9:E0M0X0 8020 BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0x20u };
    r = js_v05c_guard_code(m, 12505u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
}
/* 80:B0DB:E0M0X0 890200 BIT */
static js_stop_reason vehicle_body_50(js_machine_v05c *m) {
    /* 80:B0DB:E0M0X0 890200 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 12507u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0002u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0DEu,0u,0u,0u));
}
/* 80:B0DE:E0M0X0 F01B BEQ */
static js_stop_reason vehicle_body_51(js_machine_v05c *m) {
    /* 80:B0DE:E0M0X0 F01B BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x1Bu };
    r = js_v05c_guard_code(m, 12510u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0E0u,0u,0u,0u));
}
/* 80:B0E0:E0M0X0 AD7841 LDA */
static js_stop_reason vehicle_body_52(js_machine_v05c *m) {
    /* 80:B0E0:E0M0X0 AD7841 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12512u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0E3u,0u,0u,0u));
}
/* 80:B0E3:E0M0X0 C9E0FF CMP */
static js_stop_reason vehicle_body_53(js_machine_v05c *m) {
    /* 80:B0E3:E0M0X0 C9E0FF CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xE0u, 0xFFu };
    r = js_v05c_guard_code(m, 12515u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0xFFE0u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0E6u,0u,0u,0u));
}
/* 80:B0E6:E0M0X0 9013 BCC */
static js_stop_reason vehicle_body_54(js_machine_v05c *m) {
    /* 80:B0E6:E0M0X0 9013 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x13u };
    r = js_v05c_guard_code(m, 12518u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0E8u,0u,0u,0u));
}
/* 80:B0E8:E0M0X0 AD7641 LDA */
static js_stop_reason vehicle_body_55(js_machine_v05c *m) {
    /* 80:B0E8:E0M0X0 AD7641 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x76u, 0x41u };
    r = js_v05c_guard_code(m, 12520u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4176u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0EBu,0u,0u,0u));
}
/* 80:B0EB:E0M0X0 38 SEC */
static js_stop_reason vehicle_body_56(js_machine_v05c *m) {
    /* 80:B0EB:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 12523u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0ECu,0u,0u,0u));
}
/* 80:B0EC:E0M0X0 E90045 SBC */
static js_stop_reason vehicle_body_57(js_machine_v05c *m) {
    /* 80:B0EC:E0M0X0 E90045 SBC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE9u, 0x00u, 0x45u };
    r = js_v05c_guard_code(m, 12524u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x4500u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0EFu,0u,0u,0u));
}
/* 80:B0EF:E0M0X0 8D7641 STA */
static js_stop_reason vehicle_body_58(js_machine_v05c *m) {
    /* 80:B0EF:E0M0X0 8D7641 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x76u, 0x41u };
    r = js_v05c_guard_code(m, 12527u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4176u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0F2u,0u,0u,0u));
}
/* 80:B0F2:E0M0X0 AD7841 LDA */
static js_stop_reason vehicle_body_59(js_machine_v05c *m) {
    /* 80:B0F2:E0M0X0 AD7841 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12530u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0F5u,0u,0u,0u));
}
/* 80:B0F5:E0M0X0 E90000 SBC */
static js_stop_reason vehicle_body_60(js_machine_v05c *m) {
    /* 80:B0F5:E0M0X0 E90000 SBC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 12533u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0000u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0F8u,0u,0u,0u));
}
/* 80:B0F8:E0M0X0 8D7841 STA */
static js_stop_reason vehicle_body_61(js_machine_v05c *m) {
    /* 80:B0F8:E0M0X0 8D7841 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x78u, 0x41u };
    r = js_v05c_guard_code(m, 12536u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x4178u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FBu,0u,0u,0u));
}
/* 80:B0FB:E0M0X0 A572 LDA */
static js_stop_reason vehicle_body_62(js_machine_v05c *m) {
    /* 80:B0FB:E0M0X0 A572 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x72u };
    r = js_v05c_guard_code(m, 12539u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x72u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB0FDu,0u,0u,0u));
}
/* 80:B0FD:E0M0X0 291F00 AND */
static js_stop_reason vehicle_body_63(js_machine_v05c *m) {
    /* 80:B0FD:E0M0X0 291F00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x1Fu, 0x00u };
    r = js_v05c_guard_code(m, 12541u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x001Fu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB100u,0u,0u,0u));
}
/* 80:B100:E0M0X0 D067 BNE */
static js_stop_reason vehicle_body_64(js_machine_v05c *m) {
    /* 80:B100:E0M0X0 D067 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x67u };
    r = js_v05c_guard_code(m, 12544u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB169u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB102u,0u,0u,0u));
}
/* 80:B102:E0M0X0 A0147F LDY */
static js_stop_reason vehicle_body_65(js_machine_v05c *m) {
    /* 80:B102:E0M0X0 A0147F LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x14u, 0x7Fu };
    r = js_v05c_guard_code(m, 12546u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x7F14u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB105u,0u,0u,0u));
}
/* 80:B105:E0M0X0 8041 BRA */
static js_stop_reason vehicle_body_66(js_machine_v05c *m) {
    /* 80:B105:E0M0X0 8041 BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0x41u };
    r = js_v05c_guard_code(m, 12549u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB148u,0u,0u,0u));
}
/* 80:B107:E0M0X0 A608 LDX */
static js_stop_reason vehicle_body_67(js_machine_v05c *m) {
    /* 80:B107:E0M0X0 A608 LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0x08u };
    r = js_v05c_guard_code(m, 12551u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x08u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB109u,0u,0u,0u));
}
/* 80:B109:E0M0X0 A9FFFF LDA */
static js_stop_reason vehicle_body_68(js_machine_v05c *m) {
    /* 80:B109:E0M0X0 A9FFFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 12553u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB10Cu,0u,0u,0u));
}
/* 80:B10C:E0M0X0 8DE00F STA */
static js_stop_reason vehicle_body_69(js_machine_v05c *m) {
    /* 80:B10C:E0M0X0 8DE00F STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xE0u, 0x0Fu };
    r = js_v05c_guard_code(m, 12556u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FE0u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB10Fu,0u,0u,0u));
}
/* 80:B10F:E0M0X0 8DA211 STA */
static js_stop_reason vehicle_body_70(js_machine_v05c *m) {
    /* 80:B10F:E0M0X0 8DA211 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xA2u, 0x11u };
    r = js_v05c_guard_code(m, 12559u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A2u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB112u,0u,0u,0u));
}
/* 80:B112:E0M0X0 A9089C LDA */
static js_stop_reason vehicle_body_71(js_machine_v05c *m) {
    /* 80:B112:E0M0X0 A9089C LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x08u, 0x9Cu };
    r = js_v05c_guard_code(m, 12562u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x9C08u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB115u,0u,0u,0u));
}
/* 80:B115:E0M0X0 8DA411 STA */
static js_stop_reason vehicle_body_72(js_machine_v05c *m) {
    /* 80:B115:E0M0X0 8DA411 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xA4u, 0x11u };
    r = js_v05c_guard_code(m, 12565u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x11A4u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB118u,0u,0u,0u));
}
/* 80:B118:E0M0X0 A9C000 LDA */
static js_stop_reason vehicle_body_73(js_machine_v05c *m) {
    /* 80:B118:E0M0X0 A9C000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xC0u, 0x00u };
    r = js_v05c_guard_code(m, 12568u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00C0u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB11Bu,0u,0u,0u));
}
/* 80:B11B:E0M0X0 8DE20F STA */
static js_stop_reason vehicle_body_74(js_machine_v05c *m) {
    /* 80:B11B:E0M0X0 8DE20F STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xE2u, 0x0Fu };
    r = js_v05c_guard_code(m, 12571u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FE2u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB11Eu,0u,0u,0u));
}
/* 80:B11E:E0M0X0 A9B6BD LDA */
static js_stop_reason vehicle_body_75(js_machine_v05c *m) {
    /* 80:B11E:E0M0X0 A9B6BD LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xB6u, 0xBDu };
    r = js_v05c_guard_code(m, 12574u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xBDB6u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB121u,0u,0u,0u));
}
/* 80:B121:E0M0X0 851C STA */
static js_stop_reason vehicle_body_76(js_machine_v05c *m) {
    /* 80:B121:E0M0X0 851C STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Cu };
    r = js_v05c_guard_code(m, 12577u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Cu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB123u,0u,0u,0u));
}
/* 80:B123:E0M0X0 A00000 LDY */
static js_stop_reason vehicle_body_77(js_machine_v05c *m) {
    /* 80:B123:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 12579u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB126u,0u,0u,0u));
}
/* 80:B126:E0M0X0 BD1E00 LDA */
static js_stop_reason vehicle_body_78(js_machine_v05c *m) {
    /* 80:B126:E0M0X0 BD1E00 LDA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBDu, 0x1Eu, 0x00u };
    r = js_v05c_guard_code(m, 12582u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x001Eu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB129u,0u,0u,0u));
}
/* 80:B129:E0M0X0 300A BMI */
static js_stop_reason vehicle_body_79(js_machine_v05c *m) {
    /* 80:B129:E0M0X0 300A BMI rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x30u, 0x0Au };
    r = js_v05c_guard_code(m, 12585u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_N) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB135u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB12Bu,0u,0u,0u));
}
/* 80:B12B:E0M0X0 C91000 CMP */
static js_stop_reason vehicle_body_80(js_machine_v05c *m) {
    /* 80:B12B:E0M0X0 C91000 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 12587u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0010u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB12Eu,0u,0u,0u));
}
/* 80:B12E:E0M0X0 900D BCC */
static js_stop_reason vehicle_body_81(js_machine_v05c *m) {
    /* 80:B12E:E0M0X0 900D BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Du };
    r = js_v05c_guard_code(m, 12590u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Du,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB130u,0u,0u,0u));
}
/* 80:B130:E0M0X0 A01800 LDY */
static js_stop_reason vehicle_body_82(js_machine_v05c *m) {
    /* 80:B130:E0M0X0 A01800 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x18u, 0x00u };
    r = js_v05c_guard_code(m, 12592u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0018u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB133u,0u,0u,0u));
}
/* 80:B133:E0M0X0 8008 BRA */
static js_stop_reason vehicle_body_83(js_machine_v05c *m) {
    /* 80:B133:E0M0X0 8008 BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0x08u };
    r = js_v05c_guard_code(m, 12595u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Du,0u,0u,0u));
}
/* 80:B135:E0M0X0 C9F0FF CMP */
static js_stop_reason vehicle_body_84(js_machine_v05c *m) {
    /* 80:B135:E0M0X0 C9F0FF CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xF0u, 0xFFu };
    r = js_v05c_guard_code(m, 12597u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0xFFF0u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB138u,0u,0u,0u));
}
/* 80:B138:E0M0X0 B003 BCS */
static js_stop_reason vehicle_body_85(js_machine_v05c *m) {
    /* 80:B138:E0M0X0 B003 BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x03u };
    r = js_v05c_guard_code(m, 12600u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Du,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Au,0u,0u,0u));
}
/* 80:B13A:E0M0X0 A03000 LDY */
static js_stop_reason vehicle_body_86(js_machine_v05c *m) {
    /* 80:B13A:E0M0X0 A03000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x30u, 0x00u };
    r = js_v05c_guard_code(m, 12602u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0030u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Du,0u,0u,0u));
}
/* 80:B13D:E0M0X0 98 TYA */
static js_stop_reason vehicle_body_87(js_machine_v05c *m) {
    /* 80:B13D:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 12605u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Eu,0u,0u,0u));
}
/* 80:B13E:E0M0X0 18 CLC */
static js_stop_reason vehicle_body_88(js_machine_v05c *m) {
    /* 80:B13E:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 12606u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB13Fu,0u,0u,0u));
}
/* 80:B13F:E0M0X0 69A404 ADC */
static js_stop_reason vehicle_body_89(js_machine_v05c *m) {
    /* 80:B13F:E0M0X0 69A404 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0xA4u, 0x04u };
    r = js_v05c_guard_code(m, 12607u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x04A4u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB142u,0u,0u,0u));
}
/* 80:B142:E0M0X0 9D4E00 STA */
static js_stop_reason vehicle_body_90(js_machine_v05c *m) {
    /* 80:B142:E0M0X0 9D4E00 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x4Eu, 0x00u };
    r = js_v05c_guard_code(m, 12610u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x004Eu);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB145u,0u,0u,0u));
}
/* 80:B145:E0M0X0 A0167F LDY */
static js_stop_reason vehicle_body_91(js_machine_v05c *m) {
    /* 80:B145:E0M0X0 A0167F LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x16u, 0x7Fu };
    r = js_v05c_guard_code(m, 12613u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x7F16u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xB148u,0u,0u,0u));
}
/* 80:C17B:E0M0X0 A90000 LDA */
static js_stop_reason vehicle_body_92(js_machine_v05c *m) {
    /* 80:C17B:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 16763u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC17Eu,0u,0u,0u));
}
/* 80:C17E:E0M0X0 8FB0117F STA */
static js_stop_reason vehicle_body_93(js_machine_v05c *m) {
    /* 80:C17E:E0M0X0 8FB0117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0xB0u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 16766u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F11B0u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC182u,0u,0u,0u));
}
/* 80:C182:E0M0X0 9CEE08 STZ */
static js_stop_reason vehicle_body_94(js_machine_v05c *m) {
    /* 80:C182:E0M0X0 9CEE08 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16770u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC185u,0u,0u,0u));
}
/* 80:C185:E0M0X0 A91400 LDA */
static js_stop_reason vehicle_body_95(js_machine_v05c *m) {
    /* 80:C185:E0M0X0 A91400 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x14u, 0x00u };
    r = js_v05c_guard_code(m, 16773u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0014u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC188u,0u,0u,0u));
}
/* 80:C188:E0M0X0 A0E191 LDY */
static js_stop_reason vehicle_body_96(js_machine_v05c *m) {
    /* 80:C188:E0M0X0 A0E191 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xE1u, 0x91u };
    r = js_v05c_guard_code(m, 16776u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x91E1u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC18Bu,0u,0u,0u));
}
/* 80:C18B:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_97(js_machine_v05c *m) {
    /* 80:C18B:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16779u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC18Du);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C18E:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_98(js_machine_v05c *m) {
    /* 80:C18E:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16782u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC19Cu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC190u,0u,0u,0u));
}
/* 80:C190:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_99(js_machine_v05c *m) {
    /* 80:C190:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16784u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC192u,0u,0u,0u));
}
/* 80:C192:E0M0X0 A52A LDA */
static js_stop_reason vehicle_body_100(js_machine_v05c *m) {
    /* 80:C192:E0M0X0 A52A LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x2Au };
    r = js_v05c_guard_code(m, 16786u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Au);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC194u,0u,0u,0u));
}
/* 80:C194:E0M0X0 294000 AND */
static js_stop_reason vehicle_body_101(js_machine_v05c *m) {
    /* 80:C194:E0M0X0 294000 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x40u, 0x00u };
    r = js_v05c_guard_code(m, 16788u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x0040u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC197u,0u,0u,0u));
}
/* 80:C197:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_102(js_machine_v05c *m) {
    /* 80:C197:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16791u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC19Cu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC199u,0u,0u,0u));
}
/* 80:C199:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_103(js_machine_v05c *m) {
    /* 80:C199:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16793u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C19C:E0M0X0 EEEE08 INC */
static js_stop_reason vehicle_body_104(js_machine_v05c *m) {
    /* 80:C19C:E0M0X0 EEEE08 INC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEEu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16796u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC19Fu,0u,0u,0u));
}
/* 80:C19F:E0M0X0 A91200 LDA */
static js_stop_reason vehicle_body_105(js_machine_v05c *m) {
    /* 80:C19F:E0M0X0 A91200 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x12u, 0x00u };
    r = js_v05c_guard_code(m, 16799u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0012u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1A2u,0u,0u,0u));
}
/* 80:C1A2:E0M0X0 A09592 LDY */
static js_stop_reason vehicle_body_106(js_machine_v05c *m) {
    /* 80:C1A2:E0M0X0 A09592 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x95u, 0x92u };
    r = js_v05c_guard_code(m, 16802u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x9295u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1A5u,0u,0u,0u));
}
/* 80:C1A5:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_107(js_machine_v05c *m) {
    /* 80:C1A5:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16805u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC1A7u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C1A8:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_108(js_machine_v05c *m) {
    /* 80:C1A8:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16808u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1B6u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1AAu,0u,0u,0u));
}
/* 80:C1AA:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_109(js_machine_v05c *m) {
    /* 80:C1AA:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16810u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1ACu,0u,0u,0u));
}
/* 80:C1AC:E0M0X0 A90040 LDA */
static js_stop_reason vehicle_body_110(js_machine_v05c *m) {
    /* 80:C1AC:E0M0X0 A90040 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x40u };
    r = js_v05c_guard_code(m, 16812u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x4000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1AFu,0u,0u,0u));
}
/* 80:C1AF:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_111(js_machine_v05c *m) {
    /* 80:C1AF:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 16815u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1B1u,0u,0u,0u));
}
/* 80:C1B1:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_112(js_machine_v05c *m) {
    /* 80:C1B1:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16817u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1B6u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1B3u,0u,0u,0u));
}
/* 80:C1B3:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_113(js_machine_v05c *m) {
    /* 80:C1B3:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16819u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C1B6:E0M0X0 A91000 LDA */
static js_stop_reason vehicle_body_114(js_machine_v05c *m) {
    /* 80:C1B6:E0M0X0 A91000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 16822u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0010u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1B9u,0u,0u,0u));
}
/* 80:C1B9:E0M0X0 A0B392 LDY */
static js_stop_reason vehicle_body_115(js_machine_v05c *m) {
    /* 80:C1B9:E0M0X0 A0B392 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xB3u, 0x92u };
    r = js_v05c_guard_code(m, 16825u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x92B3u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1BCu,0u,0u,0u));
}
/* 80:C1BC:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_116(js_machine_v05c *m) {
    /* 80:C1BC:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16828u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC1BEu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C1BF:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_117(js_machine_v05c *m) {
    /* 80:C1BF:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16831u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1CDu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1C1u,0u,0u,0u));
}
/* 80:C1C1:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_118(js_machine_v05c *m) {
    /* 80:C1C1:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16833u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1C3u,0u,0u,0u));
}
/* 80:C1C3:E0M0X0 A98000 LDA */
static js_stop_reason vehicle_body_119(js_machine_v05c *m) {
    /* 80:C1C3:E0M0X0 A98000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x80u, 0x00u };
    r = js_v05c_guard_code(m, 16835u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0080u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1C6u,0u,0u,0u));
}
/* 80:C1C6:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_120(js_machine_v05c *m) {
    /* 80:C1C6:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 16838u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1C8u,0u,0u,0u));
}
/* 80:C1C8:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_121(js_machine_v05c *m) {
    /* 80:C1C8:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16840u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1CDu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1CAu,0u,0u,0u));
}
/* 80:C1CA:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_122(js_machine_v05c *m) {
    /* 80:C1CA:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16842u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C1CE:E0M0X0 A90000 LDA */
static js_stop_reason vehicle_body_123(js_machine_v05c *m) {
    /* 80:C1CE:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 16846u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1D1u,0u,0u,0u));
}
/* 80:C1D1:E0M0X0 8FB0117F STA */
static js_stop_reason vehicle_body_124(js_machine_v05c *m) {
    /* 80:C1D1:E0M0X0 8FB0117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0xB0u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 16849u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F11B0u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1D5u,0u,0u,0u));
}
/* 80:C1D5:E0M0X0 9CEE08 STZ */
static js_stop_reason vehicle_body_125(js_machine_v05c *m) {
    /* 80:C1D5:E0M0X0 9CEE08 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16853u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1D8u,0u,0u,0u));
}
/* 80:C1D8:E0M0X0 A91400 LDA */
static js_stop_reason vehicle_body_126(js_machine_v05c *m) {
    /* 80:C1D8:E0M0X0 A91400 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x14u, 0x00u };
    r = js_v05c_guard_code(m, 16856u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0014u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1DBu,0u,0u,0u));
}
/* 80:C1DB:E0M0X0 A0EF92 LDY */
static js_stop_reason vehicle_body_127(js_machine_v05c *m) {
    /* 80:C1DB:E0M0X0 A0EF92 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xEFu, 0x92u };
    r = js_v05c_guard_code(m, 16859u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x92EFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1DEu,0u,0u,0u));
}
/* 80:C1DE:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_128(js_machine_v05c *m) {
    /* 80:C1DE:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16862u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC1E0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C1E1:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_129(js_machine_v05c *m) {
    /* 80:C1E1:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16865u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1EFu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1E3u,0u,0u,0u));
}
/* 80:C1E3:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_130(js_machine_v05c *m) {
    /* 80:C1E3:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16867u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1E5u,0u,0u,0u));
}
/* 80:C1E5:E0M0X0 A52A LDA */
static js_stop_reason vehicle_body_131(js_machine_v05c *m) {
    /* 80:C1E5:E0M0X0 A52A LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x2Au };
    r = js_v05c_guard_code(m, 16869u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Au);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1E7u,0u,0u,0u));
}
/* 80:C1E7:E0M0X0 294000 AND */
static js_stop_reason vehicle_body_132(js_machine_v05c *m) {
    /* 80:C1E7:E0M0X0 294000 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x40u, 0x00u };
    r = js_v05c_guard_code(m, 16871u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x0040u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1EAu,0u,0u,0u));
}
/* 80:C1EA:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_133(js_machine_v05c *m) {
    /* 80:C1EA:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16874u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1EFu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1ECu,0u,0u,0u));
}
/* 80:C1EC:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_134(js_machine_v05c *m) {
    /* 80:C1EC:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16876u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C1EF:E0M0X0 EEEE08 INC */
static js_stop_reason vehicle_body_135(js_machine_v05c *m) {
    /* 80:C1EF:E0M0X0 EEEE08 INC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEEu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16879u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1F2u,0u,0u,0u));
}
/* 80:C1F2:E0M0X0 A91200 LDA */
static js_stop_reason vehicle_body_136(js_machine_v05c *m) {
    /* 80:C1F2:E0M0X0 A91200 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x12u, 0x00u };
    r = js_v05c_guard_code(m, 16882u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0012u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1F5u,0u,0u,0u));
}
/* 80:C1F5:E0M0X0 A0D192 LDY */
static js_stop_reason vehicle_body_137(js_machine_v05c *m) {
    /* 80:C1F5:E0M0X0 A0D192 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xD1u, 0x92u };
    r = js_v05c_guard_code(m, 16885u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x92D1u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1F8u,0u,0u,0u));
}
/* 80:C1F8:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_138(js_machine_v05c *m) {
    /* 80:C1F8:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16888u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC1FAu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C1FB:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_139(js_machine_v05c *m) {
    /* 80:C1FB:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16891u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC209u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1FDu,0u,0u,0u));
}
/* 80:C1FD:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_140(js_machine_v05c *m) {
    /* 80:C1FD:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16893u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1FFu,0u,0u,0u));
}
/* 80:C1FF:E0M0X0 A90040 LDA */
static js_stop_reason vehicle_body_141(js_machine_v05c *m) {
    /* 80:C1FF:E0M0X0 A90040 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x40u };
    r = js_v05c_guard_code(m, 16895u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x4000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC202u,0u,0u,0u));
}
/* 80:C202:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_142(js_machine_v05c *m) {
    /* 80:C202:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 16898u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC204u,0u,0u,0u));
}
/* 80:C204:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_143(js_machine_v05c *m) {
    /* 80:C204:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16900u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC209u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC206u,0u,0u,0u));
}
/* 80:C206:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_144(js_machine_v05c *m) {
    /* 80:C206:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16902u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C209:E0M0X0 A91000 LDA */
static js_stop_reason vehicle_body_145(js_machine_v05c *m) {
    /* 80:C209:E0M0X0 A91000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 16905u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0010u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC20Cu,0u,0u,0u));
}
/* 80:C20C:E0M0X0 A0B392 LDY */
static js_stop_reason vehicle_body_146(js_machine_v05c *m) {
    /* 80:C20C:E0M0X0 A0B392 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xB3u, 0x92u };
    r = js_v05c_guard_code(m, 16908u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x92B3u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC20Fu,0u,0u,0u));
}
/* 80:C20F:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_147(js_machine_v05c *m) {
    /* 80:C20F:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16911u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC211u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C212:E0M0X0 90B9 BCC */
static js_stop_reason vehicle_body_148(js_machine_v05c *m) {
    /* 80:C212:E0M0X0 90B9 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0xB9u };
    r = js_v05c_guard_code(m, 16914u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1CDu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC214u,0u,0u,0u));
}
/* 80:C214:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_149(js_machine_v05c *m) {
    /* 80:C214:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16916u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC216u,0u,0u,0u));
}
/* 80:C216:E0M0X0 A98000 LDA */
static js_stop_reason vehicle_body_150(js_machine_v05c *m) {
    /* 80:C216:E0M0X0 A98000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x80u, 0x00u };
    r = js_v05c_guard_code(m, 16918u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0080u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC219u,0u,0u,0u));
}
/* 80:C219:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_151(js_machine_v05c *m) {
    /* 80:C219:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 16921u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC21Bu,0u,0u,0u));
}
/* 80:C21B:E0M0X0 F0B0 BEQ */
static js_stop_reason vehicle_body_152(js_machine_v05c *m) {
    /* 80:C21B:E0M0X0 F0B0 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0xB0u };
    r = js_v05c_guard_code(m, 16923u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC1CDu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC21Du,0u,0u,0u));
}
/* 80:C21D:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_153(js_machine_v05c *m) {
    /* 80:C21D:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16925u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C220:E0M0X0 A9FFFF LDA */
static js_stop_reason vehicle_body_154(js_machine_v05c *m) {
    /* 80:C220:E0M0X0 A9FFFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 16928u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC223u,0u,0u,0u));
}
/* 80:C223:E0M0X0 8FB0117F STA */
static js_stop_reason vehicle_body_155(js_machine_v05c *m) {
    /* 80:C223:E0M0X0 8FB0117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0xB0u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 16931u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F11B0u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC227u,0u,0u,0u));
}
/* 80:C227:E0M0X0 9CEE08 STZ */
static js_stop_reason vehicle_body_156(js_machine_v05c *m) {
    /* 80:C227:E0M0X0 9CEE08 STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16935u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC22Au,0u,0u,0u));
}
/* 80:C22A:E0M0X0 A91400 LDA */
static js_stop_reason vehicle_body_157(js_machine_v05c *m) {
    /* 80:C22A:E0M0X0 A91400 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x14u, 0x00u };
    r = js_v05c_guard_code(m, 16938u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0014u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC22Du,0u,0u,0u));
}
/* 80:C22D:E0M0X0 A01D92 LDY */
static js_stop_reason vehicle_body_158(js_machine_v05c *m) {
    /* 80:C22D:E0M0X0 A01D92 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x1Du, 0x92u };
    r = js_v05c_guard_code(m, 16941u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x921Du, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC230u,0u,0u,0u));
}
/* 80:C230:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_159(js_machine_v05c *m) {
    /* 80:C230:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16944u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC232u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C233:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_160(js_machine_v05c *m) {
    /* 80:C233:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16947u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC241u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC235u,0u,0u,0u));
}
/* 80:C235:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_161(js_machine_v05c *m) {
    /* 80:C235:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16949u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC237u,0u,0u,0u));
}
/* 80:C237:E0M0X0 A52A LDA */
static js_stop_reason vehicle_body_162(js_machine_v05c *m) {
    /* 80:C237:E0M0X0 A52A LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x2Au };
    r = js_v05c_guard_code(m, 16951u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Au);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC239u,0u,0u,0u));
}
/* 80:C239:E0M0X0 294000 AND */
static js_stop_reason vehicle_body_163(js_machine_v05c *m) {
    /* 80:C239:E0M0X0 294000 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x40u, 0x00u };
    r = js_v05c_guard_code(m, 16953u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x0040u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC23Cu,0u,0u,0u));
}
/* 80:C23C:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_164(js_machine_v05c *m) {
    /* 80:C23C:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16956u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC241u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC23Eu,0u,0u,0u));
}
/* 80:C23E:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_165(js_machine_v05c *m) {
    /* 80:C23E:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16958u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C241:E0M0X0 EEEE08 INC */
static js_stop_reason vehicle_body_166(js_machine_v05c *m) {
    /* 80:C241:E0M0X0 EEEE08 INC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEEu, 0xEEu, 0x08u };
    r = js_v05c_guard_code(m, 16961u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08EEu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC244u,0u,0u,0u));
}
/* 80:C244:E0M0X0 A91200 LDA */
static js_stop_reason vehicle_body_167(js_machine_v05c *m) {
    /* 80:C244:E0M0X0 A91200 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x12u, 0x00u };
    r = js_v05c_guard_code(m, 16964u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0012u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC247u,0u,0u,0u));
}
/* 80:C247:E0M0X0 A03B92 LDY */
static js_stop_reason vehicle_body_168(js_machine_v05c *m) {
    /* 80:C247:E0M0X0 A03B92 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x3Bu, 0x92u };
    r = js_v05c_guard_code(m, 16967u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x923Bu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC24Au,0u,0u,0u));
}
/* 80:C24A:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_169(js_machine_v05c *m) {
    /* 80:C24A:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16970u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC24Cu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C24D:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_170(js_machine_v05c *m) {
    /* 80:C24D:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16973u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC25Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC24Fu,0u,0u,0u));
}
/* 80:C24F:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_171(js_machine_v05c *m) {
    /* 80:C24F:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16975u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC251u,0u,0u,0u));
}
/* 80:C251:E0M0X0 A90040 LDA */
static js_stop_reason vehicle_body_172(js_machine_v05c *m) {
    /* 80:C251:E0M0X0 A90040 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x40u };
    r = js_v05c_guard_code(m, 16977u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x4000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC254u,0u,0u,0u));
}
/* 80:C254:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_173(js_machine_v05c *m) {
    /* 80:C254:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 16980u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC256u,0u,0u,0u));
}
/* 80:C256:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_174(js_machine_v05c *m) {
    /* 80:C256:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 16982u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC25Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC258u,0u,0u,0u));
}
/* 80:C258:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_175(js_machine_v05c *m) {
    /* 80:C258:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 16984u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C25B:E0M0X0 A91000 LDA */
static js_stop_reason vehicle_body_176(js_machine_v05c *m) {
    /* 80:C25B:E0M0X0 A91000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 16987u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0010u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC25Eu,0u,0u,0u));
}
/* 80:C25E:E0M0X0 A07792 LDY */
static js_stop_reason vehicle_body_177(js_machine_v05c *m) {
    /* 80:C25E:E0M0X0 A07792 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x77u, 0x92u };
    r = js_v05c_guard_code(m, 16990u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x9277u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC261u,0u,0u,0u));
}
/* 80:C261:E0M0X0 2073C2 JSR */
static js_stop_reason vehicle_body_178(js_machine_v05c *m) {
    /* 80:C261:E0M0X0 2073C2 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x73u, 0xC2u };
    r = js_v05c_guard_code(m, 16993u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xC263u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC273u,0u,0u,0u));
}
/* 80:C264:E0M0X0 900C BCC */
static js_stop_reason vehicle_body_179(js_machine_v05c *m) {
    /* 80:C264:E0M0X0 900C BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x0Cu };
    r = js_v05c_guard_code(m, 16996u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC272u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC266u,0u,0u,0u));
}
/* 80:C266:E0M0X0 8626 STX */
static js_stop_reason vehicle_body_180(js_machine_v05c *m) {
    /* 80:C266:E0M0X0 8626 STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0x26u };
    r = js_v05c_guard_code(m, 16998u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x26u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC268u,0u,0u,0u));
}
/* 80:C268:E0M0X0 A98000 LDA */
static js_stop_reason vehicle_body_181(js_machine_v05c *m) {
    /* 80:C268:E0M0X0 A98000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x80u, 0x00u };
    r = js_v05c_guard_code(m, 17000u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0080u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC26Bu,0u,0u,0u));
}
/* 80:C26B:E0M0X0 142C TRB */
static js_stop_reason vehicle_body_182(js_machine_v05c *m) {
    /* 80:C26B:E0M0X0 142C TRB direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x14u, 0x2Cu };
    r = js_v05c_guard_code(m, 17003u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_trb(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC26Du,0u,0u,0u));
}
/* 80:C26D:E0M0X0 F003 BEQ */
static js_stop_reason vehicle_body_183(js_machine_v05c *m) {
    /* 80:C26D:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 17005u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC272u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC26Fu,0u,0u,0u));
}
/* 80:C26F:E0M0X0 4C52C4 JMP */
static js_stop_reason vehicle_body_184(js_machine_v05c *m) {
    /* 80:C26F:E0M0X0 4C52C4 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x52u, 0xC4u };
    r = js_v05c_guard_code(m, 17007u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xC452u,0u,0u,0u));
}
/* 80:C272:E0M0X0 60 RTS */
static js_stop_reason vehicle_body_185(js_machine_v05c *m) {
    /* 80:C272:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 17010u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0x80u,0x9C70u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
int jungle_vehicle_context_known(js_static_context_key key){switch(js_v05c_pack_key(key)){
case JS_V05C_KEY_CONST(0x80u,0xB055u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB058u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB062u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB064u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB067u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB06Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB06Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB070u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB073u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB076u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB079u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB07Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB07Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB081u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB083u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB086u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB088u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB08Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB08Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB091u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB093u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB097u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0AAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0ADu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0BCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0BEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0CAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0CDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0DBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0DEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0EBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0ECu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0EFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0FBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0FDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB100u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB102u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB105u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB107u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB109u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB10Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB10Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB112u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB115u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB118u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB11Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB11Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB121u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB123u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB126u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB129u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB12Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB12Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB130u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB133u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB135u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB138u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB142u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xB145u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC17Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC17Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC182u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC185u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC188u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC18Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC18Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC190u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC192u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC194u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC197u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC199u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC19Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC19Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1AAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1ACu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1AFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1BCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1BFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1CAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1CEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1DBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1DEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1EAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1ECu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1EFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC202u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC204u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC206u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC209u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC20Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC20Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC212u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC214u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC216u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC219u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC21Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC21Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC220u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC223u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC227u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC22Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC22Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC230u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC233u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC235u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC237u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC239u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC23Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC23Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC241u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC244u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC247u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC251u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC254u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC256u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC258u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC25Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC25Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC261u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC264u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC266u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC268u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xC272u,0u,0u,0u):return 1;
default:return 0;}}
int jungle_vehicle_dispatch(js_machine_v05c*m,js_static_context_key key,js_stop_reason*out){switch(js_v05c_pack_key(key)){
case JS_V05C_KEY_CONST(0x80u,0xB055u,0u,0u,0u):*out=vehicle_body_0(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB058u,0u,0u,0u):*out=vehicle_body_1(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Au,0u,0u,0u):*out=vehicle_body_2(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Du,0u,0u,0u):*out=vehicle_body_3(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB05Fu,0u,0u,0u):*out=vehicle_body_4(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB062u,0u,0u,0u):*out=vehicle_body_5(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB064u,0u,0u,0u):*out=vehicle_body_6(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB067u,0u,0u,0u):*out=vehicle_body_7(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB06Au,0u,0u,0u):*out=vehicle_body_8(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB06Du,0u,0u,0u):*out=vehicle_body_9(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB070u,0u,0u,0u):*out=vehicle_body_10(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB073u,0u,0u,0u):*out=vehicle_body_11(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB076u,0u,0u,0u):*out=vehicle_body_12(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB079u,0u,0u,0u):*out=vehicle_body_13(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB07Bu,0u,0u,0u):*out=vehicle_body_14(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB07Eu,0u,0u,0u):*out=vehicle_body_15(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB081u,0u,0u,0u):*out=vehicle_body_16(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB083u,0u,0u,0u):*out=vehicle_body_17(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB086u,0u,0u,0u):*out=vehicle_body_18(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB088u,0u,0u,0u):*out=vehicle_body_19(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB08Bu,0u,0u,0u):*out=vehicle_body_20(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB08Eu,0u,0u,0u):*out=vehicle_body_21(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB091u,0u,0u,0u):*out=vehicle_body_22(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB093u,0u,0u,0u):*out=vehicle_body_23(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB097u,0u,0u,0u):*out=vehicle_body_24(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Au,0u,0u,0u):*out=vehicle_body_25(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Cu,0u,0u,0u):*out=vehicle_body_26(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB09Fu,0u,0u,0u):*out=vehicle_body_27(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A2u,0u,0u,0u):*out=vehicle_body_28(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A5u,0u,0u,0u):*out=vehicle_body_29(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0A8u,0u,0u,0u):*out=vehicle_body_30(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0AAu,0u,0u,0u):*out=vehicle_body_31(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0ADu,0u,0u,0u):*out=vehicle_body_32(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B0u,0u,0u,0u):*out=vehicle_body_33(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B2u,0u,0u,0u):*out=vehicle_body_34(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B5u,0u,0u,0u):*out=vehicle_body_35(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B7u,0u,0u,0u):*out=vehicle_body_36(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0B9u,0u,0u,0u):*out=vehicle_body_37(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0BCu,0u,0u,0u):*out=vehicle_body_38(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0BEu,0u,0u,0u):*out=vehicle_body_39(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C1u,0u,0u,0u):*out=vehicle_body_40(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C4u,0u,0u,0u):*out=vehicle_body_41(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C6u,0u,0u,0u):*out=vehicle_body_42(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0C9u,0u,0u,0u):*out=vehicle_body_43(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0CAu,0u,0u,0u):*out=vehicle_body_44(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0CDu,0u,0u,0u):*out=vehicle_body_45(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D0u,0u,0u,0u):*out=vehicle_body_46(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D3u,0u,0u,0u):*out=vehicle_body_47(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D6u,0u,0u,0u):*out=vehicle_body_48(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0D9u,0u,0u,0u):*out=vehicle_body_49(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0DBu,0u,0u,0u):*out=vehicle_body_50(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0DEu,0u,0u,0u):*out=vehicle_body_51(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E0u,0u,0u,0u):*out=vehicle_body_52(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E3u,0u,0u,0u):*out=vehicle_body_53(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E6u,0u,0u,0u):*out=vehicle_body_54(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0E8u,0u,0u,0u):*out=vehicle_body_55(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0EBu,0u,0u,0u):*out=vehicle_body_56(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0ECu,0u,0u,0u):*out=vehicle_body_57(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0EFu,0u,0u,0u):*out=vehicle_body_58(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F2u,0u,0u,0u):*out=vehicle_body_59(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F5u,0u,0u,0u):*out=vehicle_body_60(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0F8u,0u,0u,0u):*out=vehicle_body_61(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0FBu,0u,0u,0u):*out=vehicle_body_62(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB0FDu,0u,0u,0u):*out=vehicle_body_63(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB100u,0u,0u,0u):*out=vehicle_body_64(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB102u,0u,0u,0u):*out=vehicle_body_65(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB105u,0u,0u,0u):*out=vehicle_body_66(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB107u,0u,0u,0u):*out=vehicle_body_67(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB109u,0u,0u,0u):*out=vehicle_body_68(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB10Cu,0u,0u,0u):*out=vehicle_body_69(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB10Fu,0u,0u,0u):*out=vehicle_body_70(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB112u,0u,0u,0u):*out=vehicle_body_71(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB115u,0u,0u,0u):*out=vehicle_body_72(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB118u,0u,0u,0u):*out=vehicle_body_73(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB11Bu,0u,0u,0u):*out=vehicle_body_74(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB11Eu,0u,0u,0u):*out=vehicle_body_75(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB121u,0u,0u,0u):*out=vehicle_body_76(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB123u,0u,0u,0u):*out=vehicle_body_77(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB126u,0u,0u,0u):*out=vehicle_body_78(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB129u,0u,0u,0u):*out=vehicle_body_79(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB12Bu,0u,0u,0u):*out=vehicle_body_80(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB12Eu,0u,0u,0u):*out=vehicle_body_81(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB130u,0u,0u,0u):*out=vehicle_body_82(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB133u,0u,0u,0u):*out=vehicle_body_83(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB135u,0u,0u,0u):*out=vehicle_body_84(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB138u,0u,0u,0u):*out=vehicle_body_85(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Au,0u,0u,0u):*out=vehicle_body_86(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Du,0u,0u,0u):*out=vehicle_body_87(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Eu,0u,0u,0u):*out=vehicle_body_88(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB13Fu,0u,0u,0u):*out=vehicle_body_89(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB142u,0u,0u,0u):*out=vehicle_body_90(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xB145u,0u,0u,0u):*out=vehicle_body_91(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC17Bu,0u,0u,0u):*out=vehicle_body_92(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC17Eu,0u,0u,0u):*out=vehicle_body_93(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC182u,0u,0u,0u):*out=vehicle_body_94(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC185u,0u,0u,0u):*out=vehicle_body_95(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC188u,0u,0u,0u):*out=vehicle_body_96(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC18Bu,0u,0u,0u):*out=vehicle_body_97(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC18Eu,0u,0u,0u):*out=vehicle_body_98(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC190u,0u,0u,0u):*out=vehicle_body_99(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC192u,0u,0u,0u):*out=vehicle_body_100(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC194u,0u,0u,0u):*out=vehicle_body_101(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC197u,0u,0u,0u):*out=vehicle_body_102(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC199u,0u,0u,0u):*out=vehicle_body_103(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC19Cu,0u,0u,0u):*out=vehicle_body_104(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC19Fu,0u,0u,0u):*out=vehicle_body_105(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A2u,0u,0u,0u):*out=vehicle_body_106(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A5u,0u,0u,0u):*out=vehicle_body_107(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1A8u,0u,0u,0u):*out=vehicle_body_108(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1AAu,0u,0u,0u):*out=vehicle_body_109(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1ACu,0u,0u,0u):*out=vehicle_body_110(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1AFu,0u,0u,0u):*out=vehicle_body_111(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B1u,0u,0u,0u):*out=vehicle_body_112(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B3u,0u,0u,0u):*out=vehicle_body_113(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B6u,0u,0u,0u):*out=vehicle_body_114(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1B9u,0u,0u,0u):*out=vehicle_body_115(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1BCu,0u,0u,0u):*out=vehicle_body_116(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1BFu,0u,0u,0u):*out=vehicle_body_117(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C1u,0u,0u,0u):*out=vehicle_body_118(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C3u,0u,0u,0u):*out=vehicle_body_119(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C6u,0u,0u,0u):*out=vehicle_body_120(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1C8u,0u,0u,0u):*out=vehicle_body_121(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1CAu,0u,0u,0u):*out=vehicle_body_122(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1CEu,0u,0u,0u):*out=vehicle_body_123(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D1u,0u,0u,0u):*out=vehicle_body_124(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D5u,0u,0u,0u):*out=vehicle_body_125(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1D8u,0u,0u,0u):*out=vehicle_body_126(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1DBu,0u,0u,0u):*out=vehicle_body_127(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1DEu,0u,0u,0u):*out=vehicle_body_128(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E1u,0u,0u,0u):*out=vehicle_body_129(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E3u,0u,0u,0u):*out=vehicle_body_130(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E5u,0u,0u,0u):*out=vehicle_body_131(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1E7u,0u,0u,0u):*out=vehicle_body_132(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1EAu,0u,0u,0u):*out=vehicle_body_133(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1ECu,0u,0u,0u):*out=vehicle_body_134(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1EFu,0u,0u,0u):*out=vehicle_body_135(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F2u,0u,0u,0u):*out=vehicle_body_136(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F5u,0u,0u,0u):*out=vehicle_body_137(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1F8u,0u,0u,0u):*out=vehicle_body_138(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FBu,0u,0u,0u):*out=vehicle_body_139(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FDu,0u,0u,0u):*out=vehicle_body_140(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC1FFu,0u,0u,0u):*out=vehicle_body_141(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC202u,0u,0u,0u):*out=vehicle_body_142(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC204u,0u,0u,0u):*out=vehicle_body_143(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC206u,0u,0u,0u):*out=vehicle_body_144(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC209u,0u,0u,0u):*out=vehicle_body_145(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC20Cu,0u,0u,0u):*out=vehicle_body_146(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC20Fu,0u,0u,0u):*out=vehicle_body_147(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC212u,0u,0u,0u):*out=vehicle_body_148(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC214u,0u,0u,0u):*out=vehicle_body_149(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC216u,0u,0u,0u):*out=vehicle_body_150(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC219u,0u,0u,0u):*out=vehicle_body_151(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC21Bu,0u,0u,0u):*out=vehicle_body_152(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC21Du,0u,0u,0u):*out=vehicle_body_153(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC220u,0u,0u,0u):*out=vehicle_body_154(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC223u,0u,0u,0u):*out=vehicle_body_155(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC227u,0u,0u,0u):*out=vehicle_body_156(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC22Au,0u,0u,0u):*out=vehicle_body_157(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC22Du,0u,0u,0u):*out=vehicle_body_158(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC230u,0u,0u,0u):*out=vehicle_body_159(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC233u,0u,0u,0u):*out=vehicle_body_160(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC235u,0u,0u,0u):*out=vehicle_body_161(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC237u,0u,0u,0u):*out=vehicle_body_162(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC239u,0u,0u,0u):*out=vehicle_body_163(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC23Cu,0u,0u,0u):*out=vehicle_body_164(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC23Eu,0u,0u,0u):*out=vehicle_body_165(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC241u,0u,0u,0u):*out=vehicle_body_166(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC244u,0u,0u,0u):*out=vehicle_body_167(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC247u,0u,0u,0u):*out=vehicle_body_168(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Au,0u,0u,0u):*out=vehicle_body_169(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Du,0u,0u,0u):*out=vehicle_body_170(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC24Fu,0u,0u,0u):*out=vehicle_body_171(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC251u,0u,0u,0u):*out=vehicle_body_172(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC254u,0u,0u,0u):*out=vehicle_body_173(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC256u,0u,0u,0u):*out=vehicle_body_174(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC258u,0u,0u,0u):*out=vehicle_body_175(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC25Bu,0u,0u,0u):*out=vehicle_body_176(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC25Eu,0u,0u,0u):*out=vehicle_body_177(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC261u,0u,0u,0u):*out=vehicle_body_178(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC264u,0u,0u,0u):*out=vehicle_body_179(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC266u,0u,0u,0u):*out=vehicle_body_180(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC268u,0u,0u,0u):*out=vehicle_body_181(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Bu,0u,0u,0u):*out=vehicle_body_182(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Du,0u,0u,0u):*out=vehicle_body_183(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC26Fu,0u,0u,0u):*out=vehicle_body_184(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xC272u,0u,0u,0u):*out=vehicle_body_185(m);return 1;
default:return 0;}}
int jungle_vehicle_return_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);
if(f==JS_V05C_KEY_CONST(0x80u,0xADD3u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C5Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC1CDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C70u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC272u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C70u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC18Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1A8u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1BFu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1E1u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1FBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC212u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC233u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC24Du,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC338u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC264u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC18Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1A8u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1BFu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1E1u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1FBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC212u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC233u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC24Du,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC33Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC264u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC46Bu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C70u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC478u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C70u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC5A3u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x9C70u,0u,0u,0u))return 1;
return 0;}
int jungle_vehicle_indirect_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);
if(f==JS_V05C_KEY_CONST(0x80u,0xACAFu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xB055u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xACAFu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xB107u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xACAFu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xB091u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC11Eu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC17Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC11Eu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC1CEu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xC11Eu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xC220u,0u,0u,0u))return 1;
return 0;}
