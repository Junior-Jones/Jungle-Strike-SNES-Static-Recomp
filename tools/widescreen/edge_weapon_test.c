#define main prior_verify_main
#include "verify.c"
#undef main

static unsigned ramword(JungleStaticCore *c, unsigned at) {
  const uint8_t *w = c->machine.bus.base.wram;
  return w[at] | (w[at + 1] << 8);
}
static int save_bytes(const char *p, const void *d, size_t z) {
  FILE *f = fopen(p, "wb");
  if (!f)
    return 0;
  return fwrite(d, 1, z, f) == z && fclose(f) == 0;
}

static unsigned player_seen_mask, player_visible_mask;
static int player_body(const js_ppu_v09c *p, unsigned i) {
  js_obj_record_v10_28 o;
  return i < 128 &&
         js_renderer_v10_28_decode_obj(p, (uint8_t)i, &o) == JS_STOP_NONE &&
         o.name_select == 1 && o.palette == 0 &&
         (o.tile_low < 8 || (o.tile_low >= 32 && o.tile_low < 40));
}
static int capture_player(JungleStaticCore *n, JungleStaticCore *w,
                          const char *dir, unsigned frame) {
  JungleCoreFrame f;
  js_ppu_v09c p = w->wide->edge_ppu;
  unsigned count[4] = {0}, x, y, i;
  int minx = JUNGLE_WIDE_WIDTH, miny = 288, maxx = -1, maxy = -1,
      ox = JUNGLE_WIDE_MARGIN - w->wide->view_shift_x,
      oy = 32 - w->wide->view_shift_y;
  char path[2048];
  if (!w->wide->active || !jungle_core_get_frame(w, &f) ||
      f.width != JUNGLE_WIDE_WIDTH)
    return 1;
  for (i = 0; i < 128; i++)
    if (w->wide->sprite_seen[i] && player_body(&p, i)) {
      js_obj_record_v10_28 o;
      int sx = w->wide->sprite_x[i] + ox, sy = w->wide->sprite_y[i] + oy;
      js_renderer_v10_28_decode_obj(&p, i, &o);
      if (sx < minx)
        minx = sx;
      if (sy < miny)
        miny = sy;
      if (sx + o.size.width > maxx)
        maxx = sx + o.size.width;
      if (sy + o.size.height > maxy)
        maxy = sy + o.size.height;
    }
  int raw_minx = minx, raw_miny = miny, raw_maxx = maxx, raw_maxy = maxy;
  if (minx < 0)
    minx = 0;
  if (miny < 0)
    miny = 0;
  if (maxx > JUNGLE_WIDE_WIDTH)
    maxx = JUNGLE_WIDE_WIDTH;
  if (maxy > 284)
    maxy = 284;
  for (y = miny; y < (unsigned)maxy && y < 284; y++) {
    int ny = (int)y - oy;
    js_obj_scanline_v10_30 line;
    if (ny >= 0 && ny < 220)
      js_renderer_v10_30_evaluate_obj_scanline(&p, ny, &line);
    for (x = minx; x < (unsigned)maxx && x < JUNGLE_WIDE_WIDTH; x++) {
      int nx = (int)x - ox, visible = 0;
      unsigned owner = w->wide->pixel_object[y * JUNGLE_WIDE_WIDTH + x];
      if (y >= 272 && x >= JUNGLE_WIDE_MARGIN &&
          x < JUNGLE_WIDE_MARGIN + 256u &&
          w->wide->hud_mask[(y - 272) * 256 + x - JUNGLE_WIDE_MARGIN])
        continue;
      if (x >= JUNGLE_WIDE_MARGIN && x < JUNGLE_WIDE_MARGIN + 256u && y >= 32 &&
          y < 256)
        continue;
      if (owner && player_body(&p, owner - 1))
        visible = 1;
      else if (nx >= 0 && nx < 256 && ny >= 0 && ny < 220) {
        js_obj_pixel_v10_30 obj;
        js_screen_pixel_v10_30 pixel;
        js_renderer_v10_30_sample_obj_pixel(&p, &line, nx, ny, &obj);
        if (!obj.transparent && player_body(&p, obj.obj_index) &&
            js_renderer_v10_30_render_source_pixel(&p, nx, ny, &pixel) ==
                JS_STOP_NONE &&
            pixel.main_pixel.source == JS_PIXEL_V10_30_OBJ) {
          uint32_t rgb = 0xff000000u | ((uint32_t)pixel.rgb.r << 16) |
                         ((uint32_t)pixel.rgb.g << 8) | pixel.rgb.b;
          if (f.bgra_pixels[y * f.width + x] == rgb)
            visible = 1;
        }
      }
      if (visible) {
        if (x < JUNGLE_WIDE_MARGIN)
          count[0]++;
        if (x >= JUNGLE_WIDE_MARGIN + 256u)
          count[1]++;
        if (y < 32)
          count[2]++;
        if (y >= 256)
          count[3]++;
      }
    }
  }
  for (i = 0; i < 4; i++)
    if (count[i] && !(player_seen_mask & (1u << i))) {
      void *data;
      size_t z = jungle_core_snapshot_size(n);
      player_seen_mask |= 1u << i;
      snprintf(path, sizeof(path), "%s/player-edge-%u-wide.ppm", dir, i);
      if (!write_frame(w, path))
        return 0;
      snprintf(path, sizeof(path), "%s/player-edge-%u-native.ppm", dir, i);
      if (!write_frame(n, path))
        return 0;
      data = malloc(z);
      jungle_core_save_snapshot(n, data, z);
      snprintf(path, sizeof(path), "%s/player-edge-%u.snapshot", dir, i);
      if (!save_bytes(path, data, z))
        return 0;
      free(data);
      printf("PLAYER EDGE side=%u frame=%u visible_body_pixels=%u "
             "bbox=%d,%d..%d,%d player_world=%u,%u camera=%u,%u health=%u "
             "native_offset=%d,%d\n",
             i, frame, count[i], minx, miny, maxx, maxy, ramword(n, 0x140fc),
             ramword(n, 0x14100), ramword(n, 64), ramword(n, 66),
             ramword(n, 0x1415c), ox, oy);
    }

  for (i = 0; i < 4; i++)
    if (count[i] >= 80 && !(player_visible_mask & (1u << i)) && raw_minx >= 0 &&
        raw_miny >= 0 && raw_maxx <= JUNGLE_WIDE_WIDTH && raw_maxy <= 284) {
      void *data;
      size_t z = jungle_core_snapshot_size(n);
      player_visible_mask |= 1u << i;
      snprintf(path, sizeof(path), "%s/player-visible-%u-wide.ppm", dir, i);
      if (!write_frame(w, path))
        return 0;
      snprintf(path, sizeof(path), "%s/player-visible-%u-native.ppm", dir, i);
      if (!write_frame(n, path))
        return 0;
      data = malloc(z);
      jungle_core_save_snapshot(n, data, z);
      snprintf(path, sizeof(path), "%s/player-visible-%u.snapshot", dir, i);
      if (!save_bytes(path, data, z))
        return 0;
      free(data);
      printf("PLAYER VISIBLE side=%u frame=%u visible_body_pixels=%u "
             "bbox=%d,%d..%d,%d player_world=%u,%u camera=%u,%u health=%u\n",
             i, frame, count[i], minx, miny, maxx, maxy, ramword(n, 0x140fc),
             ramword(n, 0x14100), ramword(n, 64), ramword(n, 66),
             ramword(n, 0x1415c));
    }
  return 1;
}
static unsigned projectile_seen_mask, projectile_visible_mask,
    weapon_evidence[3];
