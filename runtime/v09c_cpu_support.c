#include <string.h>
#include "jungle/cpu_v08c_internal.h"
#include "jungle/status_v09c.h"
#include "jungle/machine_v08c.h"
typedef struct js_sha256_ctx { uint32_t h[8]; uint64_t bits; uint8_t buf[64]; size_t used; } js_sha256_ctx;
static uint32_t js_rotr32(uint32_t x,unsigned n){return (x>>n)|(x<<(32u-n));}
static const uint32_t js_sha_k[64]={
0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u};
static void js_sha_block(js_sha256_ctx *c,const uint8_t *p){uint32_t w[64],a,b,d,e,f,g,h,t1,t2,cc; for(unsigned i=0;i<16;i++)w[i]=((uint32_t)p[i*4]<<24)|((uint32_t)p[i*4+1]<<16)|((uint32_t)p[i*4+2]<<8)|p[i*4+3]; for(unsigned i=16;i<64;i++){uint32_t s0=js_rotr32(w[i-15],7)^js_rotr32(w[i-15],18)^(w[i-15]>>3),s1=js_rotr32(w[i-2],17)^js_rotr32(w[i-2],19)^(w[i-2]>>10);w[i]=w[i-16]+s0+w[i-7]+s1;} a=c->h[0];b=c->h[1];cc=c->h[2];d=c->h[3];e=c->h[4];f=c->h[5];g=c->h[6];h=c->h[7]; for(unsigned i=0;i<64;i++){uint32_t s1=js_rotr32(e,6)^js_rotr32(e,11)^js_rotr32(e,25),ch=(e&f)^((~e)&g);t1=h+s1+ch+js_sha_k[i]+w[i];uint32_t s0=js_rotr32(a,2)^js_rotr32(a,13)^js_rotr32(a,22),maj=(a&b)^(a&cc)^(b&cc);t2=s0+maj;h=g;g=f;f=e;e=d+t1;d=cc;cc=b;b=a;a=t1+t2;} c->h[0]+=a;c->h[1]+=b;c->h[2]+=cc;c->h[3]+=d;c->h[4]+=e;c->h[5]+=f;c->h[6]+=g;c->h[7]+=h;}
static void js_sha_init(js_sha256_ctx *c){static const uint32_t iv[8]={0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u};memcpy(c->h,iv,sizeof(iv));c->bits=0;c->used=0;}
static void js_sha_update(js_sha256_ctx *c,const uint8_t *p,size_t n){c->bits+=(uint64_t)n*8u;while(n){size_t take=64u-c->used;if(take>n)take=n;memcpy(c->buf+c->used,p,take);c->used+=take;p+=take;n-=take;if(c->used==64u){js_sha_block(c,c->buf);c->used=0;}}}
static void js_sha_final(js_sha256_ctx *c,uint8_t out[32]){c->buf[c->used++]=0x80u;if(c->used>56u){while(c->used<64u)c->buf[c->used++]=0;js_sha_block(c,c->buf);c->used=0;}while(c->used<56u)c->buf[c->used++]=0;for(int i=7;i>=0;i--)c->buf[c->used++]=(uint8_t)(c->bits>>(i*8));js_sha_block(c,c->buf);for(unsigned i=0;i<8;i++){out[i*4]=(uint8_t)(c->h[i]>>24);out[i*4+1]=(uint8_t)(c->h[i]>>16);out[i*4+2]=(uint8_t)(c->h[i]>>8);out[i*4+3]=(uint8_t)c->h[i];}}
static int js_exact_rom_hash(const uint8_t *rom,size_t n){static const uint8_t want[32]={0x8d,0x81,0x2e,0xa4,0xfa,0x89,0x72,0x74,0x11,0x6f,0x7f,0x43,0xbc,0x68,0x9e,0x11,0x0f,0x1c,0xfb,0xd3,0xf7,0xeb,0x3a,0x17,0x37,0xc2,0xa8,0x5d,0x36,0x36,0x91,0x59};uint8_t got[32];js_sha256_ctx c;if(!rom||n!=2097152u)return 0;js_sha_init(&c);js_sha_update(&c,rom,n);js_sha_final(&c,got);return memcmp(got,want,32)==0;}


