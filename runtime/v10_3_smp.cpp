#include <cstdint>
#include <cstddef>
#include <cstring>
#include <new>
#include "jungle/smp_v10_2.h"

using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;
using int8 = std::int8_t;

namespace {

static const uint8 kIplRom[64] = {
  0xcd,0xef,0xbd,0xe8,0x00,0xc6,0x1d,0xd0,0xfc,0x8f,0xaa,0xf4,0x8f,0xbb,0xf5,0x78,
  0xcc,0xf4,0xd0,0xfb,0x2f,0x19,0xeb,0xf4,0xd0,0xfc,0x7e,0xf4,0xd0,0x0b,0xe4,0xf5,
  0xcb,0xf4,0xd7,0x00,0xfc,0xd0,0xf3,0xab,0x01,0x10,0xef,0x7e,0xf4,0x10,0xeb,0xba,
  0xf6,0xda,0x00,0xba,0xf4,0xc4,0xf4,0xdd,0x5d,0xd0,0xdb,0x1f,0x00,0x00,0xc0,0xff
};

#include "smp_v10_3_code_bitmap.inc"

struct SMPV102 {
  struct Flags {
    bool n{},v{},p{},b{},h{},i{},z{},c{};
    operator unsigned() const {
      return (n ? 0x80u : 0u) | (v ? 0x40u : 0u) | (p ? 0x20u : 0u) |
             (b ? 0x10u : 0u) | (h ? 0x08u : 0u) | (i ? 0x04u : 0u) |
             (z ? 0x02u : 0u) | (c ? 0x01u : 0u);
    }
    unsigned operator=(unsigned data) {
      n=(data&0x80)!=0; v=(data&0x40)!=0; p=(data&0x20)!=0; b=(data&0x10)!=0;
      h=(data&0x08)!=0; i=(data&0x04)!=0; z=(data&0x02)!=0; c=(data&0x01)!=0; return data;
    }
    unsigned operator|=(unsigned data){return operator=((unsigned)*this|data);}
    unsigned operator^=(unsigned data){return operator=((unsigned)*this^data);}
    unsigned operator&=(unsigned data){return operator=((unsigned)*this&data);}
  };
  struct Regs {
    struct Bytes { uint8 a{}, y{}; };
    uint16 pc{}; uint8 sp{};
    union { uint16 ya; Bytes B; };
    uint8 x{}; Flags p;
    Regs():ya(0){}
  } regs;
  struct Status { bool iplrom_enable{}; uint8 dsp_addr{}; uint8 ram00f8{},ram00f9{}; } status;
  template<unsigned F> struct Timer {
    bool enable{}; uint8 target{},stage1_ticks{},stage2_ticks{},stage3_ticks{};
    void tick(){ if((uint8)(stage1_ticks+1u) < F){ stage1_ticks++; return; } stage1_ticks=0; if(!enable)return; stage2_ticks=(uint8)(stage2_ticks+1u); if(stage2_ticks!=target)return; stage2_ticks=0; stage3_ticks=(uint8)((stage3_ticks+1u)&15u); }
    void tick(unsigned clocks){ while(clocks--) tick(); }
  };

  uint8 *aram{}; uint8 *known{}; uint8 *cpu_to_smp{}; uint8 *smp_to_cpu{};
  uint8 cpu_visible[4]{}; uint8 cpu_pending[4]{}; uint8 pending_mask{};
  uint8 dsp_regs[128]{}; uint8 dsp_known[16]{};
  void *dsp_hook_opaque{};
  js_smp_v10_2_dsp_write_hook dsp_write_hook{};
  js_smp_v10_2_dsp_read_hook dsp_read_hook{};
  js_smp_v10_2_dsp_cycle_hook dsp_cycle_hook{};
  Timer<128> timer0,timer1; Timer<16> timer2;
  unsigned resume_cycle{}; uint16 current_static_pc{},rd{},wr{},dp{},sp{},ya{},bit{}; uint8 guard_byte{0xff};
  uint64 executed_cycles{},instruction_count{},sc_aot_instructions{};
  uint64 code_write_barriers{},unknown_reads{},dsp_writes{},dsp_reads{},high_aram_writes{};
  uint16 fail_pc{}; uint8 expected_opcode{0xff},actual_opcode{0xff};
  js_stop_reason stop{JS_STOP_NONE}; bool code_sealed{}; bool stopped{};

