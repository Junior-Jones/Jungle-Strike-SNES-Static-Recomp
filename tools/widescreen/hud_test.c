/* Host-only message-layer fixture. Does not modify the running guest. */
#define main gameplay_verification_main
#include "verify.c"
#undef main
int main(int argc, char **argv) {
  FILE *f;
  uint8_t *rom;
  void *snapshot;
  JungleStaticCore *c;
  js_machine_v10_40 *host;
  JungleWideState *baseline;
  unsigned x, y, moved = 0, clear = 0;
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
  free(rom);
  if (!c)
    return 2;
  snapshot = malloc(jungle_core_snapshot_size(c));
  f = fopen(argv[2], "rb");
  if (!f || !snapshot ||
      fread(snapshot, 1, jungle_core_snapshot_size(c), f) !=
          jungle_core_snapshot_size(c))
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(c, snapshot, jungle_core_snapshot_size(c)) ||
      !jungle_core_set_widescreen(c, 1) || !jungle_core_run_frame(c, 0, 0))
    return 1;
  host = malloc(sizeof(*host));
  baseline = calloc(1, sizeof(*baseline));
  if (!host || !baseline)
    return 2;
  *host = c->machine;
  host->ppu = c->wide->edge_ppu;
  host->ppu.forced_blank = 0;
  host->ppu.brightness = 15;
  /* Isolated VRAM tilemap/character fixture: alternating opaque and transparent
     pixels, high-priority BG3. Geometry and world state remain from gameplay.
   */
  host->ppu.layer[2].tilemap_address = 0x7000;
  host->ppu.layer[2].chr_address = 0x7800;
  host->ppu.layer[2].h_scroll = host->ppu.layer[2].v_scroll = 0;
  host->ppu.layer[2].double_width = host->ppu.layer[2].double_height = 0;
  memset(host->ppu.vram + 0x7000, 0, 2048);
  memset(host->ppu.vram + 0x7800, 0, 32);
  memset(host->ppu.vram_known + 0xe000 / 8, 0xff, 2048 / 8);
  memset(host->ppu.vram_known + 0xf000 / 8, 0xff, 64 / 8);
  for (y = 0; y < 8; y++)
    host->ppu.vram[0x7808 + y] = (y & 1) ? 0x55 : 0xaa;
  for (y = 26; y <= 27; y++)
    for (x = 8; x < 24; x++)
      host->ppu.vram[0x7000 + y * 32 + x] = 0x2001;
  host->ppu.cgram[1] = 0x03ff;
  host->ppu.cgram_known[0] |= 12;
  baseline->enabled = 1;
  jungle_wide_invalidate(c->wide);
  for (y = 0; y < 224; y++) {
    js_rgb8_v10_28 line[256], world[256];
    host->ppu.main_screen_layers = 19;
    host->ppu.forced_blank = (y >= 220);
    if (js_renderer_v10_30_render_source_scanline(&host->ppu, (uint16_t)y,
                                                  world) != JS_STOP_NONE)
      return 1;
    if (jungle_wide_scanline(baseline, host, c->rom, c->rom_size, y, world) !=
        JS_STOP_NONE)
      return 1;
    if (y >= 208 && y < 220)
      host->ppu.main_screen_layers |= 4;
    if (js_renderer_v10_30_render_source_scanline(&host->ppu, (uint16_t)y,
                                                  line) != JS_STOP_NONE)
      return 1;
    for (x = 0; x < 256; x++)
      c->frame_bgra[y * 256 + x] = 0xff000000u | ((uint32_t)line[x].r << 16) |
                                   ((uint32_t)line[x].g << 8) | line[x].b;
    if (jungle_wide_scanline(c->wide, host, c->rom, c->rom_size, y, line) !=
        JS_STOP_NONE)
      return 1;
  }
  for (y = 208; y < 220; y++)
    for (x = 0; x < 256; x++) {
      unsigned old = (y + 32) * JUNGLE_WIDE_WIDTH + x + JUNGLE_WIDE_MARGIN, dest = (y + 64) * JUNGLE_WIDE_WIDTH + x + JUNGLE_WIDE_MARGIN;
      if (c->wide->hud_mask[(y - 208) * 256 + x]) {
        if (c->wide->pixels[dest] != c->frame_bgra[y * 256 + x] ||
            c->wide->pixels[old] != baseline->pixels[old])
          return 1;
        moved++;
      } else {
        if (c->wide->pixels[old] != baseline->pixels[old])
          return 1;
        clear++;
      }
    }
  if (!moved || !clear)
    return 1;
  snprintf(path, sizeof(path), "%s/hud-fixture-wide.ppm", argv[3]);
  if (!write_frame(c, path))
    return 2;
  c->wide->enabled = 0;
  snprintf(path, sizeof(path), "%s/hud-fixture-native.ppm", argv[3]);
  if (!write_frame(c, path))
    return 2;
  printf("PASS host-only HUD fixture: %u opaque pixels relocated 208..219 -> "
         "272..283; %u transparent pixels and underlying world preserved\n",
         moved, clear);
  free(baseline);
  free(host);
  free(snapshot);
  jungle_core_destroy(c);
  return 0;
}