static const char *projectile_phase = "settle";
static int projectile_graphic(const js_ppu_v09c *p, unsigned i) {
  js_obj_record_v10_28 o;
  return i < 128 &&
         js_renderer_v10_28_decode_obj(p, (uint8_t)i, &o) == JS_STOP_NONE &&
         o.name_select == 0 &&
         ((o.palette == 0 && o.tile_low == 223) ||
          (o.palette == 1 && o.tile_low >= 192 && o.tile_low <= 222));
}
static int capture_projectile(JungleStaticCore *n, JungleStaticCore *w,
                              const char *dir, unsigned frame) {
  JungleCoreFrame f;
  js_ppu_v09c p = w->wide->edge_ppu;
  unsigned count[4] = {0}, x, y, i;
  int minx = JUNGLE_WIDE_WIDTH, miny = 288, maxx = -1, maxy = -1,
      ox = JUNGLE_WIDE_MARGIN - w->wide->view_shift_x,
      oy = 32 - w->wide->view_shift_y;
  char path[2048];
  if (!w->wide->active || !jungle_core_get_frame(w, &f) ||
      f.width != JUNGLE_WIDE_WIDTH)
    return 1;
  for (i = 0; i < 128; i++)
    if (w->wide->sprite_seen[i] && projectile_graphic(&p, i)) {
      js_obj_record_v10_28 o;
      int sx = w->wide->sprite_x[i] + ox, sy = w->wide->sprite_y[i] + oy;
      js_renderer_v10_28_decode_obj(&p, i, &o);
      if (sx < minx)
        minx = sx;
      if (sy < miny)
        miny = sy;
      if (sx + o.size.width > maxx)
        maxx = sx + o.size.width;
      if (sy + o.size.height > maxy)
        maxy = sy + o.size.height;
    }
  int raw_minx = minx, raw_miny = miny, raw_maxx = maxx, raw_maxy = maxy;
  if (minx < 0)
    minx = 0;
  if (miny < 0)
    miny = 0;
  if (maxx > JUNGLE_WIDE_WIDTH)
    maxx = JUNGLE_WIDE_WIDTH;
  if (maxy > 284)
    maxy = 284;
  for (y = miny; y < (unsigned)maxy && y < 284; y++) {
    int ny = (int)y - oy;
    js_obj_scanline_v10_30 line;
    if (ny >= 0 && ny < 220)
      js_renderer_v10_30_evaluate_obj_scanline(&p, ny, &line);
    for (x = minx; x < (unsigned)maxx && x < JUNGLE_WIDE_WIDTH; x++) {
      int nx = (int)x - ox, visible = 0;
      unsigned owner = w->wide->pixel_object[y * JUNGLE_WIDE_WIDTH + x];
      if (y >= 272 && x >= JUNGLE_WIDE_MARGIN &&
          x < JUNGLE_WIDE_MARGIN + 256u &&
          w->wide->hud_mask[(y - 272) * 256 + x - JUNGLE_WIDE_MARGIN])
        continue;
      if (x >= JUNGLE_WIDE_MARGIN && x < JUNGLE_WIDE_MARGIN + 256u && y >= 32 &&
          y < 256)
        continue;
      if (owner && projectile_graphic(&p, owner - 1))
        visible = 1;
      else if (nx >= 0 && nx < 256 && ny >= 0 && ny < 220) {
        js_obj_pixel_v10_30 obj;
        js_screen_pixel_v10_30 pixel;
        js_renderer_v10_30_sample_obj_pixel(&p, &line, nx, ny, &obj);
        if (!obj.transparent && projectile_graphic(&p, obj.obj_index) &&
            js_renderer_v10_30_render_source_pixel(&p, nx, ny, &pixel) ==
                JS_STOP_NONE &&
            pixel.main_pixel.source == JS_PIXEL_V10_30_OBJ) {
          uint32_t rgb = 0xff000000u | ((uint32_t)pixel.rgb.r << 16) |
                         ((uint32_t)pixel.rgb.g << 8) | pixel.rgb.b;
          if (f.bgra_pixels[y * f.width + x] == rgb)
            visible = 1;
        }
      }
      if (visible) {
        if (x < JUNGLE_WIDE_MARGIN)
          count[0]++;
        if (x >= JUNGLE_WIDE_MARGIN + 256u)
          count[1]++;
        if (y < 32)
          count[2]++;
        if (y >= 256)
          count[3]++;
      }
    }
  }
  for (i = 0; i < 4; i++)
    if (count[i] && !(projectile_seen_mask & (1u << i))) {
      void *data;
      size_t z = jungle_core_snapshot_size(n);
      projectile_seen_mask |= 1u << i;
      weapon_evidence[!strcmp(projectile_phase, "gun-x")       ? 0
                      : !strcmp(projectile_phase, "missile-a") ? 1
                                                               : 2] |= 1u << i;
      snprintf(path, sizeof(path), "%s/%s-projectile-edge-%u-wide.ppm", dir,
               projectile_phase, i);
      if (!write_frame(w, path))
        return 0;
      snprintf(path, sizeof(path), "%s/%s-projectile-edge-%u-native.ppm", dir,
               projectile_phase, i);
      if (!write_frame(n, path))
        return 0;
      data = malloc(z);
      jungle_core_save_snapshot(n, data, z);
      snprintf(path, sizeof(path), "%s/%s-projectile-edge-%u.snapshot", dir,
               projectile_phase, i);
      if (!save_bytes(path, data, z))
        return 0;
      free(data);
      printf("PROJECTILE EDGE weapon=%s side=%u frame=%u "
             "visible_projectile_pixels=%u bbox=%d,%d..%d,%d "
             "player_world=%u,%u camera=%u,%u health=%u native_offset=%d,%d\n",
             projectile_phase, i, frame, count[i], minx, miny, maxx, maxy,
             ramword(n, 0x140fc), ramword(n, 0x14100), ramword(n, 64),
             ramword(n, 66), ramword(n, 0x1415c), ox, oy);
    }

  for (i = 0; i < 4; i++)
    if (count[i] >= 4 && !(projectile_visible_mask & (1u << i)) &&
        raw_minx >= 0 && raw_miny >= 0 && raw_maxx <= JUNGLE_WIDE_WIDTH &&
        raw_maxy <= 284) {
      void *data;
      size_t z = jungle_core_snapshot_size(n);
      projectile_visible_mask |= 1u << i;
      snprintf(path, sizeof(path), "%s/%s-projectile-visible-%u-wide.ppm", dir,
               projectile_phase, i);
      if (!write_frame(w, path))
        return 0;
      snprintf(path, sizeof(path), "%s/%s-projectile-visible-%u-native.ppm",
               dir, projectile_phase, i);
      if (!write_frame(n, path))
        return 0;
      data = malloc(z);
      jungle_core_save_snapshot(n, data, z);
      snprintf(path, sizeof(path), "%s/%s-projectile-visible-%u.snapshot", dir,
               projectile_phase, i);
      if (!save_bytes(path, data, z))
        return 0;
      free(data);
      printf("PROJECTILE VISIBLE weapon=%s side=%u frame=%u "
             "visible_projectile_pixels=%u bbox=%d,%d..%d,%d "
             "player_world=%u,%u camera=%u,%u health=%u\n",
             projectile_phase, i, frame, count[i], minx, miny, maxx, maxy,
             ramword(n, 0x140fc), ramword(n, 0x14100), ramword(n, 64),
             ramword(n, 66), ramword(n, 0x1415c));
    }
  return 1;
}

