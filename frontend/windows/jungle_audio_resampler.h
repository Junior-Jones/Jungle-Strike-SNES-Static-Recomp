#ifndef JUNGLE_AUDIO_RESAMPLER_H
#define JUNGLE_AUDIO_RESAMPLER_H

#include <stddef.h>
#include <stdint.h>

typedef enum JungleAudioResamplerMode {
    JUNGLE_AUDIO_RESAMPLER_HERMITE = 0,
    JUNGLE_AUDIO_RESAMPLER_LINEAR = 1,
    JUNGLE_AUDIO_RESAMPLER_NEAREST = 2
} JungleAudioResamplerMode;

#define JUNGLE_AUDIO_RESAMPLER_PENDING_FRAMES 16384u

typedef struct JungleAudioHermiteResampler {
    double previous_left[4];
    double previous_right[4];
    double rate_ratio;
    double fraction;
    int16_t last_left;
    int16_t last_right;
    int mode;
    int16_t pending_samples[JUNGLE_AUDIO_RESAMPLER_PENDING_FRAMES * 2u];
    size_t pending_frames;
} JungleAudioHermiteResampler;

void jungle_audio_resampler_reset(JungleAudioHermiteResampler *resampler);
void jungle_audio_resampler_set_rates(JungleAudioHermiteResampler *resampler,
                                      double source_rate,
                                      double destination_rate);
void jungle_audio_resampler_set_mode(JungleAudioHermiteResampler *resampler,
                                     int mode);

/* The caller must supply enough output storage.  For the Jungle Strike
   32,040 Hz to 48,000 Hz path, twice input_frames is always sufficient. */
size_t jungle_audio_resampler_process(JungleAudioHermiteResampler *resampler,
                                      const int16_t *input,
                                      size_t input_frames,
                                      int16_t *output,
                                      size_t output_capacity_frames);

#endif
