#include "jungle_gamepad_input_win32.h"

#include "jungle_app_core.h"

#include <SDL3/SDL.h>
#include <string.h>
#include <wchar.h>

#define GAMEPAD_REFRESH_FRAMES 60u
#define GAMEPAD_STICK_PRESS 16384
#define GAMEPAD_TRIGGER_PRESS 16384

static void utf8_to_wide(const char *text, wchar_t *wide, size_t capacity) {
    int result;
    if (!wide || capacity == 0u) return;
    wide[0] = L'\0';
    if (!text || !text[0]) return;
    result = MultiByteToWideChar(CP_UTF8, 0, text, -1, wide, (int)capacity);
    if (result <= 0) wide[0] = L'\0';
    wide[capacity - 1u] = L'\0';
}

static void close_gamepad(JungleStrikeGamepadInputWin32 *input) {
    if (!input) return;
    if (input->handle) SDL_CloseGamepad(input->handle);
    input->handle = NULL;
    input->name[0] = L'\0';
}

static int open_first_gamepad(JungleStrikeGamepadInputWin32 *input) {
    SDL_JoystickID *gamepads;
    int count = 0;
    int index;
    if (!input || !input->initialized || input->handle) return input && input->handle;
    gamepads = SDL_GetGamepads(&count);
    if (!gamepads) return 0;
    for (index = 0; index < count; ++index) {
        input->handle = SDL_OpenGamepad(gamepads[index]);
        if (input->handle) {
            utf8_to_wide(SDL_GetGamepadName(input->handle), input->name,
                         sizeof(input->name) / sizeof(input->name[0]));
            if (!input->name[0])
                wcscpy_s(input->name,
                         sizeof(input->name) / sizeof(input->name[0]),
                         L"Connected gamepad");
            break;
        }
    }
    SDL_free(gamepads);
    return input->handle != NULL;
}

int jungle_gamepad_win32_initialize(JungleStrikeGamepadInputWin32 *input,
                                     const wchar_t *mapping_path) {
    char utf8_path[MAX_PATH * 4];
    int length;
    if (!input) return 0;
    memset(input, 0, sizeof(*input));
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "0");
    if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD)) return 0;
    input->initialized = 1;
    SDL_SetGamepadEventsEnabled(false);
    if (mapping_path && mapping_path[0]) {
        length = WideCharToMultiByte(CP_UTF8, 0, mapping_path, -1,
                                     utf8_path, (int)sizeof(utf8_path),
                                     NULL, NULL);
        if (length > 0) (void)SDL_AddGamepadMappingsFromFile(utf8_path);
    }
    SDL_UpdateGamepads();
    input->startup_gamepad_found = open_first_gamepad(input);
    input->refresh_countdown = GAMEPAD_REFRESH_FRAMES;
    return 1;
}

void jungle_gamepad_win32_shutdown(JungleStrikeGamepadInputWin32 *input) {
    if (!input) return;
    close_gamepad(input);
    if (input->initialized) SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
    memset(input, 0, sizeof(*input));
}

