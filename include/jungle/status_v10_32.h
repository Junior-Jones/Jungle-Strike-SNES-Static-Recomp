#ifndef JUNGLE_STATUS_V10_32_H
#define JUNGLE_STATUS_V10_32_H
#include "jungle/status_v10_31.h"
#define JS_STOP_V10_32_DSP_INVALID_ARGUMENT ((js_stop_reason)5100)
#define JS_STOP_V10_32_DSP_REGISTER_UNKNOWN ((js_stop_reason)5101)
#define JS_STOP_V10_32_DSP_ARAM_UNKNOWN ((js_stop_reason)5102)
#define JS_STOP_V10_32_DSP_SOURCE_DIRECTORY_UNKNOWN ((js_stop_reason)5103)
#define JS_STOP_V10_32_DSP_BRR_BLOCK_UNKNOWN ((js_stop_reason)5104)
#define JS_STOP_V10_32_DSP_ECHO_DEPENDENCY_UNKNOWN ((js_stop_reason)5105)
#define JS_STOP_V10_32_DSP_PCM_FIFO_OVERFLOW ((js_stop_reason)5106)
#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_32(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
