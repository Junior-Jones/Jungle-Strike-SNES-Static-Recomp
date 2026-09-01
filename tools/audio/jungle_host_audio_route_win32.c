#if !defined(_WIN32)
#error This host-audio route harness is for Windows only.
#endif

#include "jungle_app_core.h"
#include "jungle_audio_output_dsound_win32.h"

#include <windows.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RouteEvent {
    uint32_t first_frame;
    uint32_t last_frame;
    uint16_t input_mask;
} RouteEvent;

static int read_file(const char *path, uint8_t **data, size_t *size) {
    FILE *file;
    long length;
    uint8_t *bytes;
    if (!data || !size) return 0;
    *data = NULL;
    *size = 0u;
    file = fopen(path, "rb");
    if (!file || fseek(file, 0, SEEK_END) != 0 ||
        (length = ftell(file)) < 0 || fseek(file, 0, SEEK_SET) != 0) {
        if (file) fclose(file);
        return 0;
    }
    bytes = (uint8_t *)malloc((size_t)length);
    if (!bytes || fread(bytes, 1u, (size_t)length, file) != (size_t)length ||
        fclose(file) != 0) {
        free(bytes);
        return 0;
    }
    *data = bytes;
    *size = (size_t)length;
    return 1;
}

static int read_route(const char *path, RouteEvent *events, size_t capacity,
                      size_t *count, uint32_t *last_frame) {
    FILE *file;
    unsigned first;
    unsigned last;
    unsigned mask;
    size_t used = 0u;
    uint32_t end = 0u;
    if (!events || !count || !last_frame) return 0;
    file = fopen(path, "rt");
    if (!file) return 0;
    while (fscanf(file, "%u %u %x", &first, &last, &mask) == 3) {
        if (used >= capacity || first > last || mask > UINT16_MAX) {
            fclose(file);
            return 0;
        }
        events[used].first_frame = first;
        events[used].last_frame = last;
        events[used].input_mask = (uint16_t)mask;
        if (last > end) end = last;
        used++;
    }
    if (ferror(file) || fclose(file) != 0 || used == 0u) return 0;
    *count = used;
    *last_frame = end;
    return 1;
}

static uint16_t route_input(const RouteEvent *events, size_t count,
                            uint32_t frame) {
    size_t index;
    uint16_t input = 0u;
    for (index = 0u; index < count; ++index) {
        if (frame >= events[index].first_frame &&
            frame <= events[index].last_frame)
            input = (uint16_t)(input | events[index].input_mask);
    }
    return input;
}