static void js_set_flag(js_cpu65816_state *s, uint8_t flag, int on) {
    if (on) s->p |= flag; else s->p &= (uint8_t)~flag;
}

const char *js_stop_reason_name(js_stop_reason reason) {
    /* V09C owns three fail-closed codes outside the frozen predecessor enum.
       Handle them before the enum switch so strict compilers do not diagnose
       out-of-enum case labels. */
    if (reason == JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS) return "JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS";
    if (reason == JS_STOP_PPU_INVALID_REGISTER) return "JS_STOP_PPU_INVALID_REGISTER";
    if (reason == JS_STOP_PPU_UNINITIALIZED_MEMORY) return "JS_STOP_PPU_UNINITIALIZED_MEMORY";
    switch (reason) {
        case JS_STOP_NONE: return "JS_STOP_NONE";
        case JS_STOP_WRONG_ROM: return "JS_STOP_WRONG_ROM";
        case JS_STOP_UNSUPPORTED_CARTRIDGE: return "JS_STOP_UNSUPPORTED_CARTRIDGE";
        case JS_STOP_UNKNOWN_STATIC_CONTEXT: return "JS_STOP_UNKNOWN_STATIC_CONTEXT";
        case JS_STOP_UNPROVED_DYNAMIC_TARGET: return "JS_STOP_UNPROVED_DYNAMIC_TARGET";
        case JS_STOP_UNPROVED_RETURN_CONTEXT: return "JS_STOP_UNPROVED_RETURN_CONTEXT";
        case JS_STOP_UNPROVED_EXECUTABLE_WRAM: return "JS_STOP_UNPROVED_EXECUTABLE_WRAM";
        case JS_STOP_UNPROVED_INTERRUPT_REENTRY: return "JS_STOP_UNPROVED_INTERRUPT_REENTRY";
        case JS_STOP_CODE_BYTES_UNAVAILABLE: return "JS_STOP_CODE_BYTES_UNAVAILABLE";
        case JS_STOP_CODE_BYTES_MISMATCH: return "JS_STOP_CODE_BYTES_MISMATCH";
        case JS_STOP_BUS_UNAVAILABLE: return "JS_STOP_BUS_UNAVAILABLE";
        case JS_STOP_BUS_FAULT: return "JS_STOP_BUS_FAULT";
        case JS_STOP_UNPROVED_SUCCESSOR_CONTEXT: return "JS_STOP_UNPROVED_SUCCESSOR_CONTEXT";
        case JS_STOP_INVALID_CPU_CONTEXT: return "JS_STOP_INVALID_CPU_CONTEXT";
        case JS_STOP_SCHEDULER_REQUIRED: return "JS_STOP_SCHEDULER_REQUIRED";
        case JS_STOP_TIMING_UNAVAILABLE: return "JS_STOP_TIMING_UNAVAILABLE";
        case JS_STOP_PPU_UNAVAILABLE: return "JS_STOP_PPU_UNAVAILABLE";
        case JS_STOP_APU_UNAVAILABLE: return "JS_STOP_APU_UNAVAILABLE";
        case JS_STOP_DMA_UNAVAILABLE: return "JS_STOP_DMA_UNAVAILABLE";
        case JS_STOP_INPUT_UNAVAILABLE: return "JS_STOP_INPUT_UNAVAILABLE";
        default: return "JS_STOP_UNRECOGNIZED";
    }
}

js_stop_reason js_machine_v05c_init(js_machine_v05c *m, const uint8_t *rom, size_t rom_size, js_v05c_bus bus) {
    memset(m, 0, sizeof(*m));
    m->canonical_rom = rom;
    m->canonical_rom_size = rom_size;
    m->bus = bus;
    m->cpu.sp = 0x01FFu;
    m->cpu.p = JS_FLAG_M | JS_FLAG_X | JS_FLAG_I;
    m->cpu.e = 1u;
    m->rom_identity_ok = (uint8_t)js_exact_rom_hash(rom, rom_size);
    return m->rom_identity_ok ? JS_STOP_NONE : JS_STOP_WRONG_ROM;
}

uint64_t js_v05c_pack_key(js_static_context_key key) {
    return JS_V05C_KEY_CONST(key.pbr, key.pc, key.e, key.m, key.x);
}

