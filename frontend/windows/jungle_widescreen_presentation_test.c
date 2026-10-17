/* Headless audit of the production paint path. No desktop window is opened.
   Only the paint target and client rectangle are replaced by a memory DIB. */
#include <windows.h>
static HDC audit_dc;
static RECT audit_bounds;
static HDC audit_begin(HWND window, PAINTSTRUCT *paint) {
  (void)window;
  paint->hdc = audit_dc;
  return audit_dc;
}
static BOOL audit_end(HWND window, const PAINTSTRUCT *paint) {
  (void)window;
  (void)paint;
  return TRUE;
}
static BOOL audit_rect(HWND window, LPRECT rect) {
  (void)window;
  *rect = audit_bounds;
  return TRUE;
}
#define BeginPaint audit_begin
#define EndPaint audit_end
#define GetClientRect audit_rect
#define wWinMain unused_launcher_entry
#include "jungle_launcher_win32.c"
#undef wWinMain
#undef BeginPaint
#undef EndPaint
#undef GetClientRect
int main(int argc, char **argv) {
  FILE *file;
  uint8_t *rom;
  char error[512];
  unsigned mode;
  BITMAPINFO bitmap;
  HBITMAP dib;
  HGDIOBJ previous;
  uint32_t *pixels;
  if (argc != 5)
    return 2;
  file = fopen(argv[1], "rb");
  rom = malloc(JUNGLE_RECOMP_ROM_SIZE);
  if (!file || !rom ||
      fread(rom, 1, JUNGLE_RECOMP_ROM_SIZE, file) != JUNGLE_RECOMP_ROM_SIZE)
    return 2;
  fclose(file);
  if (!jungle_recomp_create(&g_game, rom, JUNGLE_RECOMP_ROM_SIZE, error,
                            sizeof(error)))
    return 2;
  free(rom);
  jungle_frontend_settings_win32_defaults(&g_frontend_settings);
  g_frontend_settings.integer_scale = 0;
  g_presentation_hidden = 1;
  g_fullscreen_active = 1;
  audit_bounds = (RECT){0, 0, 1920, 1080};
  ZeroMemory(&bitmap, sizeof(bitmap));
  bitmap.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
  bitmap.bmiHeader.biWidth = 1920;
  bitmap.bmiHeader.biHeight = -1080;
  bitmap.bmiHeader.biPlanes = 1;
  bitmap.bmiHeader.biBitCount = 32;
  audit_dc = CreateCompatibleDC(NULL);
  dib = CreateDIBSection(audit_dc, &bitmap, DIB_RGB_COLORS, (void **)&pixels,
                         NULL, 0);
  if (!audit_dc || !dib)
    return 2;
  previous = SelectObject(audit_dc, dib);
  for (mode = 0; mode < 2; mode++) {
    JungleStrikeRecompFrameResult result;
    unsigned i, fw, fh, x, y, draw_w, draw_h, ox, oy;
    const uint32_t *frame;
    wchar_t path[2048], directory[2048], label[256];
    if (!jungle_recomp_snapshot_load(g_game, argv[2], error, sizeof(error)) ||
        !jungle_recomp_set_widescreen(g_game, (int)mode, error, sizeof(error)))
      return 1;
    for (i = 0; i < 3; i++)
      if (!jungle_recomp_advance(g_game, 0, 1, &result))
        return 1;
    fw = jungle_recomp_frame_width(g_game);
    fh = jungle_recomp_frame_height(g_game);
    frame = jungle_recomp_frame_bgra(g_game);
    paint_window(NULL);
    GdiFlush();
    draw_w = fw == 256 ? 1440 : 1920;
    draw_h = fw == 256 ? 1080 : draw_w * fh / fw;
    ox = (1920 - draw_w) / 2;
    oy = (1080 - draw_h) / 2;
    for (y = 0; y < fh; y += 3)
      for (x = 0; x < fw; x += 3) {
        unsigned dx = ox + (2 * x + 1) * draw_w / (2 * fw),
                 dy = oy + (2 * y + 1) * draw_h / (2 * fh);
        if ((pixels[dy * 1920 + dx] & 0xffffffu) !=
            (frame[y * fw + x] & 0xffffffu)) {
          printf("FAIL paint sample mode=%u source=%u,%u dest=%u,%u\n", mode, x,
                 y, dx, dy);
          return 1;
        }
      }
    if (fw == 512) {
      if (fh != 288)
        return 1;
    } else if (pixels[0] & 0xffffffu)
      return 1;
    utf8_to_wide(argv[3], directory, ARRAY_COUNT(directory));
    utf8_to_wide(argv[4], label, ARRAY_COUNT(label));
    _snwprintf(path, ARRAY_COUNT(path), L"%ls/%ls-%ls-fullscreen.bmp",
               directory, label, mode ? L"wide" : L"normal");
    if (!save_bgra_bmp(path, (const uint8_t *)pixels, 1920, 1080, 1920 * 4))
      return 2;
    printf("PASS headless production fullscreen paint mode=%u frame=%ux%u "
           "canvas=1920x1080 sampled pixels identical\n",
           mode, fw, fh);
  }
  SelectObject(audit_dc, previous);
  DeleteObject(dib);
  DeleteDC(audit_dc);
  jungle_recomp_destroy(g_game);
  return 0;
}
