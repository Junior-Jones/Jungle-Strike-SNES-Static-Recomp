/* Exercise the real Win32 command handlers in a hidden window. */
#define wWinMain jungle_launcher_entry
#include "jungle_launcher_win32.c"
#undef wWinMain
static int capture_notice(const char *directory) {
  RECT area;
  BITMAPINFO bmi;
  uint32_t *pixels;
  HDC dc = CreateCompatibleDC(NULL);
  HBITMAP bitmap;
  HGDIOBJ previous;
  HWND child;
  wchar_t output[PATH_CAPACITY], path[PATH_CAPACITY];
  int ok;
  GetClientRect(g_info_window, &area);
  ZeroMemory(&bmi, sizeof(bmi));
  bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
  bmi.bmiHeader.biWidth = area.right;
  bmi.bmiHeader.biHeight = -area.bottom;
  bmi.bmiHeader.biPlanes = 1;
  bmi.bmiHeader.biBitCount = 32;
  bitmap = CreateDIBSection(dc, &bmi, DIB_RGB_COLORS, (void **)&pixels, NULL, 0);
  if (!bitmap) return 0;
  previous = SelectObject(dc, bitmap);
  FillRect(dc, &area, (HBRUSH)(COLOR_WINDOW + 1));
  for (child = GetWindow(g_info_window, GW_CHILD); child;
       child = GetWindow(child, GW_HWNDNEXT)) {
    RECT bounds;
    GetWindowRect(child, &bounds);
    MapWindowPoints(NULL, g_info_window, (POINT *)&bounds, 2);
    SetViewportOrgEx(dc, bounds.left, bounds.top, NULL);
    SendMessageW(child, WM_PRINT, (WPARAM)dc,
                 PRF_CLIENT | PRF_NONCLIENT | PRF_CHILDREN);
  }
  SetViewportOrgEx(dc, 0, 0, NULL);
  GdiFlush();
  utf8_to_wide(directory, output, ARRAY_COUNT(output));
  join_wide_path(path, ARRAY_COUNT(path), output, L"notice-client.bmp");
  ok = save_bgra_bmp(path, (const uint8_t *)pixels, area.right, area.bottom, area.right * 4);
  SelectObject(dc, previous);
  DeleteObject(bitmap);
  DeleteDC(dc);
  return ok;
}
int main(int argc, char **argv) {
  WNDCLASSEXW wc;
  JungleStrikeFrontendSettingsWin32 loaded;
  wchar_t directory[MAX_PATH];
  RECT checkbox, client;
  MINMAXINFO minimum;
  g_instance = GetModuleHandleW(NULL);
  jungle_frontend_settings_win32_defaults(&g_frontend_settings);
  GetTempPathW(MAX_PATH, directory);
  swprintf(g_settings_ini_path, ARRAY_COUNT(g_settings_ini_path),
           L"%lsjungle-widescreen-ui-%lu.ini", directory,
           GetCurrentProcessId());
  ZeroMemory(&wc, sizeof(wc));
  wc.cbSize = sizeof(wc);
  wc.lpfnWndProc = window_proc;
  wc.hInstance = g_instance;
  wc.lpszClassName = L"JungleWideHiddenTest";
  if (!RegisterClassExW(&wc))
    return 1;
  wc.lpfnWndProc = info_dialog_proc;
  wc.lpszClassName = INFO_CLASS_NAME;
  if (!RegisterClassExW(&wc)) return 17;
  g_menu = create_menu_bar();
  g_window = CreateWindowExW(0, L"JungleWideHiddenTest", L"Headless verification",
                             WS_OVERLAPPEDWINDOW, 0, 0, 1024, 768, NULL, g_menu,
                             g_instance, NULL);
  if (!g_window || IsWindowVisible(g_window) ||
      !IsWindow(g_widescreen_checkbox))
    return 2;
  SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
  if (!g_frontend_settings.widescreen ||
      SendMessageW(g_widescreen_checkbox, BM_GETCHECK, 0, 0) != BST_CHECKED ||
      !(GetMenuState(g_menu, ID_WIDESCREEN, MF_BYCOMMAND) & MF_CHECKED))
    return 3;
  jungle_frontend_settings_win32_load(&loaded, g_settings_ini_path);
  if (!loaded.widescreen || !loaded.widescreen_notice_shown ||
      !IsWindow(g_info_window) || IsWindowVisible(g_info_window))
    return 4;
  {
    wchar_t title[64], body[256];
    RECT text, button, notice_client, required;
    HDC dc = GetDC(g_info_state.text);
    HFONT font = (HFONT)SendMessageW(g_info_state.text, WM_GETFONT, 0, 0);
    HGDIOBJ previous = font ? SelectObject(dc, font) : NULL;
    GetWindowTextW(g_info_window, title, ARRAY_COUNT(title));
    GetWindowTextW(g_info_state.text, body, ARRAY_COUNT(body));
    if (wcscmp(title, L"Notice") || wcscmp(body,
        L"Wide Screen is experimental, you may or may not encounter issues.\r\n\r\n"
        L"If any occur then feedback is welcomed.")) return 18;
    GetClientRect(g_info_state.text, &text);
    required = (RECT){0, 0, text.right - 8, 0};
    DrawTextW(dc, body, -1, &required, DT_CALCRECT | DT_WORDBREAK | DT_NOPREFIX);
    if (previous) SelectObject(dc, previous);
    ReleaseDC(g_info_state.text, dc);
    if (required.bottom > text.bottom - 4) return 19;
    GetWindowRect(g_info_state.close_button, &button);
    MapWindowPoints(NULL, g_info_window, (POINT *)&button, 2);
    GetClientRect(g_info_window, &notice_client);
    if (button.bottom > notice_client.bottom || notice_client.bottom - button.bottom != 16)
      return 20;
    if (LOWORD(SendMessageW(g_info_window, DM_GETDEFID, 0, 0)) != ID_INFO_CLOSE)
      return 25;
    if (argc == 4 && !capture_notice(argv[3])) return 26;
    SendMessageW(g_info_window, WM_COMMAND, ID_INFO_CLOSE, 0);
    if (IsWindow(g_info_window)) return 21;
  }
  SendMessageW(g_widescreen_checkbox, BM_SETCHECK, BST_UNCHECKED, 0);
  SendMessageW(g_window, WM_COMMAND, MAKEWPARAM(ID_WIDESCREEN, BN_CLICKED),
               (LPARAM)g_widescreen_checkbox);
  if (g_frontend_settings.widescreen ||
      (GetMenuState(g_menu, ID_WIDESCREEN, MF_BYCOMMAND) & MF_CHECKED))
    return 5;
  if (IsWindow(g_info_window)) return 22;
  /* A fresh configuration must work from the checkbox too. */
  g_frontend_settings.widescreen_notice_shown = 0;
  SendMessageW(g_widescreen_checkbox, BM_SETCHECK, BST_CHECKED, 0);
  SendMessageW(g_window, WM_COMMAND, MAKEWPARAM(ID_WIDESCREEN, BN_CLICKED),
               (LPARAM)g_widescreen_checkbox);
  if (!IsWindow(g_info_window)) return 23;
  SendMessageW(g_info_window, WM_COMMAND, ID_INFO_CLOSE, 0);
  jungle_frontend_settings_win32_load(&g_frontend_settings, g_settings_ini_path);
  SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
  SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
  if (IsWindow(g_info_window) || !g_frontend_settings.widescreen_notice_shown)
    return 24;
  SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
  puts("PASS one-time Notice: menu and checkbox, fitted text, bottom Close button, persisted dismissal after reload");
  /* The new option uses the actual shared menu/checkbox command handler. */
  if(g_frontend_settings.experimental_60fps||g_frontend_settings.fps60_notice_shown)
    return 40;
  SendMessageW(g_window,WM_COMMAND,ID_EXPERIMENTAL_60FPS,0);
  jungle_frontend_settings_win32_load(&loaded,g_settings_ini_path);
  if(!loaded.experimental_60fps||!loaded.fps60_notice_shown||
     !IsWindow(g_info_window)||IsWindowVisible(g_info_window)||
     SendMessageW(g_fps60_checkbox,BM_GETCHECK,0,0)!=BST_CHECKED||
     !(GetMenuState(g_menu,ID_EXPERIMENTAL_60FPS,MF_BYCOMMAND)&MF_CHECKED))return 41;
  {
    wchar_t title[64],body[256];RECT text,required,button,notice_client;
    HDC dc=GetDC(g_info_state.text);
    HFONT font=(HFONT)SendMessageW(g_info_state.text,WM_GETFONT,0,0);
    HGDIOBJ previous=font?SelectObject(dc,font):NULL;
    GetWindowTextW(g_info_window,title,ARRAY_COUNT(title));
    GetWindowTextW(g_info_state.text,body,ARRAY_COUNT(body));
    if(wcscmp(title,L"Notice")||wcscmp(body,
        L"This is an experimental 60FPS, any issues you find please give feedback"))return 42;
    GetClientRect(g_info_state.text,&text);required=(RECT){0,0,text.right-8,0};
    DrawTextW(dc,body,-1,&required,DT_CALCRECT|DT_WORDBREAK|DT_NOPREFIX);
    if(previous)SelectObject(dc,previous);ReleaseDC(g_info_state.text,dc);
    if(required.bottom>text.bottom-4)return 43;
    GetWindowRect(g_info_state.close_button,&button);
    MapWindowPoints(NULL,g_info_window,(POINT*)&button,2);GetClientRect(g_info_window,&notice_client);
    if(button.bottom>notice_client.bottom||notice_client.bottom-button.bottom!=16)return 44;
    if(argc==4&&!capture_notice(argv[3]))return 45;
  }
  SendMessageW(g_info_window,WM_COMMAND,ID_INFO_CLOSE,0);
  if(IsWindow(g_info_window))return 46;
  SendMessageW(g_fps60_checkbox,BM_SETCHECK,BST_UNCHECKED,0);
  SendMessageW(g_window,WM_COMMAND,MAKEWPARAM(ID_EXPERIMENTAL_60FPS,BN_CLICKED),(LPARAM)g_fps60_checkbox);
  if(g_frontend_settings.experimental_60fps||IsWindow(g_info_window)||
     (GetMenuState(g_menu,ID_EXPERIMENTAL_60FPS,MF_BYCOMMAND)&MF_CHECKED))return 47;
  jungle_frontend_settings_win32_load(&g_frontend_settings,g_settings_ini_path);
  SendMessageW(g_window,WM_COMMAND,ID_EXPERIMENTAL_60FPS,0);
  if(!g_frontend_settings.experimental_60fps||IsWindow(g_info_window))return 48;
  /* A fresh config must also show the notice when checked from the toolbar. */
  g_frontend_settings.experimental_60fps=0;g_frontend_settings.fps60_notice_shown=0;
  SendMessageW(g_fps60_checkbox,BM_SETCHECK,BST_CHECKED,0);
  SendMessageW(g_window,WM_COMMAND,MAKEWPARAM(ID_EXPERIMENTAL_60FPS,BN_CLICKED),(LPARAM)g_fps60_checkbox);
  if(!IsWindow(g_info_window))return 49;
  SendMessageW(g_info_window,WM_COMMAND,ID_INFO_CLOSE,0);
  if(IsWindow(g_window)&&IsWindowVisible(g_window))return 50;
  puts("PASS 60 FPS: default off, shared menu/checkbox, fitted one-time Notice, bottom Close, config persistence");
  ZeroMemory(&minimum, sizeof(minimum));
  SendMessageW(g_window, WM_GETMINMAXINFO, 0, (LPARAM)&minimum);
  SetWindowPos(g_window, NULL, 0, 0, minimum.ptMinTrackSize.x,
               minimum.ptMinTrackSize.y, SWP_NOZORDER | SWP_NOMOVE);
  GetClientRect(g_window, &client);
  GetWindowRect(g_widescreen_checkbox, &checkbox);
  MapWindowPoints(NULL, g_window, (POINT *)&checkbox, 2);
  if (checkbox.right > client.right)
    return 6;
  GetWindowRect(g_fps60_checkbox,&checkbox);
  MapWindowPoints(NULL,g_window,(POINT*)&checkbox,2);
  if(checkbox.right>client.right)return 51;
  if (argc == 4) {
    FILE *file = fopen(argv[1], "rb");
    uint8_t *rom = malloc(JUNGLE_RECOMP_ROM_SIZE);
    char error[512];
    wchar_t output[PATH_CAPACITY], saved[PATH_CAPACITY];
    JungleStrikeRecompFrameResult result;
    BITMAPFILEHEADER header;
    BITMAPINFOHEADER info;
    if (!file || !rom ||
        fread(rom, 1, JUNGLE_RECOMP_ROM_SIZE, file) != JUNGLE_RECOMP_ROM_SIZE)
      return 7;
    fclose(file);
    if (!jungle_recomp_create(&g_game, rom, JUNGLE_RECOMP_ROM_SIZE, error,
                              sizeof(error)))
      return 8;
    free(rom);
    update_controls();
    if(IsWindowEnabled(g_fps60_checkbox)||
       !(GetMenuState(g_menu,ID_EXPERIMENTAL_60FPS,MF_BYCOMMAND)&MF_GRAYED))return 52;
    SendMessageW(g_window,WM_COMMAND,ID_EXPERIMENTAL_60FPS,0);
    if(!g_frontend_settings.experimental_60fps)return 53;
    if(!jungle_recomp_set_experimental_60fps(g_game,1,error,sizeof(error))||
       !jungle_recomp_experimental_60fps_enabled(g_game))return 54;
    if (!jungle_recomp_snapshot_load(g_game, argv[2], error, sizeof(error)))
      return 9;
    SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
    if (jungle_recomp_frame_width(g_game) != 512 ||
        jungle_recomp_frame_height(g_game) != 288) return 27;
    if (!jungle_recomp_widescreen_enabled(g_game) ||
        !jungle_recomp_advance(g_game, 0, 1, &result) ||
        jungle_recomp_frame_width(g_game) != 512 ||
        jungle_recomp_frame_height(g_game) != 288)
      return 10;
    /* Loading while paused must restore the display without a Play/frame call. */
    if (!jungle_recomp_snapshot_load(g_game, argv[2], error, sizeof(error)) ||
        jungle_recomp_frame_width(g_game) != 512 ||
        jungle_recomp_frame_height(g_game) != 288) return 28;
    utf8_to_wide(argv[3], output, ARRAY_COUNT(output));
    if (!capture_core_screenshot_to(output, saved, ARRAY_COUNT(saved)))
      return 11;
    file = _wfopen(saved, L"rb");
    if (!file || fread(&header, 1, sizeof(header), file) != sizeof(header) ||
        fread(&info, 1, sizeof(info), file) != sizeof(info))
      return 12;
    fclose(file);
    if (info.biWidth != 512 || abs(info.biHeight) != 288)
      return 13;
    {
      HDC screen = GetDC(NULL), memory = CreateCompatibleDC(screen);
      HBITMAP bitmap = CreateCompatibleBitmap(screen, 1024, 100);
      HGDIOBJ previous = SelectObject(memory, bitmap);
      uint8_t pixels[1024 * 100 * 4];
      BITMAPINFO bmi;
      HWND child;
      RECT area = {0, 0, 1024, 100};
      FillRect(memory, &area, (HBRUSH)(COLOR_BTNFACE + 1));
      for (child = GetWindow(g_window, GW_CHILD); child;
           child = GetWindow(child, GW_HWNDNEXT)) {
        RECT bounds;
        if (!(GetWindowLongW(child, GWL_STYLE) & WS_VISIBLE))
          continue;
        GetWindowRect(child, &bounds);
        MapWindowPoints(NULL, g_window, (POINT *)&bounds, 2);
        SetViewportOrgEx(memory, bounds.left, bounds.top, NULL);
        SendMessageW(child, WM_PRINT, (WPARAM)memory,
                     PRF_CLIENT | PRF_NONCLIENT | PRF_CHILDREN);
      }
      SetViewportOrgEx(memory, 0, 0, NULL);
      SelectObject(memory, previous);
      ZeroMemory(&bmi, sizeof(bmi));
      bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
      bmi.bmiHeader.biWidth = 1024;
      bmi.bmiHeader.biHeight = -100;
      bmi.bmiHeader.biPlanes = 1;
      bmi.bmiHeader.biBitCount = 32;
      if (!GetDIBits(memory, bitmap, 0, 100, pixels, &bmi, DIB_RGB_COLORS))
        return 15;
      join_wide_path(saved, ARRAY_COUNT(saved), output, L"toolbar.bmp");
      if (!save_bgra_bmp(saved, pixels, 1024, 100, 4096))
        return 16;
      DeleteObject(bitmap);
      DeleteDC(memory);
      ReleaseDC(NULL, screen);
    }
    SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
    if (jungle_recomp_widescreen_enabled(g_game) ||
        jungle_recomp_frame_width(g_game) != 256)
      return 14;
    jungle_recomp_destroy(g_game);
    g_game = NULL;
    puts("PASS frontend core mode switching and 512x288 screenshot export");
  }
  DestroyWindow(g_window);
  DeleteFileW(g_settings_ini_path);
  puts("PASS hidden frontend: toolbar/menu synchronization, persistence, "
       "minimum-width layout");
  return 0;
}
