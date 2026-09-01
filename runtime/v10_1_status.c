#include "jungle/status_v10_1.h"

const char *js_stop_reason_name_v10_1(js_stop_reason reason) {
    switch ((int)reason) {
        case 5030: return "JS_STOP_V10_1_UNPROVED_WRAM_VECTOR";
        case 5031: return "JS_STOP_V10_1_COLD_CLOSURE_LIMIT";
        case 5032: return "JS_STOP_V10_1_SMP_AOT_REQUIRED";
        case 5033: return "JS_STOP_V10_1_IPL_PROTOCOL_ERROR";
        default: return js_stop_reason_name(reason);
    }
}
