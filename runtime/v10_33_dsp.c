#include <limits.h>
#include <string.h>
#include "jungle/dsp_v10_33.h"
#include "gaussian_table_v10_32.inc"

static int mask_get(const uint8_t *mask, uint16_t a) {
    return mask && ((mask[a >> 3u] & (uint8_t)(1u << (a & 7u))) != 0u);
}
static void mask_set(uint8_t *mask, uint16_t a) {
    if (mask) mask[a >> 3u] |= (uint8_t)(1u << (a & 7u));
}
static void mask_clear(uint8_t *mask, uint16_t a) {
    if (mask) mask[a >> 3u] &= (uint8_t)~(uint8_t)(1u << (a & 7u));
}
static void reg_mark(js_dsp_v10_33 *d, uint8_t r) {
    d->reg_known[r >> 3u] |= (uint8_t)(1u << (r & 7u));
}
int js_dsp_v10_33_register_known(const js_dsp_v10_33 *d, uint8_t r) {
    r &= 0x7fu;
    return d && ((d->reg_known[r >> 3u] & (uint8_t)(1u << (r & 7u))) != 0u);
}
static int16_t clamp16(int32_t x) {
    if (x > INT16_MAX) return INT16_MAX;
    if (x < INT16_MIN) return INT16_MIN;
    return (int16_t)x;
}
static int16_t even16(int32_t x) { return (int16_t)(clamp16(x) & (int16_t)~1); }
static uint8_t reg_read(js_dsp_v10_33 *d, uint8_t r) {
    d->last_latched_reg = (uint8_t)(r & 0x7fu);
    d->last_latch_phase = d->phase;
    return d->regs[r & 0x7fu];
}
static void reg_internal_write(js_dsp_v10_33 *d, uint8_t r, uint8_t v) {
    r &= 0x7fu;
    d->regs[r] = v;
    reg_mark(d, r);
}
static uint8_t aram_read_optional(js_dsp_v10_33 *d, uint16_t a, uint8_t *known) {
    d->aram_reads++;
    d->last_aram_phase = d->phase;
    d->last_aram_address = a;
    if (d->aram && d->aram_known && mask_get(d->aram_known, a)) {
        d->aram_known_reads++;
        d->last_aram_known = 1u;
        if (known) *known = 1u;
        return d->aram[a];
    }
    d->aram_unknown_reads++;
    d->last_aram_known = 0u;
    if (known) *known = 0u;
    return 0u;
}
static js_stop_reason require_known(js_dsp_v10_33 *d, uint8_t known) {
    if (known) return JS_STOP_NONE;
    d->last_stop = JS_STOP_V10_33_DSP_ARAM_REQUIRED_UNKNOWN;
    return d->last_stop;
}
static void aram_write_value(js_dsp_v10_33 *d, uint16_t a, uint8_t v, uint8_t known) {
    if (d->aram) d->aram[a] = v;
    if (d->aram_known) {
        if (known) mask_set(d->aram_known, a);
        else mask_clear(d->aram_known, a);
    }
    d->aram_writes++;
    d->last_aram_phase = d->phase;
    d->last_aram_address = a;
    d->last_aram_known = known ? 1u : 0u;
}

static int check_counter(const js_dsp_v10_33 *d, unsigned rate) {
    static const uint16_t periods[32] = {
        UINT16_MAX,2048u,1536u,1280u,1024u,768u,640u,512u,384u,320u,256u,192u,
        160u,128u,96u,80u,64u,48u,40u,32u,24u,20u,16u,12u,10u,8u,6u,5u,4u,3u,2u,1u
    };
    static const uint16_t offsets[32] = {
        1u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,
        0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,536u,0u,1040u,0u,0u
    };
    return (uint16_t)(d->counter + offsets[rate & 31u]) % periods[rate & 31u] == 0u;
}
static void update_counter(js_dsp_v10_33 *d) { d->counter = d->counter ? (uint16_t)(d->counter - 1u) : 0x77ffu; }

static int16_t gaussian4(const int16_t *buf, uint8_t pos, uint32_t interp) {
    uint8_t off = (uint8_t)((interp >> 4u) & 0xffu);
    unsigned s0 = (unsigned)((pos + (interp >> 12u)) % 12u);
    unsigned s1 = (s0 + 1u) % 12u;
    unsigned s2 = (s0 + 2u) % 12u;
    unsigned s3 = (s0 + 3u) % 12u;
    int32_t out = ((int32_t)js_v10_32_gaussian_table[255u - off] * buf[s0]) >> 11;
    out += ((int32_t)js_v10_32_gaussian_table[511u - off] * buf[s1]) >> 11;
    out += ((int32_t)js_v10_32_gaussian_table[256u + off] * buf[s2]) >> 11;
    out = (int16_t)out;
    out += ((int32_t)js_v10_32_gaussian_table[off] * buf[s3]) >> 11;
    return even16(out);
}

