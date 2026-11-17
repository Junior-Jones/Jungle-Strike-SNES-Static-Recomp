/* Offline immutable-ROM mission-result return closure. */
#include "static_core_compact_generated.h"
#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_v10_3_internal.h"
#include "jungle/cpu_v10_27_internal.h"
#include "jungle/cpu_v10_36_internal.h"
#include "jungle/cpu_v10_45_internal.h"
#include "jungle/cpu_dispatch_v10_100.h"
#include "jungle/status_v10_11.h"
#include "jungle/end_closure.h"
/* 80:8938:E0M0X0 2214C381 JSL */
static js_stop_reason end_body_0(js_machine_v05c *m) {
    /* 80:8938:E0M0X0 2214C381 JSL abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x22u, 0x14u, 0xC3u, 0x81u };
    r = js_v05c_guard_code(m, 2360u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push8(m, m->cpu.pbr);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x893Bu);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x81u,0xC314u,0u,0u,0u));
}
/* 80:893C:E0M0X0 A228C7 LDX */
static js_stop_reason end_body_1(js_machine_v05c *m) {
    /* 80:893C:E0M0X0 A228C7 LDX imm_x */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA2u, 0x28u, 0xC7u };
    r = js_v05c_guard_code(m, 2364u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_x(&m->cpu, 0xC728u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x893Fu,0u,0u,0u));
}
/* 80:893F:E0M0X0 A98100 LDA */
static js_stop_reason end_body_2(js_machine_v05c *m) {
    /* 80:893F:E0M0X0 A98100 LDA imm_m */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xA9u, 0x81u, 0x00u };
    r = js_v05c_guard_code(m, 2367u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, 0x0081u, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x8942u,0u,0u,0u));
}
/* 80:8942:E0M0X0 228DC581 JSL */
static js_stop_reason end_body_3(js_machine_v05c *m) {
    /* 80:8942:E0M0X0 228DC581 JSL abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x22u, 0x8Du, 0xC5u, 0x81u };
    r = js_v05c_guard_code(m, 2370u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_idle_cycles(m, 1u);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push8(m, m->cpu.pbr);
    if (r != JS_STOP_NONE) return r;
    r = js_v05c_push16(m, 0x8945u);
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x81u,0xC58Du,0u,0u,0u));
}
/* 80:8946:E0M0X0 AF9A117F LDA */
static js_stop_reason end_body_4(js_machine_v05c *m) {
    /* 80:8946:E0M0X0 AF9A117F LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0x9Au, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 2374u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F119Au;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x894Au,0u,0u,0u));
}
/* 80:894A:E0M0X0 8F96117F STA */
static js_stop_reason end_body_5(js_machine_v05c *m) {
    /* 80:894A:E0M0X0 8F96117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0x96u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 2378u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F1196u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x894Eu,0u,0u,0u));
}
/* 80:894E:E0M0X0 AF9C117F LDA */
static js_stop_reason end_body_6(js_machine_v05c *m) {
    /* 80:894E:E0M0X0 AF9C117F LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0x9Cu, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 2382u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F119Cu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x8952u,0u,0u,0u));
}
/* 80:8952:E0M0X0 8F98117F STA */
static js_stop_reason end_body_7(js_machine_v05c *m) {
    /* 80:8952:E0M0X0 8F98117F STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0x98u, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 2386u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F1198u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x8956u,0u,0u,0u));
}
/* 80:8956:E0M0X0 AF9E117F LDA */
static js_stop_reason end_body_8(js_machine_v05c *m) {
    /* 80:8956:E0M0X0 AF9E117F LDA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0xAFu, 0x9Eu, 0x11u, 0x7Fu };
    r = js_v05c_guard_code(m, 2390u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x7F119Eu;
    uint16_t value = 0u;
    r = js_v05c_read_value(m, ea, 16u, 0, &value);
    if (r != JS_STOP_NONE) return r;
    js_v05c_write_a(&m->cpu, value, 16u, 1);
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x895Au,0u,0u,0u));
}
/* 80:895A:E0M0X0 8FB80800 STA */
static js_stop_reason end_body_9(js_machine_v05c *m) {
    /* 80:895A:E0M0X0 8FB80800 STA abs_long */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x8Fu, 0xB8u, 0x08u, 0x00u };
    r = js_v05c_guard_code(m, 2394u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    uint32_t ea = 0x0008B8u;
    r = js_v05c_write_value(m, ea, 16u, 0, (uint16_t)(m->cpu.a & 0xFFFFu));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x895Eu,0u,0u,0u));
}
/* 80:895E:E0M0X0 4C1881 JMP */
static js_stop_reason end_body_10(js_machine_v05c *m) {
    /* 80:895E:E0M0X0 4C1881 JMP abs */
    js_stop_reason r = JS_STOP_NONE;
    static const uint8_t expected[] = { 0x4Cu, 0x18u, 0x81u };
    r = js_v05c_guard_code(m, 2398u, expected, sizeof(expected));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_finish_fixed(m, JS_CTX(0x80u,0x8118u,0u,0u,0u));
}
int jungle_end_context_known(js_static_context_key key){switch(js_v05c_pack_key(key)){
case JS_V05C_KEY_CONST(0x80u,0x8938u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x893Cu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x893Fu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x8942u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x8946u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x894Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x894Eu,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x8952u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x8956u,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x895Au,0u,0u,0u):return 1;
case JS_V05C_KEY_CONST(0x80u,0x895Eu,0u,0u,0u):return 1;
default:return 0;}}
int jungle_end_dispatch(js_machine_v05c*m,js_static_context_key key,js_stop_reason*out){switch(js_v05c_pack_key(key)){
case JS_V05C_KEY_CONST(0x80u,0x8938u,0u,0u,0u):*out=end_body_0(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x893Cu,0u,0u,0u):*out=end_body_1(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x893Fu,0u,0u,0u):*out=end_body_2(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x8942u,0u,0u,0u):*out=end_body_3(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x8946u,0u,0u,0u):*out=end_body_4(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x894Au,0u,0u,0u):*out=end_body_5(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x894Eu,0u,0u,0u):*out=end_body_6(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x8952u,0u,0u,0u):*out=end_body_7(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x8956u,0u,0u,0u):*out=end_body_8(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x895Au,0u,0u,0u):*out=end_body_9(m);return 1;
case JS_V05C_KEY_CONST(0x80u,0x895Eu,0u,0u,0u):*out=end_body_10(m);return 1;
default:return 0;}}
int jungle_end_return_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);
if(f==JS_V05C_KEY_CONST(0x81u,0xC336u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x893Cu,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0x81u,0xC727u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8946u,0u,0u,0u))return 1;
if(f==JS_V05C_KEY_CONST(0xA0u,0x81F8u,0u,0u,0u)&&t==JS_V05C_KEY_CONST(0x80u,0x8938u,0u,0u,0u))return 1;
return 0;}
