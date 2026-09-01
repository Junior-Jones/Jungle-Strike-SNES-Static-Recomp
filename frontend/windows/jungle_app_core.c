#include "jungle_app_core.h"
#include "jungle/jungle_static_core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES 8192u

struct JungleStrikeRecomp {
    JungleStaticCore *core;
    const uint32_t *frame_pixels;
    int16_t audio_samples[JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES *
                          JUNGLE_RECOMP_AUDIO_CHANNELS];
    size_t audio_read_index;
    size_t audio_write_index;
    size_t audio_frames;
    uint32_t current_frame;
    uint64_t instruction_count;
    int failed;
    int audio_overflowed;
    uint64_t audio_frames_dropped;
    char last_error[4096];
};

static void set_error(char *destination, size_t capacity,
                      const char *message) {
    if (!destination || !capacity) return;
    (void)snprintf(destination, capacity, "%s", message ? message : "");
    destination[capacity - 1u] = '\0';
}

static void set_instance_error(JungleStrikeRecomp *instance,
                               const char *message) {
    if (instance) set_error(instance->last_error,
                            sizeof(instance->last_error), message);
}

#ifdef _WIN32
static wchar_t *wide_from_utf8(const char *text) {
    wchar_t *wide;
    int length;
    if (!text) return NULL;
    length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                 text, -1, NULL, 0);
    if (length <= 0) return NULL;
    wide = (wchar_t *)malloc((size_t)length * sizeof(*wide));
    if (!wide) return NULL;
    if (!MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                             text, -1, wide, length)) {
        free(wide);
        return NULL;
    }
    return wide;
}

static FILE *open_utf8_file(const char *path, const char *mode) {
    wchar_t *wide_path = wide_from_utf8(path);
    wchar_t *wide_mode = wide_from_utf8(mode);
    FILE *file = NULL;
    if (wide_path && wide_mode) file = _wfopen(wide_path, wide_mode);
    free(wide_mode);
    free(wide_path);
    return file;
}

static int remove_utf8_file(const char *path) {
    wchar_t *wide_path = wide_from_utf8(path);
    int result = -1;
    if (wide_path) result = _wremove(wide_path);
    free(wide_path);
    return result;
}

static int replace_utf8_file(const char *source, const char *destination) {
    wchar_t *wide_source = wide_from_utf8(source);
    wchar_t *wide_destination = wide_from_utf8(destination);
    int result = 0;
    if (wide_source && wide_destination)
        result = MoveFileExW(wide_source, wide_destination,
                             MOVEFILE_REPLACE_EXISTING |
                             MOVEFILE_WRITE_THROUGH) != 0;
    free(wide_destination);
    free(wide_source);
    return result;
}
#else
static FILE *open_utf8_file(const char *path, const char *mode) {
    return fopen(path, mode);
}

static int remove_utf8_file(const char *path) {
    return remove(path);
}

static int replace_utf8_file(const char *source, const char *destination) {
    return rename(source, destination) == 0;
}
#endif

static int append_audio(JungleStrikeRecomp *instance) {
    JungleCoreAudio audio;
    const int16_t *source;
    size_t frames;
    size_t free_frames;
    size_t dropped;
    size_t first;
    memset(&audio, 0, sizeof(audio));
    if (!jungle_core_take_audio(instance->core, &audio) ||
        !audio.frame_count) return 1;
    source = audio.interleaved_stereo;
    frames = audio.frame_count;
    if (frames >= JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES) {
        dropped = instance->audio_frames +
                  (frames - JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES);
        source += (frames - JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES) *
                  JUNGLE_RECOMP_AUDIO_CHANNELS;
        frames = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
        instance->audio_read_index = 0u;
        instance->audio_write_index = 0u;
        instance->audio_frames = 0u;
        if (dropped) {
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = 1;
        }
    } else {
        free_frames = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES -
                      instance->audio_frames;
        if (frames > free_frames) {
            dropped = frames - free_frames;
            instance->audio_read_index =
                (instance->audio_read_index + dropped) %
                JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
            instance->audio_frames -= dropped;
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = 1;
        }
    }
    first = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_write_index;
    if (first > frames) first = frames;
    memcpy(instance->audio_samples +
               instance->audio_write_index * JUNGLE_RECOMP_AUDIO_CHANNELS,
           source,
           first * JUNGLE_RECOMP_AUDIO_CHANNELS * sizeof(int16_t));
    if (frames > first) {
        memcpy(instance->audio_samples,
               source + first * JUNGLE_RECOMP_AUDIO_CHANNELS,
               (frames - first) * JUNGLE_RECOMP_AUDIO_CHANNELS *
                   sizeof(int16_t));
    }
    instance->audio_write_index =
        (instance->audio_write_index + frames) %
        JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
    instance->audio_frames += frames;
    return 1;
}

