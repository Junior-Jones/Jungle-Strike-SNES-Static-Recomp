#include "jungle/status_v10_2.h"
const char *js_stop_reason_name_v10_2(js_stop_reason reason) {
    switch ((int)reason) {
      case 5040: return "JS_STOP_V10_2_SMP_UNKNOWN_PC";
      case 5041: return "JS_STOP_V10_2_SMP_OPCODE_MISMATCH";
      case 5042: return "JS_STOP_V10_2_SMP_UNEMITTED_OPCODE";
      case 5043: return "JS_STOP_V10_2_SMP_CODE_WRITE";
      case 5044: return "JS_STOP_V10_2_ARAM_READ_UNKNOWN";
      case 5045: return "JS_STOP_V10_2_SMP_CODE_NOT_READY";
      case 5046: return "JS_STOP_V10_2_DSP_READ_UNKNOWN";
      case 5047: return "JS_STOP_V10_2_SMP_ALLOCATION";
      case 5048: return "JS_STOP_V10_2_COLD_CLOSURE_LIMIT";
      default: return js_stop_reason_name_v10_1(reason);
    }
}
