#ifndef JUNGLE_STATUS_V10_40_H
#define JUNGLE_STATUS_V10_40_H
#include "jungle/status_v10_33.h"
#define JS_STOP_V10_40_INVALID_ARGUMENT ((js_stop_reason)5300)
#define JS_STOP_V10_40_ALLOCATION_FAILED ((js_stop_reason)5301)
#define JS_STOP_V10_40_FRAME_STEP_LIMIT ((js_stop_reason)5302)
#define JS_STOP_V10_40_RENDERER_UNAVAILABLE ((js_stop_reason)5303)
#define JS_STOP_V10_40_DIAGNOSTIC_BUFFER_TOO_SMALL ((js_stop_reason)5304)
#define JS_STOP_V10_40_ROM_INSPECTION_FAILED ((js_stop_reason)5305)
#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_40(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
