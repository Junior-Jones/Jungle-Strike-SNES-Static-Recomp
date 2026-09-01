#ifndef JUNGLE_STATUS_V10_10_H
#define JUNGLE_STATUS_V10_10_H
#include "jungle/status_v10_9.h"
#define JS_STOP_V10_10_NEXT_PERSISTENT_MENU_HANDOFF ((js_stop_reason)5050)
#define JS_STOP_V10_10_POST_ACCEPT_CALLER_HANDOFF ((js_stop_reason)5051)
const char *js_stop_reason_name_v10_10(js_stop_reason reason);
#endif
