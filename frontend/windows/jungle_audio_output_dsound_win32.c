#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#define COBJMACROS
#include "jungle_audio_output_dsound_win32.h"

#include <limits.h>
#include <math.h>
#include <string.h>
#include <wchar.h>

#define AUDIO_INI_SECTION L"Audio"
#define AUDIO_DEFAULT_DEVICE_LABEL L"Default Windows audio device"
#define AUDIO_DEFAULT_LATENCY_MS 0
#define AUDIO_FINE_RATE_STEP 0.00003125
#define AUDIO_MAX_SUB_ADJUSTMENT 3600
#define AUDIO_NATIVE_STAGING_FRAMES 4096u
#define AUDIO_HOST_STAGING_FRAMES 16384u
#define AUDIO_MESEN_RING_GRANULARITY_BYTES 0x10000u
#define AUDIO_BLOCK_ALIGN_BYTES \
    (JUNGLE_RECOMP_AUDIO_CHANNELS * (uint32_t)sizeof(int16_t))

typedef struct DirectSoundEnumeration {
    UINT requested_index;
    UINT current_index;
    UINT count;
    const wchar_t *requested_name;
    wchar_t *name;
    size_t name_capacity;
    GUID guid;
    int has_guid;
    int found;
} DirectSoundEnumeration;

static void copy_wide(wchar_t *destination, size_t capacity,
                      const wchar_t *source) {
    if (!destination || capacity == 0u) return;
    if (!source) source = L"";
    wcsncpy(destination, source, capacity - 1u);
    destination[capacity - 1u] = L'\0';
}

static void set_dsound_error(wchar_t *error, size_t capacity,
                             const wchar_t *prefix, HRESULT result) {
    wchar_t message[384];
    if (!error || capacity == 0u) return;
    (void)_snwprintf(message, sizeof(message) / sizeof(message[0]),
                     L"%s (DirectSound error 0x%08lX)",
                     prefix ? prefix : L"Audio error",
                     (unsigned long)result);
    message[(sizeof(message) / sizeof(message[0])) - 1u] = L'\0';
    copy_wide(error, capacity, message);
}

static int clamp_int(int value, int minimum, int maximum) {
    if (value < minimum) return minimum;
    if (value > maximum) return maximum;
    return value;
}

static int valid_output_rate(int value) {
    return value == 32040 || value == 44100 || value == 48000 ||
           value == 96000;
}

static void save_int_setting(const wchar_t *key, int value,
                             const wchar_t *ini_path) {
    wchar_t number[32];
    (void)_snwprintf(number, 32u, L"%d", value);
    number[31] = L'\0';
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION, key, number,
                                     ini_path);
}

void jungle_audio_settings_defaults(JungleStrikeAudioSettings *settings) {
    if (!settings) return;
    memset(settings, 0, sizeof(*settings));
    settings->enabled = 1;
    settings->volume_percent = 50;
    settings->latency_enabled = 0;
    settings->latency_ms = AUDIO_DEFAULT_LATENCY_MS;
    settings->output_sample_rate = 48000;
    settings->resampler_mode = JUNGLE_AUDIO_RESAMPLER_HERMITE;
    settings->safety_buffer_ms = 90;
    settings->ring_buffer_ms = 250;
    settings->drift_correction_enabled = 1;
    settings->drift_tolerance_ms = 3;
    settings->max_rate_adjustment_ppm = 2500;
    settings->averaging_frames = 60;
    settings->integral_correction_enabled = 1;
    settings->recovery_enabled = 1;
    settings->recovery_threshold_ms = 50;
    settings->realign_on_underrun = 1;
    settings->clear_on_pause = 0;
    settings->resume_fade_ms = 0;
}

