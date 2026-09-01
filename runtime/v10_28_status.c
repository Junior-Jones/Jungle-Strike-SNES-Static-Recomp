#include "jungle/status_v10_28.h"

const char *js_stop_reason_name_v10_28(js_stop_reason reason) {
    switch ((int)reason) {
        case 5070:
            return "JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT";
        case 5071:
            return "JS_STOP_V10_28_RENDERER_UNSUPPORTED_FORMAT";
        default:
            return js_stop_reason_name_v10_11(reason);
    }
}
