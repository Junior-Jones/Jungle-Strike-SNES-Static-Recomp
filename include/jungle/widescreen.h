#ifndef JUNGLE_WIDESCREEN_H
#define JUNGLE_WIDESCREEN_H
#include "jungle/machine_v10_40.h"
#include "jungle/renderer_v10_28.h"
#define JUNGLE_WIDE_WIDTH 512u
#define JUNGLE_WIDE_HEIGHT 288u
_Static_assert(JUNGLE_WIDE_WIDTH * 9u == JUNGLE_WIDE_HEIGHT * 16u, "Widescreen must be 16:9");
#define JUNGLE_WIDE_MARGIN_Y 32u
#define JUNGLE_WIDE_MARGIN 128u
#define JUNGLE_WIDE_HUD_TOP 208u
#define JUNGLE_WIDE_HUD_HEIGHT 16u
typedef struct JungleWideState {
  int enabled, valid, active, work_active, console;
  int view_shift_x, view_shift_y, render_shift_x, render_shift_y;
  unsigned clip_left, clip_right;
  unsigned work_scanlines;
  js_ppu_v09c edge_ppu;
  uint32_t pixels[JUNGLE_WIDE_WIDTH * JUNGLE_WIDE_HEIGHT];
  uint32_t work[JUNGLE_WIDE_WIDTH * JUNGLE_WIDE_HEIGHT];
  uint32_t hud_pixels[JUNGLE_WIDE_HUD_HEIGHT * 256u];
  uint8_t hud_mask[JUNGLE_WIDE_HUD_HEIGHT * 256u];
  uint32_t work_hud_pixels[JUNGLE_WIDE_HUD_HEIGHT * 256u];
  uint8_t work_hud_mask[JUNGLE_WIDE_HUD_HEIGHT * 256u];
  uint8_t pixel_object[JUNGLE_WIDE_WIDTH * JUNGLE_WIDE_HEIGHT];
  uint32_t edge_sprite_pixels[128][4];
  int16_t sprite_x[128], sprite_y[128];
  uint8_t sprite_seen[128];
  uint16_t columns[64][260];
  int column_key[64];
  uint8_t column_valid[64];
  uint8_t map_bank;
  uint16_t map_base;
  int foreground_x, foreground_y, foreground_ready;
  uint64_t foreground_hash;
} JungleWideState;
void jungle_wide_invalidate(JungleWideState *wide);
void jungle_wide_console(JungleWideState *wide,
                         const js_machine_v10_40 *machine,
                         const uint32_t native[256u * 224u]);
js_stop_reason jungle_wide_scanline(JungleWideState *wide,
                                    const js_machine_v10_40 *machine,
                                    const uint8_t *rom, size_t rom_size,
                                    unsigned y,
                                    const js_rgb8_v10_28 native[256]);
#endif