void jungle_audio_settings_load(JungleStrikeAudioSettings *settings,
                                 const wchar_t *ini_path) {
    if (!settings) return;
    jungle_audio_settings_defaults(settings);
    if (!ini_path || !ini_path[0]) return;
    settings->enabled = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"Enabled", settings->enabled, ini_path) != 0;
    settings->volume_percent = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"VolumePercent", settings->volume_percent,
        ini_path);
    settings->latency_enabled = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"LatencyEnabled", settings->latency_enabled,
        ini_path) != 0;
    settings->latency_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"LatencyMs", settings->latency_ms, ini_path);
    settings->output_sample_rate = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"OutputSampleRate",
        settings->output_sample_rate, ini_path);
    settings->resampler_mode = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"ResamplerMode", settings->resampler_mode,
        ini_path);
    settings->safety_buffer_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"SafetyBufferMs", settings->safety_buffer_ms,
        ini_path);
    settings->ring_buffer_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"RingBufferMs", settings->ring_buffer_ms,
        ini_path);
    settings->drift_correction_enabled = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"DriftCorrectionEnabled",
        settings->drift_correction_enabled, ini_path) != 0;
    settings->drift_tolerance_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"DriftToleranceMs",
        settings->drift_tolerance_ms, ini_path);
    settings->max_rate_adjustment_ppm = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"MaxRateAdjustmentPpm",
        settings->max_rate_adjustment_ppm, ini_path);
    settings->averaging_frames = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"AveragingFrames",
        settings->averaging_frames, ini_path);
    settings->integral_correction_enabled = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"IntegralCorrectionEnabled",
        settings->integral_correction_enabled, ini_path) != 0;
    settings->recovery_enabled = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"RecoveryEnabled",
        settings->recovery_enabled, ini_path) != 0;
    settings->recovery_threshold_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"RecoveryThresholdMs",
        settings->recovery_threshold_ms, ini_path);
    settings->realign_on_underrun = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"RealignOnUnderrun",
        settings->realign_on_underrun, ini_path) != 0;
    settings->clear_on_pause = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"ClearOnPause", settings->clear_on_pause,
        ini_path) != 0;
    settings->resume_fade_ms = GetPrivateProfileIntW(
        AUDIO_INI_SECTION, L"ResumeFadeMs", settings->resume_fade_ms,
        ini_path);
    if (settings->volume_percent < 0) settings->volume_percent = 0;
    if (settings->volume_percent > 100) settings->volume_percent = 100;
    settings->latency_ms = clamp_int(settings->latency_ms,
        JUNGLE_AUDIO_MIN_LATENCY_MS, JUNGLE_AUDIO_MAX_LATENCY_MS);
    if (!valid_output_rate(settings->output_sample_rate))
        settings->output_sample_rate = 48000;
    settings->resampler_mode = clamp_int(settings->resampler_mode,
        JUNGLE_AUDIO_RESAMPLER_HERMITE, JUNGLE_AUDIO_RESAMPLER_NEAREST);
    settings->safety_buffer_ms = clamp_int(settings->safety_buffer_ms,
        JUNGLE_AUDIO_MIN_SAFETY_BUFFER_MS,
        JUNGLE_AUDIO_MAX_SAFETY_BUFFER_MS);
    settings->ring_buffer_ms = clamp_int(settings->ring_buffer_ms,
        JUNGLE_AUDIO_MIN_RING_BUFFER_MS, JUNGLE_AUDIO_MAX_RING_BUFFER_MS);
    settings->drift_tolerance_ms = clamp_int(settings->drift_tolerance_ms,
        JUNGLE_AUDIO_MIN_DRIFT_TOLERANCE_MS,
        JUNGLE_AUDIO_MAX_DRIFT_TOLERANCE_MS);
    settings->max_rate_adjustment_ppm = clamp_int(
        settings->max_rate_adjustment_ppm,
        JUNGLE_AUDIO_MIN_RATE_ADJUSTMENT_PPM,
        JUNGLE_AUDIO_MAX_RATE_ADJUSTMENT_PPM);
    settings->averaging_frames = clamp_int(settings->averaging_frames,
        JUNGLE_AUDIO_MIN_AVERAGING_FRAMES,
        JUNGLE_AUDIO_MAX_AVERAGING_FRAMES);
    settings->recovery_threshold_ms = clamp_int(
        settings->recovery_threshold_ms, JUNGLE_AUDIO_MIN_RECOVERY_MS,
        JUNGLE_AUDIO_MAX_RECOVERY_MS);
    settings->resume_fade_ms = clamp_int(settings->resume_fade_ms,
        JUNGLE_AUDIO_MIN_FADE_MS, JUNGLE_AUDIO_MAX_FADE_MS);
    (void)GetPrivateProfileStringW(
        AUDIO_INI_SECTION, L"DeviceName", L"", settings->device_name,
        (DWORD)JUNGLE_AUDIO_DEVICE_NAME_CAPACITY, ini_path);
}

