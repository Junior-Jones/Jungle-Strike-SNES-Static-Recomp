#include "jungle/status_v10_11.h"
const char *js_stop_reason_name_v10_11(js_stop_reason reason) {
    if ((int)reason == 5060) return "JS_STOP_V10_11_THIRD_ENGINE_CALL_HANDOFF";
    if ((int)reason == 5061) return "JS_STOP_V10_11_ALTERNATE_ENGINE_CALL_HANDOFF";
    return js_stop_reason_name_v10_10(reason);
}
