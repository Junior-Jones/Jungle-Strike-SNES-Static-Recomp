#include <string.h>
#include "jungle/bus.h"

static int js_v06c_is_system_bank(uint8_t bank) {
    return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu);
}

static int js_v06c_is_lorom_bank(uint8_t bank) {
    return bank <= 0x7Du || bank >= 0x80u;
}

static uint32_t js_v06c_lorom_offset(uint8_t bank, uint16_t address) {
    /* Exact V01C 2 MiB board contract: 64 physical 32 KiB blocks. */
    return ((uint32_t)(bank & 0x3Fu) << 15) | (uint32_t)(address & 0x7FFFu);
}

const char *js_bus_v06c_region_name(js_bus_region_v06c region) {
    switch (region) {
        case JS_BUS_REGION_UNMAPPED: return "UNMAPPED";
        case JS_BUS_REGION_WRAM: return "WRAM";
        case JS_BUS_REGION_ROM: return "ROM";
        case JS_BUS_REGION_SRAM: return "SRAM";
        case JS_BUS_REGION_PPU: return "PPU";
        case JS_BUS_REGION_APU: return "APU";
        case JS_BUS_REGION_WRAM_PORT: return "WRAM_PORT";
        case JS_BUS_REGION_INPUT: return "INPUT";
        case JS_BUS_REGION_CPU_IO: return "CPU_IO";
        case JS_BUS_REGION_DMA: return "DMA";
        case JS_BUS_REGION_COUNT: return "COUNT";
        default: return "INVALID";
    }
}

static void js_v06c_math_power_on(js_math_unit_v06c *math) {
    memset(math, 0, sizeof(*math));
    math->multiplicand = 0xFFu;
    math->dividend = 0xFFFFu;
}

static void js_v06c_clear_access_accounting(js_bus_v06c *bus) {
    bus->access_clock_sum = 0u;
    bus->read_count = 0u;
    bus->write_count = 0u;
    memset(bus->region_read_count, 0, sizeof(bus->region_read_count));
    memset(bus->region_write_count, 0, sizeof(bus->region_write_count));
    bus->math_cpu_cycles_advanced = 0u;
}

static void js_v06c_power_on_registers(js_bus_v06c *bus) {
    bus->open_bus = 0u;
    bus->nmitimen = 0u;
    bus->wrio = 0xFFu;
    bus->htime = 0x01FFu;
    bus->vtime = 0x01FFu;
    bus->memsel = 0u;
    bus->wram_port_address = 0u;
    js_v06c_clear_access_accounting(bus);
    js_v06c_math_power_on(&bus->math);
}

js_stop_reason js_bus_v06c_init(js_bus_v06c *bus, const uint8_t *rom, size_t rom_size, js_bus_ports_v06c ports) {
    if (!bus || !rom || rom_size != JS_V06C_ROM_SIZE) return JS_STOP_WRONG_ROM;
    memset(bus, 0, sizeof(*bus));
    bus->rom = rom;
    bus->rom_size = rom_size;
    bus->ports = ports;

    /* Deterministic project power-on policy. Physical SNES WRAM is not promised
       to power on as zero; no oracle/imported RAM state is being claimed here. */
    memset(bus->wram, 0, sizeof(bus->wram));
    js_v06c_power_on_registers(bus);
    return JS_STOP_NONE;
}

void js_bus_v06c_reset(js_bus_v06c *bus) {
    if (!bus) return;

    /* RESET is not power-on. Preserve WRAM, external open bus, WRIO, H/V timer
       latches, FastROM selection, WRAM-port position and ALU state. The enable
       state at $4200 resets; V07 owns IRQ/NMI/auto-joy event state. */
    bus->nmitimen = 0u;
    js_v06c_clear_access_accounting(bus);
}