typedef struct JungleStrikeAudioProgressContext {
    JungleStrikeRecomp *instance;
    JungleStrikeRecompAudioProgressCallback callback;
    void *opaque;
    int failed;
} JungleStrikeAudioProgressContext;

static void stream_audio_progress(JungleStaticCore *core, void *opaque) {
    JungleStrikeAudioProgressContext *context =
        (JungleStrikeAudioProgressContext *)opaque;
    (void)core;
    if (!context || context->failed) return;
    if (!append_audio(context->instance)) {
        context->failed = 1;
        return;
    }
    if (context->callback)
        context->callback(context->instance, context->opaque);
}

static int refresh_status(JungleStrikeRecomp *instance) {
    JungleCoreFrame frame;
    JungleCoreStatus status;
    JungleCoreFailure failure;
    memset(&frame, 0, sizeof(frame));
    if (jungle_core_get_frame(instance->core, &frame) && frame.bgra_pixels)
        instance->frame_pixels = frame.bgra_pixels;
    memset(&status, 0, sizeof(status));
    if (jungle_core_status(instance->core, &status)) {
        instance->current_frame = (uint32_t)status.frame_number;
        instance->instruction_count = status.retired_scpu_instructions;
    }
    memset(&failure, 0, sizeof(failure));
    if (jungle_core_failure(instance->core, &failure) && failure.failed) {
        char detail[4096];
        instance->failed = 1;
        (void)snprintf(
            detail, sizeof(detail),
            "Stop code: %u\r\n"
            "Processor: %s\r\n"
            "Reason: %s\r\n"
            "Frame: %llu\r\n"
            "Master clock: %llu\r\n"
            "Current context: %s\r\n"
            "Source context: %s\r\n"
            "Target context: %s\r\n"
            "Expected successor count: %u\r\n"
            "Expected successors: %s\r\n"
            "Recent context count: %u\r\n"
            "Recent contexts (oldest to newest): %s",
            (unsigned)failure.stop_code,
            failure.processor[0] ? failure.processor : "unknown",
            failure.reason[0] ? failure.reason : "unknown static-core stop",
            (unsigned long long)failure.frame_number,
            (unsigned long long)failure.master_clock,
            failure.context[0] ? failure.context : "unknown",
            failure.source_context[0] ? failure.source_context : "unknown",
            failure.target_context[0] ? failure.target_context : "unknown",
            (unsigned)failure.expected_context_count,
            failure.expected_contexts[0] ? failure.expected_contexts : "none recorded",
            (unsigned)failure.recent_context_count,
            failure.recent_contexts[0] ? failure.recent_contexts : "none recorded");
        set_instance_error(instance, detail);
        return 0;
    }
    return 1;
}