void jungle_audio_settings_save(const JungleStrikeAudioSettings *settings,
                                 const wchar_t *ini_path) {
    if (!settings || !ini_path || !ini_path[0]) return;
    (void)WritePrivateProfileStringW(
        AUDIO_INI_SECTION, L"Enabled", settings->enabled ? L"1" : L"0",
        ini_path);
    save_int_setting(L"VolumePercent", settings->volume_percent, ini_path);
    (void)WritePrivateProfileStringW(
        AUDIO_INI_SECTION, L"LatencyEnabled",
        settings->latency_enabled ? L"1" : L"0", ini_path);
    save_int_setting(L"LatencyMs", settings->latency_ms, ini_path);
    save_int_setting(L"OutputSampleRate", settings->output_sample_rate,
                     ini_path);
    save_int_setting(L"ResamplerMode", settings->resampler_mode, ini_path);
    save_int_setting(L"SafetyBufferMs", settings->safety_buffer_ms,
                     ini_path);
    save_int_setting(L"RingBufferMs", settings->ring_buffer_ms, ini_path);
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION,
        L"DriftCorrectionEnabled",
        settings->drift_correction_enabled ? L"1" : L"0", ini_path);
    save_int_setting(L"DriftToleranceMs", settings->drift_tolerance_ms,
                     ini_path);
    save_int_setting(L"MaxRateAdjustmentPpm",
                     settings->max_rate_adjustment_ppm, ini_path);
    save_int_setting(L"AveragingFrames", settings->averaging_frames,
                     ini_path);
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION,
        L"IntegralCorrectionEnabled",
        settings->integral_correction_enabled ? L"1" : L"0", ini_path);
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION, L"RecoveryEnabled",
        settings->recovery_enabled ? L"1" : L"0", ini_path);
    save_int_setting(L"RecoveryThresholdMs",
                     settings->recovery_threshold_ms, ini_path);
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION,
        L"RealignOnUnderrun",
        settings->realign_on_underrun ? L"1" : L"0", ini_path);
    (void)WritePrivateProfileStringW(AUDIO_INI_SECTION, L"ClearOnPause",
        settings->clear_on_pause ? L"1" : L"0", ini_path);
    save_int_setting(L"ResumeFadeMs", settings->resume_fade_ms, ini_path);
    (void)WritePrivateProfileStringW(
        AUDIO_INI_SECTION, L"DeviceName", settings->device_name, ini_path);
    (void)WritePrivateProfileStringW(NULL, NULL, NULL, ini_path);
}

static BOOL CALLBACK enumerate_dsound_device(
    LPGUID guid, LPCWSTR description, LPCWSTR module, LPVOID context_pointer) {
    DirectSoundEnumeration *context =
        (DirectSoundEnumeration *)context_pointer;
    (void)module;
    if (!context) return FALSE;
    context->count++;
    if (!context->found &&
        ((context->requested_name && description &&
          wcscmp(context->requested_name, description) == 0) ||
         (!context->requested_name &&
          context->current_index == context->requested_index))) {
        if (context->name)
            copy_wide(context->name, context->name_capacity, description);
        if (guid) {
            context->guid = *guid;
            context->has_guid = 1;
        } else {
            memset(&context->guid, 0, sizeof(context->guid));
            context->has_guid = 0;
        }
        context->found = 1;
        if (context->requested_name || context->name) return FALSE;
    }
    context->current_index++;
    return TRUE;
}

UINT jungle_audio_device_count(void) {
    DirectSoundEnumeration context;
    memset(&context, 0, sizeof(context));
    context.requested_index = UINT_MAX;
    (void)DirectSoundEnumerateW(enumerate_dsound_device, &context);
    return context.count;
}

int jungle_audio_device_name(UINT device_index, wchar_t *name,
                             size_t name_capacity) {
    DirectSoundEnumeration context;
    if (!name || name_capacity == 0u) return 0;
    name[0] = L'\0';
    memset(&context, 0, sizeof(context));
    context.requested_index = device_index;
    context.name = name;
    context.name_capacity = name_capacity;
    (void)DirectSoundEnumerateW(enumerate_dsound_device, &context);
    return context.found && name[0];
}

static const GUID *resolve_device(const wchar_t *requested, GUID *selected,
                                  wchar_t *resolved,
                                  size_t resolved_capacity) {
    DirectSoundEnumeration context;
    copy_wide(resolved, resolved_capacity, AUDIO_DEFAULT_DEVICE_LABEL);
    if (!requested || !requested[0]) return NULL;
    memset(&context, 0, sizeof(context));
    context.requested_name = requested;
    context.requested_index = UINT_MAX;
    (void)DirectSoundEnumerateW(enumerate_dsound_device, &context);
    if (!context.found) return NULL;
    copy_wide(resolved, resolved_capacity, requested);
    if (!context.has_guid) return NULL;
    *selected = context.guid;
    return selected;
}

static DWORD valid_ring_size(uint64_t requested_bytes) {
    const uint64_t granularity = AUDIO_MESEN_RING_GRANULARITY_BYTES;
    /* Mesen rounds its doubled requested-latency capacity to whole 64-KiB
       blocks.  The caller supplies the already-doubled byte count. */
    if (requested_bytes < granularity) requested_bytes = granularity;
    if (requested_bytes <= (uint64_t)DSBSIZE_MAX - (granularity - 1u))
        requested_bytes = ((requested_bytes + granularity - 1u) /
                           granularity) * granularity;
    if (requested_bytes > DSBSIZE_MAX) requested_bytes = DSBSIZE_MAX;
    if (requested_bytes < DSBSIZE_MIN) requested_bytes = DSBSIZE_MIN;
    requested_bytes -= requested_bytes % AUDIO_BLOCK_ALIGN_BYTES;
    return (DWORD)requested_bytes;
}

