#ifndef JUNGLE_STATUS_V10_1_H
#define JUNGLE_STATUS_V10_1_H

#include "jungle/status_v09c.h"

/* Keep Version 01C-09C status authority byte-for-byte frozen.  Version 10.x
   owns its new fail-closed reasons in this additive layer. */
#define JS_STOP_V10_1_UNPROVED_WRAM_VECTOR ((js_stop_reason)5030)
#define JS_STOP_V10_1_COLD_CLOSURE_LIMIT ((js_stop_reason)5031)
#define JS_STOP_V10_1_SMP_AOT_REQUIRED ((js_stop_reason)5032)
#define JS_STOP_V10_1_IPL_PROTOCOL_ERROR ((js_stop_reason)5033)

const char *js_stop_reason_name_v10_1(js_stop_reason reason);

#endif
