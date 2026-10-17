#include "jungle_frontend_settings_win32.h"
#include "jungle_app_core.h"
#include <stdio.h>
#include <string.h>

#define SETTINGS_CLASS L"JungleStrikeFrontendSettings"
#define CONTROLS_CLASS L"JungleStrikeControls"
#define ID_SCALE 3101
#define ID_PAUSE_FOCUS 3102
#define ID_AUTO_RUN 3103
#define ID_SHOW_STATUS 3104
#define ID_SLOT 3105
#define ID_ACCESSIBLE 3106
#define ID_CLASSIC 3107
#define ID_APPLY 3108
#define ID_CANCEL 3109
#define ID_FULLSCREEN_SETTING 3110
#define ID_FPS_COUNTER 3111
#define ID_NTSC_FRAME_LOCK 3112
#define ID_CONTROL_BASE 3200
#define ID_INPUT_SOURCE 3300
#define ID_CONTROLS_ACCESSIBLE 3301
#define ID_CONTROLS_CLASSIC 3302
#define ID_CONTROLS_GAMEPAD_DEFAULTS 3303
#define ID_CONTROLS_APPLY 3304
#define ID_CONTROLS_CANCEL 3305
#define ID_CONTROLLER_STATUS 3306
#define ID_GAMEPAD_CHANGE_BASE 3400
#define ID_GAMEPAD_CAPTURE_TIMER 1
#define WM_CANCEL_GAMEPAD_CAPTURE (WM_APP + 41)
#define WM_CANCEL_KEYBOARD_CAPTURE (WM_APP + 42)
#define WM_COMPLETE_KEYBOARD_CAPTURE (WM_APP + 43)

typedef struct DialogContext {
    JungleStrikeFrontendSettingsWin32 value;
    JungleStrikeFrontendSettingsWin32 *target;
    int accepted;
    HWND parent;
    HWND controls[JUNGLE_WIN_BINDING_COUNT];
    HWND gamepad_assignments[JUNGLE_WIN_BINDING_COUNT];
    HWND gamepad_changes[JUNGLE_WIN_BINDING_COUNT];
    HWND source;
    HWND controller_status;
    HWND assigned_header;
    HWND change_header;
    HWND keyboard_help_group;
    HWND keyboard_help_text;
    HWND gamepad_help_group;
    HWND gamepad_help_text;
    HWND accessible_defaults;
    HWND classic_defaults;
    HWND gamepad_defaults;
    JungleStrikeGamepadInputWin32 *gamepad;
    int capture_action;
    int capture_wait_for_neutral;
    int keyboard_capture_action;
} DialogContext;

