#ifndef JUNGLE_FRONTEND_SETTINGS_WIN32_H
#define JUNGLE_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "jungle_gamepad_input_win32.h"

#define JUNGLE_WIN_BINDING_COUNT 12
#define JUNGLE_INPUT_SOURCE_KEYBOARD 0
#define JUNGLE_INPUT_SOURCE_GAMEPAD 1

typedef enum JungleStrikeWinBindingAction {
    JUNGLE_WIN_BIND_UP = 0, JUNGLE_WIN_BIND_DOWN, JUNGLE_WIN_BIND_LEFT, JUNGLE_WIN_BIND_RIGHT,
    JUNGLE_WIN_BIND_SNES_B, JUNGLE_WIN_BIND_SNES_A, JUNGLE_WIN_BIND_SNES_Y,
    JUNGLE_WIN_BIND_SNES_X, JUNGLE_WIN_BIND_SNES_L, JUNGLE_WIN_BIND_SNES_R,
    JUNGLE_WIN_BIND_START, JUNGLE_WIN_BIND_SELECT
} JungleStrikeWinBindingAction;

typedef struct JungleStrikeFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int widescreen;
    int snapshot_slot;
    int input_source;
    int input_source_saved;
    int welcome_shown;
    UINT bindings[JUNGLE_WIN_BINDING_COUNT];
    int gamepad_bindings[JUNGLE_WIN_BINDING_COUNT];
} JungleStrikeFrontendSettingsWin32;

void jungle_frontend_settings_win32_defaults(JungleStrikeFrontendSettingsWin32 *s);
void jungle_frontend_settings_win32_classic(JungleStrikeFrontendSettingsWin32 *s);
void jungle_frontend_settings_win32_load(JungleStrikeFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int jungle_frontend_settings_win32_save(const JungleStrikeFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t jungle_frontend_settings_win32_input(
    const JungleStrikeFrontendSettingsWin32 *s, UINT virtual_key);
const wchar_t *jungle_frontend_settings_win32_action_name(int action);
void jungle_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int jungle_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           JungleStrikeFrontendSettingsWin32 *s);
int jungle_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           JungleStrikeFrontendSettingsWin32 *s,
                                           JungleStrikeGamepadInputWin32 *gamepad);

#endif