js_static_context_key js_v05c_key_from_cpu(const js_cpu65816_state *s) {
    js_static_context_key key;
    key.pbr = s->pbr;
    key.pc = s->pc;
    key.e = (uint8_t)(s->e & 1u);
    key.m = key.e ? 1u : (uint8_t)((s->p & JS_FLAG_M) != 0u);
    key.x = key.e ? 1u : (uint8_t)((s->p & JS_FLAG_X) != 0u);
    return key;
}

int js_v05c_key_equal(js_static_context_key a, js_static_context_key b) {
    return a.pbr == b.pbr && a.pc == b.pc && a.e == b.e && a.m == b.m && a.x == b.x;
}

void js_v05c_set_key(js_cpu65816_state *s, js_static_context_key key) {
    uint8_t old_p = s->p;
    s->pbr = key.pbr;
    s->pc = key.pc;
    s->e = key.e;
    if (key.m) s->p |= JS_FLAG_M; else s->p &= (uint8_t)~JS_FLAG_M;
    if (key.x) s->p |= JS_FLAG_X; else s->p &= (uint8_t)~JS_FLAG_X;
    js_v05c_normalize(s, old_p);
}

js_stop_reason js_v05c_guard_code(js_machine_v05c *m, uint32_t file_offset, const uint8_t *expected, size_t length) {
    size_t i;
    if (!m->rom_identity_ok) return JS_STOP_WRONG_ROM;
    if (!m->canonical_rom || m->canonical_rom_size != 2097152u || !expected) return JS_STOP_CODE_BYTES_UNAVAILABLE;
    if ((uint64_t)file_offset + (uint64_t)length > (uint64_t)m->canonical_rom_size) return JS_STOP_CODE_BYTES_MISMATCH;
    if (memcmp(m->canonical_rom + file_offset, expected, length) != 0) return JS_STOP_CODE_BYTES_MISMATCH;
    if (!m->bus.read8) return JS_STOP_BUS_UNAVAILABLE;

    /* V05C fixes the byte sequence at generation time; V06C supplies its real
       bus effects. This is not opcode decoding: each already-generated body reads
       exactly its fixed instruction bytes in program order and compares them. */
    for (i = 0u; i < length; i++) {
        uint8_t observed = 0u;
        uint32_t address = ((uint32_t)m->cpu.pbr << 16) | (uint16_t)(m->cpu.pc + (uint16_t)i);
        js_stop_reason result = m->bus.read8(m->bus.opaque, address, &observed);
        if (result != JS_STOP_NONE) return result;
        if (observed != expected[i]) return JS_STOP_CODE_BYTES_MISMATCH;
    }
    return JS_STOP_NONE;
}

js_stop_reason js_v05c_read8(js_machine_v05c *m, uint32_t addr, uint8_t *value) {
    if (!m->bus.read8) return JS_STOP_BUS_UNAVAILABLE;
    return m->bus.read8(m->bus.opaque, addr & 0xFFFFFFu, value);
}

js_stop_reason js_v05c_write8(js_machine_v05c *m, uint32_t addr, uint8_t value) {
    if (!m->bus.write8) return JS_STOP_BUS_UNAVAILABLE;
    return m->bus.write8(m->bus.opaque, addr & 0xFFFFFFu, value);
}

js_stop_reason js_v05c_idle_cycles(js_machine_v05c *m, unsigned cycles) {
    if (!m) return JS_STOP_TIMING_UNAVAILABLE;
    /* V06C regression machines have no scheduler and intentionally treat internal
       cycles as unplaced. V08C production always wires this callback. */
    if (!m->bus.idle_cycles) return JS_STOP_NONE;
    return m->bus.idle_cycles(m->bus.opaque, cycles);
}

static uint32_t js_next_addr(uint32_t addr, int bank0_wrap) {
    if (bank0_wrap) return (addr & 0xFF0000u) | ((addr + 1u) & 0xFFFFu);
    return (addr + 1u) & 0xFFFFFFu;
}

