#ifndef JUNGLE_DSP_V10_33_H
#define JUNGLE_DSP_V10_33_H
#include <stddef.h>
#include <stdint.h>
#include "jungle/status_v10_33.h"
#ifdef __cplusplus
extern "C" {
#endif
#define JS_V10_33_DSP_VOICES 8u
#define JS_V10_33_DSP_REG_COUNT 128u
#define JS_V10_33_DSP_PHASES 32u
#define JS_V10_33_PCM_FIFO_FRAMES 8192u

typedef enum js_dsp_envelope_mode_v10_33 {
    JS_DSP_ENV_V10_33_RELEASE = 0,
    JS_DSP_ENV_V10_33_ATTACK = 1,
    JS_DSP_ENV_V10_33_DECAY = 2,
    JS_DSP_ENV_V10_33_SUSTAIN = 3
} js_dsp_envelope_mode_v10_33;

typedef struct js_dsp_voice_v10_33 {
    int32_t envelope;
    int32_t previous_calculated_envelope;
    uint32_t interpolation_position;
    uint16_t brr_address;
    uint16_t brr_offset;
    uint8_t envelope_mode;
    uint8_t key_on_delay;
    uint8_t env_out;
    uint8_t buffer_pos;
    int16_t sample_buffer[12];
    int16_t output;
    uint8_t active;
    uint64_t brr_groups_decoded;
} js_dsp_voice_v10_33;

typedef struct js_dsp_v10_33 {
    uint8_t *aram;
    uint8_t *aram_known;
    uint8_t regs[JS_V10_33_DSP_REG_COUNT];
    uint8_t reg_known[JS_V10_33_DSP_REG_COUNT / 8u];
    js_dsp_voice_v10_33 voices[JS_V10_33_DSP_VOICES];

    uint8_t phase;
    uint16_t counter;
    uint16_t noise_lfsr;
    uint8_t out_reg_buffer;
    uint8_t env_reg_buffer;
    uint8_t voice_end_buffer;
    int32_t voice_output;
    int32_t out_samples[2];
    uint8_t out_samples_known[2];
    uint16_t pitch;
    uint16_t sample_address;
    uint16_t brr_next_address;
    uint8_t brr_next_known;
    uint8_t dir_latch;
    uint8_t noise_on_latch;
    uint8_t pmon_latch;
    uint8_t key_on;
    uint8_t new_key_on;
    uint8_t key_off;
    uint8_t every_other_sample;
    uint8_t source_number;
    uint8_t brr_header;
    uint8_t brr_header_known;
    uint8_t brr_data;
    uint8_t brr_data_known;
    uint8_t looped;
    uint8_t adsr1;

    int32_t echo_in[2];
    int32_t echo_out[2];
    uint8_t echo_out_known[2];
    int16_t echo_history[8][2];
    uint8_t echo_history_known[8][2];
    uint16_t echo_pointer;
    uint16_t echo_length;
    uint16_t echo_offset;
    uint8_t echo_history_pos;
    uint8_t esa_latch;
    uint8_t echo_on_latch;
    uint8_t echo_enabled_latch;

    int16_t pcm_fifo[JS_V10_33_PCM_FIFO_FRAMES * 2u];
    uint8_t pcm_known_fifo[JS_V10_33_PCM_FIFO_FRAMES];
    size_t pcm_read_index;
    size_t pcm_write_index;
    size_t pcm_count;
    uint64_t pcm_frames_produced;
    uint64_t pcm_known_frames_produced;
    uint64_t pcm_unknown_frames_produced;
    uint64_t pcm_fnv1a64;

    uint64_t phase_steps;
    uint64_t sample_steps;
    uint64_t register_writes;
    uint64_t register_reads;
    uint64_t aram_reads;
    uint64_t aram_known_reads;
    uint64_t aram_unknown_reads;
    uint64_t aram_writes;
    uint64_t key_on_events;
    uint64_t key_off_events;
    uint8_t last_aram_phase;
    uint16_t last_aram_address;
    uint8_t last_aram_known;
    uint8_t last_latched_reg;
    uint8_t last_latch_phase;
    js_stop_reason last_stop;
} js_dsp_v10_33;

void js_dsp_v10_33_power_on(js_dsp_v10_33 *dsp, uint8_t *aram, uint8_t *aram_known);
js_stop_reason js_dsp_v10_33_write_register(js_dsp_v10_33 *dsp, uint8_t reg, uint8_t value);
js_stop_reason js_dsp_v10_33_read_register(js_dsp_v10_33 *dsp, uint8_t reg, uint8_t *value);
js_stop_reason js_dsp_v10_33_step_phase(js_dsp_v10_33 *dsp);
js_stop_reason js_dsp_v10_33_step_smp_cycles(js_dsp_v10_33 *dsp, uint32_t cycles);
js_stop_reason js_dsp_v10_33_step_sample(js_dsp_v10_33 *dsp);
int js_dsp_v10_33_register_known(const js_dsp_v10_33 *dsp, uint8_t reg);
size_t js_dsp_v10_33_pcm_available(const js_dsp_v10_33 *dsp);
size_t js_dsp_v10_33_pcm_read(js_dsp_v10_33 *dsp, int16_t *stereo_frames, size_t capacity_frames);
size_t js_dsp_v10_33_pcm_read_with_knownness(js_dsp_v10_33 *dsp, int16_t *stereo_frames, uint8_t *frame_known, size_t capacity_frames);
uint64_t js_dsp_v10_33_pcm_hash(const js_dsp_v10_33 *dsp);
uint8_t js_dsp_v10_33_phase(const js_dsp_v10_33 *dsp);
#ifdef __cplusplus
}
#endif
#endif
