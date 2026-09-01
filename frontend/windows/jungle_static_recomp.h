#ifndef JUNGLE_STATIC_RECOMP_FRONTEND_H
#define JUNGLE_STATIC_RECOMP_FRONTEND_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define JUNGLE_RECOMP_ROM_SIZE 2097152u
#define JUNGLE_RECOMP_FRAME_WIDTH 256u
#define JUNGLE_RECOMP_FRAME_HEIGHT 224u
#define JUNGLE_RECOMP_AUDIO_SAMPLE_RATE 32040u
#define JUNGLE_RECOMP_HOST_AUDIO_SAMPLE_RATE 32040u
#define JUNGLE_RECOMP_AUDIO_CHANNELS 2u
#define JUNGLE_RECOMP_PRESENTATION_FPS_NUMERATOR 39375000u
#define JUNGLE_RECOMP_PRESENTATION_FPS_DENOMINATOR 655171u

enum JungleStrikeRecompInput {
    JUNGLE_INPUT_B = 0x8000u, JUNGLE_INPUT_Y = 0x4000u,
    JUNGLE_INPUT_SELECT = 0x2000u, JUNGLE_INPUT_START = 0x1000u,
    JUNGLE_INPUT_UP = 0x0800u, JUNGLE_INPUT_DOWN = 0x0400u,
    JUNGLE_INPUT_LEFT = 0x0200u, JUNGLE_INPUT_RIGHT = 0x0100u,
    JUNGLE_INPUT_A = 0x0080u, JUNGLE_INPUT_X = 0x0040u,
    JUNGLE_INPUT_L = 0x0020u, JUNGLE_INPUT_R = 0x0010u
};

typedef struct JungleStrikeRecomp JungleStrikeRecomp;
typedef void (*JungleStrikeRecompAudioProgressCallback)(
    JungleStrikeRecomp *instance, void *opaque);
typedef struct JungleStrikeRecompFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} JungleStrikeRecompFrameResult;

int jungle_recomp_create(JungleStrikeRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity);
void jungle_recomp_destroy(JungleStrikeRecomp *instance);
int jungle_recomp_reset(JungleStrikeRecomp *instance,
                        char *error, size_t error_capacity);
int jungle_recomp_advance(JungleStrikeRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          JungleStrikeRecompFrameResult *result);
int jungle_recomp_advance_streamed(
    JungleStrikeRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    JungleStrikeRecompAudioProgressCallback audio_progress, void *opaque,
    JungleStrikeRecompFrameResult *result);
int jungle_recomp_advance_headless(JungleStrikeRecomp *instance,
                                   uint16_t input_mask,
                                   uint32_t frame_count,
                                   JungleStrikeRecompFrameResult *result);
const uint32_t *jungle_recomp_frame_bgra(const JungleStrikeRecomp *instance);
uint32_t jungle_recomp_frame_width(const JungleStrikeRecomp *instance);
uint32_t jungle_recomp_current_frame(const JungleStrikeRecomp *instance);
uint64_t jungle_recomp_instruction_count(const JungleStrikeRecomp *instance);
int jungle_recomp_failed(const JungleStrikeRecomp *instance);
const char *jungle_recomp_last_error(const JungleStrikeRecomp *instance);
size_t jungle_recomp_audio_available(const JungleStrikeRecomp *instance);
size_t jungle_recomp_audio_read(JungleStrikeRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity);
size_t jungle_recomp_audio_discard(JungleStrikeRecomp *instance);
int jungle_recomp_audio_overflowed(const JungleStrikeRecomp *instance);
uint64_t jungle_recomp_audio_dropped_frames(
    const JungleStrikeRecomp *instance);
void jungle_recomp_audio_clear_overflow(JungleStrikeRecomp *instance);

int jungle_recomp_widescreen_enabled(const JungleStrikeRecomp *instance);
int jungle_recomp_set_widescreen(JungleStrikeRecomp *instance, int enabled,
                                 char *error, size_t error_capacity);
int jungle_recomp_snapshot_save(const JungleStrikeRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int jungle_recomp_snapshot_load(JungleStrikeRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int jungle_recomp_sram_copy(const JungleStrikeRecomp *instance,
                            void *destination, size_t capacity);
int jungle_recomp_sram_load(JungleStrikeRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity);
int jungle_recomp_sram_dirty(const JungleStrikeRecomp *instance);
void jungle_recomp_sram_mark_clean(JungleStrikeRecomp *instance);

#ifdef __cplusplus
}
#endif
#endif