js_stop_reason js_v05c_read_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t *value) {
    uint8_t lo = 0, hi = 0; js_stop_reason r;
    r = js_v05c_read8(m, addr, &lo); if (r != JS_STOP_NONE) return r;
    if (width == 8u) { *value = lo; return JS_STOP_NONE; }
    r = js_v05c_read8(m, js_next_addr(addr, bank0_wrap), &hi); if (r != JS_STOP_NONE) return r;
    *value = (uint16_t)(lo | ((uint16_t)hi << 8)); return JS_STOP_NONE;
}

js_stop_reason js_v05c_write_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t value) {
    js_stop_reason r = js_v05c_write8(m, addr, (uint8_t)value); if (r != JS_STOP_NONE) return r;
    if (width == 8u) return JS_STOP_NONE;
    return js_v05c_write8(m, js_next_addr(addr, bank0_wrap), (uint8_t)(value >> 8));
}

js_stop_reason js_v05c_write_rmw_value(js_machine_v05c *m, uint32_t addr, unsigned width, int bank0_wrap, uint16_t value) {
    if (width == 8u) return js_v05c_write8(m, addr, (uint8_t)value);
    /* W65C816 16-bit memory RMW writes the high byte before the low byte.
       This is an architectural access-order rule, separate from later SNES timing. */
    js_stop_reason r = js_v05c_write8(m, js_next_addr(addr, bank0_wrap), (uint8_t)(value >> 8));
    if (r != JS_STOP_NONE) return r;
    return js_v05c_write8(m, addr, (uint8_t)value);
}

static uint16_t js_direct_addr(const js_cpu65816_state *s, uint16_t offset, int allow_wrap) {
    if (allow_wrap && s->e && ((s->d & 0x00FFu) == 0u)) return (uint16_t)((s->d & 0xFF00u) | (offset & 0x00FFu));
    return (uint16_t)(s->d + offset);
}

uint32_t js_v05c_addr_direct(const js_machine_v05c *m, uint8_t offset) { return js_direct_addr(&m->cpu, offset, 1); }
uint32_t js_v05c_addr_direct_x(const js_machine_v05c *m, uint8_t offset) { return js_direct_addr(&m->cpu, (uint16_t)(offset + m->cpu.x), 1); }
uint32_t js_v05c_addr_abs(const js_machine_v05c *m, uint16_t absolute) { return ((uint32_t)m->cpu.dbr << 16) | absolute; }
uint32_t js_v05c_addr_abs_x(const js_machine_v05c *m, uint16_t absolute) { return (js_v05c_addr_abs(m, absolute) + m->cpu.x) & 0xFFFFFFu; }
uint32_t js_v05c_addr_abs_y(const js_machine_v05c *m, uint16_t absolute) { return (js_v05c_addr_abs(m, absolute) + m->cpu.y) & 0xFFFFFFu; }

js_stop_reason js_v05c_addr_dir_ind_y(js_machine_v05c *m, uint8_t offset, uint32_t *effective) {
    uint16_t lo_addr = js_direct_addr(&m->cpu, offset, 1);
    uint16_t hi_addr = js_direct_addr(&m->cpu, (uint16_t)(offset + 1u), 1);
    uint8_t lo, hi; js_stop_reason r;
    r = js_v05c_read8(m, lo_addr, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, hi_addr, &hi); if (r != JS_STOP_NONE) return r;
    *effective = ((((uint32_t)m->cpu.dbr << 16) | (uint16_t)(lo | ((uint16_t)hi << 8))) + m->cpu.y) & 0xFFFFFFu;
    return JS_STOP_NONE;
}

js_stop_reason js_v05c_addr_dir_ind_long(js_machine_v05c *m, uint8_t offset, uint32_t *effective) {
    uint16_t a0 = js_direct_addr(&m->cpu, offset, 0);
    uint16_t a1 = js_direct_addr(&m->cpu, (uint16_t)(offset + 1u), 0);
    uint16_t a2 = js_direct_addr(&m->cpu, (uint16_t)(offset + 2u), 0);
    uint8_t lo, hi, bank; js_stop_reason r;
    r = js_v05c_read8(m, a0, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, a1, &hi); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, a2, &bank); if (r != JS_STOP_NONE) return r;
    *effective = ((uint32_t)bank << 16) | (uint16_t)(lo | ((uint16_t)hi << 8));
    return JS_STOP_NONE;
}

