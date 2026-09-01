#ifndef JUNGLE_STATUS_V09C_H
#define JUNGLE_STATUS_V09C_H

#include "jungle/status.h"

/* Version-owned fail-closed reasons.  Keeping these constants outside the frozen
   V06C/V08C status header preserves prior source and generated authority exactly. */
#define JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS ((js_stop_reason)5020)
#define JS_STOP_PPU_INVALID_REGISTER ((js_stop_reason)5021)
#define JS_STOP_PPU_UNINITIALIZED_MEMORY ((js_stop_reason)5022)

#endif
