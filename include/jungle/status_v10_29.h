#ifndef JUNGLE_STATUS_V10_29_H
#define JUNGLE_STATUS_V10_29_H

#include "jungle/status_v10_28.h"

#define JS_STOP_V10_29_RENDERER_INVALID_ARGUMENT ((js_stop_reason)5080)
#define JS_STOP_V10_29_RENDERER_UNSUPPORTED_MODE ((js_stop_reason)5081)
#define JS_STOP_V10_29_RENDERER_INACTIVE_LAYER ((js_stop_reason)5082)
#define JS_STOP_V10_29_RENDERER_MOSAIC_UNPROVED ((js_stop_reason)5083)
#define JS_STOP_V10_29_RENDERER_SOURCE_CONFIG_MISMATCH ((js_stop_reason)5084)

#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_29(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
