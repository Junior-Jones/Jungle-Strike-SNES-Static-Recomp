#ifndef JUNGLE_CPU_DISPATCH_V10_93_H
#define JUNGLE_CPU_DISPATCH_V10_93_H

#include "jungle/cpu_v08c_internal.h"

int js_v10_93_scpu_context_known(js_static_context_key key);
js_stop_reason js_static_dispatch_v10_93(js_machine_v05c *machine,
                                         js_static_context_key key);
js_stop_reason js_static_step_v10_93(js_machine_v05c *machine);

#endif