static js_stop_reason decode_brr_group(js_dsp_v10_33 *d, js_dsp_voice_v10_33 *v) {
    uint8_t next_known = 0u;
    uint8_t next;
    int16_t n[4];
    int32_t prev1, prev2;
    unsigned i;
    unsigned shift, filter;
    if (!d->brr_header_known || !d->brr_data_known) return require_known(d, 0u);
    next = aram_read_optional(d, (uint16_t)(v->brr_address + v->brr_offset + 1u), &next_known);
    if (!next_known) return require_known(d, 0u);
    n[0] = (int16_t)((int16_t)((uint16_t)(d->brr_data & 0xf0u) << 8u) >> 12u);
    n[1] = (int16_t)((int16_t)((uint16_t)(d->brr_data & 0x0fu) << 12u) >> 12u);
    n[2] = (int16_t)((int16_t)((uint16_t)(next & 0xf0u) << 8u) >> 12u);
    n[3] = (int16_t)((int16_t)((uint16_t)(next & 0x0fu) << 12u) >> 12u);
    shift = d->brr_header >> 4u;
    filter = d->brr_header & 0x0cu;
    prev1 = v->sample_buffer[v->buffer_pos ? (unsigned)v->buffer_pos - 1u : 11u] >> 1;
    prev2 = v->sample_buffer[v->buffer_pos > 1u ? (unsigned)v->buffer_pos - 2u : 10u] >> 1;
    for (i = 0u; i < 4u; ++i) {
        int32_t s = ((int32_t)n[i] << shift) >> 1;
        if (shift >= 13u) s = s < 0 ? -0x800 : 0;
        switch (filter) {
            case 0x00u: break;
            case 0x04u: s += prev1 + ((-prev1) >> 4); break;
            case 0x08u: s += (prev1 << 1) + ((-((prev1 << 1) + prev1)) >> 5) - prev2 + (prev2 >> 4); break;
            default: s += (prev1 << 1) + ((-(prev1 + (prev1 << 2) + (prev1 << 3))) >> 6) - prev2 + (((prev2 << 1) + prev2) >> 4); break;
        }
        v->sample_buffer[(unsigned)v->buffer_pos + i] = (int16_t)(clamp16(s) * 2);
        prev2 = prev1;
        prev1 = v->sample_buffer[(unsigned)v->buffer_pos + i] >> 1;
    }
    v->buffer_pos = v->buffer_pos <= 4u ? (uint8_t)(v->buffer_pos + 4u) : 0u;
    v->brr_groups_decoded++;
    return JS_STOP_NONE;
}

static void process_envelope(js_dsp_v10_33 *d, js_dsp_voice_v10_33 *v, unsigned index) {
    uint8_t base = (uint8_t)(index << 4u);
    int32_t env = v->envelope;
    if (v->envelope_mode == JS_DSP_ENV_V10_33_RELEASE) {
        env -= 8;
        v->envelope = env < 0 ? 0 : env;
        return;
    }
    {
        unsigned rate = 0u;
        uint8_t sustain;
        if (d->adsr1 & 0x80u) {
            uint8_t adsr2 = reg_read(d, (uint8_t)(base + 6u));
            sustain = adsr2;
            if (v->envelope_mode == JS_DSP_ENV_V10_33_ATTACK) {
                if ((d->adsr1 & 0x0fu) == 0x0fu) { rate = 31u; env += 1024; }
                else { rate = ((unsigned)(d->adsr1 & 0x0fu) << 1u) | 1u; env += 32; }
            } else if (v->envelope_mode == JS_DSP_ENV_V10_33_DECAY) {
                env -= ((env - 1) >> 8) + 1;
                rate = ((unsigned)(d->adsr1 >> 3u) & 0x0eu) | 0x10u;
            } else {
                env -= ((env - 1) >> 8) + 1;
                rate = adsr2 & 0x1fu;
            }
        } else {
            uint8_t gain = reg_read(d, (uint8_t)(base + 7u));
            sustain = gain;
            if (gain & 0x80u) {
                rate = gain & 0x1fu;
                switch (gain & 0x60u) {
                    case 0x00u: env -= 32; break;
                    case 0x20u: env -= ((env - 1) >> 8) + 1; break;
                    case 0x40u: env += 32; break;
                    default: env += ((uint16_t)v->previous_calculated_envelope < 0x600u) ? 32 : 8; break;
                }
            } else {
                env = (uint16_t)gain << 4u;
                rate = 31u;
            }
        }
        if (v->envelope_mode == JS_DSP_ENV_V10_33_DECAY && (env >> 8) == (sustain >> 5u)) v->envelope_mode = JS_DSP_ENV_V10_33_SUSTAIN;
        v->previous_calculated_envelope = env;
        if (env < 0 || env > 0x7ff) {
            env = env < 0 ? 0 : 0x7ff;
            if (v->envelope_mode == JS_DSP_ENV_V10_33_ATTACK) v->envelope_mode = JS_DSP_ENV_V10_33_DECAY;
        }
        if (check_counter(d, rate)) v->envelope = env;
    }
}

