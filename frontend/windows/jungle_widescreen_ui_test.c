/* Exercise the real Win32 command handlers in a hidden window. */
#define wWinMain jungle_launcher_entry
#include "jungle_launcher_win32.c"
#undef wWinMain
static int capture_notice(const char *directory, const wchar_t *filename) {
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
  join_wide_path(path, ARRAY_COUNT(path), output, filename);
  ok = save_bgra_bmp(path, (const uint8_t *)pixels, area.right, area.bottom, area.right * 4);
  SelectObject(dc, previous);
  DeleteObject(bitmap);
  DeleteDC(dc);
  return ok;
}

static int check_fps60_controls(int argc,char **argv) {
  unsigned origin;
  JungleStrikeFrontendSettingsWin32 loaded;
  QueryPerformanceFrequency(&g_qpc_frequency);
  if(g_frontend_settings.exact_60_fps||
     SendMessageW(g_fps60_checkbox,BM_GETCHECK,0,0)!=BST_UNCHECKED||
     (GetMenuState(g_menu,ID_FPS60,MF_BYCOMMAND)&MF_CHECKED))return 30;
  for(origin=0;origin<2;origin++) {
    wchar_t title[64],body[256],label[32];
    RECT text,button,client,required;
    HDC dc;HGDIOBJ font;
    g_frontend_settings.exact_60_fps=0;
    g_frontend_settings.fps60_notice_shown=0;
    update_controls();
    if(origin)SendMessageW(g_fps60_checkbox,BM_CLICK,0,0);
    else SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
    if(!g_frontend_settings.exact_60_fps||!g_frontend_settings.ntsc_frame_lock||
       !g_frontend_settings.fps60_notice_shown||g_frame_clock.numerator!=60u||
       SendMessageW(g_fps60_checkbox,BM_GETCHECK,0,0)!=BST_CHECKED||
       !(GetMenuState(g_menu,ID_FPS60,MF_BYCOMMAND)&MF_CHECKED)||
       !IsWindow(g_info_window)||IsWindowVisible(g_info_window))return 31;
    GetWindowTextW(g_info_window,title,64);GetWindowTextW(g_info_state.text,body,256);
    if(wcscmp(title,L"Notice")||wcscmp(body,
        L"This is an experimental 60FPS, any issues you find please give feedback"))return 32;
    dc=GetDC(g_info_state.text);
    font=SelectObject(dc,(HGDIOBJ)SendMessageW(g_info_state.text,WM_GETFONT,0,0));
    GetClientRect(g_info_state.text,&text);required=(RECT){0,0,text.right-8,0};
    DrawTextW(dc,body,-1,&required,DT_CALCRECT|DT_WORDBREAK|DT_NOPREFIX);
    SelectObject(dc,font);ReleaseDC(g_info_state.text,dc);
    if(required.bottom>text.bottom-4)return 33;
    GetWindowRect(g_info_state.close_button,&button);
    MapWindowPoints(NULL,g_info_window,(POINT*)&button,2);
    GetClientRect(g_info_window,&client);
    GetWindowTextW(g_info_state.close_button,label,32);
    if(wcscmp(label,L"&Close")||client.bottom-button.bottom!=16||button.top<text.bottom+16)return 34;
    if(argc==4&&!capture_notice(argv[3],L"fps60-notice.bmp"))return 35;
    SendMessageW(g_info_state.close_button,BM_CLICK,0,0);
    if(IsWindow(g_info_window))return 36;
    jungle_frontend_settings_win32_load(&loaded,g_settings_ini_path);
    if(!loaded.exact_60_fps||!loaded.fps60_notice_shown||!loaded.widescreen_notice_shown)return 37;
    SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
    if(g_frontend_settings.exact_60_fps||g_frame_clock.numerator!=JUNGLE_NATIVE_FPS_NUMERATOR||
       (GetMenuState(g_menu,ID_FPS60,MF_BYCOMMAND)&MF_CHECKED)||IsWindow(g_info_window))return 38;
    jungle_frontend_settings_win32_load(&g_frontend_settings,g_settings_ini_path);
    update_controls();SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
    if(!g_frontend_settings.exact_60_fps||IsWindow(g_info_window))return 39;
    SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
  }
  InterlockedExchange(&g_loading,1);
  SendMessageW(g_fps60_checkbox,BM_CLICK,0,0);
  SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
  InterlockedExchange(&g_loading,0);update_controls();
  if(g_frontend_settings.exact_60_fps||SendMessageW(g_fps60_checkbox,BM_GETCHECK,0,0)!=BST_UNCHECKED)return 40;
  puts("PASS 60 FPS: off by default, checkbox/menu sync, exact Notice text fits, bottom Close, once per config across reload, clock switch, loading guard");
  return 0;
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
    if (argc == 4 && !capture_notice(argv[3],L"notice-client.bmp")) return 26;
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
  {int result=check_fps60_controls(argc,argv);if(result)return result;}
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
  if(checkbox.right>client.right)return 41;
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
    if (!jungle_recomp_snapshot_load(g_game, argv[2], error, sizeof(error)))
      return 9;
    {uint32_t before=jungle_recomp_current_frame(g_game);
     SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
     if(g_frame_clock.numerator!=60u||g_audio_output.source_rate_hz>=32040.0||
        jungle_recomp_current_frame(g_game)!=before)return 42;
     SendMessageW(g_window,WM_COMMAND,ID_FPS60,0);
     if(g_frame_clock.numerator!=JUNGLE_NATIVE_FPS_NUMERATOR||g_audio_output.source_rate_hz!=32040.0||
        jungle_recomp_current_frame(g_game)!=before)return 43;}
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