/* Input-only route replay. The final gate requires all three weapon inputs and
   the live player helicopter to have visible pixels on the requested side. */
int main(int argc, char **argv) {
  FILE *f;
  uint8_t *rom;
  void *initial, *a, *b;
  size_t z;
  JungleStaticCore *n, *w;
  char line[512], label[100], path[2048];
  unsigned count, input, frames = 0, i, side;
  if (argc != 6) {
    puts("ROM SNAPSHOT ROUTE OUTPUT SIDE(0=left,1=right,2=top,3=bottom)");
    return 2;
  }
  side = (unsigned)strtoul(argv[5], NULL, 10);
  if (side > 3)
    return 2;
  f = fopen(argv[1], "rb");
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  if (!f || !rom ||
      fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
          JUNGLE_STATIC_CORE_ROM_SIZE)
    return 2;
  fclose(f);
  n = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  w = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!n || !w)
    return 2;
  z = jungle_core_snapshot_size(n);
  initial = malloc(z);
  a = malloc(z);
  b = malloc(z);
  f = fopen(argv[2], "rb");
  if (!f || !initial || !a || !b || fread(initial, 1, z, f) != z)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(n, initial, z) ||
      !jungle_core_load_snapshot(w, initial, z) ||
      !jungle_core_set_widescreen(w, 1))
    return 2;
  for (i = 0; i < 3; i++) {
    JungleCoreAudio audio;
    if (!jungle_core_run_frame(n, 0, 0) || !jungle_core_run_frame(w, 0, 0) ||
        !compare_frame(n, w))
      return 1;
    jungle_core_take_audio(n, &audio);
    jungle_core_take_audio(w, &audio);
  }
  output_directory = argv[4];
  f = fopen(argv[3], "r");
  if (!f)
    return 2;
  setvbuf(stdout, NULL, _IONBF, 0);
  while (fgets(line, sizeof(line), f)) {
    unsigned ammo_address = 0, ammo_before = 0;
    if (sscanf(line, "%u %x %99s", &count, &input, label) != 3)
      continue;
    if (input & 0x40) {
      projectile_phase = "gun-x";
      ammo_address = 0x11138;
    } else if (input & 0x80) {
      projectile_phase = "missile-a";
      ammo_address = 0x11134;
    } else if (input & 0x4000) {
      projectile_phase = "missile-y";
      ammo_address = 0x11136;
    }
    if (ammo_address) {
      projectile_seen_mask = projectile_visible_mask = 0;
      ammo_before = ramword(n, ammo_address);
    }
    for (i = 0; i < count; i++) {
      JungleCoreAudio audio;
      frames++;
      if (!jungle_core_run_frame(n, input, 0) ||
          !jungle_core_run_frame(w, input, 0) || !compare_frame(n, w)) {
        printf("FAIL %s frame=%u stops=%u/%u wide=%u/%u\n", label, i,
               n->machine_stop, n->renderer_stop, w->machine_stop,
               w->renderer_stop);
        return 1;
      }
      jungle_core_take_audio(n, &audio);
      jungle_core_take_audio(w, &audio);
      if (!capture_player(n, w, argv[4], frames) ||
          !capture_projectile(n, w, argv[4], frames))
        return 2;
    }
    if (ammo_address && ramword(n, ammo_address) >= ammo_before) {
      printf("FAIL no ammunition decrease for %s\n", label);
      return 1;
    }
    if (!jungle_core_save_snapshot(n, a, z) ||
        !jungle_core_save_snapshot(w, b, z) || memcmp(a, b, z)) {
      puts("FAIL guest snapshots differ");
      return 1;
    }
    snprintf(path, sizeof(path), "%s/%s-native.ppm", argv[4], label);
    if (!write_frame(n, path))
      return 2;
    snprintf(path, sizeof(path), "%s/%s-wide.ppm", argv[4], label);
    if (!write_frame(w, path))
      return 2;
    snprintf(path, sizeof(path), "%s/%s.snapshot", argv[4], label);
    if (!save_bytes(path, a, z))
      return 2;
    snprintf(path, sizeof(path), "%s/%s.wram", argv[4], label);
    if (!save_bytes(path, n->machine.bus.base.wram, 0x20000))
      return 2;
    printf("AMMO %s hellfire=%u hydra=%u gun=%u\n", label, ramword(n, 0x11134),
           ramword(n, 0x11136), ramword(n, 0x11138));
    printf("PASS %s frames=%u health=%u\n", label, count, ramword(n, 0x1415c));
  }
  fclose(f);
  for (i = 0; i < 3; i++)
    if (!(weapon_evidence[i] & (1u << side))) {
      printf("FAIL missing projectile pixels for weapon=%u side=%u\n", i, side);
      return 1;
    }
  if (!(player_seen_mask & (1u << side))) {
    puts("FAIL player aircraft not observed on requested side");
    return 1;
  }
  printf("PASS %u frames: player aircraft and all three weapon inputs visible "
         "on side=%u; ammunition decreased; native/wide crops and guest states "
         "identical\n",
         frames, side);
  free(initial);
  free(a);
  free(b);
  jungle_core_destroy(n);
  jungle_core_destroy(w);
  return 0;
}
