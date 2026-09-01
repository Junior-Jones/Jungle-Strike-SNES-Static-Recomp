#include <string.h>
#include "jungle/ppu_v09c.h"

static const js_ppu_register_descriptor_v09c js_v09c_registers[JS_V09C_PPU_REG_COUNT] = {
    { "INIDISP", JS_PPU_REG_V09C_WRITE_STATE },
    { "OBSEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "OAMADDL", JS_PPU_REG_V09C_WRITE_STATE },
    { "OAMADDH", JS_PPU_REG_V09C_WRITE_STATE },
    { "OAMDATA", JS_PPU_REG_V09C_WRITE_STATE },
    { "BGMODE", JS_PPU_REG_V09C_WRITE_STATE },
    { "MOSAIC", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG1SC", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG2SC", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG3SC", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG4SC", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG12NBA", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG34NBA", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG1HOFS/M7HOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG1VOFS/M7VOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG2HOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG2VOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG3HOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG3VOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG4HOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "BG4VOFS", JS_PPU_REG_V09C_WRITE_STATE },
    { "VMAIN", JS_PPU_REG_V09C_WRITE_STATE },
    { "VMADDL", JS_PPU_REG_V09C_WRITE_STATE },
    { "VMADDH", JS_PPU_REG_V09C_WRITE_STATE },
    { "VMDATAL", JS_PPU_REG_V09C_WRITE_STATE },
    { "VMDATAH", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7SEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7A", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7B", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7C", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7D", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7X", JS_PPU_REG_V09C_WRITE_STATE },
    { "M7Y", JS_PPU_REG_V09C_WRITE_STATE },
    { "CGADD", JS_PPU_REG_V09C_WRITE_STATE },
    { "CGDATA", JS_PPU_REG_V09C_WRITE_STATE },
    { "W12SEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "W34SEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "WOBJSEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "WH0", JS_PPU_REG_V09C_WRITE_STATE },
    { "WH1", JS_PPU_REG_V09C_WRITE_STATE },
    { "WH2", JS_PPU_REG_V09C_WRITE_STATE },
    { "WH3", JS_PPU_REG_V09C_WRITE_STATE },
    { "WBGLOG", JS_PPU_REG_V09C_WRITE_STATE },
    { "WOBJLOG", JS_PPU_REG_V09C_WRITE_STATE },
    { "TM", JS_PPU_REG_V09C_WRITE_STATE },
    { "TS", JS_PPU_REG_V09C_WRITE_STATE },
    { "TMW", JS_PPU_REG_V09C_WRITE_STATE },
    { "TSW", JS_PPU_REG_V09C_WRITE_STATE },
    { "CGWSEL", JS_PPU_REG_V09C_WRITE_STATE },
    { "CGADSUB", JS_PPU_REG_V09C_WRITE_STATE },
    { "COLDATA", JS_PPU_REG_V09C_WRITE_STATE },
    { "SETINI", JS_PPU_REG_V09C_WRITE_STATE },
    { "MPYL", JS_PPU_REG_V09C_READ_STATUS },
    { "MPYM", JS_PPU_REG_V09C_READ_STATUS },
    { "MPYH", JS_PPU_REG_V09C_READ_STATUS },
    { "SLHV", JS_PPU_REG_V09C_READ_STATUS },
    { "OAMDATAREAD", JS_PPU_REG_V09C_READ_STATUS },
    { "VMDATALREAD", JS_PPU_REG_V09C_READ_STATUS },
    { "VMDATAHREAD", JS_PPU_REG_V09C_READ_STATUS },
    { "CGDATAREAD", JS_PPU_REG_V09C_READ_STATUS },
    { "OPHCT", JS_PPU_REG_V09C_READ_STATUS },
    { "OPVCT", JS_PPU_REG_V09C_READ_STATUS },
    { "STAT77", JS_PPU_REG_V09C_READ_STATUS },
    { "STAT78", JS_PPU_REG_V09C_READ_STATUS },
};


static void js_v09c_note(uint8_t bitmap[JS_V09C_VALUE_BITMAP_BYTES], uint8_t value) {
    bitmap[value >> 3] |= (uint8_t)(1u << (value & 7u));
}

static void js_v09c_set_known(uint8_t *bits, uint32_t index) {
    bits[index >> 3] |= (uint8_t)(1u << (index & 7u));
}

static int js_v09c_is_known(const uint8_t *bits, uint32_t index) {
    return (bits[index >> 3] & (uint8_t)(1u << (index & 7u))) != 0u;
}

static uint16_t js_v09c_dot_from_hclock(uint16_t hclock) {
    if (hclock <= 1292u) return (uint16_t)(hclock >> 2);
    if (hclock <= 1310u) return (uint16_t)((hclock - 2u) >> 2);
    return (uint16_t)((hclock - 4u) >> 2);
}

static int js_v09c_in_vblank(const js_ppu_v09c *ppu) {
    return ppu && ppu->scheduler && ppu->scheduler->scanline >= ppu->scheduler->vblank_start_scanline;
}

static int js_v09c_can_access_vram(const js_ppu_v09c *ppu) {
    return ppu && ppu->scheduler && (ppu->forced_blank || js_v09c_in_vblank(ppu));
}

static int js_v09c_can_access_cgram(const js_ppu_v09c *ppu) {
    uint16_t hclock;
    if (!ppu || !ppu->scheduler) return 0;
    hclock = ppu->scheduler->hclock;
    return ppu->forced_blank || js_v09c_in_vblank(ppu) || ppu->scheduler->scanline == 0u ||
           hclock < 88u || hclock >= 1096u;
}

uint16_t js_ppu_v09c_vram_word_address(const js_ppu_v09c *ppu) {
    uint16_t address;
    if (!ppu) return 0u;
    address = ppu->vram_address;
    switch (ppu->vram_remap & 3u) {
        case 1u:
            return (uint16_t)((address & 0xFF00u) | ((address & 0x00E0u) >> 5u) |
                              ((address & 0x001Fu) << 3u));
        case 2u:
            return (uint16_t)((address & 0xFE00u) | ((address & 0x01C0u) >> 6u) |
                              ((address & 0x003Fu) << 3u));
        case 3u:
            return (uint16_t)((address & 0xFC00u) | ((address & 0x0380u) >> 7u) |
                              ((address & 0x007Fu) << 3u));
        default:
            return address;
    }
}

static void js_v09c_update_vram_read_buffer(js_ppu_v09c *ppu) {
    uint16_t word_address;
    uint32_t byte_address;
    uint8_t known = 0u;
    if (!ppu) return;
    if (!js_v09c_can_access_vram(ppu)) {
        ppu->vram_read_buffer = 0u;
        ppu->vram_read_buffer_known = 0u;
        ppu->vram_read_buffer_state = JS_V09C_VRAM_BUFFER_RENDERER_DEPENDENT;
        return;
    }
    word_address = (uint16_t)(js_ppu_v09c_vram_word_address(ppu) & 0x7FFFu);
    byte_address = (uint32_t)word_address << 1u;
    if (js_v09c_is_known(ppu->vram_known, byte_address))
        known |= JS_V09C_VRAM_BUFFER_LOW_KNOWN;
    if (js_v09c_is_known(ppu->vram_known, byte_address + 1u))
        known |= JS_V09C_VRAM_BUFFER_HIGH_KNOWN;
    ppu->vram_read_buffer = ppu->vram[word_address];
    ppu->vram_read_buffer_known = known;
    ppu->vram_read_buffer_state = known == JS_V09C_VRAM_BUFFER_BOTH_KNOWN
                                      ? JS_V09C_VRAM_BUFFER_VALID
                                      : (known != 0u ? JS_V09C_VRAM_BUFFER_PARTIAL
                                                     : JS_V09C_VRAM_BUFFER_UNINITIALIZED);
}

static void js_v09c_update_oam_address(js_ppu_v09c *ppu) {
    if (!ppu) return;
    ppu->internal_oam_address = (uint16_t)(((uint32_t)ppu->oam_ram_address << 1u) & 0x03FFu);
}

static js_stop_reason js_v09c_oam_physical_address(const js_ppu_v09c *ppu, uint16_t *address) {
    uint16_t internal;
    if (!ppu || !ppu->scheduler || !address) return JS_STOP_PPU_INVALID_REGISTER;
    if (!ppu->forced_blank && !js_v09c_in_vblank(ppu)) {
        /* Active-display OAMDATA uses renderer evaluation/fetch state.  V09C
           deliberately refuses to approximate the renderer-owned address. */
        return JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS;
    }
    internal = ppu->internal_oam_address;
    *address = internal < 512u ? internal : (uint16_t)(0x0200u | (internal & 0x001Fu));
    return JS_STOP_NONE;
}

static void js_v09c_latch_location(js_ppu_v09c *ppu) {
    if (!ppu || !ppu->scheduler) return;
    ppu->horizontal_location = js_v09c_dot_from_hclock(ppu->scheduler->hclock);
    ppu->vertical_location = ppu->scheduler->scanline;
    ppu->location_latched = 1u;
}

static void js_v09c_window_select(js_ppu_v09c *ppu, uint8_t value, unsigned layer_offset) {
    unsigned index;
    for (index = 0u; index < 2u; ++index) {
        unsigned layer = layer_offset + index;
        if (layer >= 6u) break;
        ppu->window[0].active_layers[layer] = (uint8_t)((value >> (index * 4u + 1u)) & 1u);
        ppu->window[0].inverted_layers[layer] = (uint8_t)((value >> (index * 4u)) & 1u);
        ppu->window[1].active_layers[layer] = (uint8_t)((value >> (index * 4u + 3u)) & 1u);
        ppu->window[1].inverted_layers[layer] = (uint8_t)((value >> (index * 4u + 2u)) & 1u);
    }
}

static uint8_t js_v09c_cpu_open_bus(const js_ppu_v09c *ppu) {
    return (ppu && ppu->cpu_open_bus) ? *ppu->cpu_open_bus : 0u;
}

static uint8_t js_v09c_ppu1_mirror_read(const js_ppu_v09c *ppu, uint16_t reg) {
    uint16_t mirror = (uint16_t)(reg & 0x210Fu);
    if ((mirror >= 0x2104u && mirror <= 0x2106u) ||
        (mirror >= 0x2108u && mirror <= 0x210Au)) {
        return ppu ? ppu->ppu1_open_bus : 0u;
    }
    return js_v09c_cpu_open_bus(ppu);
}

void js_ppu_v09c_power_on(js_ppu_v09c *ppu, js_scheduler_v09c *scheduler,
                          const uint8_t *cpu_open_bus, const uint8_t *wrio) {
    if (!ppu) return;
    memset(ppu, 0, sizeof(*ppu));
    ppu->scheduler = scheduler;
    ppu->cpu_open_bus = cpu_open_bus;
    ppu->wrio = wrio;
    ppu->forced_blank = 1u;
    ppu->vram_increment = 1u;
    ppu->vram_read_buffer_state = JS_V09C_VRAM_BUFFER_UNINITIALIZED;
    ppu->vram_read_buffer_known = 0u;
    /* Storage is deterministically cleared for reproducible analysis, while the
       separate known-byte maps remain clear.  Therefore no release claim says
       physical SNES video memories power on as zero. */
}

void js_ppu_v09c_reset(js_ppu_v09c *ppu) {
    if (!ppu) return;
    /* CPU RESET preserves PPU memory/register state and forces display blank.
       Raster position remains owned by the monotonic V07C scheduler. */
    ppu->forced_blank = 1u;
}

void js_ppu_v09c_scheduler_event(void *opaque, js_scheduler_ppu_event_kind_v09c kind) {
    js_ppu_v09c *ppu = (js_ppu_v09c *)opaque;
    if (!ppu) return;
    if (kind == JS_SCHEDULER_PPU_EVENT_V09C_VBLANK_START) {
        if (!ppu->forced_blank) js_v09c_update_oam_address(ppu);
    } else if (kind == JS_SCHEDULER_PPU_EVENT_V09C_FRAME_START) {
        ppu->range_over = 0u;
        ppu->time_over = 0u;
    }
}

void js_ppu_v09c_set_sprite_flags(js_ppu_v09c *ppu, uint8_t range_over, uint8_t time_over) {
    if (!ppu) return;
    ppu->range_over = (uint8_t)(range_over != 0u);
    ppu->time_over = (uint8_t)(time_over != 0u);
}

int js_ppu_v09c_value_observed(const js_ppu_v09c *ppu, uint16_t reg, int is_write, uint8_t value) {
    uint16_t index;
    const uint8_t *bits;
    if (!ppu || reg < 0x2100u || reg > 0x213Fu) return 0;
    index = (uint16_t)(reg - 0x2100u);
    bits = is_write ? ppu->observed_write_values[index] : ppu->observed_read_values[index];
    return (bits[value >> 3] & (uint8_t)(1u << (value & 7u))) != 0u;
}

int js_ppu_v09c_vram_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address) {
    return ppu && js_v09c_is_known(ppu->vram_known, byte_address);
}

int js_ppu_v09c_cgram_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address) {
    return ppu && byte_address < JS_V09C_CGRAM_BYTES && js_v09c_is_known(ppu->cgram_known, byte_address);
}

int js_ppu_v09c_oam_byte_known(const js_ppu_v09c *ppu, uint16_t byte_address) {
    return ppu && byte_address < JS_V09C_OAM_BYTES && js_v09c_is_known(ppu->oam_known, byte_address);
}

js_stop_reason js_ppu_v09c_read8(void *opaque, uint16_t reg, uint8_t *value) {
    js_ppu_v09c *ppu = (js_ppu_v09c *)opaque;
    uint8_t result;
    uint16_t index;
    if (!ppu || !value) return JS_STOP_PPU_INVALID_REGISTER;

    if (reg < 0x2100u || reg > 0x213Fu) {
        *value = js_v09c_ppu1_mirror_read(ppu, reg);
        return JS_STOP_NONE;
    }

    index = (uint16_t)(reg - 0x2100u);
    ppu->register_reads[index]++;

    switch (reg) {
        case 0x2134u:
        case 0x2135u:
        case 0x2136u: {
            int32_t product = (int32_t)ppu->mode7.matrix[0] *
                              (int32_t)(int8_t)((uint16_t)ppu->mode7.matrix[1] >> 8u);
            unsigned shift = (unsigned)(reg - 0x2134u) * 8u;
            result = (uint8_t)(((uint32_t)product >> shift) & 0xFFu);
            ppu->ppu1_open_bus = result;
            break;
        }
        case 0x2137u:
            if (ppu->wrio && ((*ppu->wrio & 0x80u) != 0u)) js_v09c_latch_location(ppu);
            result = js_v09c_cpu_open_bus(ppu);
            break;
        case 0x2138u: {
            uint16_t address;
            js_stop_reason stop = js_v09c_oam_physical_address(ppu, &address);
            if (stop != JS_STOP_NONE) return stop;
            if (!js_v09c_is_known(ppu->oam_known, address)) return JS_STOP_PPU_UNINITIALIZED_MEMORY;
            result = ppu->oam[address];
            ppu->internal_oam_address = (uint16_t)((ppu->internal_oam_address + 1u) & 0x03FFu);
            ppu->ppu1_open_bus = result;
            break;
        }
        case 0x2139u:
        case 0x213Au: {
            int high = reg == 0x213Au;
            uint8_t required_known = high ? JS_V09C_VRAM_BUFFER_HIGH_KNOWN
                                          : JS_V09C_VRAM_BUFFER_LOW_KNOWN;
            if (ppu->vram_read_buffer_state == JS_V09C_VRAM_BUFFER_RENDERER_DEPENDENT)
                return JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS;
            if ((ppu->vram_read_buffer_known & required_known) == 0u)
                return JS_STOP_PPU_UNINITIALIZED_MEMORY;
            result = high ? (uint8_t)(ppu->vram_read_buffer >> 8u) : (uint8_t)ppu->vram_read_buffer;
            if ((high && ppu->vram_increment_on_high) || (!high && !ppu->vram_increment_on_high)) {
                js_v09c_update_vram_read_buffer(ppu);
                ppu->vram_address = (uint16_t)((ppu->vram_address + ppu->vram_increment) & 0x7FFFu);
            }
            ppu->ppu1_open_bus = result;
            break;
        }
        case 0x213Bu: {
            uint16_t address = ppu->cgram_address;
            uint16_t byte_address;
            if (!js_v09c_can_access_cgram(ppu)) return JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS;
            byte_address = (uint16_t)(address << 1u);
            if (ppu->cgram_high_latch) {
                if (!js_v09c_is_known(ppu->cgram_known, (uint16_t)(byte_address + 1u)))
                    return JS_STOP_PPU_UNINITIALIZED_MEMORY;
                result = (uint8_t)(((ppu->cgram[address] >> 8u) & 0x7Fu) | (ppu->ppu2_open_bus & 0x80u));
                ppu->cgram_address = (uint8_t)(ppu->cgram_address + 1u);
            } else {
                if (!js_v09c_is_known(ppu->cgram_known, byte_address))
                    return JS_STOP_PPU_UNINITIALIZED_MEMORY;
                result = (uint8_t)ppu->cgram[address];
            }
            ppu->cgram_high_latch ^= 1u;
            ppu->ppu2_open_bus = result;
            break;
        }
        case 0x213Cu:
            if (ppu->h_location_toggle) {
                result = (uint8_t)(((ppu->horizontal_location >> 8u) & 1u) | (ppu->ppu2_open_bus & 0xFEu));
            } else {
                result = (uint8_t)ppu->horizontal_location;
            }
            ppu->h_location_toggle ^= 1u;
            ppu->ppu2_open_bus = result;
            break;
        case 0x213Du:
            if (ppu->v_location_toggle) {
                result = (uint8_t)(((ppu->vertical_location >> 8u) & 1u) | (ppu->ppu2_open_bus & 0xFEu));
            } else {
                result = (uint8_t)ppu->vertical_location;
            }
            ppu->v_location_toggle ^= 1u;
            ppu->ppu2_open_bus = result;
            break;
        case 0x213Eu:
            result = (uint8_t)((ppu->time_over ? 0x80u : 0u) |
                               (ppu->range_over ? 0x40u : 0u) |
                               (ppu->ppu1_open_bus & 0x10u) | 0x01u);
            ppu->ppu1_open_bus = result;
            break;
        case 0x213Fu:
            result = (uint8_t)(((ppu->scheduler && ppu->scheduler->field) ? 0x80u : 0u) |
                               (ppu->location_latched ? 0x40u : 0u) |
                               (ppu->ppu2_open_bus & 0x20u) |
                               0x03u); /* NTSC region, 5C78 version 3. */
            if (ppu->wrio && ((*ppu->wrio & 0x80u) != 0u)) ppu->location_latched = 0u;
            ppu->h_location_toggle = 0u;
            ppu->v_location_toggle = 0u;
            ppu->ppu2_open_bus = result;
            break;
        default:
            result = js_v09c_ppu1_mirror_read(ppu, reg);
            break;
    }

    *value = result;
    js_v09c_note(ppu->observed_read_values[index], result);
    return JS_STOP_NONE;
}

js_stop_reason js_ppu_v09c_write8(void *opaque, uint16_t reg, uint8_t value) {
    js_ppu_v09c *ppu = (js_ppu_v09c *)opaque;
    uint16_t index;
    if (!ppu) return JS_STOP_PPU_INVALID_REGISTER;
    if (reg < 0x2100u || reg > 0x213Fu) return JS_STOP_NONE;

    index = (uint16_t)(reg - 0x2100u);
    ppu->register_writes[index]++;
    js_v09c_note(ppu->observed_write_values[index], value);

    switch (reg) {
        case 0x2100u:
            if (ppu->forced_blank && ppu->scheduler &&
                ppu->scheduler->scanline == ppu->scheduler->vblank_start_scanline) {
                js_v09c_update_oam_address(ppu);
            }
            ppu->forced_blank = (uint8_t)((value & 0x80u) != 0u);
            ppu->brightness = (uint8_t)(value & 0x0Fu);
            break;
        case 0x2101u:
            ppu->oam_mode = (uint8_t)((value >> 5u) & 7u);
            ppu->oam_base_address = (uint16_t)((uint32_t)(value & 7u) << 13u);
            ppu->oam_address_offset = (uint16_t)((((uint32_t)(value >> 3u) & 3u) + 1u) << 12u);
            break;
        case 0x2102u:
            ppu->oam_ram_address = (uint16_t)((ppu->oam_ram_address & 0x0100u) | value);
            js_v09c_update_oam_address(ppu);
            break;
        case 0x2103u:
            ppu->oam_ram_address = (uint16_t)((ppu->oam_ram_address & 0x00FFu) |
                                             ((uint16_t)(value & 1u) << 8u));
            ppu->oam_priority = (uint8_t)((value & 0x80u) != 0u);
            js_v09c_update_oam_address(ppu);
            break;
        case 0x2104u: {
            uint16_t address;
            js_stop_reason stop = js_v09c_oam_physical_address(ppu, &address);
            if (stop != JS_STOP_NONE) return stop;
            if (address < 512u) {
                if ((address & 1u) != 0u) {
                    ppu->oam[address - 1u] = ppu->oam_write_buffer;
                    ppu->oam[address] = value;
                    js_v09c_set_known(ppu->oam_known, address - 1u);
                    js_v09c_set_known(ppu->oam_known, address);
                } else {
                    ppu->oam_write_buffer = value;
                }
            } else {
                if ((ppu->internal_oam_address & 1u) == 0u) ppu->oam_write_buffer = value;
                ppu->oam[address] = value;
                js_v09c_set_known(ppu->oam_known, address);
            }
            ppu->internal_oam_address = (uint16_t)((ppu->internal_oam_address + 1u) & 0x03FFu);
            break;
        }
        case 0x2105u: {
            unsigned layer;
            ppu->bg_mode = (uint8_t)(value & 7u);
            ppu->mode1_bg3_priority = (uint8_t)((value & 8u) != 0u);
            for (layer = 0u; layer < 4u; ++layer)
                ppu->layer[layer].large_tiles = (uint8_t)((value >> (4u + layer)) & 1u);
            break;
        }
        case 0x2106u:
            ppu->mosaic_size = (uint8_t)(((value >> 4u) & 0x0Fu) + 1u);
            ppu->mosaic_enabled = (uint8_t)(value & 0x0Fu);
            break;
        case 0x2107u:
        case 0x2108u:
        case 0x2109u:
        case 0x210Au: {
            unsigned layer = (unsigned)(reg - 0x2107u);
            ppu->layer[layer].tilemap_address = (uint16_t)((uint32_t)(value & 0x7Cu) << 8u);
            ppu->layer[layer].double_width = (uint8_t)(value & 1u);
            ppu->layer[layer].double_height = (uint8_t)((value >> 1u) & 1u);
            break;
        }
        case 0x210Bu:
        case 0x210Cu: {
            unsigned layer = (unsigned)(reg - 0x210Bu) * 2u;
            ppu->layer[layer].chr_address = (uint16_t)((uint32_t)(value & 7u) << 12u);
            ppu->layer[layer + 1u].chr_address = (uint16_t)((uint32_t)(value & 0x70u) << 8u);
            break;
        }
        case 0x210Du:
            ppu->mode7.h_scroll = (int16_t)((((uint32_t)value << 8u) | ppu->mode7.value_latch) & 0x1FFFu);
            ppu->mode7.value_latch = value;
            /* $210D also writes BG1 horizontal scroll. */
            ppu->layer[0].h_scroll = (uint16_t)((((uint32_t)value << 8u) |
                                                ((uint32_t)ppu->hv_scroll_latch & 0xF8u) |
                                                ((uint32_t)ppu->h_scroll_latch & 7u)) & 0x03FFu);
            ppu->hv_scroll_latch = value;
            ppu->h_scroll_latch = value;
            break;
        case 0x210Fu:
        case 0x2111u:
        case 0x2113u: {
            unsigned layer = (unsigned)((reg - 0x210Du) >> 1u);
            ppu->layer[layer].h_scroll = (uint16_t)((((uint32_t)value << 8u) |
                                                     ((uint32_t)ppu->hv_scroll_latch & 0xF8u) |
                                                     ((uint32_t)ppu->h_scroll_latch & 7u)) & 0x03FFu);
            ppu->hv_scroll_latch = value;
            ppu->h_scroll_latch = value;
            break;
        }
        case 0x210Eu:
            ppu->mode7.v_scroll = (int16_t)((((uint32_t)value << 8u) | ppu->mode7.value_latch) & 0x1FFFu);
            ppu->mode7.value_latch = value;
            /* $210E also writes BG1 vertical scroll. */
            ppu->layer[0].v_scroll = (uint16_t)((((uint32_t)value << 8u) |
                                                (uint32_t)ppu->hv_scroll_latch) & 0x03FFu);
            ppu->hv_scroll_latch = value;
            break;
        case 0x2110u:
        case 0x2112u:
        case 0x2114u: {
            unsigned layer = (unsigned)((reg - 0x210Eu) >> 1u);
            ppu->layer[layer].v_scroll = (uint16_t)((((uint32_t)value << 8u) |
                                                     (uint32_t)ppu->hv_scroll_latch) & 0x03FFu);
            ppu->hv_scroll_latch = value;
            break;
        }
        case 0x2115u:
            switch (value & 3u) {
                case 0u: ppu->vram_increment = 1u; break;
                case 1u: ppu->vram_increment = 32u; break;
                default: ppu->vram_increment = 128u; break;
            }
            ppu->vram_remap = (uint8_t)((value >> 2u) & 3u);
            ppu->vram_increment_on_high = (uint8_t)((value & 0x80u) != 0u);
            break;
        case 0x2116u:
            ppu->vram_address = (uint16_t)((ppu->vram_address & 0x7F00u) | value);
            js_v09c_update_vram_read_buffer(ppu);
            break;
        case 0x2117u:
            ppu->vram_address = (uint16_t)((ppu->vram_address & 0x00FFu) |
                                          ((uint16_t)(value & 0x7Fu) << 8u));
            js_v09c_update_vram_read_buffer(ppu);
            break;
        case 0x2118u:
        case 0x2119u: {
            int high = reg == 0x2119u;
            uint16_t word_address = (uint16_t)(js_ppu_v09c_vram_word_address(ppu) & 0x7FFFu);
            uint32_t byte_address = ((uint32_t)word_address << 1u) + (unsigned)high;
            if (js_v09c_can_access_vram(ppu)) {
                if (high) {
                    ppu->vram[word_address] = (uint16_t)((ppu->vram[word_address] & 0x00FFu) |
                                                        ((uint16_t)value << 8u));
                } else {
                    ppu->vram[word_address] = (uint16_t)((ppu->vram[word_address] & 0xFF00u) | value);
                }
                js_v09c_set_known(ppu->vram_known, byte_address);
            }
            if ((high && ppu->vram_increment_on_high) || (!high && !ppu->vram_increment_on_high))
                ppu->vram_address = (uint16_t)((ppu->vram_address + ppu->vram_increment) & 0x7FFFu);
            break;
        }
        case 0x211Au:
            ppu->mode7.large_map = (uint8_t)((value >> 7u) & 1u);
            ppu->mode7.fill_with_tile0 = (uint8_t)((value >> 6u) & 1u);
            ppu->mode7.horizontal_mirror = (uint8_t)(value & 1u);
            ppu->mode7.vertical_mirror = (uint8_t)((value >> 1u) & 1u);
            break;
        case 0x211Bu:
        case 0x211Cu:
        case 0x211Du:
        case 0x211Eu: {
            unsigned matrix = (unsigned)(reg - 0x211Bu);
            ppu->mode7.matrix[matrix] = (int16_t)(((uint16_t)value << 8u) | ppu->mode7.value_latch);
            ppu->mode7.value_latch = value;
            break;
        }
        case 0x211Fu:
            ppu->mode7.center_x = (int16_t)(((uint16_t)value << 8u) | ppu->mode7.value_latch);
            ppu->mode7.value_latch = value;
            break;
        case 0x2120u:
            ppu->mode7.center_y = (int16_t)(((uint16_t)value << 8u) | ppu->mode7.value_latch);
            ppu->mode7.value_latch = value;
            break;
        case 0x2121u:
            ppu->cgram_address = value;
            ppu->cgram_high_latch = 0u;
            break;
        case 0x2122u:
            if (!ppu->cgram_high_latch) {
                /* The first CGDATA byte always updates the latch.  Historical V09
                   incorrectly rejected this byte during active display. */
                ppu->cgram_write_buffer = value;
                ppu->cgram_high_latch = 1u;
            } else {
                uint16_t address = ppu->cgram_address;
                uint16_t byte_address;
                if (!js_v09c_can_access_cgram(ppu))
                    return JS_STOP_PPU_RENDERER_DEPENDENT_ACCESS;
                byte_address = (uint16_t)(address << 1u);
                ppu->cgram[address] = (uint16_t)(ppu->cgram_write_buffer |
                                                ((uint16_t)(value & 0x7Fu) << 8u));
                js_v09c_set_known(ppu->cgram_known, byte_address);
                js_v09c_set_known(ppu->cgram_known, (uint16_t)(byte_address + 1u));
                ppu->cgram_address = (uint8_t)(ppu->cgram_address + 1u);
                ppu->cgram_high_latch = 0u;
            }
            break;
        case 0x2123u: js_v09c_window_select(ppu, value, 0u); break;
        case 0x2124u: js_v09c_window_select(ppu, value, 2u); break;
        case 0x2125u: js_v09c_window_select(ppu, value, 4u); break;
        case 0x2126u: ppu->window[0].left = value; break;
        case 0x2127u: ppu->window[0].right = value; break;
        case 0x2128u: ppu->window[1].left = value; break;
        case 0x2129u: ppu->window[1].right = value; break;
        case 0x212Au: {
            unsigned layer;
            for (layer = 0u; layer < 4u; ++layer)
                ppu->mask_logic[layer] = (uint8_t)((value >> (2u * layer)) & 3u);
            break;
        }
        case 0x212Bu:
            ppu->mask_logic[4] = (uint8_t)(value & 3u);
            ppu->mask_logic[5] = (uint8_t)((value >> 2u) & 3u);
            break;
        case 0x212Cu: ppu->main_screen_layers = (uint8_t)(value & 0x1Fu); break;
        case 0x212Du: ppu->sub_screen_layers = (uint8_t)(value & 0x1Fu); break;
        case 0x212Eu: ppu->window_mask_main = (uint8_t)(value & 0x1Fu); break;
        case 0x212Fu: ppu->window_mask_sub = (uint8_t)(value & 0x1Fu); break;
        case 0x2130u:
            ppu->color_math_clip_mode = (uint8_t)((value >> 6u) & 3u);
            ppu->color_math_prevent_mode = (uint8_t)((value >> 4u) & 3u);
            ppu->color_math_add_subscreen = (uint8_t)((value >> 1u) & 1u);
            ppu->direct_color = (uint8_t)(value & 1u);
            break;
        case 0x2131u:
            ppu->color_math_enabled = (uint8_t)(value & 0x3Fu);
            ppu->color_math_subtract = (uint8_t)((value >> 7u) & 1u);
            ppu->color_math_half = (uint8_t)((value >> 6u) & 1u);
            break;
        case 0x2132u:
            if (value & 0x80u)
                ppu->fixed_color = (uint16_t)((ppu->fixed_color & (uint16_t)~0x7C00u) |
                                              ((uint16_t)(value & 0x1Fu) << 10u));
            if (value & 0x40u)
                ppu->fixed_color = (uint16_t)((ppu->fixed_color & (uint16_t)~0x03E0u) |
                                              ((uint16_t)(value & 0x1Fu) << 5u));
            if (value & 0x20u)
                ppu->fixed_color = (uint16_t)((ppu->fixed_color & (uint16_t)~0x001Fu) |
                                              (uint16_t)(value & 0x1Fu));
            break;
        case 0x2133u:
            ppu->external_sync = (uint8_t)((value >> 7u) & 1u);
            ppu->extbg = (uint8_t)((value >> 6u) & 1u);
            ppu->hires = (uint8_t)((value >> 3u) & 1u);
            ppu->overscan = (uint8_t)((value >> 2u) & 1u);
            ppu->obj_interlace = (uint8_t)((value >> 1u) & 1u);
            ppu->screen_interlace = (uint8_t)(value & 1u);
            if (ppu->scheduler)
                js_scheduler_v09c_set_ppu_timing(ppu->scheduler, ppu->overscan, ppu->screen_interlace);
            break;
        default:
            /* $2134-$213F are read/status registers; writes are ignored. */
            break;
    }
    return JS_STOP_NONE;
}

const js_ppu_register_descriptor_v09c *js_ppu_v09c_register_descriptor(uint16_t reg) {
    if (reg < 0x2100u || reg > 0x213Fu) return NULL;
    return &js_v09c_registers[reg - 0x2100u];
}
