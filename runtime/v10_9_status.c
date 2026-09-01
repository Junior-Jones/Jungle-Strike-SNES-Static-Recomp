#include "jungle/status_v10_9.h"
const char *js_stop_reason_name_v10_9(js_stop_reason reason) {
    if ((int)reason == 5049) return "JS_STOP_V10_9_PERSISTENT_RUNTIME_HANDOFF";
    return js_stop_reason_name_v10_2(reason);
}
