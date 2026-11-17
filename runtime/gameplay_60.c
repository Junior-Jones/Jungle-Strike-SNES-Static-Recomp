#include "jungle/gameplay_60.h"

/* The original object pipeline integrates movement every field, but tests
   contacts only on selected phases. These BIT immediates gate pure geometry
   and event-owned effects; they do not integrate elapsed time. Retain the
   original compiled branch, target ordering and hit/consumption semantics.
   In particular, static scans may hit several overlapping targets, whereas
   dynamic scans unwind after their first hit. Do not divide their damage. */
void jungle_gameplay60_after_instruction(js_machine_v10_40 *machine,
                                        uint8_t previous_bank,uint16_t previous_pc) {
    js_cpu65816_state *cpu;
    if(!machine||previous_bank!=0x80u)return;
    cpu=&machine->cpu_core.cpu;
    if(cpu->pbr!=0x80u||cpu->e||(cpu->p&JS_FLAG_M))return;
    /* The native phase-1-only poll drops a one-field Select press in the
       other three publication phases. Accept only a pending Select edge on
       those fields; the original resource capture, fade and UI handoff still
       run unchanged. Negative 08EC is a scripted transition and keeps its
       native phase gate. Match CMP #1's equal flags, including carry. */
    if(previous_pc==0x818Fu&&cpu->pc==0x8192u&&
       machine->cpu_core.rom_identity_ok&&cpu->d==0u&&cpu->dbr==0x80u&&
       !(cpu->p&JS_FLAG_X)&&cpu->a<=3u&&
       (machine->bus.base.wram[0x2Du]&0x20u)&&
       !(machine->bus.base.wram[0x8EDu]&0x80u)){
        cpu->p|=JS_FLAG_Z|JS_FLAG_C;
        cpu->p&=(uint8_t)~JS_FLAG_N;
        return;
    }
    /* Once the publication IRQ has consumed the ready bit, post-publication
       object work must not wait for a second IRQ. Retain the native BEQ and
       wait while ready remains set. No extra movement pass or timer tick is
       inserted. The following input routine overwrites N/Z before use. */
    if(previous_pc==0x82F8u&&cpu->pc==0x82FAu&&cpu->d==0u&&
       !(machine->bus.base.wram[0x73u]&0x80u))
        cpu->p&=(uint8_t)~JS_FLAG_Z;
    if((previous_pc==0xBA7Bu&&cpu->pc==0xBA7Eu)||
       (previous_pc==0xD012u&&cpu->pc==0xD015u))
        cpu->p|=JS_FLAG_Z;
}

/* The feature samples contacts each field instead of every second/fourth
   field. Only pure ROM/WRAM geometry/filter work receives a software compute
   budget. Hit consumption, health, event spawning, timers, input, publishing
   and all device/DMA/interrupt work remain outside these instruction ranges. */
int jungle_gameplay60_geometry_context(const js_machine_v10_40 *machine) {
    const js_cpu65816_state *cpu;
    unsigned pc;
    if(!machine||!machine->cpu_core.rom_identity_ok)return 0;
    cpu=&machine->cpu_core.cpu;pc=cpu->pc;
    if(cpu->pbr!=0x80u||cpu->e||cpu->d!=0u||cpu->dbr!=0x7fu||
       (cpu->p&(JS_FLAG_M|JS_FLAG_X|JS_FLAG_D))||cpu->waiting||cpu->stopped||
       machine->scheduler.nmi_pending||
       (js_scheduler_v09c_irq_asserted(&machine->scheduler)&&!(cpu->p&JS_FLAG_I))||
       machine->scheduler.dma_pending_mask||machine->scheduler.hdma_init_pending||
       machine->scheduler.hdma_line_pending||machine->dma.active_channel!=255u||
       machine->bus.base.math.multiply_cycles_remaining||
       machine->bus.base.math.divide_cycles_remaining)return 0;
    return (pc>=0xd018u&&pc<0xd1d1u)||
           (pc>=0xd25eu&&pc<0xd3d8u)||
           (pc>=0xd410u&&pc<0xd44du)||
           (pc>=0xd485u&&pc<=0xd636u)||
           (pc>=0xd637u&&pc<=0xd659u)||
           (pc>=0xd680u&&pc<=0xd6a4u);
}