  SMPV102(uint8 *a,uint8 *k,uint8 *c2s,uint8 *s2c):aram(a),known(k),cpu_to_smp(c2s),smp_to_cpu(s2c){}

  static bool mask_get(const uint8 *m,uint16 a){return (m[a>>3u] & (uint8)(1u<<(a&7u)))!=0u;}
  static void mask_set(uint8 *m,uint16 a){m[a>>3u] |= (uint8)(1u<<(a&7u));}
  bool code_owned(uint16 a) const {return mask_get(k_v10_3_code_bitmap,a);}
  bool aram_known(uint16 a) const {return mask_get(known,a);}
  void mark_known(uint16 a){mask_set(known,a);}
  bool dsp_is_known(uint8 a) const {return (dsp_known[a>>3u] & (uint8)(1u<<(a&7u)))!=0u;}
  void dsp_mark_known(uint8 a){dsp_known[a>>3u] |= (uint8)(1u<<(a&7u));}

  bool sc_aot_fail(uint32 reason,uint16 pc,uint8 expected,uint8 actual){
    if(stop!=JS_STOP_NONE) return false;
    switch(reason){
      case 1: stop=JS_STOP_V10_2_SMP_UNKNOWN_PC; break;
      case 2: stop=JS_STOP_V10_2_SMP_OPCODE_MISMATCH; break;
      case 3: stop=JS_STOP_V10_2_SMP_UNEMITTED_OPCODE; break;
      case 4: stop=JS_STOP_V10_2_SMP_CODE_WRITE; code_write_barriers++; break;
      case 5: stop=JS_STOP_V10_2_ARAM_READ_UNKNOWN; unknown_reads++; break;
      case 6: stop=JS_STOP_V10_2_SMP_CODE_NOT_READY; break;
      case 7: stop=JS_STOP_V10_2_DSP_READ_UNKNOWN; dsp_reads++; break;
      default: stop=JS_STOP_V10_2_SMP_UNEMITTED_OPCODE; break;
    }
    fail_pc=pc; expected_opcode=expected; actual_opcode=actual; return false;
  }

  bool seal_uploaded_code(){
    if(code_sealed) return true;
    for(unsigned a=0;a<65536u;a++) if(code_owned((uint16)a) && !aram_known((uint16)a)) return sc_aot_fail(6u,regs.pc,0xffu,0xffu);
    code_sealed=true; return true;
  }

  void apply_pending_cpu_ports(){
    if(!pending_mask) return;
    for(unsigned p=0;p<4;p++) if(pending_mask&(1u<<p)) cpu_visible[p]=cpu_pending[p];
    pending_mask=0;
  }
  void tick(){
    timer0.tick(); timer1.tick(); timer2.tick(); executed_cycles++; apply_pending_cpu_ports();
    if(dsp_cycle_hook && stop==JS_STOP_NONE){ js_stop_reason r=dsp_cycle_hook(dsp_hook_opaque,1u); if(r!=JS_STOP_NONE) stop=r; }
  }
  void tick(unsigned clocks){ while(clocks-- && stop==JS_STOP_NONE) tick(); }
  void op_io(){tick();} void op_io(unsigned c){tick(c);}

