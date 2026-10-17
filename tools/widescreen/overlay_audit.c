/* Check native pause/information-console transitions without guest edits. */
#define main gameplay_verification_main
#include "verify.c"
#undef main
int main(int argc, char **argv) {
  static const struct {
    const char *name;
    uint16_t input;
    unsigned frames;
  } phases[] = {
      {"flight", 0, 30},        {"pause-open", JUNGLE_BUTTON_START, 3},
      {"paused", 0, 60},        {"pause-close", JUNGLE_BUTTON_START, 3},
      {"flight-return", 0, 30}, {"console-open", JUNGLE_BUTTON_SELECT, 3},
      {"map", 0, 360},           {"mission-open", JUNGLE_BUTTON_X, 30},
      {"mission", 0, 360},       {"status-open", JUNGLE_BUTTON_A, 30},
      {"status", 0, 360},        {"map-return", JUNGLE_BUTTON_Y, 30},
      {"map-again", 0, 360},     {"status-direct", JUNGLE_BUTTON_A, 30},
      {"status-again", 0, 360},  {"console-close", JUNGLE_BUTTON_SELECT, 3},
      {"flight-final", 0, 180}};
  FILE *f;
  uint8_t *rom;
  void *snapshot, *a, *b;
  size_t size;
  JungleStaticCore *n, *w;
  unsigned phase, i;
  char path[2048];
  if (argc != 4)
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
  {
    JungleCoreStatus status;
    if (!jungle_core_status(n, &status) ||
        status.production_contexts != 28636u ||
        status.production_rom_bytes != 66177u ||
        status.sealed_not_production_contexts != 0u)
      return 1;
    puts("PASS production authority counters without unsigned underflow");
  }
  size = jungle_core_snapshot_size(n);
  snapshot = malloc(size);
  a = malloc(size);
  b = malloc(size);
  f = fopen(argv[2], "rb");
  if (!f || !snapshot || !a || !b || fread(snapshot, 1, size, f) != size)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(n, snapshot, size) ||
      !jungle_core_load_snapshot(w, snapshot, size) ||
      !jungle_core_set_widescreen(w, 1))
    return 2;
  output_directory = argv[3];
  for (phase = 0; phase < sizeof(phases) / sizeof(phases[0]); phase++) {
    JungleCoreFrame frame;
    for (i = 0; i < phases[phase].frames; i++) {
      JungleCoreAudio audio;
      {
        int nr = jungle_core_run_frame(n, phases[phase].input, 0);
        int wr = jungle_core_run_frame(w, phases[phase].input, 0);
        if (!nr || !wr || !compare_frame(n, w)) {
          size_t z = jungle_core_diagnostic_snapshot_size(n);
          char *diag = malloc(z);
          printf("FAIL phase=%s frame=%u native=%u/%u wide=%u/%u runs=%d/%d\n",
                 phases[phase].name, i, n->machine_stop, n->renderer_stop,
                 w->machine_stop, w->renderer_stop, nr, wr);
          if (diag && jungle_core_save_diagnostic_snapshot(n, diag, z))
            puts(diag);
          free(diag);
          return 1;
        }
      }
      jungle_core_take_audio(n, &audio);
      jungle_core_take_audio(w, &audio);
    }
    if (!jungle_core_save_snapshot(n, a, size) ||
        !jungle_core_save_snapshot(w, b, size) || memcmp(a, b, size) ||
        !jungle_core_get_frame(w, &frame))
      return 1;
    snprintf(path, sizeof(path), "%s/%s-native.ppm", argv[3],
             phases[phase].name);
    if (!write_frame(n, path))
      return 2;
    snprintf(path, sizeof(path), "%s/%s-wide.ppm", argv[3], phases[phase].name);
    if (!write_frame(w, path))
      return 2;
    printf("PASS %s frames=%u dimensions=%ux%u identical native view and guest "
           "snapshot\n",
           phases[phase].name, phases[phase].frames, frame.width, frame.height);
    printf("Console state=%04X input=%04X effective=%04X\n",
           n->machine.bus.base.wram[0x0c0b] |
               (n->machine.bus.base.wram[0x0c0c] << 8),
           phases[phase].input,
           n->machine.bus.base.wram[0x0cd5] |
               (n->machine.bus.base.wram[0x0cd6] << 8));
    {
      unsigned expected = 0, actual = n->machine.bus.base.wram[0x0c0b] |
                                     (n->machine.bus.base.wram[0x0c0c] << 8);
      if (!strcmp(phases[phase].name, "map") ||
          !strcmp(phases[phase].name, "map-again"))
        expected = 0x834c;
      if (!strcmp(phases[phase].name, "mission"))
        expected = 0x83fb;
      if (!strcmp(phases[phase].name, "status") ||
          !strcmp(phases[phase].name, "status-again"))
        expected = 0x84cf;
      if (expected && (actual != expected || frame.width != 256u ||
                       frame.height != 224u)) {
        printf("FAIL settled console state: expected=%04X actual=%04X\n",
               expected, actual);
        return 1;
      }
    }
    if (!strcmp(phases[phase].name, "flight-final") &&
        (frame.width != 512u || frame.height != 288u))
      return 1;
  }
  free(snapshot);
  free(a);
  free(b);
  jungle_core_destroy(n);
  jungle_core_destroy(w);
  return 0;
}
