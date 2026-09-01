#include "jungle/status_v10_30.h"
const char *js_stop_reason_name_v10_30(js_stop_reason reason) {
    switch ((int)reason) {
        case 5090: return "JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT";
        case 5091: return "JS_STOP_V10_30_RENDERER_SOURCE_CONFIG_MISMATCH";
        case 5092: return "JS_STOP_V10_30_RENDERER_WINDOWS_UNPROVED";
        case 5093: return "JS_STOP_V10_30_RENDERER_SETINI_UNPROVED";
        case 5094: return "JS_STOP_V10_30_RENDERER_OBJ_CONFIG_UNPROVED";
        default: return js_stop_reason_name_v10_29(reason);
    }
}