int jungle_recomp_create(JungleStrikeRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity) {
    JungleStrikeRecomp *instance;
    JungleCoreRomInfo info;
    if (out_instance) *out_instance = NULL;
    if (!out_instance || !rom || rom_size != JUNGLE_RECOMP_ROM_SIZE) {
        set_error(error, error_capacity,
                  "Select the exact supported 2 MiB Jungle Strike ROM.");
        return 0;
    }
    memset(&info, 0, sizeof(info));
    if (!jungle_core_inspect_rom(rom, rom_size, &info)) {
        set_error(error, error_capacity,
                  "The Jungle Strike static core rejected this ROM.");
        return 0;
    }
    instance = (JungleStrikeRecomp *)calloc(1u, sizeof(*instance));
    if (!instance) {
        set_error(error, error_capacity, "Out of memory creating the static core.");
        return 0;
    }
    /* jungle_core_create() already performs the initial cold power-on. */
    instance->core = jungle_core_create(rom, rom_size);
    if (!instance->core) {
        set_error(error, error_capacity,
                  "The Jungle Strike static core could not power on.");
        jungle_recomp_destroy(instance);
        return 0;
    }
    set_instance_error(instance, "");
    (void)refresh_status(instance);
    *out_instance = instance;
    return 1;
}

void jungle_recomp_destroy(JungleStrikeRecomp *instance) {
    if (!instance) return;
    jungle_core_destroy(instance->core);
    free(instance);
}

int jungle_recomp_reset(JungleStrikeRecomp *instance,
                        char *error, size_t error_capacity) {
    /*
     * The launcher's Reset command means a cold console reset.  The public
     * core's reset entry point models only the SNES hardware reset line and
     * deliberately preserves parts of the running machine.  Reinitializing
     * through power_on prevents queued DSP/PPU state from surviving a reset.
     */
    if (!instance || !instance->core || !jungle_core_power_on(instance->core)) {
        set_error(error, error_capacity, "The Jungle Strike static core reset failed.");
        return 0;
    }
    instance->frame_pixels = NULL;
    instance->audio_read_index = 0u;
    instance->audio_write_index = 0u;
    instance->audio_frames = 0u;
    instance->current_frame = 0u;
    instance->instruction_count = 0u;
    instance->failed = 0;
    instance->audio_overflowed = 0;
    instance->audio_frames_dropped = 0u;
    set_instance_error(instance, "");
    return refresh_status(instance);
}

static int advance_frames(JungleStrikeRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          int render_output,
                          JungleStrikeRecompAudioProgressCallback audio_progress,
                          void *progress_opaque,
                          JungleStrikeRecompFrameResult *result) {
    uint32_t start;
    uint32_t index;
    if (!instance || !instance->core || instance->failed) return 0;
    start = instance->current_frame;
    for (index = 0u; index < frame_count; ++index) {
        JungleStrikeAudioProgressContext progress_context;
        int advanced;
        memset(&progress_context, 0, sizeof(progress_context));
        progress_context.instance = instance;
        progress_context.callback = audio_progress;
        progress_context.opaque = progress_opaque;
        if (render_output && audio_progress)
            advanced = jungle_core_run_frame_streamed(
                instance->core, input_mask, 0u, stream_audio_progress,
                &progress_context);
        else
            advanced = render_output ?
                jungle_core_run_frame(instance->core, input_mask, 0u) :
                jungle_core_run_frame_headless(instance->core, input_mask, 0u);
        if (!advanced) {
            (void)refresh_status(instance);
            return 0;
        }
        if (progress_context.failed) return 0;
        if (!append_audio(instance) || !refresh_status(instance)) return 0;
    }
    if (result) {
        memset(result, 0, sizeof(*result));
        result->route_continued = 1u;
        result->frame_rendered =
            render_output && instance->frame_pixels != NULL;
        result->input_mask = input_mask;
        result->start_frame = start;
        result->end_frame = instance->current_frame;
    }
    return 1;
}

int jungle_recomp_advance(JungleStrikeRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          JungleStrikeRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 1, NULL, NULL,
                          result);
}

int jungle_recomp_advance_streamed(
    JungleStrikeRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    JungleStrikeRecompAudioProgressCallback audio_progress, void *opaque,
    JungleStrikeRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 1,
                          audio_progress, opaque, result);
}