static void voice_update_output(js_dsp_v10_33 *d, unsigned index, int right) {
    uint8_t base = (uint8_t)(index << 4u);
    int32_t x = (d->voice_output * (int8_t)reg_read(d, (uint8_t)(base + (right ? 1u : 0u)))) >> 7;
    d->out_samples[right] = clamp16(d->out_samples[right] + x);
    if (d->echo_on_latch & (uint8_t)(1u << index)) d->echo_out[right] = clamp16(d->echo_out[right] + x);
}

static void voice_step1(js_dsp_v10_33 *d, unsigned index) {
    uint8_t base = (uint8_t)(index << 4u);
    d->sample_address = (uint16_t)(((uint16_t)d->dir_latch << 8u) + (uint16_t)d->source_number * 4u);
    d->source_number = reg_read(d, (uint8_t)(base + 4u));
}
static void voice_step2(js_dsp_v10_33 *d, unsigned index) {
    js_dsp_voice_v10_33 *v = &d->voices[index];
    uint8_t base = (uint8_t)(index << 4u), k0 = 0u, k1 = 0u;
    uint16_t a = d->sample_address;
    uint8_t lo, hi;
    if (v->key_on_delay == 0u) a = (uint16_t)(a + 2u);
    lo = aram_read_optional(d, a, &k0);
    hi = aram_read_optional(d, (uint16_t)(a + 1u), &k1);
    d->brr_next_address = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8u));
    d->brr_next_known = (uint8_t)(k0 && k1);
    d->adsr1 = reg_read(d, (uint8_t)(base + 5u));
    d->pitch = reg_read(d, (uint8_t)(base + 2u));
}
static void voice_step3a(js_dsp_v10_33 *d, unsigned index) {
    d->pitch |= (uint16_t)((reg_read(d, (uint8_t)((index << 4u) + 3u)) & 0x3fu) << 8u);
}
static void voice_step3b(js_dsp_v10_33 *d, unsigned index) {
    js_dsp_voice_v10_33 *v = &d->voices[index];
    d->brr_header = aram_read_optional(d, v->brr_address, &d->brr_header_known);
    d->brr_data = aram_read_optional(d, (uint16_t)(v->brr_address + v->brr_offset), &d->brr_data_known);
}
static js_stop_reason voice_step3c(js_dsp_v10_33 *d, unsigned index) {
    js_dsp_voice_v10_33 *v = &d->voices[index];
    uint8_t bit = (uint8_t)(1u << index);
    int32_t out;
    if ((d->pmon_latch & bit) && index != 0u)
        d->pitch = (uint16_t)((d->pitch + ((((d->voice_output >> 5) * (int32_t)d->pitch) >> 10))) & 0x7fffu);
    if (v->key_on_delay) {
        if (v->key_on_delay == 5u) {
            if (!d->brr_next_known) return require_known(d, 0u);
            v->brr_address = d->brr_next_address;
            v->brr_offset = 1u;
            v->buffer_pos = 0u;
            d->brr_header = 0u;
            d->brr_header_known = 1u;
            v->active = 1u;
        }
        v->envelope = 0;
        v->previous_calculated_envelope = 0;
        v->key_on_delay--;
        v->interpolation_position = (v->key_on_delay & 3u) ? 0x4000u : 0u;
        d->pitch = 0u;
    }
    out = gaussian4(v->sample_buffer, v->buffer_pos, v->interpolation_position);
    if (d->noise_on_latch & bit) out = (int16_t)(d->noise_lfsr * 2u);
    d->voice_output = (out * v->envelope) >> 11;
    d->voice_output &= ~1;
    v->output = (int16_t)d->voice_output;
    v->env_out = (uint8_t)(v->envelope >> 4u);
    if (v->active && !d->brr_header_known) return require_known(d, 0u);
    if ((reg_read(d, 0x6cu) & 0x80u) || (d->brr_header & 3u) == 1u) {
        v->envelope_mode = JS_DSP_ENV_V10_33_RELEASE;
        v->envelope = 0;
    }
    if (d->every_other_sample) {
        if (d->key_off & bit) { v->envelope_mode = JS_DSP_ENV_V10_33_RELEASE; d->key_off_events++; }
        if (d->key_on & bit) { v->key_on_delay = 5u; v->envelope_mode = JS_DSP_ENV_V10_33_ATTACK; d->key_on_events++; }
    }
    if (!v->key_on_delay) process_envelope(d, v, index);
    return JS_STOP_NONE;
}
static js_stop_reason voice_step3(js_dsp_v10_33 *d, unsigned index) {
    js_stop_reason s;
    voice_step3a(d,index);
    voice_step3b(d,index);
    s=voice_step3c(d,index);
    return s;
}
static js_stop_reason voice_step4(js_dsp_v10_33 *d, unsigned index) {
    js_dsp_voice_v10_33 *v = &d->voices[index];
    d->looped = 0u;
    if (v->interpolation_position >= 0x4000u && v->active) {
        js_stop_reason s = decode_brr_group(d, v);
        if (s != JS_STOP_NONE) return s;
        if (v->brr_offset >= 7u) {
            if (d->brr_header & 1u) {
                if (!d->brr_next_known) return require_known(d, 0u);
                v->brr_address = d->brr_next_address;
                d->looped = (uint8_t)(1u << index);
            } else v->brr_address = (uint16_t)(v->brr_address + 9u);
            v->brr_offset = 1u;
        } else v->brr_offset = (uint16_t)(v->brr_offset + 2u);
    }
    v->interpolation_position = (v->interpolation_position & 0x3fffu) + d->pitch;
    if (v->interpolation_position > 0x7fffu) v->interpolation_position = 0x7fffu;
    voice_update_output(d, index, 0);
    return JS_STOP_NONE;
}
static void voice_step5(js_dsp_v10_33 *d, unsigned index) {
    js_dsp_voice_v10_33 *v = &d->voices[index];
    uint8_t bit = (uint8_t)(1u << index);
    uint8_t x;
    voice_update_output(d, index, 1);
    x = (uint8_t)(reg_read(d, 0x7cu) | d->looped);
    if (v->key_on_delay == 5u) x &= (uint8_t)~bit;
    d->voice_end_buffer = x;
}
static void voice_step6(js_dsp_v10_33 *d) { d->out_reg_buffer = (uint8_t)((uint32_t)d->voice_output >> 8u); }
static void voice_step7(js_dsp_v10_33 *d, unsigned index) {
    reg_internal_write(d, 0x7cu, d->voice_end_buffer);
    d->env_reg_buffer = d->voices[index].env_out;
}
static void voice_step8(js_dsp_v10_33 *d, unsigned index) { reg_internal_write(d, (uint8_t)((index << 4u) + 9u), d->out_reg_buffer); }
static void voice_step9(js_dsp_v10_33 *d, unsigned index) { reg_internal_write(d, (uint8_t)((index << 4u) + 8u), d->env_reg_buffer); }