static int restore_secondary_buffer(JungleStrikeAudioOutput *output) {
    DWORD status = 0u;
    HRESULT result;
    if (!output || !output->secondary_buffer) return 0;
    result = IDirectSoundBuffer8_GetStatus(output->secondary_buffer, &status);
    if (FAILED(result)) return 0;
    if ((status & DSBSTATUS_BUFFERLOST) != 0u) {
        result = IDirectSoundBuffer8_Restore(output->secondary_buffer);
        if (FAILED(result)) return 0;
    }
    return 1;
}

static int clear_secondary_buffer(JungleStrikeAudioOutput *output) {
    void *first = NULL;
    void *second = NULL;
    DWORD first_size = 0u;
    DWORD second_size = 0u;
    HRESULT result;
    if (!output || !output->secondary_buffer) return 0;
    if (!restore_secondary_buffer(output)) return 0;
    result = IDirectSoundBuffer8_Lock(
        output->secondary_buffer, 0u, output->buffer_size_bytes,
        &first, &first_size, &second, &second_size, DSBLOCK_ENTIREBUFFER);
    if (FAILED(result)) return 0;
    if (first && first_size) memset(first, 0, first_size);
    if (second && second_size) memset(second, 0, second_size);
    result = IDirectSoundBuffer8_Unlock(
        output->secondary_buffer, first, first_size, second, second_size);
    if (FAILED(result)) return 0;
    (void)IDirectSoundBuffer8_SetCurrentPosition(output->secondary_buffer, 0u);
    output->write_offset = 0u;
    return 1;
}

static void release_buffers(JungleStrikeAudioOutput *output) {
    if (!output) return;
    if (output->secondary_buffer) {
        IDirectSoundBuffer8_Release(output->secondary_buffer);
        output->secondary_buffer = NULL;
    }
    if (output->primary_buffer) {
        IDirectSoundBuffer_Release(output->primary_buffer);
        output->primary_buffer = NULL;
    }
    if (output->direct_sound) {
        IDirectSound8_Release(output->direct_sound);
        output->direct_sound = NULL;
    }
}

void jungle_audio_output_initialize(JungleStrikeAudioOutput *output) {
    if (output) memset(output, 0, sizeof(*output));
}

