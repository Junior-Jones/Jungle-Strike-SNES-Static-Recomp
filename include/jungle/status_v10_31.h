#ifndef JUNGLE_STATUS_V10_31_H
#define JUNGLE_STATUS_V10_31_H
#include "jungle/status_v10_30.h"
#define JS_STOP_V10_31_DSP_INVALID_ARGUMENT ((js_stop_reason)5095)
#define JS_STOP_V10_31_DSP_REGISTER_UNKNOWN ((js_stop_reason)5096)
#define JS_STOP_V10_31_DSP_ARAM_UNKNOWN ((js_stop_reason)5097)
#define JS_STOP_V10_31_DSP_SOURCE_DIRECTORY_UNKNOWN ((js_stop_reason)5098)
#define JS_STOP_V10_31_DSP_BRR_BLOCK_UNKNOWN ((js_stop_reason)5099)
#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_31(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
