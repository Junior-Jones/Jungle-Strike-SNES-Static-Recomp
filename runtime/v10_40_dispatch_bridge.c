#include "jungle/cpu_dispatch_v10_100.h"
/* Current-only compatibility seam required by mature shared CPU helpers. */
int js_v05c_context_known(js_static_context_key key) { return js_v10_100_scpu_context_known(key); }
js_stop_reason js_static_dispatch_v05c(js_machine_v05c *m, js_static_context_key key) { return js_static_dispatch_v10_100(m,key); }