int jungle_audio_output_open(JungleStrikeAudioOutput *output,
                             const JungleStrikeAudioSettings *settings,
                             HWND owner, wchar_t *error,
                             size_t error_capacity) {
    DSBUFFERDESC description;
    WAVEFORMATEX format;
    LPDIRECTSOUNDBUFFER temporary = NULL;
    GUID selected;
    const GUID *device;
    HRESULT result;
    DWORD requested_bytes;
    if (error && error_capacity) error[0] = L'\0';
    if (!output || !settings) return 0;
    jungle_audio_output_close(output);
    output->volume_percent = settings->volume_percent;
    output->latency_enabled = settings->latency_enabled;
    output->device_sample_rate = settings->output_sample_rate;
    output->drift_correction_enabled = settings->drift_correction_enabled;
    output->drift_tolerance_ms = settings->drift_tolerance_ms;
    output->max_rate_adjustment_ppm = settings->max_rate_adjustment_ppm;
    output->averaging_frames = settings->averaging_frames;
    output->integral_correction_enabled =
        settings->integral_correction_enabled;
    output->recovery_enabled = settings->recovery_enabled;
    output->recovery_threshold_ms = settings->recovery_threshold_ms;
    output->realign_on_underrun = settings->realign_on_underrun;
    output->clear_on_pause = settings->clear_on_pause;
    output->fade_frames_total = (uint32_t)(
        ((uint64_t)settings->output_sample_rate *
         (uint64_t)settings->resume_fade_ms) / 1000u);
    if (!settings->enabled) return 1;
    device = resolve_device(settings->device_name, &selected,
                            output->opened_device_name,
                            sizeof(output->opened_device_name) /
                                sizeof(output->opened_device_name[0]));
    result = DirectSoundCreate8(device, &output->direct_sound, NULL);
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to open the selected audio device", result);
        goto fail;
    }
    if (!owner) owner = GetDesktopWindow();
    result = IDirectSound8_SetCooperativeLevel(
        output->direct_sound, owner, DSSCL_PRIORITY);
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to configure the audio device", result);
        goto fail;
    }

    memset(&format, 0, sizeof(format));
    format.wFormatTag = WAVE_FORMAT_PCM;
    format.nChannels = (WORD)JUNGLE_RECOMP_AUDIO_CHANNELS;
    format.nSamplesPerSec = (DWORD)output->device_sample_rate;
    format.wBitsPerSample = 16u;
    format.nBlockAlign = (WORD)AUDIO_BLOCK_ALIGN_BYTES;
    format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;

    memset(&description, 0, sizeof(description));
    description.dwSize = sizeof(description);
    description.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
    result = IDirectSound8_CreateSoundBuffer(
        output->direct_sound, &description, &output->primary_buffer, NULL);
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to create the primary audio buffer", result);
        goto fail;
    }
    result = IDirectSoundBuffer_SetFormat(output->primary_buffer, &format);
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to set the selected stereo output rate",
                         result);
        goto fail;
    }

    output->target_latency_frames =
        (uint32_t)(((uint64_t)output->device_sample_rate *
                    (uint64_t)(settings->safety_buffer_ms +
                        (settings->latency_enabled ?
                            settings->latency_ms : 0))) / 1000u);
    /* Exact Mesen capacity rule: requested latency in bytes, doubled, then
       rounded upward to a 64-KiB DirectSound block. */
    requested_bytes = (DWORD)((uint64_t)output->target_latency_frames *
                              AUDIO_BLOCK_ALIGN_BYTES * 2u);
    output->buffer_size_bytes = valid_ring_size(requested_bytes);
    memset(&description, 0, sizeof(description));
    description.dwSize = sizeof(description);
    description.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY |
                          DSBCAPS_GETCURRENTPOSITION2 |
                          DSBCAPS_GLOBALFOCUS | DSBCAPS_LOCSOFTWARE |
                          DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY;
    description.dwBufferBytes = output->buffer_size_bytes;
    description.lpwfxFormat = &format;
    description.guid3DAlgorithm = GUID_NULL;
    result = IDirectSound8_CreateSoundBuffer(
        output->direct_sound, &description, &temporary, NULL);
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to create the playback ring buffer", result);
        goto fail;
    }
    result = IDirectSoundBuffer_QueryInterface(
        temporary, &IID_IDirectSoundBuffer8,
        (void **)&output->secondary_buffer);
    IDirectSoundBuffer_Release(temporary);
    temporary = NULL;
    if (FAILED(result)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to initialize DirectSound 8 playback", result);
        goto fail;
    }
    (void)IDirectSoundBuffer8_SetVolume(output->secondary_buffer,
                                        DSBVOLUME_MAX);
    (void)IDirectSoundBuffer8_SetFrequency(output->secondary_buffer,
        (DWORD)output->device_sample_rate);
    if (!clear_secondary_buffer(output)) {
        set_dsound_error(error, error_capacity,
                         L"Unable to clear the playback ring buffer",
                         E_FAIL);
        goto fail;
    }
    jungle_audio_resampler_set_rates(&output->resampler,
        (double)JUNGLE_RECOMP_AUDIO_SAMPLE_RATE,
        (double)output->device_sample_rate);
    jungle_audio_resampler_set_mode(&output->resampler,
                                    settings->resampler_mode);
    jungle_audio_resampler_reset(&output->resampler);
    output->playback_ratio = 1.0;
    output->paused = 1;
    output->priming = 1;
    output->fade_frames_remaining = output->fade_frames_total;
    output->diagnostics.target_latency_frames =
        output->target_latency_frames;
    output->diagnostics.playback_ratio = 1.0f;
    output->diagnostics.device_sample_rate =
        output->device_sample_rate;
    return 1;

fail:
    if (temporary) IDirectSoundBuffer_Release(temporary);
    release_buffers(output);
    memset(output, 0, sizeof(*output));
    return 0;
}

static void validate_write_cursor(JungleStrikeAudioOutput *output,
                                  DWORD safe_write_cursor) {
    int32_t write_gap;
    if (!output) return;
    write_gap = (int32_t)output->write_offset - (int32_t)safe_write_cursor;
    /* This is Mesen's DirectSound underrun rule.  If the driver's protected
       write cursor has only just overtaken our producer, move forward to the
       first safe byte instead of overwriting audio the device is consuming.
       A large negative value is the normal ring-wrap case. */
    if (write_gap < 0 && write_gap >= -10000) {
        output->diagnostics.underruns++;
        if (output->realign_on_underrun)
            output->write_offset = safe_write_cursor;
    }
}

static int get_cursors(JungleStrikeAudioOutput *output,
                       DWORD *play_cursor, DWORD *safe_write_cursor) {
    DWORD play;
    DWORD safe;
    HRESULT result;
    if (!output || !output->secondary_buffer) return 0;
    result = IDirectSoundBuffer8_GetCurrentPosition(
        output->secondary_buffer, &play, &safe);
    if (FAILED(result)) return 0;
    /* Cursor observation must remain read-only.  Mesen validates the write
       cursor from PlayBuffer/ProcessEndOfFrame; queue and diagnostics reads
       must never move the producer. */
    if (play_cursor) *play_cursor = play;
    if (safe_write_cursor) *safe_write_cursor = safe;
    return 1;
}

