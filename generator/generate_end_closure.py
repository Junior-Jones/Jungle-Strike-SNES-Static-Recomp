"""Offline immutable-ROM mission-result return closure. No runtime decoding."""
from pathlib import Path
import argparse,hashlib,json,re,sys

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--reference',type=Path,required=True);ap.add_argument('--rom',type=Path,required=True);a=ap.parse_args();src=Path(__file__).resolve().parents[1]
 sys.path.insert(0,str(a.reference.resolve()))
 import analysis.scpu_extension_v10_2 as cf
 from analysis.cpu65816_spec_v02c import instruction_length
 from generator.generate_v10_46_cpu_current import emit_body
 rom=a.rom.read_bytes();digest=hashlib.sha256(rom).hexdigest();assert digest=='8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159'
 assert rom[0x934:0x93c]==bytes.fromhex('220080A02214C381')
 cf.ROOTS=(('failure_return',0x80,0x8938,'ROM-8934-JSL-A08000-RETURN'),);cf._widths=lambda e:[(0,0)] if e==0 else [(1,1)]
 p=cf.analyze(rom)
 assert [(q['type'],q['at_context']) for q in p['frontiers']]==[('DYNAMIC_JUMP_UNPROVED','80:952E:E0M0X0')]
 text=(src/'generated/scpu/static_core_compact_dispatch.c').read_text().split('int js_v10_100_scpu_context_known')[0]
 keys=set(re.findall(r'0x([0-9A-F]{8})u',text));assert len(keys)==27835
 known={f'{k[:2]}:{k[2:6]}:E{int(k[-2:],16)>>2&1}M{int(k[-2:],16)>>1&1}X{int(k[-2:],16)&1}' for k in keys}
 for name in ['status','vehicle']:
  proof=json.loads((src/f'generator/{name}_closure_proof.json').read_bytes());known|={q['context']['id'] for q in proof['rows']}
 vehicle=proof
 fresh=[q for q in p['instructions'] if q['context']['id'] not in known];assert len(fresh)==11
 assert [q['context']['id'] for q in fresh]==[f'80:{pc:04X}:E0M0X0' for pc in [0x8938,0x893c,0x893f,0x8942,0x8946,0x894a,0x894e,0x8952,0x8956,0x895a,0x895e]]
 ids={q['context']['id'] for q in fresh};finite=sorted(known|ids)
 returns=[(q['context']['id'],e['target']) for q in p['instructions'] if q['mnemonic'] in ['RTS','RTL'] for e in q.get('successors',[]) if e.get('target') in ids]
 assert returns==[('81:C336:E0M0X0','80:893C:E0M0X0'),('81:C727:E0M0X0','80:8946:E0M0X0')]
 returns.append(('A0:81F8:E0M0X0','80:8938:E0M0X0'))
 def offset(bank,pc):return (bank&127)*32768+(pc&32767)
 for bank,pc in [(0x81,0xc336),(0x81,0xc727),(0xa0,0x81f8)]:assert rom[offset(bank,pc)]==0x6b
 def lit(s):b,pc,f=s.split(':');return f'JS_V05C_KEY_CONST(0x{b}u,0x{pc}u,{f[1]}u,{f[3]}u,{f[5]}u)'
 lines=['/* Offline immutable-ROM mission-result return closure. */','#include "static_core_compact_generated.h"']
 for h in ['cpu_v08c_internal','cpu_v10_3_internal','cpu_v10_27_internal','cpu_v10_36_internal','cpu_v10_45_internal','cpu_dispatch_v10_100','status_v10_11','end_closure']:lines.append(f'#include "jungle/{h}.h"')
 for i,row in enumerate(fresh):
  lines += [f"/* {row['context']['id']} {row['bytes']} {row['mnemonic']} */",f'static js_stop_reason end_body_{i}(js_machine_v05c *m) {{']
  lines += ['    '+q.replace('js_v10_46_scpu_context_known','js_v10_100_scpu_context_known') for q in emit_body(row,finite)];lines.append('}')
 lines+=['int jungle_end_context_known(js_static_context_key key){switch(js_v05c_pack_key(key)){']
 lines += [f"case {lit(q['context']['id'])}:return 1;" for q in fresh];lines+=['default:return 0;}}','int jungle_end_dispatch(js_machine_v05c*m,js_static_context_key key,js_stop_reason*out){switch(js_v05c_pack_key(key)){']
 lines += [f"case {lit(q['context']['id'])}:*out=end_body_{i}(m);return 1;" for i,q in enumerate(fresh)];lines+=['default:return 0;}}','int jungle_end_return_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);']
 lines += [f'if(f=={lit(f)}&&t=={lit(t)})return 1;' for f,t in returns];lines+=['return 0;}']
 code=('\n'.join(lines)+'\n').encode();(src/'runtime/end_closure.c').write_bytes(code)
 offsets={o for q in fresh for o in q['file_offsets']};original=set()
 for k in known:
  b,pc,flags=k.split(':');b=int(b,16);pc=int(pc,16)
  if pc<0x8000 or (b&127)>=64:continue
  off=offset(b,pc);n=instruction_length(rom[off],int(flags[1]),int(flags[3]),int(flags[5]));original.update(range(off,off+n))
 proof={'rom_sha256':digest,'root':'80:8938:E0M0X0','root_proof':'80:8934 JSL A0:8000 -> A0:81F8 RTL ->80:8938','new_contexts':len(fresh),'new_unique_rom_bytes':len(offsets-original),'production_contexts':len(finite),'production_rom_bytes':vehicle['production_rom_bytes']+len(offsets-original),'return_edges':returns,'frontiers':p['frontiers'],'rows':fresh,'runtime_decoding':False,'native_source_sha256':hashlib.sha256(code).hexdigest()}
 (src/'generator/end_closure_proof.json').write_bytes((json.dumps(proof,indent=2)+'\n').encode());print('PASS end closure',len(fresh),'contexts',proof['new_unique_rom_bytes'],'ROMbytes',len(returns),'returns')
if __name__=='__main__':main()