static int32_t fir_term(js_dsp_v10_33 *d, unsigned tap, int ch, uint8_t *known) {
    unsigned p = (unsigned)((d->echo_history_pos + tap + 1u) & 7u);
    int8_t c = (int8_t)reg_read(d, (uint8_t)(0x0fu + tap * 0x10u));
    if (known && c != 0 && !d->echo_history_known[p][ch]) *known = 0u;
    return ((int32_t)d->echo_history[p][ch] * c) >> 6;
}
static void echo_step22(js_dsp_v10_33 *d) {
    uint8_t k0=0u,k1=0u, known_l=1u, known_r=1u;
    uint8_t lo,hi;
    d->echo_history_pos=(uint8_t)((d->echo_history_pos+1u)&7u);
    d->echo_pointer=(uint16_t)(((uint16_t)d->esa_latch<<8u)+d->echo_offset);
    lo=aram_read_optional(d,d->echo_pointer,&k0); hi=aram_read_optional(d,(uint16_t)(d->echo_pointer+1u),&k1);
    d->echo_history[d->echo_history_pos][0]=(int16_t)((int16_t)((uint16_t)lo|((uint16_t)hi<<8u))>>1u);
    d->echo_history_known[d->echo_history_pos][0]=(uint8_t)(k0&&k1);
    d->echo_in[0]=fir_term(d,0u,0,&known_l); d->echo_in[1]=fir_term(d,0u,1,&known_r);
    /* Store FIR-known state in high bits of echo_enabled_latch transiently: bit6=L, bit7=R. */
    d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0x3fu)|(known_l?0x40u:0u)|(known_r?0x80u:0u));
}
static void echo_add_known(js_dsp_v10_33 *d, unsigned tap, uint8_t *known_l, uint8_t *known_r) {
    d->echo_in[0]+=fir_term(d,tap,0,known_l); d->echo_in[1]+=fir_term(d,tap,1,known_r);
}
static void echo_step23(js_dsp_v10_33 *d) {
    uint8_t k0=0u,k1=0u, kl=(uint8_t)((d->echo_enabled_latch&0x40u)!=0u), kr=(uint8_t)((d->echo_enabled_latch&0x80u)!=0u);
    uint8_t lo=aram_read_optional(d,(uint16_t)(d->echo_pointer+2u),&k0),hi=aram_read_optional(d,(uint16_t)(d->echo_pointer+3u),&k1);
    d->echo_history[d->echo_history_pos][1]=(int16_t)((int16_t)((uint16_t)lo|((uint16_t)hi<<8u))>>1u);
    d->echo_history_known[d->echo_history_pos][1]=(uint8_t)(k0&&k1);
    echo_add_known(d,1u,&kl,&kr); echo_add_known(d,2u,&kl,&kr);
    d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0x3fu)|(kl?0x40u:0u)|(kr?0x80u:0u));
}
static void echo_step24(js_dsp_v10_33 *d) {
    uint8_t kl=(uint8_t)((d->echo_enabled_latch&0x40u)!=0u),kr=(uint8_t)((d->echo_enabled_latch&0x80u)!=0u);
    echo_add_known(d,3u,&kl,&kr);echo_add_known(d,4u,&kl,&kr);echo_add_known(d,5u,&kl,&kr);
    d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0x3fu)|(kl?0x40u:0u)|(kr?0x80u:0u));
}
static void echo_step25(js_dsp_v10_33 *d) {
    uint8_t kl=(uint8_t)((d->echo_enabled_latch&0x40u)!=0u),kr=(uint8_t)((d->echo_enabled_latch&0x80u)!=0u);
    int32_t l=(int16_t)(d->echo_in[0]+fir_term(d,6u,0,&kl));
    int32_t r=(int16_t)(d->echo_in[1]+fir_term(d,6u,1,&kr));
    d->echo_in[0]=even16(l+(int16_t)fir_term(d,7u,0,&kl));
    d->echo_in[1]=even16(r+(int16_t)fir_term(d,7u,1,&kr));
    d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0x3fu)|(kl?0x40u:0u)|(kr?0x80u:0u));
}
static js_stop_reason push_pcm(js_dsp_v10_33 *d,int16_t l,int16_t r,uint8_t known) {
    uint16_t w[2]; unsigned i,b;
    if(d->pcm_count>=JS_V10_33_PCM_FIFO_FRAMES){d->last_stop=JS_STOP_V10_33_DSP_PCM_FIFO_OVERFLOW;return d->last_stop;}
    d->pcm_fifo[d->pcm_write_index*2u]=l;d->pcm_fifo[d->pcm_write_index*2u+1u]=r;
    d->pcm_known_fifo[d->pcm_write_index]=known?1u:0u;
    d->pcm_write_index=(d->pcm_write_index+1u)%JS_V10_33_PCM_FIFO_FRAMES;d->pcm_count++;d->pcm_frames_produced++;
    if(known)d->pcm_known_frames_produced++;else d->pcm_unknown_frames_produced++;
    /* The representative PCM hash remains deterministic, but it is authoritative only while
       pcm_unknown_frames_produced==0.  Unknown frames carry an explicit knownness bit. */
    w[0]=(uint16_t)l;w[1]=(uint16_t)r;for(i=0;i<2u;i++)for(b=0;b<2u;b++){uint8_t x=(uint8_t)(w[i]>>(b*8u));d->pcm_fnv1a64^=x;d->pcm_fnv1a64*=UINT64_C(1099511628211);}return JS_STOP_NONE;
}
static js_stop_reason echo_step26(js_dsp_v10_33 *d) {
    uint8_t kl=(uint8_t)((d->echo_enabled_latch&0x40u)!=0u),kr=(uint8_t)((d->echo_enabled_latch&0x80u)!=0u);
    int8_t mv=(int8_t)reg_read(d,0x0cu),ev=(int8_t)reg_read(d,0x2cu),efb=(int8_t)reg_read(d,0x0du);
    uint8_t dry_known=(uint8_t)(mv==0 || d->out_samples_known[0]);
    uint8_t echo_known=(uint8_t)(ev==0 || kl);
    d->out_samples[0]=clamp16(((d->out_samples[0]*mv)>>7)+((d->echo_in[0]*ev)>>7));
    d->out_samples_known[0]=(uint8_t)(dry_known&&echo_known);
    d->echo_out[0]=even16(d->echo_out[0]+((d->echo_in[0]*efb)>>7));
    d->echo_out[1]=even16(d->echo_out[1]+((d->echo_in[1]*efb)>>7));
    d->echo_out_known[0]=(uint8_t)(d->echo_out_known[0]&&(efb==0||kl));
    d->echo_out_known[1]=(uint8_t)(d->echo_out_known[1]&&(efb==0||kr));
    if(efb!=0){if(!d->echo_out_known[0])d->echo_enabled_latch&=(uint8_t)~0x10u;else d->echo_enabled_latch|=0x10u;if(!d->echo_out_known[1])d->echo_enabled_latch&=(uint8_t)~0x20u;else d->echo_enabled_latch|=0x20u;}else d->echo_enabled_latch|=0x30u;
    return JS_STOP_NONE;
}
static js_stop_reason echo_step27(js_dsp_v10_33 *d) {
    uint8_t kr=(uint8_t)((d->echo_enabled_latch&0x80u)!=0u); int16_t l,r; uint8_t pcm_known;
    int8_t mv=(int8_t)reg_read(d,0x1cu),ev=(int8_t)reg_read(d,0x3cu);
    uint8_t dry_known=(uint8_t)(mv==0 || d->out_samples_known[1]);
    uint8_t echo_known=(uint8_t)(ev==0 || kr);
    d->out_samples[1]=clamp16(((d->out_samples[1]*mv)>>7)+((d->echo_in[1]*ev)>>7));
    d->out_samples_known[1]=(uint8_t)(dry_known&&echo_known);
    if(reg_read(d,0x6cu)&0x40u){l=r=0;pcm_known=1u;}else{l=clamp16(d->out_samples[0]);r=clamp16(d->out_samples[1]);pcm_known=(uint8_t)(d->out_samples_known[0]&&d->out_samples_known[1]);}
    d->out_samples[0]=0;d->out_samples[1]=0;d->out_samples_known[0]=1u;d->out_samples_known[1]=1u;
    return push_pcm(d,l,r,pcm_known);
}
static void echo_step28(js_dsp_v10_33 *d) { d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0xf0u)|((reg_read(d,0x6cu)&0x20u)?0u:1u)); }
static js_stop_reason echo_write_word(js_dsp_v10_33 *d,uint16_t a,int16_t x,uint8_t known) {
    int16_t e=(int16_t)(x&~1);
    aram_write_value(d,a,(uint8_t)e,known);
    aram_write_value(d,(uint16_t)(a+1u),(uint8_t)((uint16_t)e>>8u),known);
    return JS_STOP_NONE;
}
static js_stop_reason echo_step29(js_dsp_v10_33 *d) {
    js_stop_reason s;
    if(d->echo_offset==0u)d->echo_length=(uint16_t)((reg_read(d,0x7du)&0x0fu)<<11u);
    d->echo_offset=(uint16_t)(d->echo_offset+4u);if(d->echo_offset>=d->echo_length)d->echo_offset=0u;
    if(d->echo_enabled_latch&1u){s=echo_write_word(d,d->echo_pointer,clamp16(d->echo_out[0]),d->echo_out_known[0]);if(s!=JS_STOP_NONE)return s;}
    d->echo_out[0]=0;d->echo_out_known[0]=1u;
    d->esa_latch=reg_read(d,0x6du);
    d->echo_enabled_latch=(uint8_t)((d->echo_enabled_latch&0xf0u)|((reg_read(d,0x6cu)&0x20u)?0u:1u));
    return JS_STOP_NONE;
}
static js_stop_reason echo_step30(js_dsp_v10_33 *d) {
    js_stop_reason s;if(d->echo_enabled_latch&1u){s=echo_write_word(d,(uint16_t)(d->echo_pointer+2u),clamp16(d->echo_out[1]),d->echo_out_known[1]);if(s!=JS_STOP_NONE)return s;}d->echo_out[1]=0;d->echo_out_known[1]=1u;return JS_STOP_NONE;
}