js_stop_reason js_v05c_addr_dir_ind_long_y(js_machine_v05c *m, uint8_t offset, uint32_t *effective) {
    uint16_t a0 = js_direct_addr(&m->cpu, offset, 0);
    uint16_t a1 = js_direct_addr(&m->cpu, (uint16_t)(offset + 1u), 0);
    uint16_t a2 = js_direct_addr(&m->cpu, (uint16_t)(offset + 2u), 0);
    uint8_t lo, hi, bank; js_stop_reason r;
    r = js_v05c_read8(m, a0, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, a1, &hi); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, a2, &bank); if (r != JS_STOP_NONE) return r;
    *effective = (((uint32_t)bank << 16) | (uint16_t)(lo | ((uint16_t)hi << 8))) + m->cpu.y;
    *effective &= 0xFFFFFFu; return JS_STOP_NONE;
}

js_stop_reason js_v05c_read_abs_ind_target(js_machine_v05c *m, uint16_t pointer, uint16_t *target_pc) {
    uint8_t lo, hi; js_stop_reason r;
    r = js_v05c_read8(m, pointer, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, (uint16_t)(pointer + 1u), &hi); if (r != JS_STOP_NONE) return r;
    *target_pc = (uint16_t)(lo | ((uint16_t)hi << 8)); return JS_STOP_NONE;
}

