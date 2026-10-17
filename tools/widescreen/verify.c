/* Headless integration evidence: uses the production core, with private access
   only to record OAM/camera coverage. Never linked into Launcher.exe. */
#include "../../runtime/v10_40_core_api.c"
static int write_frame(JungleStaticCore *c, const char *path) {
  JungleCoreFrame frame;
  unsigned x, y;
  FILE *f;
  if (!jungle_core_get_frame(c, &frame))
    return 0;
  f = fopen(path, "wb");
  if (!f)
    return 0;
  fprintf(f, "P6\n%u %u\n255\n", frame.width, frame.height);
  for (y = 0; y < frame.height; y++)
    for (x = 0; x < frame.width; x++) {
      uint32_t p = frame.bgra_pixels[y * frame.width + x];
      uint8_t rgb[3] = {(uint8_t)(p >> 16), (uint8_t)(p >> 8), (uint8_t)p};
      if (fwrite(rgb, 1, 3, f) != 3) {
        fclose(f);
        return 0;
      }
    }
  return fclose(f) == 0;
}
static unsigned edge_samples[4], weapon_edges[4], hud_frames;
static const char *output_directory;
/* Pixel-preservation contract for all 256x200 original console pixels.
   Text, numbers, map, score and controls each retain their exact source size.
 */