void js_dsp_v10_33_power_on(js_dsp_v10_33 *d,uint8_t *aram,uint8_t *known) {
    unsigned i;if(!d)return;memset(d,0,sizeof(*d));d->aram=aram;d->aram_known=known;d->noise_lfsr=0x4000u;d->every_other_sample=1u;d->pcm_fnv1a64=UINT64_C(14695981039346656037);d->out_samples_known[0]=d->out_samples_known[1]=1u;d->echo_out_known[0]=d->echo_out_known[1]=1u;for(i=0;i<128u;i++)reg_mark(d,(uint8_t)i);d->regs[0x6c]=0xe0u;d->new_key_on=d->regs[0x4c];d->dir_latch=d->regs[0x5d];d->esa_latch=d->regs[0x6d];
}

js_stop_reason js_dsp_v10_33_write_register(js_dsp_v10_33 *d,uint8_t r,uint8_t v) {
    if(!d) return JS_STOP_V10_33_DSP_INVALID_ARGUMENT;
    r&=0x7fu;d->regs[r]=v;reg_mark(d,r);d->register_writes++;
    if((r&0x0fu)==8u)d->env_reg_buffer=v;else if((r&0x0fu)==9u)d->out_reg_buffer=v;
    if(r==0x4cu)d->new_key_on=v;else if(r==0x7cu){d->voice_end_buffer=0u;d->regs[0x7c]=0u;}
    return d->last_stop;
}
js_stop_reason js_dsp_v10_33_read_register(js_dsp_v10_33 *d,uint8_t r,uint8_t *v) {
    if(!d||!v) return JS_STOP_V10_33_DSP_INVALID_ARGUMENT;
    r&=0x7fu;if(!js_dsp_v10_33_register_known(d,r)){d->last_stop=JS_STOP_V10_33_DSP_REGISTER_UNKNOWN;return d->last_stop;}*v=d->regs[r];d->register_reads++;return JS_STOP_NONE;
}