static uint32_t queued_host_frames(JungleStrikeAudioOutput *output) {
    DWORD play_cursor;
    DWORD queued_bytes;
    if (!output || !output->secondary_buffer) return 0u;
    if (!get_cursors(output, &play_cursor, NULL)) return 0u;
    queued_bytes = output->write_offset >= play_cursor ?
        output->write_offset - play_cursor :
        output->buffer_size_bytes - play_cursor + output->write_offset;
    return (uint32_t)(queued_bytes / AUDIO_BLOCK_ALIGN_BYTES);
}

static uint32_t safe_queue_frames(JungleStrikeAudioOutput *output) {
    DWORD safe_write_cursor;
    DWORD queued_bytes;
    if (!output || !output->secondary_buffer) return 0u;
    if (!get_cursors(output, NULL, &safe_write_cursor)) return 0u;
    queued_bytes = output->write_offset >= safe_write_cursor ?
        output->write_offset - safe_write_cursor :
        output->buffer_size_bytes - safe_write_cursor + output->write_offset;
    return (uint32_t)(queued_bytes / AUDIO_BLOCK_ALIGN_BYTES);
}

static void reset_rate_control(JungleStrikeAudioOutput *output) {
    output->queue_history_index = 0u;
    output->queue_history_count = 0u;
    output->under_target = 0;
    memset(output->queue_history, 0, sizeof(output->queue_history));
    output->playback_ratio = 1.0;
    output->diagnostics.playback_ratio = 1.0f;
    jungle_audio_resampler_set_rates(&output->resampler,
        (double)JUNGLE_RECOMP_AUDIO_SAMPLE_RATE,
        (double)output->device_sample_rate);
    jungle_audio_resampler_reset(&output->resampler);
}

void jungle_audio_output_flush(JungleStrikeAudioOutput *output) {
    if (!output || !output->secondary_buffer) return;
    (void)IDirectSoundBuffer8_Stop(output->secondary_buffer);
    output->playing = 0;
    (void)clear_secondary_buffer(output);
    output->priming = 1;
    output->starved_last_pump = 0;
    reset_rate_control(output);
    output->diagnostics.queue_depth_frames = 0u;
}

void jungle_audio_output_close(JungleStrikeAudioOutput *output) {
    if (!output) return;
    if (output->secondary_buffer)
        (void)IDirectSoundBuffer8_Stop(output->secondary_buffer);
    release_buffers(output);
    memset(output, 0, sizeof(*output));
}

void jungle_audio_output_pause(JungleStrikeAudioOutput *output) {
    if (!output || !output->secondary_buffer || output->paused) return;
    if (SUCCEEDED(IDirectSoundBuffer8_Stop(output->secondary_buffer))) {
        output->playing = 0;
        output->paused = 1;
        /* Mesen Pause stops playback without destroying queued samples.
           Stop/flush is the operation that clears the secondary buffer. */
    }
}

static int start_playback(JungleStrikeAudioOutput *output) {
    HRESULT result;
    if (!output || !output->secondary_buffer) return 0;
    result = IDirectSoundBuffer8_Play(
        output->secondary_buffer, 0u, 0u, DSBPLAY_LOOPING);
    if (FAILED(result)) {
        output->diagnostics.queue_failures++;
        return 0;
    }
    output->playing = 1;
    return 1;
}

void jungle_audio_output_resume(JungleStrikeAudioOutput *output) {
    uint32_t queued;
    if (!output || !output->secondary_buffer || !output->paused) return;
    output->paused = 0;
    queued = queued_host_frames(output);
    output->priming = queued < output->target_latency_frames / 2u;
    output->fade_frames_remaining = output->fade_frames_total;
    if (!output->priming) (void)start_playback(output);
}

int jungle_audio_output_is_open(const JungleStrikeAudioOutput *output) {
    return output && output->secondary_buffer != NULL;
}

int32_t jungle_audio_output_pacing_ppm(
    const JungleStrikeAudioOutput *output) {
    (void)output;
    /* Mesen corrects the audio resampling ratio from measured device latency;
       it does not alter the emulated SNES frame clock. */
    return 0;
}