js_stop_reason js_v05c_read_abs_x_ind_target(js_machine_v05c *m, uint16_t base, uint16_t *target_pc) {
    uint16_t ptr = (uint16_t)(base + m->cpu.x);
    uint32_t bank = (uint32_t)m->cpu.pbr << 16;
    uint8_t lo, hi; js_stop_reason r;
    r = js_v05c_read8(m, bank | ptr, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_read8(m, bank | (uint16_t)(ptr + 1u), &hi); if (r != JS_STOP_NONE) return r;
    *target_pc = (uint16_t)(lo | ((uint16_t)hi << 8)); return JS_STOP_NONE;
}

static uint16_t js_stack_push_addr(const js_cpu65816_state *s) { return s->e ? (uint16_t)(0x0100u | (s->sp & 0x00FFu)) : s->sp; }
static void js_stack_after_push(js_cpu65816_state *s) { s->sp = s->e ? (uint16_t)(0x0100u | ((s->sp - 1u) & 0x00FFu)) : (uint16_t)(s->sp - 1u); }
static uint16_t js_stack_before_pull(js_cpu65816_state *s) { s->sp = s->e ? (uint16_t)(0x0100u | ((s->sp + 1u) & 0x00FFu)) : (uint16_t)(s->sp + 1u); return s->sp; }

js_stop_reason js_v05c_push8(js_machine_v05c *m, uint8_t value) {
    js_stop_reason r = js_v05c_write8(m, js_stack_push_addr(&m->cpu), value); if (r != JS_STOP_NONE) return r;
    js_stack_after_push(&m->cpu); return JS_STOP_NONE;
}
js_stop_reason js_v05c_pull8(js_machine_v05c *m, uint8_t *value) { return js_v05c_read8(m, js_stack_before_pull(&m->cpu), value); }
js_stop_reason js_v05c_push16(js_machine_v05c *m, uint16_t value) {
    js_stop_reason r = js_v05c_push8(m, (uint8_t)(value >> 8)); if (r != JS_STOP_NONE) return r;
    return js_v05c_push8(m, (uint8_t)value);
}
js_stop_reason js_v05c_pull16(js_machine_v05c *m, uint16_t *value) {
    uint8_t lo, hi; js_stop_reason r = js_v05c_pull8(m, &lo); if (r != JS_STOP_NONE) return r;
    r = js_v05c_pull8(m, &hi); if (r != JS_STOP_NONE) return r;
    *value = (uint16_t)(lo | ((uint16_t)hi << 8)); return JS_STOP_NONE;
}

void js_v05c_normalize(js_cpu65816_state *s, uint8_t old_p) {
    s->e &= 1u;
    if (s->e) { s->p |= JS_FLAG_M | JS_FLAG_X; s->sp = (uint16_t)(0x0100u | (s->sp & 0x00FFu)); }
    if ((s->p & JS_FLAG_X) && !(old_p & JS_FLAG_X)) { s->x &= 0x00FFu; s->y &= 0x00FFu; }
    if (s->e) { s->x &= 0x00FFu; s->y &= 0x00FFu; }
}

void js_v05c_set_nz(js_cpu65816_state *s, uint16_t value, unsigned width) {
    uint16_t mask = width == 8u ? 0x00FFu : 0xFFFFu;
    uint16_t sign = width == 8u ? 0x0080u : 0x8000u;
    value &= mask; js_set_flag(s, JS_FLAG_Z, value == 0u); js_set_flag(s, JS_FLAG_N, (value & sign) != 0u);
}

uint16_t js_v05c_adc(js_cpu65816_state *s, uint16_t a, uint16_t b, unsigned width) {
    uint32_t mask = width == 8u ? 0xFFu : 0xFFFFu;
    uint32_t sign = width == 8u ? 0x80u : 0x8000u;
    uint32_t av = a & mask, bv = b & mask, carry = (s->p & JS_FLAG_C) ? 1u : 0u, result;
    if (!(s->p & JS_FLAG_D)) {
        uint32_t full = av + bv + carry; result = full & mask;
        js_set_flag(s, JS_FLAG_C, full > mask); js_set_flag(s, JS_FLAG_V, ((~(av ^ bv) & (av ^ result) & sign) != 0u));
        js_v05c_set_nz(s, (uint16_t)result, width); return (uint16_t)result;
    }
    result = (av & 0x000Fu) + (bv & 0x000Fu) + carry;
    if (result > 0x0009u) result += 0x0006u;
    result = (av & 0x00F0u) + (bv & 0x00F0u) + (result > 0x000Fu ? 0x10u : 0u) + (result & 0x000Fu);
    if (width == 16u) {
        if (result > 0x009Fu) result += 0x0060u;
        result = (av & 0x0F00u) + (bv & 0x0F00u) + (result > 0x00FFu ? 0x100u : 0u) + (result & 0x00FFu);
        if (result > 0x09FFu) result += 0x0600u;
        result = (av & 0xF000u) + (bv & 0xF000u) + (result > 0x0FFFu ? 0x1000u : 0u) + (result & 0x0FFFu);
        js_set_flag(s, JS_FLAG_V, ((~(av ^ bv) & (av ^ result) & 0x8000u) != 0u));
        if (result > 0x9FFFu) result += 0x6000u;
    } else {
        js_set_flag(s, JS_FLAG_V, ((~(av ^ bv) & (av ^ result) & 0x80u) != 0u));
        if (result > 0x009Fu) result += 0x0060u;
    }
    js_set_flag(s, JS_FLAG_C, result > mask); result &= mask; js_v05c_set_nz(s, (uint16_t)result, width); return (uint16_t)result;
}

uint16_t js_v05c_sbc(js_cpu65816_state *s, uint16_t a, uint16_t b, unsigned width) {
    uint32_t mask = width == 8u ? 0xFFu : 0xFFFFu;
    uint32_t sign = width == 8u ? 0x80u : 0x8000u;
    uint32_t av = a & mask, bv = b & mask, inv = (~bv) & mask, carry = (s->p & JS_FLAG_C) ? 1u : 0u;
    if (!(s->p & JS_FLAG_D)) {
        uint32_t full = av + inv + carry, result = full & mask;
        js_set_flag(s, JS_FLAG_C, full > mask);
        js_set_flag(s, JS_FLAG_V, ((~(av ^ inv) & (av ^ full) & sign) != 0u));
        js_v05c_set_nz(s, (uint16_t)result, width);
        return (uint16_t)result;
    }
    /* Keep decimal correction signed: the reference W65C816 staging intentionally
       uses negative intermediate values when a low digit borrows. */
    int32_t result = (int32_t)(av & 0x000Fu) + (int32_t)(inv & 0x000Fu) + (int32_t)carry;
    if (result <= 0x000F) result -= 0x0006;
    result = (int32_t)(av & 0x00F0u) + (int32_t)(inv & 0x00F0u) + (result > 0x000F ? 0x10 : 0) + (result & 0x000F);
    if (width == 16u) {
        if (result <= 0x00FF) result -= 0x0060;
        result = (int32_t)(av & 0x0F00u) + (int32_t)(inv & 0x0F00u) + (result > 0x00FF ? 0x100 : 0) + (result & 0x00FF);
        if (result <= 0x0FFF) result -= 0x0600;
        result = (int32_t)(av & 0xF000u) + (int32_t)(inv & 0xF000u) + (result > 0x0FFF ? 0x1000 : 0) + (result & 0x0FFF);
        js_set_flag(s, JS_FLAG_V, ((~(av ^ inv) & (av ^ (uint32_t)result) & 0x8000u) != 0u));
        if (result <= 0xFFFF) result -= 0x6000;
    } else {
        js_set_flag(s, JS_FLAG_V, ((~(av ^ inv) & (av ^ (uint32_t)result) & 0x80u) != 0u));
        if (result <= 0x00FF) result -= 0x0060;
    }
    js_set_flag(s, JS_FLAG_C, result > (int32_t)mask);
    uint16_t out = (uint16_t)((uint32_t)result & mask);
    js_v05c_set_nz(s, out, width);
    return out;
}

uint16_t js_v05c_compare(js_cpu65816_state *s, uint16_t lhs, uint16_t rhs, unsigned width) {
    uint16_t mask = width == 8u ? 0x00FFu : 0xFFFFu; lhs &= mask; rhs &= mask;
    uint16_t r = (uint16_t)((lhs - rhs) & mask); js_set_flag(s, JS_FLAG_C, lhs >= rhs); js_v05c_set_nz(s, r, width); return r;
}
uint16_t js_v05c_asl(js_cpu65816_state *s, uint16_t value, unsigned width) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu, sign=width==8u?0x0080u:0x8000u;
    js_set_flag(s,JS_FLAG_C,(value&sign)!=0u); value=(uint16_t)((value<<1)&mask); js_v05c_set_nz(s,value,width); return value;
}
uint16_t js_v05c_lsr(js_cpu65816_state *s, uint16_t value, unsigned width) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu; value&=mask; js_set_flag(s,JS_FLAG_C,(value&1u)!=0u); value=(uint16_t)(value>>1); js_v05c_set_nz(s,value,width); return value;
}
uint16_t js_v05c_rol(js_cpu65816_state *s, uint16_t value, unsigned width) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu, sign=width==8u?0x0080u:0x8000u; uint16_t cin=(s->p&JS_FLAG_C)?1u:0u;
    js_set_flag(s,JS_FLAG_C,(value&sign)!=0u); value=(uint16_t)(((value<<1)|cin)&mask); js_v05c_set_nz(s,value,width); return value;
}
uint16_t js_v05c_ror(js_cpu65816_state *s, uint16_t value, unsigned width) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu, sign=width==8u?0x0080u:0x8000u, cin=(s->p&JS_FLAG_C)?sign:0u; value&=mask;
    js_set_flag(s,JS_FLAG_C,(value&1u)!=0u); value=(uint16_t)((value>>1)|cin); js_v05c_set_nz(s,value,width); return value;
}
void js_v05c_bit(js_cpu65816_state *s, uint16_t a, uint16_t mem, unsigned width, int immediate) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu, sign=width==8u?0x0080u:0x8000u, ov=width==8u?0x0040u:0x4000u;
    js_set_flag(s,JS_FLAG_Z,((a&mem)&mask)==0u); if(!immediate){js_set_flag(s,JS_FLAG_N,(mem&sign)!=0u);js_set_flag(s,JS_FLAG_V,(mem&ov)!=0u);}
}
uint16_t js_v05c_trb(js_cpu65816_state *s, uint16_t a, uint16_t mem, unsigned width) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu; js_set_flag(s,JS_FLAG_Z,((a&mem)&mask)==0u); return (uint16_t)(mem & (uint16_t)~a & mask);
}
uint16_t js_v05c_increment(js_cpu65816_state *s, uint16_t value, unsigned width, int delta) {
    uint16_t mask=width==8u?0x00FFu:0xFFFFu; value=(uint16_t)((value+delta)&mask); js_v05c_set_nz(s,value,width); return value;
}

