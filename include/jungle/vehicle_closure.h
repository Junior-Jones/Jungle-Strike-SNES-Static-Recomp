#ifndef JUNGLE_VEHICLE_CLOSURE_H
#define JUNGLE_VEHICLE_CLOSURE_H
#include "jungle/cpu_dispatch_v10_100.h"
int jungle_vehicle_context_known(js_static_context_key key);
int jungle_vehicle_dispatch(js_machine_v05c *m, js_static_context_key key, js_stop_reason *out);
int jungle_vehicle_return_allowed(js_static_context_key from, js_static_context_key to);
int jungle_vehicle_indirect_allowed(js_static_context_key from, js_static_context_key to);
#endif
