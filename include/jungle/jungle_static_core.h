#ifndef JUNGLE_STATIC_CORE_H
#define JUNGLE_STATIC_CORE_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#define JUNGLE_STATIC_CORE_VERSION_STRING "1.0.0"
#define JUNGLE_STATIC_CORE_ROM_SIZE 2097152u
#define JUNGLE_STATIC_CORE_FRAME_WIDTH 256u
#define JUNGLE_STATIC_CORE_FRAME_HEIGHT 224u
#define JUNGLE_STATIC_CORE_AUDIO_CHANNELS 2u
#define JUNGLE_STATIC_CORE_AUDIO_SAMPLE_RATE 32040u
#define JUNGLE_STATIC_CORE_SEALED_CONTEXTS 27835u
#define JUNGLE_STATIC_CORE_PRODUCTION_CONTEXTS 27835u
#define JUNGLE_STATIC_CORE_PRODUCTION_ROM_BYTES 64330u
#define JUNGLE_STATIC_CORE_IMMUTABLE_DATA_BYTES 46386u
#define JUNGLE_STATIC_CORE_ROM_SHA256 "8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159"

typedef struct JungleStaticCore JungleStaticCore;

typedef enum JungleCoreButton {
    JUNGLE_BUTTON_B      = 0x8000u,
    JUNGLE_BUTTON_Y      = 0x4000u,
    JUNGLE_BUTTON_SELECT = 0x2000u,
    JUNGLE_BUTTON_START  = 0x1000u,
    JUNGLE_BUTTON_UP     = 0x0800u,
    JUNGLE_BUTTON_DOWN   = 0x0400u,
    JUNGLE_BUTTON_LEFT   = 0x0200u,
    JUNGLE_BUTTON_RIGHT  = 0x0100u,
    JUNGLE_BUTTON_A      = 0x0080u,
    JUNGLE_BUTTON_X      = 0x0040u,
    JUNGLE_BUTTON_L      = 0x0020u,
    JUNGLE_BUTTON_R      = 0x0010u
} JungleCoreButton;

typedef struct JungleCoreRomInfo {
    size_t file_size;
    size_t canonical_rom_size;
    uint16_t reset_vector;
    uint8_t map_mode;
    uint8_t region_code;
    char title[22];
    char sha256[65];
} JungleCoreRomInfo;

typedef struct JungleCoreFrame {
    const uint32_t *bgra_pixels;
    uint32_t width;
    uint32_t height;
    uint32_t pitch_bytes;
    uint64_t frame_number;
} JungleCoreFrame;

typedef struct JungleCoreAudio {
    const int16_t *interleaved_stereo;
    const uint8_t *frame_known;
    size_t frame_count;
    size_t known_frame_count;
    size_t unknown_frame_count;
    uint32_t sample_rate;
} JungleCoreAudio;

typedef struct JungleCoreFailure {
    uint8_t failed;
    uint32_t stop_code;
    char processor[12];
    char context[40];
    char source_context[40];
    char target_context[40];
    char expected_contexts[320];
    char recent_contexts[1280];
    char reason[192];
    uint32_t expected_context_count;
    uint32_t recent_context_count;
    uint64_t master_clock;
    uint64_t frame_number;
} JungleCoreFailure;

