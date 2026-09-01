#include <string.h>
#include "jungle/machine_v10_40.h"
#include "jungle/cpu_v08c_internal.h"
#include "jungle/cpu_dispatch_v10_100.h"

static js_stop_reason js_v10_40_dma_port_read(void *opaque, uint16_t reg, uint8_t *value) {
    return js_dma_v09c_read8(opaque, reg, value);
}

static js_stop_reason js_v10_40_dma_port_write(void *opaque, uint16_t reg, uint8_t value) {
    return js_dma_v09c_write8(opaque, reg, value);
}

static js_stop_reason js_v10_40_dma_scheduler_event(void *opaque,
                                                   js_dma_event_kind_v09c kind,
                                                   uint8_t channel_mask) {
    return js_dma_v09c_scheduler_event(opaque, kind, channel_mask);
}


static js_stop_reason js_v10_40_input_read(void *opaque, uint16_t reg, uint8_t *value) {
    return js_input_v10_2_read8(opaque, reg, value);
}

static js_stop_reason js_v10_40_input_write(void *opaque, uint16_t reg, uint8_t value) {
    return js_input_v10_2_write8(opaque, reg, value);
}

static js_stop_reason js_v10_40_apu_port_read(void *opaque, uint16_t reg, uint8_t *value) {
    return js_apu_v10_33_read8(opaque, reg, value);
}

static js_stop_reason js_v10_40_apu_port_write(void *opaque, uint16_t reg, uint8_t value) {
    return js_apu_v10_33_write8(opaque, reg, value);
}

static js_stop_reason js_v10_40_check_apu(js_machine_v10_40 *machine, js_stop_reason stop) {
    if (stop != JS_STOP_NONE) return stop;
    if (machine->apu.last_stop != JS_STOP_NONE) return machine->apu.last_stop;
    return JS_STOP_NONE;
}

static js_stop_reason js_v10_40_cpu_bus_read(void *opaque, uint32_t address, uint8_t *value) {
    js_machine_v10_40 *machine = (js_machine_v10_40 *)opaque;
    return js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, address, value));
}

static js_stop_reason js_v10_40_cpu_bus_write(void *opaque, uint32_t address, uint8_t value) {
    js_machine_v10_40 *machine = (js_machine_v10_40 *)opaque;
    uint8_t bank = (uint8_t)(address >> 16u);
    uint16_t offset = (uint16_t)address;
    uint8_t old_nmitimen = machine->scheduler.nmitimen;
    js_stop_reason stop = js_bus_v09c_write8(&machine->bus, address, value);
    if (stop != JS_STOP_NONE) return js_v10_40_check_apu(machine, stop);
    /* Version-10.2 input ownership: a $4200 autojoy-enable transition during
       the scheduler-owned initial strobe window changes the effective controller
       strobe immediately.  Keep this integration in the V10.2 machine rather
       than mutating the frozen V09C scheduler authority. */
    if (offset == 0x4200u && (bank & 0x40u) == 0u &&
        ((old_nmitimen ^ value) & 0x01u) != 0u &&
        machine->scheduler.autojoy_next_clock != UINT64_MAX &&
        machine->scheduler.master_clock >= machine->scheduler.autojoy_start_clock &&
        (machine->scheduler.master_clock - machine->scheduler.autojoy_start_clock) < 256u) {
        js_input_v10_2_autojoy_control(&machine->input, (uint8_t)((value & 1u) != 0u));
    }
    return js_v10_40_check_apu(machine, JS_STOP_NONE);
}

static js_stop_reason js_v10_40_cpu_idle(void *opaque, unsigned cycles) {
    js_machine_v10_40 *machine = (js_machine_v10_40 *)opaque;
    return js_v10_40_check_apu(machine, js_bus_v09c_idle_cycles(&machine->bus, cycles));
}

static js_v05c_bus js_v10_40_make_cpu_bus(js_machine_v10_40 *machine) {
    js_v05c_bus cpu_bus;
    cpu_bus.opaque = machine;
    cpu_bus.read8 = js_v10_40_cpu_bus_read;
    cpu_bus.write8 = js_v10_40_cpu_bus_write;
    cpu_bus.idle_cycles = js_v10_40_cpu_idle;
    return cpu_bus;
}