  uint8 mmio_read(uint16 addr){
    switch(addr){
      case 0xf2:return status.dsp_addr;
      case 0xf3:{
        uint8 a=(uint8)(status.dsp_addr&0x7fu);
        if(dsp_read_hook){ uint8 value=0; js_stop_reason r=dsp_read_hook(dsp_hook_opaque,a,&value); if(r!=JS_STOP_NONE){stop=r;return 0;} dsp_regs[a]=value;dsp_mark_known(a);dsp_reads++;return value; }
        if(!dsp_is_known(a)){sc_aot_fail(7u,regs.pc,a,0xffu);return 0;} dsp_reads++; return dsp_regs[a];}
      case 0xf4:case 0xf5:case 0xf6:case 0xf7:return cpu_visible[addr&3u];
      case 0xf8:return status.ram00f8; case 0xf9:return status.ram00f9;
      case 0xfd:{uint8 r=(uint8)(timer0.stage3_ticks&15u);timer0.stage3_ticks=0;return r;}
      case 0xfe:{uint8 r=(uint8)(timer1.stage3_ticks&15u);timer1.stage3_ticks=0;return r;}
      case 0xff:{uint8 r=(uint8)(timer2.stage3_ticks&15u);timer2.stage3_ticks=0;return r;}
      default:return 0;
    }
  }
  void mmio_write(uint16 addr,uint8 data){
    switch(addr){
      case 0xf1:{
        status.iplrom_enable=(data&0x80u)!=0;
        if(data&0x20u){cpu_visible[2]=cpu_visible[3]=0;cpu_pending[2]=cpu_pending[3]=0;pending_mask&=(uint8)~0x0cu;}
        if(data&0x10u){cpu_visible[0]=cpu_visible[1]=0;cpu_pending[0]=cpu_pending[1]=0;pending_mask&=(uint8)~0x03u;}
        if(!timer2.enable && (data&0x04u)){timer2.stage2_ticks=timer2.stage3_ticks=0;} timer2.enable=(data&0x04u)!=0;
        if(!timer1.enable && (data&0x02u)){timer1.stage2_ticks=timer1.stage3_ticks=0;} timer1.enable=(data&0x02u)!=0;
        if(!timer0.enable && (data&0x01u)){timer0.stage2_ticks=timer0.stage3_ticks=0;} timer0.enable=(data&0x01u)!=0;
        break;}
      case 0xf2:status.dsp_addr=data;break;
      case 0xf3:{if(!(status.dsp_addr&0x80u)){uint8 a=(uint8)(status.dsp_addr&0x7fu);dsp_regs[a]=data;dsp_mark_known(a);dsp_writes++;if(dsp_write_hook){js_stop_reason r=dsp_write_hook(dsp_hook_opaque,a,data);if(r!=JS_STOP_NONE)stop=r;}}break;}
      case 0xf4:case 0xf5:case 0xf6:case 0xf7:smp_to_cpu[addr&3u]=data;break;
      case 0xf8:status.ram00f8=data;break; case 0xf9:status.ram00f9=data;break;
      case 0xfa:timer0.target=data;break; case 0xfb:timer1.target=data;break; case 0xfc:timer2.target=data;break;
      default:break;
    }
  }

  uint8 op_read(uint16 addr){
    tick(); if(stop!=JS_STOP_NONE)return 0;
    if((addr&0xfff0u)==0x00f0u) return mmio_read(addr);
    if(addr>=0xffc0u && status.iplrom_enable) return kIplRom[addr&0x3fu];
    if(!aram_known(addr)){sc_aot_fail(5u,regs.pc,0xffu,0xffu);return 0;}
    return aram[addr];
  }
  void op_read_discard(uint16 addr){
    tick(); if(stop!=JS_STOP_NONE)return;
    if((addr&0xfff0u)==0x00f0u){
      /* Preserve read side effects without inventing an unknown value. */
      switch(addr){
        case 0xf3: dsp_reads++; break;
        case 0xfd: timer0.stage3_ticks=0; break;
        case 0xfe: timer1.stage3_ticks=0; break;
        case 0xff: timer2.stage3_ticks=0; break;
        default: break;
      }
      return;
    }
    /* IPL/ARAM dummy reads have no value-dependent architectural result. */
  }
  void op_write(uint16 addr,uint8 data){
    tick(); if(stop!=JS_STOP_NONE)return;
    if(code_sealed && code_owned(addr)){sc_aot_fail(4u,regs.pc,aram[addr],data);return;}
    if((addr&0xfff0u)==0x00f0u) mmio_write(addr,data);
    aram[addr]=data; mark_known(addr); if(addr>=0xf000u) high_aram_writes++;
  }
  uint8 op_readstack(){tick();uint16 a=(uint16)(0x0100u|++regs.sp);if(!aram_known(a)){sc_aot_fail(5u,regs.pc,0xffu,0xffu);return 0;}return aram[a];}
  void op_writestack(uint8 data){tick();uint16 a=(uint16)(0x0100u|regs.sp);if(code_sealed&&code_owned(a)){sc_aot_fail(4u,regs.pc,aram[a],data);return;}aram[a]=data;mark_known(a);regs.sp--;}

  uint8 op_adc(uint8,uint8); uint16 op_addw(uint16,uint16); uint8 op_and(uint8,uint8); uint8 op_cmp(uint8,uint8); uint16 op_cmpw(uint16,uint16);
  uint8 op_eor(uint8,uint8); uint8 op_inc(uint8); uint8 op_dec(uint8); uint8 op_or(uint8,uint8); uint8 op_sbc(uint8,uint8); uint16 op_subw(uint16,uint16);
  uint8 op_asl(uint8); uint8 op_lsr(uint8); uint8 op_rol(uint8); uint8 op_ror(uint8);
  bool sc_aot_prepare(uint16 pc,uint8 actual);

