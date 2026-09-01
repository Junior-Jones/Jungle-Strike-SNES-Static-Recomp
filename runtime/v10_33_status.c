#include "jungle/status_v10_33.h"
const char *js_stop_reason_name_v10_33(js_stop_reason reason) {
    if (reason == JS_STOP_V10_33_DSP_INVALID_ARGUMENT) return "S-DSP invalid argument";
    if (reason == JS_STOP_V10_33_DSP_REGISTER_UNKNOWN) return "S-DSP register unknown";
    if (reason == JS_STOP_V10_33_DSP_ARAM_REQUIRED_UNKNOWN) return "S-DSP required ARAM dependency unknown";
    if (reason == JS_STOP_V10_33_DSP_PCM_FIFO_OVERFLOW) return "S-DSP PCM FIFO overflow";
    if (reason == JS_STOP_V10_33_DSP_PHASE_INVARIANT) return "S-DSP phase invariant failure";
    return js_stop_reason_name_v10_32(reason);
}
