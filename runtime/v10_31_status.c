#include "jungle/status_v10_31.h"
const char *js_stop_reason_name_v10_31(js_stop_reason reason) {
    switch ((int)reason) {
        case 5095: return "JS_STOP_V10_31_DSP_INVALID_ARGUMENT";
        case 5096: return "JS_STOP_V10_31_DSP_REGISTER_UNKNOWN";
        case 5097: return "JS_STOP_V10_31_DSP_ARAM_UNKNOWN";
        case 5098: return "JS_STOP_V10_31_DSP_SOURCE_DIRECTORY_UNKNOWN";
        case 5099: return "JS_STOP_V10_31_DSP_BRR_BLOCK_UNKNOWN";
        default: return js_stop_reason_name_v10_30(reason);
    }
}