  void op_step(){
#define op_readpc() op_read(regs.pc++)
#define op_readdp(addr) op_read((uint16)(((unsigned)regs.p.p<<8u)+((addr)&0xffu)))
#define op_readdp_discard(addr) op_read_discard((uint16)(((unsigned)regs.p.p<<8u)+((addr)&0xffu)))
#define op_writedp(addr,data) op_write((uint16)(((unsigned)regs.p.p<<8u)+((addr)&0xffu)),(uint8)(data))
#define op_readaddr(addr) op_read((uint16)(addr))
#define op_readaddr_discard(addr) op_read_discard((uint16)(addr))
#define op_writeaddr(addr,data) op_write((uint16)(addr),(uint8)(data))
    if(stop!=JS_STOP_NONE||stopped)return;
    if(resume_cycle==0){
      current_static_pc=regs.pc;
      if(current_static_pc==0x0840u && !code_sealed && !seal_uploaded_code()) return;
      ++instruction_count; guard_byte=op_readpc(); if(stop!=JS_STOP_NONE)return;
      if(!sc_aot_prepare(current_static_pc,guard_byte)) return;
    }
    switch(current_static_pc){
#include "smp_v10_3_dispatch.inc"
    }
#undef op_readpc
#undef op_readdp
#undef op_readdp_discard
#undef op_writedp
#undef op_readaddr
#undef op_readaddr_discard
#undef op_writeaddr
  }

  void power_on(){
    std::memset(aram,0,65536); std::memset(known,0,8192); std::memset(cpu_to_smp,0,4); std::memset(smp_to_cpu,0,4);
    std::memset(cpu_visible,0,4);std::memset(cpu_pending,0,4);pending_mask=0;std::memset(dsp_regs,0,128);std::memset(dsp_known,0,16);
    regs=Regs{}; regs.pc=0xffc0; regs.sp=0xef; regs.p=0x02; status=Status{}; status.iplrom_enable=true;
    timer0=Timer<128>{};timer1=Timer<128>{};timer2=Timer<16>{};resume_cycle=0;current_static_pc=0;guard_byte=0xff;rd=wr=dp=sp=ya=bit=0;
    executed_cycles=instruction_count=sc_aot_instructions=0;code_write_barriers=unknown_reads=dsp_writes=dsp_reads=high_aram_writes=0;fail_pc=0;expected_opcode=actual_opcode=0xff;
    stop=JS_STOP_NONE;code_sealed=false;stopped=false;
  }
  void cpu_port_write(unsigned p,uint8 value){p&=3u;cpu_to_smp[p]=value;cpu_pending[p]=value;pending_mask|=(uint8)(1u<<p);}
  js_stop_reason run_to(uint64 target_ticks){
    uint64 target_cycles=target_ticks>>1u;
    while(stop==JS_STOP_NONE && !stopped && executed_cycles<target_cycles) op_step();
    return stop;
  }
};

#include "smp_v10_2_algorithms.inc"
#include "smp_v10_3_lookup.inc"

} // namespace

struct js_smp_v10_2 { SMPV102 impl; js_smp_v10_2(uint8*a,uint8*k,uint8*c,uint8*s):impl(a,k,c,s){} };