void js_v05c_write_a(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags) {
    if(width==8u) s->a=(uint16_t)((s->a&0xFF00u)|(value&0x00FFu)); else s->a=value;
    if(set_flags) js_v05c_set_nz(s,value,width);
}
void js_v05c_write_x(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags) {
    s->x=(uint16_t)(value & (width==8u?0x00FFu:0xFFFFu)); if(set_flags) js_v05c_set_nz(s,s->x,width);
}
void js_v05c_write_y(js_cpu65816_state *s, uint16_t value, unsigned width, int set_flags) {
    s->y=(uint16_t)(value & (width==8u?0x00FFu:0xFFFFu)); if(set_flags) js_v05c_set_nz(s,s->y,width);
}

void js_v05c_diagnostic_begin_step(js_machine_v05c *m) {
    uint32_t slot;
    if (!m) return;
    m->diagnostic_current_key = js_v05c_key_from_cpu(&m->cpu);
    slot = m->diagnostic_trace_next % JS_V05C_DIAGNOSTIC_TRACE_CAPACITY;
    m->diagnostic_trace[slot] = m->diagnostic_current_key;
    m->diagnostic_trace_next =
        (slot + 1u) % JS_V05C_DIAGNOSTIC_TRACE_CAPACITY;
    if (m->diagnostic_trace_count < JS_V05C_DIAGNOSTIC_TRACE_CAPACITY)
        ++m->diagnostic_trace_count;
}

