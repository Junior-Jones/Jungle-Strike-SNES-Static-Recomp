#if !defined(_WIN32)
#error This test requires Windows.
#endif

#include <windows.h>

#include <stdio.h>
#include <string.h>

#include "jungle_frontend_settings_win32.h"
#include "jungle_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const UINT accessible_keys[JUNGLE_WIN_BINDING_COUNT] = {
        VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
        'D', 'F', 'A', 'S', 'E', 'R', 'G', 'T'
    };
    static const uint16_t masks[JUNGLE_WIN_BINDING_COUNT] = {
        JUNGLE_INPUT_UP, JUNGLE_INPUT_DOWN, JUNGLE_INPUT_LEFT,
        JUNGLE_INPUT_RIGHT, JUNGLE_INPUT_B, JUNGLE_INPUT_A,
        JUNGLE_INPUT_Y, JUNGLE_INPUT_X, JUNGLE_INPUT_L,
        JUNGLE_INPUT_R, JUNGLE_INPUT_START, JUNGLE_INPUT_SELECT
    };
    static const int gamepad[JUNGLE_WIN_BINDING_COUNT] = {
        JUNGLE_GAMEPAD_DPAD_UP, JUNGLE_GAMEPAD_DPAD_DOWN,
        JUNGLE_GAMEPAD_DPAD_LEFT, JUNGLE_GAMEPAD_DPAD_RIGHT,
        JUNGLE_GAMEPAD_FACE_SOUTH, JUNGLE_GAMEPAD_FACE_EAST,
        JUNGLE_GAMEPAD_FACE_WEST, JUNGLE_GAMEPAD_FACE_NORTH,
        JUNGLE_GAMEPAD_LEFT_SHOULDER, JUNGLE_GAMEPAD_RIGHT_SHOULDER,
        JUNGLE_GAMEPAD_START, JUNGLE_GAMEPAD_BACK
    };
    JungleStrikeFrontendSettingsWin32 settings;
    JungleStrikeFrontendSettingsWin32 loaded;
    wchar_t path[MAX_PATH];
    int index;

    CHECK(GetFullPathNameW(L"jungle-input-settings-contract.ini", MAX_PATH,
                           path, NULL) > 0u);
    (void)DeleteFileW(path);

    jungle_frontend_settings_win32_defaults(&settings);
    CHECK(settings.welcome_shown == 0);
    CHECK(settings.widescreen_notice_shown == 0);
    CHECK(settings.show_fps_counter == 0);
    CHECK(settings.ntsc_frame_lock == 1);
    for (index = 0; index < JUNGLE_WIN_BINDING_COUNT; ++index) {
        CHECK(settings.bindings[index] == accessible_keys[index]);
        CHECK(settings.gamepad_bindings[index] == gamepad[index]);
        CHECK(jungle_frontend_settings_win32_input(
                  &settings, settings.bindings[index]) == masks[index]);
    }
    CHECK(settings.bindings[10] == 'G');
    CHECK(settings.bindings[11] == 'T');

    memset(&loaded, 0xff, sizeof(loaded));
    jungle_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.welcome_shown == 0);

    settings.input_source = JUNGLE_INPUT_SOURCE_GAMEPAD;
    settings.integer_scale = 3;
    settings.pause_on_focus_loss = 1;
    settings.auto_run_on_load = 1;
    settings.fullscreen_on_play = 1;
    settings.welcome_shown = 1;
    settings.show_fps_counter = 1;
    settings.ntsc_frame_lock = 0;
    settings.widescreen = 1;
    settings.widescreen_notice_shown = 1;
    settings.snapshot_slot = 4;
    CHECK(jungle_frontend_settings_win32_save(&settings, path));
    memset(&loaded, 0, sizeof(loaded));
    jungle_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.input_source == JUNGLE_INPUT_SOURCE_GAMEPAD);
    CHECK(loaded.integer_scale == 3);
    CHECK(loaded.pause_on_focus_loss == 1);
    CHECK(loaded.auto_run_on_load == 1);
    CHECK(loaded.fullscreen_on_play == 1);
    CHECK(loaded.input_source_saved == 1);
    CHECK(loaded.welcome_shown == 1);
    CHECK(loaded.show_fps_counter == 1);
    CHECK(loaded.ntsc_frame_lock == 0);
    CHECK(loaded.widescreen == 1);
    CHECK(loaded.widescreen_notice_shown == 1);
    CHECK(loaded.snapshot_slot == 4);
    for (index = 0; index < JUNGLE_WIN_BINDING_COUNT; ++index) {
        CHECK(loaded.bindings[index] == accessible_keys[index]);
        CHECK(loaded.gamepad_bindings[index] == gamepad[index]);
        CHECK(jungle_frontend_settings_win32_input(
                  &loaded, loaded.bindings[index]) == masks[index]);
    }

    CHECK(WritePrivateProfileStringW(L"Input", L"Action10", L"84", path));
    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"71", path));
    jungle_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'T');
    CHECK(loaded.bindings[11] == 'G');
    CHECK(jungle_frontend_settings_win32_input(&loaded, 'T') ==
          JUNGLE_INPUT_START);
    CHECK(jungle_frontend_settings_win32_input(&loaded, 'G') ==
          JUNGLE_INPUT_SELECT);

    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"84", path));
    jungle_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'G');
    CHECK(loaded.bindings[11] == 'T');
    CHECK(jungle_frontend_settings_win32_input(&loaded, 'G') ==
          JUNGLE_INPUT_START);
    CHECK(jungle_frontend_settings_win32_input(&loaded, 'T') ==
          JUNGLE_INPUT_SELECT);

    CHECK(DeleteFileW(path));
    puts("PASS keyboard/gamepad action order, settings round-trip, and invalid-binding recovery");
    return 0;
}
