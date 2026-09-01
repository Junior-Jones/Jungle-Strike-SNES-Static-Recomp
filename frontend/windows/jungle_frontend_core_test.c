#include "jungle_app_core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file(const char *path, size_t *size) {
    FILE *file;
    long length;
    uint8_t *data;
    *size = 0u;
    file = fopen(path, "rb");
    if (!file) return NULL;
    if (fseek(file, 0, SEEK_END) != 0 || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET) != 0) {
        fclose(file);
        return NULL;
    }
    data = (uint8_t *)malloc((size_t)length);
    if (!data || fread(data, 1u, (size_t)length, file) != (size_t)length) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *size = (size_t)length;
    return data;
}

static uint64_t hash_frame(const uint32_t *pixels) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u;
         index < JUNGLE_RECOMP_FRAME_WIDTH * JUNGLE_RECOMP_FRAME_HEIGHT;
         ++index) {
        hash ^= pixels[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static uint16_t logged_test_input(uint32_t frame) {
    static const struct { uint32_t frame; uint16_t mask; } events[] = {
        {772u,0x1000u},{1019u,0x0080u},{1137u,0x8000u},
        {1341u,0x0020u},{1364u,0x0010u},{1398u,0x4000u},
        {1414u,0x0040u},{1482u,0x2000u},{1921u,0x2000u},
        {2158u,0x1000u},{2580u,0x1000u},{2750u,0x1000u},
        {3053u,0x8000u},{3158u,0x0080u},{3338u,0x0040u},
        {3475u,0x4000u},{3634u,0x1000u},{4418u,0x1000u},
        {4535u,0x0080u},{4605u,0x8000u},{4725u,0x0040u},
        {4803u,0x4000u},{5138u,0x2000u},
    };
    size_t index;
    for (index = 0u; index < sizeof(events) / sizeof(events[0]); ++index)
        if (events[index].frame == frame) return events[index].mask;
    return 0u;
}

static int run_logged_timeline(JungleStrikeRecomp *game, uint32_t frame_limit) {
    JungleStrikeRecompFrameResult result;
    uint32_t frame;
    for (frame = 0u; frame < frame_limit; ++frame) {
        uint16_t input = logged_test_input(frame);
        if (!jungle_recomp_advance(game, input, 1u, &result)) {
            fprintf(stderr, "FAIL: logged render timeline stopped at frame %u: %s\n",
                    frame, jungle_recomp_last_error(game));
            return 0;
        }
        (void)jungle_recomp_audio_discard(game);
    }
    return 1;
}

static int run_mixed_render_timeline(JungleStrikeRecomp *game,
                                     uint32_t frame_limit) {
    JungleStrikeRecompFrameResult result;
    while (jungle_recomp_current_frame(game) < frame_limit) {
        uint32_t frame = jungle_recomp_current_frame(game);
        uint16_t input = logged_test_input(frame);
        int advanced = (frame & 1u) ?
            jungle_recomp_advance(game, input, 1u, &result) :
            jungle_recomp_advance_headless(game, input, 1u, &result);
        if (!advanced) {
            fprintf(stderr, "FAIL: mixed render timeline stopped at frame %u: %s\n",
                    frame, jungle_recomp_last_error(game));
            return 0;
        }
        (void)jungle_recomp_audio_discard(game);
    }
    return 1;
}

static int run_segment(JungleStrikeRecomp *game, int discard_video,
                       uint32_t frame_limit,
                       uint64_t *frame_hash, size_t *audio_total) {
    JungleStrikeRecompFrameResult result;
    uint32_t frame;
    *audio_total = 0u;
    for (frame = 0u; frame < frame_limit; ++frame) {
        int advanced = discard_video && frame + 1u < frame_limit ?
            jungle_recomp_advance_headless(game, 0u, 1u, &result) :
            jungle_recomp_advance(game, 0u, 1u, &result);
        if (!advanced) return 0;
        *audio_total += jungle_recomp_audio_discard(game);
    }
    if (!jungle_recomp_frame_bgra(game)) return 0;
    *frame_hash = hash_frame(jungle_recomp_frame_bgra(game));
    return !jungle_recomp_failed(game);
}

static int run_snapshot_contract(JungleStrikeRecomp *game) {
    static const char base_path[] = "jungle-snapshot-contract-base.scsnap";
    static const char first_path[] = "jungle-snapshot-contract-first.scsnap";
    static const char replay_path[] = "jungle-snapshot-contract-replay.scsnap";
    JungleStrikeRecompFrameResult result;
    uint8_t *first = NULL;
    uint8_t *replay = NULL;
    size_t first_size = 0u;
    size_t replay_size = 0u;
    uint32_t saved_frame;
    uint32_t index;
    char error[256];
    int passed = 0;
    for (index = 0u; index < 180u; ++index) {
        if (!jungle_recomp_advance(game, 0u, 1u, &result)) {
            fprintf(stderr, "FAIL: pre-snapshot advance at %u: %s\n", index,
                    jungle_recomp_last_error(game));
            goto cleanup;
        }
        (void)jungle_recomp_audio_discard(game);
    }
    saved_frame = jungle_recomp_current_frame(game);
    if (!jungle_recomp_snapshot_save(game, base_path, error, sizeof(error))) {
        fprintf(stderr, "FAIL: snapshot save: %s\n", error);
        goto cleanup;
    }
    for (index = 0u; index < 90u; ++index) {
        if (!jungle_recomp_advance(game, 0u, 1u, &result)) {
            fprintf(stderr, "FAIL: first continuation at %u: %s\n", index,
                    jungle_recomp_last_error(game));
            goto cleanup;
        }
        (void)jungle_recomp_audio_discard(game);
    }
    if (!jungle_recomp_snapshot_save(game, first_path, error, sizeof(error))) {
        fprintf(stderr, "FAIL: continuation snapshot: %s\n", error);
        goto cleanup;
    }
    if (!jungle_recomp_snapshot_load(game, base_path, error, sizeof(error))) {
        fprintf(stderr, "FAIL: snapshot load: %s\n", error);
        goto cleanup;
    }
    if (jungle_recomp_current_frame(game) != saved_frame) {
        fputs("FAIL: snapshot did not restore the saved frame\n", stderr);
        goto cleanup;
    }
    for (index = 0u; index < 90u; ++index) {
        if (!jungle_recomp_advance(game, 0u, 1u, &result)) {
            fprintf(stderr, "FAIL: replay continuation at %u: %s\n", index,
                    jungle_recomp_last_error(game));
            goto cleanup;
        }
        (void)jungle_recomp_audio_discard(game);
    }
    if (!jungle_recomp_snapshot_save(game, replay_path, error, sizeof(error))) {
        fprintf(stderr, "FAIL: replay snapshot: %s\n", error);
        goto cleanup;
    }
    first = load_file(first_path, &first_size);
    replay = load_file(replay_path, &replay_size);
    passed = first && replay && first_size == replay_size &&
             memcmp(first, replay, first_size) == 0;
    if (!passed)
        fputs("FAIL: save/load continuation was not byte-deterministic\n", stderr);
#ifdef _WIN32
    if (passed) {
        static const char unicode_path[] =
            "jungle-snapshot-\xE6\xB8\xAC\xE8\xA9\xA6.scsnap";
        if (!jungle_recomp_snapshot_save(game, unicode_path,
                                         error, sizeof(error)) ||
            !jungle_recomp_snapshot_load(game, unicode_path,
                                         error, sizeof(error))) {
            fprintf(stderr, "FAIL: Unicode snapshot path: %s\n", error);
            passed = 0;
        }
        (void)_wremove(L"jungle-snapshot-\x6E2C\x8A66.scsnap");
    }
#endif
cleanup:
    free(first);
    free(replay);
    (void)remove(base_path);
    (void)remove(first_path);
    (void)remove(replay_path);
    return passed;
}

static void discard_streamed_audio(JungleStrikeRecomp *game, void *opaque) {
    size_t *audio_total = (size_t *)opaque;
    if (audio_total) *audio_total += jungle_recomp_audio_discard(game);
}

static int run_external_snapshot(JungleStrikeRecomp *game,
                                 const char *snapshot_path,
                                 uint32_t frame_limit) {
    JungleStrikeRecompFrameResult result;
    char error[256];
    uint32_t index;
    size_t audio_total = 0u;
    memset(error, 0, sizeof(error));
    fprintf(stderr, "Loading external snapshot: %s\n", snapshot_path);
    fflush(stderr);
    if (!jungle_recomp_snapshot_load(game, snapshot_path,
                                     error, sizeof(error))) {
        fprintf(stderr, "FAIL: external snapshot load: %s\n", error);
        return 0;
    }
    fprintf(stderr, "Loaded external snapshot at frame %u\n",
            jungle_recomp_current_frame(game));
    fflush(stderr);
    for (index = 0u; index < frame_limit; ++index) {
        if (!jungle_recomp_advance_streamed(
                game, 0u, 1u, discard_streamed_audio,
                &audio_total, &result)) {
            fprintf(stderr, "FAIL: external snapshot continuation at %u: %s\n",
                    index, jungle_recomp_last_error(game));
            return 0;
        }
        audio_total += jungle_recomp_audio_discard(game);
    }
    printf("PASS: external snapshot advanced %u streamed frames from frame %u "
           "and produced %zu audio frames\n",
           frame_limit, jungle_recomp_current_frame(game) - frame_limit,
           audio_total);
    return 1;
}

int main(void) {
    const char *path = getenv("JUNGLE_STRIKE_ROM");
    uint8_t *rom;
    size_t rom_size;
    JungleStrikeRecomp *game = NULL;
    uint64_t first_hash = 0u;
    uint64_t reset_hash = 0u;
    size_t first_audio = 0u;
    size_t reset_audio = 0u;
    char error[256];
    uint32_t frame_limit = 180u;
    const char *frame_limit_text = getenv("JUNGLE_FRONTEND_TEST_FRAMES");
    const char *logged_timeline = getenv("JUNGLE_FRONTEND_TEST_LOGGED_TIMELINE");
    const char *mixed_timeline = getenv("JUNGLE_FRONTEND_TEST_MIXED_RENDER");
    const char *snapshot_test = getenv("JUNGLE_FRONTEND_TEST_SNAPSHOT");
    const char *external_snapshot =
        getenv("JUNGLE_FRONTEND_TEST_EXTERNAL_SNAPSHOT");
    int passed;
    if (!path || !path[0]) {
        puts("SKIP jungle_frontend_core_test: JUNGLE_STRIKE_ROM not set");
        return 0;
    }
    rom = load_file(path, &rom_size);
    if (!rom) {
        fputs("FAIL: unable to read ROM\n", stderr);
        return 1;
    }
    passed = jungle_recomp_create(&game, rom, rom_size, error, sizeof(error));
    free(rom);
    if (!passed) {
        fprintf(stderr, "FAIL: create: %s\n", error);
        return 1;
    }
    if (frame_limit_text && frame_limit_text[0]) {
        unsigned long parsed = strtoul(frame_limit_text, NULL, 10);
        if (parsed > 0u && parsed <= UINT32_MAX)
            frame_limit = (uint32_t)parsed;
    }
    if (logged_timeline && logged_timeline[0]) {
        passed = run_logged_timeline(game, frame_limit);
        jungle_recomp_destroy(game);
        if (!passed) return 1;
        printf("PASS: logged input/render timeline reproduced %u frames\n",
               frame_limit);
        return 0;
    }
    if (mixed_timeline && mixed_timeline[0]) {
        passed = run_mixed_render_timeline(game, frame_limit);
        jungle_recomp_destroy(game);
        if (!passed) return 1;
        printf("PASS: mixed headless/render timeline reached %u frames\n",
               frame_limit);
        return 0;
    }
    if (snapshot_test && snapshot_test[0]) {
        passed = run_snapshot_contract(game);
        jungle_recomp_destroy(game);
        if (!passed) return 1;
        puts("PASS: complete static-core snapshot restored a byte-identical continuation");
        return 0;
    }
    if (external_snapshot && external_snapshot[0]) {
        passed = run_external_snapshot(game, external_snapshot, frame_limit);
        jungle_recomp_destroy(game);
        return passed ? 0 : 1;
    }
    /* Compare like-for-like headless catch-up routes on both sides of reset.
     * A first rendered frame may intentionally consume one extra emulated
     * frame to resynchronise from the power-on mid-raster position. */
    passed = run_segment(game, 1, frame_limit, &first_hash, &first_audio);
    if (passed)
        passed = jungle_recomp_reset(game, error, sizeof(error));
    if (passed)
        passed = jungle_recomp_current_frame(game) == 0u &&
                 jungle_recomp_audio_available(game) == 0u;
    if (passed)
        passed = run_segment(game, 1, frame_limit, &reset_hash, &reset_audio);
    if (passed)
        passed = first_hash == reset_hash && first_audio == reset_audio &&
                 first_audio > 0u;
    jungle_recomp_destroy(game);
    if (!passed) {
        fprintf(stderr,
                "FAIL: cold reset did not reproduce clean video/audio state "
                "(first_hash=%016llx reset_hash=%016llx first_audio=%zu "
                "reset_audio=%zu)\n",
                (unsigned long long)first_hash,
                (unsigned long long)reset_hash,
                first_audio, reset_audio);
        return 1;
    }
    printf("PASS: cold reset and headless catch-up reproduced %u frames "
           "(%zu audio frames)\n", frame_limit, reset_audio);
    return 0;
}
