#include <string.h>
#include "jungle/bus_v09c.h"
#include "jungle/scheduler_v09c.h"

static int js_v09c_is_system_bank(uint8_t bank) {
    return bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu);
}

static js_stop_reason js_v09c_component_read(js_component_port_v09c port,
                                              js_stop_reason missing,
                                              uint16_t reg,
                                              uint8_t *value) {
    if (!port.read8) return missing;
    return port.read8(port.opaque, reg, value);
}

static js_stop_reason js_v09c_component_write(js_component_port_v09c port,
                                               js_stop_reason missing,
                                               uint16_t reg,
                                               uint8_t value) {
    if (!port.write8) return missing;
    return port.write8(port.opaque, reg, value);
}

static js_stop_reason js_v09c_timing_read(void *opaque, uint16_t reg, uint8_t *value) {
    js_bus_v09c *bus = (js_bus_v09c *)opaque;
    if (!bus || !bus->scheduler || !value) return JS_STOP_TIMING_UNAVAILABLE;
    switch (reg) {
        /* V06C owns the internal A-bus/open-bus formatting.  The scheduler
           supplies only the hardware-owned bits so the value is not composed
           twice when js_bus_v06c_read8() applies its certified masks. */
        case 0x4210u: *value = (uint8_t)(js_scheduler_v09c_read_rdnmi(bus->scheduler, 0u) & 0x80u); return JS_STOP_NONE;
        case 0x4211u: *value = (uint8_t)(js_scheduler_v09c_read_timeup(bus->scheduler, 0u) & 0x80u); return JS_STOP_NONE;
        case 0x4212u: *value = (uint8_t)(js_scheduler_v09c_read_hvbjoy(bus->scheduler, 0u) & 0xC1u); return JS_STOP_NONE;
        default: return JS_STOP_TIMING_UNAVAILABLE;
    }
}