static void set_font(HWND h) {
    SendMessageW(h, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
}

static void center_dialog(HWND w,HWND parent){
    RECT wr,pr;MONITORINFO mi;HMONITOR monitor;int width,height,x,y;
    if(!w||!GetWindowRect(w,&wr))return;
    if(!parent||!IsWindow(parent)||!GetWindowRect(parent,&pr)){
        pr.left=0;pr.top=0;pr.right=GetSystemMetrics(SM_CXSCREEN);pr.bottom=GetSystemMetrics(SM_CYSCREEN);
    }
    width=wr.right-wr.left;height=wr.bottom-wr.top;
    x=pr.left+((pr.right-pr.left)-width)/2;y=pr.top+((pr.bottom-pr.top)-height)/2;
    monitor=MonitorFromWindow(parent?parent:w,MONITOR_DEFAULTTONEAREST);
    memset(&mi,0,sizeof(mi));mi.cbSize=sizeof(mi);
    if(GetMonitorInfoW(monitor,&mi)){
        if(x<mi.rcWork.left)x=mi.rcWork.left;
        if(y<mi.rcWork.top)y=mi.rcWork.top;
        if(x+width>mi.rcWork.right)x=mi.rcWork.right-width;
        if(y+height>mi.rcWork.bottom)y=mi.rcWork.bottom-height;
    }
    SetWindowPos(w,NULL,x,y,0,0,SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE);
}

static int keyboard_key_is_reserved(UINT key){
    return key==VK_ESCAPE||key==VK_F1||(key>=VK_F4&&key<=VK_F8);
}

static int keyboard_bindings_are_valid(
    const UINT bindings[JUNGLE_WIN_BINDING_COUNT]){
    int first;int second;
    if(!bindings)return 0;
    for(first=0;first<JUNGLE_WIN_BINDING_COUNT;first++){
        if(bindings[first]==0u||bindings[first]>0xfeu||
           keyboard_key_is_reserved(bindings[first]))return 0;
        for(second=first+1;second<JUNGLE_WIN_BINDING_COUNT;second++)
            if(bindings[first]==bindings[second])return 0;
    }
    return 1;
}

void jungle_frontend_settings_win32_defaults(JungleStrikeFrontendSettingsWin32 *s) {
    if (!s) return;
    memset(s, 0, sizeof(*s));
    s->pause_on_focus_loss = 0;
    s->ntsc_frame_lock = 1;
    s->widescreen = 0;
    s->snapshot_slot = 1;
    s->input_source = JUNGLE_INPUT_SOURCE_KEYBOARD;
    s->bindings[0]=VK_UP; s->bindings[1]=VK_DOWN;
    s->bindings[2]=VK_LEFT; s->bindings[3]=VK_RIGHT;
    s->bindings[4]='D'; s->bindings[5]='F'; s->bindings[6]='A'; s->bindings[7]='S';
    s->bindings[8]='E'; s->bindings[9]='R'; s->bindings[10]='G'; s->bindings[11]='T';
    jungle_gamepad_win32_default_bindings(s->gamepad_bindings);
}

void jungle_frontend_settings_win32_classic(JungleStrikeFrontendSettingsWin32 *s) {
    if (!s) return;
    jungle_frontend_settings_win32_defaults(s);
    s->bindings[4]='Z'; s->bindings[5]='X'; s->bindings[6]='A'; s->bindings[7]='S';
    s->bindings[10]=VK_RETURN; s->bindings[11]=VK_SPACE;
}

void jungle_frontend_settings_win32_load(JungleStrikeFrontendSettingsWin32 *s,
                                          const wchar_t *path) {
    int i;
    int invalid_gamepad_binding=0;
    int source;
    wchar_t key[32];
    if (!s) return;
    jungle_frontend_settings_win32_defaults(s);
    if (!path || !*path) return;
    s->integer_scale=GetPrivateProfileIntW(L"General",L"IntegerScale",0,path);
    s->pause_on_focus_loss=GetPrivateProfileIntW(L"General",L"PauseOnFocusLoss",0,path)!=0;
    s->auto_run_on_load=GetPrivateProfileIntW(L"General",L"AutoRunOnLoad",0,path)!=0;
    s->fullscreen_on_play=GetPrivateProfileIntW(
        L"General",L"FullScreenOnPlay",0,path)!=0;
    s->show_fps_counter=GetPrivateProfileIntW(
        L"General",L"ShowFpsCounter",0,path)!=0;
    s->ntsc_frame_lock=GetPrivateProfileIntW(
        L"General",L"NtscFrameLock",1,path)!=0;
    s->widescreen=GetPrivateProfileIntW(L"Display",L"Widescreen",0,path)!=0;
    s->widescreen_notice_shown=GetPrivateProfileIntW(
        L"Display",L"WidescreenNoticeShown",0,path)!=0;
    s->snapshot_slot=GetPrivateProfileIntW(
        L"General",L"SnapshotSlot",1,path);
    s->welcome_shown=GetPrivateProfileIntW(
        L"General",L"WelcomeShown",
        GetPrivateProfileIntW(L"General",L"GettingStartedShown",0,path),
        path)!=0;
    source=GetPrivateProfileIntW(L"Input",L"Source",-1,path);
    if(source==JUNGLE_INPUT_SOURCE_KEYBOARD||source==JUNGLE_INPUT_SOURCE_GAMEPAD){
        s->input_source=source;s->input_source_saved=1;
    }
    if(s->integer_scale<0||s->integer_scale>4)s->integer_scale=0;
    if(s->snapshot_slot<1||s->snapshot_slot>5)s->snapshot_slot=1;
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++){
        _snwprintf_s(key,32,_TRUNCATE,L"Action%d",i);
        s->bindings[i]=(UINT)GetPrivateProfileIntW(L"Input",key,(int)s->bindings[i],path);
        _snwprintf_s(key,32,_TRUNCATE,L"GamepadAction%d",i);
        s->gamepad_bindings[i]=GetPrivateProfileIntW(
            L"Input",key,s->gamepad_bindings[i],path);
        if(s->gamepad_bindings[i]<JUNGLE_GAMEPAD_DPAD_UP||
           s->gamepad_bindings[i]>JUNGLE_GAMEPAD_CONTROL_LAST)
            invalid_gamepad_binding=1;
    }
    if(!keyboard_bindings_are_valid(s->bindings)){
        JungleStrikeFrontendSettingsWin32 defaults;
        jungle_frontend_settings_win32_defaults(&defaults);
        memcpy(s->bindings,defaults.bindings,sizeof(s->bindings));
    }
    if(invalid_gamepad_binding)
        jungle_gamepad_win32_default_bindings(s->gamepad_bindings);
}

static int write_int(const wchar_t *section,const wchar_t *key,int value,const wchar_t *path){
    wchar_t text[32]; _snwprintf_s(text,32,_TRUNCATE,L"%d",value);
    return WritePrivateProfileStringW(section,key,text,path)!=0;
}
int jungle_frontend_settings_win32_save(const JungleStrikeFrontendSettingsWin32 *s,
                                         const wchar_t *path) {
    int i,ok=1; wchar_t key[32];
    if(!s||!path||!*path)return 0;
    ok&=write_int(L"General",L"IntegerScale",s->integer_scale,path);
    ok&=write_int(L"General",L"PauseOnFocusLoss",s->pause_on_focus_loss,path);
    ok&=write_int(L"General",L"AutoRunOnLoad",s->auto_run_on_load,path);
    ok&=write_int(L"General",L"FullScreenOnPlay",s->fullscreen_on_play,path);
    ok&=write_int(L"General",L"ShowFpsCounter",s->show_fps_counter,path);
    ok&=write_int(L"General",L"NtscFrameLock",s->ntsc_frame_lock,path);
    ok&=write_int(L"Display",L"Widescreen",s->widescreen,path);
    ok&=write_int(L"Display",L"WidescreenNoticeShown",s->widescreen_notice_shown,path);
    ok&=write_int(L"General",L"SnapshotSlot",s->snapshot_slot,path);
    ok&=write_int(L"General",L"WelcomeShown",s->welcome_shown,path);
    ok&=WritePrivateProfileStringW(
        L"General",L"GettingStartedShown",NULL,path)!=0;
    ok&=write_int(L"Input",L"Source",s->input_source,path);
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++){
        _snwprintf_s(key,32,_TRUNCATE,L"Action%d",i);
        ok&=write_int(L"Input",key,(int)s->bindings[i],path);
        _snwprintf_s(key,32,_TRUNCATE,L"GamepadAction%d",i);
        ok&=write_int(L"Input",key,s->gamepad_bindings[i],path);
    }
    (void)WritePrivateProfileStringW(NULL,NULL,NULL,path);
    return ok;
}