js_bus_mapping_v06c js_bus_v06c_map(const js_bus_v06c *bus, uint32_t address) {
    js_bus_mapping_v06c out = { JS_BUS_REGION_UNMAPPED, 0u, 0u, 0u };
    uint32_t a;
    uint8_t bank;
    uint16_t offset;

    if (!bus) return out;
    a = address & 0xFFFFFFu;
    bank = (uint8_t)(a >> 16);
    offset = (uint16_t)a;

    if (bank == 0x7Eu || bank == 0x7Fu) {
        out.region = JS_BUS_REGION_WRAM;
        out.physical_offset = ((uint32_t)(bank - 0x7Eu) << 16) | offset;
        out.mapped = 1u;
        out.writable = 1u;
        return out;
    }

    if (js_v06c_is_system_bank(bank)) {
        if (offset <= 0x1FFFu) {
            out.region = JS_BUS_REGION_WRAM;
            out.physical_offset = offset;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
        if (offset >= 0x2140u && offset <= 0x217Fu) {
            out.region = JS_BUS_REGION_APU;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
        if (offset >= 0x2180u && offset <= 0x2183u) {
            out.region = JS_BUS_REGION_WRAM_PORT;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
        if (offset >= 0x2000u && offset <= 0x2FFFu) {
            out.region = JS_BUS_REGION_PPU;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
        if (offset == 0x4016u || offset == 0x4017u) {
            out.region = JS_BUS_REGION_INPUT;
            out.mapped = 1u;
            out.writable = (uint8_t)(offset == 0x4016u);
            return out;
        }
        if (offset >= 0x4300u && offset <= 0x437Fu) {
            out.region = JS_BUS_REGION_DMA;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
        if (offset >= 0x4000u && offset <= 0x4FFFu) {
            out.region = JS_BUS_REGION_CPU_IO;
            out.mapped = 1u;
            out.writable = 1u;
            return out;
        }
    }

    if (offset >= 0x8000u && js_v06c_is_lorom_bank(bank) && bank != 0x7Eu && bank != 0x7Fu) {
        out.region = JS_BUS_REGION_ROM;
        out.physical_offset = js_v06c_lorom_offset(bank, offset);
        out.mapped = (uint8_t)(bus->rom != NULL && bus->rom_size == JS_V06C_ROM_SIZE);
        out.writable = 0u;
        return out;
    }

    /* V01C proves SRAM size code $00. The explicit SRAM region therefore owns
       zero addresses for this exact cartridge; likely generic SRAM windows remain
       intentionally unmapped rather than becoming writable fallback memory. */
    return out;
}

unsigned js_bus_v06c_access_clocks(const js_bus_v06c *bus, uint32_t address) {
    uint32_t a = address & 0xFFFFFFu;
    uint8_t bank_class = (uint8_t)((a >> 22) & 3u);
    uint8_t page = (uint8_t)(a >> 8);
    int fastrom = bus && (bus->memsel & 1u) != 0u;

    if (bank_class == 1u) return 8u;              /* $40-$7F */
    if (bank_class == 3u) return fastrom ? 6u : 8u; /* $C0-$FF */

    /* $00-$3F and $80-$BF. */
    if (page <= 0x1Fu) return 8u;
    if (page <= 0x3Fu) return 6u;
    if (page == 0x40u || page == 0x41u) return 12u;
    if (page <= 0x5Fu) return 6u;
    if (page <= 0x7Fu) return 8u;
    if (bank_class == 0u) return 8u;
    return fastrom ? 6u : 8u;
}

static js_stop_reason js_v06c_component_read(js_component_port_v06c port, js_stop_reason missing, uint16_t reg, uint8_t *value) {
    if (!port.read8) return missing;
    return port.read8(port.opaque, reg, value);
}

static js_stop_reason js_v06c_component_write(js_component_port_v06c port, js_stop_reason missing, uint16_t reg, uint8_t value) {
    if (!port.write8) return missing;
    return port.write8(port.opaque, reg, value);
}

static void js_v06c_advance_one_math_cycle(js_math_unit_v06c *math) {
    if (math->multiply_cycles_remaining != 0u) {
        math->multiply_cycles_remaining--;
        if ((math->quotient & 1u) != 0u) {
            math->remainder_or_product = (uint16_t)(math->remainder_or_product + (uint16_t)math->shift);
        }
        math->shift <<= 1;
        math->quotient >>= 1;
    }
    if (math->divide_cycles_remaining != 0u) {
        math->divide_cycles_remaining--;
        math->shift >>= 1;
        math->quotient = (uint16_t)(math->quotient << 1);
        if ((uint32_t)math->remainder_or_product >= math->shift) {
            math->remainder_or_product = (uint16_t)((uint32_t)math->remainder_or_product - math->shift);
            math->quotient |= 1u;
        }
    }
}

void js_bus_v06c_advance_cpu_cycles(js_bus_v06c *bus, unsigned cycles) {
    if (!bus) return;
    while (cycles-- != 0u) {
        js_v06c_advance_one_math_cycle(&bus->math);
        bus->math_cpu_cycles_advanced++;
    }
}

static js_stop_reason js_v06c_peek_cpu_io(const js_bus_v06c *bus, uint16_t reg, uint8_t *value) {
    switch (reg) {
        case 0x4210u:
        case 0x4211u:
        case 0x4212u:
            return JS_STOP_TIMING_UNAVAILABLE;
        case 0x4213u:
            *value = bus->wrio;
            return JS_STOP_NONE;
        case 0x4214u:
            *value = (uint8_t)bus->math.quotient;
            return JS_STOP_NONE;
        case 0x4215u:
            *value = (uint8_t)(bus->math.quotient >> 8);
            return JS_STOP_NONE;
        case 0x4216u:
            *value = (uint8_t)bus->math.remainder_or_product;
            return JS_STOP_NONE;
        case 0x4217u:
            *value = (uint8_t)(bus->math.remainder_or_product >> 8);
            return JS_STOP_NONE;
        case 0x4218u: case 0x4219u: case 0x421Au: case 0x421Bu:
        case 0x421Cu: case 0x421Du: case 0x421Eu: case 0x421Fu:
            return JS_STOP_INPUT_UNAVAILABLE;
        default:
            *value = bus->open_bus;
            return JS_STOP_NONE;
    }
}

js_stop_reason js_bus_v06c_peek8(const js_bus_v06c *bus, uint32_t address, uint8_t *value) {
    js_bus_mapping_v06c map;
    uint16_t reg;
    if (!bus || !value) return JS_STOP_BUS_FAULT;
    map = js_bus_v06c_map(bus, address);
    reg = (uint16_t)address;

    switch (map.region) {
        case JS_BUS_REGION_WRAM:
            *value = bus->wram[map.physical_offset];
            return JS_STOP_NONE;
        case JS_BUS_REGION_ROM:
            if (!map.mapped || map.physical_offset >= bus->rom_size) return JS_STOP_BUS_FAULT;
            *value = bus->rom[map.physical_offset];
            return JS_STOP_NONE;
        case JS_BUS_REGION_SRAM:
            return JS_STOP_BUS_FAULT;
        case JS_BUS_REGION_WRAM_PORT:
            *value = reg == 0x2180u ? bus->wram[bus->wram_port_address & 0x1FFFFu] : bus->open_bus;
            return JS_STOP_NONE;
        case JS_BUS_REGION_CPU_IO:
            return js_v06c_peek_cpu_io(bus, reg, value);
        case JS_BUS_REGION_PPU:
            return JS_STOP_PPU_UNAVAILABLE;
        case JS_BUS_REGION_APU:
            return JS_STOP_APU_UNAVAILABLE;
        case JS_BUS_REGION_INPUT:
            return JS_STOP_INPUT_UNAVAILABLE;
        case JS_BUS_REGION_DMA:
            return JS_STOP_DMA_UNAVAILABLE;
        case JS_BUS_REGION_UNMAPPED:
        default:
            *value = bus->open_bus;
            return JS_STOP_NONE;
    }
}

js_stop_reason js_bus_v06c_sample_reset_vector(const js_bus_v06c *bus, uint16_t *vector) {
    js_bus_mapping_v06c lo_map;
    js_bus_mapping_v06c hi_map;
    uint8_t lo;
    uint8_t hi;
    js_stop_reason r;
    if (!bus || !vector) return JS_STOP_BUS_FAULT;

    lo_map = js_bus_v06c_map(bus, 0x00FFFCu);
    hi_map = js_bus_v06c_map(bus, 0x00FFFDu);
    if (lo_map.region != JS_BUS_REGION_ROM || hi_map.region != JS_BUS_REGION_ROM) return JS_STOP_BUS_FAULT;
    r = js_bus_v06c_peek8(bus, 0x00FFFCu, &lo);
    if (r != JS_STOP_NONE) return r;
    r = js_bus_v06c_peek8(bus, 0x00FFFDu, &hi);
    if (r != JS_STOP_NONE) return r;
    *vector = (uint16_t)(lo | ((uint16_t)hi << 8));
    return JS_STOP_NONE;
}

static js_stop_reason js_v06c_read_cpu_io(js_bus_v06c *bus, uint16_t reg, uint8_t *value) {
    switch (reg) {
        case 0x4210u:
        case 0x4211u:
        case 0x4212u: {
            uint8_t raw = 0u;
            js_stop_reason r = js_v06c_component_read(bus->ports.timing, JS_STOP_TIMING_UNAVAILABLE, reg, &raw);
            if (r != JS_STOP_NONE) return r;
            if (reg == 0x4210u) *value = (uint8_t)((raw & 0x80u) | 0x02u | (bus->open_bus & 0x70u));
            else if (reg == 0x4211u) *value = (uint8_t)((raw & 0x80u) | (bus->open_bus & 0x7Fu));
            else *value = (uint8_t)((raw & 0xC1u) | (bus->open_bus & 0x3Eu));
            return JS_STOP_NONE;
        }
        case 0x4213u:
            *value = bus->wrio;
            return JS_STOP_NONE;
        case 0x4214u:
            *value = (uint8_t)bus->math.quotient;
            return JS_STOP_NONE;
        case 0x4215u:
            *value = (uint8_t)(bus->math.quotient >> 8);
            return JS_STOP_NONE;
        case 0x4216u:
            *value = (uint8_t)bus->math.remainder_or_product;
            return JS_STOP_NONE;
        case 0x4217u:
            *value = (uint8_t)(bus->math.remainder_or_product >> 8);
            return JS_STOP_NONE;
        case 0x4218u: case 0x4219u: case 0x421Au: case 0x421Bu:
        case 0x421Cu: case 0x421Du: case 0x421Eu: case 0x421Fu:
            return js_v06c_component_read(bus->ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, value);
        default:
            *value = bus->open_bus;
            return JS_STOP_NONE;
    }
}

static js_stop_reason js_v06c_write_cpu_io(js_bus_v06c *bus, uint16_t reg, uint8_t value) {
    switch (reg) {
        case 0x4200u:
            bus->nmitimen = value;
            return JS_STOP_NONE;
        case 0x4201u:
            bus->wrio = value;
            return JS_STOP_NONE;
        case 0x4202u:
            bus->math.multiplicand = value;
            return JS_STOP_NONE;
        case 0x4203u: {
            int busy = bus->math.multiply_cycles_remaining != 0u || bus->math.divide_cycles_remaining != 0u;
            bus->math.remainder_or_product = 0u;
            if (!busy) {
                bus->math.multiplier = value;
                bus->math.multiply_cycles_remaining = 8u;
                bus->math.quotient = (uint16_t)(((uint16_t)value << 8) | bus->math.multiplicand);
                bus->math.shift = value;
            }
            return JS_STOP_NONE;
        }
        case 0x4204u:
            bus->math.dividend = (uint16_t)((bus->math.dividend & 0xFF00u) | value);
            return JS_STOP_NONE;
        case 0x4205u:
            bus->math.dividend = (uint16_t)((bus->math.dividend & 0x00FFu) | ((uint16_t)value << 8));
            return JS_STOP_NONE;
        case 0x4206u: {
            int busy = bus->math.multiply_cycles_remaining != 0u || bus->math.divide_cycles_remaining != 0u;
            bus->math.remainder_or_product = bus->math.dividend;
            if (!busy) {
                bus->math.divisor = value;
                bus->math.divide_cycles_remaining = 16u;
                bus->math.shift = (uint32_t)value << 16;
            }
            return JS_STOP_NONE;
        }
        case 0x4207u:
            bus->htime = (uint16_t)((bus->htime & 0x0100u) | value);
            return JS_STOP_NONE;
        case 0x4208u:
            bus->htime = (uint16_t)((bus->htime & 0x00FFu) | ((uint16_t)(value & 1u) << 8));
            return JS_STOP_NONE;
        case 0x4209u:
            bus->vtime = (uint16_t)((bus->vtime & 0x0100u) | value);
            return JS_STOP_NONE;
        case 0x420Au:
            bus->vtime = (uint16_t)((bus->vtime & 0x00FFu) | ((uint16_t)(value & 1u) << 8));
            return JS_STOP_NONE;
        case 0x420Bu:
        case 0x420Cu:
            return js_v06c_component_write(bus->ports.dma, JS_STOP_DMA_UNAVAILABLE, reg, value);
        case 0x420Du:
            bus->memsel = (uint8_t)(value & 1u);
            return JS_STOP_NONE;
        default:
            return JS_STOP_NONE;
    }
}

static void js_v06c_record_read(js_bus_v06c *bus, uint32_t address, js_bus_region_v06c region) {
    bus->access_clock_sum += js_bus_v06c_access_clocks(bus, address);
    bus->read_count++;
    if (region < JS_BUS_REGION_COUNT) bus->region_read_count[region]++;
}

static void js_v06c_record_write(js_bus_v06c *bus, uint32_t address, js_bus_region_v06c region) {
    bus->access_clock_sum += js_bus_v06c_access_clocks(bus, address);
    bus->write_count++;
    if (region < JS_BUS_REGION_COUNT) bus->region_write_count[region]++;
}

js_stop_reason js_bus_v06c_read8(js_bus_v06c *bus, uint32_t address, uint8_t *value) {
    js_bus_mapping_v06c map;
    js_stop_reason result = JS_STOP_NONE;
    uint32_t a;
    uint16_t reg;
    uint8_t v = 0u;
    int update_open_bus = 0;

    if (!bus || !value) return JS_STOP_BUS_FAULT;
    a = address & 0xFFFFFFu;
    reg = (uint16_t)a;
    map = js_bus_v06c_map(bus, a);
    js_v06c_record_read(bus, a, map.region);

    switch (map.region) {
        case JS_BUS_REGION_WRAM:
            v = bus->wram[map.physical_offset];
            update_open_bus = 1;
            break;
        case JS_BUS_REGION_ROM:
            if (!map.mapped || map.physical_offset >= bus->rom_size) return JS_STOP_BUS_FAULT;
            v = bus->rom[map.physical_offset];
            update_open_bus = 1;
            break;
        case JS_BUS_REGION_SRAM:
            return JS_STOP_BUS_FAULT;
        case JS_BUS_REGION_PPU:
            result = js_v06c_component_read(bus->ports.ppu, JS_STOP_PPU_UNAVAILABLE, reg, &v);
            update_open_bus = 1;
            break;
        case JS_BUS_REGION_APU:
            result = js_v06c_component_read(bus->ports.apu, JS_STOP_APU_UNAVAILABLE, (uint16_t)(0x2140u | (reg & 3u)), &v);
            update_open_bus = 1;
            break;
        case JS_BUS_REGION_WRAM_PORT:
            if (reg == 0x2180u) {
                v = bus->wram[bus->wram_port_address & 0x1FFFFu];
                bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
            } else {
                v = bus->open_bus;
            }
            update_open_bus = 1;
            break;
        case JS_BUS_REGION_INPUT:
            result = js_v06c_component_read(bus->ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, &v);
            break;
        case JS_BUS_REGION_CPU_IO:
            result = js_v06c_read_cpu_io(bus, reg, &v);
            break;
        case JS_BUS_REGION_DMA:
            result = js_v06c_component_read(bus->ports.dma, JS_STOP_DMA_UNAVAILABLE, reg, &v);
            break;
        case JS_BUS_REGION_UNMAPPED:
        default:
            v = bus->open_bus;
            break;
    }

    if (result != JS_STOP_NONE) return result;
    if (update_open_bus) bus->open_bus = v;
    *value = v;
    return JS_STOP_NONE;
}

js_stop_reason js_bus_v06c_write8(js_bus_v06c *bus, uint32_t address, uint8_t value) {
    js_bus_mapping_v06c map;
    js_stop_reason result = JS_STOP_NONE;
    uint32_t a;
    uint16_t reg;

    if (!bus) return JS_STOP_BUS_FAULT;
    a = address & 0xFFFFFFu;
    reg = (uint16_t)a;
    map = js_bus_v06c_map(bus, a);
    js_v06c_record_write(bus, a, map.region);

    switch (map.region) {
        case JS_BUS_REGION_WRAM:
            bus->wram[map.physical_offset] = value;
            break;
        case JS_BUS_REGION_ROM:
            /* Cartridge ROM ignores S-CPU writes. */
            break;
        case JS_BUS_REGION_SRAM:
            return JS_STOP_BUS_FAULT;
        case JS_BUS_REGION_PPU:
            result = js_v06c_component_write(bus->ports.ppu, JS_STOP_PPU_UNAVAILABLE, reg, value);
            break;
        case JS_BUS_REGION_APU:
            result = js_v06c_component_write(bus->ports.apu, JS_STOP_APU_UNAVAILABLE, (uint16_t)(0x2140u | (reg & 3u)), value);
            break;
        case JS_BUS_REGION_WRAM_PORT:
            if (reg == 0x2180u) {
                bus->wram[bus->wram_port_address & 0x1FFFFu] = value;
                bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
            } else if (reg == 0x2181u) {
                bus->wram_port_address = (bus->wram_port_address & 0x1FF00u) | value;
            } else if (reg == 0x2182u) {
                bus->wram_port_address = (bus->wram_port_address & 0x100FFu) | ((uint32_t)value << 8);
            } else if (reg == 0x2183u) {
                bus->wram_port_address = (bus->wram_port_address & 0x0FFFFu) | ((uint32_t)(value & 1u) << 16);
            }
            break;
        case JS_BUS_REGION_INPUT:
            if (reg == 0x4016u) {
                result = js_v06c_component_write(bus->ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, value);
            }
            break;
        case JS_BUS_REGION_CPU_IO:
            result = js_v06c_write_cpu_io(bus, reg, value);
            break;
        case JS_BUS_REGION_DMA:
            result = js_v06c_component_write(bus->ports.dma, JS_STOP_DMA_UNAVAILABLE, reg, value);
            break;
        case JS_BUS_REGION_UNMAPPED:
        default:
            /* Unmapped writes are explicit no-ops for the base cartridge. */
            break;
    }
    return result;
}