static js_stop_reason js_v10_40_seed_reset_vector(js_machine_v10_40 *machine) {
    uint16_t vector = 0u;
    js_stop_reason stop = js_bus_v09c_sample_reset_vector(&machine->bus, &vector);
    if (stop != JS_STOP_NONE) return stop;
    machine->cpu_core.cpu.pbr = 0u;
    machine->cpu_core.cpu.pc = vector;
    return JS_STOP_NONE;
}

static js_stop_reason js_v10_40_cpu_reset_sequence(js_machine_v10_40 *machine) {
    const uint8_t *rom = machine->bus.base.rom;
    size_t rom_size = machine->bus.base.rom_size;
    js_stop_reason stop = js_machine_v05c_init(&machine->cpu_core, rom, rom_size,
                                               js_v10_40_make_cpu_bus(machine));
    if (stop != JS_STOP_NONE) return stop;
    stop = js_v10_40_seed_reset_vector(machine);
    if (stop != JS_STOP_NONE) return stop;
    return js_scheduler_v09c_advance_wall(&machine->scheduler, 186u);
}

js_stop_reason js_machine_v10_40_init(js_machine_v10_40 *machine,
                                    const uint8_t *rom,
                                    size_t rom_size,
                                    js_bus_ports_v09c ports,
                                    js_scheduler_hooks_v09c hooks) {
    js_stop_reason stop;
    if (!machine) return JS_STOP_BUS_FAULT;
    memset(machine, 0, sizeof(*machine));

    hooks.dma_opaque = &machine->dma;
    hooks.dma_event = js_v10_40_dma_scheduler_event;
    hooks.ppu_opaque = &machine->ppu;
    hooks.ppu_event = js_ppu_v09c_scheduler_event;
    hooks.smp_opaque = &machine->apu;
    hooks.smp_sync = js_apu_v10_33_sync;
    hooks.autojoy_opaque = &machine->input;
    hooks.autojoy_step = js_input_v10_2_autojoy_step;

    ports.dma.opaque = &machine->dma;
    ports.dma.read8 = js_v10_40_dma_port_read;
    ports.dma.write8 = js_v10_40_dma_port_write;
    ports.ppu.opaque = &machine->ppu;
    ports.ppu.read8 = js_ppu_v09c_read8;
    ports.ppu.write8 = js_ppu_v09c_write8;
    ports.apu.opaque = &machine->apu;
    ports.apu.read8 = js_v10_40_apu_port_read;
    ports.apu.write8 = js_v10_40_apu_port_write;
    ports.input.opaque = &machine->input;
    ports.input.read8 = js_v10_40_input_read;
    ports.input.write8 = js_v10_40_input_write;

    js_scheduler_v09c_power_on(&machine->scheduler, hooks);
    stop = js_apu_v10_33_power_on(&machine->apu, &machine->scheduler);
    if (stop != JS_STOP_NONE) return stop;
    stop = js_bus_v09c_init(&machine->bus, rom, rom_size, ports, &machine->scheduler);
    if (stop != JS_STOP_NONE) { js_apu_v10_33_destroy(&machine->apu); return stop; }
    js_input_v10_2_power_on(&machine->input, &machine->bus.base.open_bus);
    js_ppu_v09c_power_on(&machine->ppu, &machine->scheduler,
                         &machine->bus.base.open_bus, &machine->bus.base.wrio);
    js_dma_v09c_init(&machine->dma, &machine->bus, &machine->scheduler);
    stop = js_v10_40_cpu_reset_sequence(machine);
    if (stop != JS_STOP_NONE) { js_apu_v10_33_destroy(&machine->apu); return stop; }
    return JS_STOP_NONE;
}

void js_machine_v10_40_destroy(js_machine_v10_40 *machine) {
    if (!machine) return;
    js_apu_v10_33_destroy(&machine->apu);
}

