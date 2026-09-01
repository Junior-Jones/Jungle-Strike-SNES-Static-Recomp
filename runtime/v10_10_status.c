#include "jungle/status_v10_10.h"
const char *js_stop_reason_name_v10_10(js_stop_reason reason) {
    if ((int)reason == 5050) return "JS_STOP_V10_10_NEXT_PERSISTENT_MENU_HANDOFF";
    if ((int)reason == 5051) return "JS_STOP_V10_10_POST_ACCEPT_CALLER_HANDOFF";
    return js_stop_reason_name_v10_9(reason);
}