int jungle_recomp_advance_headless(JungleStrikeRecomp *instance,
                                   uint16_t input_mask,
                                   uint32_t frame_count,
                                   JungleStrikeRecompFrameResult *result) {
    return advance_frames(instance, input_mask, frame_count, 0, NULL, NULL,
                          result);
}

const uint32_t *jungle_recomp_frame_bgra(const JungleStrikeRecomp *instance) {
    return instance ? instance->frame_pixels : NULL;
}

uint32_t jungle_recomp_frame_width(const JungleStrikeRecomp *instance) {
    (void)instance;
    return JUNGLE_RECOMP_FRAME_WIDTH;
}

uint32_t jungle_recomp_current_frame(const JungleStrikeRecomp *instance) {
    return instance ? instance->current_frame : 0u;
}

uint64_t jungle_recomp_instruction_count(const JungleStrikeRecomp *instance) {
    return instance ? instance->instruction_count : 0u;
}

int jungle_recomp_failed(const JungleStrikeRecomp *instance) {
    return instance ? instance->failed : 1;
}

const char *jungle_recomp_last_error(const JungleStrikeRecomp *instance) {
    return instance ? instance->last_error : "No static core is loaded.";
}

size_t jungle_recomp_audio_available(const JungleStrikeRecomp *instance) {
    return instance ? instance->audio_frames : 0u;
}

size_t jungle_recomp_audio_read(JungleStrikeRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity) {
    size_t frames;
    size_t first;
    if (!instance || !interleaved_stereo || !frame_capacity) return 0u;
    frames = instance->audio_frames < frame_capacity ?
             instance->audio_frames : frame_capacity;
    first = JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_read_index;
    if (first > frames) first = frames;
    memcpy(interleaved_stereo,
           instance->audio_samples +
               instance->audio_read_index * JUNGLE_RECOMP_AUDIO_CHANNELS,
           first * JUNGLE_RECOMP_AUDIO_CHANNELS * sizeof(int16_t));
    if (frames > first) {
        memcpy(interleaved_stereo + first * JUNGLE_RECOMP_AUDIO_CHANNELS,
               instance->audio_samples,
               (frames - first) * JUNGLE_RECOMP_AUDIO_CHANNELS *
                   sizeof(int16_t));
    }
    instance->audio_read_index =
        (instance->audio_read_index + frames) %
        JUNGLE_FRONTEND_AUDIO_FIFO_FRAMES;
    instance->audio_frames -= frames;
    if (!instance->audio_frames)
        instance->audio_write_index = instance->audio_read_index;
    return frames;
}

size_t jungle_recomp_audio_discard(JungleStrikeRecomp *instance) {
    size_t discarded = instance ? instance->audio_frames : 0u;
    if (instance) {
        instance->audio_frames = 0u;
        instance->audio_read_index = 0u;
        instance->audio_write_index = 0u;
    }
    return discarded;
}

int jungle_recomp_audio_overflowed(const JungleStrikeRecomp *instance) {
    return instance ? instance->audio_overflowed : 0;
}

uint64_t jungle_recomp_audio_dropped_frames(
    const JungleStrikeRecomp *instance) {
    return instance ? instance->audio_frames_dropped : 0u;
}

void jungle_recomp_audio_clear_overflow(JungleStrikeRecomp *instance) {
    if (instance) instance->audio_overflowed = 0;
}

int jungle_recomp_widescreen_enabled(const JungleStrikeRecomp *instance) {
    (void)instance;
    return 0;
}

int jungle_recomp_set_widescreen(JungleStrikeRecomp *instance, int enabled,
                                 char *error, size_t error_capacity) {
    (void)instance;
    if (!enabled) return 1;
    set_error(error, error_capacity,
              "This Jungle Strike core does not expose widescreen rendering.");
    return 0;
}

static int unsupported(char *error, size_t error_capacity) {
    set_error(error, error_capacity,
              "This operation is not exposed by the Jungle Strike static core.");
    return 0;
}