void js_v05c_diagnostic_capture_stop(js_machine_v05c *m,
                                      js_stop_reason stop) {
    if (!m || stop == JS_STOP_NONE || m->diagnostic_failure_valid) return;
    m->diagnostic_failure_source = m->diagnostic_current_key;
    m->diagnostic_failure_target = js_v05c_key_from_cpu(&m->cpu);
    m->diagnostic_expected_count = 0u;
    m->diagnostic_expected_stored = 0u;
    m->diagnostic_stop_code = (uint32_t)stop;
    m->diagnostic_failure_valid = 1u;
}

js_stop_reason js_v05c_validate_current_key(js_machine_v05c *m, const js_static_context_key *allowed, size_t count, js_stop_reason failure) {
    js_static_context_key current = js_v05c_key_from_cpu(&m->cpu);
    for(size_t i=0;i<count;i++) if(js_v05c_key_equal(current,allowed[i])) return JS_STOP_NONE;
    if (m) {
        size_t stored = count < JS_V05C_DIAGNOSTIC_EXPECTED_CAPACITY ?
                        count : JS_V05C_DIAGNOSTIC_EXPECTED_CAPACITY;
        m->diagnostic_failure_source = m->diagnostic_current_key;
        m->diagnostic_failure_target = current;
        m->diagnostic_expected_count =
            count > UINT32_MAX ? UINT32_MAX : (uint32_t)count;
        m->diagnostic_expected_stored = (uint32_t)stored;
        if (stored) memcpy(m->diagnostic_expected, allowed,
                           stored * sizeof(m->diagnostic_expected[0]));
        m->diagnostic_stop_code = (uint32_t)failure;
        m->diagnostic_failure_valid = 1u;
    }
    return failure;
}

js_stop_reason js_v05c_finish_fixed(js_machine_v05c *m, js_static_context_key target) {
    m->cpu.pbr = target.pbr;
    m->cpu.pc = target.pc;
    if (!js_v05c_key_equal(js_v05c_key_from_cpu(&m->cpu), target)) {
        js_v05c_validate_current_key(
            m, &target, 1u, JS_STOP_UNPROVED_SUCCESSOR_CONTEXT);
        return JS_STOP_UNPROVED_SUCCESSOR_CONTEXT;
    }
    m->cpu.retired_instructions++;
    return JS_STOP_NONE;
}

js_stop_reason js_static_step_v05c(js_machine_v05c *m) {
    if (!m->rom_identity_ok) return JS_STOP_WRONG_ROM;
    js_static_context_key key = js_v05c_key_from_cpu(&m->cpu);
    js_v05c_diagnostic_begin_step(m);
    if ((key.e && (!key.m || !key.x)) || key.e > 1u || key.m > 1u || key.x > 1u) return JS_STOP_INVALID_CPU_CONTEXT;
    return js_static_dispatch_v05c(m, key);
}
