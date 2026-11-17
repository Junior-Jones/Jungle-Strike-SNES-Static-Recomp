#ifndef JUNGLE_GAMEPLAY_WATER_60_H
#define JUNGLE_GAMEPLAY_WATER_60_H
#include "jungle/machine_v10_40.h"
#include "jungle/renderer_v10_28.h"
struct js_screen_pixel_v10_30;
/* Derived once at visible line zero, then immutable for that entire frame.
   No guest state or presentation history is stored in this value. */
typedef struct JungleWater60Palette {
    uint16_t current_bgr555[5],next_bgr555[5];
    js_rgb8_v10_28 rgb8[5];
    uint8_t phase;
    uint16_t source_offset;
} JungleWater60Palette;
int jungle_gameplay_water60_palette(const js_machine_v10_40 *machine,
                                    JungleWater60Palette *out);
void jungle_gameplay_water60_shade(const JungleWater60Palette *palette,
                                   const js_ppu_v09c *ppu,
                                   const struct js_screen_pixel_v10_30 *pixel,
                                   js_rgb8_v10_28 *out);
#endif