int jungle_recomp_snapshot_save(const JungleStrikeRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity) {
    size_t size;
    size_t path_length;
    void *buffer = NULL;
    char *temporary = NULL;
    FILE *file = NULL;
    int ok = 0;
    if (!instance || !instance->core || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A running Jungle Strike game is required to save a snapshot.");
        return 0;
    }
    size = jungle_core_snapshot_size(instance->core);
    if (!size) {
        set_error(error, error_capacity,
                  "The static core could not size its complete snapshot state.");
        return 0;
    }
    path_length = strlen(path);
    if (path_length > SIZE_MAX - 16u) {
        set_error(error, error_capacity, "The snapshot path is too long.");
        return 0;
    }
    buffer = malloc(size);
    temporary = (char *)malloc(path_length + 16u);
    if (!buffer || !temporary) {
        set_error(error, error_capacity,
                  "Not enough memory to create the snapshot.");
        goto cleanup;
    }
    if (!jungle_core_save_snapshot(instance->core, buffer, size)) {
        set_error(error, error_capacity,
                  "The complete static machine state could not be captured.");
        goto cleanup;
    }
    (void)snprintf(temporary, path_length + 16u, "%s.writing", path);
    file = open_utf8_file(temporary, "wb");
    if (!file) {
        (void)remove_utf8_file(temporary);
        set_error(error, error_capacity,
                  "Unable to write the complete snapshot file.");
        goto cleanup;
    }
    if (fwrite(buffer, 1u, size, file) != size || fflush(file) != 0) {
        (void)fclose(file);
        file = NULL;
        (void)remove_utf8_file(temporary);
        set_error(error, error_capacity,
                  "Unable to write the complete snapshot file.");
        goto cleanup;
    }
    if (fclose(file) != 0) {
        file = NULL;
        (void)remove_utf8_file(temporary);
        set_error(error, error_capacity,
                  "Unable to finish writing the complete snapshot file.");
        goto cleanup;
    }
    file = NULL;
    if (!replace_utf8_file(temporary, path)) {
        (void)remove_utf8_file(temporary);
        set_error(error, error_capacity,
                  "Unable to replace the snapshot file.");
        goto cleanup;
    }
    set_error(error, error_capacity, "");
    ok = 1;
cleanup:
    if (file) fclose(file);
    free(temporary);
    free(buffer);
    return ok;
}

int jungle_recomp_snapshot_load(JungleStrikeRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity) {
    size_t expected;
    long file_size;
    void *buffer = NULL;
    FILE *file = NULL;
    int trailing;
    int ok = 0;
    if (!instance || !instance->core || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A running Jungle Strike game is required to load a snapshot.");
        return 0;
    }
    expected = jungle_core_snapshot_size(instance->core);
    if (!expected) {
        set_error(error, error_capacity,
                  "The static core could not size its complete snapshot state.");
        return 0;
    }
    file = open_utf8_file(path, "rb");
    if (!file) {
        set_error(error, error_capacity, "Unable to open the snapshot file.");
        goto cleanup;
    }
    if (fseek(file, 0, SEEK_END) != 0 ||
        (file_size = ftell(file)) < 0 || (size_t)file_size != expected ||
        fseek(file, 0, SEEK_SET) != 0) {
        set_error(error, error_capacity,
                  "The snapshot is invalid or belongs to another build.");
        goto cleanup;
    }
    buffer = malloc(expected);
    if (!buffer) {
        set_error(error, error_capacity,
                  "Not enough memory to load the snapshot.");
        goto cleanup;
    }
    if (fread(buffer, 1u, expected, file) != expected) {
        set_error(error, error_capacity, "The snapshot file is truncated.");
        goto cleanup;
    }
    trailing = fgetc(file);
    if (ferror(file) || trailing != EOF) {
        (void)fclose(file);
        file = NULL;
        set_error(error, error_capacity,
                  "The snapshot has unexpected trailing data.");
        goto cleanup;
    }
    if (fclose(file) != 0) {
        file = NULL;
        set_error(error, error_capacity,
                  "Unable to finish reading the snapshot file.");
        goto cleanup;
    }
    file = NULL;
    if (!jungle_core_load_snapshot(instance->core, buffer, expected)) {
        set_error(error, error_capacity,
                  "The snapshot is corrupt or belongs to another build.");
        goto cleanup;
    }
    instance->frame_pixels = NULL;
    instance->audio_read_index = 0u;
    instance->audio_write_index = 0u;
    instance->audio_frames = 0u;
    instance->failed = 0;
    instance->audio_overflowed = 0;
    instance->audio_frames_dropped = 0u;
    set_instance_error(instance, "");
    if (!refresh_status(instance)) {
        set_error(error, error_capacity,
                  "The snapshot loaded but its static-core status was invalid.");
        goto cleanup;
    }
    set_error(error, error_capacity, "");
    ok = 1;
cleanup:
    if (file) fclose(file);
    free(buffer);
    return ok;
}

