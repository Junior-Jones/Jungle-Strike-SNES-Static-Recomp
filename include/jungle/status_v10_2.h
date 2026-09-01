#ifndef JUNGLE_STATUS_V10_2_H
#define JUNGLE_STATUS_V10_2_H
#include "jungle/status_v10_1.h"
#define JS_STOP_V10_2_SMP_UNKNOWN_PC ((js_stop_reason)5040)
#define JS_STOP_V10_2_SMP_OPCODE_MISMATCH ((js_stop_reason)5041)
#define JS_STOP_V10_2_SMP_UNEMITTED_OPCODE ((js_stop_reason)5042)
#define JS_STOP_V10_2_SMP_CODE_WRITE ((js_stop_reason)5043)
#define JS_STOP_V10_2_ARAM_READ_UNKNOWN ((js_stop_reason)5044)
#define JS_STOP_V10_2_SMP_CODE_NOT_READY ((js_stop_reason)5045)
#define JS_STOP_V10_2_DSP_READ_UNKNOWN ((js_stop_reason)5046)
#define JS_STOP_V10_2_SMP_ALLOCATION ((js_stop_reason)5047)
#define JS_STOP_V10_2_COLD_CLOSURE_LIMIT ((js_stop_reason)5048)
const char *js_stop_reason_name_v10_2(js_stop_reason reason);
#endif
