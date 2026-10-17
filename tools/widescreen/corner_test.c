#define main prior_verify_main
#include "verify.c"
#undef main
#include <math.h>
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
static unsigned trial_input(unsigned action, unsigned tick, unsigned motion) {
  static const unsigned direct[] = {0x810, 0x410, 0x210, 0x110,
                                    0x910, 0xa10, 0x510, 0x610};
  if (tick >= motion)
    return 0;
  if (action < 8)
    return direct[action];
  if (tick < ((action - 8) / 2 + 1) * 15u)
    return action & 1 ? 0x100 : 0x200;
  return 0x800;
}
static int warm(JungleStaticCore *n, JungleStaticCore *w) {
  unsigned i;
  for (i = 0; i < 3; i++) {
    JungleCoreAudio audio;
    if (!jungle_core_run_frame(n, 0, 0) || !jungle_core_run_frame(w, 0, 0) ||
        !compare_frame(n, w))
      return 0;
    jungle_core_take_audio(n, &audio);
    jungle_core_take_audio(w, &audio);
  }
  return 1;
}
int main(int argc, char **argv) {
  FILE *f;
  uint8_t *rom;
  void *initial, *a, *b;
  size_t z;
  JungleStaticCore *n, *w, *probe;
  char line[512], label[100], path[2048];
  unsigned count, input, frames = 0, i;
  if (argc != 5) {
    puts("ROM SNAPSHOT ROUTE OUTPUT");
    return 2;
  }
  f = fopen(argv[1], "rb");
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  if (!f || fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
                JUNGLE_STATIC_CORE_ROM_SIZE)
    return 2;
  fclose(f);
  n = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  w = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  probe = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!n || !w || !probe)
    return 2;
  z = jungle_core_snapshot_size(n);
  initial = malloc(z);
  a = malloc(z);
  b = malloc(z);
  f = fopen(argv[2], "rb");
  if (!f || fread(initial, 1, z, f) != z)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(n, initial, z) ||
      !jungle_core_load_snapshot(w, initial, z) ||
      !jungle_core_set_widescreen(w, 1))
    return 2;
  output_directory = argv[4];
  if (!warm(n, w))
    return 1;
  f = fopen(argv[3], "r");
  if (!f)
    return 2;
  setvbuf(stdout, NULL, _IONBF, 0);
  while (fgets(line, sizeof(line), f)) {
    unsigned tx = 0, ty = 0, remaining = 0, total = 0, motion = 0, action = 0;
    int navigate = 0;
    if (!strncmp(line, "reset", 5)) {
      jungle_core_load_snapshot(n, initial, z);
      jungle_core_load_snapshot(w, initial, z);
      if (!warm(n, w))
        return 1;
      continue;
    }
    if (sscanf(line, "go %u %u %u %99s", &tx, &ty, &count, label) == 4) {
      navigate = 1;
      input = 0;
    } else if (sscanf(line, "%u %x %99s", &count, &input, label) != 3)
      continue;
    for (i = 0; i < count; i++) {
      if (navigate && !remaining) {
        int dx = (int)tx - (int)ramword(n, 0x40),
            dy = (int)ty - (int)ramword(n, 0x42);
        if (abs(dx) < 24 && abs(dy) < 24) {
          printf("REACHED %s camera=%u,%u frames=%u\n", label, ramword(n, 0x40),
                 ramword(n, 0x42), i);
          break;
        }
        double before = (double)dx * dx + (double)dy * dy, best = 1e30;
        unsigned k, t, best_motion = 90;
        motion = abs(dx) + 2 * abs(dy) > 300 ? 90 : 20;
        total = motion + 30;
        if (!jungle_core_save_snapshot(n, a, z))
          return 1;
        for (k = 0; k < 24; k++) {
          int px, py;
          double score;
          unsigned trial_motion = k >= 8 ? 180 : motion,
                   trial_total = trial_motion + 30;
          if (k == 8 && best < before - (abs(dx) + abs(dy)) * 20)
            break;
          if (!jungle_core_load_snapshot(probe, a, z))
            return 1;
          for (t = 0; t < trial_total; t++) {
            JungleCoreAudio audio;
            if (!jungle_core_run_frame_headless(
                    probe, trial_input(k, t, trial_motion), 0)) {
              printf("FAIL trial action=%u stop=%u\n", k, probe->machine_stop);
              return 1;
            }
            jungle_core_take_audio(probe, &audio);
          }
          px = (int)tx - (int)ramword(probe, 0x40);
          py = (int)ty - (int)ramword(probe, 0x42);
          score = (double)px * px + (double)py * py;
          if (ramword(probe, 0x1415c) < 200 || ramword(probe, 0x1415c) > 1000)
            score += 1e15;
          else if (ramword(n, 0x1415c) > ramword(probe, 0x1415c))
            score += (ramword(n, 0x1415c) - ramword(probe, 0x1415c)) * 200.0;
          if (score < best) {
            best = score;
            action = k;
            best_motion = trial_motion;
          }
        }
        motion = best_motion;
        total = motion + 30;
        remaining = total;
        printf("PLAN %s camera=%u,%u target=%u,%u action=%u motion=%u "
               "distance=%.0f -> %.0f\n",
               label, ramword(n, 0x40), ramword(n, 0x42), tx, ty, action,
               motion, before, best);
      }
      if (navigate) {
        input = trial_input(action, total - remaining, motion);
        remaining--;
      }
      JungleCoreAudio audio;
      int render = 1, nr, wr;
      nr = render ? jungle_core_run_frame(n, input, 0)
                  : jungle_core_run_frame_headless(n, input, 0);
      wr = render ? jungle_core_run_frame(w, input, 0)
                  : jungle_core_run_frame_headless(w, input, 0);
      frames++;
      if (!nr || !wr || (render && !compare_frame(n, w))) {
        size_t q = jungle_core_diagnostic_snapshot_size(n);
        char *d = malloc(q);
        printf("FAIL %s frame=%u stops=%u/%u wide=%u/%u\n", label, i,
               n->machine_stop, n->renderer_stop, w->machine_stop,
               w->renderer_stop);
        if (jungle_core_save_diagnostic_snapshot(n, d, q))
          puts(d);
        return 1;
      }
      jungle_core_take_audio(n, &audio);
      jungle_core_take_audio(w, &audio);
      if (navigate &&
          (ramword(n, 0x1415c) < 200 || ramword(n, 0x1415c) > 1000)) {
        printf("FAIL unsafe armor=%u\n", ramword(n, 0x1415c));
        return 1;
      }
      if (render && !capture_edges(n, w, argv[4], frames))
        return 2;
      if (i % 120 == 0)
        printf("TRACE %s frame=%u camera=%u,%u armor=%u fuel=%u state=%04X\n",
               label, i, ramword(n, 0x40), ramword(n, 0x42),
               ramword(n, 0x1415c), ramword(n, 0x11132), ramword(n, 0xc0b));
      if (navigate && i % 1200 == 0) {
        jungle_core_save_snapshot(n, a, z);
        snprintf(path, sizeof(path), "%s/progress.snapshot", argv[4]);
        save_bytes(path, a, z);
        snprintf(path, sizeof(path), "%s/progress-wide.ppm", argv[4]);
        write_frame(w, path);
        snprintf(path, sizeof(path), "%s/progress.wram", argv[4]);
        save_bytes(path, n->machine.bus.base.wram, 0x20000);
      }
    }
    if (navigate && i == count) {
      printf("FAIL target not reached %s camera=%u,%u target=%u,%u\n", label,
             ramword(n, 0x40), ramword(n, 0x42), tx, ty);
      return 1;
    }
    if (navigate) {
      JungleCoreAudio audio;
      unsigned settle;
      for (settle = 0; settle < 3; settle++) {
        if (!jungle_core_run_frame(n, 0, 0) ||
            !jungle_core_run_frame(w, 0, 0) || !compare_frame(n, w))
          return 1;
        jungle_core_take_audio(n, &audio);
        jungle_core_take_audio(w, &audio);
        frames++;
      }
    }
    if (!jungle_core_save_snapshot(n, a, z) ||
        !jungle_core_save_snapshot(w, b, z) || memcmp(a, b, z))
      return 1;
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
    printf("PASS %s frames=%u camera=%u,%u map=%ux%u bank=%02X base=%04X "
           "console=%04X\n",
           label, i, ramword(n, 0x40), ramword(n, 0x42), ramword(n, 0x10f68),
           ramword(n, 0x10f6a), n->machine.bus.base.wram[0x106],
           ramword(n, 0x78), ramword(n, 0xc0b));
  }
  printf("PASS total=%u edge_samples=%u,%u,%u,%u weapons=%u,%u,%u,%u HUD=%u\n",
         frames, edge_samples[0], edge_samples[1], edge_samples[2],
         edge_samples[3], weapon_edges[0], weapon_edges[1], weapon_edges[2],
         weapon_edges[3], hud_frames);
  return 0;
}