uint16_t jungle_frontend_settings_win32_input(
    const JungleStrikeFrontendSettingsWin32 *s, UINT key) {
    static const uint16_t mask[] = {JUNGLE_INPUT_UP,JUNGLE_INPUT_DOWN,
        JUNGLE_INPUT_LEFT,JUNGLE_INPUT_RIGHT,JUNGLE_INPUT_B,JUNGLE_INPUT_A,
        JUNGLE_INPUT_Y,JUNGLE_INPUT_X,JUNGLE_INPUT_L,JUNGLE_INPUT_R,
        JUNGLE_INPUT_START,JUNGLE_INPUT_SELECT};
    int i; if(!s)return 0;
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++)if(s->bindings[i]==key)return mask[i];
    return 0;
}
const wchar_t *jungle_frontend_settings_win32_action_name(int a){
    static const wchar_t *n[]={L"D-pad Up",L"D-pad Down",L"D-pad Left",L"D-pad Right",
        L"B Button",L"A Button",L"Y Button",L"X Button",L"L Button",L"R Button",
        L"Start Button",L"Select Button"};
    return a>=0&&a<JUNGLE_WIN_BINDING_COUNT?n[a]:L"Unknown";
}
void jungle_frontend_settings_win32_key_name(UINT key,wchar_t *text,size_t cap){
    UINT scan; LONG param; if(!text||!cap)return; text[0]=0;
    scan=MapVirtualKeyW(key,MAPVK_VK_TO_VSC); param=(LONG)(scan<<16);
    if(key==VK_LEFT||key==VK_RIGHT||key==VK_UP||key==VK_DOWN)param|=1L<<24;
    if(!GetKeyNameTextW(param,text,(int)cap))_snwprintf(text,cap,L"VK %u",key);
    text[cap-1]=0;
}

static void copy_keyboard_defaults(UINT destination[JUNGLE_WIN_BINDING_COUNT],
                                   int classic){
    JungleStrikeFrontendSettingsWin32 defaults;int i;
    if(classic)jungle_frontend_settings_win32_classic(&defaults);
    else jungle_frontend_settings_win32_defaults(&defaults);
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++)destination[i]=defaults.bindings[i];
}

static void set_controls_status(DialogContext *c,const wchar_t *text){
    if(!c||!c->controller_status)return;
    SetWindowTextW(c->controller_status,text?text:L"");
    NotifyWinEvent(EVENT_OBJECT_VALUECHANGE,c->controller_status,
                   OBJID_CLIENT,CHILDID_SELF);
}

static void update_controls_status(DialogContext *c){
    wchar_t text[384];int source;
    if(!c||!c->source||!c->controller_status)return;
    source=(int)SendMessageW(c->source,CB_GETCURSEL,0,0);
    if(source==JUNGLE_INPUT_SOURCE_GAMEPAD){
        if(jungle_gamepad_win32_connected(c->gamepad))
            _snwprintf(text,384,L"Gamepad selected: %s. Keyboard shortcuts remain available.",
                       jungle_gamepad_win32_name(c->gamepad));
        else
            wcscpy_s(text,384,L"Gamepad selected, but none is connected. Gameplay uses the keyboard until one connects.");
    }else{
        if(jungle_gamepad_win32_connected(c->gamepad))
            _snwprintf(text,384,L"Keyboard selected. %s is connected and can be selected above.",
                       jungle_gamepad_win32_name(c->gamepad));
        else
            wcscpy_s(text,384,L"Keyboard selected. No gamepad is currently connected.");
    }
    text[383]=L'\0';set_controls_status(c,text);
}

