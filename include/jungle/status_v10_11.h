#ifndef JUNGLE_STATUS_V10_11_H
#define JUNGLE_STATUS_V10_11_H
#include "jungle/status_v10_10.h"
#define JS_STOP_V10_11_THIRD_ENGINE_CALL_HANDOFF ((js_stop_reason)5060)
#define JS_STOP_V10_11_ALTERNATE_ENGINE_CALL_HANDOFF ((js_stop_reason)5061)
const char *js_stop_reason_name_v10_11(js_stop_reason reason);
#endif
