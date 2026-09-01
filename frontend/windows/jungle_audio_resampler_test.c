#include "jungle_audio_resampler.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define INPUT_FRAMES 3204u
#define OUTPUT_CAPACITY 5000u

static void fill_input(int16_t *samples) {
    size_t frame;
    for (frame = 0u; frame < INPUT_FRAMES; ++frame) {
        samples[frame * 2u] = (int16_t)((frame * 97u) % 60001u - 30000);
        samples[frame * 2u + 1u] =
            (int16_t)(30000 - (int32_t)((frame * 193u) % 60001u));
    }
}

int main(void) {
    int16_t input[INPUT_FRAMES * 2u];
    int16_t complete[OUTPUT_CAPACITY * 2u];
    int16_t split[OUTPUT_CAPACITY * 2u];
    JungleAudioHermiteResampler one;
    JungleAudioHermiteResampler two;
    size_t complete_count;
    size_t first_count;
    size_t second_count;
    int16_t exact_input[16];
    int16_t exact_output[16];
    size_t exact_first;
    size_t exact_second;
    size_t exact_index;
    memset(&one, 0, sizeof(one));
    memset(&two, 0, sizeof(two));
    fill_input(input);
    jungle_audio_resampler_set_rates(&one, 32040.0, 48000.0);
    jungle_audio_resampler_set_rates(&two, 32040.0, 48000.0);
    jungle_audio_resampler_reset(&one);
    jungle_audio_resampler_reset(&two);
    complete_count = jungle_audio_resampler_process(
        &one, input, INPUT_FRAMES, complete, OUTPUT_CAPACITY);
    first_count = jungle_audio_resampler_process(
        &two, input, 1703u, split, OUTPUT_CAPACITY);
    second_count = jungle_audio_resampler_process(
        &two, input + 1703u * 2u, INPUT_FRAMES - 1703u,
        split + first_count * 2u, OUTPUT_CAPACITY - first_count);
    if (complete_count < 4799u || complete_count > 4801u) {
        fprintf(stderr, "unexpected output count: %zu\n", complete_count);
        return 1;
    }
    if (complete_count != first_count + second_count ||
        memcmp(complete, split, complete_count * 2u * sizeof(int16_t)) != 0) {
        fputs("resampler state changed at an input batch boundary\n", stderr);
        return 1;
    }
    for (exact_index = 0u; exact_index < 16u; ++exact_index)
        exact_input[exact_index] = (int16_t)(exact_index * 101u - 700u);
    memset(&one, 0, sizeof(one));
    memset(exact_output, 0, sizeof(exact_output));
    jungle_audio_resampler_set_rates(&one, 32040.0, 32040.0);
    jungle_audio_resampler_reset(&one);
    exact_first = jungle_audio_resampler_process(
        &one, exact_input, 8u, exact_output, 3u);
    exact_second = jungle_audio_resampler_process(
        &one, NULL, 0u, exact_output + exact_first * 2u, 5u);
    if (exact_first != 3u || exact_second != 5u ||
        memcmp(exact_input, exact_output, sizeof(exact_input)) != 0) {
        fputs("equal-rate Mesen bypass or pending queue failed\n", stderr);
        return 1;
    }
    printf("Mesen-sequence Hermite resampler passed: %zu frames\n",
           complete_count);
    return 0;
}