static void process_end_of_frame(JungleStrikeAudioOutput *output) {
    uint32_t queue_frames;
    uint64_t queue_sum = 0u;
    double average_latency_ms;
    double latency_gap;
    double adjustment;
    double sub_adjustment;
    double requested;
    uint32_t index;
    if (!output || !output->secondary_buffer) return;
    (void)IDirectSoundBuffer8_SetFrequency(output->secondary_buffer,
                                            (DWORD)output->device_sample_rate);
    if (output->priming || output->paused || !output->playing) return;
    /* Mesen BaseSoundManager measures latency from the play cursor to the
       producer cursor.  The protected DirectSound write cursor is only for
       underrun validation and must not be used as the latency target. */
    queue_frames = queued_host_frames(output);
    output->queue_history[output->queue_history_index] = queue_frames;
    output->queue_history_index = (output->queue_history_index + 1u) %
        (uint32_t)output->averaging_frames;
    if (output->queue_history_count < (uint32_t)output->averaging_frames)
        output->queue_history_count++;
    if (output->queue_history_count < (uint32_t)output->averaging_frames)
        return;
    for (index = 0u; index < (uint32_t)output->averaging_frames; ++index)
        queue_sum += output->queue_history[index];
    average_latency_ms =
        ((double)queue_sum / (double)output->averaging_frames) * 1000.0 /
        (double)output->device_sample_rate;
    output->diagnostics.average_latency_ms = (float)average_latency_ms;
    latency_gap = average_latency_ms -
        ((double)output->target_latency_frames * 1000.0 /
         (double)output->device_sample_rate);
    if (!output->drift_correction_enabled) {
        output->under_target = 0;
        output->playback_ratio = 1.0;
        jungle_audio_resampler_set_rates(&output->resampler,
            (double)JUNGLE_RECOMP_AUDIO_SAMPLE_RATE,
            (double)output->device_sample_rate);
        output->diagnostics.playback_ratio = 1.0f;
    }
    adjustment = ceil((fabs(latency_gap) -
                       (double)output->drift_tolerance_ms) * 8.0) *
                 AUDIO_FINE_RATE_STEP;
    if (adjustment < 0.0) adjustment = 0.0;
    if (adjustment > (double)output->max_rate_adjustment_ppm / 1000000.0)
        adjustment = (double)output->max_rate_adjustment_ppm / 1000000.0;
    if (output->drift_correction_enabled &&
        output->integral_correction_enabled && latency_gap < 0.0 &&
        output->under_target < AUDIO_MAX_SUB_ADJUSTMENT)
        output->under_target++;
    else if (output->drift_correction_enabled &&
             output->integral_correction_enabled && latency_gap > 0.0 &&
             output->under_target > -AUDIO_MAX_SUB_ADJUSTMENT)
        output->under_target--;
    if (!output->drift_correction_enabled ||
        !output->integral_correction_enabled) output->under_target = 0;
    sub_adjustment = AUDIO_FINE_RATE_STEP *
                     (double)output->under_target / 180.0;
    requested = output->playback_ratio;
    if (output->drift_correction_enabled && adjustment > 0.0) {
        if (latency_gap > (double)output->drift_tolerance_ms)
            requested = 1.0 - adjustment + sub_adjustment;
        else if (latency_gap < -(double)output->drift_tolerance_ms)
            requested = 1.0 + adjustment + sub_adjustment;
    } else if (output->drift_correction_enabled && fabs(latency_gap) < 1.0) {
        requested = 1.0 + sub_adjustment;
    }
    if (output->drift_correction_enabled) {
        output->playback_ratio = requested;
        jungle_audio_resampler_set_rates(&output->resampler,
            (double)JUNGLE_RECOMP_AUDIO_SAMPLE_RATE,
            (double)output->device_sample_rate * requested);
        output->diagnostics.playback_ratio = (float)requested;
    }
    if (output->recovery_enabled && average_latency_ms > 0.0 &&
        fabs(latency_gap) > (double)output->recovery_threshold_ms) {
        /* Mesen stops and reprimes when measured play-cursor latency is more
           than 50 ms from the requested value.  It does not discard pending
           core PCM based on a custom hard queue limit. */
        (void)IDirectSoundBuffer8_Stop(output->secondary_buffer);
        output->playing = 0;
        if (clear_secondary_buffer(output)) {
            output->diagnostics.queue_recoveries++;
            output->priming = 1;
            output->starved_last_pump = 0;
            reset_rate_control(output);
            output->diagnostics.queue_depth_frames = 0u;
            output->diagnostics.safe_queue_depth_frames = 0u;
        } else {
            output->diagnostics.queue_failures++;
        }
    }
}

static int write_secondary_buffer(JungleStrikeAudioOutput *output,
                                  const int16_t *samples,
                                  size_t frame_count) {
    void *first = NULL;
    void *second = NULL;
    DWORD first_size = 0u;
    DWORD second_size = 0u;
    DWORD byte_count;
    HRESULT result;
    DWORD safe_write_cursor;
    if (!output || !output->secondary_buffer || !samples || !frame_count)
        return 0;
    byte_count = (DWORD)(frame_count * AUDIO_BLOCK_ALIGN_BYTES);
    if (byte_count > output->buffer_size_bytes) return 0;
    if (!get_cursors(output, NULL, &safe_write_cursor)) return 0;
    /* Mesen PlayBuffer validation: realign only at an actual submission. */
    validate_write_cursor(output, safe_write_cursor);
    result = IDirectSoundBuffer8_Lock(
        output->secondary_buffer, output->write_offset, byte_count,
        &first, &first_size, &second, &second_size, 0u);
    if (result == DSERR_BUFFERLOST && restore_secondary_buffer(output)) {
        result = IDirectSoundBuffer8_Lock(
            output->secondary_buffer, output->write_offset, byte_count,
            &first, &first_size, &second, &second_size, 0u);
    }
    if (FAILED(result)) return 0;
    memcpy(first, samples, first_size);
    if (second && second_size)
        memcpy(second, (const uint8_t *)samples + first_size, second_size);
    result = IDirectSoundBuffer8_Unlock(
        output->secondary_buffer, first, first_size, second, second_size);
    if (FAILED(result)) return 0;
    output->write_offset =
        (output->write_offset + byte_count) % output->buffer_size_bytes;
    return 1;
}