int jungle_recomp_sram_copy(const JungleStrikeRecomp *instance,
                            void *destination, size_t capacity) {
    (void)instance; (void)destination; (void)capacity;
    return 0;
}

int jungle_recomp_sram_load(JungleStrikeRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity) {
    (void)instance; (void)source; (void)size;
    return unsupported(error, error_capacity);
}

int jungle_recomp_sram_dirty(const JungleStrikeRecomp *instance) {
    (void)instance;
    return 0;
}

void jungle_recomp_sram_mark_clean(JungleStrikeRecomp *instance) {
    (void)instance;
}

int jungle_recomp_write_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity) {
    size_t size;
    void *buffer;
    FILE *file;
    (void)screenshot_path;
    if (!instance || !instance->core || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A loaded static core and diagnostic path are required.");
        return 0;
    }
    size = jungle_core_diagnostic_snapshot_size(instance->core);
    if (!size) return unsupported(error, error_capacity);
    buffer = malloc(size);
    if (!buffer) {
        set_error(error, error_capacity, "Out of memory exporting diagnostics.");
        return 0;
    }
    if (!jungle_core_save_diagnostic_snapshot(instance->core, buffer, size)) {
        free(buffer);
        return unsupported(error, error_capacity);
    }
    file = fopen(path, "wb");
    if (!file || fwrite(buffer, 1u, size, file) != size) {
        if (file) fclose(file);
        free(buffer);
        set_error(error, error_capacity, "Unable to write the diagnostic log.");
        return 0;
    }
    free(buffer);
    if (fclose(file) != 0) {
        set_error(error, error_capacity, "Unable to finish the diagnostic log.");
        return 0;
    }
    return 1;
}

int jungle_recomp_append_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity) {
    size_t size;
    void *buffer;
    FILE *file;
    size_t text_size;
    if (!instance || !instance->core || !path || !path[0]) {
        set_error(error, error_capacity,
                  "A loaded static core and diagnostic path are required.");
        return 0;
    }
    size = jungle_core_diagnostic_snapshot_size(instance->core);
    if (!size) return unsupported(error, error_capacity);
    buffer = malloc(size);
    if (!buffer) {
        set_error(error, error_capacity, "Out of memory exporting diagnostics.");
        return 0;
    }
    if (!jungle_core_save_diagnostic_snapshot(instance->core, buffer, size)) {
        free(buffer);
        return unsupported(error, error_capacity);
    }
    text_size = strlen((const char *)buffer);
    file = fopen(path, "ab");
    if (!file ||
        fprintf(file, "\r\n--- %s ---\r\n",
                section_title && section_title[0] ? section_title :
                "Static-core diagnostic snapshot") < 0 ||
        fwrite(buffer, 1u, text_size, file) != text_size ||
        fwrite("\r\n", 1u, 2u, file) != 2u) {
        if (file) fclose(file);
        free(buffer);
        set_error(error, error_capacity, "Unable to append the diagnostic log.");
        return 0;
    }
    free(buffer);
    if (fclose(file) != 0) {
        set_error(error, error_capacity, "Unable to finish the diagnostic log.");
        return 0;
    }
    return 1;
}