void js_machine_v10_40_snapshot_sanitize(js_machine_v10_40 *machine) {
    if (!machine) return;
    memset(&machine->scheduler.hooks, 0, sizeof(machine->scheduler.hooks));
    machine->bus.base.rom = NULL;
    memset(&machine->bus.base.ports, 0, sizeof(machine->bus.base.ports));
    machine->bus.scheduler = NULL;
    machine->dma.bus = NULL;
    machine->dma.scheduler = NULL;
    machine->ppu.scheduler = NULL;
    machine->ppu.cpu_open_bus = NULL;
    machine->ppu.wrio = NULL;
    machine->apu.scheduler = NULL;
    machine->apu.smp = NULL;
    machine->apu.dsp.aram = NULL;
    machine->apu.dsp.aram_known = NULL;
    machine->input.open_bus = NULL;
    memset(&machine->cpu_core.bus, 0, sizeof(machine->cpu_core.bus));
    machine->cpu_core.canonical_rom = NULL;
}

void js_machine_v10_40_snapshot_rebind(
    js_machine_v10_40 *machine, const uint8_t *rom, size_t rom_size,
    void *ppu_opaque, js_scheduler_ppu_event_fn ppu_event) {
    js_scheduler_hooks_v09c *hooks;
    js_bus_ports_v09c *ports;
    if (!machine || !rom || !machine->apu.smp) return;

    hooks = &machine->scheduler.hooks;
    memset(hooks, 0, sizeof(*hooks));
    hooks->dma_opaque = &machine->dma;
    hooks->dma_event = js_v10_40_dma_scheduler_event;
    hooks->ppu_opaque = ppu_opaque ? ppu_opaque : &machine->ppu;
    hooks->ppu_event = ppu_event ? ppu_event : js_ppu_v09c_scheduler_event;
    hooks->smp_opaque = &machine->apu;
    hooks->smp_sync = js_apu_v10_33_sync;
    hooks->autojoy_opaque = &machine->input;
    hooks->autojoy_step = js_input_v10_2_autojoy_step;

    ports = &machine->bus.base.ports;
    memset(ports, 0, sizeof(*ports));
    ports->dma.opaque = &machine->dma;
    ports->dma.read8 = js_v10_40_dma_port_read;
    ports->dma.write8 = js_v10_40_dma_port_write;
    ports->ppu.opaque = &machine->ppu;
    ports->ppu.read8 = js_ppu_v09c_read8;
    ports->ppu.write8 = js_ppu_v09c_write8;
    ports->apu.opaque = &machine->apu;
    ports->apu.read8 = js_v10_40_apu_port_read;
    ports->apu.write8 = js_v10_40_apu_port_write;
    ports->input.opaque = &machine->input;
    ports->input.read8 = js_v10_40_input_read;
    ports->input.write8 = js_v10_40_input_write;

    js_bus_v09c_snapshot_rebind(&machine->bus, rom, rom_size, *ports,
                                &machine->scheduler);
    machine->dma.bus = &machine->bus;
    machine->dma.scheduler = &machine->scheduler;
    machine->ppu.scheduler = &machine->scheduler;
    machine->ppu.cpu_open_bus = &machine->bus.base.open_bus;
    machine->ppu.wrio = &machine->bus.base.wrio;
    js_apu_v10_33_snapshot_rebind(&machine->apu, &machine->scheduler);
    machine->input.open_bus = &machine->bus.base.open_bus;
    machine->cpu_core.bus = js_v10_40_make_cpu_bus(machine);
    machine->cpu_core.canonical_rom = rom;
    machine->cpu_core.canonical_rom_size = rom_size;
}

js_stop_reason js_machine_v10_40_reset(js_machine_v10_40 *machine) {
    if (!machine) return JS_STOP_BUS_FAULT;
    js_scheduler_v09c_cpu_reset(&machine->scheduler);
    js_bus_v09c_reset(&machine->bus);
    js_dma_v09c_reset(&machine->dma);
    js_ppu_v09c_reset(&machine->ppu);
    js_apu_v10_33_cpu_reset(&machine->apu);
    js_input_v10_2_reset(&machine->input);
    js_scheduler_v09c_set_hdma_enable(&machine->scheduler, 0u);
    machine->nmi_entries = 0u;
    machine->irq_entries = 0u;
    machine->wai_wall_clocks = 0u;
    machine->wram_vector_dispatches = 0u;
    machine->wram_nmi_dispatches = 0u;
    machine->wram_irq_dispatches = 0u;
    return js_v10_40_cpu_reset_sequence(machine);
}

