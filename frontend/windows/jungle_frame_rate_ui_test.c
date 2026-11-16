/* Exercise the real Settings controls without making a window visible. */
#include "jungle_frontend_settings_win32.c"
int main(void) {
    WNDCLASSW wc = {0};
    JungleStrikeFrontendSettingsWin32 target, loaded;
    wchar_t directory[MAX_PATH], path[MAX_PATH];
    int selection;
    wc.lpfnWndProc=settings_proc;wc.hInstance=GetModuleHandleW(NULL);
    wc.lpszClassName=L"JungleHiddenFrameRateSettingsTest";
    if(!RegisterClassW(&wc))return 1;
    GetTempPathW(MAX_PATH,directory);
    swprintf(path,MAX_PATH,L"%lsjungle-rate-ui-%lu.ini",directory,GetCurrentProcessId());
    jungle_frontend_settings_win32_defaults(&target);
    for(selection=0;selection<3;selection++) {
        DialogContext context={0};
        HWND window,rate;
        HDC dc;
        HGDIOBJ font;
        RECT area;
        SIZE extent;wchar_t text[128];
        target.exact_60_fps=selection==2;
        target.ntsc_frame_lock=selection!=0;
        context.value=target;context.target=&target;
        window=CreateWindowW(wc.lpszClassName,L"",WS_OVERLAPPEDWINDOW,
            0,0,560,414,NULL,NULL,wc.hInstance,&context);
        if(!window||IsWindowVisible(window))return 2;
        rate=GetDlgItem(window,ID_NTSC_FRAME_LOCK);
        if(SendMessageW(rate,BM_GETCHECK,0,0)!=(selection?BST_CHECKED:BST_UNCHECKED))return 3;
        GetClientRect(rate,&area);dc=GetDC(rate);
        font=SelectObject(dc,(HGDIOBJ)SendMessageW(rate,WM_GETFONT,0,0));
        GetWindowTextW(rate,text,128);
        if(!GetTextExtentPoint32W(dc,text,(int)wcslen(text),&extent)||
            extent.cx>area.right-24)return 4;
        SelectObject(dc,font);ReleaseDC(rate,dc);
        SendMessageW(rate,BM_SETCHECK,selection==0?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(window,WM_COMMAND,ID_APPLY,0);
        if(IsWindow(window)||!context.accepted||
            target.ntsc_frame_lock!=(selection==0)||target.exact_60_fps)return 5;
        if(!jungle_frontend_settings_win32_save(&target,path))return 6;
        jungle_frontend_settings_win32_load(&loaded,path);
        if(loaded.ntsc_frame_lock!=target.ntsc_frame_lock||
           loaded.exact_60_fps!=target.exact_60_fps)return 7;
    }
    DeleteFileW(path);
    puts("PASS hidden Settings: frame lock fits, native/unlocked Apply persists, disabling lock clears 60 FPS.");
    return 0;
}