typedef struct JungleCoreStatus {
    uint32_t sealed_contexts;
    uint32_t production_contexts;
    uint32_t production_rom_bytes;
    uint32_t immutable_data_bytes;
    uint32_t sealed_not_production_contexts;
    uint64_t master_clock;
    uint64_t frame_number;
    uint64_t retired_scpu_instructions;
    uint64_t smp_instructions;
    uint64_t smp_cycles;
    uint64_t dsp_phase_steps;
    uint64_t pcm_frames_produced;
    uint64_t pcm_known_frames_produced;
    uint64_t pcm_unknown_frames_produced;
    uint64_t pcm_hash;
    uint8_t pcm_hash_fully_known;
    uint16_t scpu_pc;
    uint8_t scpu_pbr;
    uint16_t smp_pc;
    uint8_t dsp_phase;
    uint8_t frame_valid;
    uint8_t exact_pc_smp_aot;
    uint8_t exact_32_phase_sdsp;
    uint8_t interpreter_fallback_enabled;
    uint32_t machine_stop_code;
    uint32_t renderer_stop_code;
    uint16_t player1_serial_report;
    uint16_t player2_serial_report;
    uint16_t autojoy1_report;
    uint16_t autojoy2_report;
    uint16_t game_input_report;
    uint16_t game_input_transition;
    uint16_t game_input_effective;
    uint16_t game_input_previous;
    uint8_t ppu_forced_blank;
    uint8_t ppu_brightness;
    uint8_t ppu_bg_mode;
    uint8_t ppu_mode1_bg3_priority;
    uint8_t ppu_mosaic_enabled;
    uint8_t ppu_main_screen_layers;
    uint8_t ppu_sub_screen_layers;
    uint8_t ppu_setini_flags;
    uint8_t ppu_bg_large_tile_mask;
    uint8_t ppu_direct_color;
    uint8_t ppu_color_math_add_subscreen;
    uint8_t ppu_active_violation_mask;
    uint64_t ppu_visible_scanlines;
    uint64_t ppu_active_scanlines;
    uint64_t ppu_forced_blank_scanlines;
    uint64_t ppu_brightness_zero_scanlines;
    uint64_t ppu_mode_scanlines[8];
    uint64_t ppu_mode_violation_scanlines;
    uint64_t ppu_bg3_priority_violation_scanlines;
    uint64_t ppu_tile_geometry_violation_scanlines;
    uint64_t ppu_mosaic_violation_scanlines;
    uint64_t ppu_setini_violation_scanlines;
    uint64_t ppu_obj_config_violation_scanlines;
    uint64_t ppu_color_path_violation_scanlines;
    uint64_t ppu_renderer_domain_violation_scanlines;
    uint64_t ppu_register_reads[64];
    uint64_t ppu_register_writes[64];
    uint8_t ppu_observed_read_values[64][32];
    uint8_t ppu_observed_write_values[64][32];
} JungleCoreStatus;

typedef void (*JungleCoreAudioProgressCallback)(JungleStaticCore *core,
                                                void *opaque);

int jungle_core_inspect_rom(const void *data, size_t size, JungleCoreRomInfo *out_info);
JungleStaticCore *jungle_core_create(const void *data, size_t size);
void jungle_core_destroy(JungleStaticCore *core);
int jungle_core_power_on(JungleStaticCore *core);
int jungle_core_reset(JungleStaticCore *core);

/* One call attempts exactly one natural SNES frame. A static-core stop is fail-closed. */
int jungle_core_run_frame(JungleStaticCore *core, uint16_t player1_mask, uint16_t player2_mask);
/* Render a natural frame while exposing completed DSP batches during the
   frame.  This prevents a slow host compositor from blocking PCM delivery. */
int jungle_core_run_frame_streamed(
    JungleStaticCore *core, uint16_t player1_mask, uint16_t player2_mask,
    JungleCoreAudioProgressCallback audio_progress, void *opaque);
/* Advances one natural frame without composing a disposable host framebuffer. */
int jungle_core_run_frame_headless(JungleStaticCore *core,
                                   uint16_t player1_mask,
                                   uint16_t player2_mask);
int jungle_core_get_frame(const JungleStaticCore *core, JungleCoreFrame *out_frame);
int jungle_core_take_audio(JungleStaticCore *core, JungleCoreAudio *out_audio);
int jungle_core_status(const JungleStaticCore *core, JungleCoreStatus *out_status);
int jungle_core_failure(const JungleStaticCore *core, JungleCoreFailure *out_failure);

/* Complete, restorable same-build snapshots.  The payload includes S-CPU,
   scheduler, DMA, PPU, input, S-SMP, S-DSP, ARAM and rendered-frame state.
   Host pointers and queued frontend PCM are excluded and rebound on load. */
size_t jungle_core_snapshot_size(const JungleStaticCore *core);
int jungle_core_save_snapshot(const JungleStaticCore *core,
                              void *dst, size_t dst_size);
int jungle_core_load_snapshot(JungleStaticCore *core,
                              const void *src, size_t src_size);

/* Diagnostic snapshots are deterministic JSON diagnostics, not restorable save states. */
size_t jungle_core_diagnostic_snapshot_size(const JungleStaticCore *core);
int jungle_core_save_diagnostic_snapshot(const JungleStaticCore *core, void *dst, size_t dst_size);

#ifdef __cplusplus
}
#endif
#endif
