/* Offline immutable-ROM Status-screen closure; no runtime decoding. */
#include "static_core_compact_generated.h"
#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_v10_3_internal.h"
#include "jungle/cpu_v10_27_internal.h"
#include "jungle/cpu_v10_36_internal.h"
#include "jungle/cpu_v10_45_internal.h"
#include "jungle/cpu_dispatch_v10_100.h"
#include "jungle/status_v10_11.h"
#include "jungle/status_closure.h"
/* 80:BC61:E0M0X0 FA PLX */
static js_stop_reason status_body_0(js_machine_v05c *m) {
    /* 80:BC61:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 15457u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC62u,0u,0u,0u));
}
/* 80:BC62:E0M0X0 9E4400 STZ */
static js_stop_reason status_body_1(js_machine_v05c *m) {
    /* 80:BC62:E0M0X0 9E4400 STZ abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Eu, 0x44u, 0x00u };
    r = js_v05c_guard_code(m, 15458u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0044u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC65u,0u,0u,0u));
}
/* 80:BC65:E0M0X0 5A PHY */
static js_stop_reason status_body_2(js_machine_v05c *m) {
    /* 80:BC65:E0M0X0 5A PHY stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x5Au };
    r = js_v05c_guard_code(m, 15461u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.y & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC66u,0u,0u,0u));
}
/* 80:BC66:E0M0X0 ACC80F LDY */
static js_stop_reason status_body_3(js_machine_v05c *m) {
    /* 80:BC66:E0M0X0 ACC80F LDY abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xACu, 0xC8u, 0x0Fu };
    r = js_v05c_guard_code(m, 15462u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0FC8u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC69u,0u,0u,0u));
}
/* 80:BC69:E0M0X0 B90000 LDA */
static js_stop_reason status_body_4(js_machine_v05c *m) {
    /* 80:BC69:E0M0X0 B90000 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 15465u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0000u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC6Cu,0u,0u,0u));
}
/* 80:BC6C:E0M0X0 2900A0 AND */
static js_stop_reason status_body_5(js_machine_v05c *m) {
    /* 80:BC6C:E0M0X0 2900A0 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x00u, 0xA0u };
    r = js_v05c_guard_code(m, 15468u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xA000u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC6Fu,0u,0u,0u));
}
/* 80:BC6F:E0M0X0 F003 BEQ */
static js_stop_reason status_body_6(js_machine_v05c *m) {
    /* 80:BC6F:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 15471u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC74u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC71u,0u,0u,0u));
}
/* 80:BC71:E0M0X0 4C00BD JMP */
static js_stop_reason status_body_7(js_machine_v05c *m) {
    /* 80:BC71:E0M0X0 4C00BD JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x00u, 0xBDu };
    r = js_v05c_guard_code(m, 15473u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBD00u,0u,0u,0u));
}
/* 80:BC74:E0M0X0 A90400 LDA */
static js_stop_reason status_body_8(js_machine_v05c *m) {
    /* 80:BC74:E0M0X0 A90400 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 15476u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC77u,0u,0u,0u));
}
/* 80:BC77:E0M0X0 993000 STA */
static js_stop_reason status_body_9(js_machine_v05c *m) {
    /* 80:BC77:E0M0X0 993000 STA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x99u, 0x30u, 0x00u };
    r = js_v05c_guard_code(m, 15479u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0030u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC7Au,0u,0u,0u));
}
/* 80:BC7A:E0M0X0 A90000 LDA */
static js_stop_reason status_body_10(js_machine_v05c *m) {
    /* 80:BC7A:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 15482u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC7Du,0u,0u,0u));
}
/* 80:BC7D:E0M0X0 991600 STA */
static js_stop_reason status_body_11(js_machine_v05c *m) {
    /* 80:BC7D:E0M0X0 991600 STA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x99u, 0x16u, 0x00u };
    r = js_v05c_guard_code(m, 15485u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0016u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBC80u,0u,0u,0u));
}
/* 80:BC80:E0M0X0 8058 BRA */
static js_stop_reason status_body_12(js_machine_v05c *m) {
    /* 80:BC80:E0M0X0 8058 BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0x58u };
    r = js_v05c_guard_code(m, 15488u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xBCDAu,0u,0u,0u));
}
/* 80:D3FD:E0M0X0 BD0200 LDA */
static js_stop_reason status_body_13(js_machine_v05c *m) {
    /* 80:D3FD:E0M0X0 BD0200 LDA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBDu, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 21501u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0002u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD400u,0u,0u,0u));
}
/* 80:D400:E0M0X0 090080 ORA */
static js_stop_reason status_body_14(js_machine_v05c *m) {
    /* 80:D400:E0M0X0 090080 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 21504u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x8000u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD403u,0u,0u,0u));
}
/* 80:D403:E0M0X0 9D0200 STA */
static js_stop_reason status_body_15(js_machine_v05c *m) {
    /* 80:D403:E0M0X0 9D0200 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 21507u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0002u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD406u,0u,0u,0u));
}
/* 80:D406:E0M0X0 BD6E00 LDA */
static js_stop_reason status_body_16(js_machine_v05c *m) {
    /* 80:D406:E0M0X0 BD6E00 LDA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBDu, 0x6Eu, 0x00u };
    r = js_v05c_guard_code(m, 21510u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x006Eu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD409u,0u,0u,0u));
}
/* 80:D409:E0M0X0 A608 LDX */
static js_stop_reason status_body_17(js_machine_v05c *m) {
    /* 80:D409:E0M0X0 A608 LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0x08u };
    r = js_v05c_guard_code(m, 21513u, expected, sizeof(expected));
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
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD40Bu,0u,0u,0u));
}
/* 80:D40B:E0M0X0 9FE30100 STA */
static js_stop_reason status_body_18(js_machine_v05c *m) {
    /* 80:D40B:E0M0X0 9FE30100 STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0xE3u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 21515u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x0001E3u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD40Fu,0u,0u,0u));
}
/* 80:D47B:E0M0X0 BD6E00 LDA */
static js_stop_reason status_body_19(js_machine_v05c *m) {
    /* 80:D47B:E0M0X0 BD6E00 LDA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBDu, 0x6Eu, 0x00u };
    r = js_v05c_guard_code(m, 21627u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x006Eu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD47Eu,0u,0u,0u));
}
/* 80:D47E:E0M0X0 A608 LDX */
static js_stop_reason status_body_20(js_machine_v05c *m) {
    /* 80:D47E:E0M0X0 A608 LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0x08u };
    r = js_v05c_guard_code(m, 21630u, expected, sizeof(expected));
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
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD480u,0u,0u,0u));
}
/* 80:D480:E0M0X0 9FE30100 STA */
static js_stop_reason status_body_21(js_machine_v05c *m) {
    /* 80:D480:E0M0X0 9FE30100 STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0xE3u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 21632u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x0001E3u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xD484u,0u,0u,0u));
}
/* 80:D484:E0M0X0 60 RTS */
static js_stop_reason status_body_22(js_machine_v05c *m) {
    /* 80:D484:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 21636u, expected, sizeof(expected));
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
/* 80:DB01:E0M0X0 FA PLX */
static js_stop_reason status_body_23(js_machine_v05c *m) {
    /* 80:DB01:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23297u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB02u,0u,0u,0u));
}
/* 80:DB02:E0M0X0 B90100 LDA */
static js_stop_reason status_body_24(js_machine_v05c *m) {
    /* 80:DB02:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23298u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB05u,0u,0u,0u));
}
/* 80:DB05:E0M0X0 29FF00 AND */
static js_stop_reason status_body_25(js_machine_v05c *m) {
    /* 80:DB05:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 23301u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB08u,0u,0u,0u));
}
/* 80:DB08:E0M0X0 9DEB01 STA */
static js_stop_reason status_body_26(js_machine_v05c *m) {
    /* 80:DB08:E0M0X0 9DEB01 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0xEBu, 0x01u };
    r = js_v05c_guard_code(m, 23304u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x01EBu);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB0Bu,0u,0u,0u));
}
/* 80:DB0B:E0M0X0 C8 INY */
static js_stop_reason status_body_27(js_machine_v05c *m) {
    /* 80:DB0B:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23307u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB0Cu,0u,0u,0u));
}
/* 80:DB0C:E0M0X0 C8 INY */
static js_stop_reason status_body_28(js_machine_v05c *m) {
    /* 80:DB0C:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23308u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB0Du,0u,0u,0u));
}
/* 80:DB0D:E0M0X0 98 TYA */
static js_stop_reason status_body_29(js_machine_v05c *m) {
    /* 80:DB0D:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 23309u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB0Eu,0u,0u,0u));
}
/* 80:DB0E:E0M0X0 9DE301 STA */
static js_stop_reason status_body_30(js_machine_v05c *m) {
    /* 80:DB0E:E0M0X0 9DE301 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0xE3u, 0x01u };
    r = js_v05c_guard_code(m, 23310u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x01E3u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB11u,0u,0u,0u));
}
/* 80:DB11:E0M0X0 60 RTS */
static js_stop_reason status_body_31(js_machine_v05c *m) {
    /* 80:DB11:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 23313u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0x80u,0x882Au,0u,0u,0u), JS_CTX(0x80u,0x8835u,0u,0u,0u), JS_CTX(0x80u,0x8840u,0u,0u,0u), JS_CTX(0x80u,0x884Bu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* 80:DB12:E0M0X0 B90100 LDA */
static js_stop_reason status_body_32(js_machine_v05c *m) {
    /* 80:DB12:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23314u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB15u,0u,0u,0u));
}
/* 80:DB15:E0M0X0 AA TAX */
static js_stop_reason status_body_33(js_machine_v05c *m) {
    /* 80:DB15:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23317u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB16u,0u,0u,0u));
}
/* 80:DB16:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_34(js_machine_v05c *m) {
    /* 80:DB16:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23318u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB1Au,0u,0u,0u));
}
/* 80:DB1A:E0M0X0 390300 AND */
static js_stop_reason status_body_35(js_machine_v05c *m) {
    /* 80:DB1A:E0M0X0 390300 AND abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x39u, 0x03u, 0x00u };
    r = js_v05c_guard_code(m, 23322u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0003u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & value) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB1Du,0u,0u,0u));
}
/* 80:DB1D:E0M0X0 9F00007F STA */
static js_stop_reason status_body_36(js_machine_v05c *m) {
    /* 80:DB1D:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23325u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB21u,0u,0u,0u));
}
/* 80:DB21:E0M0X0 C8 INY */
static js_stop_reason status_body_37(js_machine_v05c *m) {
    /* 80:DB21:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23329u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB22u,0u,0u,0u));
}
/* 80:DB22:E0M0X0 C8 INY */
static js_stop_reason status_body_38(js_machine_v05c *m) {
    /* 80:DB22:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23330u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB23u,0u,0u,0u));
}
/* 80:DB23:E0M0X0 C8 INY */
static js_stop_reason status_body_39(js_machine_v05c *m) {
    /* 80:DB23:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23331u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB24u,0u,0u,0u));
}
/* 80:DB24:E0M0X0 C8 INY */
static js_stop_reason status_body_40(js_machine_v05c *m) {
    /* 80:DB24:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23332u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB25u,0u,0u,0u));
}
/* 80:DB25:E0M0X0 C8 INY */
static js_stop_reason status_body_41(js_machine_v05c *m) {
    /* 80:DB25:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23333u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB26u,0u,0u,0u));
}
/* 80:DB26:E0M0X0 FA PLX */
static js_stop_reason status_body_42(js_machine_v05c *m) {
    /* 80:DB26:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23334u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB27u,0u,0u,0u));
}
/* 80:DB27:E0M0X0 80A5 BRA */
static js_stop_reason status_body_43(js_machine_v05c *m) {
    /* 80:DB27:E0M0X0 80A5 BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0xA5u };
    r = js_v05c_guard_code(m, 23335u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB29:E0M0X0 B90100 LDA */
static js_stop_reason status_body_44(js_machine_v05c *m) {
    /* 80:DB29:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23337u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB2Cu,0u,0u,0u));
}
/* 80:DB2C:E0M0X0 AA TAX */
static js_stop_reason status_body_45(js_machine_v05c *m) {
    /* 80:DB2C:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23340u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB2Du,0u,0u,0u));
}
/* 80:DB2D:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_46(js_machine_v05c *m) {
    /* 80:DB2D:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23341u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB31u,0u,0u,0u));
}
/* 80:DB31:E0M0X0 190300 ORA */
static js_stop_reason status_body_47(js_machine_v05c *m) {
    /* 80:DB31:E0M0X0 190300 ORA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x19u, 0x03u, 0x00u };
    r = js_v05c_guard_code(m, 23345u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0003u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB34u,0u,0u,0u));
}
/* 80:DB34:E0M0X0 9F00007F STA */
static js_stop_reason status_body_48(js_machine_v05c *m) {
    /* 80:DB34:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23348u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB38u,0u,0u,0u));
}
/* 80:DB38:E0M0X0 C8 INY */
static js_stop_reason status_body_49(js_machine_v05c *m) {
    /* 80:DB38:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23352u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB39u,0u,0u,0u));
}
/* 80:DB39:E0M0X0 C8 INY */
static js_stop_reason status_body_50(js_machine_v05c *m) {
    /* 80:DB39:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23353u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB3Au,0u,0u,0u));
}
/* 80:DB3A:E0M0X0 C8 INY */
static js_stop_reason status_body_51(js_machine_v05c *m) {
    /* 80:DB3A:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23354u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB3Bu,0u,0u,0u));
}
/* 80:DB3B:E0M0X0 C8 INY */
static js_stop_reason status_body_52(js_machine_v05c *m) {
    /* 80:DB3B:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23355u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB3Cu,0u,0u,0u));
}
/* 80:DB3C:E0M0X0 C8 INY */
static js_stop_reason status_body_53(js_machine_v05c *m) {
    /* 80:DB3C:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23356u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB3Du,0u,0u,0u));
}
/* 80:DB3D:E0M0X0 FA PLX */
static js_stop_reason status_body_54(js_machine_v05c *m) {
    /* 80:DB3D:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23357u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB3Eu,0u,0u,0u));
}
/* 80:DB3E:E0M0X0 808E BRA */
static js_stop_reason status_body_55(js_machine_v05c *m) {
    /* 80:DB3E:E0M0X0 808E BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0x8Eu };
    r = js_v05c_guard_code(m, 23358u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB40:E0M0X0 B90100 LDA */
static js_stop_reason status_body_56(js_machine_v05c *m) {
    /* 80:DB40:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23360u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB43u,0u,0u,0u));
}
/* 80:DB43:E0M0X0 AA TAX */
static js_stop_reason status_body_57(js_machine_v05c *m) {
    /* 80:DB43:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23363u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB44u,0u,0u,0u));
}
/* 80:DB44:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_58(js_machine_v05c *m) {
    /* 80:DB44:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23364u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB48u,0u,0u,0u));
}
/* 80:DB48:E0M0X0 48 PHA */
static js_stop_reason status_body_59(js_machine_v05c *m) {
    /* 80:DB48:E0M0X0 48 PHA stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x48u };
    r = js_v05c_guard_code(m, 23368u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.a & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB49u,0u,0u,0u));
}
/* 80:DB49:E0M0X0 B90300 LDA */
static js_stop_reason status_body_60(js_machine_v05c *m) {
    /* 80:DB49:E0M0X0 B90300 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x03u, 0x00u };
    r = js_v05c_guard_code(m, 23369u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0003u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB4Cu,0u,0u,0u));
}
/* 80:DB4C:E0M0X0 AA TAX */
static js_stop_reason status_body_61(js_machine_v05c *m) {
    /* 80:DB4C:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23372u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB4Du,0u,0u,0u));
}
/* 80:DB4D:E0M0X0 68 PLA */
static js_stop_reason status_body_62(js_machine_v05c *m) {
    /* 80:DB4D:E0M0X0 68 PLA stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x68u };
    r = js_v05c_guard_code(m, 23373u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB4Eu,0u,0u,0u));
}
/* 80:DB4E:E0M0X0 9F00007F STA */
static js_stop_reason status_body_63(js_machine_v05c *m) {
    /* 80:DB4E:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23374u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB52u,0u,0u,0u));
}
/* 80:DB52:E0M0X0 C8 INY */
static js_stop_reason status_body_64(js_machine_v05c *m) {
    /* 80:DB52:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23378u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB53u,0u,0u,0u));
}
/* 80:DB53:E0M0X0 C8 INY */
static js_stop_reason status_body_65(js_machine_v05c *m) {
    /* 80:DB53:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23379u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB54u,0u,0u,0u));
}
/* 80:DB54:E0M0X0 C8 INY */
static js_stop_reason status_body_66(js_machine_v05c *m) {
    /* 80:DB54:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23380u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB55u,0u,0u,0u));
}
/* 80:DB55:E0M0X0 C8 INY */
static js_stop_reason status_body_67(js_machine_v05c *m) {
    /* 80:DB55:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23381u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB56u,0u,0u,0u));
}
/* 80:DB56:E0M0X0 C8 INY */
static js_stop_reason status_body_68(js_machine_v05c *m) {
    /* 80:DB56:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23382u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB57u,0u,0u,0u));
}
/* 80:DB57:E0M0X0 FA PLX */
static js_stop_reason status_body_69(js_machine_v05c *m) {
    /* 80:DB57:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23383u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB58u,0u,0u,0u));
}
/* 80:DB58:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_70(js_machine_v05c *m) {
    /* 80:DB58:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23384u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB5B:E0M0X0 FA PLX */
static js_stop_reason status_body_71(js_machine_v05c *m) {
    /* 80:DB5B:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23387u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB5Cu,0u,0u,0u));
}
/* 80:DB5C:E0M0X0 ADDE08 LDA */
static js_stop_reason status_body_72(js_machine_v05c *m) {
    /* 80:DB5C:E0M0X0 ADDE08 LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0xDEu, 0x08u };
    r = js_v05c_guard_code(m, 23388u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08DEu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB5Fu,0u,0u,0u));
}
/* 80:DB5F:E0M0X0 D007 BNE */
static js_stop_reason status_body_73(js_machine_v05c *m) {
    /* 80:DB5F:E0M0X0 D007 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x07u };
    r = js_v05c_guard_code(m, 23391u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB68u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB61u,0u,0u,0u));
}
/* 80:DB61:E0M0X0 B90100 LDA */
static js_stop_reason status_body_74(js_machine_v05c *m) {
    /* 80:DB61:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23393u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB64u,0u,0u,0u));
}
/* 80:DB64:E0M0X0 3A DEC */
static js_stop_reason status_body_75(js_machine_v05c *m) {
    /* 80:DB64:E0M0X0 3A DEC acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x3Au };
    r = js_v05c_guard_code(m, 23396u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u, -1);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB65u,0u,0u,0u));
}
/* 80:DB65:E0M0X0 8DDE08 STA */
static js_stop_reason status_body_76(js_machine_v05c *m) {
    /* 80:DB65:E0M0X0 8DDE08 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0xDEu, 0x08u };
    r = js_v05c_guard_code(m, 23397u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x08DEu);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB68u,0u,0u,0u));
}
/* 80:DB68:E0M0X0 AF16117F LDA */
static js_stop_reason status_body_77(js_machine_v05c *m) {
    /* 80:DB68:E0M0X0 AF16117F LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0x16u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 23400u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F1116u;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB6Cu,0u,0u,0u));
}
/* 80:DB6C:E0M0X0 090080 ORA */
static js_stop_reason status_body_78(js_machine_v05c *m) {
    /* 80:DB6C:E0M0X0 090080 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 23404u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x8000u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB6Fu,0u,0u,0u));
}
/* 80:DB6F:E0M0X0 8F16117F STA */
static js_stop_reason status_body_79(js_machine_v05c *m) {
    /* 80:DB6F:E0M0X0 8F16117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0x16u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 23407u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F1116u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB73u,0u,0u,0u));
}
/* 80:DB73:E0M0X0 C8 INY */
static js_stop_reason status_body_80(js_machine_v05c *m) {
    /* 80:DB73:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23411u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB74u,0u,0u,0u));
}
/* 80:DB74:E0M0X0 C8 INY */
static js_stop_reason status_body_81(js_machine_v05c *m) {
    /* 80:DB74:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23412u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB75u,0u,0u,0u));
}
/* 80:DB75:E0M0X0 C8 INY */
static js_stop_reason status_body_82(js_machine_v05c *m) {
    /* 80:DB75:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23413u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB76u,0u,0u,0u));
}
/* 80:DB76:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_83(js_machine_v05c *m) {
    /* 80:DB76:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23414u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB79:E0M0X0 FA PLX */
static js_stop_reason status_body_84(js_machine_v05c *m) {
    /* 80:DB79:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23417u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB7Au,0u,0u,0u));
}
/* 80:DB7A:E0M0X0 B90100 LDA */
static js_stop_reason status_body_85(js_machine_v05c *m) {
    /* 80:DB7A:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23418u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB7Du,0u,0u,0u));
}
/* 80:DB7D:E0M0X0 29FF00 AND */
static js_stop_reason status_body_86(js_machine_v05c *m) {
    /* 80:DB7D:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 23421u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB80u,0u,0u,0u));
}
/* 80:DB80:E0M0X0 20E9FC JSR */
static js_stop_reason status_body_87(js_machine_v05c *m) {
    /* 80:DB80:E0M0X0 20E9FC JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE9u, 0xFCu };
    r = js_v05c_guard_code(m, 23424u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xDB82u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xFCE9u,0u,0u,0u));
}
/* 80:DB83:E0M0X0 C8 INY */
static js_stop_reason status_body_88(js_machine_v05c *m) {
    /* 80:DB83:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23427u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB84u,0u,0u,0u));
}
/* 80:DB84:E0M0X0 C8 INY */
static js_stop_reason status_body_89(js_machine_v05c *m) {
    /* 80:DB84:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23428u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB85u,0u,0u,0u));
}
/* 80:DB85:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_90(js_machine_v05c *m) {
    /* 80:DB85:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23429u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB88:E0M0X0 B90100 LDA */
static js_stop_reason status_body_91(js_machine_v05c *m) {
    /* 80:DB88:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23432u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB8Bu,0u,0u,0u));
}
/* 80:DB8B:E0M0X0 AA TAX */
static js_stop_reason status_body_92(js_machine_v05c *m) {
    /* 80:DB8B:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23435u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB8Cu,0u,0u,0u));
}
/* 80:DB8C:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_93(js_machine_v05c *m) {
    /* 80:DB8C:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23436u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB90u,0u,0u,0u));
}
/* 80:DB90:E0M0X0 1A INC */
static js_stop_reason status_body_94(js_machine_v05c *m) {
    /* 80:DB90:E0M0X0 1A INC acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x1Au };
    r = js_v05c_guard_code(m, 23440u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u, 1);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB91u,0u,0u,0u));
}
/* 80:DB91:E0M0X0 9F00007F STA */
static js_stop_reason status_body_95(js_machine_v05c *m) {
    /* 80:DB91:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23441u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB95u,0u,0u,0u));
}
/* 80:DB95:E0M0X0 FA PLX */
static js_stop_reason status_body_96(js_machine_v05c *m) {
    /* 80:DB95:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23445u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB96u,0u,0u,0u));
}
/* 80:DB96:E0M0X0 C8 INY */
static js_stop_reason status_body_97(js_machine_v05c *m) {
    /* 80:DB96:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23446u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB97u,0u,0u,0u));
}
/* 80:DB97:E0M0X0 C8 INY */
static js_stop_reason status_body_98(js_machine_v05c *m) {
    /* 80:DB97:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23447u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB98u,0u,0u,0u));
}
/* 80:DB98:E0M0X0 C8 INY */
static js_stop_reason status_body_99(js_machine_v05c *m) {
    /* 80:DB98:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23448u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB99u,0u,0u,0u));
}
/* 80:DB99:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_100(js_machine_v05c *m) {
    /* 80:DB99:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23449u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DB9C:E0M0X0 B90100 LDA */
static js_stop_reason status_body_101(js_machine_v05c *m) {
    /* 80:DB9C:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23452u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDB9Fu,0u,0u,0u));
}
/* 80:DB9F:E0M0X0 AA TAX */
static js_stop_reason status_body_102(js_machine_v05c *m) {
    /* 80:DB9F:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23455u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBA0u,0u,0u,0u));
}
/* 80:DBA0:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_103(js_machine_v05c *m) {
    /* 80:DBA0:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23456u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBA4u,0u,0u,0u));
}
/* 80:DBA4:E0M0X0 29FEFF AND */
static js_stop_reason status_body_104(js_machine_v05c *m) {
    /* 80:DBA4:E0M0X0 29FEFF AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFEu, 0xFFu };
    r = js_v05c_guard_code(m, 23460u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFFFEu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBA7u,0u,0u,0u));
}
/* 80:DBA7:E0M0X0 090200 ORA */
static js_stop_reason status_body_105(js_machine_v05c *m) {
    /* 80:DBA7:E0M0X0 090200 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 23463u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0002u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBAAu,0u,0u,0u));
}
/* 80:DBAA:E0M0X0 9F00007F STA */
static js_stop_reason status_body_106(js_machine_v05c *m) {
    /* 80:DBAA:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23466u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBAEu,0u,0u,0u));
}
/* 80:DBAE:E0M0X0 FA PLX */
static js_stop_reason status_body_107(js_machine_v05c *m) {
    /* 80:DBAE:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23470u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBAFu,0u,0u,0u));
}
/* 80:DBAF:E0M0X0 C8 INY */
static js_stop_reason status_body_108(js_machine_v05c *m) {
    /* 80:DBAF:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23471u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBB0u,0u,0u,0u));
}
/* 80:DBB0:E0M0X0 C8 INY */
static js_stop_reason status_body_109(js_machine_v05c *m) {
    /* 80:DBB0:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23472u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBB1u,0u,0u,0u));
}
/* 80:DBB1:E0M0X0 C8 INY */
static js_stop_reason status_body_110(js_machine_v05c *m) {
    /* 80:DBB1:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23473u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBB2u,0u,0u,0u));
}
/* 80:DBB2:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_111(js_machine_v05c *m) {
    /* 80:DBB2:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23474u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* 80:DBB5:E0M0X0 B90100 LDA */
static js_stop_reason status_body_112(js_machine_v05c *m) {
    /* 80:DBB5:E0M0X0 B90100 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 23477u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0001u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBB8u,0u,0u,0u));
}
/* 80:DBB8:E0M0X0 AA TAX */
static js_stop_reason status_body_113(js_machine_v05c *m) {
    /* 80:DBB8:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 23480u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBB9u,0u,0u,0u));
}
/* 80:DBB9:E0M0X0 BF00007F LDA */
static js_stop_reason status_body_114(js_machine_v05c *m) {
    /* 80:DBB9:E0M0X0 BF00007F LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23481u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBBDu,0u,0u,0u));
}
/* 80:DBBD:E0M0X0 29FF7F AND */
static js_stop_reason status_body_115(js_machine_v05c *m) {
    /* 80:DBBD:E0M0X0 29FF7F AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x7Fu };
    r = js_v05c_guard_code(m, 23485u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x7FFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC0u,0u,0u,0u));
}
/* 80:DBC0:E0M0X0 9F00007F STA */
static js_stop_reason status_body_116(js_machine_v05c *m) {
    /* 80:DBC0:E0M0X0 9F00007F STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x00u, 0x00u, 0x7Fu };
    r = js_v05c_guard_code(m, 23488u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7F0000u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC4u,0u,0u,0u));
}
/* 80:DBC4:E0M0X0 FA PLX */
static js_stop_reason status_body_117(js_machine_v05c *m) {
    /* 80:DBC4:E0M0X0 FA PLX stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xFAu };
    r = js_v05c_guard_code(m, 23492u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC5u,0u,0u,0u));
}
/* 80:DBC5:E0M0X0 C8 INY */
static js_stop_reason status_body_118(js_machine_v05c *m) {
    /* 80:DBC5:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23493u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC6u,0u,0u,0u));
}
/* 80:DBC6:E0M0X0 C8 INY */
static js_stop_reason status_body_119(js_machine_v05c *m) {
    /* 80:DBC6:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23494u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC7u,0u,0u,0u));
}
/* 80:DBC7:E0M0X0 C8 INY */
static js_stop_reason status_body_120(js_machine_v05c *m) {
    /* 80:DBC7:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 23495u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDBC8u,0u,0u,0u));
}
/* 80:DBC8:E0M0X0 4CCEDA JMP */
static js_stop_reason status_body_121(js_machine_v05c *m) {
    /* 80:DBC8:E0M0X0 4CCEDA JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xCEu, 0xDAu };
    r = js_v05c_guard_code(m, 23496u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0xDACEu,0u,0u,0u));
}
/* A0:8387:E0M0X0 20D6B5 JSR */
static js_stop_reason status_body_122(js_machine_v05c *m) {
    /* A0:8387:E0M0X0 20D6B5 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD6u, 0xB5u };
    r = js_v05c_guard_code(m, 1049479u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8389u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xB5D6u,0u,0u,0u));
}
/* A0:838A:E0M0X0 C90000 CMP */
static js_stop_reason status_body_123(js_machine_v05c *m) {
    /* A0:838A:E0M0X0 C90000 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049482u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0000u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x838Du,0u,0u,0u));
}
/* A0:838D:E0M0X0 F0F8 BEQ */
static js_stop_reason status_body_124(js_machine_v05c *m) {
    /* A0:838D:E0M0X0 F0F8 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0xF8u };
    r = js_v05c_guard_code(m, 1049485u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8387u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x838Fu,0u,0u,0u));
}
/* A0:838F:E0M0X0 9C640D STZ */
static js_stop_reason status_body_125(js_machine_v05c *m) {
    /* A0:838F:E0M0X0 9C640D STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1049487u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8392u,0u,0u,0u));
}
/* A0:8392:E0M0X0 A585 LDA */
static js_stop_reason status_body_126(js_machine_v05c *m) {
    /* A0:8392:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049490u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8394u,0u,0u,0u));
}
/* A0:8394:E0M0X0 29FFFB AND */
static js_stop_reason status_body_127(js_machine_v05c *m) {
    /* A0:8394:E0M0X0 29FFFB AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFBu };
    r = js_v05c_guard_code(m, 1049492u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFBFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8397u,0u,0u,0u));
}
/* A0:8397:E0M0X0 8585 STA */
static js_stop_reason status_body_128(js_machine_v05c *m) {
    /* A0:8397:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049495u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8399u,0u,0u,0u));
}
/* A0:8399:E0M0X0 20C288 JSR */
static js_stop_reason status_body_129(js_machine_v05c *m) {
    /* A0:8399:E0M0X0 20C288 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC2u, 0x88u };
    r = js_v05c_guard_code(m, 1049497u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x839Bu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x88C2u,0u,0u,0u));
}
/* A0:839C:E0M0X0 A20400 LDX */
static js_stop_reason status_body_130(js_machine_v05c *m) {
    /* A0:839C:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1049500u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x839Fu,0u,0u,0u));
}
/* A0:839F:E0M0X0 20C6E0 JSR */
static js_stop_reason status_body_131(js_machine_v05c *m) {
    /* A0:839F:E0M0X0 20C6E0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC6u, 0xE0u };
    r = js_v05c_guard_code(m, 1049503u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83A1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0C6u,0u,0u,0u));
}
/* A0:83A2:E0M0X0 20DDE0 JSR */
static js_stop_reason status_body_132(js_machine_v05c *m) {
    /* A0:83A2:E0M0X0 20DDE0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xDDu, 0xE0u };
    r = js_v05c_guard_code(m, 1049506u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83A4u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0DDu,0u,0u,0u));
}
/* A0:83A5:E0M0X0 A585 LDA */
static js_stop_reason status_body_133(js_machine_v05c *m) {
    /* A0:83A5:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049509u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83A7u,0u,0u,0u));
}
/* A0:83A7:E0M0X0 090004 ORA */
static js_stop_reason status_body_134(js_machine_v05c *m) {
    /* A0:83A7:E0M0X0 090004 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049511u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0400u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83AAu,0u,0u,0u));
}
/* A0:83AA:E0M0X0 8585 STA */
static js_stop_reason status_body_135(js_machine_v05c *m) {
    /* A0:83AA:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049514u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83ACu,0u,0u,0u));
}
/* A0:83AC:E0M0X0 20D291 JSR */
static js_stop_reason status_body_136(js_machine_v05c *m) {
    /* A0:83AC:E0M0X0 20D291 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD2u, 0x91u };
    r = js_v05c_guard_code(m, 1049516u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83AEu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91D2u,0u,0u,0u));
}
/* A0:83AF:E0M0X0 20198D JSR */
static js_stop_reason status_body_137(js_machine_v05c *m) {
    /* A0:83AF:E0M0X0 20198D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x19u, 0x8Du };
    r = js_v05c_guard_code(m, 1049519u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83B1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8D19u,0u,0u,0u));
}
/* A0:83B2:E0M0X0 20E884 JSR */
static js_stop_reason status_body_138(js_machine_v05c *m) {
    /* A0:83B2:E0M0X0 20E884 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE8u, 0x84u };
    r = js_v05c_guard_code(m, 1049522u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83B4u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84E8u,0u,0u,0u));
}
/* A0:83B5:E0M0X0 202585 JSR */
static js_stop_reason status_body_139(js_machine_v05c *m) {
    /* A0:83B5:E0M0X0 202585 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x25u, 0x85u };
    r = js_v05c_guard_code(m, 1049525u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83B7u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8525u,0u,0u,0u));
}
/* A0:83B8:E0M0X0 20E591 JSR */
static js_stop_reason status_body_140(js_machine_v05c *m) {
    /* A0:83B8:E0M0X0 20E591 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE5u, 0x91u };
    r = js_v05c_guard_code(m, 1049528u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83BAu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91E5u,0u,0u,0u));
}
/* A0:83BB:E0M0X0 20FC91 JSR */
static js_stop_reason status_body_141(js_machine_v05c *m) {
    /* A0:83BB:E0M0X0 20FC91 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xFCu, 0x91u };
    r = js_v05c_guard_code(m, 1049531u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83BDu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91FCu,0u,0u,0u));
}
/* A0:83BE:E0M0X0 A9A200 LDA */
static js_stop_reason status_body_142(js_machine_v05c *m) {
    /* A0:83BE:E0M0X0 A9A200 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xA2u, 0x00u };
    r = js_v05c_guard_code(m, 1049534u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00A2u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83C1u,0u,0u,0u));
}
/* A0:83C1:E0M0X0 8513 STA */
static js_stop_reason status_body_143(js_machine_v05c *m) {
    /* A0:83C1:E0M0X0 8513 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x13u };
    r = js_v05c_guard_code(m, 1049537u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x13u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83C3u,0u,0u,0u));
}
/* A0:83C3:E0M0X0 A90E98 LDA */
static js_stop_reason status_body_144(js_machine_v05c *m) {
    /* A0:83C3:E0M0X0 A90E98 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x0Eu, 0x98u };
    r = js_v05c_guard_code(m, 1049539u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x980Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83C6u,0u,0u,0u));
}
/* A0:83C6:E0M0X0 8511 STA */
static js_stop_reason status_body_145(js_machine_v05c *m) {
    /* A0:83C6:E0M0X0 8511 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x11u };
    r = js_v05c_guard_code(m, 1049542u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x11u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83C8u,0u,0u,0u));
}
/* A0:83C8:E0M0X0 20FACF JSR */
static js_stop_reason status_body_146(js_machine_v05c *m) {
    /* A0:83C8:E0M0X0 20FACF JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xFAu, 0xCFu };
    r = js_v05c_guard_code(m, 1049544u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83CAu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xCFFAu,0u,0u,0u));
}
/* A0:83CB:E0M0X0 20DDE0 JSR */
static js_stop_reason status_body_147(js_machine_v05c *m) {
    /* A0:83CB:E0M0X0 20DDE0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xDDu, 0xE0u };
    r = js_v05c_guard_code(m, 1049547u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83CDu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0DDu,0u,0u,0u));
}
/* A0:83CE:E0M0X0 A585 LDA */
static js_stop_reason status_body_148(js_machine_v05c *m) {
    /* A0:83CE:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049550u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83D0u,0u,0u,0u));
}
/* A0:83D0:E0M0X0 090004 ORA */
static js_stop_reason status_body_149(js_machine_v05c *m) {
    /* A0:83D0:E0M0X0 090004 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049552u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0400u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83D3u,0u,0u,0u));
}
/* A0:83D3:E0M0X0 8585 STA */
static js_stop_reason status_body_150(js_machine_v05c *m) {
    /* A0:83D3:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049555u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83D5u,0u,0u,0u));
}
/* A0:83D5:E0M0X0 A585 LDA */
static js_stop_reason status_body_151(js_machine_v05c *m) {
    /* A0:83D5:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049557u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83D7u,0u,0u,0u));
}
/* A0:83D7:E0M0X0 890004 BIT */
static js_stop_reason status_body_152(js_machine_v05c *m) {
    /* A0:83D7:E0M0X0 890004 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049559u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0400u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83DAu,0u,0u,0u));
}
/* A0:83DA:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_153(js_machine_v05c *m) {
    /* A0:83DA:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1049562u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83D5u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83DCu,0u,0u,0u));
}
/* A0:83DC:E0M0X0 A587 LDA */
static js_stop_reason status_body_154(js_machine_v05c *m) {
    /* A0:83DC:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1049564u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83DEu,0u,0u,0u));
}
/* A0:83DE:E0M0X0 29FFFE AND */
static js_stop_reason status_body_155(js_machine_v05c *m) {
    /* A0:83DE:E0M0X0 29FFFE AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFEu };
    r = js_v05c_guard_code(m, 1049566u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFEFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83E1u,0u,0u,0u));
}
/* A0:83E1:E0M0X0 8587 STA */
static js_stop_reason status_body_156(js_machine_v05c *m) {
    /* A0:83E1:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1049569u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83E3u,0u,0u,0u));
}
/* A0:83E3:E0M0X0 E220 SEP */
static js_stop_reason status_body_157(js_machine_v05c *m) {
    /* A0:83E3:E0M0X0 E220 SEP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE2u, 0x20u };
    r = js_v05c_guard_code(m, 1049571u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p |= 0x20u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83E5u,0u,1u,0u));
}
/* A0:83E5:E0M1X0 A502 LDA */
static js_stop_reason status_body_158(js_machine_v05c *m) {
    /* A0:83E5:E0M1X0 A502 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x02u };
    r = js_v05c_guard_code(m, 1049573u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x02u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 8u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 8u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83E7u,0u,1u,0u));
}
/* A0:83E7:E0M1X0 0915 ORA */
static js_stop_reason status_body_159(js_machine_v05c *m) {
    /* A0:83E7:E0M1X0 0915 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x15u };
    r = js_v05c_guard_code(m, 1049575u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0x00FFu) | 0x0015u) & 0x00FFu);
    js_v05c_write_a(&m->cpu, result, 8u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83E9u,0u,1u,0u));
}
/* A0:83E9:E0M1X0 8502 STA */
static js_stop_reason status_body_160(js_machine_v05c *m) {
    /* A0:83E9:E0M1X0 8502 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x02u };
    r = js_v05c_guard_code(m, 1049577u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x02u);
    r = js_v05c_write_value(m, ea, 8u, 1, (uint16_t)(m->cpu.a & 0x00FFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83EBu,0u,1u,0u));
}
/* A0:83EB:E0M1X0 8D2C21 STA */
static js_stop_reason status_body_161(js_machine_v05c *m) {
    /* A0:83EB:E0M1X0 8D2C21 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x2Cu, 0x21u };
    r = js_v05c_guard_code(m, 1049579u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x212Cu);
    r = js_v05c_write_value(m, ea, 8u, 0, (uint16_t)(m->cpu.a & 0x00FFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83EEu,0u,1u,0u));
}
/* A0:83EE:E0M1X0 C220 REP */
static js_stop_reason status_body_162(js_machine_v05c *m) {
    /* A0:83EE:E0M1X0 C220 REP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC2u, 0x20u };
    r = js_v05c_guard_code(m, 1049582u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p &= (uint8_t)~ 0x20u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83F0u,0u,0u,0u));
}
/* A0:83F0:E0M0X0 208F85 JSR */
static js_stop_reason status_body_163(js_machine_v05c *m) {
    /* A0:83F0:E0M0X0 208F85 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x8Fu, 0x85u };
    r = js_v05c_guard_code(m, 1049584u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x83F2u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Fu,0u,0u,0u));
}
/* A0:83F3:E0M0X0 A9FB83 LDA */
static js_stop_reason status_body_164(js_machine_v05c *m) {
    /* A0:83F3:E0M0X0 A9FB83 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFBu, 0x83u };
    r = js_v05c_guard_code(m, 1049587u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x83FBu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83F6u,0u,0u,0u));
}
/* A0:83F6:E0M0X0 850B STA */
static js_stop_reason status_body_165(js_machine_v05c *m) {
    /* A0:83F6:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1049590u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83F8u,0u,0u,0u));
}
/* A0:83F8:E0M0X0 4C6E81 JMP */
static js_stop_reason status_body_166(js_machine_v05c *m) {
    /* A0:83F8:E0M0X0 4C6E81 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x6Eu, 0x81u };
    r = js_v05c_guard_code(m, 1049592u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x816Eu,0u,0u,0u));
}
/* A0:83FB:E0M0X0 A585 LDA */
static js_stop_reason status_body_167(js_machine_v05c *m) {
    /* A0:83FB:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049595u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83FDu,0u,0u,0u));
}
/* A0:83FD:E0M0X0 890004 BIT */
static js_stop_reason status_body_168(js_machine_v05c *m) {
    /* A0:83FD:E0M0X0 890004 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049597u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0400u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8400u,0u,0u,0u));
}
/* A0:8400:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_169(js_machine_v05c *m) {
    /* A0:8400:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1049600u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x83FBu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8402u,0u,0u,0u));
}
/* A0:8402:E0M0X0 A585 LDA */
static js_stop_reason status_body_170(js_machine_v05c *m) {
    /* A0:8402:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049602u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8404u,0u,0u,0u));
}
/* A0:8404:E0M0X0 29FFFB AND */
static js_stop_reason status_body_171(js_machine_v05c *m) {
    /* A0:8404:E0M0X0 29FFFB AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFBu };
    r = js_v05c_guard_code(m, 1049604u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFBFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8407u,0u,0u,0u));
}
/* A0:8407:E0M0X0 8585 STA */
static js_stop_reason status_body_172(js_machine_v05c *m) {
    /* A0:8407:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049607u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8409u,0u,0u,0u));
}
/* A0:8409:E0M0X0 20C288 JSR */
static js_stop_reason status_body_173(js_machine_v05c *m) {
    /* A0:8409:E0M0X0 20C288 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC2u, 0x88u };
    r = js_v05c_guard_code(m, 1049609u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x840Bu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x88C2u,0u,0u,0u));
}
/* A0:840C:E0M0X0 A20400 LDX */
static js_stop_reason status_body_174(js_machine_v05c *m) {
    /* A0:840C:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1049612u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x840Fu,0u,0u,0u));
}
/* A0:840F:E0M0X0 20C6E0 JSR */
static js_stop_reason status_body_175(js_machine_v05c *m) {
    /* A0:840F:E0M0X0 20C6E0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC6u, 0xE0u };
    r = js_v05c_guard_code(m, 1049615u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8411u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0C6u,0u,0u,0u));
}
/* A0:8412:E0M0X0 2027A0 JSR */
static js_stop_reason status_body_176(js_machine_v05c *m) {
    /* A0:8412:E0M0X0 2027A0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x27u, 0xA0u };
    r = js_v05c_guard_code(m, 1049618u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8414u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA027u,0u,0u,0u));
}
/* A0:8415:E0M0X0 9028 BCC */
static js_stop_reason status_body_177(js_machine_v05c *m) {
    /* A0:8415:E0M0X0 9028 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x28u };
    r = js_v05c_guard_code(m, 1049621u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x843Fu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8417u,0u,0u,0u));
}
/* A0:8417:E0M0X0 A587 LDA */
static js_stop_reason status_body_178(js_machine_v05c *m) {
    /* A0:8417:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1049623u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8419u,0u,0u,0u));
}
/* A0:8419:E0M0X0 890001 BIT */
static js_stop_reason status_body_179(js_machine_v05c *m) {
    /* A0:8419:E0M0X0 890001 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1049625u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0100u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x841Cu,0u,0u,0u));
}
/* A0:841C:E0M0X0 D021 BNE */
static js_stop_reason status_body_180(js_machine_v05c *m) {
    /* A0:841C:E0M0X0 D021 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x21u };
    r = js_v05c_guard_code(m, 1049628u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x843Fu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x841Eu,0u,0u,0u));
}
/* A0:841E:E0M0X0 20D291 JSR */
static js_stop_reason status_body_181(js_machine_v05c *m) {
    /* A0:841E:E0M0X0 20D291 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD2u, 0x91u };
    r = js_v05c_guard_code(m, 1049630u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8420u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91D2u,0u,0u,0u));
}
/* A0:8421:E0M0X0 20D6B5 JSR */
static js_stop_reason status_body_182(js_machine_v05c *m) {
    /* A0:8421:E0M0X0 20D6B5 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD6u, 0xB5u };
    r = js_v05c_guard_code(m, 1049633u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8423u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xB5D6u,0u,0u,0u));
}
/* A0:8424:E0M0X0 C90000 CMP */
static js_stop_reason status_body_183(js_machine_v05c *m) {
    /* A0:8424:E0M0X0 C90000 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049636u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0000u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8427u,0u,0u,0u));
}
/* A0:8427:E0M0X0 F0F8 BEQ */
static js_stop_reason status_body_184(js_machine_v05c *m) {
    /* A0:8427:E0M0X0 F0F8 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0xF8u };
    r = js_v05c_guard_code(m, 1049639u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8421u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8429u,0u,0u,0u));
}
/* A0:8429:E0M0X0 20198D JSR */
static js_stop_reason status_body_185(js_machine_v05c *m) {
    /* A0:8429:E0M0X0 20198D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x19u, 0x8Du };
    r = js_v05c_guard_code(m, 1049641u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x842Bu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8D19u,0u,0u,0u));
}
/* A0:842C:E0M0X0 20E884 JSR */
static js_stop_reason status_body_186(js_machine_v05c *m) {
    /* A0:842C:E0M0X0 20E884 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE8u, 0x84u };
    r = js_v05c_guard_code(m, 1049644u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x842Eu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84E8u,0u,0u,0u));
}
/* A0:842F:E0M0X0 202585 JSR */
static js_stop_reason status_body_187(js_machine_v05c *m) {
    /* A0:842F:E0M0X0 202585 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x25u, 0x85u };
    r = js_v05c_guard_code(m, 1049647u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8431u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8525u,0u,0u,0u));
}
/* A0:8432:E0M0X0 20E591 JSR */
static js_stop_reason status_body_188(js_machine_v05c *m) {
    /* A0:8432:E0M0X0 20E591 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE5u, 0x91u };
    r = js_v05c_guard_code(m, 1049650u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8434u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91E5u,0u,0u,0u));
}
/* A0:8435:E0M0X0 20FC91 JSR */
static js_stop_reason status_body_189(js_machine_v05c *m) {
    /* A0:8435:E0M0X0 20FC91 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xFCu, 0x91u };
    r = js_v05c_guard_code(m, 1049653u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8437u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91FCu,0u,0u,0u));
}
/* A0:8438:E0M0X0 A587 LDA */
static js_stop_reason status_body_190(js_machine_v05c *m) {
    /* A0:8438:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1049656u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x843Au,0u,0u,0u));
}
/* A0:843A:E0M0X0 090001 ORA */
static js_stop_reason status_body_191(js_machine_v05c *m) {
    /* A0:843A:E0M0X0 090001 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1049658u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0100u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x843Du,0u,0u,0u));
}
/* A0:843D:E0M0X0 8587 STA */
static js_stop_reason status_body_192(js_machine_v05c *m) {
    /* A0:843D:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1049661u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x843Fu,0u,0u,0u));
}
/* A0:843F:E0M0X0 A20400 LDX */
static js_stop_reason status_body_193(js_machine_v05c *m) {
    /* A0:843F:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1049663u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8442u,0u,0u,0u));
}
/* A0:8442:E0M0X0 206285 JSR */
static js_stop_reason status_body_194(js_machine_v05c *m) {
    /* A0:8442:E0M0X0 206285 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x62u, 0x85u };
    r = js_v05c_guard_code(m, 1049666u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8444u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8562u,0u,0u,0u));
}
/* A0:8445:E0M0X0 20DDE0 JSR */
static js_stop_reason status_body_195(js_machine_v05c *m) {
    /* A0:8445:E0M0X0 20DDE0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xDDu, 0xE0u };
    r = js_v05c_guard_code(m, 1049669u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8447u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0DDu,0u,0u,0u));
}
/* A0:8448:E0M0X0 A585 LDA */
static js_stop_reason status_body_196(js_machine_v05c *m) {
    /* A0:8448:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049672u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x844Au,0u,0u,0u));
}
/* A0:844A:E0M0X0 090004 ORA */
static js_stop_reason status_body_197(js_machine_v05c *m) {
    /* A0:844A:E0M0X0 090004 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049674u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0400u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x844Du,0u,0u,0u));
}
/* A0:844D:E0M0X0 8585 STA */
static js_stop_reason status_body_198(js_machine_v05c *m) {
    /* A0:844D:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049677u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x844Fu,0u,0u,0u));
}
/* A0:844F:E0M0X0 4C6E81 JMP */
static js_stop_reason status_body_199(js_machine_v05c *m) {
    /* A0:844F:E0M0X0 4C6E81 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x6Eu, 0x81u };
    r = js_v05c_guard_code(m, 1049679u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x816Eu,0u,0u,0u));
}
/* A0:8452:E0M0X0 20C288 JSR */
static js_stop_reason status_body_200(js_machine_v05c *m) {
    /* A0:8452:E0M0X0 20C288 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC2u, 0x88u };
    r = js_v05c_guard_code(m, 1049682u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8454u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x88C2u,0u,0u,0u));
}
/* A0:8455:E0M0X0 A20400 LDX */
static js_stop_reason status_body_201(js_machine_v05c *m) {
    /* A0:8455:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1049685u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8458u,0u,0u,0u));
}
/* A0:8458:E0M0X0 20C6E0 JSR */
static js_stop_reason status_body_202(js_machine_v05c *m) {
    /* A0:8458:E0M0X0 20C6E0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC6u, 0xE0u };
    r = js_v05c_guard_code(m, 1049688u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x845Au);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0C6u,0u,0u,0u));
}
/* A0:845B:E0M0X0 20DDE0 JSR */
static js_stop_reason status_body_203(js_machine_v05c *m) {
    /* A0:845B:E0M0X0 20DDE0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xDDu, 0xE0u };
    r = js_v05c_guard_code(m, 1049691u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x845Du);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0DDu,0u,0u,0u));
}
/* A0:845E:E0M0X0 A585 LDA */
static js_stop_reason status_body_204(js_machine_v05c *m) {
    /* A0:845E:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049694u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8460u,0u,0u,0u));
}
/* A0:8460:E0M0X0 090004 ORA */
static js_stop_reason status_body_205(js_machine_v05c *m) {
    /* A0:8460:E0M0X0 090004 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049696u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0400u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8463u,0u,0u,0u));
}
/* A0:8463:E0M0X0 8585 STA */
static js_stop_reason status_body_206(js_machine_v05c *m) {
    /* A0:8463:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049699u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8465u,0u,0u,0u));
}
/* A0:8465:E0M0X0 A585 LDA */
static js_stop_reason status_body_207(js_machine_v05c *m) {
    /* A0:8465:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049701u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8467u,0u,0u,0u));
}
/* A0:8467:E0M0X0 890004 BIT */
static js_stop_reason status_body_208(js_machine_v05c *m) {
    /* A0:8467:E0M0X0 890004 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049703u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0400u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x846Au,0u,0u,0u));
}
/* A0:846A:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_209(js_machine_v05c *m) {
    /* A0:846A:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1049706u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8465u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x846Cu,0u,0u,0u));
}
/* A0:846C:E0M0X0 20D6B5 JSR */
static js_stop_reason status_body_210(js_machine_v05c *m) {
    /* A0:846C:E0M0X0 20D6B5 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD6u, 0xB5u };
    r = js_v05c_guard_code(m, 1049708u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x846Eu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xB5D6u,0u,0u,0u));
}
/* A0:846F:E0M0X0 C90000 CMP */
static js_stop_reason status_body_211(js_machine_v05c *m) {
    /* A0:846F:E0M0X0 C90000 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049711u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0000u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8472u,0u,0u,0u));
}
/* A0:8472:E0M0X0 F0F8 BEQ */
static js_stop_reason status_body_212(js_machine_v05c *m) {
    /* A0:8472:E0M0X0 F0F8 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0xF8u };
    r = js_v05c_guard_code(m, 1049714u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x846Cu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8474u,0u,0u,0u));
}
/* A0:8474:E0M0X0 20D291 JSR */
static js_stop_reason status_body_213(js_machine_v05c *m) {
    /* A0:8474:E0M0X0 20D291 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xD2u, 0x91u };
    r = js_v05c_guard_code(m, 1049716u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8476u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91D2u,0u,0u,0u));
}
/* A0:8477:E0M0X0 A9F090 LDA */
static js_stop_reason status_body_214(js_machine_v05c *m) {
    /* A0:8477:E0M0X0 A9F090 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xF0u, 0x90u };
    r = js_v05c_guard_code(m, 1049719u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x90F0u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x847Au,0u,0u,0u));
}
/* A0:847A:E0M0X0 8519 STA */
static js_stop_reason status_body_215(js_machine_v05c *m) {
    /* A0:847A:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1049722u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x847Cu,0u,0u,0u));
}
/* A0:847C:E0M0X0 A9A300 LDA */
static js_stop_reason status_body_216(js_machine_v05c *m) {
    /* A0:847C:E0M0X0 A9A300 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xA3u, 0x00u };
    r = js_v05c_guard_code(m, 1049724u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00A3u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x847Fu,0u,0u,0u));
}
/* A0:847F:E0M0X0 851B STA */
static js_stop_reason status_body_217(js_machine_v05c *m) {
    /* A0:847F:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1049727u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8481u,0u,0u,0u));
}
/* A0:8481:E0M0X0 A00000 LDY */
static js_stop_reason status_body_218(js_machine_v05c *m) {
    /* A0:8481:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049729u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8484u,0u,0u,0u));
}
/* A0:8484:E0M0X0 20F78D JSR */
static js_stop_reason status_body_219(js_machine_v05c *m) {
    /* A0:8484:E0M0X0 20F78D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xF7u, 0x8Du };
    r = js_v05c_guard_code(m, 1049732u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8486u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF7u,0u,0u,0u));
}
/* A0:8487:E0M0X0 A9CA0D LDA */
static js_stop_reason status_body_220(js_machine_v05c *m) {
    /* A0:8487:E0M0X0 A9CA0D LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xCAu, 0x0Du };
    r = js_v05c_guard_code(m, 1049735u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0DCAu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x848Au,0u,0u,0u));
}
/* A0:848A:E0M0X0 851D STA */
static js_stop_reason status_body_221(js_machine_v05c *m) {
    /* A0:848A:E0M0X0 851D STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Du };
    r = js_v05c_guard_code(m, 1049738u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x848Cu,0u,0u,0u));
}
/* A0:848C:E0M0X0 AD2C0D LDA */
static js_stop_reason status_body_222(js_machine_v05c *m) {
    /* A0:848C:E0M0X0 AD2C0D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x2Cu, 0x0Du };
    r = js_v05c_guard_code(m, 1049740u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D2Cu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x848Fu,0u,0u,0u));
}
/* A0:848F:E0M0X0 3A DEC */
static js_stop_reason status_body_223(js_machine_v05c *m) {
    /* A0:848F:E0M0X0 3A DEC acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x3Au };
    r = js_v05c_guard_code(m, 1049743u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u, -1);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8490u,0u,0u,0u));
}
/* A0:8490:E0M0X0 0A ASL */
static js_stop_reason status_body_224(js_machine_v05c *m) {
    /* A0:8490:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1049744u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8491u,0u,0u,0u));
}
/* A0:8491:E0M0X0 0A ASL */
static js_stop_reason status_body_225(js_machine_v05c *m) {
    /* A0:8491:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1049745u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8492u,0u,0u,0u));
}
/* A0:8492:E0M0X0 AA TAX */
static js_stop_reason status_body_226(js_machine_v05c *m) {
    /* A0:8492:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 1049746u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8493u,0u,0u,0u));
}
/* A0:8493:E0M0X0 BFFE9CA3 LDA */
static js_stop_reason status_body_227(js_machine_v05c *m) {
    /* A0:8493:E0M0X0 BFFE9CA3 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xFEu, 0x9Cu, 0xA3u };
    r = js_v05c_guard_code(m, 1049747u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA39CFEu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8497u,0u,0u,0u));
}
/* A0:8497:E0M0X0 8519 STA */
static js_stop_reason status_body_228(js_machine_v05c *m) {
    /* A0:8497:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1049751u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8499u,0u,0u,0u));
}
/* A0:8499:E0M0X0 BF009DA3 LDA */
static js_stop_reason status_body_229(js_machine_v05c *m) {
    /* A0:8499:E0M0X0 BF009DA3 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0x00u, 0x9Du, 0xA3u };
    r = js_v05c_guard_code(m, 1049753u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA39D00u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x849Du,0u,0u,0u));
}
/* A0:849D:E0M0X0 851B STA */
static js_stop_reason status_body_230(js_machine_v05c *m) {
    /* A0:849D:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1049757u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x849Fu,0u,0u,0u));
}
/* A0:849F:E0M0X0 A00000 LDY */
static js_stop_reason status_body_231(js_machine_v05c *m) {
    /* A0:849F:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049759u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84A2u,0u,0u,0u));
}
/* A0:84A2:E0M0X0 6411 STZ */
static js_stop_reason status_body_232(js_machine_v05c *m) {
    /* A0:84A2:E0M0X0 6411 STZ direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x64u, 0x11u };
    r = js_v05c_guard_code(m, 1049762u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x11u);
    r = js_v05c_write_value(m, ea, 16u, 1, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84A4u,0u,0u,0u));
}
/* A0:84A4:E0M0X0 20A58D JSR */
static js_stop_reason status_body_233(js_machine_v05c *m) {
    /* A0:84A4:E0M0X0 20A58D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xA5u, 0x8Du };
    r = js_v05c_guard_code(m, 1049764u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84A6u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DA5u,0u,0u,0u));
}
/* A0:84A7:E0M0X0 20E591 JSR */
static js_stop_reason status_body_234(js_machine_v05c *m) {
    /* A0:84A7:E0M0X0 20E591 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE5u, 0x91u };
    r = js_v05c_guard_code(m, 1049767u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84A9u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91E5u,0u,0u,0u));
}
/* A0:84AA:E0M0X0 20FC91 JSR */
static js_stop_reason status_body_235(js_machine_v05c *m) {
    /* A0:84AA:E0M0X0 20FC91 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xFCu, 0x91u };
    r = js_v05c_guard_code(m, 1049770u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84ACu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91FCu,0u,0u,0u));
}
/* A0:84AD:E0M0X0 A587 LDA */
static js_stop_reason status_body_236(js_machine_v05c *m) {
    /* A0:84AD:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1049773u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84AFu,0u,0u,0u));
}
/* A0:84AF:E0M0X0 29FFFE AND */
static js_stop_reason status_body_237(js_machine_v05c *m) {
    /* A0:84AF:E0M0X0 29FFFE AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFEu };
    r = js_v05c_guard_code(m, 1049775u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFEFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84B2u,0u,0u,0u));
}
/* A0:84B2:E0M0X0 8587 STA */
static js_stop_reason status_body_238(js_machine_v05c *m) {
    /* A0:84B2:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1049778u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84B4u,0u,0u,0u));
}
/* A0:84B4:E0M0X0 20AD85 JSR */
static js_stop_reason status_body_239(js_machine_v05c *m) {
    /* A0:84B4:E0M0X0 20AD85 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xADu, 0x85u };
    r = js_v05c_guard_code(m, 1049780u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84B6u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x85ADu,0u,0u,0u));
}
/* A0:84B7:E0M0X0 E220 SEP */
static js_stop_reason status_body_240(js_machine_v05c *m) {
    /* A0:84B7:E0M0X0 E220 SEP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE2u, 0x20u };
    r = js_v05c_guard_code(m, 1049783u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p |= 0x20u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84B9u,0u,1u,0u));
}
/* A0:84B9:E0M1X0 A502 LDA */
static js_stop_reason status_body_241(js_machine_v05c *m) {
    /* A0:84B9:E0M1X0 A502 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x02u };
    r = js_v05c_guard_code(m, 1049785u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x02u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 8u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 8u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84BBu,0u,1u,0u));
}
/* A0:84BB:E0M1X0 0915 ORA */
static js_stop_reason status_body_242(js_machine_v05c *m) {
    /* A0:84BB:E0M1X0 0915 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x15u };
    r = js_v05c_guard_code(m, 1049787u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0x00FFu) | 0x0015u) & 0x00FFu);
    js_v05c_write_a(&m->cpu, result, 8u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84BDu,0u,1u,0u));
}
/* A0:84BD:E0M1X0 8502 STA */
static js_stop_reason status_body_243(js_machine_v05c *m) {
    /* A0:84BD:E0M1X0 8502 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x02u };
    r = js_v05c_guard_code(m, 1049789u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x02u);
    r = js_v05c_write_value(m, ea, 8u, 1, (uint16_t)(m->cpu.a & 0x00FFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84BFu,0u,1u,0u));
}
/* A0:84BF:E0M1X0 8D2C21 STA */
static js_stop_reason status_body_244(js_machine_v05c *m) {
    /* A0:84BF:E0M1X0 8D2C21 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x2Cu, 0x21u };
    r = js_v05c_guard_code(m, 1049791u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x212Cu);
    r = js_v05c_write_value(m, ea, 8u, 0, (uint16_t)(m->cpu.a & 0x00FFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84C2u,0u,1u,0u));
}
/* A0:84C2:E0M1X0 C220 REP */
static js_stop_reason status_body_245(js_machine_v05c *m) {
    /* A0:84C2:E0M1X0 C220 REP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC2u, 0x20u };
    r = js_v05c_guard_code(m, 1049794u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p &= (uint8_t)~ 0x20u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84C4u,0u,0u,0u));
}
/* A0:84C4:E0M0X0 208F85 JSR */
static js_stop_reason status_body_246(js_machine_v05c *m) {
    /* A0:84C4:E0M0X0 208F85 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x8Fu, 0x85u };
    r = js_v05c_guard_code(m, 1049796u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84C6u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Fu,0u,0u,0u));
}
/* A0:84C7:E0M0X0 A9CF84 LDA */
static js_stop_reason status_body_247(js_machine_v05c *m) {
    /* A0:84C7:E0M0X0 A9CF84 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xCFu, 0x84u };
    r = js_v05c_guard_code(m, 1049799u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x84CFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84CAu,0u,0u,0u));
}
/* A0:84CA:E0M0X0 850B STA */
static js_stop_reason status_body_248(js_machine_v05c *m) {
    /* A0:84CA:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1049802u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84CCu,0u,0u,0u));
}
/* A0:84CC:E0M0X0 4C6E81 JMP */
static js_stop_reason status_body_249(js_machine_v05c *m) {
    /* A0:84CC:E0M0X0 4C6E81 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x6Eu, 0x81u };
    r = js_v05c_guard_code(m, 1049804u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x816Eu,0u,0u,0u));
}
/* A0:84CF:E0M0X0 20C288 JSR */
static js_stop_reason status_body_250(js_machine_v05c *m) {
    /* A0:84CF:E0M0X0 20C288 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC2u, 0x88u };
    r = js_v05c_guard_code(m, 1049807u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84D1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x88C2u,0u,0u,0u));
}
/* A0:84D2:E0M0X0 A20400 LDX */
static js_stop_reason status_body_251(js_machine_v05c *m) {
    /* A0:84D2:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1049810u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84D5u,0u,0u,0u));
}
/* A0:84D5:E0M0X0 20C6E0 JSR */
static js_stop_reason status_body_252(js_machine_v05c *m) {
    /* A0:84D5:E0M0X0 20C6E0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC6u, 0xE0u };
    r = js_v05c_guard_code(m, 1049813u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84D7u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0C6u,0u,0u,0u));
}
/* A0:84D8:E0M0X0 20C0A0 JSR */
static js_stop_reason status_body_253(js_machine_v05c *m) {
    /* A0:84D8:E0M0X0 20C0A0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xC0u, 0xA0u };
    r = js_v05c_guard_code(m, 1049816u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84DAu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0C0u,0u,0u,0u));
}
/* A0:84DB:E0M0X0 20DDE0 JSR */
static js_stop_reason status_body_254(js_machine_v05c *m) {
    /* A0:84DB:E0M0X0 20DDE0 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xDDu, 0xE0u };
    r = js_v05c_guard_code(m, 1049819u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x84DDu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xE0DDu,0u,0u,0u));
}
/* A0:84DE:E0M0X0 A585 LDA */
static js_stop_reason status_body_255(js_machine_v05c *m) {
    /* A0:84DE:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1049822u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84E0u,0u,0u,0u));
}
/* A0:84E0:E0M0X0 090004 ORA */
static js_stop_reason status_body_256(js_machine_v05c *m) {
    /* A0:84E0:E0M0X0 090004 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1049824u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0400u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84E3u,0u,0u,0u));
}
/* A0:84E3:E0M0X0 8585 STA */
static js_stop_reason status_body_257(js_machine_v05c *m) {
    /* A0:84E3:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1049827u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x84E5u,0u,0u,0u));
}
/* A0:84E5:E0M0X0 4C6E81 JMP */
static js_stop_reason status_body_258(js_machine_v05c *m) {
    /* A0:84E5:E0M0X0 4C6E81 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x6Eu, 0x81u };
    r = js_v05c_guard_code(m, 1049829u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x816Eu,0u,0u,0u));
}
/* A0:8525:E0M0X0 AD220D LDA */
static js_stop_reason status_body_259(js_machine_v05c *m) {
    /* A0:8525:E0M0X0 AD220D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1049893u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8528u,0u,0u,0u));
}
/* A0:8528:E0M0X0 C90700 CMP */
static js_stop_reason status_body_260(js_machine_v05c *m) {
    /* A0:8528:E0M0X0 C90700 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x07u, 0x00u };
    r = js_v05c_guard_code(m, 1049896u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0007u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x852Bu,0u,0u,0u));
}
/* A0:852B:E0M0X0 B031 BCS */
static js_stop_reason status_body_261(js_machine_v05c *m) {
    /* A0:852B:E0M0X0 B031 BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x31u };
    r = js_v05c_guard_code(m, 1049899u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x852Du,0u,0u,0u));
}
/* A0:852D:E0M0X0 0A ASL */
static js_stop_reason status_body_262(js_machine_v05c *m) {
    /* A0:852D:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1049901u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x852Eu,0u,0u,0u));
}
/* A0:852E:E0M0X0 AA TAX */
static js_stop_reason status_body_263(js_machine_v05c *m) {
    /* A0:852E:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 1049902u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x852Fu,0u,0u,0u));
}
/* A0:852F:E0M0X0 BFDA0DA0 LDA */
static js_stop_reason status_body_264(js_machine_v05c *m) {
    /* A0:852F:E0M0X0 BFDA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xDAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049903u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DDAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8533u,0u,0u,0u));
}
/* A0:8533:E0M0X0 F029 BEQ */
static js_stop_reason status_body_265(js_machine_v05c *m) {
    /* A0:8533:E0M0X0 F029 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x29u };
    r = js_v05c_guard_code(m, 1049907u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8535u,0u,0u,0u));
}
/* A0:8535:E0M0X0 BFCA0DA0 LDA */
static js_stop_reason status_body_266(js_machine_v05c *m) {
    /* A0:8535:E0M0X0 BFCA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xCAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049909u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8539u,0u,0u,0u));
}
/* A0:8539:E0M0X0 29FF00 AND */
static js_stop_reason status_body_267(js_machine_v05c *m) {
    /* A0:8539:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1049913u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x853Cu,0u,0u,0u));
}
/* A0:853C:E0M0X0 D020 BNE */
static js_stop_reason status_body_268(js_machine_v05c *m) {
    /* A0:853C:E0M0X0 D020 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x20u };
    r = js_v05c_guard_code(m, 1049916u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x853Eu,0u,0u,0u));
}
/* A0:853E:E0M0X0 BFCA0DA0 LDA */
static js_stop_reason status_body_269(js_machine_v05c *m) {
    /* A0:853E:E0M0X0 BFCA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xCAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049918u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8542u,0u,0u,0u));
}
/* A0:8542:E0M0X0 2900FF AND */
static js_stop_reason status_body_270(js_machine_v05c *m) {
    /* A0:8542:E0M0X0 2900FF AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x00u, 0xFFu };
    r = js_v05c_guard_code(m, 1049922u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFF00u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8545u,0u,0u,0u));
}
/* A0:8545:E0M0X0 EB XBA */
static js_stop_reason status_body_271(js_machine_v05c *m) {
    /* A0:8545:E0M0X0 EB XBA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEBu };
    r = js_v05c_guard_code(m, 1049925u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.a = (uint16_t)((m->cpu.a << 8) | (m->cpu.a >> 8));
    js_v05c_set_nz(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), 8u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8546u,0u,0u,0u));
}
/* A0:8546:E0M0X0 CD600D CMP */
static js_stop_reason status_body_272(js_machine_v05c *m) {
    /* A0:8546:E0M0X0 CD600D CMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xCDu, 0x60u, 0x0Du };
    r = js_v05c_guard_code(m, 1049926u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D60u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8549u,0u,0u,0u));
}
/* A0:8549:E0M0X0 F013 BEQ */
static js_stop_reason status_body_273(js_machine_v05c *m) {
    /* A0:8549:E0M0X0 F013 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x13u };
    r = js_v05c_guard_code(m, 1049929u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x854Bu,0u,0u,0u));
}
/* A0:854B:E0M0X0 9011 BCC */
static js_stop_reason status_body_274(js_machine_v05c *m) {
    /* A0:854B:E0M0X0 9011 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x11u };
    r = js_v05c_guard_code(m, 1049931u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x854Du,0u,0u,0u));
}
/* A0:854D:E0M0X0 A95291 LDA */
static js_stop_reason status_body_275(js_machine_v05c *m) {
    /* A0:854D:E0M0X0 A95291 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x52u, 0x91u };
    r = js_v05c_guard_code(m, 1049933u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x9152u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8550u,0u,0u,0u));
}
/* A0:8550:E0M0X0 8519 STA */
static js_stop_reason status_body_276(js_machine_v05c *m) {
    /* A0:8550:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1049936u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8552u,0u,0u,0u));
}
/* A0:8552:E0M0X0 A9A300 LDA */
static js_stop_reason status_body_277(js_machine_v05c *m) {
    /* A0:8552:E0M0X0 A9A300 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xA3u, 0x00u };
    r = js_v05c_guard_code(m, 1049938u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00A3u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8555u,0u,0u,0u));
}
/* A0:8555:E0M0X0 851B STA */
static js_stop_reason status_body_278(js_machine_v05c *m) {
    /* A0:8555:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1049941u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8557u,0u,0u,0u));
}
/* A0:8557:E0M0X0 A00000 LDY */
static js_stop_reason status_body_279(js_machine_v05c *m) {
    /* A0:8557:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1049943u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x855Au,0u,0u,0u));
}
/* A0:855A:E0M0X0 20F78D JSR */
static js_stop_reason status_body_280(js_machine_v05c *m) {
    /* A0:855A:E0M0X0 20F78D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xF7u, 0x8Du };
    r = js_v05c_guard_code(m, 1049946u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x855Cu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF7u,0u,0u,0u));
}
/* A0:855D:E0M0X0 60 RTS */
static js_stop_reason status_body_281(js_machine_v05c *m) {
    /* A0:855D:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1049949u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x83B8u,0u,0u,0u), JS_CTX(0xA0u,0x8432u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:855E:E0M0X0 20E88D JSR */
static js_stop_reason status_body_282(js_machine_v05c *m) {
    /* A0:855E:E0M0X0 20E88D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xE8u, 0x8Du };
    r = js_v05c_guard_code(m, 1049950u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8560u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE8u,0u,0u,0u));
}
/* A0:8561:E0M0X0 60 RTS */
static js_stop_reason status_body_283(js_machine_v05c *m) {
    /* A0:8561:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1049953u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x83B8u,0u,0u,0u), JS_CTX(0xA0u,0x8432u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:8562:E0M0X0 AD220D LDA */
static js_stop_reason status_body_284(js_machine_v05c *m) {
    /* A0:8562:E0M0X0 AD220D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1049954u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8565u,0u,0u,0u));
}
/* A0:8565:E0M0X0 C90700 CMP */
static js_stop_reason status_body_285(js_machine_v05c *m) {
    /* A0:8565:E0M0X0 C90700 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x07u, 0x00u };
    r = js_v05c_guard_code(m, 1049957u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0007u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8568u,0u,0u,0u));
}
/* A0:8568:E0M0X0 B021 BCS */
static js_stop_reason status_body_286(js_machine_v05c *m) {
    /* A0:8568:E0M0X0 B021 BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x21u };
    r = js_v05c_guard_code(m, 1049960u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x856Au,0u,0u,0u));
}
/* A0:856A:E0M0X0 0A ASL */
static js_stop_reason status_body_287(js_machine_v05c *m) {
    /* A0:856A:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1049962u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x856Bu,0u,0u,0u));
}
/* A0:856B:E0M0X0 AA TAX */
static js_stop_reason status_body_288(js_machine_v05c *m) {
    /* A0:856B:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 1049963u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x856Cu,0u,0u,0u));
}
/* A0:856C:E0M0X0 BFDA0DA0 LDA */
static js_stop_reason status_body_289(js_machine_v05c *m) {
    /* A0:856C:E0M0X0 BFDA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xDAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049964u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DDAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8570u,0u,0u,0u));
}
/* A0:8570:E0M0X0 F019 BEQ */
static js_stop_reason status_body_290(js_machine_v05c *m) {
    /* A0:8570:E0M0X0 F019 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x19u };
    r = js_v05c_guard_code(m, 1049968u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8572u,0u,0u,0u));
}
/* A0:8572:E0M0X0 BFCA0DA0 LDA */
static js_stop_reason status_body_291(js_machine_v05c *m) {
    /* A0:8572:E0M0X0 BFCA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xCAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049970u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8576u,0u,0u,0u));
}
/* A0:8576:E0M0X0 29FF00 AND */
static js_stop_reason status_body_292(js_machine_v05c *m) {
    /* A0:8576:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1049974u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8579u,0u,0u,0u));
}
/* A0:8579:E0M0X0 D010 BNE */
static js_stop_reason status_body_293(js_machine_v05c *m) {
    /* A0:8579:E0M0X0 D010 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x10u };
    r = js_v05c_guard_code(m, 1049977u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x857Bu,0u,0u,0u));
}
/* A0:857B:E0M0X0 BFCA0DA0 LDA */
static js_stop_reason status_body_294(js_machine_v05c *m) {
    /* A0:857B:E0M0X0 BFCA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xCAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1049979u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x857Fu,0u,0u,0u));
}
/* A0:857F:E0M0X0 2900FF AND */
static js_stop_reason status_body_295(js_machine_v05c *m) {
    /* A0:857F:E0M0X0 2900FF AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0x00u, 0xFFu };
    r = js_v05c_guard_code(m, 1049983u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFF00u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8582u,0u,0u,0u));
}
/* A0:8582:E0M0X0 EB XBA */
static js_stop_reason status_body_296(js_machine_v05c *m) {
    /* A0:8582:E0M0X0 EB XBA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEBu };
    r = js_v05c_guard_code(m, 1049986u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.a = (uint16_t)((m->cpu.a << 8) | (m->cpu.a >> 8));
    js_v05c_set_nz(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), 8u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8583u,0u,0u,0u));
}
/* A0:8583:E0M0X0 CD600D CMP */
static js_stop_reason status_body_297(js_machine_v05c *m) {
    /* A0:8583:E0M0X0 CD600D CMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xCDu, 0x60u, 0x0Du };
    r = js_v05c_guard_code(m, 1049987u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D60u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8586u,0u,0u,0u));
}
/* A0:8586:E0M0X0 F003 BEQ */
static js_stop_reason status_body_298(js_machine_v05c *m) {
    /* A0:8586:E0M0X0 F003 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x03u };
    r = js_v05c_guard_code(m, 1049990u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8588u,0u,0u,0u));
}
/* A0:8588:E0M0X0 9001 BCC */
static js_stop_reason status_body_299(js_machine_v05c *m) {
    /* A0:8588:E0M0X0 9001 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x01u };
    r = js_v05c_guard_code(m, 1049992u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Bu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x858Au,0u,0u,0u));
}
/* A0:858A:E0M0X0 60 RTS */
static js_stop_reason status_body_300(js_machine_v05c *m) {
    /* A0:858A:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1049994u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8445u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:858B:E0M0X0 204F8F JSR */
static js_stop_reason status_body_301(js_machine_v05c *m) {
    /* A0:858B:E0M0X0 204F8F JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x4Fu, 0x8Fu };
    r = js_v05c_guard_code(m, 1049995u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x858Du);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F4Fu,0u,0u,0u));
}
/* A0:858E:E0M0X0 60 RTS */
static js_stop_reason status_body_302(js_machine_v05c *m) {
    /* A0:858E:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1049998u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8445u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:8815:E0M0X0 A91E00 LDA */
static js_stop_reason status_body_303(js_machine_v05c *m) {
    /* A0:8815:E0M0X0 A91E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x1Eu, 0x00u };
    r = js_v05c_guard_code(m, 1050645u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x001Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8818u,0u,0u,0u));
}
/* A0:8818:E0M0X0 8D7E0D STA */
static js_stop_reason status_body_304(js_machine_v05c *m) {
    /* A0:8818:E0M0X0 8D7E0D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x7Eu, 0x0Du };
    r = js_v05c_guard_code(m, 1050648u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D7Eu);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x881Bu,0u,0u,0u));
}
/* A0:881B:E0M0X0 A90F00 LDA */
static js_stop_reason status_body_305(js_machine_v05c *m) {
    /* A0:881B:E0M0X0 A90F00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x0Fu, 0x00u };
    r = js_v05c_guard_code(m, 1050651u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x000Fu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x881Eu,0u,0u,0u));
}
/* A0:881E:E0M0X0 8D0005 STA */
static js_stop_reason status_body_306(js_machine_v05c *m) {
    /* A0:881E:E0M0X0 8D0005 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x00u, 0x05u };
    r = js_v05c_guard_code(m, 1050654u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0500u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8821u,0u,0u,0u));
}
/* A0:8821:E0M0X0 A9C700 LDA */
static js_stop_reason status_body_307(js_machine_v05c *m) {
    /* A0:8821:E0M0X0 A9C700 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xC7u, 0x00u };
    r = js_v05c_guard_code(m, 1050657u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x00C7u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8824u,0u,0u,0u));
}
/* A0:8824:E0M0X0 8D0105 STA */
static js_stop_reason status_body_308(js_machine_v05c *m) {
    /* A0:8824:E0M0X0 8D0105 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x01u, 0x05u };
    r = js_v05c_guard_code(m, 1050660u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0501u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8827u,0u,0u,0u));
}
/* A0:8827:E0M0X0 AFFE98A1 LDA */
static js_stop_reason status_body_309(js_machine_v05c *m) {
    /* A0:8827:E0M0X0 AFFE98A1 LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0xFEu, 0x98u, 0xA1u };
    r = js_v05c_guard_code(m, 1050663u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0xA198FEu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x882Bu,0u,0u,0u));
}
/* A0:882B:E0M0X0 8D0205 STA */
static js_stop_reason status_body_310(js_machine_v05c *m) {
    /* A0:882B:E0M0X0 8D0205 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x02u, 0x05u };
    r = js_v05c_guard_code(m, 1050667u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0502u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x882Eu,0u,0u,0u));
}
/* A0:882E:E0M0X0 A9FFFF LDA */
static js_stop_reason status_body_311(js_machine_v05c *m) {
    /* A0:882E:E0M0X0 A9FFFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 1050670u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8831u,0u,0u,0u));
}
/* A0:8831:E0M0X0 8D0203 STA */
static js_stop_reason status_body_312(js_machine_v05c *m) {
    /* A0:8831:E0M0X0 8D0203 STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x02u, 0x03u };
    r = js_v05c_guard_code(m, 1050673u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0302u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8834u,0u,0u,0u));
}
/* A0:8834:E0M0X0 8D800D STA */
static js_stop_reason status_body_313(js_machine_v05c *m) {
    /* A0:8834:E0M0X0 8D800D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x80u, 0x0Du };
    r = js_v05c_guard_code(m, 1050676u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D80u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8837u,0u,0u,0u));
}
/* A0:8837:E0M0X0 60 RTS */
static js_stop_reason status_body_314(js_machine_v05c *m) {
    /* A0:8837:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1050679u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0xA09Eu,0u,0u,0u), JS_CTX(0xA0u,0xA0E5u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:8DA5:E0M0X0 A519 LDA */
static js_stop_reason status_body_315(js_machine_v05c *m) {
    /* A0:8DA5:E0M0X0 A519 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x19u };
    r = js_v05c_guard_code(m, 1052069u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DA7u,0u,0u,0u));
}
/* A0:8DA7:E0M0X0 8D7A0D STA */
static js_stop_reason status_body_316(js_machine_v05c *m) {
    /* A0:8DA7:E0M0X0 8D7A0D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x7Au, 0x0Du };
    r = js_v05c_guard_code(m, 1052071u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D7Au);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DAAu,0u,0u,0u));
}
/* A0:8DAA:E0M0X0 B719 LDA */
static js_stop_reason status_body_317(js_machine_v05c *m) {
    /* A0:8DAA:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052074u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DACu,0u,0u,0u));
}
/* A0:8DAC:E0M0X0 C9FFFF CMP */
static js_stop_reason status_body_318(js_machine_v05c *m) {
    /* A0:8DAC:E0M0X0 C9FFFF CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 1052076u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0xFFFFu, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DAFu,0u,0u,0u));
}
/* A0:8DAF:E0M0X0 F036 BEQ */
static js_stop_reason status_body_319(js_machine_v05c *m) {
    /* A0:8DAF:E0M0X0 F036 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x36u };
    r = js_v05c_guard_code(m, 1052079u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE7u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB1u,0u,0u,0u));
}
/* A0:8DB1:E0M0X0 AD2A0D LDA */
static js_stop_reason status_body_320(js_machine_v05c *m) {
    /* A0:8DB1:E0M0X0 AD2A0D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x2Au, 0x0Du };
    r = js_v05c_guard_code(m, 1052081u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D2Au);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB4u,0u,0u,0u));
}
/* A0:8DB4:E0M0X0 D719 CMP */
static js_stop_reason status_body_321(js_machine_v05c *m) {
    /* A0:8DB4:E0M0X0 D719 CMP dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD7u, 0x19u };
    r = js_v05c_guard_code(m, 1052084u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB6u,0u,0u,0u));
}
/* A0:8DB6:E0M0X0 9018 BCC */
static js_stop_reason status_body_322(js_machine_v05c *m) {
    /* A0:8DB6:E0M0X0 9018 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x18u };
    r = js_v05c_guard_code(m, 1052086u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DD0u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB8u,0u,0u,0u));
}
/* A0:8DB8:E0M0X0 C8 INY */
static js_stop_reason status_body_323(js_machine_v05c *m) {
    /* A0:8DB8:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052088u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB9u,0u,0u,0u));
}
/* A0:8DB9:E0M0X0 C8 INY */
static js_stop_reason status_body_324(js_machine_v05c *m) {
    /* A0:8DB9:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052089u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DBAu,0u,0u,0u));
}
/* A0:8DBA:E0M0X0 5A PHY */
static js_stop_reason status_body_325(js_machine_v05c *m) {
    /* A0:8DBA:E0M0X0 5A PHY stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x5Au };
    r = js_v05c_guard_code(m, 1052090u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.y & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DBBu,0u,0u,0u));
}
/* A0:8DBB:E0M0X0 B719 LDA */
static js_stop_reason status_body_326(js_machine_v05c *m) {
    /* A0:8DBB:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052091u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DBDu,0u,0u,0u));
}
/* A0:8DBD:E0M0X0 8519 STA */
static js_stop_reason status_body_327(js_machine_v05c *m) {
    /* A0:8DBD:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1052093u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DBFu,0u,0u,0u));
}
/* A0:8DBF:E0M0X0 A00000 LDY */
static js_stop_reason status_body_328(js_machine_v05c *m) {
    /* A0:8DBF:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052095u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DC2u,0u,0u,0u));
}
/* A0:8DC2:E0M0X0 20F78D JSR */
static js_stop_reason status_body_329(js_machine_v05c *m) {
    /* A0:8DC2:E0M0X0 20F78D JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xF7u, 0x8Du };
    r = js_v05c_guard_code(m, 1052098u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8DC4u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF7u,0u,0u,0u));
}
/* A0:8DC5:E0M0X0 7A PLY */
static js_stop_reason status_body_330(js_machine_v05c *m) {
    /* A0:8DC5:E0M0X0 7A PLY stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x7Au };
    r = js_v05c_guard_code(m, 1052101u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DC6u,0u,0u,0u));
}
/* A0:8DC6:E0M0X0 C8 INY */
static js_stop_reason status_body_331(js_machine_v05c *m) {
    /* A0:8DC6:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052102u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DC7u,0u,0u,0u));
}
/* A0:8DC7:E0M0X0 C8 INY */
static js_stop_reason status_body_332(js_machine_v05c *m) {
    /* A0:8DC7:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052103u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DC8u,0u,0u,0u));
}
/* A0:8DC8:E0M0X0 AD7A0D LDA */
static js_stop_reason status_body_333(js_machine_v05c *m) {
    /* A0:8DC8:E0M0X0 AD7A0D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x7Au, 0x0Du };
    r = js_v05c_guard_code(m, 1052104u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D7Au);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DCBu,0u,0u,0u));
}
/* A0:8DCB:E0M0X0 8519 STA */
static js_stop_reason status_body_334(js_machine_v05c *m) {
    /* A0:8DCB:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1052107u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DCDu,0u,0u,0u));
}
/* A0:8DCD:E0M0X0 4CAA8D JMP */
static js_stop_reason status_body_335(js_machine_v05c *m) {
    /* A0:8DCD:E0M0X0 4CAA8D JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xAAu, 0x8Du };
    r = js_v05c_guard_code(m, 1052109u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DAAu,0u,0u,0u));
}
/* A0:8DD0:E0M0X0 98 TYA */
static js_stop_reason status_body_336(js_machine_v05c *m) {
    /* A0:8DD0:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 1052112u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DD1u,0u,0u,0u));
}
/* A0:8DD1:E0M0X0 4A LSR */
static js_stop_reason status_body_337(js_machine_v05c *m) {
    /* A0:8DD1:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052113u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DD2u,0u,0u,0u));
}
/* A0:8DD2:E0M0X0 AA TAX */
static js_stop_reason status_body_338(js_machine_v05c *m) {
    /* A0:8DD2:E0M0X0 AA TAX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAAu };
    r = js_v05c_guard_code(m, 1052114u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DD3u,0u,0u,0u));
}
/* A0:8DD3:E0M0X0 BFCA0DA0 LDA */
static js_stop_reason status_body_339(js_machine_v05c *m) {
    /* A0:8DD3:E0M0X0 BFCA0DA0 LDA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xBFu, 0xCAu, 0x0Du, 0xA0u };
    r = js_v05c_guard_code(m, 1052115u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0xA00DCAu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DD7u,0u,0u,0u));
}
/* A0:8DD7:E0M0X0 29FF00 AND */
static js_stop_reason status_body_340(js_machine_v05c *m) {
    /* A0:8DD7:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1052119u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DDAu,0u,0u,0u));
}
/* A0:8DDA:E0M0X0 D0DC BNE */
static js_stop_reason status_body_341(js_machine_v05c *m) {
    /* A0:8DDA:E0M0X0 D0DC BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xDCu };
    r = js_v05c_guard_code(m, 1052122u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DB8u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DDCu,0u,0u,0u));
}
/* A0:8DDC:E0M0X0 E61D INC */
static js_stop_reason status_body_342(js_machine_v05c *m) {
    /* A0:8DDC:E0M0X0 E61D INC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE6u, 0x1Du };
    r = js_v05c_guard_code(m, 1052124u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DDEu,0u,0u,0u));
}
/* A0:8DDE:E0M0X0 E61D INC */
static js_stop_reason status_body_343(js_machine_v05c *m) {
    /* A0:8DDE:E0M0X0 E61D INC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE6u, 0x1Du };
    r = js_v05c_guard_code(m, 1052126u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 1, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE0u,0u,0u,0u));
}
/* A0:8DE0:E0M0X0 C8 INY */
static js_stop_reason status_body_344(js_machine_v05c *m) {
    /* A0:8DE0:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052128u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE1u,0u,0u,0u));
}
/* A0:8DE1:E0M0X0 C8 INY */
static js_stop_reason status_body_345(js_machine_v05c *m) {
    /* A0:8DE1:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052129u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE2u,0u,0u,0u));
}
/* A0:8DE2:E0M0X0 C8 INY */
static js_stop_reason status_body_346(js_machine_v05c *m) {
    /* A0:8DE2:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052130u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE3u,0u,0u,0u));
}
/* A0:8DE3:E0M0X0 C8 INY */
static js_stop_reason status_body_347(js_machine_v05c *m) {
    /* A0:8DE3:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052131u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DE4u,0u,0u,0u));
}
/* A0:8DE4:E0M0X0 4CAA8D JMP */
static js_stop_reason status_body_348(js_machine_v05c *m) {
    /* A0:8DE4:E0M0X0 4CAA8D JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xAAu, 0x8Du };
    r = js_v05c_guard_code(m, 1052132u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DAAu,0u,0u,0u));
}
/* A0:8DE7:E0M0X0 60 RTS */
static js_stop_reason status_body_349(js_machine_v05c *m) {
    /* A0:8DE7:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1052135u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x84A7u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:8DE8:E0M0X0 A525 LDA */
static js_stop_reason status_body_350(js_machine_v05c *m) {
    /* A0:8DE8:E0M0X0 A525 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x25u };
    r = js_v05c_guard_code(m, 1052136u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x25u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DEAu,0u,0u,0u));
}
/* A0:8DEA:E0M0X0 18 CLC */
static js_stop_reason status_body_351(js_machine_v05c *m) {
    /* A0:8DEA:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052138u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DEBu,0u,0u,0u));
}
/* A0:8DEB:E0M0X0 691200 ADC */
static js_stop_reason status_body_352(js_machine_v05c *m) {
    /* A0:8DEB:E0M0X0 691200 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x12u, 0x00u };
    r = js_v05c_guard_code(m, 1052139u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0012u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DEEu,0u,0u,0u));
}
/* A0:8DEE:E0M0X0 8519 STA */
static js_stop_reason status_body_353(js_machine_v05c *m) {
    /* A0:8DEE:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1052142u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF0u,0u,0u,0u));
}
/* A0:8DF0:E0M0X0 A527 LDA */
static js_stop_reason status_body_354(js_machine_v05c *m) {
    /* A0:8DF0:E0M0X0 A527 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x27u };
    r = js_v05c_guard_code(m, 1052144u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x27u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF2u,0u,0u,0u));
}
/* A0:8DF2:E0M0X0 851B STA */
static js_stop_reason status_body_355(js_machine_v05c *m) {
    /* A0:8DF2:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1052146u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF4u,0u,0u,0u));
}
/* A0:8DF4:E0M0X0 A00000 LDY */
static js_stop_reason status_body_356(js_machine_v05c *m) {
    /* A0:8DF4:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052148u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8DF7u,0u,0u,0u));
}
/* A0:8F4F:E0M0X0 A00100 LDY */
static js_stop_reason status_body_357(js_machine_v05c *m) {
    /* A0:8F4F:E0M0X0 A00100 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1052495u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F52u,0u,0u,0u));
}
/* A0:8F52:E0M0X0 B725 LDA */
static js_stop_reason status_body_358(js_machine_v05c *m) {
    /* A0:8F52:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052498u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F54u,0u,0u,0u));
}
/* A0:8F54:E0M0X0 29FF00 AND */
static js_stop_reason status_body_359(js_machine_v05c *m) {
    /* A0:8F54:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1052500u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F57u,0u,0u,0u));
}
/* A0:8F57:E0M0X0 C90100 CMP */
static js_stop_reason status_body_360(js_machine_v05c *m) {
    /* A0:8F57:E0M0X0 C90100 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1052503u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F5Au,0u,0u,0u));
}
/* A0:8F5A:E0M0X0 D003 BNE */
static js_stop_reason status_body_361(js_machine_v05c *m) {
    /* A0:8F5A:E0M0X0 D003 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x03u };
    r = js_v05c_guard_code(m, 1052506u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F5Fu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F5Cu,0u,0u,0u));
}
/* A0:8F5C:E0M0X0 4C688F JMP */
static js_stop_reason status_body_362(js_machine_v05c *m) {
    /* A0:8F5C:E0M0X0 4C688F JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x68u, 0x8Fu };
    r = js_v05c_guard_code(m, 1052508u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F68u,0u,0u,0u));
}
/* A0:8F5F:E0M0X0 C90200 CMP */
static js_stop_reason status_body_363(js_machine_v05c *m) {
    /* A0:8F5F:E0M0X0 C90200 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1052511u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0002u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F62u,0u,0u,0u));
}
/* A0:8F62:E0M0X0 D003 BNE */
static js_stop_reason status_body_364(js_machine_v05c *m) {
    /* A0:8F62:E0M0X0 D003 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x03u };
    r = js_v05c_guard_code(m, 1052514u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F67u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F64u,0u,0u,0u));
}
/* A0:8F64:E0M0X0 4C4590 JMP */
static js_stop_reason status_body_365(js_machine_v05c *m) {
    /* A0:8F64:E0M0X0 4C4590 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x45u, 0x90u };
    r = js_v05c_guard_code(m, 1052516u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9045u,0u,0u,0u));
}
/* A0:8F67:E0M0X0 60 RTS */
static js_stop_reason status_body_366(js_machine_v05c *m) {
    /* A0:8F67:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1052519u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x858Eu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:8F68:E0M0X0 A00E00 LDY */
static js_stop_reason status_body_367(js_machine_v05c *m) {
    /* A0:8F68:E0M0X0 A00E00 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x0Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052520u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x000Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F6Bu,0u,0u,0u));
}
/* A0:8F6B:E0M0X0 B725 LDA */
static js_stop_reason status_body_368(js_machine_v05c *m) {
    /* A0:8F6B:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052523u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F6Du,0u,0u,0u));
}
/* A0:8F6D:E0M0X0 8519 STA */
static js_stop_reason status_body_369(js_machine_v05c *m) {
    /* A0:8F6D:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1052525u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F6Fu,0u,0u,0u));
}
/* A0:8F6F:E0M0X0 C8 INY */
static js_stop_reason status_body_370(js_machine_v05c *m) {
    /* A0:8F6F:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052527u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F70u,0u,0u,0u));
}
/* A0:8F70:E0M0X0 C8 INY */
static js_stop_reason status_body_371(js_machine_v05c *m) {
    /* A0:8F70:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052528u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F71u,0u,0u,0u));
}
/* A0:8F71:E0M0X0 B725 LDA */
static js_stop_reason status_body_372(js_machine_v05c *m) {
    /* A0:8F71:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052529u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F73u,0u,0u,0u));
}
/* A0:8F73:E0M0X0 851B STA */
static js_stop_reason status_body_373(js_machine_v05c *m) {
    /* A0:8F73:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1052531u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F75u,0u,0u,0u));
}
/* A0:8F75:E0M0X0 A00000 LDY */
static js_stop_reason status_body_374(js_machine_v05c *m) {
    /* A0:8F75:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052533u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F78u,0u,0u,0u));
}
/* A0:8F78:E0M0X0 A20000 LDX */
static js_stop_reason status_body_375(js_machine_v05c *m) {
    /* A0:8F78:E0M0X0 A20000 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052536u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F7Bu,0u,0u,0u));
}
/* A0:8F7B:E0M0X0 B719 LDA */
static js_stop_reason status_body_376(js_machine_v05c *m) {
    /* A0:8F7B:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052539u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F7Du,0u,0u,0u));
}
/* A0:8F7D:E0M0X0 9F33207E STA */
static js_stop_reason status_body_377(js_machine_v05c *m) {
    /* A0:8F7D:E0M0X0 9F33207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x33u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052541u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2033u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F81u,0u,0u,0u));
}
/* A0:8F81:E0M0X0 C8 INY */
static js_stop_reason status_body_378(js_machine_v05c *m) {
    /* A0:8F81:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052545u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F82u,0u,0u,0u));
}
/* A0:8F82:E0M0X0 C8 INY */
static js_stop_reason status_body_379(js_machine_v05c *m) {
    /* A0:8F82:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052546u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F83u,0u,0u,0u));
}
/* A0:8F83:E0M0X0 B719 LDA */
static js_stop_reason status_body_380(js_machine_v05c *m) {
    /* A0:8F83:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052547u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F85u,0u,0u,0u));
}
/* A0:8F85:E0M0X0 9F35207E STA */
static js_stop_reason status_body_381(js_machine_v05c *m) {
    /* A0:8F85:E0M0X0 9F35207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x35u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052549u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2035u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F89u,0u,0u,0u));
}
/* A0:8F89:E0M0X0 A90080 LDA */
static js_stop_reason status_body_382(js_machine_v05c *m) {
    /* A0:8F89:E0M0X0 A90080 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 1052553u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F8Cu,0u,0u,0u));
}
/* A0:8F8C:E0M0X0 9F36207E STA */
static js_stop_reason status_body_383(js_machine_v05c *m) {
    /* A0:8F8C:E0M0X0 9F36207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x36u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052556u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2036u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F90u,0u,0u,0u));
}
/* A0:8F90:E0M0X0 A97E00 LDA */
static js_stop_reason status_body_384(js_machine_v05c *m) {
    /* A0:8F90:E0M0X0 A97E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x7Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052560u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x007Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F93u,0u,0u,0u));
}
/* A0:8F93:E0M0X0 9F38207E STA */
static js_stop_reason status_body_385(js_machine_v05c *m) {
    /* A0:8F93:E0M0X0 9F38207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x38u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052563u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2038u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F97u,0u,0u,0u));
}
/* A0:8F97:E0M0X0 A9FFFF LDA */
static js_stop_reason status_body_386(js_machine_v05c *m) {
    /* A0:8F97:E0M0X0 A9FFFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 1052567u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F9Au,0u,0u,0u));
}
/* A0:8F9A:E0M0X0 9F39207E STA */
static js_stop_reason status_body_387(js_machine_v05c *m) {
    /* A0:8F9A:E0M0X0 9F39207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x39u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052570u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2039u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8F9Eu,0u,0u,0u));
}
/* A0:8F9E:E0M0X0 A91030 LDA */
static js_stop_reason status_body_388(js_machine_v05c *m) {
    /* A0:8F9E:E0M0X0 A91030 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x10u, 0x30u };
    r = js_v05c_guard_code(m, 1052574u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x3010u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FA1u,0u,0u,0u));
}
/* A0:8FA1:E0M0X0 9F3B207E STA */
static js_stop_reason status_body_389(js_machine_v05c *m) {
    /* A0:8FA1:E0M0X0 9F3B207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x3Bu, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052577u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E203Bu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FA5u,0u,0u,0u));
}
/* A0:8FA5:E0M0X0 A00300 LDY */
static js_stop_reason status_body_390(js_machine_v05c *m) {
    /* A0:8FA5:E0M0X0 A00300 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x03u, 0x00u };
    r = js_v05c_guard_code(m, 1052581u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0003u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FA8u,0u,0u,0u));
}
/* A0:8FA8:E0M0X0 A20A00 LDX */
static js_stop_reason status_body_391(js_machine_v05c *m) {
    /* A0:8FA8:E0M0X0 A20A00 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x0Au, 0x00u };
    r = js_v05c_guard_code(m, 1052584u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x000Au, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FABu,0u,0u,0u));
}
/* A0:8FAB:E0M0X0 B719 LDA */
static js_stop_reason status_body_392(js_machine_v05c *m) {
    /* A0:8FAB:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052587u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FADu,0u,0u,0u));
}
/* A0:8FAD:E0M0X0 9F33207E STA */
static js_stop_reason status_body_393(js_machine_v05c *m) {
    /* A0:8FAD:E0M0X0 9F33207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x33u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052589u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2033u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FB1u,0u,0u,0u));
}
/* A0:8FB1:E0M0X0 C8 INY */
static js_stop_reason status_body_394(js_machine_v05c *m) {
    /* A0:8FB1:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052593u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FB2u,0u,0u,0u));
}
/* A0:8FB2:E0M0X0 C8 INY */
static js_stop_reason status_body_395(js_machine_v05c *m) {
    /* A0:8FB2:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052594u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FB3u,0u,0u,0u));
}
/* A0:8FB3:E0M0X0 B719 LDA */
static js_stop_reason status_body_396(js_machine_v05c *m) {
    /* A0:8FB3:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052595u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FB5u,0u,0u,0u));
}
/* A0:8FB5:E0M0X0 9F35207E STA */
static js_stop_reason status_body_397(js_machine_v05c *m) {
    /* A0:8FB5:E0M0X0 9F35207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x35u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052597u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2035u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FB9u,0u,0u,0u));
}
/* A0:8FB9:E0M0X0 A90080 LDA */
static js_stop_reason status_body_398(js_machine_v05c *m) {
    /* A0:8FB9:E0M0X0 A90080 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 1052601u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FBCu,0u,0u,0u));
}
/* A0:8FBC:E0M0X0 9F36207E STA */
static js_stop_reason status_body_399(js_machine_v05c *m) {
    /* A0:8FBC:E0M0X0 9F36207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x36u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052604u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2036u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FC0u,0u,0u,0u));
}
/* A0:8FC0:E0M0X0 A97E00 LDA */
static js_stop_reason status_body_400(js_machine_v05c *m) {
    /* A0:8FC0:E0M0X0 A97E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x7Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052608u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x007Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FC3u,0u,0u,0u));
}
/* A0:8FC3:E0M0X0 9F38207E STA */
static js_stop_reason status_body_401(js_machine_v05c *m) {
    /* A0:8FC3:E0M0X0 9F38207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x38u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052611u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2038u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FC7u,0u,0u,0u));
}
/* A0:8FC7:E0M0X0 A9F8FF LDA */
static js_stop_reason status_body_402(js_machine_v05c *m) {
    /* A0:8FC7:E0M0X0 A9F8FF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xF8u, 0xFFu };
    r = js_v05c_guard_code(m, 1052615u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFF8u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FCAu,0u,0u,0u));
}
/* A0:8FCA:E0M0X0 9F39207E STA */
static js_stop_reason status_body_403(js_machine_v05c *m) {
    /* A0:8FCA:E0M0X0 9F39207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x39u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052618u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2039u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FCEu,0u,0u,0u));
}
/* A0:8FCE:E0M0X0 A90000 LDA */
static js_stop_reason status_body_404(js_machine_v05c *m) {
    /* A0:8FCE:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052622u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FD1u,0u,0u,0u));
}
/* A0:8FD1:E0M0X0 9F3B207E STA */
static js_stop_reason status_body_405(js_machine_v05c *m) {
    /* A0:8FD1:E0M0X0 9F3B207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x3Bu, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052625u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E203Bu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FD5u,0u,0u,0u));
}
/* A0:8FD5:E0M0X0 A00600 LDY */
static js_stop_reason status_body_406(js_machine_v05c *m) {
    /* A0:8FD5:E0M0X0 A00600 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1052629u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0006u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FD8u,0u,0u,0u));
}
/* A0:8FD8:E0M0X0 A21400 LDX */
static js_stop_reason status_body_407(js_machine_v05c *m) {
    /* A0:8FD8:E0M0X0 A21400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x14u, 0x00u };
    r = js_v05c_guard_code(m, 1052632u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0014u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FDBu,0u,0u,0u));
}
/* A0:8FDB:E0M0X0 B719 LDA */
static js_stop_reason status_body_408(js_machine_v05c *m) {
    /* A0:8FDB:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052635u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FDDu,0u,0u,0u));
}
/* A0:8FDD:E0M0X0 9F33207E STA */
static js_stop_reason status_body_409(js_machine_v05c *m) {
    /* A0:8FDD:E0M0X0 9F33207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x33u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052637u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2033u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FE1u,0u,0u,0u));
}
/* A0:8FE1:E0M0X0 C8 INY */
static js_stop_reason status_body_410(js_machine_v05c *m) {
    /* A0:8FE1:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052641u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FE2u,0u,0u,0u));
}
/* A0:8FE2:E0M0X0 C8 INY */
static js_stop_reason status_body_411(js_machine_v05c *m) {
    /* A0:8FE2:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052642u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FE3u,0u,0u,0u));
}
/* A0:8FE3:E0M0X0 B719 LDA */
static js_stop_reason status_body_412(js_machine_v05c *m) {
    /* A0:8FE3:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052643u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FE5u,0u,0u,0u));
}
/* A0:8FE5:E0M0X0 9F35207E STA */
static js_stop_reason status_body_413(js_machine_v05c *m) {
    /* A0:8FE5:E0M0X0 9F35207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x35u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052645u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2035u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FE9u,0u,0u,0u));
}
/* A0:8FE9:E0M0X0 A90080 LDA */
static js_stop_reason status_body_414(js_machine_v05c *m) {
    /* A0:8FE9:E0M0X0 A90080 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 1052649u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FECu,0u,0u,0u));
}
/* A0:8FEC:E0M0X0 9F36207E STA */
static js_stop_reason status_body_415(js_machine_v05c *m) {
    /* A0:8FEC:E0M0X0 9F36207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x36u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052652u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2036u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FF0u,0u,0u,0u));
}
/* A0:8FF0:E0M0X0 A97E00 LDA */
static js_stop_reason status_body_416(js_machine_v05c *m) {
    /* A0:8FF0:E0M0X0 A97E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x7Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052656u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x007Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FF3u,0u,0u,0u));
}
/* A0:8FF3:E0M0X0 9F38207E STA */
static js_stop_reason status_body_417(js_machine_v05c *m) {
    /* A0:8FF3:E0M0X0 9F38207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x38u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052659u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2038u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FF7u,0u,0u,0u));
}
/* A0:8FF7:E0M0X0 A9FEFF LDA */
static js_stop_reason status_body_418(js_machine_v05c *m) {
    /* A0:8FF7:E0M0X0 A9FEFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFEu, 0xFFu };
    r = js_v05c_guard_code(m, 1052663u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFEu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FFAu,0u,0u,0u));
}
/* A0:8FFA:E0M0X0 9F39207E STA */
static js_stop_reason status_body_419(js_machine_v05c *m) {
    /* A0:8FFA:E0M0X0 9F39207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x39u, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052666u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E2039u + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8FFEu,0u,0u,0u));
}
/* A0:8FFE:E0M0X0 A90000 LDA */
static js_stop_reason status_body_420(js_machine_v05c *m) {
    /* A0:8FFE:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052670u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9001u,0u,0u,0u));
}
/* A0:9001:E0M0X0 9F3B207E STA */
static js_stop_reason status_body_421(js_machine_v05c *m) {
    /* A0:9001:E0M0X0 9F3B207E STA abs_long_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Fu, 0x3Bu, 0x20u, 0x7Eu };
    r = js_v05c_guard_code(m, 1052673u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (0x7E203Bu + (uint32_t)m->cpu.x) & 0xFFFFFFu;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9005u,0u,0u,0u));
}
/* A0:9005:E0M0X0 A97E00 LDA */
static js_stop_reason status_body_422(js_machine_v05c *m) {
    /* A0:9005:E0M0X0 A97E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x7Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052677u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x007Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9008u,0u,0u,0u));
}
/* A0:9008:E0M0X0 8513 STA */
static js_stop_reason status_body_423(js_machine_v05c *m) {
    /* A0:9008:E0M0X0 8513 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x13u };
    r = js_v05c_guard_code(m, 1052680u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x13u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x900Au,0u,0u,0u));
}
/* A0:900A:E0M0X0 A93320 LDA */
static js_stop_reason status_body_424(js_machine_v05c *m) {
    /* A0:900A:E0M0X0 A93320 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x33u, 0x20u };
    r = js_v05c_guard_code(m, 1052682u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x2033u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x900Du,0u,0u,0u));
}
/* A0:900D:E0M0X0 8511 STA */
static js_stop_reason status_body_425(js_machine_v05c *m) {
    /* A0:900D:E0M0X0 8511 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x11u };
    r = js_v05c_guard_code(m, 1052685u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x11u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x900Fu,0u,0u,0u));
}
/* A0:900F:E0M0X0 20FACF JSR */
static js_stop_reason status_body_426(js_machine_v05c *m) {
    /* A0:900F:E0M0X0 20FACF JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xFAu, 0xCFu };
    r = js_v05c_guard_code(m, 1052687u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x9011u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xCFFAu,0u,0u,0u));
}
/* A0:9012:E0M0X0 A585 LDA */
static js_stop_reason status_body_427(js_machine_v05c *m) {
    /* A0:9012:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1052690u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9014u,0u,0u,0u));
}
/* A0:9014:E0M0X0 890400 BIT */
static js_stop_reason status_body_428(js_machine_v05c *m) {
    /* A0:9014:E0M0X0 890400 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052692u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9017u,0u,0u,0u));
}
/* A0:9017:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_429(js_machine_v05c *m) {
    /* A0:9017:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1052695u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9012u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9019u,0u,0u,0u));
}
/* A0:9019:E0M0X0 A90118 LDA */
static js_stop_reason status_body_430(js_machine_v05c *m) {
    /* A0:9019:E0M0X0 A90118 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x01u, 0x18u };
    r = js_v05c_guard_code(m, 1052697u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x1801u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x901Cu,0u,0u,0u));
}
/* A0:901C:E0M0X0 8549 STA */
static js_stop_reason status_body_431(js_machine_v05c *m) {
    /* A0:901C:E0M0X0 8549 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x49u };
    r = js_v05c_guard_code(m, 1052700u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x49u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x901Eu,0u,0u,0u));
}
/* A0:901E:E0M0X0 A90080 LDA */
static js_stop_reason status_body_432(js_machine_v05c *m) {
    /* A0:901E:E0M0X0 A90080 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 1052702u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9021u,0u,0u,0u));
}
/* A0:9021:E0M0X0 8541 STA */
static js_stop_reason status_body_433(js_machine_v05c *m) {
    /* A0:9021:E0M0X0 8541 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x41u };
    r = js_v05c_guard_code(m, 1052705u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x41u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9023u,0u,0u,0u));
}
/* A0:9023:E0M0X0 A97E00 LDA */
static js_stop_reason status_body_434(js_machine_v05c *m) {
    /* A0:9023:E0M0X0 A97E00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x7Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052707u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x007Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9026u,0u,0u,0u));
}
/* A0:9026:E0M0X0 853F STA */
static js_stop_reason status_body_435(js_machine_v05c *m) {
    /* A0:9026:E0M0X0 853F STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x3Fu };
    r = js_v05c_guard_code(m, 1052710u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x3Fu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9028u,0u,0u,0u));
}
/* A0:9028:E0M0X0 A9A148 LDA */
static js_stop_reason status_body_436(js_machine_v05c *m) {
    /* A0:9028:E0M0X0 A9A148 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xA1u, 0x48u };
    r = js_v05c_guard_code(m, 1052712u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x48A1u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x902Bu,0u,0u,0u));
}
/* A0:902B:E0M0X0 8543 STA */
static js_stop_reason status_body_437(js_machine_v05c *m) {
    /* A0:902B:E0M0X0 8543 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x43u };
    r = js_v05c_guard_code(m, 1052715u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x43u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x902Du,0u,0u,0u));
}
/* A0:902D:E0M0X0 A90C00 LDA */
static js_stop_reason status_body_438(js_machine_v05c *m) {
    /* A0:902D:E0M0X0 A90C00 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x0Cu, 0x00u };
    r = js_v05c_guard_code(m, 1052717u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x000Cu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9030u,0u,0u,0u));
}
/* A0:9030:E0M0X0 8545 STA */
static js_stop_reason status_body_439(js_machine_v05c *m) {
    /* A0:9030:E0M0X0 8545 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x45u };
    r = js_v05c_guard_code(m, 1052720u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x45u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9032u,0u,0u,0u));
}
/* A0:9032:E0M0X0 A90900 LDA */
static js_stop_reason status_body_440(js_machine_v05c *m) {
    /* A0:9032:E0M0X0 A90900 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x09u, 0x00u };
    r = js_v05c_guard_code(m, 1052722u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0009u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9035u,0u,0u,0u));
}
/* A0:9035:E0M0X0 8547 STA */
static js_stop_reason status_body_441(js_machine_v05c *m) {
    /* A0:9035:E0M0X0 8547 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x47u };
    r = js_v05c_guard_code(m, 1052725u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x47u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9037u,0u,0u,0u));
}
/* A0:9037:E0M0X0 A90800 LDA */
static js_stop_reason status_body_442(js_machine_v05c *m) {
    /* A0:9037:E0M0X0 A90800 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 1052727u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0008u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x903Au,0u,0u,0u));
}
/* A0:903A:E0M0X0 0585 ORA */
static js_stop_reason status_body_443(js_machine_v05c *m) {
    /* A0:903A:E0M0X0 0585 ORA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x05u, 0x85u };
    r = js_v05c_guard_code(m, 1052730u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | value) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x903Cu,0u,0u,0u));
}
/* A0:903C:E0M0X0 090400 ORA */
static js_stop_reason status_body_444(js_machine_v05c *m) {
    /* A0:903C:E0M0X0 090400 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052732u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0004u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x903Fu,0u,0u,0u));
}
/* A0:903F:E0M0X0 8585 STA */
static js_stop_reason status_body_445(js_machine_v05c *m) {
    /* A0:903F:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1052735u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9041u,0u,0u,0u));
}
/* A0:9041:E0M0X0 A20400 LDX */
static js_stop_reason status_body_446(js_machine_v05c *m) {
    /* A0:9041:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052737u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9044u,0u,0u,0u));
}
/* A0:9044:E0M0X0 60 RTS */
static js_stop_reason status_body_447(js_machine_v05c *m) {
    /* A0:9044:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1052740u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x858Eu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:9045:E0M0X0 A00E00 LDY */
static js_stop_reason status_body_448(js_machine_v05c *m) {
    /* A0:9045:E0M0X0 A00E00 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x0Eu, 0x00u };
    r = js_v05c_guard_code(m, 1052741u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x000Eu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9048u,0u,0u,0u));
}
/* A0:9048:E0M0X0 B725 LDA */
static js_stop_reason status_body_449(js_machine_v05c *m) {
    /* A0:9048:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052744u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x904Au,0u,0u,0u));
}
/* A0:904A:E0M0X0 8519 STA */
static js_stop_reason status_body_450(js_machine_v05c *m) {
    /* A0:904A:E0M0X0 8519 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x19u };
    r = js_v05c_guard_code(m, 1052746u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x19u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x904Cu,0u,0u,0u));
}
/* A0:904C:E0M0X0 C8 INY */
static js_stop_reason status_body_451(js_machine_v05c *m) {
    /* A0:904C:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052748u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x904Du,0u,0u,0u));
}
/* A0:904D:E0M0X0 C8 INY */
static js_stop_reason status_body_452(js_machine_v05c *m) {
    /* A0:904D:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1052749u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x904Eu,0u,0u,0u));
}
/* A0:904E:E0M0X0 B725 LDA */
static js_stop_reason status_body_453(js_machine_v05c *m) {
    /* A0:904E:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052750u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9050u,0u,0u,0u));
}
/* A0:9050:E0M0X0 851B STA */
static js_stop_reason status_body_454(js_machine_v05c *m) {
    /* A0:9050:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1052752u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9052u,0u,0u,0u));
}
/* A0:9052:E0M0X0 A00000 LDY */
static js_stop_reason status_body_455(js_machine_v05c *m) {
    /* A0:9052:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052754u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9055u,0u,0u,0u));
}
/* A0:9055:E0M0X0 B719 LDA */
static js_stop_reason status_body_456(js_machine_v05c *m) {
    /* A0:9055:E0M0X0 B719 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x19u };
    r = js_v05c_guard_code(m, 1052757u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x19u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9057u,0u,0u,0u));
}
/* A0:9057:E0M0X0 18 CLC */
static js_stop_reason status_body_457(js_machine_v05c *m) {
    /* A0:9057:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052759u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9058u,0u,0u,0u));
}
/* A0:9058:E0M0X0 654D ADC */
static js_stop_reason status_body_458(js_machine_v05c *m) {
    /* A0:9058:E0M0X0 654D ADC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x65u, 0x4Du };
    r = js_v05c_guard_code(m, 1052760u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x4Du);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x905Au,0u,0u,0u));
}
/* A0:905A:E0M0X0 8521 STA */
static js_stop_reason status_body_459(js_machine_v05c *m) {
    /* A0:905A:E0M0X0 8521 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x21u };
    r = js_v05c_guard_code(m, 1052762u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x21u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x905Cu,0u,0u,0u));
}
/* A0:905C:E0M0X0 A98100 LDA */
static js_stop_reason status_body_460(js_machine_v05c *m) {
    /* A0:905C:E0M0X0 A98100 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x81u, 0x00u };
    r = js_v05c_guard_code(m, 1052764u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0081u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x905Fu,0u,0u,0u));
}
/* A0:905F:E0M0X0 8523 STA */
static js_stop_reason status_body_461(js_machine_v05c *m) {
    /* A0:905F:E0M0X0 8523 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x23u };
    r = js_v05c_guard_code(m, 1052767u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x23u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9061u,0u,0u,0u));
}
/* A0:9061:E0M0X0 A20400 LDX */
static js_stop_reason status_body_462(js_machine_v05c *m) {
    /* A0:9061:E0M0X0 A20400 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052769u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9064u,0u,0u,0u));
}
/* A0:9064:E0M0X0 86BD STX */
static js_stop_reason status_body_463(js_machine_v05c *m) {
    /* A0:9064:E0M0X0 86BD STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0xBDu };
    r = js_v05c_guard_code(m, 1052772u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xBDu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9066u,0u,0u,0u));
}
/* A0:9066:E0M0X0 A00400 LDY */
static js_stop_reason status_body_464(js_machine_v05c *m) {
    /* A0:9066:E0M0X0 A00400 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052774u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9069u,0u,0u,0u));
}
/* A0:9069:E0M0X0 B725 LDA */
static js_stop_reason status_body_465(js_machine_v05c *m) {
    /* A0:9069:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052777u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x906Bu,0u,0u,0u));
}
/* A0:906B:E0M0X0 18 CLC */
static js_stop_reason status_body_466(js_machine_v05c *m) {
    /* A0:906B:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052779u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x906Cu,0u,0u,0u));
}
/* A0:906C:E0M0X0 6D620D ADC */
static js_stop_reason status_body_467(js_machine_v05c *m) {
    /* A0:906C:E0M0X0 6D620D ADC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x6Du, 0x62u, 0x0Du };
    r = js_v05c_guard_code(m, 1052780u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D62u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x906Fu,0u,0u,0u));
}
/* A0:906F:E0M0X0 A00200 LDY */
static js_stop_reason status_body_468(js_machine_v05c *m) {
    /* A0:906F:E0M0X0 A00200 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1052783u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0002u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9072u,0u,0u,0u));
}
/* A0:9072:E0M0X0 D725 CMP */
static js_stop_reason status_body_469(js_machine_v05c *m) {
    /* A0:9072:E0M0X0 D725 CMP dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD7u, 0x25u };
    r = js_v05c_guard_code(m, 1052786u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9074u,0u,0u,0u));
}
/* A0:9074:E0M0X0 9003 BCC */
static js_stop_reason status_body_470(js_machine_v05c *m) {
    /* A0:9074:E0M0X0 9003 BCC rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x90u, 0x03u };
    r = js_v05c_guard_code(m, 1052788u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9079u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9076u,0u,0u,0u));
}
/* A0:9076:E0M0X0 A90000 LDA */
static js_stop_reason status_body_471(js_machine_v05c *m) {
    /* A0:9076:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052790u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9079u,0u,0u,0u));
}
/* A0:9079:E0M0X0 8D620D STA */
static js_stop_reason status_body_472(js_machine_v05c *m) {
    /* A0:9079:E0M0X0 8D620D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x62u, 0x0Du };
    r = js_v05c_guard_code(m, 1052793u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D62u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x907Cu,0u,0u,0u));
}
/* A0:907C:E0M0X0 A90008 LDA */
static js_stop_reason status_body_473(js_machine_v05c *m) {
    /* A0:907C:E0M0X0 A90008 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x08u };
    r = js_v05c_guard_code(m, 1052796u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0800u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x907Fu,0u,0u,0u));
}
/* A0:907F:E0M0X0 38 SEC */
static js_stop_reason status_body_474(js_machine_v05c *m) {
    /* A0:907F:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 1052799u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9080u,0u,0u,0u));
}
/* A0:9080:E0M0X0 ED640D SBC */
static js_stop_reason status_body_475(js_machine_v05c *m) {
    /* A0:9080:E0M0X0 ED640D SBC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEDu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052800u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_sbc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9083u,0u,0u,0u));
}
/* A0:9083:E0M0X0 8D640D STA */
static js_stop_reason status_body_476(js_machine_v05c *m) {
    /* A0:9083:E0M0X0 8D640D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052803u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9086u,0u,0u,0u));
}
/* A0:9086:E0M0X0 AD640D LDA */
static js_stop_reason status_body_477(js_machine_v05c *m) {
    /* A0:9086:E0M0X0 AD640D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052806u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9089u,0u,0u,0u));
}
/* A0:9089:E0M0X0 18 CLC */
static js_stop_reason status_body_478(js_machine_v05c *m) {
    /* A0:9089:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052809u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x908Au,0u,0u,0u));
}
/* A0:908A:E0M0X0 690004 ADC */
static js_stop_reason status_body_479(js_machine_v05c *m) {
    /* A0:908A:E0M0X0 690004 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x00u, 0x04u };
    r = js_v05c_guard_code(m, 1052810u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0400u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x908Du,0u,0u,0u));
}
/* A0:908D:E0M0X0 8515 STA */
static js_stop_reason status_body_480(js_machine_v05c *m) {
    /* A0:908D:E0M0X0 8515 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x15u };
    r = js_v05c_guard_code(m, 1052813u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x908Fu,0u,0u,0u));
}
/* A0:908F:E0M0X0 A00200 LDY */
static js_stop_reason status_body_481(js_machine_v05c *m) {
    /* A0:908F:E0M0X0 A00200 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1052815u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0002u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9092u,0u,0u,0u));
}
/* A0:9092:E0M0X0 B721 LDA */
static js_stop_reason status_body_482(js_machine_v05c *m) {
    /* A0:9092:E0M0X0 B721 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x21u };
    r = js_v05c_guard_code(m, 1052818u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9094u,0u,0u,0u));
}
/* A0:9094:E0M0X0 F046 BEQ */
static js_stop_reason status_body_483(js_machine_v05c *m) {
    /* A0:9094:E0M0X0 F046 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x46u };
    r = js_v05c_guard_code(m, 1052820u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90DCu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9096u,0u,0u,0u));
}
/* A0:9096:E0M0X0 AD620D LDA */
static js_stop_reason status_body_484(js_machine_v05c *m) {
    /* A0:9096:E0M0X0 AD620D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x62u, 0x0Du };
    r = js_v05c_guard_code(m, 1052822u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D62u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9099u,0u,0u,0u));
}
/* A0:9099:E0M0X0 EB XBA */
static js_stop_reason status_body_485(js_machine_v05c *m) {
    /* A0:9099:E0M0X0 EB XBA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEBu };
    r = js_v05c_guard_code(m, 1052825u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.a = (uint16_t)((m->cpu.a << 8) | (m->cpu.a >> 8));
    js_v05c_set_nz(&m->cpu, (uint16_t)(m->cpu.a & 0x00FFu), 8u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x909Au,0u,0u,0u));
}
/* A0:909A:E0M0X0 29FF00 AND */
static js_stop_reason status_body_486(js_machine_v05c *m) {
    /* A0:909A:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1052826u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x909Du,0u,0u,0u));
}
/* A0:909D:E0M0X0 18 CLC */
static js_stop_reason status_body_487(js_machine_v05c *m) {
    /* A0:909D:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052829u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x909Eu,0u,0u,0u));
}
/* A0:909E:E0M0X0 7721 ADC */
static js_stop_reason status_body_488(js_machine_v05c *m) {
    /* A0:909E:E0M0X0 7721 ADC dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x77u, 0x21u };
    r = js_v05c_guard_code(m, 1052830u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90A0u,0u,0u,0u));
}
/* A0:90A0:E0M0X0 201D91 JSR */
static js_stop_reason status_body_489(js_machine_v05c *m) {
    /* A0:90A0:E0M0X0 201D91 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x1Du, 0x91u };
    r = js_v05c_guard_code(m, 1052832u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x90A2u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Du,0u,0u,0u));
}
/* A0:90A3:E0M0X0 A00600 LDY */
static js_stop_reason status_body_490(js_machine_v05c *m) {
    /* A0:90A3:E0M0X0 A00600 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1052835u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0006u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90A6u,0u,0u,0u));
}
/* A0:90A6:E0M0X0 B721 LDA */
static js_stop_reason status_body_491(js_machine_v05c *m) {
    /* A0:90A6:E0M0X0 B721 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x21u };
    r = js_v05c_guard_code(m, 1052838u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90A8u,0u,0u,0u));
}
/* A0:90A8:E0M0X0 A0F000 LDY */
static js_stop_reason status_body_492(js_machine_v05c *m) {
    /* A0:90A8:E0M0X0 A0F000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xF0u, 0x00u };
    r = js_v05c_guard_code(m, 1052840u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x00F0u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90ABu,0u,0u,0u));
}
/* A0:90AB:E0M0X0 20A591 JSR */
static js_stop_reason status_body_493(js_machine_v05c *m) {
    /* A0:90AB:E0M0X0 20A591 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xA5u, 0x91u };
    r = js_v05c_guard_code(m, 1052843u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x90ADu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A5u,0u,0u,0u));
}
/* A0:90AE:E0M0X0 A00600 LDY */
static js_stop_reason status_body_494(js_machine_v05c *m) {
    /* A0:90AE:E0M0X0 A00600 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1052846u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0006u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90B1u,0u,0u,0u));
}
/* A0:90B1:E0M0X0 B725 LDA */
static js_stop_reason status_body_495(js_machine_v05c *m) {
    /* A0:90B1:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052849u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90B3u,0u,0u,0u));
}
/* A0:90B3:E0M0X0 18 CLC */
static js_stop_reason status_body_496(js_machine_v05c *m) {
    /* A0:90B3:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052851u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90B4u,0u,0u,0u));
}
/* A0:90B4:E0M0X0 A00800 LDY */
static js_stop_reason status_body_497(js_machine_v05c *m) {
    /* A0:90B4:E0M0X0 A00800 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 1052852u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0008u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90B7u,0u,0u,0u));
}
/* A0:90B7:E0M0X0 7721 ADC */
static js_stop_reason status_body_498(js_machine_v05c *m) {
    /* A0:90B7:E0M0X0 7721 ADC dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x77u, 0x21u };
    r = js_v05c_guard_code(m, 1052855u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90B9u,0u,0u,0u));
}
/* A0:90B9:E0M0X0 8515 STA */
static js_stop_reason status_body_499(js_machine_v05c *m) {
    /* A0:90B9:E0M0X0 8515 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x15u };
    r = js_v05c_guard_code(m, 1052857u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90BBu,0u,0u,0u));
}
/* A0:90BB:E0M0X0 A00800 LDY */
static js_stop_reason status_body_500(js_machine_v05c *m) {
    /* A0:90BB:E0M0X0 A00800 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 1052859u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0008u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90BEu,0u,0u,0u));
}
/* A0:90BE:E0M0X0 B725 LDA */
static js_stop_reason status_body_501(js_machine_v05c *m) {
    /* A0:90BE:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052862u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90C0u,0u,0u,0u));
}
/* A0:90C0:E0M0X0 18 CLC */
static js_stop_reason status_body_502(js_machine_v05c *m) {
    /* A0:90C0:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052864u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90C1u,0u,0u,0u));
}
/* A0:90C1:E0M0X0 A00A00 LDY */
static js_stop_reason status_body_503(js_machine_v05c *m) {
    /* A0:90C1:E0M0X0 A00A00 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x0Au, 0x00u };
    r = js_v05c_guard_code(m, 1052865u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x000Au, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90C4u,0u,0u,0u));
}
/* A0:90C4:E0M0X0 7721 ADC */
static js_stop_reason status_body_504(js_machine_v05c *m) {
    /* A0:90C4:E0M0X0 7721 ADC dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x77u, 0x21u };
    r = js_v05c_guard_code(m, 1052868u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90C6u,0u,0u,0u));
}
/* A0:90C6:E0M0X0 8517 STA */
static js_stop_reason status_body_505(js_machine_v05c *m) {
    /* A0:90C6:E0M0X0 8517 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x17u };
    r = js_v05c_guard_code(m, 1052870u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x17u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90C8u,0u,0u,0u));
}
/* A0:90C8:E0M0X0 AD640D LDA */
static js_stop_reason status_body_506(js_machine_v05c *m) {
    /* A0:90C8:E0M0X0 AD640D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052872u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90CBu,0u,0u,0u));
}
/* A0:90CB:E0M0X0 4A LSR */
static js_stop_reason status_body_507(js_machine_v05c *m) {
    /* A0:90CB:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052875u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90CCu,0u,0u,0u));
}
/* A0:90CC:E0M0X0 4A LSR */
static js_stop_reason status_body_508(js_machine_v05c *m) {
    /* A0:90CC:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052876u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90CDu,0u,0u,0u));
}
/* A0:90CD:E0M0X0 4A LSR */
static js_stop_reason status_body_509(js_machine_v05c *m) {
    /* A0:90CD:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052877u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90CEu,0u,0u,0u));
}
/* A0:90CE:E0M0X0 4A LSR */
static js_stop_reason status_body_510(js_machine_v05c *m) {
    /* A0:90CE:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052878u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90CFu,0u,0u,0u));
}
/* A0:90CF:E0M0X0 18 CLC */
static js_stop_reason status_body_511(js_machine_v05c *m) {
    /* A0:90CF:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052879u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90D0u,0u,0u,0u));
}
/* A0:90D0:E0M0X0 69400E ADC */
static js_stop_reason status_body_512(js_machine_v05c *m) {
    /* A0:90D0:E0M0X0 69400E ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x40u, 0x0Eu };
    r = js_v05c_guard_code(m, 1052880u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0E40u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90D3u,0u,0u,0u));
}
/* A0:90D3:E0M0X0 851F STA */
static js_stop_reason status_body_513(js_machine_v05c *m) {
    /* A0:90D3:E0M0X0 851F STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Fu };
    r = js_v05c_guard_code(m, 1052883u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Fu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90D5u,0u,0u,0u));
}
/* A0:90D5:E0M0X0 A6BD LDX */
static js_stop_reason status_body_514(js_machine_v05c *m) {
    /* A0:90D5:E0M0X0 A6BD LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0xBDu };
    r = js_v05c_guard_code(m, 1052885u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xBDu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90D7u,0u,0u,0u));
}
/* A0:90D7:E0M0X0 2001BF JSR */
static js_stop_reason status_body_515(js_machine_v05c *m) {
    /* A0:90D7:E0M0X0 2001BF JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x01u, 0xBFu };
    r = js_v05c_guard_code(m, 1052887u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x90D9u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF01u,0u,0u,0u));
}
/* A0:90DA:E0M0X0 86BD STX */
static js_stop_reason status_body_516(js_machine_v05c *m) {
    /* A0:90DA:E0M0X0 86BD STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0xBDu };
    r = js_v05c_guard_code(m, 1052890u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xBDu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90DCu,0u,0u,0u));
}
/* A0:90DC:E0M0X0 AD640D LDA */
static js_stop_reason status_body_517(js_machine_v05c *m) {
    /* A0:90DC:E0M0X0 AD640D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052892u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90DFu,0u,0u,0u));
}
/* A0:90DF:E0M0X0 18 CLC */
static js_stop_reason status_body_518(js_machine_v05c *m) {
    /* A0:90DF:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052895u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90E0u,0u,0u,0u));
}
/* A0:90E0:E0M0X0 690000 ADC */
static js_stop_reason status_body_519(js_machine_v05c *m) {
    /* A0:90E0:E0M0X0 690000 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052896u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0000u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90E3u,0u,0u,0u));
}
/* A0:90E3:E0M0X0 8515 STA */
static js_stop_reason status_body_520(js_machine_v05c *m) {
    /* A0:90E3:E0M0X0 8515 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x15u };
    r = js_v05c_guard_code(m, 1052899u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90E5u,0u,0u,0u));
}
/* A0:90E5:E0M0X0 A00000 LDY */
static js_stop_reason status_body_521(js_machine_v05c *m) {
    /* A0:90E5:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052901u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90E8u,0u,0u,0u));
}
/* A0:90E8:E0M0X0 B721 LDA */
static js_stop_reason status_body_522(js_machine_v05c *m) {
    /* A0:90E8:E0M0X0 B721 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x21u };
    r = js_v05c_guard_code(m, 1052904u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90EAu,0u,0u,0u));
}
/* A0:90EA:E0M0X0 F030 BEQ */
static js_stop_reason status_body_523(js_machine_v05c *m) {
    /* A0:90EA:E0M0X0 F030 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x30u };
    r = js_v05c_guard_code(m, 1052906u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Cu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90ECu,0u,0u,0u));
}
/* A0:90EC:E0M0X0 201D91 JSR */
static js_stop_reason status_body_524(js_machine_v05c *m) {
    /* A0:90EC:E0M0X0 201D91 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x1Du, 0x91u };
    r = js_v05c_guard_code(m, 1052908u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x90EEu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Du,0u,0u,0u));
}
/* A0:90EF:E0M0X0 A00400 LDY */
static js_stop_reason status_body_525(js_machine_v05c *m) {
    /* A0:90EF:E0M0X0 A00400 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052911u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90F2u,0u,0u,0u));
}
/* A0:90F2:E0M0X0 B721 LDA */
static js_stop_reason status_body_526(js_machine_v05c *m) {
    /* A0:90F2:E0M0X0 B721 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x21u };
    r = js_v05c_guard_code(m, 1052914u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x21u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90F4u,0u,0u,0u));
}
/* A0:90F4:E0M0X0 A0E000 LDY */
static js_stop_reason status_body_527(js_machine_v05c *m) {
    /* A0:90F4:E0M0X0 A0E000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0xE0u, 0x00u };
    r = js_v05c_guard_code(m, 1052916u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x00E0u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90F7u,0u,0u,0u));
}
/* A0:90F7:E0M0X0 20A591 JSR */
static js_stop_reason status_body_528(js_machine_v05c *m) {
    /* A0:90F7:E0M0X0 20A591 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0xA5u, 0x91u };
    r = js_v05c_guard_code(m, 1052919u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x90F9u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A5u,0u,0u,0u));
}
/* A0:90FA:E0M0X0 A00600 LDY */
static js_stop_reason status_body_529(js_machine_v05c *m) {
    /* A0:90FA:E0M0X0 A00600 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1052922u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0006u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90FDu,0u,0u,0u));
}
/* A0:90FD:E0M0X0 B725 LDA */
static js_stop_reason status_body_530(js_machine_v05c *m) {
    /* A0:90FD:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052925u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x90FFu,0u,0u,0u));
}
/* A0:90FF:E0M0X0 8515 STA */
static js_stop_reason status_body_531(js_machine_v05c *m) {
    /* A0:90FF:E0M0X0 8515 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x15u };
    r = js_v05c_guard_code(m, 1052927u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9101u,0u,0u,0u));
}
/* A0:9101:E0M0X0 A00800 LDY */
static js_stop_reason status_body_532(js_machine_v05c *m) {
    /* A0:9101:E0M0X0 A00800 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 1052929u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0008u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9104u,0u,0u,0u));
}
/* A0:9104:E0M0X0 B725 LDA */
static js_stop_reason status_body_533(js_machine_v05c *m) {
    /* A0:9104:E0M0X0 B725 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x25u };
    r = js_v05c_guard_code(m, 1052932u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x25u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9106u,0u,0u,0u));
}
/* A0:9106:E0M0X0 8517 STA */
static js_stop_reason status_body_534(js_machine_v05c *m) {
    /* A0:9106:E0M0X0 8517 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x17u };
    r = js_v05c_guard_code(m, 1052934u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x17u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9108u,0u,0u,0u));
}
/* A0:9108:E0M0X0 AD640D LDA */
static js_stop_reason status_body_535(js_machine_v05c *m) {
    /* A0:9108:E0M0X0 AD640D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x64u, 0x0Du };
    r = js_v05c_guard_code(m, 1052936u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D64u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x910Bu,0u,0u,0u));
}
/* A0:910B:E0M0X0 4A LSR */
static js_stop_reason status_body_536(js_machine_v05c *m) {
    /* A0:910B:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052939u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x910Cu,0u,0u,0u));
}
/* A0:910C:E0M0X0 4A LSR */
static js_stop_reason status_body_537(js_machine_v05c *m) {
    /* A0:910C:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052940u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x910Du,0u,0u,0u));
}
/* A0:910D:E0M0X0 4A LSR */
static js_stop_reason status_body_538(js_machine_v05c *m) {
    /* A0:910D:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052941u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x910Eu,0u,0u,0u));
}
/* A0:910E:E0M0X0 4A LSR */
static js_stop_reason status_body_539(js_machine_v05c *m) {
    /* A0:910E:E0M0X0 4A LSR acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Au };
    r = js_v05c_guard_code(m, 1052942u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_lsr(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x910Fu,0u,0u,0u));
}
/* A0:910F:E0M0X0 18 CLC */
static js_stop_reason status_body_540(js_machine_v05c *m) {
    /* A0:910F:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052943u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9110u,0u,0u,0u));
}
/* A0:9110:E0M0X0 69000C ADC */
static js_stop_reason status_body_541(js_machine_v05c *m) {
    /* A0:9110:E0M0X0 69000C ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x00u, 0x0Cu };
    r = js_v05c_guard_code(m, 1052944u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0C00u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9113u,0u,0u,0u));
}
/* A0:9113:E0M0X0 851F STA */
static js_stop_reason status_body_542(js_machine_v05c *m) {
    /* A0:9113:E0M0X0 851F STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Fu };
    r = js_v05c_guard_code(m, 1052947u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Fu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9115u,0u,0u,0u));
}
/* A0:9115:E0M0X0 A6BD LDX */
static js_stop_reason status_body_543(js_machine_v05c *m) {
    /* A0:9115:E0M0X0 A6BD LDX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA6u, 0xBDu };
    r = js_v05c_guard_code(m, 1052949u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xBDu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9117u,0u,0u,0u));
}
/* A0:9117:E0M0X0 2001BF JSR */
static js_stop_reason status_body_544(js_machine_v05c *m) {
    /* A0:9117:E0M0X0 2001BF JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x01u, 0xBFu };
    r = js_v05c_guard_code(m, 1052951u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x9119u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF01u,0u,0u,0u));
}
/* A0:911A:E0M0X0 86BD STX */
static js_stop_reason status_body_545(js_machine_v05c *m) {
    /* A0:911A:E0M0X0 86BD STX direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x86u, 0xBDu };
    r = js_v05c_guard_code(m, 1052954u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xBDu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.x & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Cu,0u,0u,0u));
}
/* A0:911C:E0M0X0 60 RTS */
static js_stop_reason status_body_546(js_machine_v05c *m) {
    /* A0:911C:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1052956u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x858Eu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:911D:E0M0X0 0A ASL */
static js_stop_reason status_body_547(js_machine_v05c *m) {
    /* A0:911D:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1052957u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Eu,0u,0u,0u));
}
/* A0:911E:E0M0X0 48 PHA */
static js_stop_reason status_body_548(js_machine_v05c *m) {
    /* A0:911E:E0M0X0 48 PHA stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x48u };
    r = js_v05c_guard_code(m, 1052958u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.a & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x911Fu,0u,0u,0u));
}
/* A0:911F:E0M0X0 0A ASL */
static js_stop_reason status_body_549(js_machine_v05c *m) {
    /* A0:911F:E0M0X0 0A ASL acc */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x0Au };
    r = js_v05c_guard_code(m, 1052959u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_asl(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9120u,0u,0u,0u));
}
/* A0:9120:E0M0X0 18 CLC */
static js_stop_reason status_body_550(js_machine_v05c *m) {
    /* A0:9120:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052960u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9121u,0u,0u,0u));
}
/* A0:9121:E0M0X0 6301 ADC */
static js_stop_reason status_body_551(js_machine_v05c *m) {
    /* A0:9121:E0M0X0 6301 ADC stack_rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x63u, 0x01u };
    r = js_v05c_guard_code(m, 1052961u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (uint16_t)(m->cpu.sp + 0x01u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9123u,0u,0u,0u));
}
/* A0:9123:E0M0X0 8301 STA */
static js_stop_reason status_body_552(js_machine_v05c *m) {
    /* A0:9123:E0M0X0 8301 STA stack_rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x83u, 0x01u };
    r = js_v05c_guard_code(m, 1052963u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = (uint16_t)(m->cpu.sp + 0x01u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9125u,0u,0u,0u));
}
/* A0:9125:E0M0X0 68 PLA */
static js_stop_reason status_body_553(js_machine_v05c *m) {
    /* A0:9125:E0M0X0 68 PLA stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x68u };
    r = js_v05c_guard_code(m, 1052965u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9126u,0u,0u,0u));
}
/* A0:9126:E0M0X0 18 CLC */
static js_stop_reason status_body_554(js_machine_v05c *m) {
    /* A0:9126:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052966u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9127u,0u,0u,0u));
}
/* A0:9127:E0M0X0 654F ADC */
static js_stop_reason status_body_555(js_machine_v05c *m) {
    /* A0:9127:E0M0X0 654F ADC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x65u, 0x4Fu };
    r = js_v05c_guard_code(m, 1052967u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x4Fu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9129u,0u,0u,0u));
}
/* A0:9129:E0M0X0 8529 STA */
static js_stop_reason status_body_556(js_machine_v05c *m) {
    /* A0:9129:E0M0X0 8529 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x29u };
    r = js_v05c_guard_code(m, 1052969u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x29u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x912Bu,0u,0u,0u));
}
/* A0:912B:E0M0X0 A98500 LDA */
static js_stop_reason status_body_557(js_machine_v05c *m) {
    /* A0:912B:E0M0X0 A98500 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x85u, 0x00u };
    r = js_v05c_guard_code(m, 1052971u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0085u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x912Eu,0u,0u,0u));
}
/* A0:912E:E0M0X0 852B STA */
static js_stop_reason status_body_558(js_machine_v05c *m) {
    /* A0:912E:E0M0X0 852B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x2Bu };
    r = js_v05c_guard_code(m, 1052974u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x2Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9130u,0u,0u,0u));
}
/* A0:9130:E0M0X0 A00000 LDY */
static js_stop_reason status_body_559(js_machine_v05c *m) {
    /* A0:9130:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1052976u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9133u,0u,0u,0u));
}
/* A0:9133:E0M0X0 B729 LDA */
static js_stop_reason status_body_560(js_machine_v05c *m) {
    /* A0:9133:E0M0X0 B729 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x29u };
    r = js_v05c_guard_code(m, 1052979u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x29u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9135u,0u,0u,0u));
}
/* A0:9135:E0M0X0 851B STA */
static js_stop_reason status_body_561(js_machine_v05c *m) {
    /* A0:9135:E0M0X0 851B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Bu };
    r = js_v05c_guard_code(m, 1052981u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9137u,0u,0u,0u));
}
/* A0:9137:E0M0X0 A00200 LDY */
static js_stop_reason status_body_562(js_machine_v05c *m) {
    /* A0:9137:E0M0X0 A00200 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1052983u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0002u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x913Au,0u,0u,0u));
}
/* A0:913A:E0M0X0 B729 LDA */
static js_stop_reason status_body_563(js_machine_v05c *m) {
    /* A0:913A:E0M0X0 B729 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x29u };
    r = js_v05c_guard_code(m, 1052986u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x29u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x913Cu,0u,0u,0u));
}
/* A0:913C:E0M0X0 29FF00 AND */
static js_stop_reason status_body_564(js_machine_v05c *m) {
    /* A0:913C:E0M0X0 29FF00 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0x00u };
    r = js_v05c_guard_code(m, 1052988u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0x00FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x913Fu,0u,0u,0u));
}
/* A0:913F:E0M0X0 8553 STA */
static js_stop_reason status_body_565(js_machine_v05c *m) {
    /* A0:913F:E0M0X0 8553 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x53u };
    r = js_v05c_guard_code(m, 1052991u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x53u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9141u,0u,0u,0u));
}
/* A0:9141:E0M0X0 A00400 LDY */
static js_stop_reason status_body_566(js_machine_v05c *m) {
    /* A0:9141:E0M0X0 A00400 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1052993u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9144u,0u,0u,0u));
}
/* A0:9144:E0M0X0 B729 LDA */
static js_stop_reason status_body_567(js_machine_v05c *m) {
    /* A0:9144:E0M0X0 B729 LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x29u };
    r = js_v05c_guard_code(m, 1052996u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x29u, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9146u,0u,0u,0u));
}
/* A0:9146:E0M0X0 18 CLC */
static js_stop_reason status_body_568(js_machine_v05c *m) {
    /* A0:9146:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1052998u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9147u,0u,0u,0u));
}
/* A0:9147:E0M0X0 6551 ADC */
static js_stop_reason status_body_569(js_machine_v05c *m) {
    /* A0:9147:E0M0X0 6551 ADC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x65u, 0x51u };
    r = js_v05c_guard_code(m, 1052999u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x51u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9149u,0u,0u,0u));
}
/* A0:9149:E0M0X0 851D STA */
static js_stop_reason status_body_570(js_machine_v05c *m) {
    /* A0:9149:E0M0X0 851D STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Du };
    r = js_v05c_guard_code(m, 1053001u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x914Bu,0u,0u,0u));
}
/* A0:914B:E0M0X0 A98600 LDA */
static js_stop_reason status_body_571(js_machine_v05c *m) {
    /* A0:914B:E0M0X0 A98600 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x86u, 0x00u };
    r = js_v05c_guard_code(m, 1053003u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0086u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x914Eu,0u,0u,0u));
}
/* A0:914E:E0M0X0 851F STA */
static js_stop_reason status_body_572(js_machine_v05c *m) {
    /* A0:914E:E0M0X0 851F STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Fu };
    r = js_v05c_guard_code(m, 1053006u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Fu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9150u,0u,0u,0u));
}
/* A0:9150:E0M0X0 A585 LDA */
static js_stop_reason status_body_573(js_machine_v05c *m) {
    /* A0:9150:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053008u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9152u,0u,0u,0u));
}
/* A0:9152:E0M0X0 890100 BIT */
static js_stop_reason status_body_574(js_machine_v05c *m) {
    /* A0:9152:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053010u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9155u,0u,0u,0u));
}
/* A0:9155:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_575(js_machine_v05c *m) {
    /* A0:9155:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1053013u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9150u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9157u,0u,0u,0u));
}
/* A0:9157:E0M0X0 A00400 LDY */
static js_stop_reason status_body_576(js_machine_v05c *m) {
    /* A0:9157:E0M0X0 A00400 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1053015u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x915Au,0u,0u,0u));
}
/* A0:915A:E0M0X0 B71D LDA */
static js_stop_reason status_body_577(js_machine_v05c *m) {
    /* A0:915A:E0M0X0 B71D LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x1Du };
    r = js_v05c_guard_code(m, 1053018u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x1Du, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x915Cu,0u,0u,0u));
}
/* A0:915C:E0M0X0 F027 BEQ */
static js_stop_reason status_body_578(js_machine_v05c *m) {
    /* A0:915C:E0M0X0 F027 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x27u };
    r = js_v05c_guard_code(m, 1053020u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9185u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x915Eu,0u,0u,0u));
}
/* A0:915E:E0M0X0 8539 STA */
static js_stop_reason status_body_579(js_machine_v05c *m) {
    /* A0:915E:E0M0X0 8539 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x39u };
    r = js_v05c_guard_code(m, 1053022u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x39u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9160u,0u,0u,0u));
}
/* A0:9160:E0M0X0 A90118 LDA */
static js_stop_reason status_body_580(js_machine_v05c *m) {
    /* A0:9160:E0M0X0 A90118 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x01u, 0x18u };
    r = js_v05c_guard_code(m, 1053024u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x1801u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9163u,0u,0u,0u));
}
/* A0:9163:E0M0X0 8531 STA */
static js_stop_reason status_body_581(js_machine_v05c *m) {
    /* A0:9163:E0M0X0 8531 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x31u };
    r = js_v05c_guard_code(m, 1053027u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x31u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9165u,0u,0u,0u));
}
/* A0:9165:E0M0X0 A00200 LDY */
static js_stop_reason status_body_582(js_machine_v05c *m) {
    /* A0:9165:E0M0X0 A00200 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1053029u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0002u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9168u,0u,0u,0u));
}
/* A0:9168:E0M0X0 B71D LDA */
static js_stop_reason status_body_583(js_machine_v05c *m) {
    /* A0:9168:E0M0X0 B71D LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x1Du };
    r = js_v05c_guard_code(m, 1053032u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x1Du, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x916Au,0u,0u,0u));
}
/* A0:916A:E0M0X0 8533 STA */
static js_stop_reason status_body_584(js_machine_v05c *m) {
    /* A0:916A:E0M0X0 8533 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x33u };
    r = js_v05c_guard_code(m, 1053034u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x33u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x916Cu,0u,0u,0u));
}
/* A0:916C:E0M0X0 A00000 LDY */
static js_stop_reason status_body_585(js_machine_v05c *m) {
    /* A0:916C:E0M0X0 A00000 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1053036u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x916Fu,0u,0u,0u));
}
/* A0:916F:E0M0X0 B71D LDA */
static js_stop_reason status_body_586(js_machine_v05c *m) {
    /* A0:916F:E0M0X0 B71D LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x1Du };
    r = js_v05c_guard_code(m, 1053039u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x1Du, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9171u,0u,0u,0u));
}
/* A0:9171:E0M0X0 8535 STA */
static js_stop_reason status_body_587(js_machine_v05c *m) {
    /* A0:9171:E0M0X0 8535 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x35u };
    r = js_v05c_guard_code(m, 1053041u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x35u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9173u,0u,0u,0u));
}
/* A0:9173:E0M0X0 A515 LDA */
static js_stop_reason status_body_588(js_machine_v05c *m) {
    /* A0:9173:E0M0X0 A515 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x15u };
    r = js_v05c_guard_code(m, 1053043u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9175u,0u,0u,0u));
}
/* A0:9175:E0M0X0 8537 STA */
static js_stop_reason status_body_589(js_machine_v05c *m) {
    /* A0:9175:E0M0X0 8537 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x37u };
    r = js_v05c_guard_code(m, 1053045u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x37u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9177u,0u,0u,0u));
}
/* A0:9177:E0M0X0 A585 LDA */
static js_stop_reason status_body_590(js_machine_v05c *m) {
    /* A0:9177:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053047u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9179u,0u,0u,0u));
}
/* A0:9179:E0M0X0 090100 ORA */
static js_stop_reason status_body_591(js_machine_v05c *m) {
    /* A0:9179:E0M0X0 090100 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053049u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0001u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x917Cu,0u,0u,0u));
}
/* A0:917C:E0M0X0 8585 STA */
static js_stop_reason status_body_592(js_machine_v05c *m) {
    /* A0:917C:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1053052u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x917Eu,0u,0u,0u));
}
/* A0:917E:E0M0X0 A585 LDA */
static js_stop_reason status_body_593(js_machine_v05c *m) {
    /* A0:917E:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053054u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9180u,0u,0u,0u));
}
/* A0:9180:E0M0X0 890100 BIT */
static js_stop_reason status_body_594(js_machine_v05c *m) {
    /* A0:9180:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053056u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9183u,0u,0u,0u));
}
/* A0:9183:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_595(js_machine_v05c *m) {
    /* A0:9183:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1053059u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x917Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9185u,0u,0u,0u));
}
/* A0:9185:E0M0X0 A00600 LDY */
static js_stop_reason status_body_596(js_machine_v05c *m) {
    /* A0:9185:E0M0X0 A00600 LDY imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA0u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1053061u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, 0x0006u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9188u,0u,0u,0u));
}
/* A0:9188:E0M0X0 B71D LDA */
static js_stop_reason status_body_597(js_machine_v05c *m) {
    /* A0:9188:E0M0X0 B71D LDA dir_ind_long_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB7u, 0x1Du };
    r = js_v05c_guard_code(m, 1053064u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = 0u;
    r = js_v05c_addr_dir_ind_long_y(m, 0x1Du, &ea);
    if (r != JS_STOP_NONE) return r;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x918Au,0u,0u,0u));
}
/* A0:918A:E0M0X0 F018 BEQ */
static js_stop_reason status_body_598(js_machine_v05c *m) {
    /* A0:918A:E0M0X0 F018 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x18u };
    r = js_v05c_guard_code(m, 1053066u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A4u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x918Cu,0u,0u,0u));
}
/* A0:918C:E0M0X0 8539 STA */
static js_stop_reason status_body_599(js_machine_v05c *m) {
    /* A0:918C:E0M0X0 8539 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x39u };
    r = js_v05c_guard_code(m, 1053068u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x39u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x918Eu,0u,0u,0u));
}
/* A0:918E:E0M0X0 A515 LDA */
static js_stop_reason status_body_600(js_machine_v05c *m) {
    /* A0:918E:E0M0X0 A515 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x15u };
    r = js_v05c_guard_code(m, 1053070u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9190u,0u,0u,0u));
}
/* A0:9190:E0M0X0 18 CLC */
static js_stop_reason status_body_601(js_machine_v05c *m) {
    /* A0:9190:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1053072u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9191u,0u,0u,0u));
}
/* A0:9191:E0M0X0 690001 ADC */
static js_stop_reason status_body_602(js_machine_v05c *m) {
    /* A0:9191:E0M0X0 690001 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1053073u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0100u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9194u,0u,0u,0u));
}
/* A0:9194:E0M0X0 8537 STA */
static js_stop_reason status_body_603(js_machine_v05c *m) {
    /* A0:9194:E0M0X0 8537 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x37u };
    r = js_v05c_guard_code(m, 1053076u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x37u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9196u,0u,0u,0u));
}
/* A0:9196:E0M0X0 A585 LDA */
static js_stop_reason status_body_604(js_machine_v05c *m) {
    /* A0:9196:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053078u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9198u,0u,0u,0u));
}
/* A0:9198:E0M0X0 090100 ORA */
static js_stop_reason status_body_605(js_machine_v05c *m) {
    /* A0:9198:E0M0X0 090100 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053080u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0001u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x919Bu,0u,0u,0u));
}
/* A0:919B:E0M0X0 8585 STA */
static js_stop_reason status_body_606(js_machine_v05c *m) {
    /* A0:919B:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1053083u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x919Du,0u,0u,0u));
}
/* A0:919D:E0M0X0 A585 LDA */
static js_stop_reason status_body_607(js_machine_v05c *m) {
    /* A0:919D:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053085u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x919Fu,0u,0u,0u));
}
/* A0:919F:E0M0X0 890100 BIT */
static js_stop_reason status_body_608(js_machine_v05c *m) {
    /* A0:919F:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053087u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A2u,0u,0u,0u));
}
/* A0:91A2:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_609(js_machine_v05c *m) {
    /* A0:91A2:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1053090u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x919Du,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A4u,0u,0u,0u));
}
/* A0:91A4:E0M0X0 60 RTS */
static js_stop_reason status_body_610(js_machine_v05c *m) {
    /* A0:91A4:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1053092u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x90A3u,0u,0u,0u), JS_CTX(0xA0u,0x90EFu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:91A5:E0M0X0 5A PHY */
static js_stop_reason status_body_611(js_machine_v05c *m) {
    /* A0:91A5:E0M0X0 5A PHY stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x5Au };
    r = js_v05c_guard_code(m, 1053093u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.y & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A6u,0u,0u,0u));
}
/* A0:91A6:E0M0X0 A8 TAY */
static js_stop_reason status_body_612(js_machine_v05c *m) {
    /* A0:91A6:E0M0X0 A8 TAY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA8u };
    r = js_v05c_guard_code(m, 1053094u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A7u,0u,0u,0u));
}
/* A0:91A7:E0M0X0 A585 LDA */
static js_stop_reason status_body_613(js_machine_v05c *m) {
    /* A0:91A7:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053095u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A9u,0u,0u,0u));
}
/* A0:91A9:E0M0X0 890100 BIT */
static js_stop_reason status_body_614(js_machine_v05c *m) {
    /* A0:91A9:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053097u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91ACu,0u,0u,0u));
}
/* A0:91AC:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_615(js_machine_v05c *m) {
    /* A0:91AC:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1053100u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91A7u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91AEu,0u,0u,0u));
}
/* A0:91AE:E0M0X0 98 TYA */
static js_stop_reason status_body_616(js_machine_v05c *m) {
    /* A0:91AE:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 1053102u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91AFu,0u,0u,0u));
}
/* A0:91AF:E0M0X0 8535 STA */
static js_stop_reason status_body_617(js_machine_v05c *m) {
    /* A0:91AF:E0M0X0 8535 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x35u };
    r = js_v05c_guard_code(m, 1053103u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x35u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91B1u,0u,0u,0u));
}
/* A0:91B1:E0M0X0 7A PLY */
static js_stop_reason status_body_618(js_machine_v05c *m) {
    /* A0:91B1:E0M0X0 7A PLY stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x7Au };
    r = js_v05c_guard_code(m, 1053105u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint16_t pulled = 0u;
    r = js_v05c_pull16(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, pulled, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91B2u,0u,0u,0u));
}
/* A0:91B2:E0M0X0 843D STY */
static js_stop_reason status_body_619(js_machine_v05c *m) {
    /* A0:91B2:E0M0X0 843D STY direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x84u, 0x3Du };
    r = js_v05c_guard_code(m, 1053106u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x3Du);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.y & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91B4u,0u,0u,0u));
}
/* A0:91B4:E0M0X0 A90022 LDA */
static js_stop_reason status_body_620(js_machine_v05c *m) {
    /* A0:91B4:E0M0X0 A90022 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x22u };
    r = js_v05c_guard_code(m, 1053108u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x2200u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91B7u,0u,0u,0u));
}
/* A0:91B7:E0M0X0 8531 STA */
static js_stop_reason status_body_621(js_machine_v05c *m) {
    /* A0:91B7:E0M0X0 8531 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x31u };
    r = js_v05c_guard_code(m, 1053111u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x31u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91B9u,0u,0u,0u));
}
/* A0:91B9:E0M0X0 A98100 LDA */
static js_stop_reason status_body_622(js_machine_v05c *m) {
    /* A0:91B9:E0M0X0 A98100 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x81u, 0x00u };
    r = js_v05c_guard_code(m, 1053113u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0081u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91BCu,0u,0u,0u));
}
/* A0:91BC:E0M0X0 8533 STA */
static js_stop_reason status_body_623(js_machine_v05c *m) {
    /* A0:91BC:E0M0X0 8533 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x33u };
    r = js_v05c_guard_code(m, 1053116u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x33u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91BEu,0u,0u,0u));
}
/* A0:91BE:E0M0X0 A92000 LDA */
static js_stop_reason status_body_624(js_machine_v05c *m) {
    /* A0:91BE:E0M0X0 A92000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x20u, 0x00u };
    r = js_v05c_guard_code(m, 1053118u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0020u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91C1u,0u,0u,0u));
}
/* A0:91C1:E0M0X0 8539 STA */
static js_stop_reason status_body_625(js_machine_v05c *m) {
    /* A0:91C1:E0M0X0 8539 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x39u };
    r = js_v05c_guard_code(m, 1053121u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x39u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91C3u,0u,0u,0u));
}
/* A0:91C3:E0M0X0 A585 LDA */
static js_stop_reason status_body_626(js_machine_v05c *m) {
    /* A0:91C3:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053123u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91C5u,0u,0u,0u));
}
/* A0:91C5:E0M0X0 090100 ORA */
static js_stop_reason status_body_627(js_machine_v05c *m) {
    /* A0:91C5:E0M0X0 090100 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053125u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0001u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91C8u,0u,0u,0u));
}
/* A0:91C8:E0M0X0 8585 STA */
static js_stop_reason status_body_628(js_machine_v05c *m) {
    /* A0:91C8:E0M0X0 8585 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x85u };
    r = js_v05c_guard_code(m, 1053128u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91CAu,0u,0u,0u));
}
/* A0:91CA:E0M0X0 A585 LDA */
static js_stop_reason status_body_629(js_machine_v05c *m) {
    /* A0:91CA:E0M0X0 A585 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x85u };
    r = js_v05c_guard_code(m, 1053130u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x85u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91CCu,0u,0u,0u));
}
/* A0:91CC:E0M0X0 890100 BIT */
static js_stop_reason status_body_630(js_machine_v05c *m) {
    /* A0:91CC:E0M0X0 890100 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x01u, 0x00u };
    r = js_v05c_guard_code(m, 1053132u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0001u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91CFu,0u,0u,0u));
}
/* A0:91CF:E0M0X0 D0F9 BNE */
static js_stop_reason status_body_631(js_machine_v05c *m) {
    /* A0:91CF:E0M0X0 D0F9 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0xF9u };
    r = js_v05c_guard_code(m, 1053135u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91CAu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x91D1u,0u,0u,0u));
}
/* A0:91D1:E0M0X0 60 RTS */
static js_stop_reason status_body_632(js_machine_v05c *m) {
    /* A0:91D1:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1053137u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x90AEu,0u,0u,0u), JS_CTX(0xA0u,0x90FAu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A027:E0M0X0 C230 REP */
static js_stop_reason status_body_633(js_machine_v05c *m) {
    /* A0:A027:E0M0X0 C230 REP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC2u, 0x30u };
    r = js_v05c_guard_code(m, 1056807u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p &= (uint8_t)~ 0x30u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA029u,0u,0u,0u));
}
/* A0:A029:E0M0X0 A5D5 LDA */
static js_stop_reason status_body_634(js_machine_v05c *m) {
    /* A0:A029:E0M0X0 A5D5 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0xD5u };
    r = js_v05c_guard_code(m, 1056809u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xD5u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA02Bu,0u,0u,0u));
}
/* A0:A02B:E0M0X0 892000 BIT */
static js_stop_reason status_body_635(js_machine_v05c *m) {
    /* A0:A02B:E0M0X0 892000 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x20u, 0x00u };
    r = js_v05c_guard_code(m, 1056811u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0020u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA02Eu,0u,0u,0u));
}
/* A0:A02E:E0M0X0 F00A BEQ */
static js_stop_reason status_body_636(js_machine_v05c *m) {
    /* A0:A02E:E0M0X0 F00A BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x0Au };
    r = js_v05c_guard_code(m, 1056814u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA03Au,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA030u,0u,0u,0u));
}
/* A0:A030:E0M0X0 A97682 LDA */
static js_stop_reason status_body_637(js_machine_v05c *m) {
    /* A0:A030:E0M0X0 A97682 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x76u, 0x82u };
    r = js_v05c_guard_code(m, 1056816u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8276u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA033u,0u,0u,0u));
}
/* A0:A033:E0M0X0 850B STA */
static js_stop_reason status_body_638(js_machine_v05c *m) {
    /* A0:A033:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1056819u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA035u,0u,0u,0u));
}
/* A0:A035:E0M0X0 A90000 LDA */
static js_stop_reason status_body_639(js_machine_v05c *m) {
    /* A0:A035:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1056821u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA038u,0u,0u,0u));
}
/* A0:A038:E0M0X0 38 SEC */
static js_stop_reason status_body_640(js_machine_v05c *m) {
    /* A0:A038:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 1056824u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA039u,0u,0u,0u));
}
/* A0:A039:E0M0X0 60 RTS */
static js_stop_reason status_body_641(js_machine_v05c *m) {
    /* A0:A039:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056825u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8415u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A03A:E0M0X0 890400 BIT */
static js_stop_reason status_body_642(js_machine_v05c *m) {
    /* A0:A03A:E0M0X0 890400 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1056826u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0004u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA03Du,0u,0u,0u));
}
/* A0:A03D:E0M0X0 F020 BEQ */
static js_stop_reason status_body_643(js_machine_v05c *m) {
    /* A0:A03D:E0M0X0 F020 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x20u };
    r = js_v05c_guard_code(m, 1056829u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA05Fu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA03Fu,0u,0u,0u));
}
/* A0:A03F:E0M0X0 A587 LDA */
static js_stop_reason status_body_644(js_machine_v05c *m) {
    /* A0:A03F:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1056831u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA041u,0u,0u,0u));
}
/* A0:A041:E0M0X0 29FFFE AND */
static js_stop_reason status_body_645(js_machine_v05c *m) {
    /* A0:A041:E0M0X0 29FFFE AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFEu };
    r = js_v05c_guard_code(m, 1056833u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFEFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA044u,0u,0u,0u));
}
/* A0:A044:E0M0X0 8587 STA */
static js_stop_reason status_body_646(js_machine_v05c *m) {
    /* A0:A044:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1056836u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA046u,0u,0u,0u));
}
/* A0:A046:E0M0X0 204598 JSR */
static js_stop_reason status_body_647(js_machine_v05c *m) {
    /* A0:A046:E0M0X0 204598 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x45u, 0x98u };
    r = js_v05c_guard_code(m, 1056838u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA048u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9845u,0u,0u,0u));
}
/* A0:A049:E0M0X0 209E88 JSR */
static js_stop_reason status_body_648(js_machine_v05c *m) {
    /* A0:A049:E0M0X0 209E88 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x9Eu, 0x88u };
    r = js_v05c_guard_code(m, 1056841u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA04Bu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x889Eu,0u,0u,0u));
}
/* A0:A04C:E0M0X0 AD220D LDA */
static js_stop_reason status_body_649(js_machine_v05c *m) {
    /* A0:A04C:E0M0X0 AD220D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056844u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA04Fu,0u,0u,0u));
}
/* A0:A04F:E0M0X0 F006 BEQ */
static js_stop_reason status_body_650(js_machine_v05c *m) {
    /* A0:A04F:E0M0X0 F006 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x06u };
    r = js_v05c_guard_code(m, 1056847u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA057u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA051u,0u,0u,0u));
}
/* A0:A051:E0M0X0 CE220D DEC */
static js_stop_reason status_body_651(js_machine_v05c *m) {
    /* A0:A051:E0M0X0 CE220D DEC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xCEu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056849u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, -1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA054u,0u,0u,0u));
}
/* A0:A054:E0M0X0 4CBEA0 JMP */
static js_stop_reason status_body_652(js_machine_v05c *m) {
    /* A0:A054:E0M0X0 4CBEA0 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xBEu, 0xA0u };
    r = js_v05c_guard_code(m, 1056852u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BEu,0u,0u,0u));
}
/* A0:A057:E0M0X0 A597 LDA */
static js_stop_reason status_body_653(js_machine_v05c *m) {
    /* A0:A057:E0M0X0 A597 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x97u };
    r = js_v05c_guard_code(m, 1056855u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x97u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA059u,0u,0u,0u));
}
/* A0:A059:E0M0X0 8D220D STA */
static js_stop_reason status_body_654(js_machine_v05c *m) {
    /* A0:A059:E0M0X0 8D220D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056857u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA05Cu,0u,0u,0u));
}
/* A0:A05C:E0M0X0 4CBEA0 JMP */
static js_stop_reason status_body_655(js_machine_v05c *m) {
    /* A0:A05C:E0M0X0 4CBEA0 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xBEu, 0xA0u };
    r = js_v05c_guard_code(m, 1056860u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BEu,0u,0u,0u));
}
/* A0:A05F:E0M0X0 890800 BIT */
static js_stop_reason status_body_656(js_machine_v05c *m) {
    /* A0:A05F:E0M0X0 890800 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 1056863u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0008u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA062u,0u,0u,0u));
}
/* A0:A062:E0M0X0 F020 BEQ */
static js_stop_reason status_body_657(js_machine_v05c *m) {
    /* A0:A062:E0M0X0 F020 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x20u };
    r = js_v05c_guard_code(m, 1056866u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA084u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA064u,0u,0u,0u));
}
/* A0:A064:E0M0X0 A587 LDA */
static js_stop_reason status_body_658(js_machine_v05c *m) {
    /* A0:A064:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1056868u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA066u,0u,0u,0u));
}
/* A0:A066:E0M0X0 29FFFE AND */
static js_stop_reason status_body_659(js_machine_v05c *m) {
    /* A0:A066:E0M0X0 29FFFE AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xFEu };
    r = js_v05c_guard_code(m, 1056870u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xFEFFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA069u,0u,0u,0u));
}
/* A0:A069:E0M0X0 8587 STA */
static js_stop_reason status_body_660(js_machine_v05c *m) {
    /* A0:A069:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1056873u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA06Bu,0u,0u,0u));
}
/* A0:A06B:E0M0X0 204598 JSR */
static js_stop_reason status_body_661(js_machine_v05c *m) {
    /* A0:A06B:E0M0X0 204598 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x45u, 0x98u };
    r = js_v05c_guard_code(m, 1056875u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA06Du);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x9845u,0u,0u,0u));
}
/* A0:A06E:E0M0X0 207E88 JSR */
static js_stop_reason status_body_662(js_machine_v05c *m) {
    /* A0:A06E:E0M0X0 207E88 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x7Eu, 0x88u };
    r = js_v05c_guard_code(m, 1056878u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA070u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x887Eu,0u,0u,0u));
}
/* A0:A071:E0M0X0 AD220D LDA */
static js_stop_reason status_body_663(js_machine_v05c *m) {
    /* A0:A071:E0M0X0 AD220D LDA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xADu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056881u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA074u,0u,0u,0u));
}
/* A0:A074:E0M0X0 C597 CMP */
static js_stop_reason status_body_664(js_machine_v05c *m) {
    /* A0:A074:E0M0X0 C597 CMP direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC5u, 0x97u };
    r = js_v05c_guard_code(m, 1056884u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x97u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA076u,0u,0u,0u));
}
/* A0:A076:E0M0X0 B006 BCS */
static js_stop_reason status_body_665(js_machine_v05c *m) {
    /* A0:A076:E0M0X0 B006 BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x06u };
    r = js_v05c_guard_code(m, 1056886u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA07Eu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA078u,0u,0u,0u));
}
/* A0:A078:E0M0X0 EE220D INC */
static js_stop_reason status_body_666(js_machine_v05c *m) {
    /* A0:A078:E0M0X0 EE220D INC abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xEEu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056888u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    value = js_v05c_increment(&m->cpu, value, 16u, 1);
    r = js_v05c_write_rmw_value(m, ea, 16u, 0, value);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA07Bu,0u,0u,0u));
}
/* A0:A07B:E0M0X0 4CBEA0 JMP */
static js_stop_reason status_body_667(js_machine_v05c *m) {
    /* A0:A07B:E0M0X0 4CBEA0 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xBEu, 0xA0u };
    r = js_v05c_guard_code(m, 1056891u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BEu,0u,0u,0u));
}
/* A0:A07E:E0M0X0 9C220D STZ */
static js_stop_reason status_body_668(js_machine_v05c *m) {
    /* A0:A07E:E0M0X0 9C220D STZ abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Cu, 0x22u, 0x0Du };
    r = js_v05c_guard_code(m, 1056894u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D22u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA081u,0u,0u,0u));
}
/* A0:A081:E0M0X0 4CBEA0 JMP */
static js_stop_reason status_body_669(js_machine_v05c *m) {
    /* A0:A081:E0M0X0 4CBEA0 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0xBEu, 0xA0u };
    r = js_v05c_guard_code(m, 1056897u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BEu,0u,0u,0u));
}
/* A0:A084:E0M0X0 894000 BIT */
static js_stop_reason status_body_670(js_machine_v05c *m) {
    /* A0:A084:E0M0X0 894000 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x40u, 0x00u };
    r = js_v05c_guard_code(m, 1056900u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0040u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA087u,0u,0u,0u));
}
/* A0:A087:E0M0X0 F017 BEQ */
static js_stop_reason status_body_671(js_machine_v05c *m) {
    /* A0:A087:E0M0X0 F017 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x17u };
    r = js_v05c_guard_code(m, 1056903u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0A0u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA089u,0u,0u,0u));
}
/* A0:A089:E0M0X0 A587 LDA */
static js_stop_reason status_body_672(js_machine_v05c *m) {
    /* A0:A089:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1056905u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA08Bu,0u,0u,0u));
}
/* A0:A08B:E0M0X0 090001 ORA */
static js_stop_reason status_body_673(js_machine_v05c *m) {
    /* A0:A08B:E0M0X0 090001 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1056907u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0100u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA08Eu,0u,0u,0u));
}
/* A0:A08E:E0M0X0 8587 STA */
static js_stop_reason status_body_674(js_machine_v05c *m) {
    /* A0:A08E:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1056910u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA090u,0u,0u,0u));
}
/* A0:A090:E0M0X0 A99182 LDA */
static js_stop_reason status_body_675(js_machine_v05c *m) {
    /* A0:A090:E0M0X0 A99182 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x91u, 0x82u };
    r = js_v05c_guard_code(m, 1056912u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8291u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA093u,0u,0u,0u));
}
/* A0:A093:E0M0X0 8D200D STA */
static js_stop_reason status_body_676(js_machine_v05c *m) {
    /* A0:A093:E0M0X0 8D200D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x20u, 0x0Du };
    r = js_v05c_guard_code(m, 1056915u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D20u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA096u,0u,0u,0u));
}
/* A0:A096:E0M0X0 850B STA */
static js_stop_reason status_body_677(js_machine_v05c *m) {
    /* A0:A096:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1056918u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA098u,0u,0u,0u));
}
/* A0:A098:E0M0X0 205E98 JSR */
static js_stop_reason status_body_678(js_machine_v05c *m) {
    /* A0:A098:E0M0X0 205E98 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x5Eu, 0x98u };
    r = js_v05c_guard_code(m, 1056920u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA09Au);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x985Eu,0u,0u,0u));
}
/* A0:A09B:E0M0X0 201588 JSR */
static js_stop_reason status_body_679(js_machine_v05c *m) {
    /* A0:A09B:E0M0X0 201588 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x15u, 0x88u };
    r = js_v05c_guard_code(m, 1056923u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA09Du);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8815u,0u,0u,0u));
}
/* A0:A09E:E0M0X0 38 SEC */
static js_stop_reason status_body_680(js_machine_v05c *m) {
    /* A0:A09E:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 1056926u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA09Fu,0u,0u,0u));
}
/* A0:A09F:E0M0X0 60 RTS */
static js_stop_reason status_body_681(js_machine_v05c *m) {
    /* A0:A09F:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056927u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8415u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0A0:E0M0X0 890080 BIT */
static js_stop_reason status_body_682(js_machine_v05c *m) {
    /* A0:A0A0:E0M0X0 890080 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x80u };
    r = js_v05c_guard_code(m, 1056928u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x8000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0A3u,0u,0u,0u));
}
/* A0:A0A3:E0M0X0 F017 BEQ */
static js_stop_reason status_body_683(js_machine_v05c *m) {
    /* A0:A0A3:E0M0X0 F017 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x17u };
    r = js_v05c_guard_code(m, 1056931u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BCu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0A5u,0u,0u,0u));
}
/* A0:A0A5:E0M0X0 A587 LDA */
static js_stop_reason status_body_684(js_machine_v05c *m) {
    /* A0:A0A5:E0M0X0 A587 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x87u };
    r = js_v05c_guard_code(m, 1056933u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0A7u,0u,0u,0u));
}
/* A0:A0A7:E0M0X0 090001 ORA */
static js_stop_reason status_body_685(js_machine_v05c *m) {
    /* A0:A0A7:E0M0X0 090001 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1056935u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0x0100u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0AAu,0u,0u,0u));
}
/* A0:A0AA:E0M0X0 8587 STA */
static js_stop_reason status_body_686(js_machine_v05c *m) {
    /* A0:A0AA:E0M0X0 8587 STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x87u };
    r = js_v05c_guard_code(m, 1056938u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x87u);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0ACu,0u,0u,0u));
}
/* A0:A0AC:E0M0X0 A95284 LDA */
static js_stop_reason status_body_687(js_machine_v05c *m) {
    /* A0:A0AC:E0M0X0 A95284 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x52u, 0x84u };
    r = js_v05c_guard_code(m, 1056940u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8452u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0AFu,0u,0u,0u));
}
/* A0:A0AF:E0M0X0 8D200D STA */
static js_stop_reason status_body_688(js_machine_v05c *m) {
    /* A0:A0AF:E0M0X0 8D200D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x20u, 0x0Du };
    r = js_v05c_guard_code(m, 1056943u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D20u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0B2u,0u,0u,0u));
}
/* A0:A0B2:E0M0X0 850B STA */
static js_stop_reason status_body_689(js_machine_v05c *m) {
    /* A0:A0B2:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1056946u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0B4u,0u,0u,0u));
}
/* A0:A0B4:E0M0X0 205E98 JSR */
static js_stop_reason status_body_690(js_machine_v05c *m) {
    /* A0:A0B4:E0M0X0 205E98 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x5Eu, 0x98u };
    r = js_v05c_guard_code(m, 1056948u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0B6u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x985Eu,0u,0u,0u));
}
/* A0:A0B7:E0M0X0 205B88 JSR */
static js_stop_reason status_body_691(js_machine_v05c *m) {
    /* A0:A0B7:E0M0X0 205B88 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x5Bu, 0x88u };
    r = js_v05c_guard_code(m, 1056951u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0B9u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x885Bu,0u,0u,0u));
}
/* A0:A0BA:E0M0X0 38 SEC */
static js_stop_reason status_body_692(js_machine_v05c *m) {
    /* A0:A0BA:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 1056954u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BBu,0u,0u,0u));
}
/* A0:A0BB:E0M0X0 60 RTS */
static js_stop_reason status_body_693(js_machine_v05c *m) {
    /* A0:A0BB:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056955u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8415u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0BC:E0M0X0 18 CLC */
static js_stop_reason status_body_694(js_machine_v05c *m) {
    /* A0:A0BC:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1056956u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BDu,0u,0u,0u));
}
/* A0:A0BD:E0M0X0 60 RTS */
static js_stop_reason status_body_695(js_machine_v05c *m) {
    /* A0:A0BD:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056957u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8415u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0BE:E0M0X0 38 SEC */
static js_stop_reason status_body_696(js_machine_v05c *m) {
    /* A0:A0BE:E0M0X0 38 SEC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x38u };
    r = js_v05c_guard_code(m, 1056958u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p |= JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0BFu,0u,0u,0u));
}
/* A0:A0BF:E0M0X0 60 RTS */
static js_stop_reason status_body_697(js_machine_v05c *m) {
    /* A0:A0BF:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056959u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x8415u,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0C0:E0M0X0 C230 REP */
static js_stop_reason status_body_698(js_machine_v05c *m) {
    /* A0:A0C0:E0M0X0 C230 REP imm8 */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC2u, 0x30u };
    r = js_v05c_guard_code(m, 1056960u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint8_t old_p = m->cpu.p;
    m->cpu.p &= (uint8_t)~ 0x30u;
    js_v05c_normalize(&m->cpu, old_p);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0C2u,0u,0u,0u));
}
/* A0:A0C2:E0M0X0 A5D5 LDA */
static js_stop_reason status_body_699(js_machine_v05c *m) {
    /* A0:A0C2:E0M0X0 A5D5 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0xD5u };
    r = js_v05c_guard_code(m, 1056962u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0xD5u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0C4u,0u,0u,0u));
}
/* A0:A0C4:E0M0X0 892000 BIT */
static js_stop_reason status_body_700(js_machine_v05c *m) {
    /* A0:A0C4:E0M0X0 892000 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x20u, 0x00u };
    r = js_v05c_guard_code(m, 1056964u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0020u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0C7u,0u,0u,0u));
}
/* A0:A0C7:E0M0X0 F009 BEQ */
static js_stop_reason status_body_701(js_machine_v05c *m) {
    /* A0:A0C7:E0M0X0 F009 BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x09u };
    r = js_v05c_guard_code(m, 1056967u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0D2u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0C9u,0u,0u,0u));
}
/* A0:A0C9:E0M0X0 A97682 LDA */
static js_stop_reason status_body_702(js_machine_v05c *m) {
    /* A0:A0C9:E0M0X0 A97682 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x76u, 0x82u };
    r = js_v05c_guard_code(m, 1056969u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8276u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0CCu,0u,0u,0u));
}
/* A0:A0CC:E0M0X0 850B STA */
static js_stop_reason status_body_703(js_machine_v05c *m) {
    /* A0:A0CC:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1056972u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0CEu,0u,0u,0u));
}
/* A0:A0CE:E0M0X0 A90000 LDA */
static js_stop_reason status_body_704(js_machine_v05c *m) {
    /* A0:A0CE:E0M0X0 A90000 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1056974u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0D1u,0u,0u,0u));
}
/* A0:A0D1:E0M0X0 60 RTS */
static js_stop_reason status_body_705(js_machine_v05c *m) {
    /* A0:A0D1:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056977u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x84DBu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0D2:E0M0X0 894000 BIT */
static js_stop_reason status_body_706(js_machine_v05c *m) {
    /* A0:A0D2:E0M0X0 894000 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x40u, 0x00u };
    r = js_v05c_guard_code(m, 1056978u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0040u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0D5u,0u,0u,0u));
}
/* A0:A0D5:E0M0X0 F00F BEQ */
static js_stop_reason status_body_707(js_machine_v05c *m) {
    /* A0:A0D5:E0M0X0 F00F BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x0Fu };
    r = js_v05c_guard_code(m, 1056981u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0E6u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0D7u,0u,0u,0u));
}
/* A0:A0D7:E0M0X0 A99182 LDA */
static js_stop_reason status_body_708(js_machine_v05c *m) {
    /* A0:A0D7:E0M0X0 A99182 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x91u, 0x82u };
    r = js_v05c_guard_code(m, 1056983u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8291u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0DAu,0u,0u,0u));
}
/* A0:A0DA:E0M0X0 8D200D STA */
static js_stop_reason status_body_709(js_machine_v05c *m) {
    /* A0:A0DA:E0M0X0 8D200D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x20u, 0x0Du };
    r = js_v05c_guard_code(m, 1056986u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D20u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0DDu,0u,0u,0u));
}
/* A0:A0DD:E0M0X0 850B STA */
static js_stop_reason status_body_710(js_machine_v05c *m) {
    /* A0:A0DD:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1056989u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0DFu,0u,0u,0u));
}
/* A0:A0DF:E0M0X0 205E98 JSR */
static js_stop_reason status_body_711(js_machine_v05c *m) {
    /* A0:A0DF:E0M0X0 205E98 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x5Eu, 0x98u };
    r = js_v05c_guard_code(m, 1056991u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0E1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x985Eu,0u,0u,0u));
}
/* A0:A0E2:E0M0X0 201588 JSR */
static js_stop_reason status_body_712(js_machine_v05c *m) {
    /* A0:A0E2:E0M0X0 201588 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x15u, 0x88u };
    r = js_v05c_guard_code(m, 1056994u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0E4u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8815u,0u,0u,0u));
}
/* A0:A0E5:E0M0X0 60 RTS */
static js_stop_reason status_body_713(js_machine_v05c *m) {
    /* A0:A0E5:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1056997u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x84DBu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0E6:E0M0X0 890040 BIT */
static js_stop_reason status_body_714(js_machine_v05c *m) {
    /* A0:A0E6:E0M0X0 890040 BIT imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x89u, 0x00u, 0x40u };
    r = js_v05c_guard_code(m, 1056998u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_bit(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x4000u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0E9u,0u,0u,0u));
}
/* A0:A0E9:E0M0X0 F00F BEQ */
static js_stop_reason status_body_715(js_machine_v05c *m) {
    /* A0:A0E9:E0M0X0 F00F BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x0Fu };
    r = js_v05c_guard_code(m, 1057001u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0FAu,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0EBu,0u,0u,0u));
}
/* A0:A0EB:E0M0X0 A98783 LDA */
static js_stop_reason status_body_716(js_machine_v05c *m) {
    /* A0:A0EB:E0M0X0 A98783 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x87u, 0x83u };
    r = js_v05c_guard_code(m, 1057003u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x8387u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0EEu,0u,0u,0u));
}
/* A0:A0EE:E0M0X0 8D200D STA */
static js_stop_reason status_body_717(js_machine_v05c *m) {
    /* A0:A0EE:E0M0X0 8D200D STA abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Du, 0x20u, 0x0Du };
    r = js_v05c_guard_code(m, 1057006u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs(m, 0x0D20u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0F1u,0u,0u,0u));
}
/* A0:A0F1:E0M0X0 850B STA */
static js_stop_reason status_body_718(js_machine_v05c *m) {
    /* A0:A0F1:E0M0X0 850B STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x0Bu };
    r = js_v05c_guard_code(m, 1057009u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x0Bu);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xA0F3u,0u,0u,0u));
}
/* A0:A0F3:E0M0X0 205E98 JSR */
static js_stop_reason status_body_719(js_machine_v05c *m) {
    /* A0:A0F3:E0M0X0 205E98 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x5Eu, 0x98u };
    r = js_v05c_guard_code(m, 1057011u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0F5u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x985Eu,0u,0u,0u));
}
/* A0:A0F6:E0M0X0 203888 JSR */
static js_stop_reason status_body_720(js_machine_v05c *m) {
    /* A0:A0F6:E0M0X0 203888 JSR abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x20u, 0x38u, 0x88u };
    r = js_v05c_guard_code(m, 1057014u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0xA0F8u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0x8838u,0u,0u,0u));
}
/* A0:A0F9:E0M0X0 60 RTS */
static js_stop_reason status_body_721(js_machine_v05c *m) {
    /* A0:A0F9:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1057017u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x84DBu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:A0FA:E0M0X0 60 RTS */
static js_stop_reason status_body_722(js_machine_v05c *m) {
    /* A0:A0FA:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1057018u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x84DBu,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:BF01:E0M0X0 E00001 CPX */
static js_stop_reason status_body_723(js_machine_v05c *m) {
    /* A0:BF01:E0M0X0 E00001 CPX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE0u, 0x00u, 0x01u };
    r = js_v05c_guard_code(m, 1064705u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 0x0100u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF04u,0u,0u,0u));
}
/* A0:BF04:E0M0X0 D001 BNE */
static js_stop_reason status_body_724(js_machine_v05c *m) {
    /* A0:BF04:E0M0X0 D001 BNE rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xD0u, 0x01u };
    r = js_v05c_guard_code(m, 1064708u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) == 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF07u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF06u,0u,0u,0u));
}
/* A0:BF06:E0M0X0 60 RTS */
static js_stop_reason status_body_725(js_machine_v05c *m) {
    /* A0:BF06:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1064710u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x90DAu,0u,0u,0u), JS_CTX(0xA0u,0x911Au,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
/* A0:BF07:E0M0X0 A553 LDA */
static js_stop_reason status_body_726(js_machine_v05c *m) {
    /* A0:BF07:E0M0X0 A553 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x53u };
    r = js_v05c_guard_code(m, 1064711u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x53u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF09u,0u,0u,0u));
}
/* A0:BF09:E0M0X0 0900A0 ORA */
static js_stop_reason status_body_727(js_machine_v05c *m) {
    /* A0:BF09:E0M0X0 0900A0 ORA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x09u, 0x00u, 0xA0u };
    r = js_v05c_guard_code(m, 1064713u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) | 0xA000u) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF0Cu,0u,0u,0u));
}
/* A0:BF0C:E0M0X0 48 PHA */
static js_stop_reason status_body_728(js_machine_v05c *m) {
    /* A0:BF0C:E0M0X0 48 PHA stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x48u };
    r = js_v05c_guard_code(m, 1064716u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, (uint16_t)((uint16_t)(m->cpu.a & 0xFFFFu)));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF0Du,0u,0u,0u));
}
/* A0:BF0D:E0M0X0 AB PLB */
static js_stop_reason status_body_729(js_machine_v05c *m) {
    /* A0:BF0D:E0M0X0 AB PLB stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xABu };
    r = js_v05c_guard_code(m, 1064717u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint8_t pulled = 0u;
    r = js_v05c_pull8(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    m->cpu.dbr = pulled;
    js_v05c_set_nz(&m->cpu, pulled, 8u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF0Eu,0u,0u,0u));
}
/* A0:BF0E:E0M0X0 A51B LDA */
static js_stop_reason status_body_730(js_machine_v05c *m) {
    /* A0:BF0E:E0M0X0 A51B LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x1Bu };
    r = js_v05c_guard_code(m, 1064718u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Bu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF10u,0u,0u,0u));
}
/* A0:BF10:E0M0X0 A8 TAY */
static js_stop_reason status_body_731(js_machine_v05c *m) {
    /* A0:BF10:E0M0X0 A8 TAY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA8u };
    r = js_v05c_guard_code(m, 1064720u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF11u,0u,0u,0u));
}
/* A0:BF11:E0M0X0 B90000 LDA */
static js_stop_reason status_body_732(js_machine_v05c *m) {
    /* A0:BF11:E0M0X0 B90000 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1064721u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0000u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF14u,0u,0u,0u));
}
/* A0:BF14:E0M0X0 F03F BEQ */
static js_stop_reason status_body_733(js_machine_v05c *m) {
    /* A0:BF14:E0M0X0 F03F BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x3Fu };
    r = js_v05c_guard_code(m, 1064724u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF55u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF16u,0u,0u,0u));
}
/* A0:BF16:E0M0X0 29FFF1 AND */
static js_stop_reason status_body_734(js_machine_v05c *m) {
    /* A0:BF16:E0M0X0 29FFF1 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xF1u };
    r = js_v05c_guard_code(m, 1064726u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xF1FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF19u,0u,0u,0u));
}
/* A0:BF19:E0M0X0 851D STA */
static js_stop_reason status_body_735(js_machine_v05c *m) {
    /* A0:BF19:E0M0X0 851D STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Du };
    r = js_v05c_guard_code(m, 1064729u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF1Bu,0u,0u,0u));
}
/* A0:BF1B:E0M0X0 A515 LDA */
static js_stop_reason status_body_736(js_machine_v05c *m) {
    /* A0:BF1B:E0M0X0 A515 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x15u };
    r = js_v05c_guard_code(m, 1064731u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF1Du,0u,0u,0u));
}
/* A0:BF1D:E0M0X0 18 CLC */
static js_stop_reason status_body_737(js_machine_v05c *m) {
    /* A0:BF1D:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064733u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF1Eu,0u,0u,0u));
}
/* A0:BF1E:E0M0X0 790400 ADC */
static js_stop_reason status_body_738(js_machine_v05c *m) {
    /* A0:BF1E:E0M0X0 790400 ADC abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x79u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1064734u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0004u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF21u,0u,0u,0u));
}
/* A0:BF21:E0M0X0 9D0003 STA */
static js_stop_reason status_body_739(js_machine_v05c *m) {
    /* A0:BF21:E0M0X0 9D0003 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x00u, 0x03u };
    r = js_v05c_guard_code(m, 1064737u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0300u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF24u,0u,0u,0u));
}
/* A0:BF24:E0M0X0 9D0005 STA */
static js_stop_reason status_body_740(js_machine_v05c *m) {
    /* A0:BF24:E0M0X0 9D0005 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x00u, 0x05u };
    r = js_v05c_guard_code(m, 1064740u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0500u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF27u,0u,0u,0u));
}
/* A0:BF27:E0M0X0 A517 LDA */
static js_stop_reason status_body_741(js_machine_v05c *m) {
    /* A0:BF27:E0M0X0 A517 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x17u };
    r = js_v05c_guard_code(m, 1064743u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x17u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF29u,0u,0u,0u));
}
/* A0:BF29:E0M0X0 18 CLC */
static js_stop_reason status_body_742(js_machine_v05c *m) {
    /* A0:BF29:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064745u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF2Au,0u,0u,0u));
}
/* A0:BF2A:E0M0X0 790200 ADC */
static js_stop_reason status_body_743(js_machine_v05c *m) {
    /* A0:BF2A:E0M0X0 790200 ADC abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x79u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1064746u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0002u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF2Du,0u,0u,0u));
}
/* A0:BF2D:E0M0X0 9D0105 STA */
static js_stop_reason status_body_744(js_machine_v05c *m) {
    /* A0:BF2D:E0M0X0 9D0105 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x01u, 0x05u };
    r = js_v05c_guard_code(m, 1064749u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0501u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF30u,0u,0u,0u));
}
/* A0:BF30:E0M0X0 18 CLC */
static js_stop_reason status_body_745(js_machine_v05c *m) {
    /* A0:BF30:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064752u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF31u,0u,0u,0u));
}
/* A0:BF31:E0M0X0 691000 ADC */
static js_stop_reason status_body_746(js_machine_v05c *m) {
    /* A0:BF31:E0M0X0 691000 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 1064753u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0010u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF34u,0u,0u,0u));
}
/* A0:BF34:E0M0X0 3017 BMI */
static js_stop_reason status_body_747(js_machine_v05c *m) {
    /* A0:BF34:E0M0X0 3017 BMI rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x30u, 0x17u };
    r = js_v05c_guard_code(m, 1064756u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_N) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Du,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF36u,0u,0u,0u));
}
/* A0:BF36:E0M0X0 C9F000 CMP */
static js_stop_reason status_body_748(js_machine_v05c *m) {
    /* A0:BF36:E0M0X0 C9F000 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xF0u, 0x00u };
    r = js_v05c_guard_code(m, 1064758u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x00F0u, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF39u,0u,0u,0u));
}
/* A0:BF39:E0M0X0 B012 BCS */
static js_stop_reason status_body_749(js_machine_v05c *m) {
    /* A0:BF39:E0M0X0 B012 BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x12u };
    r = js_v05c_guard_code(m, 1064761u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Du,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF3Bu,0u,0u,0u));
}
/* A0:BF3B:E0M0X0 A51F LDA */
static js_stop_reason status_body_750(js_machine_v05c *m) {
    /* A0:BF3B:E0M0X0 A51F LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x1Fu };
    r = js_v05c_guard_code(m, 1064763u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Fu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF3Du,0u,0u,0u));
}
/* A0:BF3D:E0M0X0 18 CLC */
static js_stop_reason status_body_751(js_machine_v05c *m) {
    /* A0:BF3D:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064765u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF3Eu,0u,0u,0u));
}
/* A0:BF3E:E0M0X0 651D ADC */
static js_stop_reason status_body_752(js_machine_v05c *m) {
    /* A0:BF3E:E0M0X0 651D ADC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x65u, 0x1Du };
    r = js_v05c_guard_code(m, 1064766u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF40u,0u,0u,0u));
}
/* A0:BF40:E0M0X0 9D0205 STA */
static js_stop_reason status_body_753(js_machine_v05c *m) {
    /* A0:BF40:E0M0X0 9D0205 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x02u, 0x05u };
    r = js_v05c_guard_code(m, 1064768u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0502u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF43u,0u,0u,0u));
}
/* A0:BF43:E0M0X0 A9FFFF LDA */
static js_stop_reason status_body_754(js_machine_v05c *m) {
    /* A0:BF43:E0M0X0 A9FFFF LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0xFFu, 0xFFu };
    r = js_v05c_guard_code(m, 1064771u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0xFFFFu, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF46u,0u,0u,0u));
}
/* A0:BF46:E0M0X0 9D0203 STA */
static js_stop_reason status_body_755(js_machine_v05c *m) {
    /* A0:BF46:E0M0X0 9D0203 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x02u, 0x03u };
    r = js_v05c_guard_code(m, 1064774u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0302u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF49u,0u,0u,0u));
}
/* A0:BF49:E0M0X0 E8 INX */
static js_stop_reason status_body_756(js_machine_v05c *m) {
    /* A0:BF49:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064777u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Au,0u,0u,0u));
}
/* A0:BF4A:E0M0X0 E8 INX */
static js_stop_reason status_body_757(js_machine_v05c *m) {
    /* A0:BF4A:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064778u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Bu,0u,0u,0u));
}
/* A0:BF4B:E0M0X0 E8 INX */
static js_stop_reason status_body_758(js_machine_v05c *m) {
    /* A0:BF4B:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064779u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Cu,0u,0u,0u));
}
/* A0:BF4C:E0M0X0 E8 INX */
static js_stop_reason status_body_759(js_machine_v05c *m) {
    /* A0:BF4C:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064780u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Du,0u,0u,0u));
}
/* A0:BF4D:E0M0X0 98 TYA */
static js_stop_reason status_body_760(js_machine_v05c *m) {
    /* A0:BF4D:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 1064781u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Eu,0u,0u,0u));
}
/* A0:BF4E:E0M0X0 18 CLC */
static js_stop_reason status_body_761(js_machine_v05c *m) {
    /* A0:BF4E:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064782u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF4Fu,0u,0u,0u));
}
/* A0:BF4F:E0M0X0 690600 ADC */
static js_stop_reason status_body_762(js_machine_v05c *m) {
    /* A0:BF4F:E0M0X0 690600 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1064783u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0006u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF52u,0u,0u,0u));
}
/* A0:BF52:E0M0X0 A8 TAY */
static js_stop_reason status_body_763(js_machine_v05c *m) {
    /* A0:BF52:E0M0X0 A8 TAY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA8u };
    r = js_v05c_guard_code(m, 1064786u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF53u,0u,0u,0u));
}
/* A0:BF53:E0M0X0 80BC BRA */
static js_stop_reason status_body_764(js_machine_v05c *m) {
    /* A0:BF53:E0M0X0 80BC BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0xBCu };
    r = js_v05c_guard_code(m, 1064787u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF11u,0u,0u,0u));
}
/* A0:BF55:E0M0X0 C8 INY */
static js_stop_reason status_body_765(js_machine_v05c *m) {
    /* A0:BF55:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1064789u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF56u,0u,0u,0u));
}
/* A0:BF56:E0M0X0 C8 INY */
static js_stop_reason status_body_766(js_machine_v05c *m) {
    /* A0:BF56:E0M0X0 C8 INY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC8u };
    r = js_v05c_guard_code(m, 1064790u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.y = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.y & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF57u,0u,0u,0u));
}
/* A0:BF57:E0M0X0 B90000 LDA */
static js_stop_reason status_body_767(js_machine_v05c *m) {
    /* A0:BF57:E0M0X0 B90000 LDA abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB9u, 0x00u, 0x00u };
    r = js_v05c_guard_code(m, 1064791u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0000u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF5Au,0u,0u,0u));
}
/* A0:BF5A:E0M0X0 F03C BEQ */
static js_stop_reason status_body_768(js_machine_v05c *m) {
    /* A0:BF5A:E0M0X0 F03C BEQ rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xF0u, 0x3Cu };
    r = js_v05c_guard_code(m, 1064794u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_Z) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF98u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF5Cu,0u,0u,0u));
}
/* A0:BF5C:E0M0X0 29FFF1 AND */
static js_stop_reason status_body_769(js_machine_v05c *m) {
    /* A0:BF5C:E0M0X0 29FFF1 AND imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x29u, 0xFFu, 0xF1u };
    r = js_v05c_guard_code(m, 1064796u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = (uint16_t)(((uint16_t)(m->cpu.a & 0xFFFFu) & 0xF1FFu) & 0xFFFFu);
    js_v05c_write_a(&m->cpu, result, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF5Fu,0u,0u,0u));
}
/* A0:BF5F:E0M0X0 851D STA */
static js_stop_reason status_body_770(js_machine_v05c *m) {
    /* A0:BF5F:E0M0X0 851D STA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x85u, 0x1Du };
    r = js_v05c_guard_code(m, 1064799u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    r = js_v05c_write_value(m, ea, 16u, 1, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF61u,0u,0u,0u));
}
/* A0:BF61:E0M0X0 A515 LDA */
static js_stop_reason status_body_771(js_machine_v05c *m) {
    /* A0:BF61:E0M0X0 A515 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x15u };
    r = js_v05c_guard_code(m, 1064801u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x15u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF63u,0u,0u,0u));
}
/* A0:BF63:E0M0X0 18 CLC */
static js_stop_reason status_body_772(js_machine_v05c *m) {
    /* A0:BF63:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064803u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF64u,0u,0u,0u));
}
/* A0:BF64:E0M0X0 790400 ADC */
static js_stop_reason status_body_773(js_machine_v05c *m) {
    /* A0:BF64:E0M0X0 790400 ADC abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x79u, 0x04u, 0x00u };
    r = js_v05c_guard_code(m, 1064804u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0004u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF67u,0u,0u,0u));
}
/* A0:BF67:E0M0X0 9D0003 STA */
static js_stop_reason status_body_774(js_machine_v05c *m) {
    /* A0:BF67:E0M0X0 9D0003 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x00u, 0x03u };
    r = js_v05c_guard_code(m, 1064807u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0300u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF6Au,0u,0u,0u));
}
/* A0:BF6A:E0M0X0 9D0005 STA */
static js_stop_reason status_body_775(js_machine_v05c *m) {
    /* A0:BF6A:E0M0X0 9D0005 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x00u, 0x05u };
    r = js_v05c_guard_code(m, 1064810u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0500u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF6Du,0u,0u,0u));
}
/* A0:BF6D:E0M0X0 A517 LDA */
static js_stop_reason status_body_776(js_machine_v05c *m) {
    /* A0:BF6D:E0M0X0 A517 LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x17u };
    r = js_v05c_guard_code(m, 1064813u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x17u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF6Fu,0u,0u,0u));
}
/* A0:BF6F:E0M0X0 18 CLC */
static js_stop_reason status_body_777(js_machine_v05c *m) {
    /* A0:BF6F:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064815u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF70u,0u,0u,0u));
}
/* A0:BF70:E0M0X0 790200 ADC */
static js_stop_reason status_body_778(js_machine_v05c *m) {
    /* A0:BF70:E0M0X0 790200 ADC abs_y */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x79u, 0x02u, 0x00u };
    r = js_v05c_guard_code(m, 1064816u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_y(m, 0x0002u);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF73u,0u,0u,0u));
}
/* A0:BF73:E0M0X0 9D0105 STA */
static js_stop_reason status_body_779(js_machine_v05c *m) {
    /* A0:BF73:E0M0X0 9D0105 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x01u, 0x05u };
    r = js_v05c_guard_code(m, 1064819u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0501u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF76u,0u,0u,0u));
}
/* A0:BF76:E0M0X0 18 CLC */
static js_stop_reason status_body_780(js_machine_v05c *m) {
    /* A0:BF76:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064822u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF77u,0u,0u,0u));
}
/* A0:BF77:E0M0X0 691000 ADC */
static js_stop_reason status_body_781(js_machine_v05c *m) {
    /* A0:BF77:E0M0X0 691000 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x10u, 0x00u };
    r = js_v05c_guard_code(m, 1064823u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0010u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF7Au,0u,0u,0u));
}
/* A0:BF7A:E0M0X0 3014 BMI */
static js_stop_reason status_body_782(js_machine_v05c *m) {
    /* A0:BF7A:E0M0X0 3014 BMI rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x30u, 0x14u };
    r = js_v05c_guard_code(m, 1064826u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_N) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF90u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF7Cu,0u,0u,0u));
}
/* A0:BF7C:E0M0X0 C9EF00 CMP */
static js_stop_reason status_body_783(js_machine_v05c *m) {
    /* A0:BF7C:E0M0X0 C9EF00 CMP imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xC9u, 0xEFu, 0x00u };
    r = js_v05c_guard_code(m, 1064828u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    (void)js_v05c_compare(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x00EFu, 16u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF7Fu,0u,0u,0u));
}
/* A0:BF7F:E0M0X0 B00F BCS */
static js_stop_reason status_body_784(js_machine_v05c *m) {
    /* A0:BF7F:E0M0X0 B00F BCS rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xB0u, 0x0Fu };
    r = js_v05c_guard_code(m, 1064831u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if (((m->cpu.p & JS_FLAG_C) != 0u)) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
        return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF90u,0u,0u,0u));
    }
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF81u,0u,0u,0u));
}
/* A0:BF81:E0M0X0 A51F LDA */
static js_stop_reason status_body_785(js_machine_v05c *m) {
    /* A0:BF81:E0M0X0 A51F LDA direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA5u, 0x1Fu };
    r = js_v05c_guard_code(m, 1064833u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Fu);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF83u,0u,0u,0u));
}
/* A0:BF83:E0M0X0 18 CLC */
static js_stop_reason status_body_786(js_machine_v05c *m) {
    /* A0:BF83:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064835u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF84u,0u,0u,0u));
}
/* A0:BF84:E0M0X0 651D ADC */
static js_stop_reason status_body_787(js_machine_v05c *m) {
    /* A0:BF84:E0M0X0 651D ADC direct */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x65u, 0x1Du };
    r = js_v05c_guard_code(m, 1064836u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    if ((m->cpu.d & 0x00FFu) != 0u) {
        r = js_v05c_idle_cycles(m, 1u);
        if (r != JS_STOP_NONE) return r;
    }
    uint32_t ea = js_v05c_addr_direct(m, 0x1Du);
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 1, &value);
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), value, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF86u,0u,0u,0u));
}
/* A0:BF86:E0M0X0 9D0205 STA */
static js_stop_reason status_body_788(js_machine_v05c *m) {
    /* A0:BF86:E0M0X0 9D0205 STA abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Du, 0x02u, 0x05u };
    r = js_v05c_guard_code(m, 1064838u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0502u);
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF89u,0u,0u,0u));
}
/* A0:BF89:E0M0X0 9E0203 STZ */
static js_stop_reason status_body_789(js_machine_v05c *m) {
    /* A0:BF89:E0M0X0 9E0203 STZ abs_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x9Eu, 0x02u, 0x03u };
    r = js_v05c_guard_code(m, 1064841u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = js_v05c_addr_abs_x(m, 0x0302u);
    r = js_v05c_write_value(m, ea, 16u, 0, 0u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF8Cu,0u,0u,0u));
}
/* A0:BF8C:E0M0X0 E8 INX */
static js_stop_reason status_body_790(js_machine_v05c *m) {
    /* A0:BF8C:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064844u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF8Du,0u,0u,0u));
}
/* A0:BF8D:E0M0X0 E8 INX */
static js_stop_reason status_body_791(js_machine_v05c *m) {
    /* A0:BF8D:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064845u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF8Eu,0u,0u,0u));
}
/* A0:BF8E:E0M0X0 E8 INX */
static js_stop_reason status_body_792(js_machine_v05c *m) {
    /* A0:BF8E:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064846u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF8Fu,0u,0u,0u));
}
/* A0:BF8F:E0M0X0 E8 INX */
static js_stop_reason status_body_793(js_machine_v05c *m) {
    /* A0:BF8F:E0M0X0 E8 INX implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xE8u };
    r = js_v05c_guard_code(m, 1064847u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.x = js_v05c_increment(&m->cpu, (uint16_t)(m->cpu.x & 0xFFFFu), 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF90u,0u,0u,0u));
}
/* A0:BF90:E0M0X0 98 TYA */
static js_stop_reason status_body_794(js_machine_v05c *m) {
    /* A0:BF90:E0M0X0 98 TYA implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x98u };
    r = js_v05c_guard_code(m, 1064848u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, m->cpu.y, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF91u,0u,0u,0u));
}
/* A0:BF91:E0M0X0 18 CLC */
static js_stop_reason status_body_795(js_machine_v05c *m) {
    /* A0:BF91:E0M0X0 18 CLC implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x18u };
    r = js_v05c_guard_code(m, 1064849u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    m->cpu.p &= (uint8_t)~JS_FLAG_C;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF92u,0u,0u,0u));
}
/* A0:BF92:E0M0X0 690600 ADC */
static js_stop_reason status_body_796(js_machine_v05c *m) {
    /* A0:BF92:E0M0X0 690600 ADC imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x69u, 0x06u, 0x00u };
    r = js_v05c_guard_code(m, 1064850u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint16_t result = js_v05c_adc(&m->cpu, (uint16_t)(m->cpu.a & 0xFFFFu), 0x0006u, 16u);
    js_v05c_write_a(&m->cpu, result, 16u, 0);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF95u,0u,0u,0u));
}
/* A0:BF95:E0M0X0 A8 TAY */
static js_stop_reason status_body_797(js_machine_v05c *m) {
    /* A0:BF95:E0M0X0 A8 TAY implied */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA8u };
    r = js_v05c_guard_code(m, 1064853u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_y(&m->cpu, m->cpu.a, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF96u,0u,0u,0u));
}
/* A0:BF96:E0M0X0 80BF BRA */
static js_stop_reason status_body_798(js_machine_v05c *m) {
    /* A0:BF96:E0M0X0 80BF BRA rel */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x80u, 0xBFu };
    r = js_v05c_guard_code(m, 1064854u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF57u,0u,0u,0u));
}
/* A0:BF98:E0M0X0 AB PLB */
static js_stop_reason status_body_799(js_machine_v05c *m) {
    /* A0:BF98:E0M0X0 AB PLB stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xABu };
    r = js_v05c_guard_code(m, 1064856u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 2u);
    if (r != JS_STOP_NONE) return r;
    uint8_t pulled = 0u;
    r = js_v05c_pull8(m, &pulled);
    if (r != JS_STOP_NONE) return r;
    m->cpu.dbr = pulled;
    js_v05c_set_nz(&m->cpu, pulled, 8u);
    return js_v05c_finish_fixed(m, JS_CTX(0xA0u,0xBF99u,0u,0u,0u));
}
/* A0:BF99:E0M0X0 60 RTS */
static js_stop_reason status_body_800(js_machine_v05c *m) {
    /* A0:BF99:E0M0X0 60 RTS stack */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x60u };
    r = js_v05c_guard_code(m, 1064857u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 3u);
    if (r != JS_STOP_NONE) return r;
    uint16_t ret = 0u;
    r = js_v05c_pull16(m, &ret);
    if (r != JS_STOP_NONE) return r;
    m->cpu.pc = (uint16_t)(ret + 1u);
    const js_static_context_key allowed[] = { JS_CTX(0xA0u,0x90DAu,0u,0u,0u), JS_CTX(0xA0u,0x911Au,0u,0u,0u) };
    r = js_v05c_validate_current_key(m, allowed, sizeof(allowed)/sizeof(allowed[0]), JS_STOP_UNPROVED_RETURN_CONTEXT);
    if (r != JS_STOP_NONE) return r;
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}
int jungle_status_context_known(js_static_context_key key) {
switch(js_v05c_pack_key(key)) {
case JS_V05C_KEY_CONST(0x80u,0xBC61u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC62u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC65u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC66u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC69u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC6Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC6Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC71u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC74u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC77u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC7Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC7Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC80u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD400u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD403u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD406u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD409u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD40Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD47Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD480u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB01u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB02u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB05u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB08u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB12u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB15u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB16u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB1Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB1Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB21u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB22u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB23u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB24u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB25u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB26u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB27u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB29u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB2Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB2Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB31u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB34u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB38u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB39u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB40u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB43u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB44u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB48u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB49u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB52u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB53u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB54u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB55u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB56u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB57u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB58u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB61u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB64u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB65u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB68u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB6Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB6Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB73u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB74u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB75u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB76u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB79u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB7Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB7Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB80u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB83u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB84u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB85u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB88u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB8Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB8Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB90u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB91u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB95u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB96u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB97u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB98u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB99u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB9Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB9Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBBDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8387u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8392u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8394u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8397u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8399u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x839Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x839Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83AAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83ACu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83AFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83BBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83BEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83CBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83CEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E5u,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E7u,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E9u,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83EBu,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83EEu,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83FBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83FDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8400u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8402u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8404u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8407u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8409u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x840Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x840Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8412u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8417u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8419u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x841Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x841Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8421u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8424u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8427u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8429u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x842Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x842Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8432u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8435u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8438u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8442u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8445u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8448u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8452u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8455u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8458u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x845Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x845Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8460u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8463u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8465u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8467u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8472u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8474u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8477u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8481u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8484u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8487u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8490u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8491u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8492u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8493u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8497u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8499u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x849Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x849Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84AAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84ADu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84AFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B9u,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BBu,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BDu,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BFu,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C2u,0u,1u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84DEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8525u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8528u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8533u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8535u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8539u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x853Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x853Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8542u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8545u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8546u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8549u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x854Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x854Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8550u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8552u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8555u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8557u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8561u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8562u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8565u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8568u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8570u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8572u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8576u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8579u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x857Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x857Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8582u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8583u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8586u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8588u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8815u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8818u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x881Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x881Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8821u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8824u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8827u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x882Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x882Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8831u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8834u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8837u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DA5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DA7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DAAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DACu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DAFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DCBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DCDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F4Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F52u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F54u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F57u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F62u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F64u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F67u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F68u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F70u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F71u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F73u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F75u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F78u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F7Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F7Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F81u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F82u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F83u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F85u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F89u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F8Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F90u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F93u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F97u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F9Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F9Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FABu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FADu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FBCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FCAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FCEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FDBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FDDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FECu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FFAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FFEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9001u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9005u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9008u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9012u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9014u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9017u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9019u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x901Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x901Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9021u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9023u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9026u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9028u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x902Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x902Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9030u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9032u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9035u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9037u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9041u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9044u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9045u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9048u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9050u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9052u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9055u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9057u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9058u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9061u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9064u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9066u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9069u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9072u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9074u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9076u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9079u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x907Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x907Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9080u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9083u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9086u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9089u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9092u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9094u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9096u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9099u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90ABu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90AEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90BBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90BEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90EAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90ECu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90EFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9101u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9104u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9106u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9108u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9110u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9113u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9115u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9117u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9120u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9121u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9123u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9125u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9126u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9127u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9129u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x912Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x912Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9130u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9133u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9135u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9137u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9141u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9144u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9146u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9147u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9149u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x914Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x914Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9150u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9152u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9155u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9157u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9160u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9163u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9165u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9168u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9171u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9173u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9175u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9177u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9179u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x917Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x917Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9180u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9183u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9185u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9188u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9190u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9191u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9194u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9196u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9198u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91ACu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91AEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91AFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91BCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91BEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C8u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91D1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA027u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA029u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA02Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA02Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA030u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA033u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA035u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA038u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA039u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA041u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA044u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA046u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA049u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA04Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA04Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA051u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA054u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA057u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA059u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA05Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA05Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA062u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA064u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA066u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA069u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA06Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA06Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA071u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA074u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA076u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA078u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA07Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA07Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA081u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA084u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA087u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA089u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA08Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA08Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA090u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA093u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA096u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA098u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0AAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0ACu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0AFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C0u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C4u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0CCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0CEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D7u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DDu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DFu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E2u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E5u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0EBu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0EEu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F1u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F3u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F6u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F9u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0FAu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF01u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF04u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF06u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF07u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF09u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF10u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF11u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF14u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF16u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF19u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF21u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF24u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF27u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF29u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF2Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF2Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF30u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF31u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF34u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF36u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF39u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF40u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF43u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF46u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF49u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF52u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF53u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF55u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF56u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF57u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF61u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF63u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF64u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF67u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF70u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF73u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF76u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF77u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF81u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF83u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF84u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF86u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF89u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Du,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF90u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF91u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF92u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF95u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF96u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF98u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF99u,0u,0u,0u):return 1;
default:return 0;}}
int jungle_status_dispatch(js_machine_v05c *m,js_static_context_key key,js_stop_reason *out) {
switch(js_v05c_pack_key(key)) {
case JS_V05C_KEY_CONST(0x80u,0xBC61u,0u,0u,0u):*out=status_body_0(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC62u,0u,0u,0u):*out=status_body_1(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC65u,0u,0u,0u):*out=status_body_2(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC66u,0u,0u,0u):*out=status_body_3(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC69u,0u,0u,0u):*out=status_body_4(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC6Cu,0u,0u,0u):*out=status_body_5(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC6Fu,0u,0u,0u):*out=status_body_6(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC71u,0u,0u,0u):*out=status_body_7(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC74u,0u,0u,0u):*out=status_body_8(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC77u,0u,0u,0u):*out=status_body_9(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC7Au,0u,0u,0u):*out=status_body_10(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC7Du,0u,0u,0u):*out=status_body_11(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xBC80u,0u,0u,0u):*out=status_body_12(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u):*out=status_body_13(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD400u,0u,0u,0u):*out=status_body_14(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD403u,0u,0u,0u):*out=status_body_15(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD406u,0u,0u,0u):*out=status_body_16(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD409u,0u,0u,0u):*out=status_body_17(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD40Bu,0u,0u,0u):*out=status_body_18(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u):*out=status_body_19(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD47Eu,0u,0u,0u):*out=status_body_20(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD480u,0u,0u,0u):*out=status_body_21(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u):*out=status_body_22(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB01u,0u,0u,0u):*out=status_body_23(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB02u,0u,0u,0u):*out=status_body_24(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB05u,0u,0u,0u):*out=status_body_25(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB08u,0u,0u,0u):*out=status_body_26(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Bu,0u,0u,0u):*out=status_body_27(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Cu,0u,0u,0u):*out=status_body_28(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Du,0u,0u,0u):*out=status_body_29(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB0Eu,0u,0u,0u):*out=status_body_30(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u):*out=status_body_31(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB12u,0u,0u,0u):*out=status_body_32(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB15u,0u,0u,0u):*out=status_body_33(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB16u,0u,0u,0u):*out=status_body_34(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB1Au,0u,0u,0u):*out=status_body_35(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB1Du,0u,0u,0u):*out=status_body_36(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB21u,0u,0u,0u):*out=status_body_37(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB22u,0u,0u,0u):*out=status_body_38(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB23u,0u,0u,0u):*out=status_body_39(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB24u,0u,0u,0u):*out=status_body_40(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB25u,0u,0u,0u):*out=status_body_41(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB26u,0u,0u,0u):*out=status_body_42(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB27u,0u,0u,0u):*out=status_body_43(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB29u,0u,0u,0u):*out=status_body_44(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB2Cu,0u,0u,0u):*out=status_body_45(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB2Du,0u,0u,0u):*out=status_body_46(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB31u,0u,0u,0u):*out=status_body_47(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB34u,0u,0u,0u):*out=status_body_48(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB38u,0u,0u,0u):*out=status_body_49(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB39u,0u,0u,0u):*out=status_body_50(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Au,0u,0u,0u):*out=status_body_51(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Bu,0u,0u,0u):*out=status_body_52(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Cu,0u,0u,0u):*out=status_body_53(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Du,0u,0u,0u):*out=status_body_54(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB3Eu,0u,0u,0u):*out=status_body_55(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB40u,0u,0u,0u):*out=status_body_56(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB43u,0u,0u,0u):*out=status_body_57(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB44u,0u,0u,0u):*out=status_body_58(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB48u,0u,0u,0u):*out=status_body_59(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB49u,0u,0u,0u):*out=status_body_60(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Cu,0u,0u,0u):*out=status_body_61(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Du,0u,0u,0u):*out=status_body_62(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB4Eu,0u,0u,0u):*out=status_body_63(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB52u,0u,0u,0u):*out=status_body_64(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB53u,0u,0u,0u):*out=status_body_65(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB54u,0u,0u,0u):*out=status_body_66(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB55u,0u,0u,0u):*out=status_body_67(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB56u,0u,0u,0u):*out=status_body_68(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB57u,0u,0u,0u):*out=status_body_69(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB58u,0u,0u,0u):*out=status_body_70(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Bu,0u,0u,0u):*out=status_body_71(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Cu,0u,0u,0u):*out=status_body_72(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Fu,0u,0u,0u):*out=status_body_73(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB61u,0u,0u,0u):*out=status_body_74(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB64u,0u,0u,0u):*out=status_body_75(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB65u,0u,0u,0u):*out=status_body_76(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB68u,0u,0u,0u):*out=status_body_77(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB6Cu,0u,0u,0u):*out=status_body_78(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB6Fu,0u,0u,0u):*out=status_body_79(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB73u,0u,0u,0u):*out=status_body_80(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB74u,0u,0u,0u):*out=status_body_81(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB75u,0u,0u,0u):*out=status_body_82(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB76u,0u,0u,0u):*out=status_body_83(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB79u,0u,0u,0u):*out=status_body_84(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB7Au,0u,0u,0u):*out=status_body_85(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB7Du,0u,0u,0u):*out=status_body_86(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB80u,0u,0u,0u):*out=status_body_87(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB83u,0u,0u,0u):*out=status_body_88(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB84u,0u,0u,0u):*out=status_body_89(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB85u,0u,0u,0u):*out=status_body_90(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB88u,0u,0u,0u):*out=status_body_91(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB8Bu,0u,0u,0u):*out=status_body_92(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB8Cu,0u,0u,0u):*out=status_body_93(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB90u,0u,0u,0u):*out=status_body_94(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB91u,0u,0u,0u):*out=status_body_95(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB95u,0u,0u,0u):*out=status_body_96(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB96u,0u,0u,0u):*out=status_body_97(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB97u,0u,0u,0u):*out=status_body_98(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB98u,0u,0u,0u):*out=status_body_99(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB99u,0u,0u,0u):*out=status_body_100(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB9Cu,0u,0u,0u):*out=status_body_101(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB9Fu,0u,0u,0u):*out=status_body_102(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA0u,0u,0u,0u):*out=status_body_103(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA4u,0u,0u,0u):*out=status_body_104(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBA7u,0u,0u,0u):*out=status_body_105(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAAu,0u,0u,0u):*out=status_body_106(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAEu,0u,0u,0u):*out=status_body_107(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBAFu,0u,0u,0u):*out=status_body_108(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB0u,0u,0u,0u):*out=status_body_109(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB1u,0u,0u,0u):*out=status_body_110(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB2u,0u,0u,0u):*out=status_body_111(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB5u,0u,0u,0u):*out=status_body_112(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB8u,0u,0u,0u):*out=status_body_113(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB9u,0u,0u,0u):*out=status_body_114(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBBDu,0u,0u,0u):*out=status_body_115(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC0u,0u,0u,0u):*out=status_body_116(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC4u,0u,0u,0u):*out=status_body_117(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC5u,0u,0u,0u):*out=status_body_118(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC6u,0u,0u,0u):*out=status_body_119(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC7u,0u,0u,0u):*out=status_body_120(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBC8u,0u,0u,0u):*out=status_body_121(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8387u,0u,0u,0u):*out=status_body_122(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Au,0u,0u,0u):*out=status_body_123(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Du,0u,0u,0u):*out=status_body_124(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x838Fu,0u,0u,0u):*out=status_body_125(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8392u,0u,0u,0u):*out=status_body_126(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8394u,0u,0u,0u):*out=status_body_127(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8397u,0u,0u,0u):*out=status_body_128(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8399u,0u,0u,0u):*out=status_body_129(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x839Cu,0u,0u,0u):*out=status_body_130(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x839Fu,0u,0u,0u):*out=status_body_131(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A2u,0u,0u,0u):*out=status_body_132(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A5u,0u,0u,0u):*out=status_body_133(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83A7u,0u,0u,0u):*out=status_body_134(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83AAu,0u,0u,0u):*out=status_body_135(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83ACu,0u,0u,0u):*out=status_body_136(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83AFu,0u,0u,0u):*out=status_body_137(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B2u,0u,0u,0u):*out=status_body_138(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B5u,0u,0u,0u):*out=status_body_139(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83B8u,0u,0u,0u):*out=status_body_140(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83BBu,0u,0u,0u):*out=status_body_141(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83BEu,0u,0u,0u):*out=status_body_142(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C1u,0u,0u,0u):*out=status_body_143(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C3u,0u,0u,0u):*out=status_body_144(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C6u,0u,0u,0u):*out=status_body_145(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83C8u,0u,0u,0u):*out=status_body_146(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83CBu,0u,0u,0u):*out=status_body_147(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83CEu,0u,0u,0u):*out=status_body_148(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D0u,0u,0u,0u):*out=status_body_149(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D3u,0u,0u,0u):*out=status_body_150(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D5u,0u,0u,0u):*out=status_body_151(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83D7u,0u,0u,0u):*out=status_body_152(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DAu,0u,0u,0u):*out=status_body_153(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DCu,0u,0u,0u):*out=status_body_154(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83DEu,0u,0u,0u):*out=status_body_155(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E1u,0u,0u,0u):*out=status_body_156(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E3u,0u,0u,0u):*out=status_body_157(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E5u,0u,1u,0u):*out=status_body_158(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E7u,0u,1u,0u):*out=status_body_159(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83E9u,0u,1u,0u):*out=status_body_160(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83EBu,0u,1u,0u):*out=status_body_161(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83EEu,0u,1u,0u):*out=status_body_162(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F0u,0u,0u,0u):*out=status_body_163(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F3u,0u,0u,0u):*out=status_body_164(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F6u,0u,0u,0u):*out=status_body_165(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83F8u,0u,0u,0u):*out=status_body_166(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83FBu,0u,0u,0u):*out=status_body_167(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x83FDu,0u,0u,0u):*out=status_body_168(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8400u,0u,0u,0u):*out=status_body_169(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8402u,0u,0u,0u):*out=status_body_170(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8404u,0u,0u,0u):*out=status_body_171(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8407u,0u,0u,0u):*out=status_body_172(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8409u,0u,0u,0u):*out=status_body_173(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x840Cu,0u,0u,0u):*out=status_body_174(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x840Fu,0u,0u,0u):*out=status_body_175(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8412u,0u,0u,0u):*out=status_body_176(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u):*out=status_body_177(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8417u,0u,0u,0u):*out=status_body_178(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8419u,0u,0u,0u):*out=status_body_179(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x841Cu,0u,0u,0u):*out=status_body_180(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x841Eu,0u,0u,0u):*out=status_body_181(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8421u,0u,0u,0u):*out=status_body_182(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8424u,0u,0u,0u):*out=status_body_183(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8427u,0u,0u,0u):*out=status_body_184(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8429u,0u,0u,0u):*out=status_body_185(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x842Cu,0u,0u,0u):*out=status_body_186(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x842Fu,0u,0u,0u):*out=status_body_187(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8432u,0u,0u,0u):*out=status_body_188(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8435u,0u,0u,0u):*out=status_body_189(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8438u,0u,0u,0u):*out=status_body_190(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Au,0u,0u,0u):*out=status_body_191(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Du,0u,0u,0u):*out=status_body_192(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x843Fu,0u,0u,0u):*out=status_body_193(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8442u,0u,0u,0u):*out=status_body_194(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8445u,0u,0u,0u):*out=status_body_195(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8448u,0u,0u,0u):*out=status_body_196(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Au,0u,0u,0u):*out=status_body_197(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Du,0u,0u,0u):*out=status_body_198(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x844Fu,0u,0u,0u):*out=status_body_199(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8452u,0u,0u,0u):*out=status_body_200(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8455u,0u,0u,0u):*out=status_body_201(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8458u,0u,0u,0u):*out=status_body_202(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x845Bu,0u,0u,0u):*out=status_body_203(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x845Eu,0u,0u,0u):*out=status_body_204(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8460u,0u,0u,0u):*out=status_body_205(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8463u,0u,0u,0u):*out=status_body_206(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8465u,0u,0u,0u):*out=status_body_207(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8467u,0u,0u,0u):*out=status_body_208(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Au,0u,0u,0u):*out=status_body_209(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Cu,0u,0u,0u):*out=status_body_210(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x846Fu,0u,0u,0u):*out=status_body_211(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8472u,0u,0u,0u):*out=status_body_212(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8474u,0u,0u,0u):*out=status_body_213(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8477u,0u,0u,0u):*out=status_body_214(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Au,0u,0u,0u):*out=status_body_215(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Cu,0u,0u,0u):*out=status_body_216(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x847Fu,0u,0u,0u):*out=status_body_217(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8481u,0u,0u,0u):*out=status_body_218(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8484u,0u,0u,0u):*out=status_body_219(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8487u,0u,0u,0u):*out=status_body_220(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Au,0u,0u,0u):*out=status_body_221(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Cu,0u,0u,0u):*out=status_body_222(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x848Fu,0u,0u,0u):*out=status_body_223(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8490u,0u,0u,0u):*out=status_body_224(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8491u,0u,0u,0u):*out=status_body_225(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8492u,0u,0u,0u):*out=status_body_226(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8493u,0u,0u,0u):*out=status_body_227(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8497u,0u,0u,0u):*out=status_body_228(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8499u,0u,0u,0u):*out=status_body_229(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x849Du,0u,0u,0u):*out=status_body_230(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x849Fu,0u,0u,0u):*out=status_body_231(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A2u,0u,0u,0u):*out=status_body_232(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A4u,0u,0u,0u):*out=status_body_233(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84A7u,0u,0u,0u):*out=status_body_234(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84AAu,0u,0u,0u):*out=status_body_235(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84ADu,0u,0u,0u):*out=status_body_236(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84AFu,0u,0u,0u):*out=status_body_237(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B2u,0u,0u,0u):*out=status_body_238(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B4u,0u,0u,0u):*out=status_body_239(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B7u,0u,0u,0u):*out=status_body_240(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84B9u,0u,1u,0u):*out=status_body_241(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BBu,0u,1u,0u):*out=status_body_242(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BDu,0u,1u,0u):*out=status_body_243(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84BFu,0u,1u,0u):*out=status_body_244(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C2u,0u,1u,0u):*out=status_body_245(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C4u,0u,0u,0u):*out=status_body_246(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84C7u,0u,0u,0u):*out=status_body_247(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CAu,0u,0u,0u):*out=status_body_248(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CCu,0u,0u,0u):*out=status_body_249(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84CFu,0u,0u,0u):*out=status_body_250(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D2u,0u,0u,0u):*out=status_body_251(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D5u,0u,0u,0u):*out=status_body_252(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84D8u,0u,0u,0u):*out=status_body_253(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u):*out=status_body_254(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84DEu,0u,0u,0u):*out=status_body_255(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E0u,0u,0u,0u):*out=status_body_256(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E3u,0u,0u,0u):*out=status_body_257(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x84E5u,0u,0u,0u):*out=status_body_258(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8525u,0u,0u,0u):*out=status_body_259(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8528u,0u,0u,0u):*out=status_body_260(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Bu,0u,0u,0u):*out=status_body_261(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Du,0u,0u,0u):*out=status_body_262(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Eu,0u,0u,0u):*out=status_body_263(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x852Fu,0u,0u,0u):*out=status_body_264(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8533u,0u,0u,0u):*out=status_body_265(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8535u,0u,0u,0u):*out=status_body_266(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8539u,0u,0u,0u):*out=status_body_267(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x853Cu,0u,0u,0u):*out=status_body_268(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x853Eu,0u,0u,0u):*out=status_body_269(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8542u,0u,0u,0u):*out=status_body_270(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8545u,0u,0u,0u):*out=status_body_271(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8546u,0u,0u,0u):*out=status_body_272(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8549u,0u,0u,0u):*out=status_body_273(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x854Bu,0u,0u,0u):*out=status_body_274(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x854Du,0u,0u,0u):*out=status_body_275(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8550u,0u,0u,0u):*out=status_body_276(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8552u,0u,0u,0u):*out=status_body_277(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8555u,0u,0u,0u):*out=status_body_278(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8557u,0u,0u,0u):*out=status_body_279(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Au,0u,0u,0u):*out=status_body_280(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Du,0u,0u,0u):*out=status_body_281(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x855Eu,0u,0u,0u):*out=status_body_282(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8561u,0u,0u,0u):*out=status_body_283(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8562u,0u,0u,0u):*out=status_body_284(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8565u,0u,0u,0u):*out=status_body_285(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8568u,0u,0u,0u):*out=status_body_286(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Au,0u,0u,0u):*out=status_body_287(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Bu,0u,0u,0u):*out=status_body_288(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x856Cu,0u,0u,0u):*out=status_body_289(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8570u,0u,0u,0u):*out=status_body_290(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8572u,0u,0u,0u):*out=status_body_291(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8576u,0u,0u,0u):*out=status_body_292(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8579u,0u,0u,0u):*out=status_body_293(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x857Bu,0u,0u,0u):*out=status_body_294(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x857Fu,0u,0u,0u):*out=status_body_295(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8582u,0u,0u,0u):*out=status_body_296(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8583u,0u,0u,0u):*out=status_body_297(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8586u,0u,0u,0u):*out=status_body_298(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8588u,0u,0u,0u):*out=status_body_299(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Au,0u,0u,0u):*out=status_body_300(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Bu,0u,0u,0u):*out=status_body_301(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u):*out=status_body_302(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8815u,0u,0u,0u):*out=status_body_303(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8818u,0u,0u,0u):*out=status_body_304(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x881Bu,0u,0u,0u):*out=status_body_305(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x881Eu,0u,0u,0u):*out=status_body_306(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8821u,0u,0u,0u):*out=status_body_307(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8824u,0u,0u,0u):*out=status_body_308(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8827u,0u,0u,0u):*out=status_body_309(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x882Bu,0u,0u,0u):*out=status_body_310(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x882Eu,0u,0u,0u):*out=status_body_311(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8831u,0u,0u,0u):*out=status_body_312(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8834u,0u,0u,0u):*out=status_body_313(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8837u,0u,0u,0u):*out=status_body_314(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DA5u,0u,0u,0u):*out=status_body_315(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DA7u,0u,0u,0u):*out=status_body_316(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DAAu,0u,0u,0u):*out=status_body_317(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DACu,0u,0u,0u):*out=status_body_318(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DAFu,0u,0u,0u):*out=status_body_319(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB1u,0u,0u,0u):*out=status_body_320(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB4u,0u,0u,0u):*out=status_body_321(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB6u,0u,0u,0u):*out=status_body_322(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB8u,0u,0u,0u):*out=status_body_323(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DB9u,0u,0u,0u):*out=status_body_324(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBAu,0u,0u,0u):*out=status_body_325(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBBu,0u,0u,0u):*out=status_body_326(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBDu,0u,0u,0u):*out=status_body_327(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DBFu,0u,0u,0u):*out=status_body_328(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC2u,0u,0u,0u):*out=status_body_329(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC5u,0u,0u,0u):*out=status_body_330(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC6u,0u,0u,0u):*out=status_body_331(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC7u,0u,0u,0u):*out=status_body_332(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DC8u,0u,0u,0u):*out=status_body_333(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DCBu,0u,0u,0u):*out=status_body_334(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DCDu,0u,0u,0u):*out=status_body_335(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD0u,0u,0u,0u):*out=status_body_336(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD1u,0u,0u,0u):*out=status_body_337(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD2u,0u,0u,0u):*out=status_body_338(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD3u,0u,0u,0u):*out=status_body_339(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DD7u,0u,0u,0u):*out=status_body_340(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDAu,0u,0u,0u):*out=status_body_341(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDCu,0u,0u,0u):*out=status_body_342(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DDEu,0u,0u,0u):*out=status_body_343(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE0u,0u,0u,0u):*out=status_body_344(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE1u,0u,0u,0u):*out=status_body_345(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE2u,0u,0u,0u):*out=status_body_346(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE3u,0u,0u,0u):*out=status_body_347(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE4u,0u,0u,0u):*out=status_body_348(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE7u,0u,0u,0u):*out=status_body_349(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DE8u,0u,0u,0u):*out=status_body_350(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEAu,0u,0u,0u):*out=status_body_351(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEBu,0u,0u,0u):*out=status_body_352(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DEEu,0u,0u,0u):*out=status_body_353(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF0u,0u,0u,0u):*out=status_body_354(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF2u,0u,0u,0u):*out=status_body_355(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8DF4u,0u,0u,0u):*out=status_body_356(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F4Fu,0u,0u,0u):*out=status_body_357(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F52u,0u,0u,0u):*out=status_body_358(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F54u,0u,0u,0u):*out=status_body_359(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F57u,0u,0u,0u):*out=status_body_360(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Au,0u,0u,0u):*out=status_body_361(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Cu,0u,0u,0u):*out=status_body_362(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F5Fu,0u,0u,0u):*out=status_body_363(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F62u,0u,0u,0u):*out=status_body_364(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F64u,0u,0u,0u):*out=status_body_365(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F67u,0u,0u,0u):*out=status_body_366(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F68u,0u,0u,0u):*out=status_body_367(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Bu,0u,0u,0u):*out=status_body_368(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Du,0u,0u,0u):*out=status_body_369(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F6Fu,0u,0u,0u):*out=status_body_370(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F70u,0u,0u,0u):*out=status_body_371(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F71u,0u,0u,0u):*out=status_body_372(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F73u,0u,0u,0u):*out=status_body_373(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F75u,0u,0u,0u):*out=status_body_374(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F78u,0u,0u,0u):*out=status_body_375(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F7Bu,0u,0u,0u):*out=status_body_376(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F7Du,0u,0u,0u):*out=status_body_377(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F81u,0u,0u,0u):*out=status_body_378(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F82u,0u,0u,0u):*out=status_body_379(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F83u,0u,0u,0u):*out=status_body_380(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F85u,0u,0u,0u):*out=status_body_381(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F89u,0u,0u,0u):*out=status_body_382(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F8Cu,0u,0u,0u):*out=status_body_383(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F90u,0u,0u,0u):*out=status_body_384(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F93u,0u,0u,0u):*out=status_body_385(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F97u,0u,0u,0u):*out=status_body_386(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F9Au,0u,0u,0u):*out=status_body_387(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8F9Eu,0u,0u,0u):*out=status_body_388(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA1u,0u,0u,0u):*out=status_body_389(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA5u,0u,0u,0u):*out=status_body_390(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FA8u,0u,0u,0u):*out=status_body_391(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FABu,0u,0u,0u):*out=status_body_392(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FADu,0u,0u,0u):*out=status_body_393(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB1u,0u,0u,0u):*out=status_body_394(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB2u,0u,0u,0u):*out=status_body_395(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB3u,0u,0u,0u):*out=status_body_396(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB5u,0u,0u,0u):*out=status_body_397(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FB9u,0u,0u,0u):*out=status_body_398(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FBCu,0u,0u,0u):*out=status_body_399(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC0u,0u,0u,0u):*out=status_body_400(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC3u,0u,0u,0u):*out=status_body_401(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FC7u,0u,0u,0u):*out=status_body_402(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FCAu,0u,0u,0u):*out=status_body_403(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FCEu,0u,0u,0u):*out=status_body_404(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD1u,0u,0u,0u):*out=status_body_405(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD5u,0u,0u,0u):*out=status_body_406(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FD8u,0u,0u,0u):*out=status_body_407(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FDBu,0u,0u,0u):*out=status_body_408(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FDDu,0u,0u,0u):*out=status_body_409(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE1u,0u,0u,0u):*out=status_body_410(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE2u,0u,0u,0u):*out=status_body_411(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE3u,0u,0u,0u):*out=status_body_412(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE5u,0u,0u,0u):*out=status_body_413(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FE9u,0u,0u,0u):*out=status_body_414(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FECu,0u,0u,0u):*out=status_body_415(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF0u,0u,0u,0u):*out=status_body_416(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF3u,0u,0u,0u):*out=status_body_417(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FF7u,0u,0u,0u):*out=status_body_418(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FFAu,0u,0u,0u):*out=status_body_419(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x8FFEu,0u,0u,0u):*out=status_body_420(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9001u,0u,0u,0u):*out=status_body_421(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9005u,0u,0u,0u):*out=status_body_422(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9008u,0u,0u,0u):*out=status_body_423(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Au,0u,0u,0u):*out=status_body_424(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Du,0u,0u,0u):*out=status_body_425(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x900Fu,0u,0u,0u):*out=status_body_426(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9012u,0u,0u,0u):*out=status_body_427(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9014u,0u,0u,0u):*out=status_body_428(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9017u,0u,0u,0u):*out=status_body_429(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9019u,0u,0u,0u):*out=status_body_430(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x901Cu,0u,0u,0u):*out=status_body_431(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x901Eu,0u,0u,0u):*out=status_body_432(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9021u,0u,0u,0u):*out=status_body_433(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9023u,0u,0u,0u):*out=status_body_434(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9026u,0u,0u,0u):*out=status_body_435(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9028u,0u,0u,0u):*out=status_body_436(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x902Bu,0u,0u,0u):*out=status_body_437(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x902Du,0u,0u,0u):*out=status_body_438(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9030u,0u,0u,0u):*out=status_body_439(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9032u,0u,0u,0u):*out=status_body_440(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9035u,0u,0u,0u):*out=status_body_441(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9037u,0u,0u,0u):*out=status_body_442(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Au,0u,0u,0u):*out=status_body_443(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Cu,0u,0u,0u):*out=status_body_444(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x903Fu,0u,0u,0u):*out=status_body_445(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9041u,0u,0u,0u):*out=status_body_446(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9044u,0u,0u,0u):*out=status_body_447(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9045u,0u,0u,0u):*out=status_body_448(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9048u,0u,0u,0u):*out=status_body_449(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Au,0u,0u,0u):*out=status_body_450(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Cu,0u,0u,0u):*out=status_body_451(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Du,0u,0u,0u):*out=status_body_452(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x904Eu,0u,0u,0u):*out=status_body_453(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9050u,0u,0u,0u):*out=status_body_454(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9052u,0u,0u,0u):*out=status_body_455(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9055u,0u,0u,0u):*out=status_body_456(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9057u,0u,0u,0u):*out=status_body_457(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9058u,0u,0u,0u):*out=status_body_458(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Au,0u,0u,0u):*out=status_body_459(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Cu,0u,0u,0u):*out=status_body_460(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x905Fu,0u,0u,0u):*out=status_body_461(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9061u,0u,0u,0u):*out=status_body_462(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9064u,0u,0u,0u):*out=status_body_463(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9066u,0u,0u,0u):*out=status_body_464(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9069u,0u,0u,0u):*out=status_body_465(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Bu,0u,0u,0u):*out=status_body_466(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Cu,0u,0u,0u):*out=status_body_467(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x906Fu,0u,0u,0u):*out=status_body_468(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9072u,0u,0u,0u):*out=status_body_469(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9074u,0u,0u,0u):*out=status_body_470(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9076u,0u,0u,0u):*out=status_body_471(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9079u,0u,0u,0u):*out=status_body_472(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x907Cu,0u,0u,0u):*out=status_body_473(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x907Fu,0u,0u,0u):*out=status_body_474(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9080u,0u,0u,0u):*out=status_body_475(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9083u,0u,0u,0u):*out=status_body_476(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9086u,0u,0u,0u):*out=status_body_477(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9089u,0u,0u,0u):*out=status_body_478(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Au,0u,0u,0u):*out=status_body_479(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Du,0u,0u,0u):*out=status_body_480(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x908Fu,0u,0u,0u):*out=status_body_481(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9092u,0u,0u,0u):*out=status_body_482(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9094u,0u,0u,0u):*out=status_body_483(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9096u,0u,0u,0u):*out=status_body_484(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9099u,0u,0u,0u):*out=status_body_485(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Au,0u,0u,0u):*out=status_body_486(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Du,0u,0u,0u):*out=status_body_487(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x909Eu,0u,0u,0u):*out=status_body_488(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A0u,0u,0u,0u):*out=status_body_489(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A3u,0u,0u,0u):*out=status_body_490(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A6u,0u,0u,0u):*out=status_body_491(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90A8u,0u,0u,0u):*out=status_body_492(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90ABu,0u,0u,0u):*out=status_body_493(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90AEu,0u,0u,0u):*out=status_body_494(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B1u,0u,0u,0u):*out=status_body_495(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B3u,0u,0u,0u):*out=status_body_496(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B4u,0u,0u,0u):*out=status_body_497(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B7u,0u,0u,0u):*out=status_body_498(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90B9u,0u,0u,0u):*out=status_body_499(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90BBu,0u,0u,0u):*out=status_body_500(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90BEu,0u,0u,0u):*out=status_body_501(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C0u,0u,0u,0u):*out=status_body_502(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C1u,0u,0u,0u):*out=status_body_503(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C4u,0u,0u,0u):*out=status_body_504(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C6u,0u,0u,0u):*out=status_body_505(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90C8u,0u,0u,0u):*out=status_body_506(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CBu,0u,0u,0u):*out=status_body_507(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CCu,0u,0u,0u):*out=status_body_508(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CDu,0u,0u,0u):*out=status_body_509(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CEu,0u,0u,0u):*out=status_body_510(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90CFu,0u,0u,0u):*out=status_body_511(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D0u,0u,0u,0u):*out=status_body_512(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D3u,0u,0u,0u):*out=status_body_513(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D5u,0u,0u,0u):*out=status_body_514(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90D7u,0u,0u,0u):*out=status_body_515(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DAu,0u,0u,0u):*out=status_body_516(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DCu,0u,0u,0u):*out=status_body_517(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90DFu,0u,0u,0u):*out=status_body_518(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E0u,0u,0u,0u):*out=status_body_519(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E3u,0u,0u,0u):*out=status_body_520(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E5u,0u,0u,0u):*out=status_body_521(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90E8u,0u,0u,0u):*out=status_body_522(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90EAu,0u,0u,0u):*out=status_body_523(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90ECu,0u,0u,0u):*out=status_body_524(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90EFu,0u,0u,0u):*out=status_body_525(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F2u,0u,0u,0u):*out=status_body_526(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F4u,0u,0u,0u):*out=status_body_527(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90F7u,0u,0u,0u):*out=status_body_528(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FAu,0u,0u,0u):*out=status_body_529(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FDu,0u,0u,0u):*out=status_body_530(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x90FFu,0u,0u,0u):*out=status_body_531(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9101u,0u,0u,0u):*out=status_body_532(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9104u,0u,0u,0u):*out=status_body_533(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9106u,0u,0u,0u):*out=status_body_534(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9108u,0u,0u,0u):*out=status_body_535(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Bu,0u,0u,0u):*out=status_body_536(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Cu,0u,0u,0u):*out=status_body_537(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Du,0u,0u,0u):*out=status_body_538(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Eu,0u,0u,0u):*out=status_body_539(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x910Fu,0u,0u,0u):*out=status_body_540(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9110u,0u,0u,0u):*out=status_body_541(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9113u,0u,0u,0u):*out=status_body_542(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9115u,0u,0u,0u):*out=status_body_543(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9117u,0u,0u,0u):*out=status_body_544(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Au,0u,0u,0u):*out=status_body_545(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Cu,0u,0u,0u):*out=status_body_546(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Du,0u,0u,0u):*out=status_body_547(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Eu,0u,0u,0u):*out=status_body_548(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x911Fu,0u,0u,0u):*out=status_body_549(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9120u,0u,0u,0u):*out=status_body_550(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9121u,0u,0u,0u):*out=status_body_551(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9123u,0u,0u,0u):*out=status_body_552(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9125u,0u,0u,0u):*out=status_body_553(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9126u,0u,0u,0u):*out=status_body_554(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9127u,0u,0u,0u):*out=status_body_555(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9129u,0u,0u,0u):*out=status_body_556(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x912Bu,0u,0u,0u):*out=status_body_557(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x912Eu,0u,0u,0u):*out=status_body_558(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9130u,0u,0u,0u):*out=status_body_559(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9133u,0u,0u,0u):*out=status_body_560(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9135u,0u,0u,0u):*out=status_body_561(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9137u,0u,0u,0u):*out=status_body_562(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Au,0u,0u,0u):*out=status_body_563(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Cu,0u,0u,0u):*out=status_body_564(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x913Fu,0u,0u,0u):*out=status_body_565(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9141u,0u,0u,0u):*out=status_body_566(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9144u,0u,0u,0u):*out=status_body_567(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9146u,0u,0u,0u):*out=status_body_568(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9147u,0u,0u,0u):*out=status_body_569(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9149u,0u,0u,0u):*out=status_body_570(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x914Bu,0u,0u,0u):*out=status_body_571(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x914Eu,0u,0u,0u):*out=status_body_572(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9150u,0u,0u,0u):*out=status_body_573(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9152u,0u,0u,0u):*out=status_body_574(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9155u,0u,0u,0u):*out=status_body_575(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9157u,0u,0u,0u):*out=status_body_576(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Au,0u,0u,0u):*out=status_body_577(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Cu,0u,0u,0u):*out=status_body_578(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x915Eu,0u,0u,0u):*out=status_body_579(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9160u,0u,0u,0u):*out=status_body_580(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9163u,0u,0u,0u):*out=status_body_581(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9165u,0u,0u,0u):*out=status_body_582(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9168u,0u,0u,0u):*out=status_body_583(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Au,0u,0u,0u):*out=status_body_584(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Cu,0u,0u,0u):*out=status_body_585(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x916Fu,0u,0u,0u):*out=status_body_586(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9171u,0u,0u,0u):*out=status_body_587(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9173u,0u,0u,0u):*out=status_body_588(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9175u,0u,0u,0u):*out=status_body_589(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9177u,0u,0u,0u):*out=status_body_590(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9179u,0u,0u,0u):*out=status_body_591(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x917Cu,0u,0u,0u):*out=status_body_592(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x917Eu,0u,0u,0u):*out=status_body_593(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9180u,0u,0u,0u):*out=status_body_594(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9183u,0u,0u,0u):*out=status_body_595(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9185u,0u,0u,0u):*out=status_body_596(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9188u,0u,0u,0u):*out=status_body_597(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Au,0u,0u,0u):*out=status_body_598(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Cu,0u,0u,0u):*out=status_body_599(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x918Eu,0u,0u,0u):*out=status_body_600(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9190u,0u,0u,0u):*out=status_body_601(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9191u,0u,0u,0u):*out=status_body_602(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9194u,0u,0u,0u):*out=status_body_603(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9196u,0u,0u,0u):*out=status_body_604(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x9198u,0u,0u,0u):*out=status_body_605(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Bu,0u,0u,0u):*out=status_body_606(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Du,0u,0u,0u):*out=status_body_607(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x919Fu,0u,0u,0u):*out=status_body_608(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A2u,0u,0u,0u):*out=status_body_609(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A4u,0u,0u,0u):*out=status_body_610(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A5u,0u,0u,0u):*out=status_body_611(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A6u,0u,0u,0u):*out=status_body_612(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A7u,0u,0u,0u):*out=status_body_613(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91A9u,0u,0u,0u):*out=status_body_614(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91ACu,0u,0u,0u):*out=status_body_615(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91AEu,0u,0u,0u):*out=status_body_616(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91AFu,0u,0u,0u):*out=status_body_617(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B1u,0u,0u,0u):*out=status_body_618(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B2u,0u,0u,0u):*out=status_body_619(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B4u,0u,0u,0u):*out=status_body_620(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B7u,0u,0u,0u):*out=status_body_621(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91B9u,0u,0u,0u):*out=status_body_622(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91BCu,0u,0u,0u):*out=status_body_623(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91BEu,0u,0u,0u):*out=status_body_624(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C1u,0u,0u,0u):*out=status_body_625(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C3u,0u,0u,0u):*out=status_body_626(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C5u,0u,0u,0u):*out=status_body_627(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91C8u,0u,0u,0u):*out=status_body_628(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CAu,0u,0u,0u):*out=status_body_629(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CCu,0u,0u,0u):*out=status_body_630(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91CFu,0u,0u,0u):*out=status_body_631(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0x91D1u,0u,0u,0u):*out=status_body_632(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA027u,0u,0u,0u):*out=status_body_633(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA029u,0u,0u,0u):*out=status_body_634(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA02Bu,0u,0u,0u):*out=status_body_635(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA02Eu,0u,0u,0u):*out=status_body_636(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA030u,0u,0u,0u):*out=status_body_637(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA033u,0u,0u,0u):*out=status_body_638(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA035u,0u,0u,0u):*out=status_body_639(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA038u,0u,0u,0u):*out=status_body_640(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA039u,0u,0u,0u):*out=status_body_641(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Au,0u,0u,0u):*out=status_body_642(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Du,0u,0u,0u):*out=status_body_643(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA03Fu,0u,0u,0u):*out=status_body_644(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA041u,0u,0u,0u):*out=status_body_645(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA044u,0u,0u,0u):*out=status_body_646(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA046u,0u,0u,0u):*out=status_body_647(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA049u,0u,0u,0u):*out=status_body_648(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA04Cu,0u,0u,0u):*out=status_body_649(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA04Fu,0u,0u,0u):*out=status_body_650(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA051u,0u,0u,0u):*out=status_body_651(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA054u,0u,0u,0u):*out=status_body_652(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA057u,0u,0u,0u):*out=status_body_653(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA059u,0u,0u,0u):*out=status_body_654(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA05Cu,0u,0u,0u):*out=status_body_655(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA05Fu,0u,0u,0u):*out=status_body_656(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA062u,0u,0u,0u):*out=status_body_657(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA064u,0u,0u,0u):*out=status_body_658(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA066u,0u,0u,0u):*out=status_body_659(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA069u,0u,0u,0u):*out=status_body_660(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA06Bu,0u,0u,0u):*out=status_body_661(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA06Eu,0u,0u,0u):*out=status_body_662(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA071u,0u,0u,0u):*out=status_body_663(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA074u,0u,0u,0u):*out=status_body_664(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA076u,0u,0u,0u):*out=status_body_665(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA078u,0u,0u,0u):*out=status_body_666(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA07Bu,0u,0u,0u):*out=status_body_667(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA07Eu,0u,0u,0u):*out=status_body_668(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA081u,0u,0u,0u):*out=status_body_669(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA084u,0u,0u,0u):*out=status_body_670(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA087u,0u,0u,0u):*out=status_body_671(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA089u,0u,0u,0u):*out=status_body_672(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA08Bu,0u,0u,0u):*out=status_body_673(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA08Eu,0u,0u,0u):*out=status_body_674(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA090u,0u,0u,0u):*out=status_body_675(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA093u,0u,0u,0u):*out=status_body_676(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA096u,0u,0u,0u):*out=status_body_677(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA098u,0u,0u,0u):*out=status_body_678(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Bu,0u,0u,0u):*out=status_body_679(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Eu,0u,0u,0u):*out=status_body_680(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA09Fu,0u,0u,0u):*out=status_body_681(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A0u,0u,0u,0u):*out=status_body_682(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A3u,0u,0u,0u):*out=status_body_683(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A5u,0u,0u,0u):*out=status_body_684(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0A7u,0u,0u,0u):*out=status_body_685(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0AAu,0u,0u,0u):*out=status_body_686(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0ACu,0u,0u,0u):*out=status_body_687(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0AFu,0u,0u,0u):*out=status_body_688(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B2u,0u,0u,0u):*out=status_body_689(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B4u,0u,0u,0u):*out=status_body_690(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0B7u,0u,0u,0u):*out=status_body_691(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BAu,0u,0u,0u):*out=status_body_692(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BBu,0u,0u,0u):*out=status_body_693(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BCu,0u,0u,0u):*out=status_body_694(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BDu,0u,0u,0u):*out=status_body_695(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BEu,0u,0u,0u):*out=status_body_696(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0BFu,0u,0u,0u):*out=status_body_697(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C0u,0u,0u,0u):*out=status_body_698(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C2u,0u,0u,0u):*out=status_body_699(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C4u,0u,0u,0u):*out=status_body_700(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C7u,0u,0u,0u):*out=status_body_701(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0C9u,0u,0u,0u):*out=status_body_702(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0CCu,0u,0u,0u):*out=status_body_703(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0CEu,0u,0u,0u):*out=status_body_704(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D1u,0u,0u,0u):*out=status_body_705(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D2u,0u,0u,0u):*out=status_body_706(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D5u,0u,0u,0u):*out=status_body_707(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0D7u,0u,0u,0u):*out=status_body_708(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DAu,0u,0u,0u):*out=status_body_709(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DDu,0u,0u,0u):*out=status_body_710(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0DFu,0u,0u,0u):*out=status_body_711(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E2u,0u,0u,0u):*out=status_body_712(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E5u,0u,0u,0u):*out=status_body_713(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E6u,0u,0u,0u):*out=status_body_714(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0E9u,0u,0u,0u):*out=status_body_715(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0EBu,0u,0u,0u):*out=status_body_716(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0EEu,0u,0u,0u):*out=status_body_717(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F1u,0u,0u,0u):*out=status_body_718(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F3u,0u,0u,0u):*out=status_body_719(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F6u,0u,0u,0u):*out=status_body_720(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0F9u,0u,0u,0u):*out=status_body_721(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xA0FAu,0u,0u,0u):*out=status_body_722(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF01u,0u,0u,0u):*out=status_body_723(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF04u,0u,0u,0u):*out=status_body_724(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF06u,0u,0u,0u):*out=status_body_725(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF07u,0u,0u,0u):*out=status_body_726(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF09u,0u,0u,0u):*out=status_body_727(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Cu,0u,0u,0u):*out=status_body_728(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Du,0u,0u,0u):*out=status_body_729(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF0Eu,0u,0u,0u):*out=status_body_730(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF10u,0u,0u,0u):*out=status_body_731(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF11u,0u,0u,0u):*out=status_body_732(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF14u,0u,0u,0u):*out=status_body_733(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF16u,0u,0u,0u):*out=status_body_734(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF19u,0u,0u,0u):*out=status_body_735(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Bu,0u,0u,0u):*out=status_body_736(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Du,0u,0u,0u):*out=status_body_737(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF1Eu,0u,0u,0u):*out=status_body_738(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF21u,0u,0u,0u):*out=status_body_739(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF24u,0u,0u,0u):*out=status_body_740(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF27u,0u,0u,0u):*out=status_body_741(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF29u,0u,0u,0u):*out=status_body_742(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF2Au,0u,0u,0u):*out=status_body_743(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF2Du,0u,0u,0u):*out=status_body_744(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF30u,0u,0u,0u):*out=status_body_745(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF31u,0u,0u,0u):*out=status_body_746(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF34u,0u,0u,0u):*out=status_body_747(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF36u,0u,0u,0u):*out=status_body_748(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF39u,0u,0u,0u):*out=status_body_749(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Bu,0u,0u,0u):*out=status_body_750(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Du,0u,0u,0u):*out=status_body_751(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF3Eu,0u,0u,0u):*out=status_body_752(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF40u,0u,0u,0u):*out=status_body_753(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF43u,0u,0u,0u):*out=status_body_754(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF46u,0u,0u,0u):*out=status_body_755(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF49u,0u,0u,0u):*out=status_body_756(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Au,0u,0u,0u):*out=status_body_757(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Bu,0u,0u,0u):*out=status_body_758(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Cu,0u,0u,0u):*out=status_body_759(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Du,0u,0u,0u):*out=status_body_760(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Eu,0u,0u,0u):*out=status_body_761(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF4Fu,0u,0u,0u):*out=status_body_762(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF52u,0u,0u,0u):*out=status_body_763(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF53u,0u,0u,0u):*out=status_body_764(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF55u,0u,0u,0u):*out=status_body_765(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF56u,0u,0u,0u):*out=status_body_766(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF57u,0u,0u,0u):*out=status_body_767(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Au,0u,0u,0u):*out=status_body_768(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Cu,0u,0u,0u):*out=status_body_769(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF5Fu,0u,0u,0u):*out=status_body_770(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF61u,0u,0u,0u):*out=status_body_771(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF63u,0u,0u,0u):*out=status_body_772(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF64u,0u,0u,0u):*out=status_body_773(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF67u,0u,0u,0u):*out=status_body_774(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Au,0u,0u,0u):*out=status_body_775(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Du,0u,0u,0u):*out=status_body_776(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF6Fu,0u,0u,0u):*out=status_body_777(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF70u,0u,0u,0u):*out=status_body_778(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF73u,0u,0u,0u):*out=status_body_779(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF76u,0u,0u,0u):*out=status_body_780(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF77u,0u,0u,0u):*out=status_body_781(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Au,0u,0u,0u):*out=status_body_782(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Cu,0u,0u,0u):*out=status_body_783(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF7Fu,0u,0u,0u):*out=status_body_784(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF81u,0u,0u,0u):*out=status_body_785(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF83u,0u,0u,0u):*out=status_body_786(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF84u,0u,0u,0u):*out=status_body_787(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF86u,0u,0u,0u):*out=status_body_788(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF89u,0u,0u,0u):*out=status_body_789(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Cu,0u,0u,0u):*out=status_body_790(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Du,0u,0u,0u):*out=status_body_791(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Eu,0u,0u,0u):*out=status_body_792(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF8Fu,0u,0u,0u):*out=status_body_793(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF90u,0u,0u,0u):*out=status_body_794(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF91u,0u,0u,0u):*out=status_body_795(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF92u,0u,0u,0u):*out=status_body_796(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF95u,0u,0u,0u):*out=status_body_797(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF96u,0u,0u,0u):*out=status_body_798(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF98u,0u,0u,0u):*out=status_body_799(m);return 1;
case JS_V05C_KEY_CONST(0xA0u,0xBF99u,0u,0u,0u):*out=status_body_800(m);return 1;
default:return 0;}}
int jungle_status_return_allowed(js_static_context_key from,js_static_context_key to) {
uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);
if(f==JS_V05C_KEY_CONST(0x80u,0xB996u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xB996u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xB996u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xB996u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xB996u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBB60u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBB60u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBB60u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBB60u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBB60u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBA9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBA9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBA9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBA9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBA9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBBBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBBBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBBBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBBBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBBBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBF7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBF7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBF7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBF7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBBF7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBC37u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBC37u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBC37u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBC37u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBC37u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD96u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD96u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD96u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD96u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBD96u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBE01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA315u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBE01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xA752u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBE01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xBB31u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBE01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD3FDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xBE01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xD47Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86A1u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86AFu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86BDu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86CBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86D6u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86E1u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86ECu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x86F7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8702u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x870Du,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8718u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8723u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x872Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8739u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8744u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x874Fu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8762u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x876Du,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8778u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8783u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8797u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87A2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87ADu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87C1u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87CCu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87D7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87E2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x87F6u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8801u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xD484u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x880Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x882Au,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8835u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8840u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xDB11u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x884Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x80u,0xFD26u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0xDB83u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8520u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83B5u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8520u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x842Fu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8524u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83B5u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8524u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x842Fu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x855Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83B8u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x855Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8432u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8561u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83B8u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8561u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8432u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x858Au,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8445u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8445u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8593u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83F3u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8593u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84C7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x85ACu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83F3u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x85ACu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84C7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x85DBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84B7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8837u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA09Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8837u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0E5u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x885Au,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0F9u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x887Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0BAu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x889Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA071u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88C1u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA04Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88CDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x839Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88CDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x840Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88CDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8455u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88CDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84D2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x839Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x840Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8455u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x88E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84D2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8D47u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83B2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8D47u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x842Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8DE7u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84A7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8E01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8487u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8E01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x855Du,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8E01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8561u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8E01u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8DC5u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x8F67u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x9044u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x911Cu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x858Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91A4u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90A3u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91A4u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90EFu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91D1u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90AEu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91D1u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90FAu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91E4u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83AFu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91E4u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8421u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91E4u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8477u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91FBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83BBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91FBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8435u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x91FBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84AAu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x922Au,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83BEu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x922Au,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8438u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x922Au,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84ADu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x985Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA049u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x985Du,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA06Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x9876u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA09Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x9876u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0B7u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x9876u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0E2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x9876u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0xA0F6u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA039u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA09Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0BBu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0BDu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0BFu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8415u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0D1u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0E5u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0F9u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xA0FAu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84DBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB5E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x838Au,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB5E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8424u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB5E0u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x846Fu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB646u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x838Au,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB646u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8424u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xB646u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x846Fu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xBF06u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90DAu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xBF06u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x911Au,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xBF99u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x90DAu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xBF99u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x911Au,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xD022u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83CBu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xD022u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x9012u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE0DCu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83A2u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE0DCu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8412u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE0DCu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x845Bu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE0DCu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84D8u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE44Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83A5u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE44Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x83CEu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE44Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x8448u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE44Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x845Eu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0xE44Fu,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0xA0u,0x84DEu,0u,0u,0u))return 1;
return 0;}
int jungle_damage_dispatch_allowed(js_static_context_key from,js_static_context_key to) {
if(js_v05c_pack_key(from)!=JS_V05C_KEY_CONST(0x80u,0xDAD7u,0u,0u,0u))return 0;
switch(js_v05c_pack_key(to)){
case JS_V05C_KEY_CONST(0x80u,0xDAFCu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB01u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB12u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB29u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB40u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB5Bu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB79u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB88u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDB9Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0xDBB5u,0u,0u,0u):return 1;
default:return 0;}}
