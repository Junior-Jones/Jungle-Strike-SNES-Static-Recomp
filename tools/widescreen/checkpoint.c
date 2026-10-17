/* Generate a checkpoint by replaying a natural password/input route. */
#include "jungle/jungle_static_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  unsigned first[256], last[256], mask[256], count = 0, frame, k, a, b, m;
  char line[256];
  FILE *f;
  uint8_t *rom;
  JungleStaticCore *c;
  JungleCoreAudio audio;
  size_t size;
  void *data;
  if (argc != 4)
    return 2;
  f = fopen(argv[1], "rb");
  rom = malloc(JUNGLE_STATIC_CORE_ROM_SIZE);
  if (!f || !rom ||
      fread(rom, 1, JUNGLE_STATIC_CORE_ROM_SIZE, f) !=
          JUNGLE_STATIC_CORE_ROM_SIZE)
    return 2;
  fclose(f);
  c = jungle_core_create(rom, JUNGLE_STATIC_CORE_ROM_SIZE);
  free(rom);
  if (!c)
    return 2;
  if (strstr(argv[2], ".snapshot")) {
    size = jungle_core_snapshot_size(c);
    data = malloc(size);
    f = fopen(argv[2], "rb");
    if (!f || !data || fread(data, 1, size, f) != size ||
        !jungle_core_load_snapshot(c, data, size))
      return 2;
    fclose(f);
    free(data);
    for (frame = 0; frame < 240; frame++) {
      if (!jungle_core_run_frame(c, frame < 3 ? JUNGLE_BUTTON_SELECT : 0, 0))
        return 1;
      jungle_core_take_audio(c, &audio);
    }
    goto save;
  }
  f = fopen(argv[2], "r");
  if (!f)
    return 2;
  while (fgets(line, sizeof(line), f))
    if (sscanf(line, "%u %u %x", &a, &b, &m) == 3) {
      if (count >= 256)
        return 2;
      first[count] = a;
      last[count] = b;
      mask[count++] = m;
    }
  fclose(f);
  for (frame = 0; frame < 9000; frame++) {
    uint16_t input = 0;
    for (k = 0; k < count; k++)
      if (frame >= first[k] && frame <= last[k])
        input |= (uint16_t)mask[k];
    if (!(frame < 8900 ? jungle_core_run_frame_headless(c, input, 0)
                       : jungle_core_run_frame(c, input, 0))) {
      fprintf(stderr, "FAIL frame %u\n", frame);
      return 1;
    }
    jungle_core_take_audio(c, &audio);
  }
save:
  size = jungle_core_snapshot_size(c);
  data = malloc(size);
  if (!data || !jungle_core_save_snapshot(c, data, size))
    return 2;
  f = fopen(argv[3], "wb");
  if (!f || fwrite(data, 1, size, f) != size)
    return 2;
  fclose(f);
  free(data);
  jungle_core_destroy(c);
  printf("PASS checkpoint %s natural frames=9000\n", argv[3]);
  return 0;
}
