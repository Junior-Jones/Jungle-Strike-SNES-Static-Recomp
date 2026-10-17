/* Real paused-snapshot display regression; no scheduler steps or guest edits. */
#define main prior_verify_main
#include "verify.c"
#undef main
int main(int argc, char **argv) {
  FILE *file;
  uint8_t *rom;
  void *snapshot, *before, *after;
  JungleStaticCore *native, *wide;
  JungleCoreFrame frame;
  size_t size;
  char path[2048];
  if (argc != 4) return 2;
  output_directory = argv[3];
  rom = (uint8_t *)malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  file = fopen(argv[1], "rb");
  if (!file || !rom || fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, file) !=
      JUNGLE_STATIC_CORE_ROM_SIZE) return 2;
  fclose(file);
  native = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  wide = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!native || !wide) return 2;
  size = jungle_core_snapshot_size(native);
  snapshot = malloc(size); before = malloc(size); after = malloc(size);
  file = fopen(argv[2], "rb");
  if (!file || !snapshot || !before || !after ||
      fread(snapshot, 1, size, file) != size) return 2;
  fclose(file);
  if (!jungle_core_load_snapshot(native, snapshot, size) ||
      !jungle_core_save_snapshot(native, before, size) ||
      !jungle_core_set_widescreen(wide, 1) ||
      !jungle_core_load_snapshot(wide, snapshot, size) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 512u ||
      frame.height != 288u || !compare_frame(native, wide) ||
      !jungle_core_save_snapshot(wide, after, size) || memcmp(before, after, size))
    return 1;
  snprintf(path, sizeof(path), "%s/paused-native.ppm", argv[3]);
  if (!write_frame(native, path)) return 2;
  snprintf(path, sizeof(path), "%s/paused-wide.ppm", argv[3]);
  if (!write_frame(wide, path)) return 2;
  if (!jungle_core_set_widescreen(wide, 0) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 256u ||
      memcmp(frame.bgra_pixels, native->frame_bgra, sizeof(native->frame_bgra)) ||
      !jungle_core_set_widescreen(wide, 1) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 512u ||
      !compare_frame(native, wide) ||
      !jungle_core_save_snapshot(wide, after, size) || memcmp(before, after, size))
    return 1;
  printf("PASS paused snapshot load and mode switching: immediate 512x288; "
         "native crop/HUD/console preserved; guest snapshot bytes identical; "
         "zero emulated frames advanced\n");
  /* A headless step deliberately leaves the last rendered native image in
     place. Never combine that image with a newer scene on load or enable. */
  if (!jungle_core_run_frame_headless(native, 0, 0) ||
      !jungle_core_run_frame_headless(wide, 0, 0) ||
      !jungle_core_save_snapshot(native, snapshot, size) ||
      !jungle_core_load_snapshot(wide, snapshot, size) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 256u ||
      memcmp(frame.bgra_pixels, native->frame_bgra, sizeof(native->frame_bgra)) ||
      !jungle_core_set_widescreen(wide, 0) ||
      !jungle_core_set_widescreen(wide, 1) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 256u ||
      !jungle_core_save_snapshot(native, before, size) ||
      !jungle_core_save_snapshot(wide, after, size) || memcmp(before, after, size))
    return 1;
  if (!jungle_core_run_frame(native, 0, 0) ||
      !jungle_core_run_frame(wide, 0, 0) ||
      !jungle_core_get_frame(wide, &frame) || frame.width != 512u ||
      !compare_frame(native, wide) ||
      !jungle_core_save_snapshot(native, before, size) ||
      !jungle_core_save_snapshot(wide, after, size) || memcmp(before, after, size))
    return 1;
  puts("PASS stale headless snapshots: no mixed-scene restoration; load/enable preserve guest bytes; next rendered frame resynchronizes to 512x288");
  free(snapshot); free(before); free(after);
  jungle_core_destroy(native); jungle_core_destroy(wide);
  return 0;
}
