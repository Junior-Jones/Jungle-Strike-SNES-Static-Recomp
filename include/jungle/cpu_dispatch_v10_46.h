#ifndef JUNGLE_CPU_DISPATCH_V10_46_H
#define JUNGLE_CPU_DISPATCH_V10_46_H
#include "jungle/cpu_dispatch_v08c.h"
#include "jungle/status_v10_11.h"
#ifdef __cplusplus
extern "C" {
#endif
int js_v10_46_scpu_context_known(js_static_context_key key);
js_stop_reason js_static_dispatch_v10_46(js_machine_v05c *machine, js_static_context_key key);
js_stop_reason js_static_step_v10_46(js_machine_v05c *machine);
#ifdef __cplusplus
}
#endif
#endif
