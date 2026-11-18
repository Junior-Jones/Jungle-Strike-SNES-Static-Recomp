#ifndef JUNGLE_LAUNCH_OPTIONS_H
#define JUNGLE_LAUNCH_OPTIONS_H
#include <stddef.h>
#include <wchar.h>

typedef struct JungleLaunchOptions {
    const wchar_t *game_path;
    int widescreen, fps60, fullscreen; /* -1 retains the saved setting. */
} JungleLaunchOptions;

static const wchar_t *jungle_parse_launch_options(
    int argc, wchar_t *const *argv, JungleLaunchOptions *out) {
    int i;
    if (!out || argc < 1 || !argv) return L"Unable to read launch options.";
    out->game_path = NULL;
    out->widescreen = out->fps60 = out->fullscreen = -1;
    for (i = 1; i < argc; ++i) {
        if (!wcscmp(argv[i], L"--game")) {
            if (++i >= argc || !argv[i][0] || !wcsncmp(argv[i], L"--", 2))
                return L"--game requires a ROM path. Quote paths containing spaces.";
            out->game_path = argv[i];
        } else if (!wcsncmp(argv[i], L"--game=", 7)) {
            if (!argv[i][7]) return L"--game requires a ROM path.";
            out->game_path = argv[i] + 7;
        } else if (!wcscmp(argv[i], L"--port-widescreen") ||
                   !wcscmp(argv[i], L"--port-wide-canvas")) out->widescreen = 1;
        else if (!wcscmp(argv[i], L"--no-port-widescreen")) out->widescreen = 0;
        else if (!wcscmp(argv[i], L"--60fps")) out->fps60 = 1;
        else if (!wcscmp(argv[i], L"--no-60fps")) out->fps60 = 0;
        else if (!wcscmp(argv[i], L"--fullscreen")) out->fullscreen = 1;
        else if (!wcscmp(argv[i], L"--windowed")) out->fullscreen = 0;
        else return L"Unknown launch option. Use --game, --port-widescreen, --60fps, --fullscreen or their documented alternatives.";
    }
    return NULL;
}
#endif