static js_stop_reason js_v10_40_interrupt_entry(js_machine_v10_40 *machine, int nmi) {
    js_cpu65816_state *cpu = &machine->cpu_core.cpu;
    js_stop_reason stop;
    uint16_t vector;
    uint8_t low = 0u;
    uint8_t high = 0u;

    cpu->waiting = 0u;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_idle_cycles(&machine->bus, 2u));
    if (stop != JS_STOP_NONE) return stop;

    if (cpu->e) {
        stop = js_v05c_push8(&machine->cpu_core, (uint8_t)(cpu->pc >> 8u)); if (stop != JS_STOP_NONE) return stop;
        stop = js_v05c_push8(&machine->cpu_core, (uint8_t)cpu->pc); if (stop != JS_STOP_NONE) return stop;
        stop = js_v05c_push8(&machine->cpu_core, (uint8_t)(cpu->p & (uint8_t)~0x10u)); if (stop != JS_STOP_NONE) return stop;
        vector = (uint16_t)(nmi ? 0xFFFAu : 0xFFFEu);
    } else {
        stop = js_v05c_push8(&machine->cpu_core, cpu->pbr); if (stop != JS_STOP_NONE) return stop;
        stop = js_v05c_push8(&machine->cpu_core, (uint8_t)(cpu->pc >> 8u)); if (stop != JS_STOP_NONE) return stop;
        stop = js_v05c_push8(&machine->cpu_core, (uint8_t)cpu->pc); if (stop != JS_STOP_NONE) return stop;
        stop = js_v05c_push8(&machine->cpu_core, cpu->p); if (stop != JS_STOP_NONE) return stop;
        vector = (uint16_t)(nmi ? 0xFFEAu : 0xFFEEu);
    }
    cpu->p |= JS_FLAG_I;
    cpu->p &= (uint8_t)~JS_FLAG_D;
    cpu->pbr = 0u;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, vector, &low)); if (stop != JS_STOP_NONE) return stop;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, (uint16_t)(vector + 1u), &high)); if (stop != JS_STOP_NONE) return stop;
    cpu->pc = (uint16_t)(low | ((uint16_t)high << 8u));
    if (nmi) machine->nmi_entries++; else machine->irq_entries++;

    /* Native vectors intentionally target the producer-controlled low-WRAM
       JMLs at $0000/$0004.  Before the reset path executes XCE, the hardware
       emulation vectors instead enter the two exact ROM contexts proved by the
       cartridge header: NMI $89D4 and IRQ $8000.  Admit only those four finite
       entries; all other executable WRAM/interrupt targets remain closed. */
    if (cpu->pbr == 0u) {
        if (!cpu->e && (cpu->pc == 0x0000u || cpu->pc == 0x0004u))
            return JS_STOP_NONE;
        if (cpu->e && ((nmi && cpu->pc == 0x89D4u) ||
                       (!nmi && cpu->pc == 0x8000u)))
            return JS_STOP_NONE;
    }
    return JS_STOP_UNPROVED_INTERRUPT_REENTRY;
}

static int js_v10_40_allowed_wram_target(uint16_t entry, uint16_t target, uint8_t bank) {
    /* Epoch 1/2 were proved by V04C.  The A0 epoch is also ROM-producer
       proved: A0:8035 LDA #$00A0 / XBA / PHA / PLB / PLB establishes
       DBR=$A0, then reached A0:D215-$D234 writes 5C B5 D7 A0 to $0000 and
       5C CA D3 A0 to $0004 using fixed immediates.  The reached A0:D725/A0:D728
       producer later writes the fixed immediate $D731 to $0005 while DBR remains
       $A0, producing 5C 31 D7 A0; the D731 handler later restores D3CA.  These
       are finite static vector epochs, not targets learned from the cold-boot observation. */
    if (entry == 0x0000u) {
        if (bank == 0x80u && target == 0x91BBu) return 1;
        if (bank == 0xA0u && target == 0xD7B5u) return 1;
        return 0;
    }
    if (entry == 0x0004u) {
        if (bank == 0x80u && (target == 0x89D6u || target == 0x90E2u)) return 1;
        if (bank == 0xA0u && (target == 0xD3CAu || target == 0xD731u)) return 1;
        return 0;
    }
    return 0;
}

