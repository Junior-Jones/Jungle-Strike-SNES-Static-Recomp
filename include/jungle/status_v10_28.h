#ifndef JUNGLE_STATUS_V10_28_H
#define JUNGLE_STATUS_V10_28_H

#include "jungle/status_v10_11.h"

#define JS_STOP_V10_28_RENDERER_INVALID_ARGUMENT ((js_stop_reason)5070)
#define JS_STOP_V10_28_RENDERER_UNSUPPORTED_FORMAT ((js_stop_reason)5071)

#ifdef __cplusplus
extern "C" {
#endif

const char *js_stop_reason_name_v10_28(js_stop_reason reason);

#ifdef __cplusplus
}
#endif
#endif