static void refresh_control_bindings(DialogContext *c){
    int i;int source;int gamepad_connected;wchar_t name[192];
    if(!c||!c->source)return;
    source=(int)SendMessageW(c->source,CB_GETCURSEL,0,0);
    gamepad_connected=jungle_gamepad_win32_connected(c->gamepad);
    SetWindowTextW(c->assigned_header,source==JUNGLE_INPUT_SOURCE_KEYBOARD?
                   L"Current key - choose to change":L"Assigned input");
    ShowWindow(c->change_header,source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
    ShowWindow(c->keyboard_help_group,source==JUNGLE_INPUT_SOURCE_KEYBOARD?SW_SHOW:SW_HIDE);
    ShowWindow(c->keyboard_help_text,source==JUNGLE_INPUT_SOURCE_KEYBOARD?SW_SHOW:SW_HIDE);
    ShowWindow(c->gamepad_help_group,source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
    ShowWindow(c->gamepad_help_text,source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++){
        ShowWindow(c->controls[i],source==JUNGLE_INPUT_SOURCE_KEYBOARD?SW_SHOW:SW_HIDE);
        ShowWindow(c->gamepad_assignments[i],source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
        ShowWindow(c->gamepad_changes[i],source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
        if(source==JUNGLE_INPUT_SOURCE_KEYBOARD){
            jungle_frontend_settings_win32_key_name(c->value.bindings[i],name,
                                                     sizeof(name)/sizeof(name[0]));
            SetWindowTextW(c->controls[i],name);
            EnableWindow(c->controls[i],c->keyboard_capture_action<0);
        }else{
            jungle_gamepad_win32_control_display_name(
                c->gamepad,c->value.gamepad_bindings[i],name,
                sizeof(name)/sizeof(name[0]));
            SetWindowTextW(c->gamepad_assignments[i],name);
            EnableWindow(c->gamepad_changes[i],gamepad_connected&&c->capture_action<0);
        }
    }
    ShowWindow(c->accessible_defaults,source==JUNGLE_INPUT_SOURCE_KEYBOARD?SW_SHOW:SW_HIDE);
    ShowWindow(c->classic_defaults,source==JUNGLE_INPUT_SOURCE_KEYBOARD?SW_SHOW:SW_HIDE);
    ShowWindow(c->gamepad_defaults,source==JUNGLE_INPUT_SOURCE_GAMEPAD?SW_SHOW:SW_HIDE);
    EnableWindow(c->accessible_defaults,source==JUNGLE_INPUT_SOURCE_KEYBOARD&&
                 c->keyboard_capture_action<0);
    EnableWindow(c->classic_defaults,source==JUNGLE_INPUT_SOURCE_KEYBOARD&&
                 c->keyboard_capture_action<0);
    EnableWindow(c->gamepad_defaults,source==JUNGLE_INPUT_SOURCE_GAMEPAD&&c->capture_action<0);
    EnableWindow(c->source,c->capture_action<0&&c->keyboard_capture_action<0);
    if(c->capture_action<0&&c->keyboard_capture_action<0)update_controls_status(c);
}

static int first_duplicate_binding(const DialogContext *c,int source){
    int first;int second;int a;int b;
    if(!c)return -1;
    for(first=0;first<JUNGLE_WIN_BINDING_COUNT;first++){
        a=source==JUNGLE_INPUT_SOURCE_GAMEPAD?
            c->value.gamepad_bindings[first]:(int)c->value.bindings[first];
        for(second=first+1;second<JUNGLE_WIN_BINDING_COUNT;second++){
            b=source==JUNGLE_INPUT_SOURCE_GAMEPAD?
                c->value.gamepad_bindings[second]:(int)c->value.bindings[second];
            if(a==b)return second;
        }
    }
    return -1;
}

static void cancel_gamepad_capture(HWND window,DialogContext *c,const wchar_t *message){
    if(!c||c->capture_action<0)return;
    KillTimer(window,ID_GAMEPAD_CAPTURE_TIMER);
    c->capture_action=-1;c->capture_wait_for_neutral=0;
    EnableWindow(GetDlgItem(window,ID_CONTROLS_APPLY),TRUE);
    refresh_control_bindings(c);
    if(message)set_controls_status(c,message);
}

static void start_gamepad_capture(HWND window,DialogContext *c,int action){
    wchar_t message[256];int i;
    if(!c||action<0||action>=JUNGLE_WIN_BINDING_COUNT)return;
    if(!jungle_gamepad_win32_connected(c->gamepad)){
        set_controls_status(c,L"Connect a gamepad before changing a gamepad assignment.");
        return;
    }
    c->capture_action=action;c->capture_wait_for_neutral=1;
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++)EnableWindow(c->gamepad_changes[i],FALSE);
    EnableWindow(c->source,FALSE);EnableWindow(c->gamepad_defaults,FALSE);
    EnableWindow(GetDlgItem(window,ID_CONTROLS_APPLY),FALSE);
    _snwprintf(message,256,L"Release all gamepad controls, then press the control for %s. Escape cancels.",
               jungle_frontend_settings_win32_action_name(action));
    message[255]=L'\0';set_controls_status(c,message);
    SetTimer(window,ID_GAMEPAD_CAPTURE_TIMER,16,NULL);
}

static void cancel_keyboard_capture(HWND window,DialogContext *c,const wchar_t *message){
    int action;
    if(!c||c->keyboard_capture_action<0)return;
    action=c->keyboard_capture_action;c->keyboard_capture_action=-1;
    EnableWindow(GetDlgItem(window,ID_CONTROLS_APPLY),TRUE);
    refresh_control_bindings(c);
    if(message)set_controls_status(c,message);
    SetFocus(c->controls[action]);
}

static void start_keyboard_capture(HWND window,DialogContext *c,int action){
    wchar_t message[256];int i;
    if(!c||action<0||action>=JUNGLE_WIN_BINDING_COUNT)return;
    if(c->keyboard_capture_action>=0)return;
    c->keyboard_capture_action=action;
    for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++)EnableWindow(c->controls[i],FALSE);
    EnableWindow(c->controls[action],TRUE);
    SetWindowTextW(c->controls[action],L"Press a key...");
    EnableWindow(c->source,FALSE);EnableWindow(c->accessible_defaults,FALSE);
    EnableWindow(c->classic_defaults,FALSE);
    EnableWindow(GetDlgItem(window,ID_CONTROLS_APPLY),FALSE);
    _snwprintf(message,256,L"Press the new keyboard key for %s. Escape cancels.",
               jungle_frontend_settings_win32_action_name(action));
    message[255]=L'\0';set_controls_status(c,message);
    SetFocus(c->controls[action]);
}

static LRESULT CALLBACK settings_proc(HWND w,UINT msg,WPARAM wp,LPARAM lp){
    DialogContext *c=(DialogContext*)GetWindowLongPtrW(w,GWLP_USERDATA);
    switch(msg){
    case WM_NCCREATE:
        SetWindowLongPtrW(w,GWLP_USERDATA,(LONG_PTR)((CREATESTRUCTW*)lp)->lpCreateParams);
        return TRUE;
    case WM_CREATE:{
        int i; wchar_t t[32]; HWND scale;
        c=(DialogContext*)GetWindowLongPtrW(w,GWLP_USERDATA);
        SetWindowTextW(w,L"Jungle Strike Settings");
        set_font(CreateWindowW(L"BUTTON",L"General",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,14,12,512,112,w,NULL,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Start a valid ROM automatically when the launcher opens",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,32,42,455,24,w,(HMENU)ID_AUTO_RUN,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Pause the game when the app loses keyboard focus",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,32,76,455,24,w,(HMENU)ID_PAUSE_FOCUS,NULL,NULL));

        set_font(CreateWindowW(L"BUTTON",L"Display",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,14,134,512,172,w,NULL,NULL,NULL));
        set_font(CreateWindowW(L"STATIC",L"Game image scale:",WS_CHILD|WS_VISIBLE,32,166,150,22,w,NULL,NULL,NULL));
        scale=CreateWindowExW(0,L"COMBOBOX",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP|CBS_DROPDOWNLIST,190,162,180,160,w,(HMENU)ID_SCALE,NULL,NULL);
        set_font(scale);
        SendMessageW(scale,CB_ADDSTRING,0,(LPARAM)L"Automatic (fit window)");
        for(i=1;i<=4;i++){_snwprintf(t,32,L"%dx integer scale",i);SendMessageW(scale,CB_ADDSTRING,0,(LPARAM)t);}
        SendMessageW(scale,CB_SETCURSEL,c->value.integer_scale,0);
        set_font(CreateWindowW(L"BUTTON",L"Use full screen when Play starts",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,32,202,320,24,w,(HMENU)ID_FULLSCREEN_SETTING,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Show live FPS counter in the game title bar",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,32,234,390,24,w,(HMENU)ID_FPS_COUNTER,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Lock game speed to natural NTSC (60.0988 FPS)",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,32,266,410,24,w,(HMENU)ID_NTSC_FRAME_LOCK,NULL,NULL));

        set_font(CreateWindowW(L"BUTTON",L"Apply",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,350,324,80,30,w,(HMENU)ID_APPLY,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Close",WS_CHILD|WS_VISIBLE|WS_TABSTOP,440,324,80,30,w,(HMENU)ID_CANCEL,NULL,NULL));
        SendDlgItemMessageW(w,ID_PAUSE_FOCUS,BM_SETCHECK,c->value.pause_on_focus_loss?BST_CHECKED:BST_UNCHECKED,0);
        SendDlgItemMessageW(w,ID_AUTO_RUN,BM_SETCHECK,c->value.auto_run_on_load?BST_CHECKED:BST_UNCHECKED,0);
        SendDlgItemMessageW(w,ID_FULLSCREEN_SETTING,BM_SETCHECK,
            c->value.fullscreen_on_play?BST_CHECKED:BST_UNCHECKED,0);
        SendDlgItemMessageW(w,ID_FPS_COUNTER,BM_SETCHECK,
            c->value.show_fps_counter?BST_CHECKED:BST_UNCHECKED,0);
        SendDlgItemMessageW(w,ID_NTSC_FRAME_LOCK,BM_SETCHECK,
            c->value.ntsc_frame_lock?BST_CHECKED:BST_UNCHECKED,0);
        return 0;}
    case WM_COMMAND:
        if(!c)break;
        switch(LOWORD(wp)){
        case ID_APPLY:
            c->value.integer_scale=(int)SendDlgItemMessageW(w,ID_SCALE,CB_GETCURSEL,0,0);
            c->value.pause_on_focus_loss=SendDlgItemMessageW(w,ID_PAUSE_FOCUS,BM_GETCHECK,0,0)==BST_CHECKED;
            c->value.auto_run_on_load=SendDlgItemMessageW(w,ID_AUTO_RUN,BM_GETCHECK,0,0)==BST_CHECKED;
            c->value.fullscreen_on_play=SendDlgItemMessageW(
                w,ID_FULLSCREEN_SETTING,BM_GETCHECK,0,0)==BST_CHECKED;
            c->value.show_fps_counter=SendDlgItemMessageW(
                w,ID_FPS_COUNTER,BM_GETCHECK,0,0)==BST_CHECKED;
            c->value.ntsc_frame_lock=SendDlgItemMessageW(
                w,ID_NTSC_FRAME_LOCK,BM_GETCHECK,0,0)==BST_CHECKED;
            SendDlgItemMessageW(c->parent,1020,BM_SETCHECK,
                SendDlgItemMessageW(w,ID_FULLSCREEN_SETTING,BM_GETCHECK,0,0),0);
            *c->target=c->value;c->accepted=1;DestroyWindow(w);return 0;
        case ID_CANCEL:DestroyWindow(w);return 0;
        }break;
    case WM_CLOSE:DestroyWindow(w);return 0;
    }
    return DefWindowProcW(w,msg,wp,lp);
}

static LRESULT CALLBACK controls_proc(HWND w,UINT msg,WPARAM wp,LPARAM lp){
    DialogContext *c=(DialogContext*)GetWindowLongPtrW(w,GWLP_USERDATA);int i;
    switch(msg){
    case WM_NCCREATE:SetWindowLongPtrW(w,GWLP_USERDATA,(LONG_PTR)((CREATESTRUCTW*)lp)->lpCreateParams);return TRUE;
    case WM_CREATE:{
        HWND group;HWND label;wchar_t change_label[96];
        c=(DialogContext*)GetWindowLongPtrW(w,GWLP_USERDATA);SetWindowTextW(w,L"Jungle Strike Controller Bindings");
        group=CreateWindowW(L"BUTTON",L"Active input",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
                            14,12,712,84,w,NULL,NULL,NULL);set_font(group);
        label=CreateWindowW(L"STATIC",L"Use for gameplay:",WS_CHILD|WS_VISIBLE,
                            30,39,125,22,w,NULL,NULL,NULL);set_font(label);
        c->source=CreateWindowExW(0,L"COMBOBOX",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP|CBS_DROPDOWNLIST,
                                  158,35,190,160,w,(HMENU)ID_INPUT_SOURCE,NULL,NULL);set_font(c->source);
        SendMessageW(c->source,CB_ADDSTRING,0,(LPARAM)L"Keyboard");
        SendMessageW(c->source,CB_ADDSTRING,0,(LPARAM)L"Gamepad");
        SendMessageW(c->source,CB_SETCURSEL,c->value.input_source,0);
        c->controller_status=CreateWindowW(L"STATIC",L"",WS_CHILD|WS_VISIBLE,
                                           30,65,675,20,w,(HMENU)ID_CONTROLLER_STATUS,NULL,NULL);set_font(c->controller_status);
        set_font(CreateWindowW(L"STATIC",L"SNES control",WS_CHILD|WS_VISIBLE,
                               24,108,122,22,w,NULL,NULL,NULL));
        c->assigned_header=CreateWindowW(L"STATIC",L"Assigned input",WS_CHILD|WS_VISIBLE,
                                         158,108,260,22,w,NULL,NULL,NULL);set_font(c->assigned_header);
        c->change_header=CreateWindowW(L"STATIC",L"Change assignment",WS_CHILD|WS_VISIBLE,
                                       438,108,190,22,w,NULL,NULL,NULL);set_font(c->change_header);
        for(i=0;i<JUNGLE_WIN_BINDING_COUNT;i++){
            set_font(CreateWindowW(L"STATIC",jungle_frontend_settings_win32_action_name(i),
                                   WS_CHILD|WS_VISIBLE,24,134+i*28,122,22,w,NULL,NULL,NULL));
            c->controls[i]=CreateWindowW(L"BUTTON",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                                         158,129+i*28,260,25,w,
                                         (HMENU)(INT_PTR)(ID_CONTROL_BASE+i),NULL,NULL);set_font(c->controls[i]);
            c->gamepad_assignments[i]=CreateWindowW(
                L"STATIC",L"",WS_CHILD|SS_LEFT|SS_CENTERIMAGE,
                158,130+i*28,260,24,w,NULL,NULL,NULL);set_font(c->gamepad_assignments[i]);
            _snwprintf(change_label,96,L"Change %s...",
                       jungle_frontend_settings_win32_action_name(i));
            change_label[95]=L'\0';
            c->gamepad_changes[i]=CreateWindowW(
                L"BUTTON",change_label,WS_CHILD|WS_TABSTOP,
                438,129+i*28,190,25,w,
                (HMENU)(INT_PTR)(ID_GAMEPAD_CHANGE_BASE+i),NULL,NULL);set_font(c->gamepad_changes[i]);
        }
        c->keyboard_help_group=CreateWindowW(
            L"BUTTON",L"Changing keyboard keys",WS_CHILD|BS_GROUPBOX,
            438,129,288,112,w,NULL,NULL,NULL);set_font(c->keyboard_help_group);
        c->keyboard_help_text=CreateWindowW(
            L"STATIC",L"Choose the current-key button beside a control, then press the replacement key. Escape cancels. Choose Apply to save all changes.",
            WS_CHILD,454,151,252,70,w,NULL,NULL,NULL);set_font(c->keyboard_help_text);
        group=CreateWindowW(L"BUTTON",L"Defaults",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
                            14,472,350,72,w,NULL,NULL,NULL);set_font(group);
        c->accessible_defaults=CreateWindowW(L"BUTTON",L"Standard keyboard",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                                             30,495,150,30,w,(HMENU)ID_CONTROLS_ACCESSIBLE,NULL,NULL);set_font(c->accessible_defaults);
        c->classic_defaults=CreateWindowW(L"BUTTON",L"Classic keyboard",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                                          192,495,150,30,w,(HMENU)ID_CONTROLS_CLASSIC,NULL,NULL);set_font(c->classic_defaults);
        c->gamepad_defaults=CreateWindowW(L"BUTTON",L"SNES gamepad layout",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                                          95,495,190,30,w,(HMENU)ID_CONTROLS_GAMEPAD_DEFAULTS,NULL,NULL);set_font(c->gamepad_defaults);
        c->gamepad_help_group=CreateWindowW(L"BUTTON",L"Gamepad behavior",WS_CHILD|BS_GROUPBOX,
                                            380,472,346,72,w,NULL,NULL,NULL);set_font(c->gamepad_help_group);
        c->gamepad_help_text=CreateWindowW(L"STATIC",L"Choose Change, release held controls, then press the new button or direction. Escape cancels capture. Keyboard resumes if the gamepad disconnects.",
                                           WS_CHILD,396,492,312,40,w,NULL,NULL,NULL);set_font(c->gamepad_help_text);
        set_font(CreateWindowW(L"BUTTON",L"Apply",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,
                               552,558,82,32,w,(HMENU)ID_CONTROLS_APPLY,NULL,NULL));
        set_font(CreateWindowW(L"BUTTON",L"Cancel",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                               644,558,82,32,w,(HMENU)ID_CONTROLS_CANCEL,NULL,NULL));
        refresh_control_bindings(c);return 0;}
    case WM_COMMAND:if(!c)break;switch(LOWORD(wp)){
        case ID_INPUT_SOURCE:
            if(HIWORD(wp)==CBN_SELCHANGE){
                c->value.input_source=(int)SendMessageW(c->source,CB_GETCURSEL,0,0);
                refresh_control_bindings(c);
            }return 0;
        case ID_CONTROLS_ACCESSIBLE:
            copy_keyboard_defaults(c->value.bindings,0);refresh_control_bindings(c);return 0;
        case ID_CONTROLS_CLASSIC:
            copy_keyboard_defaults(c->value.bindings,1);refresh_control_bindings(c);return 0;
        case ID_CONTROLS_GAMEPAD_DEFAULTS:
            jungle_gamepad_win32_default_bindings(c->value.gamepad_bindings);
            refresh_control_bindings(c);return 0;
        case ID_CONTROLS_APPLY:
            c->value.input_source=(int)SendMessageW(c->source,CB_GETCURSEL,0,0);
            i=first_duplicate_binding(c,c->value.input_source);
            if(i>=0){
                MessageBoxW(w,
                    L"Each SNES control needs a different assigned input. Change the highlighted duplicate before applying.",
                    L"Controls",MB_OK|MB_ICONWARNING);
                SetFocus(c->value.input_source==JUNGLE_INPUT_SOURCE_GAMEPAD?
                         c->gamepad_changes[i]:c->controls[i]);return 0;
            }
            c->value.input_source_saved=1;
            *c->target=c->value;c->accepted=1;DestroyWindow(w);return 0;
        case ID_CONTROLS_CANCEL:KillTimer(w,ID_GAMEPAD_CAPTURE_TIMER);DestroyWindow(w);return 0;
        default:
            if(LOWORD(wp)>=ID_CONTROL_BASE&&
               LOWORD(wp)<ID_CONTROL_BASE+JUNGLE_WIN_BINDING_COUNT){
                start_keyboard_capture(w,c,LOWORD(wp)-ID_CONTROL_BASE);return 0;
            }
            if(LOWORD(wp)>=ID_GAMEPAD_CHANGE_BASE&&
               LOWORD(wp)<ID_GAMEPAD_CHANGE_BASE+JUNGLE_WIN_BINDING_COUNT){
                start_gamepad_capture(w,c,LOWORD(wp)-ID_GAMEPAD_CHANGE_BASE);return 0;
            }
            break;}break;
    case WM_TIMER:
        if(c&&wp==ID_GAMEPAD_CAPTURE_TIMER&&c->capture_action>=0){
            int control=jungle_gamepad_win32_capture_control(c->gamepad);
            wchar_t status[320];wchar_t assignment[192];int action=c->capture_action;
            if(!jungle_gamepad_win32_connected(c->gamepad)){
                cancel_gamepad_capture(w,c,L"Gamepad disconnected. Capture cancelled; keyboard gameplay remains available.");return 0;
            }
            if(c->capture_wait_for_neutral){
                if(control==0){
                    c->capture_wait_for_neutral=0;
                    _snwprintf(status,320,L"Press the new gamepad control for %s. Escape cancels.",
                               jungle_frontend_settings_win32_action_name(action));
                    status[319]=L'\0';set_controls_status(c,status);
                }
            }else if(control!=0){
                c->value.gamepad_bindings[action]=control;
                jungle_gamepad_win32_control_display_name(c->gamepad,control,
                                                           assignment,192);
                cancel_gamepad_capture(w,c,NULL);
                _snwprintf(status,320,L"%s is now assigned to %s. Choose Apply to save.",
                           jungle_frontend_settings_win32_action_name(action),assignment);
                status[319]=L'\0';set_controls_status(c,status);
                SetFocus(c->gamepad_changes[action]);
            }
            return 0;
        }break;
    case WM_CANCEL_GAMEPAD_CAPTURE:
        if(c&&c->capture_action>=0){
            cancel_gamepad_capture(w,c,L"Gamepad assignment capture cancelled.");
            SetFocus(c->gamepad_changes[0]);return 0;
        }break;
    case WM_COMPLETE_KEYBOARD_CAPTURE:
        if(c&&c->keyboard_capture_action>=0){
            wchar_t status[320];wchar_t key_name[96];int action=c->keyboard_capture_action;
            if(keyboard_key_is_reserved((UINT)wp)){
                set_controls_status(c,
                    L"That key is reserved for a launcher shortcut. Press a different key, or Escape to cancel.");
                return 0;
            }
            c->value.bindings[action]=(UINT)wp;
            jungle_frontend_settings_win32_key_name((UINT)wp,key_name,
                                                     sizeof(key_name)/sizeof(key_name[0]));
            cancel_keyboard_capture(w,c,NULL);
            _snwprintf(status,320,L"%s is now assigned to %s. Choose Apply to save.",
                       jungle_frontend_settings_win32_action_name(action),key_name);
            status[319]=L'\0';set_controls_status(c,status);return 0;
        }break;
    case WM_CANCEL_KEYBOARD_CAPTURE:
        if(c&&c->keyboard_capture_action>=0){
            cancel_keyboard_capture(w,c,L"Keyboard assignment capture cancelled.");return 0;
        }break;
    case WM_CLOSE:KillTimer(w,ID_GAMEPAD_CAPTURE_TIMER);DestroyWindow(w);return 0;
    case WM_DESTROY:KillTimer(w,ID_GAMEPAD_CAPTURE_TIMER);return 0;
    }return DefWindowProcW(w,msg,wp,lp);
}

static int run_dialog(HWND parent,HINSTANCE inst,const wchar_t *cls,const wchar_t *title,WNDPROC proc,int width,int height,JungleStrikeFrontendSettingsWin32 *s,JungleStrikeGamepadInputWin32 *gamepad){
    WNDCLASSW wc;DialogContext c;MSG msg;HWND w;BOOL parent_enabled;int message_result=1;
    memset(&wc,0,sizeof(wc));wc.lpfnWndProc=proc;wc.hInstance=inst;wc.lpszClassName=cls;wc.hCursor=LoadCursor(NULL,IDC_ARROW);wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);RegisterClassW(&wc);
    memset(&msg,0,sizeof(msg));
    memset(&c,0,sizeof(c));c.value=*s;c.target=s;c.parent=parent;c.gamepad=gamepad;
    c.capture_action=-1;c.keyboard_capture_action=-1;
    w=CreateWindowExW(WS_EX_DLGMODALFRAME|WS_EX_CONTROLPARENT,cls,title,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,width,height,parent,NULL,inst,&c);if(!w)return 0;SetWindowTextW(w,title);center_dialog(w,parent);
    parent_enabled=IsWindowEnabled(parent);EnableWindow(parent,FALSE);SetFocus(GetNextDlgTabItem(w,NULL,FALSE));
    while(IsWindow(w)&&(message_result=GetMessageW(&msg,NULL,0,0))>0){
        if(c.capture_action>=0&&msg.message==WM_KEYDOWN&&msg.wParam==VK_ESCAPE){
            SendMessageW(w,WM_CANCEL_GAMEPAD_CAPTURE,0,0);continue;
        }
        if(c.keyboard_capture_action>=0&&msg.message==WM_KEYDOWN){
            if(msg.wParam==VK_ESCAPE)SendMessageW(w,WM_CANCEL_KEYBOARD_CAPTURE,0,0);
            else SendMessageW(w,WM_COMPLETE_KEYBOARD_CAPTURE,msg.wParam,0);
            continue;
        }
        if(msg.message==WM_KEYDOWN&&msg.wParam==VK_ESCAPE){
            DestroyWindow(w);continue;
        }
        if(!IsDialogMessageW(w,&msg)){TranslateMessage(&msg);DispatchMessageW(&msg);}
    }
    if(parent_enabled)EnableWindow(parent,TRUE);
    SetForegroundWindow(parent);
    if(message_result==0)PostQuitMessage((int)msg.wParam);
    return c.accepted;
}
int jungle_frontend_settings_win32_dialog(HWND p,HINSTANCE i,JungleStrikeFrontendSettingsWin32 *s){return run_dialog(p,i,SETTINGS_CLASS,L"Jungle Strike Settings",settings_proc,560,414,s,NULL);}
int jungle_frontend_controls_win32_dialog(HWND p,HINSTANCE i,JungleStrikeFrontendSettingsWin32 *s,JungleStrikeGamepadInputWin32 *gamepad){return run_dialog(p,i,CONTROLS_CLASS,L"Jungle Strike Controller Bindings",controls_proc,760,640,s,gamepad);}