js_stop_reason js_dsp_v10_33_step_phase(js_dsp_v10_33 *d) {
    js_stop_reason s=JS_STOP_NONE;uint8_t p;
    if(!d) return JS_STOP_V10_33_DSP_INVALID_ARGUMENT;
    if(d->last_stop!=JS_STOP_NONE) return d->last_stop;
    p=d->phase;
    switch(p){
        case 0: voice_step5(d,0);voice_step2(d,1);break;
        case 1: voice_step6(d);s=voice_step3(d,1);break;
        case 2: voice_step7(d,0);if((s=voice_step4(d,1))==JS_STOP_NONE)voice_step1(d,3);break;
        case 3: voice_step8(d,0);voice_step5(d,1);voice_step2(d,2);break;
        case 4: voice_step9(d,0);voice_step6(d);s=voice_step3(d,2);break;
        case 5: voice_step7(d,1);if((s=voice_step4(d,2))==JS_STOP_NONE)voice_step1(d,4);break;
        case 6: voice_step8(d,1);voice_step5(d,2);voice_step2(d,3);break;
        case 7: voice_step9(d,1);voice_step6(d);s=voice_step3(d,3);break;
        case 8: voice_step7(d,2);if((s=voice_step4(d,3))==JS_STOP_NONE)voice_step1(d,5);break;
        case 9: voice_step8(d,2);voice_step5(d,3);voice_step2(d,4);break;
        case 10: voice_step9(d,2);voice_step6(d);s=voice_step3(d,4);break;
        case 11: voice_step7(d,3);if((s=voice_step4(d,4))==JS_STOP_NONE)voice_step1(d,6);break;
        case 12: voice_step8(d,3);voice_step5(d,4);voice_step2(d,5);break;
        case 13: voice_step9(d,3);voice_step6(d);s=voice_step3(d,5);break;
        case 14: voice_step7(d,4);if((s=voice_step4(d,5))==JS_STOP_NONE)voice_step1(d,7);break;
        case 15: voice_step8(d,4);voice_step5(d,5);voice_step2(d,6);break;
        case 16: voice_step9(d,4);voice_step6(d);s=voice_step3(d,6);break;
        case 17: voice_step1(d,0);voice_step7(d,5);s=voice_step4(d,6);break;
        case 18: voice_step8(d,5);voice_step5(d,6);voice_step2(d,7);break;
        case 19: voice_step9(d,5);voice_step6(d);s=voice_step3(d,7);break;
        case 20: voice_step1(d,1);voice_step7(d,6);s=voice_step4(d,7);break;
        case 21: voice_step8(d,6);voice_step5(d,7);voice_step2(d,0);break;
        case 22: voice_step3a(d,0);voice_step9(d,6);voice_step6(d);echo_step22(d);break;
        case 23: voice_step7(d,7);echo_step23(d);break;
        case 24: voice_step8(d,7);echo_step24(d);break;
        case 25: voice_step3b(d,0);voice_step9(d,7);echo_step25(d);break;
        case 26: s=echo_step26(d);break;
        case 27: d->pmon_latch=(uint8_t)(reg_read(d,0x2du)&0xfeu);s=echo_step27(d);break;
        case 28: d->dir_latch=reg_read(d,0x5du);d->noise_on_latch=reg_read(d,0x3du);d->echo_on_latch=reg_read(d,0x4du);echo_step28(d);break;
        case 29: d->every_other_sample^=1u;if(d->every_other_sample)d->new_key_on&=(uint8_t)~d->key_on;s=echo_step29(d);break;
        case 30:
            if(d->every_other_sample){d->key_on=d->new_key_on;d->key_off=reg_read(d,0x5cu);}update_counter(d);if(check_counter(d,reg_read(d,0x6cu)&0x1fu)){uint16_t n=(uint16_t)(((d->noise_lfsr<<14u)^(d->noise_lfsr<<13u))&0x4000u);d->noise_lfsr=(uint16_t)(n^(d->noise_lfsr>>1u));}s=voice_step3c(d,0);if(s==JS_STOP_NONE)s=echo_step30(d);break;
        case 31: s=voice_step4(d,0);if(s==JS_STOP_NONE)voice_step1(d,2);break;
        default: d->last_stop=JS_STOP_V10_33_DSP_PHASE_INVARIANT;return d->last_stop;
    }
    if(s!=JS_STOP_NONE){d->last_stop=s;return s;}
    d->phase=(uint8_t)((p+1u)&31u);d->phase_steps++;if(d->phase==0u)d->sample_steps++;return JS_STOP_NONE;
}
js_stop_reason js_dsp_v10_33_step_smp_cycles(js_dsp_v10_33 *d,uint32_t cycles){uint32_t i;if(!d)return JS_STOP_V10_33_DSP_INVALID_ARGUMENT;for(i=0;i<cycles;i++){js_stop_reason s=js_dsp_v10_33_step_phase(d);if(s!=JS_STOP_NONE)return s;}return JS_STOP_NONE;}
js_stop_reason js_dsp_v10_33_step_sample(js_dsp_v10_33 *d){uint8_t start;uint32_t n=0;if(!d)return JS_STOP_V10_33_DSP_INVALID_ARGUMENT;start=d->phase;do{js_stop_reason s=js_dsp_v10_33_step_phase(d);if(s!=JS_STOP_NONE)return s;n++;}while(d->phase!=start&&n<=32u);return n==32u?JS_STOP_NONE:JS_STOP_V10_33_DSP_PHASE_INVARIANT;}
size_t js_dsp_v10_33_pcm_available(const js_dsp_v10_33 *d){return d?d->pcm_count:0u;}
size_t js_dsp_v10_33_pcm_read_with_knownness(js_dsp_v10_33 *d,int16_t *o,uint8_t *known,size_t cap){size_t n=0;if(!d||!o)return 0u;while(n<cap&&d->pcm_count){o[n*2u]=d->pcm_fifo[d->pcm_read_index*2u];o[n*2u+1u]=d->pcm_fifo[d->pcm_read_index*2u+1u];if(known)known[n]=d->pcm_known_fifo[d->pcm_read_index];d->pcm_read_index=(d->pcm_read_index+1u)%JS_V10_33_PCM_FIFO_FRAMES;d->pcm_count--;n++;}return n;}
size_t js_dsp_v10_33_pcm_read(js_dsp_v10_33 *d,int16_t *o,size_t cap){return js_dsp_v10_33_pcm_read_with_knownness(d,o,NULL,cap);}
uint64_t js_dsp_v10_33_pcm_hash(const js_dsp_v10_33 *d){return d?d->pcm_fnv1a64:0u;}
uint8_t js_dsp_v10_33_phase(const js_dsp_v10_33 *d){return d?d->phase:0xffu;}
