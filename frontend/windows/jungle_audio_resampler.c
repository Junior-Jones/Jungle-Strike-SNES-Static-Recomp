#include "jungle_audio_resampler.h"

#include <limits.h>
#include <string.h>

/* Cubic Hermite interpolation described by Paul Bourke:
   https://paulbourke.net/miscellaneous/interpolation/
   This C implementation uses the same four-sample, stateful sequence as
   Mesen's SNES speaker path. */
static int16_t hermite_interpolate(const double values[4], double position) {
    double position2 = position * position;
    double position3 = position2 * position;
    double tangent0 = (values[1] - values[0]) * 0.5 +
                      (values[2] - values[1]) * 0.5;
    double tangent1 = (values[2] - values[1]) * 0.5 +
                      (values[3] - values[2]) * 0.5;
    double coefficient0 = 2.0 * position3 - 3.0 * position2 + 1.0;
    double coefficient1 = position3 - 2.0 * position2 + position;
    double coefficient2 = position3 - position2;
    double coefficient3 = -2.0 * position3 + 3.0 * position2;
    double sample = coefficient0 * values[1] + coefficient1 * tangent0 +
                    coefficient2 * tangent1 + coefficient3 * values[2];
    if (sample < (double)INT16_MIN) sample = (double)INT16_MIN;
    if (sample > (double)INT16_MAX) sample = (double)INT16_MAX;
    return (int16_t)sample;
}

static int16_t linear_interpolate(const double values[4], double position) {
    double sample = values[1] + (values[2] - values[1]) * position;
    if (sample < (double)INT16_MIN) sample = (double)INT16_MIN;
    if (sample > (double)INT16_MAX) sample = (double)INT16_MAX;
    return (int16_t)sample;
}

static int16_t interpolate(const double values[4], double position,
                           int mode) {
    if (mode == JUNGLE_AUDIO_RESAMPLER_NEAREST)
        return (int16_t)(position < 0.5 ? values[1] : values[2]);
    if (mode == JUNGLE_AUDIO_RESAMPLER_LINEAR)
        return linear_interpolate(values, position);
    return hermite_interpolate(values, position);
}

static void push_sample(double values[4], int16_t sample) {
    values[0] = values[1];
    values[1] = values[2];
    values[2] = values[3];
    values[3] = (double)sample;
}

void jungle_audio_resampler_reset(JungleAudioHermiteResampler *resampler) {
    if (!resampler) return;
    memset(resampler->previous_left, 0, sizeof(resampler->previous_left));
    memset(resampler->previous_right, 0, sizeof(resampler->previous_right));
    resampler->fraction = 0.0;
    resampler->last_left = 0;
    resampler->last_right = 0;
    resampler->pending_frames = 0u;
    if (resampler->rate_ratio <= 0.0) resampler->rate_ratio = 1.0;
}

void jungle_audio_resampler_set_rates(JungleAudioHermiteResampler *resampler,
                                      double source_rate,
                                      double destination_rate) {
    if (!resampler || source_rate <= 0.0 || destination_rate <= 0.0) return;
    resampler->rate_ratio = source_rate / destination_rate;
}

void jungle_audio_resampler_set_mode(JungleAudioHermiteResampler *resampler,
                                     int mode) {
    if (!resampler) return;
    if (mode < JUNGLE_AUDIO_RESAMPLER_HERMITE ||
        mode > JUNGLE_AUDIO_RESAMPLER_NEAREST)
        mode = JUNGLE_AUDIO_RESAMPLER_HERMITE;
    resampler->mode = mode;
}

size_t jungle_audio_resampler_process(JungleAudioHermiteResampler *resampler,
                                      const int16_t *input,
                                      size_t input_frames,
                                      int16_t *output,
                                      size_t output_capacity_frames) {
    size_t input_frame;
    size_t output_frames = 0u;
    size_t pending_copy;
    if (!resampler || (!input && input_frames) || !output ||
        resampler->rate_ratio <= 0.0)
        return 0u;
    pending_copy = resampler->pending_frames < output_capacity_frames ?
                   resampler->pending_frames : output_capacity_frames;
    if (pending_copy) {
        memcpy(output, resampler->pending_samples,
               pending_copy * 2u * sizeof(int16_t));
        output_frames = pending_copy;
        resampler->pending_frames -= pending_copy;
        if (resampler->pending_frames)
            memmove(resampler->pending_samples,
                    resampler->pending_samples + pending_copy * 2u,
                    resampler->pending_frames * 2u * sizeof(int16_t));
    }
    if (output_frames == output_capacity_frames) return output_frames;

    /* Mesen bypasses interpolation when the rates are exactly equal.  This
       preserves every native sample bit-for-bit and retains excess output in
       its pending queue instead of dropping it at a caller boundary. */
    if (resampler->rate_ratio == 1.0) {
        size_t direct = input_frames;
        size_t room = output_capacity_frames - output_frames;
        size_t queued;
        if (direct > room) direct = room;
        if (direct) {
            memcpy(output + output_frames * 2u, input,
                   direct * 2u * sizeof(int16_t));
            output_frames += direct;
            resampler->last_left = input[(direct - 1u) * 2u];
            resampler->last_right = input[(direct - 1u) * 2u + 1u];
        }
        queued = input_frames - direct;
        if (queued > JUNGLE_AUDIO_RESAMPLER_PENDING_FRAMES -
                         resampler->pending_frames)
            queued = JUNGLE_AUDIO_RESAMPLER_PENDING_FRAMES -
                     resampler->pending_frames;
        if (queued) {
            memcpy(resampler->pending_samples +
                       resampler->pending_frames * 2u,
                   input + direct * 2u,
                   queued * 2u * sizeof(int16_t));
            resampler->pending_frames += queued;
            resampler->last_left = input[(direct + queued - 1u) * 2u];
            resampler->last_right = input[(direct + queued - 1u) * 2u + 1u];
        }
        return output_frames;
    }
    for (input_frame = 0u; input_frame < input_frames; ++input_frame) {
        while (resampler->fraction <= 1.0) {
            resampler->last_left = interpolate(
                resampler->previous_left, resampler->fraction,
                resampler->mode);
            resampler->last_right = interpolate(
                resampler->previous_right, resampler->fraction,
                resampler->mode);
            if (output_frames < output_capacity_frames) {
                output[output_frames * 2u] = resampler->last_left;
                output[output_frames * 2u + 1u] = resampler->last_right;
                output_frames++;
            } else if (resampler->pending_frames <
                       JUNGLE_AUDIO_RESAMPLER_PENDING_FRAMES) {
                size_t pending = resampler->pending_frames++ * 2u;
                resampler->pending_samples[pending] = resampler->last_left;
                resampler->pending_samples[pending + 1u] =
                    resampler->last_right;
            }
            resampler->fraction += resampler->rate_ratio;
        }
        push_sample(resampler->previous_left, input[input_frame * 2u]);
        push_sample(resampler->previous_right, input[input_frame * 2u + 1u]);
        resampler->fraction -= 1.0;
    }
    return output_frames;
}
