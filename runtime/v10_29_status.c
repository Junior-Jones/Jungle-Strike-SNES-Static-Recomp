#include "jungle/status_v10_29.h"

const char *js_stop_reason_name_v10_29(js_stop_reason reason) {
    switch ((int)reason) {
        case 5080: return "JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT";
        case 5081: return "JS_STOP_V10_29_RENDERER_UNSUPPORTED_MODE";
        case 5082: return "JS_STOP_V10_29_RENDERER_INACTIVE_LAYER";
        case 5083: return "JS_STOP_V10_29_RENDERER_MOSAIC_UNPROVED";
        case 5084: return "JS_STOP_V10_29_RENDERER_SOURCE_CONFIG_MISMATCH";
        default: return js_stop_reason_name_v10_28(reason);
    }
}