static void apply_volume(JungleStrikeAudioOutput *output, int16_t *samples,
                         size_t frame_count) {
    size_t frame;
    if (!output || !samples) return;
    for (frame = 0u; frame < frame_count; ++frame) {
        int percent = output->volume_percent;
        if (output->fade_frames_remaining && output->fade_frames_total) {
            uint32_t completed = output->fade_frames_total -
                                 output->fade_frames_remaining;
            percent = (int)((uint64_t)percent * completed /
                            output->fade_frames_total);
            output->fade_frames_remaining--;
        }
        samples[frame * 2u] = (int16_t)(
            (int32_t)samples[frame * 2u] * percent / 100);
        samples[frame * 2u + 1u] = (int16_t)(
            (int32_t)samples[frame * 2u + 1u] * percent / 100);
    }
}

static void pump_audio(JungleStrikeAudioOutput *output,
                       JungleStrikeRecomp *game, int end_of_frame) {
    int16_t native_staging[AUDIO_NATIVE_STAGING_FRAMES *
                           JUNGLE_RECOMP_AUDIO_CHANNELS];
    int16_t host_staging[AUDIO_HOST_STAGING_FRAMES *
                         JUNGLE_RECOMP_AUDIO_CHANNELS];
    if (output && output->secondary_buffer && !output->paused &&
        output->playing) {
        uint32_t queue_before = queued_host_frames(output);
        int starved = queue_before == 0u;
        if (starved && !output->starved_last_pump)
            output->diagnostics.underruns++;
        output->starved_last_pump = starved;
    }
    if (!game) return;
    while (jungle_recomp_audio_available(game) > 0u) {
        size_t available = jungle_recomp_audio_available(game);
        size_t request = available > AUDIO_NATIVE_STAGING_FRAMES ?
                         AUDIO_NATIVE_STAGING_FRAMES : available;
        size_t frames = jungle_recomp_audio_read(game, native_staging,
                                                 request);
        if (!frames) break;
        if (output && output->secondary_buffer) {
            size_t host_frames = jungle_audio_resampler_process(
                &output->resampler, native_staging, frames, host_staging,
                AUDIO_HOST_STAGING_FRAMES);
            apply_volume(output, host_staging, host_frames);
            if (!write_secondary_buffer(output, host_staging, host_frames)) {
                output->diagnostics.queue_failures++;
            } else {
                output->diagnostics.native_frames_queued += frames;
            }
        }
    }
    if (!output || !output->secondary_buffer) return;
    if (end_of_frame) {
        DWORD safe_write_cursor;
        /* Mesen ProcessEndOfFrame validation.  This is deliberately the only
           validation outside actual buffer submission. */
        if (get_cursors(output, NULL, &safe_write_cursor))
            validate_write_cursor(output, safe_write_cursor);
    }
    output->diagnostics.queue_depth_frames = queued_host_frames(output);
    output->diagnostics.safe_queue_depth_frames = safe_queue_frames(output);
    if (output->diagnostics.peak_queue_depth_frames <
        output->diagnostics.queue_depth_frames)
        output->diagnostics.peak_queue_depth_frames =
            output->diagnostics.queue_depth_frames;
    if (output->priming && !output->paused &&
        output->diagnostics.queue_depth_frames >=
            output->target_latency_frames / 2u) {
        /* Exact Mesen startup rule: begin playback once half the requested
           latency has been written relative to the play cursor. */
        if (start_playback(output)) output->priming = 0;
    }
    if (end_of_frame && !output->paused && !output->priming &&
        output->playing) {
        if (output->diagnostics.queue_depth_frames > 0u)
            output->starved_last_pump = 0;
        process_end_of_frame(output);
    }
}

void jungle_audio_output_pump(JungleStrikeAudioOutput *output,
                              JungleStrikeRecomp *game) {
    pump_audio(output, game, 1);
}

void jungle_audio_output_pump_progress(JungleStrikeAudioOutput *output,
                                       JungleStrikeRecomp *game) {
    pump_audio(output, game, 0);
}

void jungle_audio_output_get_diagnostics(
    const JungleStrikeAudioOutput *output,
    JungleStrikeAudioDiagnostics *diagnostics) {
    if (!diagnostics) return;
    if (!output) memset(diagnostics, 0, sizeof(*diagnostics));
    else *diagnostics = output->diagnostics;
}
