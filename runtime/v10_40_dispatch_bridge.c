#include "jungle/cpu_dispatch_v10_100.h"
#include "jungle/cpu_v08c_internal.h"
#include "jungle/status_closure.h"
int js_compact_base_context_known(js_static_context_key key);
js_stop_reason js_compact_base_dispatch(js_machine_v05c *m,
                                        js_static_context_key key);
int js_v10_100_scpu_context_known(js_static_context_key key) {
  return jungle_status_context_known(key) || js_compact_base_context_known(key);
}
js_stop_reason js_static_dispatch_v10_100(js_machine_v05c *m,
                                          js_static_context_key key) {
  js_stop_reason out;
  if (jungle_status_dispatch(m, key, &out))
    return out;
  return js_compact_base_dispatch(m, key);
}
js_stop_reason js_static_step_v10_100(js_machine_v05c *m) {
  js_static_context_key key;
  if (!m->rom_identity_ok)
    return JS_STOP_WRONG_ROM;
  key = js_v05c_key_from_cpu(&m->cpu);
  if ((key.e && (!key.m || !key.x)) || key.e > 1u || key.m > 1u || key.x > 1u)
    return JS_STOP_INVALID_CPU_CONTEXT;
  return js_static_dispatch_v10_100(m, key);
}
/* Current-only compatibility seam required by mature shared CPU helpers. */
int js_v05c_context_known(js_static_context_key key) {
  return js_v10_100_scpu_context_known(key);
}
js_stop_reason js_static_dispatch_v05c(js_machine_v05c *m,
                                       js_static_context_key key) {
  return js_static_dispatch_v10_100(m, key);
}