static int compare_console_frame(const JungleCoreFrame *n,
                                 const JungleCoreFrame *v) {
  enum { main_width = JUNGLE_WIDE_WIDTH - 48u };
  static const unsigned rectangles[][6] = {
      {0, 16, 32, 24, 0, 0},
      {32, 16, 144, 24, (main_width - 144) / 2, 0},
      {176, 16, 32, 24, main_width - 32, 0},
      {0, 40, 208, 144, (main_width - 208) / 2, 68},
      {0, 184, 200, 16, 0, 256},
      {200, 184, 8, 16, main_width - 8, 256},
      {0, 200, 64, 16, 0, 272},
      {64, 200, 64, 16, (main_width - 64) / 2, 272},
      {128, 200, 64, 16, main_width - 80, 272},
      {192, 200, 16, 16, main_width - 16, 272},
      {208, 16, 48, 24, main_width, 0},
      {208, 40, 48, 24, main_width, 36},
      {208, 64, 48, 24, main_width, 72},
      {208, 88, 48, 24, main_width, 108},
      {208, 112, 48, 24, main_width, 144},
      {208, 136, 48, 24, main_width, 180},
      {208, 160, 48, 24, main_width, 216},
      {208, 184, 48, 32, main_width, 256}};
  unsigned i, x, y;
  if (n->width != 256u || n->height != 224u || v->width != JUNGLE_WIDE_WIDTH ||
      v->height != 288u)
    return 0;
  for (i = 0; i < sizeof(rectangles) / sizeof(rectangles[0]); i++) {
    const unsigned *r = rectangles[i];
    for (y = 0; y < r[3]; y++)
      for (x = 0; x < r[2]; x++)
        if (n->bgra_pixels[(r[1] + y) * 256u + r[0] + x] !=
            v->bgra_pixels[(r[5] + y) * JUNGLE_WIDE_WIDTH + r[4] + x]) {
          printf("CONSOLE mismatch region=%u source=%u,%u output=%u,%u\n", i,
                 r[0] + x, r[1] + y, r[4] + x, r[5] + y);
          return 0;
        }
  }
  /* Added statistic spacers must not contain duplicated bright digit/text
     pixels. Original blank grid and chassis colors stay below this level. */
  for (i = 0; i < 6; i++)
    for (y = 24u + i * 36u; y < 36u + i * 36u; y++)
      for (x = main_width; x < JUNGLE_WIDE_WIDTH; x++) {
        uint32_t pixel = v->bgra_pixels[y * JUNGLE_WIDE_WIDTH + x];
        if (((pixel >> 8u) & 255u) > 160u ||
            ((pixel >> 16u) & 255u) > 160u) {
          printf("CONSOLE text leaked into spacer=%u at %u,%u\n", i, x, y);
          return 0;
        }
      }
  return 1;
}
static int compare_frame(JungleStaticCore *native, JungleStaticCore *wide) {
  JungleCoreFrame n, v;
  unsigned x, y, hud = 0;
  if (!jungle_core_get_frame(native, &n) || !jungle_core_get_frame(wide, &v))
    return 0;
  if (wide->wide && wide->wide->console)
    return compare_console_frame(&n, &v);
  if (v.width == 256u)
    return v.height == 224u &&
           !memcmp(n.bgra_pixels, v.bgra_pixels, 256u * 224u * 4u);
  if (v.width != JUNGLE_WIDE_WIDTH || v.height != 288u)
    return 0;
  for (y = 0; y < 220u; y++)
    for (x = 0; x < 256u; x++) {
      int vx = (int)x + (int)JUNGLE_WIDE_MARGIN - wide->wide->view_shift_x;
      int vy = (int)y + 32 - wide->wide->view_shift_y;
      if (y >= 208u && wide->wide->hud_mask[(y - 208u) * 256u + x])
        continue;
      if (vy >= 272 && vy < 288 && vx >= (int)JUNGLE_WIDE_MARGIN &&
          vx < (int)JUNGLE_WIDE_MARGIN + 256 &&
          wide->wide->hud_mask[(vy - 272) * 256 + vx - JUNGLE_WIDE_MARGIN])
        continue;
      if (n.bgra_pixels[y * 256u + x] !=
          v.bgra_pixels[(y + 32u - wide->wide->view_shift_y) *
                            JUNGLE_WIDE_WIDTH +
                        x + JUNGLE_WIDE_MARGIN - wide->wide->view_shift_x]) {
        printf("CROP mismatch native=%u,%u output=%d,%d shift=%d,%d want=%08X "
               "got=%08X\n",
               x, y, vx, vy, wide->wide->view_shift_x, wide->wide->view_shift_y,
               n.bgra_pixels[y * 256u + x],
               v.bgra_pixels[vy * JUNGLE_WIDE_WIDTH + vx]);
        return 0;
      }
    }
  for (y = 0; y < 16u; y++)
    for (x = 0; x < 256u; x++)
      if (wide->wide->hud_mask[y * 256u + x]) {
        if (v.bgra_pixels[(272u + y) * JUNGLE_WIDE_WIDTH + x +
                          JUNGLE_WIDE_MARGIN] !=
            wide->wide->hud_pixels[y * 256u + x])
          return 0;
        if (y < 12u && (wide->wide->hud_pixels[y * 256u + x] & 0xffffffu))
          hud++;
      }
  if (hud) {
    if (!hud_frames) {
      char path[2048];
      snprintf(path, sizeof(path), "%s/hud-native.ppm", output_directory);
      if (!write_frame(native, path))
        return 0;
      snprintf(path, sizeof(path), "%s/hud-wide.ppm", output_directory);
      if (!write_frame(wide, path))
        return 0;
      printf("HUD relocated: native y=208..219 -> expanded y=272..283, visible "
             "pixels=%u\n",
             hud);
    }
    hud_frames++;
  }
  return 1;
}
static int capture_edges(JungleStaticCore *native, JungleStaticCore *wide,
                         const char *directory, unsigned heading) {
  unsigned i, e;
  const js_ppu_v09c *p = &wide->wide->edge_ppu;
  char path[2048];
  for (i = 0; i < 128u; i++) {
    js_obj_record_v10_28 obj;
    int x, y;
    unsigned mask = 0;
    if (!wide->wide->sprite_seen[i] ||
        js_renderer_v10_28_decode_obj(p, (uint8_t)i, &obj) != JS_STOP_NONE)
      continue;
    x = wide->wide->sprite_x[i];
    y = wide->wide->sprite_y[i];
    if (x >= 256 + (int)JUNGLE_WIDE_MARGIN ||
        x + obj.size.width <= -(int)JUNGLE_WIDE_MARGIN || y >= 256 ||
        y + obj.size.height <= -32)
      continue;
    for (e = 0; e < 4; e++)
      if (wide->wide->edge_sprite_pixels[i][e])
        mask |= 1u << e;
    for (e = 0; e < 4; e++)
      if (mask & (1u << e)) {
        if (!edge_samples[e]) {
          snprintf(path, sizeof(path), "%s/edge-%u-native.ppm", directory, e);
          if (!write_frame(native, path))
            return 0;
          snprintf(path, sizeof(path), "%s/edge-%u-wide.ppm", directory, e);
          if (!write_frame(wide, path))
            return 0;
          printf("FIRST EDGE %s heading=%u OAM=%u xy=%d,%d tile=%u name=%u "
                 "palette=%u\n",
                 e == 0   ? "left"
                 : e == 1 ? "right"
                 : e == 2 ? "top"
                          : "bottom",
                 heading, i, x, y, obj.tile_low, obj.name_select, obj.palette);
        }
        if (obj.name_select == 0u &&
            ((obj.palette == 0u && obj.tile_low == 223u) ||
             (obj.palette == 1u && obj.tile_low >= 192u &&
              obj.tile_low <= 222u))) {
          if (!weapon_edges[e]) {
            snprintf(path, sizeof(path), "%s/weapon-edge-%u-native.ppm",
                     directory, e);
            if (!write_frame(native, path))
              return 0;
            snprintf(path, sizeof(path), "%s/weapon-edge-%u-wide.ppm",
                     directory, e);
            if (!write_frame(wide, path))
              return 0;
            printf("WEAPON EDGE %u heading=%u OAM=%u xy=%d,%d tile=%u "
                   "palette=%u visible_pixels=%u\n",
                   e, heading, i, x, y, obj.tile_low, obj.palette,
                   wide->wide->edge_sprite_pixels[i][e]);
          }
          weapon_edges[e]++;
        }
        edge_samples[e]++;
      }
  }
  return 1;
}
int main(int argc, char **argv) {
  uint8_t *rom;
  JungleStaticCore *native, *wide;
  FILE *f;
  void *snapshot, *a, *b;
  size_t size;
  unsigned phase, index, frames = 0u, side_sprites = 0u, side_frames = 0u;
  int settled_console = argc == 5 && !strcmp(argv[4], "--settled-console");
  int smoke = argc == 5 && !settled_console;
  char path[2048];
  static const struct {
    const char *name;
    uint16_t input;
    unsigned frames;
  } phases[] = {{"idle", 0, 60},
                {"forward-chain-gun", JUNGLE_BUTTON_UP | JUNGLE_BUTTON_X, 180},
                {"turn-hydra", JUNGLE_BUTTON_RIGHT | JUNGLE_BUTTON_A, 180},
                {"reverse-hellfire", JUNGLE_BUTTON_DOWN | JUNGLE_BUTTON_Y, 180},
                {"turn-chain-gun", JUNGLE_BUTTON_LEFT | JUNGLE_BUTTON_X, 180},
                {"north-east", JUNGLE_BUTTON_UP | JUNGLE_BUTTON_RIGHT, 180},
                {"south-west", JUNGLE_BUTTON_DOWN | JUNGLE_BUTTON_LEFT, 180},
                {"map-open", JUNGLE_BUTTON_SELECT, 4},
                {"map-idle", 0, 90},
                {"map-close", JUNGLE_BUTTON_SELECT, 4},
                {"flight-return", 0, 90}};
  if (argc != 4 && argc != 5) {
    fprintf(stderr, "usage: widescreen-verify ROM SNAPSHOT OUTPUT_DIRECTORY\n");
    return 2;
  }
  output_directory = argv[3];
  f = fopen(argv[1], "rb");
  if (!f)
    return 2;
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  if (!rom || fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
                  JUNGLE_STATIC_CORE_ROM_SIZE)
    return 2;
  fclose(f);
  native = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  wide = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!native || !wide)
    return 2;
  size = jungle_core_snapshot_size(native);
  snapshot = malloc(size);
  a = malloc(size);
  b = malloc(size);
  if (!snapshot || !a || !b)
    return 2;
  f = fopen(argv[2], "rb");
  if (!f || fread(snapshot, 1, size, f) != size)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(native, snapshot, size) ||
      !jungle_core_load_snapshot(wide, snapshot, size) ||
      !jungle_core_set_widescreen(wide, 1))
    return 2;
  for (phase = 0; phase < (smoke ? 1u : sizeof(phases) / sizeof(phases[0]));
       phase++) {
    unsigned phase_frames = phases[phase].frames;
    if (settled_console && (phase == 7u || phase == 9u))
      phase_frames = 12u;
    if (settled_console && (phase == 8u || phase == 10u))
      phase_frames = 360u;
    unsigned phase_side = 0u, left_side = 0u, right_side = 0u;
    uint16_t cx0 =
        (uint16_t)(wide->machine.bus.base.wram[0x40] |
                   ((uint16_t)wide->machine.bus.base.wram[0x41] << 8));
    uint16_t cy0 =
        (uint16_t)(wide->machine.bus.base.wram[0x42] |
                   ((uint16_t)wide->machine.bus.base.wram[0x43] << 8));
    for (index = 0; index < phase_frames; index++) {
      JungleCoreAudio audio;
      JungleCoreFrame n, v;
      unsigned y, side = 0u;
      if (!jungle_core_run_frame(native, phases[phase].input, 0) ||
          !jungle_core_run_frame(wide, phases[phase].input, 0)) {
        printf("FAIL frame=%u native=%u/%u wide=%u/%u pc=%02x:%04x\n", frames,
               native->machine_stop, native->renderer_stop, wide->machine_stop,
               wide->renderer_stop, native->machine.cpu_core.cpu.pbr,
               native->machine.cpu_core.cpu.pc);
        {
          size_t z = jungle_core_diagnostic_snapshot_size(native);
          char *diagnostic = malloc(z);
          if (diagnostic &&
              jungle_core_save_diagnostic_snapshot(native, diagnostic, z))
            puts(diagnostic);
          free(diagnostic);
        }
        return 1;
      }
      jungle_core_take_audio(native, &audio);
      jungle_core_take_audio(wide, &audio);
      frames++;
      if (!jungle_core_get_frame(native, &n) ||
          !jungle_core_get_frame(wide, &v))
        return 1;
      if ((phase == 0u || (phase == 10u && index + 1u == phase_frames)) &&
          v.width != JUNGLE_WIDE_WIDTH) {
        puts("FAIL gameplay checkpoint did not produce a wide frame");
        return 1;
      }
      if (phase == 8u && index > 30u && v.width != 256u) {
        puts("FAIL fixed map screen was expanded");
        return 1;
      }
      if (!compare_frame(native, wide)) {
        printf("FAIL presentation/HUD frame=%u\n", frames);
        return 1;
      }
      if (!capture_edges(native, wide, argv[3], phase))
        return 2;
      if (index % 30u == 0u) {
        jungle_core_save_snapshot(native, a, size);
        jungle_core_save_snapshot(wide, b, size);
        if (memcmp(a, b, size)) {
          printf("FAIL guest/snapshot changed frame=%u\n", frames);
          return 1;
        }
      }
      for (y = 0; y < 128u; y++) {
        js_obj_record_v10_28 obj;
        if (js_renderer_v10_28_decode_obj(&wide->machine.ppu, (uint8_t)y,
                                          &obj) != JS_STOP_NONE)
          continue;
        if (obj.y >= 224u || obj.y + obj.size.height == 0u)
          continue;
        if ((obj.x < 0 && obj.x + obj.size.width > -128) ||
            (obj.x < -128 && obj.x + 512 < 384)) {
          side++;
          if (obj.x < 0 && obj.x + obj.size.width > -128)
            left_side++;
          else
            right_side++;
          if (!phase_side)
            printf("SIDE %s OAM=%u x=%d y=%u tile=%u name=%u palette=%u\n",
                   phases[phase].name, y, obj.x, obj.y, obj.tile_low,
                   obj.name_select, obj.palette);
        };
      }
      side_sprites += side;
      if (side) {
        side_frames++;
        if (!phase_side) {
          snprintf(path, sizeof(path), "%s/%02u-%s-first-edge.ppm", argv[3],
                   phase, phases[phase].name);
          if (!write_frame(wide, path))
            return 2;
        }
        phase_side++;
      }
    }
    snprintf(path, sizeof(path), "%s/%02u-%s-native.ppm", argv[3], phase,
             phases[phase].name);
    if (!write_frame(native, path))
      return 2;
    snprintf(path, sizeof(path), "%s/%02u-%s-wide.ppm", argv[3], phase,
             phases[phase].name);
    if (!write_frame(wide, path))
      return 2;
    printf("PASS %s frames=%u camera=%u,%u -> %u,%u width=%u side_frames=%u\n",
           phases[phase].name, phase_frames, cx0, cy0,
           (unsigned)(wide->machine.bus.base.wram[0x40] |
                      ((uint16_t)wide->machine.bus.base.wram[0x41] << 8)),
           (unsigned)(wide->machine.bus.base.wram[0x42] |
                      ((uint16_t)wide->machine.bus.base.wram[0x43] << 8)),
           wide->wide->active ? JUNGLE_WIDE_WIDTH : 256u, phase_side);
    printf("EDGE samples left=%u right=%u\n", left_side, right_side);
    fflush(stdout);
  }
  /* Restart the same natural flight state at multiple headings. */
  for (phase = 0; phase < (smoke ? 0u : 8u); phase++) {
    unsigned side_left = 0u, side_right = 0u;
    if (!jungle_core_load_snapshot(native, snapshot, size) ||
        !jungle_core_load_snapshot(wide, snapshot, size))
      return 1;
    for (index = 0; index < 240u; index++) {
      unsigned turn = phase * 20u;
      uint16_t input =
          index < turn ? JUNGLE_BUTTON_RIGHT
                       : (JUNGLE_BUTTON_UP | JUNGLE_BUTTON_B | JUNGLE_BUTTON_A |
                          JUNGLE_BUTTON_Y | JUNGLE_BUTTON_X);
      JungleCoreFrame n, v;
      JungleCoreAudio audio;
      unsigned y;
      if (!jungle_core_run_frame(native, input, 0) ||
          !jungle_core_run_frame(wide, input, 0))
        return 1;
      jungle_core_take_audio(native, &audio);
      jungle_core_take_audio(wide, &audio);
      frames++;
      jungle_core_get_frame(native, &n);
      jungle_core_get_frame(wide, &v);
      if (!compare_frame(native, wide)) {
        printf("FAIL heading presentation/HUD frame=%u\n", frames);
        return 1;
      }
      if (!capture_edges(native, wide, argv[3], phase + 20u))
        return 2;
      for (y = 0; y < 128u; y++) {
        js_obj_record_v10_28 obj;
        if (js_renderer_v10_28_decode_obj(&wide->machine.ppu, (uint8_t)y,
                                          &obj) != JS_STOP_NONE ||
            obj.y >= 224u)
          continue;
        if (obj.x < 0 && obj.x + obj.size.width > -128) {
          if (!side_left) {
            snprintf(path, sizeof(path), "%s/heading-%u-left.ppm", argv[3],
                     phase);
            if (!write_frame(wide, path))
              return 2;
          }
          side_left++;
        }
        if (obj.x < -128 && obj.x + 512 < 384) {
          if (!side_right) {
            snprintf(path, sizeof(path), "%s/heading-%u-right.ppm", argv[3],
                     phase);
            if (!write_frame(wide, path))
              return 2;
          }
          side_right++;
        }
      }
    }
    jungle_core_save_snapshot(native, a, size);
    jungle_core_save_snapshot(wide, b, size);
    if (memcmp(a, b, size))
      return 1;
    printf("PASS heading=%u fire=B+A+Y+X left_samples=%u right_samples=%u "
           "guest/crop identical\n",
           phase, side_left, side_right);
    fflush(stdout);
  }
  printf("COVERAGE left=%u right=%u top=%u bottom=%u HUD_frames=%u\n",
         edge_samples[0], edge_samples[1], edge_samples[2], edge_samples[3],
         hud_frames);
  printf("WEAPON COVERAGE left=%u right=%u top=%u bottom=%u\n", weapon_edges[0],
         weapon_edges[1], weapon_edges[2], weapon_edges[3]);
  if (!smoke && (!edge_samples[0] || !edge_samples[1] || !edge_samples[2] ||
                 !edge_samples[3])) {
    puts("FAIL missing visible four-edge coverage");
    return 1;
  }
  /* Toggle and snapshot restoration preserve the user's presentation choice. */
  jungle_core_save_snapshot(wide, b, size);
  if (!jungle_core_load_snapshot(wide, b, size) ||
      !jungle_core_widescreen_enabled(wide))
    return 1;
  if (!jungle_core_set_widescreen(wide, 0) ||
      !jungle_core_run_frame(wide, 0, 0))
    return 1;
  {
    JungleCoreFrame v;
    if (!jungle_core_get_frame(wide, &v) || v.width != 256u)
      return 1;
  }
  printf("PASS total=%u identical guest snapshots/native crops "
         "side_sprite_samples=%u side_frames=%u\n",
         frames, side_sprites, side_frames);
  free(snapshot);
  free(a);
  free(b);
  jungle_core_destroy(native);
  jungle_core_destroy(wide);
  return 0;
}
