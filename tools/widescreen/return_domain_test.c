#include "jungle/cpu_v08c_internal.h"
#include "jungle/status_closure.h"
#include <stdio.h>
#include <string.h>
int main(void) {
  js_machine_v05c m;
  js_static_context_key allowed = {0x80u, 0xd298u, 0u, 0u, 0u};
  memset(&m, 0, sizeof(m));
  m.rom_identity_ok = 1;
  m.cpu.pbr = 0x80;
  m.cpu.pc = 0x8762;
  m.diagnostic_current_key.pbr = 0x80;
  m.diagnostic_current_key.pc = 0xd40f;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 1;
  m.cpu.pc = 0x8763;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 2;
  m.cpu.pc = 0x8762;
  m.diagnostic_current_key.pc = 0xd40e;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 3;
  m.diagnostic_current_key.pc = 0xd40f;
  m.cpu.e = 1;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 4;
  m.cpu.e = 0;
  m.rom_identity_ok = 0;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 5;
  puts("PASS frozen return edge and rejection of unknown "
       "target/source/mode/ROM");
  m.rom_identity_ok = 1;
  m.cpu.pbr = 0xa0;
  m.cpu.pc = 0x8452;
  m.diagnostic_current_key.pbr = 0xa0;
  m.diagnostic_current_key.pc = 0x816b;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_DYNAMIC_TARGET) != JS_STOP_NONE)
    return 6;
  m.cpu.pc = 0x84cf;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_DYNAMIC_TARGET) != JS_STOP_NONE)
    return 7;
  m.cpu.pc = 0x8453;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 8;
  m.cpu.pc = 0x8452;
  m.cpu.p = 0x20;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 9;
  m.cpu.p = 0;
  m.rom_identity_ok = 0;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 10;
  m.rom_identity_ok = 1;
  m.diagnostic_current_key.pc = 0x816a;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 11;
  m.diagnostic_current_key.pc = 0x88cd;
  m.cpu.pc = 0x8455;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 12;
  m.cpu.pc = 0x8456;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 13;
  if (!jungle_status_context_known(
          (js_static_context_key){0xa0, 0x8452, 0, 0, 0}) ||
      jungle_status_context_known(
          (js_static_context_key){0xa0, 0x8453, 0, 0, 0}) ||
      jungle_status_context_known(
          (js_static_context_key){0xa0, 0x8452, 0, 1, 0}))
    return 14;
  puts("PASS Status entry/poll/return domains and rejection of unknown "
       "target/source/mode/ROM");
  m.diagnostic_current_key = (js_static_context_key){0xa0, 0x816b, 0, 0, 0};
  m.cpu.pc = 0x8387;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_DYNAMIC_TARGET) != JS_STOP_NONE)
    return 15;
  m.cpu.pc = 0x83fb;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_DYNAMIC_TARGET) != JS_STOP_NONE)
    return 16;
  m.cpu.pc = 0x8388;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 17;
  m.cpu.pc = 0x8387;
  m.rom_identity_ok = 0;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 18;
  puts("PASS Mission entry/poll domains and rejection of adjacent "
       "target/unverified ROM");
  m.rom_identity_ok = 1;
  m.cpu.pbr = 0x80;
  m.cpu.pc = 0xd3fd;
  m.diagnostic_current_key = (js_static_context_key){0x80, 0xbd01, 0, 0, 0};
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 19;
  m.cpu.pc = 0xd3fe;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 20;
  m.cpu.pc = 0xd3fd;
  m.diagnostic_current_key.pc = 0xbd02;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 21;
  m.diagnostic_current_key.pc = 0xbd01;
  m.rom_identity_ok = 0;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 22;
  m.rom_identity_ok = 1;
  m.cpu.p = 0x20;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 23;
  m.cpu.p = 0;
  m.diagnostic_current_key.pc = 0xbba9;
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 29;
  m.cpu.pc = 0xd47b;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                 JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 30;
  m.cpu.pc = 0xd47c;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                 JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 31;
  m.cpu.pc = 0x8762;
  m.diagnostic_current_key.pc = 0xd484;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                 JS_STOP_UNPROVED_RETURN_CONTEXT) != JS_STOP_NONE)
    return 32;
  m.cpu.pc = 0xd318;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                 JS_STOP_UNPROVED_RETURN_CONTEXT) !=
      JS_STOP_UNPROVED_RETURN_CONTEXT)
    return 33;
  puts(
      "PASS damage return edges and adjacent target/source/mode/ROM rejection");
  m.cpu.p = 0;
  m.cpu.pc = 0xdbb5;
  m.diagnostic_current_key = (js_static_context_key){0x80, 0xdad7, 0, 0, 0};
  if (js_v05c_validate_current_key(
          &m, &allowed, 1, JS_STOP_UNPROVED_DYNAMIC_TARGET) != JS_STOP_NONE)
    return 24;
  m.cpu.pc = 0xdbb6;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 25;
  m.cpu.pc = 0xdbb5;
  m.diagnostic_current_key.pc = 0xdad6;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 26;
  m.diagnostic_current_key.pc = 0xdad7;
  m.cpu.p = 0x20;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 27;
  m.cpu.p = 0;
  m.rom_identity_ok = 0;
  if (js_v05c_validate_current_key(&m, &allowed, 1,
                                   JS_STOP_UNPROVED_DYNAMIC_TARGET) !=
      JS_STOP_UNPROVED_DYNAMIC_TARGET)
    return 28;
  puts("PASS frozen 16-word damage dispatch and adjacent "
       "target/source/mode/ROM rejection");
  return 0;
}