static js_stop_reason js_v09c_begin_cpu_cycle(js_bus_v09c *bus) {
    js_stop_reason r;
    if (!bus || !bus->scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    r = js_scheduler_v09c_cpu_cycle_begin(bus->scheduler);
    if (r != JS_STOP_NONE) return r;
    js_bus_v06c_advance_cpu_cycles(&bus->base, 1u);
    bus->cpu_bus_cycles++;
    return JS_STOP_NONE;
}

static js_stop_reason js_v09c_advance_cpu(js_bus_v09c *bus, uint32_t clocks) {
    if (!bus || !bus->scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    return js_scheduler_v09c_advance_cpu(bus->scheduler, clocks);
}

js_stop_reason js_bus_v09c_init(js_bus_v09c *bus, const uint8_t *rom, size_t rom_size,
                                js_bus_ports_v09c ports, js_scheduler_v09c *scheduler) {
    js_stop_reason r;
    if (!bus || !scheduler) return JS_STOP_TIMING_UNAVAILABLE;
    memset(bus, 0, sizeof(*bus));
    bus->scheduler = scheduler;
    /* Scheduler-owned $4210-$4212 reads replace the V06C future-component seam.
       All other component ports remain exactly the caller-supplied V06C ports. */
    ports.timing.opaque = bus;
    ports.timing.read8 = js_v09c_timing_read;
    ports.timing.write8 = NULL;
    r = js_bus_v06c_init(&bus->base, rom, rom_size, ports);
    if (r != JS_STOP_NONE) return r;
    bus->cpu_speed_clocks = 8u;
    return JS_STOP_NONE;
}

void js_bus_v09c_snapshot_rebind(js_bus_v09c *bus, const uint8_t *rom,
                                 size_t rom_size, js_bus_ports_v09c ports,
                                 js_scheduler_v09c *scheduler) {
    if (!bus || !rom || !scheduler) return;
    bus->scheduler = scheduler;
    bus->base.rom = rom;
    bus->base.rom_size = rom_size;
    ports.timing.opaque = bus;
    ports.timing.read8 = js_v09c_timing_read;
    ports.timing.write8 = NULL;
    bus->base.ports = ports;
}

void js_bus_v09c_reset(js_bus_v09c *bus) {
    if (!bus) return;
    js_bus_v06c_reset(&bus->base);
    bus->dma_read_count = 0u;
    bus->dma_write_count = 0u;
    bus->cpu_bus_cycles = 0u;
    bus->cpu_idle_cycles = 0u;
    bus->cpu_speed_clocks = 8u;
}

js_bus_mapping_v09c js_bus_v09c_map(const js_bus_v09c *bus, uint32_t address) {
    js_bus_mapping_v09c empty = { JS_BUS_REGION_UNMAPPED, 0u, 0u, 0u };
    if (!bus) return empty;
    return js_bus_v06c_map(&bus->base, address);
}

unsigned js_bus_v09c_access_clocks(const js_bus_v09c *bus, uint32_t address) {
    return bus ? js_bus_v06c_access_clocks(&bus->base, address) : 8u;
}

js_stop_reason js_bus_v09c_peek8(const js_bus_v09c *bus, uint32_t address, uint8_t *value) {
    return bus ? js_bus_v06c_peek8(&bus->base, address, value) : JS_STOP_BUS_FAULT;
}

js_stop_reason js_bus_v09c_sample_reset_vector(const js_bus_v09c *bus, uint16_t *vector) {
    return bus ? js_bus_v06c_sample_reset_vector(&bus->base, vector) : JS_STOP_BUS_FAULT;
}

js_stop_reason js_bus_v09c_read8(js_bus_v09c *bus, uint32_t address, uint8_t *value) {
    js_stop_reason r;
    unsigned clocks;
    if (!bus || !value) return JS_STOP_BUS_FAULT;
    clocks = js_bus_v09c_access_clocks(bus, address);
    bus->cpu_speed_clocks = (uint8_t)clocks;
    r = js_v09c_begin_cpu_cycle(bus);
    if (r != JS_STOP_NONE) return r;
    r = js_v09c_advance_cpu(bus, clocks - 4u);
    if (r != JS_STOP_NONE) return r;
    r = js_bus_v06c_read8(&bus->base, address, value);
    if (r != JS_STOP_NONE) return r;
    r = js_v09c_advance_cpu(bus, 4u);
    if (r != JS_STOP_NONE) return r;
    return JS_STOP_NONE;
}

static void js_v09c_link_cpu_io_write(js_bus_v09c *bus, uint16_t reg, uint8_t value) {
    if (!bus || !bus->scheduler) return;
    switch (reg) {
        case 0x4200u:
            js_scheduler_v09c_write_nmitimen(bus->scheduler, value);
            break;
        case 0x4207u:
        case 0x4208u:
            js_scheduler_v09c_set_h_timer(bus->scheduler, bus->base.htime);
            break;
        case 0x4209u:
        case 0x420Au:
            js_scheduler_v09c_set_v_timer(bus->scheduler, bus->base.vtime);
            break;
        case 0x420Bu:
            js_scheduler_v09c_request_dma(bus->scheduler, value);
            break;
        case 0x420Cu:
            js_scheduler_v09c_set_hdma_enable(bus->scheduler, value);
            break;
        default:
            break;
    }
}

js_stop_reason js_bus_v09c_write8(js_bus_v09c *bus, uint32_t address, uint8_t value) {
    js_stop_reason r;
    unsigned clocks;
    uint16_t reg;
    js_bus_mapping_v09c map;
    if (!bus) return JS_STOP_BUS_FAULT;
    clocks = js_bus_v09c_access_clocks(bus, address);
    bus->cpu_speed_clocks = (uint8_t)clocks;
    r = js_v09c_begin_cpu_cycle(bus);
    if (r != JS_STOP_NONE) return r;
    r = js_v09c_advance_cpu(bus, clocks);
    if (r != JS_STOP_NONE) return r;
    r = js_bus_v06c_write8(&bus->base, address, value);
    if (r != JS_STOP_NONE) return r;
    map = js_bus_v09c_map(bus, address);
    reg = (uint16_t)address;
    if (map.region == JS_BUS_REGION_CPU_IO) js_v09c_link_cpu_io_write(bus, reg, value);
    return JS_STOP_NONE;
}

js_stop_reason js_bus_v09c_idle_cycles(js_bus_v09c *bus, unsigned cycles) {
    while (cycles-- != 0u) {
        js_stop_reason r = js_v09c_begin_cpu_cycle(bus);
        if (r != JS_STOP_NONE) return r;
        r = js_v09c_advance_cpu(bus, 6u);
        if (r != JS_STOP_NONE) return r;
        bus->cpu_idle_cycles++;
    }
    return JS_STOP_NONE;
}

int js_bus_v09c_is_wram_address(const js_bus_v09c *bus, uint32_t address) {
    js_bus_mapping_v09c map = js_bus_v09c_map(bus, address);
    return map.region == JS_BUS_REGION_WRAM;
}

static int js_v09c_dma_a_hits_bbus(uint32_t address) {
    uint8_t bank = (uint8_t)(address >> 16);
    uint16_t reg = (uint16_t)address;
    return js_v09c_is_system_bank(bank) && reg >= 0x2100u && reg <= 0x21FFu;
}

static int js_v09c_dma_hits_dma_register(uint32_t address) {
    uint8_t bank = (uint8_t)(address >> 16);
    uint16_t reg = (uint16_t)address;
    if (!js_v09c_is_system_bank(bank)) return 0;
    return reg == 0x420Bu || reg == 0x420Cu || (reg >= 0x4300u && reg <= 0x437Fu);
}

static js_stop_reason js_v09c_dma_read_cpu_io(js_bus_v09c *bus, uint16_t reg, uint8_t *value) {
    js_bus_v06c *b = &bus->base;
    switch (reg) {
        case 0x4210u: *value = js_scheduler_v09c_read_rdnmi(bus->scheduler, b->open_bus); return JS_STOP_NONE;
        case 0x4211u: *value = js_scheduler_v09c_read_timeup(bus->scheduler, b->open_bus); return JS_STOP_NONE;
        case 0x4212u: *value = js_scheduler_v09c_read_hvbjoy(bus->scheduler, b->open_bus); return JS_STOP_NONE;
        case 0x4213u: *value = b->wrio; return JS_STOP_NONE;
        case 0x4214u: *value = (uint8_t)b->math.quotient; return JS_STOP_NONE;
        case 0x4215u: *value = (uint8_t)(b->math.quotient >> 8); return JS_STOP_NONE;
        case 0x4216u: *value = (uint8_t)b->math.remainder_or_product; return JS_STOP_NONE;
        case 0x4217u: *value = (uint8_t)(b->math.remainder_or_product >> 8); return JS_STOP_NONE;
        case 0x4218u: case 0x4219u: case 0x421Au: case 0x421Bu:
        case 0x421Cu: case 0x421Du: case 0x421Eu: case 0x421Fu:
            return js_v09c_component_read(b->ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, value);
        default: *value = b->open_bus; return JS_STOP_NONE;
    }
}

static js_stop_reason js_v09c_dma_write_cpu_io(js_bus_v09c *bus, uint16_t reg, uint8_t value) {
    js_bus_v06c *b = &bus->base;
    switch (reg) {
        case 0x4200u: b->nmitimen = value; js_scheduler_v09c_write_nmitimen(bus->scheduler, value); return JS_STOP_NONE;
        case 0x4201u: b->wrio = value; return JS_STOP_NONE;
        case 0x4202u: b->math.multiplicand = value; return JS_STOP_NONE;
        case 0x4203u:
            b->math.remainder_or_product = 0u;
            if (b->math.multiply_cycles_remaining == 0u && b->math.divide_cycles_remaining == 0u) {
                b->math.multiplier = value;
                b->math.multiply_cycles_remaining = 8u;
                b->math.quotient = (uint16_t)(((uint16_t)value << 8) | b->math.multiplicand);
                b->math.shift = value;
            }
            return JS_STOP_NONE;
        case 0x4204u: b->math.dividend = (uint16_t)((b->math.dividend & 0xFF00u) | value); return JS_STOP_NONE;
        case 0x4205u: b->math.dividend = (uint16_t)((b->math.dividend & 0x00FFu) | ((uint16_t)value << 8)); return JS_STOP_NONE;
        case 0x4206u:
            b->math.remainder_or_product = b->math.dividend;
            if (b->math.multiply_cycles_remaining == 0u && b->math.divide_cycles_remaining == 0u) {
                b->math.divisor = value;
                b->math.divide_cycles_remaining = 16u;
                b->math.shift = (uint32_t)value << 16;
            }
            return JS_STOP_NONE;
        case 0x4207u: b->htime = (uint16_t)((b->htime & 0x0100u) | value); js_scheduler_v09c_set_h_timer(bus->scheduler, b->htime); return JS_STOP_NONE;
        case 0x4208u: b->htime = (uint16_t)((b->htime & 0x00FFu) | ((uint16_t)(value & 1u) << 8)); js_scheduler_v09c_set_h_timer(bus->scheduler, b->htime); return JS_STOP_NONE;
        case 0x4209u: b->vtime = (uint16_t)((b->vtime & 0x0100u) | value); js_scheduler_v09c_set_v_timer(bus->scheduler, b->vtime); return JS_STOP_NONE;
        case 0x420Au: b->vtime = (uint16_t)((b->vtime & 0x00FFu) | ((uint16_t)(value & 1u) << 8)); js_scheduler_v09c_set_v_timer(bus->scheduler, b->vtime); return JS_STOP_NONE;
        case 0x420Du: b->memsel = (uint8_t)(value & 1u); return JS_STOP_NONE;
        default: return JS_STOP_NONE;
    }
}

js_stop_reason js_bus_v09c_dma_read8(js_bus_v09c *bus, uint32_t address,
                                     uint8_t for_bus_a, uint8_t *value) {
    js_bus_mapping_v09c map;
    js_stop_reason r = JS_STOP_NONE;
    uint32_t a;
    uint16_t reg;
    uint8_t v;
    if (!bus || !value || !bus->scheduler) return JS_STOP_BUS_FAULT;
    a = address & 0xFFFFFFu;
    reg = (uint16_t)a;
    r = js_scheduler_v09c_advance_dma(bus->scheduler, 4u);
    if (r != JS_STOP_NONE) return r;
    bus->dma_read_count++;
    if (for_bus_a && (js_v09c_dma_a_hits_bbus(a) || js_v09c_dma_hits_dma_register(a))) {
        *value = bus->base.open_bus;
        return JS_STOP_NONE;
    }
    map = js_bus_v09c_map(bus, a);
    v = bus->base.open_bus;
    switch (map.region) {
        case JS_BUS_REGION_WRAM:
            v = bus->base.wram[map.physical_offset];
            break;
        case JS_BUS_REGION_ROM:
            if (!map.mapped || map.physical_offset >= bus->base.rom_size) return JS_STOP_BUS_FAULT;
            v = bus->base.rom[map.physical_offset];
            break;
        case JS_BUS_REGION_SRAM:
            return JS_STOP_BUS_FAULT;
        case JS_BUS_REGION_PPU:
            r = js_v09c_component_read(bus->base.ports.ppu, JS_STOP_PPU_UNAVAILABLE, reg, &v);
            break;
        case JS_BUS_REGION_APU:
            r = js_v09c_component_read(bus->base.ports.apu, JS_STOP_APU_UNAVAILABLE,
                                       (uint16_t)(0x2140u | (reg & 3u)), &v);
            break;
        case JS_BUS_REGION_WRAM_PORT:
            if (reg == 0x2180u) {
                v = bus->base.wram[bus->base.wram_port_address & 0x1FFFFu];
                bus->base.wram_port_address = (bus->base.wram_port_address + 1u) & 0x1FFFFu;
            }
            break;
        case JS_BUS_REGION_INPUT:
            r = js_v09c_component_read(bus->base.ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, &v);
            break;
        case JS_BUS_REGION_CPU_IO:
            r = js_v09c_dma_read_cpu_io(bus, reg, &v);
            break;
        case JS_BUS_REGION_DMA:
        case JS_BUS_REGION_UNMAPPED:
        default:
            v = bus->base.open_bus;
            break;
    }
    if (r != JS_STOP_NONE) return r;
    bus->base.open_bus = v;
    *value = v;
    return JS_STOP_NONE;
}

js_stop_reason js_bus_v09c_dma_write8(js_bus_v09c *bus, uint32_t address,
                                      uint8_t for_bus_a, uint8_t value) {
    js_bus_mapping_v09c map;
    js_stop_reason r = JS_STOP_NONE;
    uint32_t a;
    uint16_t reg;
    if (!bus || !bus->scheduler) return JS_STOP_BUS_FAULT;
    a = address & 0xFFFFFFu;
    reg = (uint16_t)a;
    r = js_scheduler_v09c_advance_dma(bus->scheduler, 4u);
    if (r != JS_STOP_NONE) return r;
    bus->dma_write_count++;
    if (for_bus_a && (js_v09c_dma_a_hits_bbus(a) || js_v09c_dma_hits_dma_register(a))) {
        /* The A-bus write side effect is blocked, but the DMA write value still
           becomes external open bus.  This ordering is observable by the next
           DMA read and matches SnesMemoryManager::WriteDma(). */
        bus->base.open_bus = value;
        return JS_STOP_NONE;
    }
    map = js_bus_v09c_map(bus, a);
    switch (map.region) {
        case JS_BUS_REGION_WRAM:
            bus->base.wram[map.physical_offset] = value;
            break;
        case JS_BUS_REGION_ROM:
            break;
        case JS_BUS_REGION_SRAM:
            return JS_STOP_BUS_FAULT;
        case JS_BUS_REGION_PPU:
            r = js_v09c_component_write(bus->base.ports.ppu, JS_STOP_PPU_UNAVAILABLE, reg, value);
            break;
        case JS_BUS_REGION_APU:
            r = js_v09c_component_write(bus->base.ports.apu, JS_STOP_APU_UNAVAILABLE,
                                        (uint16_t)(0x2140u | (reg & 3u)), value);
            break;
        case JS_BUS_REGION_WRAM_PORT:
            if (reg == 0x2180u) {
                bus->base.wram[bus->base.wram_port_address & 0x1FFFFu] = value;
                bus->base.wram_port_address = (bus->base.wram_port_address + 1u) & 0x1FFFFu;
            } else if (reg == 0x2181u) {
                bus->base.wram_port_address = (bus->base.wram_port_address & 0x1FF00u) | value;
            } else if (reg == 0x2182u) {
                bus->base.wram_port_address = (bus->base.wram_port_address & 0x100FFu) | ((uint32_t)value << 8);
            } else if (reg == 0x2183u) {
                bus->base.wram_port_address = (bus->base.wram_port_address & 0x0FFFFu) | ((uint32_t)(value & 1u) << 16);
            }
            break;
        case JS_BUS_REGION_INPUT:
            if (reg == 0x4016u) r = js_v09c_component_write(bus->base.ports.input, JS_STOP_INPUT_UNAVAILABLE, reg, value);
            break;
        case JS_BUS_REGION_CPU_IO:
            if (!js_v09c_dma_hits_dma_register(a)) r = js_v09c_dma_write_cpu_io(bus, reg, value);
            break;
        case JS_BUS_REGION_DMA:
        case JS_BUS_REGION_UNMAPPED:
        default:
            break;
    }
    if (r != JS_STOP_NONE) return r;
    bus->base.open_bus = value;
    return JS_STOP_NONE;
}
