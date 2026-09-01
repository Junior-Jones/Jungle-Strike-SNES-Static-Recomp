#if !defined(_WIN32)
#error This test requires Windows.
#endif

#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "jungle_audio_output_dsound_win32.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void) {
    JungleStrikeAudioSettings settings;
    JungleStrikeAudioSettings loaded;
    wchar_t path[MAX_PATH];

    CHECK(GetFullPathNameW(L"jungle-audio-settings-contract.ini", MAX_PATH,
                           path, NULL) > 0u);
    (void)DeleteFileW(path);

    jungle_audio_settings_defaults(&settings);
    CHECK(settings.enabled == 1);
    CHECK(settings.volume_percent == 50);
    CHECK(settings.latency_enabled == 0);
    CHECK(settings.latency_ms == 0);
    CHECK(settings.output_sample_rate == 48000);
    CHECK(settings.resampler_mode == JUNGLE_AUDIO_RESAMPLER_HERMITE);
    CHECK(settings.safety_buffer_ms == 90);
    CHECK(settings.ring_buffer_ms == 250);
    CHECK(settings.drift_correction_enabled == 1);
    CHECK(settings.drift_tolerance_ms == 3);
    CHECK(settings.max_rate_adjustment_ppm == 2500);
    CHECK(settings.averaging_frames == 60);
    CHECK(settings.integral_correction_enabled == 1);
    CHECK(settings.recovery_enabled == 1);
    CHECK(settings.recovery_threshold_ms == 50);
    CHECK(settings.realign_on_underrun == 1);
    CHECK(settings.clear_on_pause == 0);
    CHECK(settings.resume_fade_ms == 0);

    settings.latency_enabled = 1;
    settings.enabled = 0;
    settings.volume_percent = 73;
    settings.latency_ms = 17;
    settings.output_sample_rate = 96000;
    settings.resampler_mode = JUNGLE_AUDIO_RESAMPLER_LINEAR;
    settings.safety_buffer_ms = 31;
    settings.ring_buffer_ms = 333;
    settings.drift_correction_enabled = 0;
    settings.drift_tolerance_ms = 7;
    settings.max_rate_adjustment_ppm = 4500;
    settings.averaging_frames = 24;
    settings.integral_correction_enabled = 0;
    settings.recovery_enabled = 0;
    settings.recovery_threshold_ms = 77;
    settings.realign_on_underrun = 0;
    settings.clear_on_pause = 0;
    settings.resume_fade_ms = 12;
    wcscpy_s(settings.device_name, JUNGLE_AUDIO_DEVICE_NAME_CAPACITY,
             L"Persistence Test Device");
    jungle_audio_settings_save(&settings, path);
    memset(&loaded, 0, sizeof(loaded));
    jungle_audio_settings_load(&loaded, path);
    CHECK(loaded.enabled == 0);
    CHECK(loaded.volume_percent == 73);
    CHECK(loaded.latency_enabled == 1);
    CHECK(loaded.latency_ms == 17);
    CHECK(loaded.output_sample_rate == 96000);
    CHECK(loaded.resampler_mode == JUNGLE_AUDIO_RESAMPLER_LINEAR);
    CHECK(loaded.safety_buffer_ms == 31);
    CHECK(loaded.ring_buffer_ms == 333);
    CHECK(loaded.drift_correction_enabled == 0);
    CHECK(loaded.drift_tolerance_ms == 7);
    CHECK(loaded.max_rate_adjustment_ppm == 4500);
    CHECK(loaded.averaging_frames == 24);
    CHECK(loaded.integral_correction_enabled == 0);
    CHECK(loaded.recovery_enabled == 0);
    CHECK(loaded.recovery_threshold_ms == 77);
    CHECK(loaded.realign_on_underrun == 0);
    CHECK(loaded.clear_on_pause == 0);
    CHECK(loaded.resume_fade_ms == 12);
    CHECK(wcscmp(loaded.device_name, L"Persistence Test Device") == 0);

    CHECK(WritePrivateProfileStringW(L"Audio", L"LatencyMs", L"99", path));
    jungle_audio_settings_load(&loaded, path);
    CHECK(loaded.latency_ms == 40);
    CHECK(WritePrivateProfileStringW(L"Audio", L"LatencyMs", L"-5", path));
    jungle_audio_settings_load(&loaded, path);
    CHECK(loaded.latency_ms == 0);

    CHECK(WritePrivateProfileStringW(L"Audio", L"SafetyBufferMs", L"999", path));
    CHECK(WritePrivateProfileStringW(L"Audio", L"RingBufferMs", L"1", path));
    CHECK(WritePrivateProfileStringW(L"Audio", L"OutputSampleRate", L"12345", path));
    CHECK(WritePrivateProfileStringW(L"Audio", L"ResamplerMode", L"99", path));
    CHECK(WritePrivateProfileStringW(L"Audio", L"AveragingFrames", L"0", path));
    jungle_audio_settings_load(&loaded, path);
    CHECK(loaded.safety_buffer_ms == JUNGLE_AUDIO_MAX_SAFETY_BUFFER_MS);
    CHECK(loaded.ring_buffer_ms == JUNGLE_AUDIO_MIN_RING_BUFFER_MS);
    CHECK(loaded.output_sample_rate == 48000);
    CHECK(loaded.resampler_mode == JUNGLE_AUDIO_RESAMPLER_NEAREST);
    CHECK(loaded.averaging_frames == JUNGLE_AUDIO_MIN_AVERAGING_FRAMES);

    CHECK(DeleteFileW(path));
    puts("PASS all advanced audio settings persist and clamp safely");
    return 0;
}
