#ifndef JUNGLE_GAMEPAD_INPUT_WIN32_H
#define JUNGLE_GAMEPAD_INPUT_WIN32_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#include <SDL3/SDL_gamepad.h>

#define JUNGLE_GAMEPAD_BINDING_COUNT 12

typedef enum JungleStrikeGamepadControl {
    JUNGLE_GAMEPAD_DPAD_UP = 1,
    JUNGLE_GAMEPAD_DPAD_DOWN,
    JUNGLE_GAMEPAD_DPAD_LEFT,
    JUNGLE_GAMEPAD_DPAD_RIGHT,
    JUNGLE_GAMEPAD_LEFT_STICK_UP,
    JUNGLE_GAMEPAD_LEFT_STICK_DOWN,
    JUNGLE_GAMEPAD_LEFT_STICK_LEFT,
    JUNGLE_GAMEPAD_LEFT_STICK_RIGHT,
    JUNGLE_GAMEPAD_FACE_SOUTH,
    JUNGLE_GAMEPAD_FACE_EAST,
    JUNGLE_GAMEPAD_FACE_WEST,
    JUNGLE_GAMEPAD_FACE_NORTH,
    JUNGLE_GAMEPAD_LEFT_SHOULDER,
    JUNGLE_GAMEPAD_RIGHT_SHOULDER,
    JUNGLE_GAMEPAD_LEFT_TRIGGER,
    JUNGLE_GAMEPAD_RIGHT_TRIGGER,
    JUNGLE_GAMEPAD_START,
    JUNGLE_GAMEPAD_BACK,
    JUNGLE_GAMEPAD_LEFT_STICK_BUTTON,
    JUNGLE_GAMEPAD_RIGHT_STICK_BUTTON,
    JUNGLE_GAMEPAD_CONTROL_LAST = JUNGLE_GAMEPAD_RIGHT_STICK_BUTTON
} JungleStrikeGamepadControl;

typedef struct JungleStrikeGamepadInputWin32 {
    SDL_Gamepad *handle;
    int initialized;
    int startup_gamepad_found;
    unsigned refresh_countdown;
    wchar_t name[160];
} JungleStrikeGamepadInputWin32;

int jungle_gamepad_win32_initialize(JungleStrikeGamepadInputWin32 *input,
                                     const wchar_t *mapping_path);
void jungle_gamepad_win32_shutdown(JungleStrikeGamepadInputWin32 *input);
uint16_t jungle_gamepad_win32_poll(
    JungleStrikeGamepadInputWin32 *input,
    const int bindings[JUNGLE_GAMEPAD_BINDING_COUNT]);
int jungle_gamepad_win32_connected(const JungleStrikeGamepadInputWin32 *input);
const wchar_t *jungle_gamepad_win32_name(const JungleStrikeGamepadInputWin32 *input);
void jungle_gamepad_win32_default_bindings(
    int bindings[JUNGLE_GAMEPAD_BINDING_COUNT]);
const wchar_t *jungle_gamepad_win32_control_name(int control);
int jungle_gamepad_win32_capture_control(JungleStrikeGamepadInputWin32 *input);
void jungle_gamepad_win32_control_display_name(
    const JungleStrikeGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity);

#endif