js_stop_reason js_machine_v10_40_step_wram_vector(js_machine_v10_40 *machine) {
    js_cpu65816_state *cpu;
    uint16_t entry;
    uint8_t op = 0u, lo = 0u, hi = 0u, bank = 0u;
    uint16_t target;
    js_stop_reason stop;
    if (!machine) return JS_STOP_BUS_FAULT;
    cpu = &machine->cpu_core.cpu;
    if (cpu->pbr != 0u || (cpu->pc != 0x0000u && cpu->pc != 0x0004u))
        return JS_STOP_V10_1_UNPROVED_WRAM_VECTOR;
    entry = cpu->pc;

    /* Fetch the proved four-byte JML through the real timed bus so the thunk's
       four instruction fetch cycles and open-bus effects remain on the master
       timeline.  The bytes are then matched against the finite producer proof;
       there is no generic WRAM opcode decoding path. */
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, entry + 0u, &op)); if (stop != JS_STOP_NONE) return stop;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, entry + 1u, &lo)); if (stop != JS_STOP_NONE) return stop;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, entry + 2u, &hi)); if (stop != JS_STOP_NONE) return stop;
    stop = js_v10_40_check_apu(machine, js_bus_v09c_read8(&machine->bus, entry + 3u, &bank)); if (stop != JS_STOP_NONE) return stop;
    target = (uint16_t)(lo | ((uint16_t)hi << 8u));
    if (op != 0x5Cu || !js_v10_40_allowed_wram_target(entry, target, bank))
        return JS_STOP_V10_1_UNPROVED_WRAM_VECTOR;

    cpu->pbr = bank;
    cpu->pc = target;
    machine->wram_vector_dispatches++;
    if (entry == 0x0000u) machine->wram_nmi_dispatches++;
    else machine->wram_irq_dispatches++;
    return JS_STOP_NONE;
}

js_stop_reason js_machine_v10_40_step(js_machine_v10_40 *machine) {
    js_cpu65816_state *cpu;
    if (!machine) return JS_STOP_BUS_FAULT;
    cpu = &machine->cpu_core.cpu;
    if (machine->apu.last_stop != JS_STOP_NONE) return machine->apu.last_stop;
    if (cpu->stopped) return JS_STOP_NONE;

    if (cpu->pbr == 0u && (cpu->pc == 0x0000u || cpu->pc == 0x0004u))
        return js_machine_v10_40_step_wram_vector(machine);
    if (cpu->pbr == 0u && cpu->pc < 0x2000u)
        return JS_STOP_UNPROVED_EXECUTABLE_WRAM;

    if (js_scheduler_v09c_take_nmi(&machine->scheduler))
        return js_v10_40_interrupt_entry(machine, 1);
    if (js_scheduler_v09c_irq_asserted(&machine->scheduler)) {
        if (cpu->waiting) cpu->waiting = 0u;
        if ((cpu->p & JS_FLAG_I) == 0u) return js_v10_40_interrupt_entry(machine, 0);
    }

    if (cpu->waiting) {
        js_stop_reason stop = js_scheduler_v09c_advance_wall(&machine->scheduler, 2u);
        stop = js_v10_40_check_apu(machine, stop);
        if (stop == JS_STOP_NONE) machine->wai_wall_clocks += 2u;
        return stop;
    }
    {
        js_stop_reason stop;
        js_v05c_diagnostic_begin_step(&machine->cpu_core);
        stop = js_static_step_v10_100(&machine->cpu_core);
        js_v05c_diagnostic_capture_stop(&machine->cpu_core, stop);
        return stop;
    }
}
