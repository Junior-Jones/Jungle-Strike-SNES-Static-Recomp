#ifndef JUNGLE_END_CLOSURE_H
#define JUNGLE_END_CLOSURE_H
#include "jungle/cpu_dispatch_v10_100.h"
int jungle_end_context_known(js_static_context_key key);
int jungle_end_dispatch(js_machine_v05c *m,js_static_context_key key,js_stop_reason *out);
int jungle_end_return_allowed(js_static_context_key from,js_static_context_key to);
#endif
