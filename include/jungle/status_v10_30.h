#ifndef JUNGLE_STATUS_V10_30_H
#define JUNGLE_STATUS_V10_30_H
#include "jungle/status_v10_29.h"
#define JS_STOP_V10_30_RENDERER_INVALID_ARGUMENT ((js_stop_reason)5090)
#define JS_STOP_V10_30_RENDERER_SOURCE_CONFIG_MISMATCH ((js_stop_reason)5091)
#define JS_STOP_V10_30_RENDERER_WINDOWS_UNPROVED ((js_stop_reason)5092)
#define JS_STOP_V10_30_RENDERER_SETINI_UNPROVED ((js_stop_reason)5093)
#define JS_STOP_V10_30_RENDERER_OBJ_CONFIG_UNPROVED ((js_stop_reason)5094)
#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_30(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