static int control_pressed(SDL_Gamepad *gamepad, int control) {
    Sint16 axis;
    if (!gamepad) return 0;
    switch (control) {
        case JUNGLE_GAMEPAD_DPAD_UP: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_DPAD_UP);
        case JUNGLE_GAMEPAD_DPAD_DOWN: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_DPAD_DOWN);
        case JUNGLE_GAMEPAD_DPAD_LEFT: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
        case JUNGLE_GAMEPAD_DPAD_RIGHT: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
        case JUNGLE_GAMEPAD_LEFT_STICK_UP:
            axis = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);
            return axis < -GAMEPAD_STICK_PRESS;
        case JUNGLE_GAMEPAD_LEFT_STICK_DOWN:
            axis = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);
            return axis > GAMEPAD_STICK_PRESS;
        case JUNGLE_GAMEPAD_LEFT_STICK_LEFT:
            axis = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);
            return axis < -GAMEPAD_STICK_PRESS;
        case JUNGLE_GAMEPAD_LEFT_STICK_RIGHT:
            axis = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);
            return axis > GAMEPAD_STICK_PRESS;
        case JUNGLE_GAMEPAD_FACE_SOUTH: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_SOUTH);
        case JUNGLE_GAMEPAD_FACE_EAST: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_EAST);
        case JUNGLE_GAMEPAD_FACE_WEST: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_WEST);
        case JUNGLE_GAMEPAD_FACE_NORTH: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_NORTH);
        case JUNGLE_GAMEPAD_LEFT_SHOULDER: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
        case JUNGLE_GAMEPAD_RIGHT_SHOULDER: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);
        case JUNGLE_GAMEPAD_LEFT_TRIGGER:
            return SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) > GAMEPAD_TRIGGER_PRESS;
        case JUNGLE_GAMEPAD_RIGHT_TRIGGER:
            return SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) > GAMEPAD_TRIGGER_PRESS;
        case JUNGLE_GAMEPAD_START: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_START);
        case JUNGLE_GAMEPAD_BACK: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_BACK);
        case JUNGLE_GAMEPAD_LEFT_STICK_BUTTON: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_LEFT_STICK);
        case JUNGLE_GAMEPAD_RIGHT_STICK_BUTTON: return SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_RIGHT_STICK);
        default: return 0;
    }
}

uint16_t jungle_gamepad_win32_poll(
    JungleStrikeGamepadInputWin32 *input,
    const int bindings[JUNGLE_GAMEPAD_BINDING_COUNT]) {
    static const uint16_t masks[JUNGLE_GAMEPAD_BINDING_COUNT] = {
        JUNGLE_INPUT_UP, JUNGLE_INPUT_DOWN, JUNGLE_INPUT_LEFT,
        JUNGLE_INPUT_RIGHT, JUNGLE_INPUT_B, JUNGLE_INPUT_A,
        JUNGLE_INPUT_Y, JUNGLE_INPUT_X, JUNGLE_INPUT_L,
        JUNGLE_INPUT_R, JUNGLE_INPUT_START, JUNGLE_INPUT_SELECT
    };
    uint16_t result = 0u;
    int index;
    if (!input || !input->initialized || !bindings) return 0u;
    SDL_UpdateGamepads();
    if (input->handle && !SDL_GamepadConnected(input->handle)) close_gamepad(input);
    if (!input->handle) {
        if (input->refresh_countdown > 0u) --input->refresh_countdown;
        if (input->refresh_countdown == 0u) {
            (void)open_first_gamepad(input);
            input->refresh_countdown = GAMEPAD_REFRESH_FRAMES;
        }
    }
    if (!input->handle) return 0u;
    for (index = 0; index < JUNGLE_GAMEPAD_BINDING_COUNT; ++index)
        if (control_pressed(input->handle, bindings[index])) result |= masks[index];
    return result;
}

int jungle_gamepad_win32_connected(const JungleStrikeGamepadInputWin32 *input) {
    return input && input->handle && SDL_GamepadConnected(input->handle);
}

const wchar_t *jungle_gamepad_win32_name(const JungleStrikeGamepadInputWin32 *input) {
    if (!jungle_gamepad_win32_connected(input)) return L"No gamepad connected";
    return input->name[0] ? input->name : L"Connected gamepad";
}

void jungle_gamepad_win32_default_bindings(
    int bindings[JUNGLE_GAMEPAD_BINDING_COUNT]) {
    if (!bindings) return;
    bindings[0] = JUNGLE_GAMEPAD_DPAD_UP;
    bindings[1] = JUNGLE_GAMEPAD_DPAD_DOWN;
    bindings[2] = JUNGLE_GAMEPAD_DPAD_LEFT;
    bindings[3] = JUNGLE_GAMEPAD_DPAD_RIGHT;
    bindings[4] = JUNGLE_GAMEPAD_FACE_SOUTH;
    bindings[5] = JUNGLE_GAMEPAD_FACE_EAST;
    bindings[6] = JUNGLE_GAMEPAD_FACE_WEST;
    bindings[7] = JUNGLE_GAMEPAD_FACE_NORTH;
    bindings[8] = JUNGLE_GAMEPAD_LEFT_SHOULDER;
    bindings[9] = JUNGLE_GAMEPAD_RIGHT_SHOULDER;
    bindings[10] = JUNGLE_GAMEPAD_START;
    bindings[11] = JUNGLE_GAMEPAD_BACK;
}

