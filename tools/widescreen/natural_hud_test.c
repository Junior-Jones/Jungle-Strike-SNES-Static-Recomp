/* Replay inputs only; no writes to guest RAM, ROM, VRAM or OAM. */
#define main gameplay_verification_main
#include "verify.c"
#undef main
static unsigned hud_min_y, hud_max_y, hud_visible;
static void observe_hud(void *opaque, js_scheduler_ppu_event_kind_v09c kind) {
  JungleStaticCore *c = (JungleStaticCore *)opaque;
  js_core_ppu_event_v10_88(opaque, kind);
  if (kind == JS_SCHEDULER_PPU_EVENT_V09C_VISIBLE_SCANLINE &&
      c->render_output_enabled) {
    unsigned x, y = c->machine.scheduler.scanline;
    const js_ppu_v09c *p = &c->machine.ppu;
    if (y == 0) {
      hud_visible = 0;
      hud_min_y = 224;
      hud_max_y = 0;
    }
    if (y >= 224 || p->forced_blank || !(p->main_screen_layers & 4) ||
        !p->layer[0].large_tiles || !p->layer[1].large_tiles)
      return;
    for (x = 0; x < 256; x++) {
      js_bg_pixel_v10_29 bg;
      js_screen_pixel_v10_30 pixel;
      js_ppu_v09c copy;
      if (js_renderer_v10_29_sample_mode1_bg(p, 2, (uint16_t)x, (uint16_t)y,
                                             &bg) != JS_STOP_NONE ||
          bg.transparent)
        continue;
      copy = *p;
      if (js_renderer_v10_30_render_source_pixel(
              &copy, (uint16_t)x, (uint16_t)y, &pixel) == JS_STOP_NONE &&
          pixel.main_pixel.source == JS_PIXEL_V10_30_BG3) {
        hud_visible++;
        if (y < hud_min_y)
          hud_min_y = y;
        if (y > hud_max_y)
          hud_max_y = y;
      }
    }
  }
}
int main(int argc, char **argv) {
  FILE *f;
  uint8_t *rom;
  void *initial, *before, *a, *b;
  size_t size;
  JungleStaticCore *c, *native;
  JungleCoreAudio audio;
  unsigned frame, x, y, visible;
  char path[2048];
  if (argc != 4)
    return 2;
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  f = fopen(argv[1], "rb");
  if (!f || !rom ||
      fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
          JUNGLE_STATIC_CORE_ROM_SIZE)
    return 2;
  fclose(f);
  c = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  native = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!c || !native)
    return 2;
  size = jungle_core_snapshot_size(c);
  initial = malloc(size);
  before = malloc(size);
  a = malloc(size);
  b = malloc(size);
  f = fopen(argv[2], "rb");
  if (!f || !initial || !before || !a || !b ||
      fread(initial, 1, size, f) != size)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(c, initial, size) ||
      !jungle_core_set_widescreen(c, 1))
    return 2;
  c->machine.scheduler.hooks.ppu_event = observe_hud;
  output_directory = argv[3];
  for (frame = 0; frame < 60000; frame++) {
    uint16_t input = frame < 180 ? JUNGLE_BUTTON_UP : 0;
    int render = (frame % 16u) == 0u;
    if (render && !jungle_core_save_snapshot(c, before, size))
      return 2;
    if (!(render ? jungle_core_run_frame(c, input, 0)
                 : jungle_core_run_frame_headless(c, input, 0))) {
      printf("FAIL frame=%u machine=%u renderer=%u\n", frame, c->machine_stop,
             c->renderer_stop);
      return 1;
    }
    jungle_core_take_audio(c, &audio);
    if (!render)
      continue;
    visible = 0;
    for (y = 0; y < 12; y++)
      for (x = 0; x < 256; x++)
        if (c->wide->hud_mask[y * 256 + x] &&
            (c->wide->hud_pixels[y * 256 + x] & 0xffffffu))
          visible++;
    if (frame % 1600 == 0) {
      printf("SEARCH frame=%u hud=%u camera=%u,%u\n", frame, visible,
             (unsigned)(c->machine.bus.base.wram[0x40] |
                        c->machine.bus.base.wram[0x41] << 8),
             (unsigned)(c->machine.bus.base.wram[0x42] |
                        c->machine.bus.base.wram[0x43] << 8));
      fflush(stdout);
    }
    if (hud_visible && c->wide->active) {
      printf(
          "ACTUAL HUD bounds y=%u..%u source_pixels=%u bottom_mask_pixels=%u\n",
          hud_min_y, hud_max_y, hud_visible, visible);
      if (!jungle_core_load_snapshot(native, before, size) ||
          !jungle_core_run_frame(native, input, 0))
        return 1;
      jungle_core_take_audio(native, &audio);
      snprintf(path, sizeof(path), "%s/actual-native.ppm", argv[3]);
      if (!write_frame(native, path))
        return 2;
      snprintf(path, sizeof(path), "%s/actual-wide.ppm", argv[3]);
      if (!write_frame(c, path))
        return 2;
      if (!compare_frame(native, c) ||
          !jungle_core_save_snapshot(native, a, size) ||
          !jungle_core_save_snapshot(c, b, size) || memcmp(a, b, size))
        return 1;
      snprintf(path, sizeof(path), "%s/real-hud.snapshot", argv[3]);
      f = fopen(path, "wb");
      if (!f || fwrite(b, 1, size, f) != size)
        return 2;
      fclose(f);
      printf("PASS natural gameplay HUD frame=%u visible=%u native/wide guest "
             "state identical\n",
             frame, visible);
      {
        unsigned follow, warning_frames = 0;
        for (follow = 0; follow < 240; follow++) {
          if (!jungle_core_run_frame(native, 0, 0) ||
              !jungle_core_run_frame(c, 0, 0))
            return 1;
          jungle_core_take_audio(native, &audio);
          jungle_core_take_audio(c, &audio);
          if (!compare_frame(native, c))
            return 1;
          if (hud_visible) {
            if (hud_min_y < 208 || hud_max_y >= 220)
              return 1;
            warning_frames++;
          }
          if (follow % 16u == 0u &&
              (!jungle_core_save_snapshot(native, a, size) ||
               !jungle_core_save_snapshot(c, b, size) || memcmp(a, b, size)))
            return 1;
        }
        if (!warning_frames)
          return 1;
        printf("PASS real warning continuation: 240 frames, %u with visible "
               "HUD, every native crop and relocated HUD pixel identical; "
               "sampled guest snapshots identical\n",
               warning_frames);
      }
      free(initial);
      free(before);
      free(a);
      free(b);
      jungle_core_destroy(native);
      jungle_core_destroy(c);
      return 0;
    }
  }
  puts("FAIL no natural HUD reached in route");
  return 1;
}
