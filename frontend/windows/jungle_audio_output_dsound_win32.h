#ifndef JUNGLE_AUDIO_OUTPUT_DSOUND_WIN32_H
#define JUNGLE_AUDIO_OUTPUT_DSOUND_WIN32_H

#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdint.h>

#include "jungle_app_core.h"
#include "jungle_audio_resampler.h"

#define JUNGLE_AUDIO_DEVICE_NAME_CAPACITY 128u
#define JUNGLE_AUDIO_QUEUE_HISTORY_CAPACITY 60u

#define JUNGLE_AUDIO_MIN_LATENCY_MS 0
#define JUNGLE_AUDIO_MAX_LATENCY_MS 40
#define JUNGLE_AUDIO_MIN_SAFETY_BUFFER_MS 0
#define JUNGLE_AUDIO_MAX_SAFETY_BUFFER_MS 100
#define JUNGLE_AUDIO_MIN_RING_BUFFER_MS 50
#define JUNGLE_AUDIO_MAX_RING_BUFFER_MS 1000
#define JUNGLE_AUDIO_MIN_RECOVERY_MS 10
#define JUNGLE_AUDIO_MAX_RECOVERY_MS 500
#define JUNGLE_AUDIO_MIN_DRIFT_TOLERANCE_MS 0
#define JUNGLE_AUDIO_MAX_DRIFT_TOLERANCE_MS 20
#define JUNGLE_AUDIO_MIN_RATE_ADJUSTMENT_PPM 0
#define JUNGLE_AUDIO_MAX_RATE_ADJUSTMENT_PPM 10000
#define JUNGLE_AUDIO_MIN_AVERAGING_FRAMES 1
#define JUNGLE_AUDIO_MAX_AVERAGING_FRAMES 60
#define JUNGLE_AUDIO_MIN_FADE_MS 0
#define JUNGLE_AUDIO_MAX_FADE_MS 100

typedef struct JungleStrikeAudioSettings {
    int enabled;
    int volume_percent;
    int latency_enabled;
    int latency_ms;
    int output_sample_rate;
    int resampler_mode;
    int safety_buffer_ms;
    int ring_buffer_ms;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    int realign_on_underrun;
    int clear_on_pause;
    int resume_fade_ms;
    wchar_t device_name[JUNGLE_AUDIO_DEVICE_NAME_CAPACITY];
} JungleStrikeAudioSettings;

typedef struct JungleStrikeAudioDiagnostics {
    uint64_t native_frames_queued;
    uint64_t underruns;
    uint64_t queue_failures;
    uint64_t queue_recoveries;
    uint64_t stale_frames_dropped;
    uint64_t device_reopens;
    uint32_t queue_depth_frames;
    uint32_t safe_queue_depth_frames;
    uint32_t peak_queue_depth_frames;
    uint32_t target_latency_frames;
    float playback_ratio;
    float average_latency_ms;
    int device_sample_rate;
} JungleStrikeAudioDiagnostics;

typedef struct JungleStrikeAudioOutput {
    LPDIRECTSOUND8 direct_sound;
    LPDIRECTSOUNDBUFFER primary_buffer;
    LPDIRECTSOUNDBUFFER8 secondary_buffer;
    JungleAudioHermiteResampler resampler;
    DWORD buffer_size_bytes;
    DWORD write_offset;
    DWORD previous_play_cursor;
    uint64_t total_bytes_written;
    uint64_t total_bytes_played;
    uint32_t target_latency_frames;
    uint32_t queue_history[JUNGLE_AUDIO_QUEUE_HISTORY_CAPACITY];
    uint32_t queue_history_index;
    uint32_t queue_history_count;
    int32_t under_target;
    int paused;
    int playing;
    int priming;
    int volume_percent;
    int latency_enabled;
    int device_sample_rate;
    int drift_correction_enabled;
    int drift_tolerance_ms;
    int max_rate_adjustment_ppm;
    int averaging_frames;
    int integral_correction_enabled;
    int recovery_enabled;
    int recovery_threshold_ms;
    int realign_on_underrun;
    int clear_on_pause;
    uint32_t fade_frames_remaining;
    uint32_t fade_frames_total;
    int starved_last_pump;
    double playback_ratio;
    wchar_t opened_device_name[JUNGLE_AUDIO_DEVICE_NAME_CAPACITY];
    JungleStrikeAudioDiagnostics diagnostics;
} JungleStrikeAudioOutput;

void jungle_audio_settings_defaults(JungleStrikeAudioSettings *settings);
void jungle_audio_settings_load(JungleStrikeAudioSettings *settings,
                                 const wchar_t *ini_path);
void jungle_audio_settings_save(const JungleStrikeAudioSettings *settings,
                                 const wchar_t *ini_path);

UINT jungle_audio_device_count(void);
int jungle_audio_device_name(UINT device_index, wchar_t *name,
                             size_t name_capacity);

void jungle_audio_output_initialize(JungleStrikeAudioOutput *output);
int jungle_audio_output_open(JungleStrikeAudioOutput *output,
                             const JungleStrikeAudioSettings *settings,
                             HWND owner, wchar_t *error,
                             size_t error_capacity);
void jungle_audio_output_close(JungleStrikeAudioOutput *output);
void jungle_audio_output_pause(JungleStrikeAudioOutput *output);
void jungle_audio_output_resume(JungleStrikeAudioOutput *output);
void jungle_audio_output_flush(JungleStrikeAudioOutput *output);
int jungle_audio_output_is_open(const JungleStrikeAudioOutput *output);
int32_t jungle_audio_output_pacing_ppm(
    const JungleStrikeAudioOutput *output);
void jungle_audio_output_get_diagnostics(
    const JungleStrikeAudioOutput *output,
    JungleStrikeAudioDiagnostics *diagnostics);

/* Recording remains native 32,040 Hz PCM; only speaker output is resampled. */
void jungle_audio_output_pump(JungleStrikeAudioOutput *output,
                              JungleStrikeRecomp *game);
/* Drain a partial in-frame DSP batch without running end-of-frame latency
   control more than once per emulated frame. */
void jungle_audio_output_pump_progress(JungleStrikeAudioOutput *output,
                                       JungleStrikeRecomp *game);

#endif
