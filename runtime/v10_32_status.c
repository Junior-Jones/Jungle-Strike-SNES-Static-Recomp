#include "jungle/status_v10_32.h"
const char *js_stop_reason_name_v10_32(js_stop_reason reason) {
    switch ((int)reason) {
        case 5100: return "JS_STOP_V10_32_DSP_INVALID_ARGUMENT";
        case 5101: return "JS_STOP_V10_32_DSP_REGISTER_UNKNOWN";
        case 5102: return "JS_STOP_V10_32_DSP_ARAM_UNKNOWN";
        case 5103: return "JS_STOP_V10_32_DSP_SOURCE_DIRECTORY_UNKNOWN";
        case 5104: return "JS_STOP_V10_32_DSP_BRR_BLOCK_UNKNOWN";
        case 5105: return "JS_STOP_V10_32_DSP_ECHO_DEPENDENCY_UNKNOWN";
        case 5106: return "JS_STOP_V10_32_DSP_PCM_FIFO_OVERFLOW";
        default: return js_stop_reason_name_v10_31(reason);
    }
}