const wchar_t *jungle_gamepad_win32_control_name(int control) {
    static const wchar_t *names[] = {
        L"", L"D-pad Up", L"D-pad Down", L"D-pad Left", L"D-pad Right",
        L"Left Stick Up", L"Left Stick Down", L"Left Stick Left",
        L"Left Stick Right", L"South / bottom face button",
        L"East / right face button", L"West / left face button",
        L"North / top face button", L"Left shoulder", L"Right shoulder",
        L"Left trigger", L"Right trigger", L"Start / Menu", L"Back / View",
        L"Left stick button", L"Right stick button"
    };
    if (control < JUNGLE_GAMEPAD_DPAD_UP || control > JUNGLE_GAMEPAD_CONTROL_LAST)
        return L"Unknown gamepad control";
    return names[control];
}

int jungle_gamepad_win32_capture_control(JungleStrikeGamepadInputWin32 *input) {
    int control;
    if (!input || !input->initialized) return 0;
    SDL_UpdateGamepads();
    if (input->handle && !SDL_GamepadConnected(input->handle)) close_gamepad(input);
    if (!input->handle) (void)open_first_gamepad(input);
    if (!input->handle) return 0;
    for (control = JUNGLE_GAMEPAD_DPAD_UP;
         control <= JUNGLE_GAMEPAD_CONTROL_LAST; ++control)
        if (control_pressed(input->handle, control)) return control;
    return 0;
}

static const wchar_t *button_label_name(SDL_GamepadButtonLabel label) {
    switch (label) {
        case SDL_GAMEPAD_BUTTON_LABEL_A: return L"A";
        case SDL_GAMEPAD_BUTTON_LABEL_B: return L"B";
        case SDL_GAMEPAD_BUTTON_LABEL_X: return L"X";
        case SDL_GAMEPAD_BUTTON_LABEL_Y: return L"Y";
        case SDL_GAMEPAD_BUTTON_LABEL_CROSS: return L"Cross";
        case SDL_GAMEPAD_BUTTON_LABEL_CIRCLE: return L"Circle";
        case SDL_GAMEPAD_BUTTON_LABEL_SQUARE: return L"Square";
        case SDL_GAMEPAD_BUTTON_LABEL_TRIANGLE: return L"Triangle";
        default: return L"";
    }
}

void jungle_gamepad_win32_control_display_name(
    const JungleStrikeGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity) {
    SDL_GamepadButton button = SDL_GAMEPAD_BUTTON_INVALID;
    const wchar_t *label = L"";
    const wchar_t *base;
    if (!text || capacity == 0u) return;
    base = jungle_gamepad_win32_control_name(control);
    if (input && jungle_gamepad_win32_connected(input)) {
        switch (control) {
            case JUNGLE_GAMEPAD_FACE_SOUTH: button = SDL_GAMEPAD_BUTTON_SOUTH; break;
            case JUNGLE_GAMEPAD_FACE_EAST: button = SDL_GAMEPAD_BUTTON_EAST; break;
            case JUNGLE_GAMEPAD_FACE_WEST: button = SDL_GAMEPAD_BUTTON_WEST; break;
            case JUNGLE_GAMEPAD_FACE_NORTH: button = SDL_GAMEPAD_BUTTON_NORTH; break;
            default: break;
        }
        if (button != SDL_GAMEPAD_BUTTON_INVALID)
            label = button_label_name(SDL_GetGamepadButtonLabel(input->handle, button));
    }
    if (label[0])
        (void)_snwprintf(text, capacity, L"%s (%s)", base, label);
    else
        (void)_snwprintf(text, capacity, L"%s", base);
    text[capacity - 1u] = L'\0';
}
