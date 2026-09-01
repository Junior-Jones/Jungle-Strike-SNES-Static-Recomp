#include "jungle/status_v10_40.h"
#include "jungle/status_v10_30.h"
const char *js_stop_reason_name_v10_40(js_stop_reason reason) {
    if (reason == JS_STOP_V10_40_INVALID_ARGUMENT) return "static core invalid argument";
    if (reason == JS_STOP_V10_40_ALLOCATION_FAILED) return "static core allocation failed";
    if (reason == JS_STOP_V10_40_FRAME_STEP_LIMIT) return "static core frame step limit";
    if (reason == JS_STOP_V10_40_RENDERER_UNAVAILABLE) return "static core renderer output unavailable";
    if (reason == JS_STOP_V10_40_DIAGNOSTIC_BUFFER_TOO_SMALL) return "static core diagnostic buffer too small";
    if (reason == JS_STOP_V10_40_ROM_INSPECTION_FAILED) return "static core ROM inspection failed";
    if ((unsigned)reason >= 5070u && (unsigned)reason <= 5094u) return js_stop_reason_name_v10_30(reason);
    return js_stop_reason_name_v10_33(reason);
}