int main(int argc, char **argv) {
    RouteEvent events[256];
    size_t event_count = 0u;
    uint32_t route_last_frame = 0u;
    uint32_t total_frames;
    uint32_t stall_frame = UINT32_MAX;
    uint8_t *rom = NULL;
    size_t rom_size = 0u;
    JungleStrikeRecomp *game = NULL;
    JungleStrikeAudioOutput output;
    JungleStrikeAudioSettings settings;
    JungleStrikeAudioDiagnostics diagnostics;
    LARGE_INTEGER frequency;
    LARGE_INTEGER started;
    uint64_t deadline;
    uint64_t ticks_base;
    uint32_t ticks_remainder;
    uint32_t remainder = 0u;
    uint32_t peak_queue_depth = 0u;
    uint32_t frame;
    wchar_t audio_error[512];
    char core_error[512];
    int passed = 0;

    if (argc != 3 && argc != 4) {
        fprintf(stderr, "usage: %s ROM ROUTE [STALL_FRAME]\n", argv[0]);
        return 2;
    }
    if (argc == 4) stall_frame = (uint32_t)strtoul(argv[3], NULL, 10);
    memset(&output, 0, sizeof(output));
    memset(&diagnostics, 0, sizeof(diagnostics));
    memset(audio_error, 0, sizeof(audio_error));
    memset(core_error, 0, sizeof(core_error));
    if (!read_route(argv[2], events, sizeof(events) / sizeof(events[0]),
                    &event_count, &route_last_frame) ||
        !read_file(argv[1], &rom, &rom_size) ||
        !jungle_recomp_create(&game, rom, rom_size,
                              core_error, sizeof(core_error))) {
        fprintf(stderr, "route/core setup failed: %s\n", core_error);
        free(rom);
        return 1;
    }
    free(rom);
    total_frames = route_last_frame + 120u;
    jungle_audio_output_initialize(&output);
    jungle_audio_settings_defaults(&settings);
    {
        const char *rate = getenv("JUNGLE_AUDIO_TEST_RATE");
        const char *mode = getenv("JUNGLE_AUDIO_TEST_RESAMPLER");
        const char *safety = getenv("JUNGLE_AUDIO_TEST_SAFETY_MS");
        if (rate && rate[0]) settings.output_sample_rate = atoi(rate);
        if (mode && mode[0]) settings.resampler_mode = atoi(mode);
        if (safety && safety[0]) settings.safety_buffer_ms = atoi(safety);
    }
    if (!jungle_audio_output_open(&output, &settings, NULL,
                                  audio_error,
                                  sizeof(audio_error) /
                                  sizeof(audio_error[0]))) {
        fwprintf(stderr, L"audio open failed: %ls\n", audio_error);
        jungle_recomp_destroy(game);
        return 1;
    }
    jungle_audio_output_resume(&output);
    if (!QueryPerformanceFrequency(&frequency) ||
        !QueryPerformanceCounter(&started)) goto cleanup;
    {
        uint64_t scaled = (uint64_t)frequency.QuadPart *
            JUNGLE_RECOMP_PRESENTATION_FPS_DENOMINATOR;
        ticks_base = scaled / JUNGLE_RECOMP_PRESENTATION_FPS_NUMERATOR;
        ticks_remainder = (uint32_t)(scaled %
            JUNGLE_RECOMP_PRESENTATION_FPS_NUMERATOR);
    }
    deadline = (uint64_t)started.QuadPart;
    for (frame = 0u; frame <= total_frames; ++frame) {
        JungleStrikeRecompFrameResult result;
        LARGE_INTEGER now;
        uint16_t input = route_input(events, event_count, frame);
        uint64_t frame_ticks = ticks_base;
        if (frame == stall_frame) Sleep(250u);
        remainder += ticks_remainder;
        if (remainder >= JUNGLE_RECOMP_PRESENTATION_FPS_NUMERATOR) {
            frame_ticks++;
            remainder -= JUNGLE_RECOMP_PRESENTATION_FPS_NUMERATOR;
        }
        deadline += frame_ticks;
        do {
            if (!QueryPerformanceCounter(&now)) goto cleanup;
            if ((uint64_t)now.QuadPart < deadline) Sleep(1u);
        } while ((uint64_t)now.QuadPart < deadline);
        memset(&result, 0, sizeof(result));
        if (!jungle_recomp_advance_headless(game, input, 1u, &result)) {
            fprintf(stderr, "core stopped at route frame %u: %s\n",
                    frame, jungle_recomp_last_error(game));
            goto cleanup;
        }
        jungle_audio_output_pump(&output, game);
        jungle_audio_output_get_diagnostics(&output, &diagnostics);
        if (peak_queue_depth < diagnostics.queue_depth_frames)
            peak_queue_depth = diagnostics.queue_depth_frames;
        if (frame % 60u == 0u) {
            printf("frame=%u queue=%u target=%u peak=%u ratio=%.6f "
                   "pacing_ppm=%d "
                   "underruns=%llu\n",
                   frame, diagnostics.queue_depth_frames,
                   diagnostics.target_latency_frames,
                   peak_queue_depth,
                   diagnostics.playback_ratio,
                   jungle_audio_output_pacing_ppm(&output),
                   (unsigned long long)diagnostics.underruns);
            fflush(stdout);
        }
    }
    jungle_audio_output_get_diagnostics(&output, &diagnostics);
    passed = !jungle_recomp_failed(game) &&
             !jungle_recomp_audio_overflowed(game) &&
             diagnostics.queue_failures == 0u &&
             peak_queue_depth <=
                diagnostics.target_latency_frames +
                ((uint32_t)diagnostics.device_sample_rate *
                 (uint32_t)settings.recovery_threshold_ms) / 1000u + 1u;
    printf("passed=%d final_queue=%u peak=%u target=%u "
           "underruns=%llu failures=%llu\n",
           passed, diagnostics.queue_depth_frames,
           peak_queue_depth,
           diagnostics.target_latency_frames,
           (unsigned long long)diagnostics.underruns,
           (unsigned long long)diagnostics.queue_failures);

cleanup:
    jungle_audio_output_close(&output);
    jungle_recomp_destroy(game);
    return passed ? 0 : 1;
}
