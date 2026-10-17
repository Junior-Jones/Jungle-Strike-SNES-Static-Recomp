/* Live display switching: real input replay, no guest-state edits. */
#define main prior_verify_main
#include "verify.c"
#undef main
int main(int argc, char **argv) {
  FILE *f;
  uint8_t *rom;
  void *snapshot, *a, *b;
  size_t size;
  JungleStaticCore *native, *wide;
  char line[512], label[100], path[2048];
  unsigned count, input, frame = 0, switches = 0, console = 0, flight = 0;
  unsigned normal_frames = 0, wide_frames = 0, i;
  if (argc != 5)
    return 2;
  f = fopen(argv[1], "rb");
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  if (!f || !rom ||
      fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
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
  f = fopen(argv[2], "rb");
  if (!f || !snapshot || !a || !b || fread(snapshot, 1, size, f) != size)
    return 2;
  fclose(f);
  if (!jungle_core_load_snapshot(native, snapshot, size) ||
      !jungle_core_load_snapshot(wide, snapshot, size) ||
      !jungle_core_set_widescreen(wide, 1))
    return 2;
  output_directory = argv[4];
  f = fopen(argv[3], "r");
  if (!f)
    return 2;
  while (fgets(line, sizeof(line), f)) {
    if (sscanf(line, "%u %x %99s", &count, &input, label) != 3)
      continue;
    for (i = 0; i < count; i++) {
      JungleCoreAudio audio;
      JungleCoreFrame result;
      if (frame && frame % 60u == 0u) {
        if (!jungle_core_set_widescreen(wide,
                                        !jungle_core_widescreen_enabled(wide)))
          return 1;
        switches++;
      }
      if (!jungle_core_run_frame(native, input, 0) ||
          !jungle_core_run_frame(wide, input, 0) ||
          !compare_frame(native, wide) ||
          !jungle_core_get_frame(wide, &result)) {
        printf("FAIL switching frame=%u machine=%u/%u renderer=%u/%u\n", frame,
               native->machine_stop, wide->machine_stop, native->renderer_stop,
               wide->renderer_stop);
        return 1;
      }
      jungle_core_take_audio(native, &audio);
      jungle_core_take_audio(wide, &audio);
      if (result.width == JUNGLE_WIDE_WIDTH)
        wide_frames++;
      else
        normal_frames++;
      if (wide->wide->console)
        console++;
      else if (wide->wide->active)
        flight++;
      frame++;
    }
    if (!jungle_core_save_snapshot(native, a, size) ||
        !jungle_core_save_snapshot(wide, b, size) || memcmp(a, b, size))
      return 1;
    snprintf(path, sizeof(path), "%s/%s.ppm", argv[4], label);
    if (!write_frame(wide, path))
      return 2;
    printf("PASS %s frame=%u switches=%u guest states identical\n", label,
           frame, switches);
    fflush(stdout);
  }
  if (!switches || !normal_frames || !wide_frames || !console || !flight)
    return 1;
  printf("PASS live switching: %u frames, %u switches, %u normal / %u wide; %u "
         "console / %u flight observations; every frame compared\n",
         frame, switches, normal_frames, wide_frames, console, flight);
  fclose(f);
  free(snapshot);
  free(a);
  free(b);
  jungle_core_destroy(native);
  jungle_core_destroy(wide);
  return 0;
}
