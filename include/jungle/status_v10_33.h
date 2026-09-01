#ifndef JUNGLE_STATUS_V10_33_H
#define JUNGLE_STATUS_V10_33_H
#include "jungle/status_v10_32.h"
#define JS_STOP_V10_33_DSP_INVALID_ARGUMENT ((js_stop_reason)5200)
#define JS_STOP_V10_33_DSP_REGISTER_UNKNOWN ((js_stop_reason)5201)
#define JS_STOP_V10_33_DSP_ARAM_REQUIRED_UNKNOWN ((js_stop_reason)5202)
#define JS_STOP_V10_33_DSP_PCM_FIFO_OVERFLOW ((js_stop_reason)5203)
#define JS_STOP_V10_33_DSP_PHASE_INVARIANT ((js_stop_reason)5204)
#ifdef __cplusplus
extern "C" {
#endif
const char *js_stop_reason_name_v10_33(js_stop_reason reason);
#ifdef __cplusplus
}
#endif
#endif