extern "C" js_smp_v10_2 *js_smp_v10_2_create(uint8_t *aram,uint8_t *known,uint8_t *c2s,uint8_t *s2c){
  if(!aram||!known||!c2s||!s2c) return nullptr;
  try { return new js_smp_v10_2(aram,known,c2s,s2c); }
  catch(...) { return nullptr; }
}
extern "C" void js_smp_v10_2_destroy(js_smp_v10_2 *s){delete s;}
extern "C" void js_smp_v10_2_power_on(js_smp_v10_2 *s){if(s)s->impl.power_on();}
extern "C" void js_smp_v10_2_cpu_port_write(js_smp_v10_2 *s,unsigned p,uint8_t v){if(s)s->impl.cpu_port_write(p,v);}
extern "C" void js_smp_v10_2_set_dsp_hooks(js_smp_v10_2 *s,void *opaque,
                                             js_smp_v10_2_dsp_write_hook wh,
                                             js_smp_v10_2_dsp_read_hook rh,
                                             js_smp_v10_2_dsp_cycle_hook ch){
  if(!s) return;
  s->impl.dsp_hook_opaque=opaque;
  s->impl.dsp_write_hook=wh;
  s->impl.dsp_read_hook=rh;
  s->impl.dsp_cycle_hook=ch;
}
extern "C" js_stop_reason js_smp_v10_2_run_to(js_smp_v10_2 *s,uint64_t target){return s?s->impl.run_to(target):JS_STOP_V10_2_SMP_ALLOCATION;}
extern "C" js_stop_reason js_smp_v10_2_last_stop(const js_smp_v10_2 *s){return s?s->impl.stop:JS_STOP_V10_2_SMP_ALLOCATION;}
extern "C" void js_smp_v10_2_get_state(const js_smp_v10_2 *s,js_smp_v10_2_state *o){
  if(!s||!o) return;
  const SMPV102 &x=s->impl;
  std::memset(o,0,sizeof(*o));
  o->pc=x.regs.pc; o->a=x.regs.B.a; o->x=x.regs.x; o->y=x.regs.B.y; o->sp=x.regs.sp; o->psw=(uint8)(unsigned)x.regs.p;
  o->executed_cycles=x.executed_cycles; o->instructions=x.instruction_count; o->aot_instructions=x.sc_aot_instructions;
  o->fail_pc=x.fail_pc; o->expected_opcode=x.expected_opcode; o->actual_opcode=x.actual_opcode;
  o->code_sealed=x.code_sealed; o->iplrom_enable=x.status.iplrom_enable; o->stopped=x.stopped;
  o->timer_enable_mask=(uint8)((x.timer0.enable?1:0)|(x.timer1.enable?2:0)|(x.timer2.enable?4:0)); o->dsp_addr=x.status.dsp_addr;
  o->code_write_barriers=x.code_write_barriers; o->unknown_reads=x.unknown_reads; o->dsp_writes=x.dsp_writes; o->dsp_reads=x.dsp_reads; o->high_aram_writes=x.high_aram_writes;
}

extern "C" size_t js_smp_v10_2_snapshot_size(void){return sizeof(SMPV102);}

extern "C" int js_smp_v10_2_snapshot_save(const js_smp_v10_2 *s,
                                             void *destination,
                                             size_t capacity){
  SMPV102 copy(nullptr,nullptr,nullptr,nullptr);
  if(!s||!destination||capacity<sizeof(copy)) return 0;
  std::memcpy(&copy,&s->impl,sizeof(copy));
  copy.aram=nullptr;
  copy.known=nullptr;
  copy.cpu_to_smp=nullptr;
  copy.smp_to_cpu=nullptr;
  copy.dsp_hook_opaque=nullptr;
  copy.dsp_write_hook=nullptr;
  copy.dsp_read_hook=nullptr;
  copy.dsp_cycle_hook=nullptr;
  std::memcpy(destination,&copy,sizeof(copy));
  return 1;
}

extern "C" int js_smp_v10_2_snapshot_load(js_smp_v10_2 *s,
                                             const void *source,
                                             size_t size){
  SMPV102 copy(nullptr,nullptr,nullptr,nullptr);
  uint8 *aram;
  uint8 *known;
  uint8 *cpu_to_smp;
  uint8 *smp_to_cpu;
  void *dsp_hook_opaque;
  js_smp_v10_2_dsp_write_hook dsp_write_hook;
  js_smp_v10_2_dsp_read_hook dsp_read_hook;
  js_smp_v10_2_dsp_cycle_hook dsp_cycle_hook;
  if(!s||!source||size!=sizeof(copy)) return 0;
  std::memcpy(&copy,source,sizeof(copy));
  aram=s->impl.aram;
  known=s->impl.known;
  cpu_to_smp=s->impl.cpu_to_smp;
  smp_to_cpu=s->impl.smp_to_cpu;
  dsp_hook_opaque=s->impl.dsp_hook_opaque;
  dsp_write_hook=s->impl.dsp_write_hook;
  dsp_read_hook=s->impl.dsp_read_hook;
  dsp_cycle_hook=s->impl.dsp_cycle_hook;
  std::memcpy(&s->impl,&copy,sizeof(copy));
  s->impl.aram=aram;
  s->impl.known=known;
  s->impl.cpu_to_smp=cpu_to_smp;
  s->impl.smp_to_cpu=smp_to_cpu;
  s->impl.dsp_hook_opaque=dsp_hook_opaque;
  s->impl.dsp_write_hook=dsp_write_hook;
  s->impl.dsp_read_hook=dsp_read_hook;
  s->impl.dsp_cycle_hook=dsp_cycle_hook;
  return 1;
}
