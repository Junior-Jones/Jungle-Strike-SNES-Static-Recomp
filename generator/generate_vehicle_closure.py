"""Offline immutable-USA-ROM native alternate-vehicle closure. No runtime decoder."""
from pathlib import Path
import argparse,hashlib,json,re,sys

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--reference',type=Path,required=True);ap.add_argument('--rom',type=Path,required=True);a=ap.parse_args();src=Path(__file__).resolve().parents[1]
 sys.path.insert(0,str(a.reference.resolve()))
 import analysis.scpu_extension_v10_2 as cf
 from analysis.cpu65816_spec_v02c import instruction_length
 from generator.generate_v10_46_cpu_current import emit_body
 rom=a.rom.read_bytes();digest=hashlib.sha256(rom).hexdigest();assert digest=='8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159'
 assert rom[0x2cab:0x2cba]==bytes.fromhex('BD7200AA7CB2AC8FAF55B007B191B0')
 assert rom[0x4119:0x4129]==bytes.fromhex('8624AE94087C21C129C17BC1CEC120C2')
 assert rom[0x1c58:0x1c5b]==bytes.fromhex('205FA8') and rom[0x1c6d:0x1c70]==bytes.fromhex('2019C1')
 roots=[0xB055,0xB107,0xB091,0xC17B,0xC1CE,0xC220]
 cf.ROOTS=tuple((f'vehicle_{pc:04X}',0x80,pc,'ROM-ACB2-C121-LITERAL-TABLE') for pc in roots);cf._widths=lambda e:[(0,0)] if e==0 else [(1,1)]
 p=cf.analyze(rom)
 frontiers={q['at_context'] for q in p['frontiers']};assert {q['type'] for q in p['frontiers']}=={'RETURN_UNPAIRED'}
 assert frontiers=={'80:ADD3:E0M0X0','80:C1CD:E0M0X0','80:C272:E0M0X0','80:C46B:E0M0X0','80:C478:E0M0X0','80:C5A3:E0M0X0'}
 text=(src/'generated/scpu/static_core_compact_dispatch.c').read_text().split('int js_v10_100_scpu_context_known')[0]
 packed=set(re.findall(r'0x([0-9A-F]{8})u',text));assert len(packed)==27835
 def identity(k):f=int(k[-2:],16);return f'{k[:2]}:{k[2:6]}:E{f>>2&1}M{f>>1&1}X{f&1}'
 known={identity(k) for k in packed};status=json.loads((src/'generator/status_closure_proof.json').read_bytes());known|={r['context']['id'] for r in status['rows']}
 fresh=[r for r in p['instructions'] if r['context']['id'] not in known];assert len(fresh)==186
 returns=[('80:ADD3:E0M0X0','80:9C5B:E0M0X0')]+[(q,'80:9C70:E0M0X0') for q in sorted(frontiers-{'80:ADD3:E0M0X0'})]
 fresh_ids={r['context']['id'] for r in fresh}
 paired_edges={(r['context']['id'],q['target']) for r in p['instructions'] if r['mnemonic'] in ('RTS','RTL') for q in r.get('successors',[]) if q.get('target') in fresh_ids}
 # Historic sealed helpers omitted newly lowered callers from return domains.
 # Each paired edge carries an offline literal CALLSITE proof, never a guessed target.
 paired_proofs=[q['proof_id'] for r in p['instructions'] if r['mnemonic'] in ('RTS','RTL') for q in r.get('successors',[]) if q.get('target') in fresh_ids]
 assert all(q.startswith('CALLSITE-') for q in paired_proofs)
 returns=sorted(set(returns)|paired_edges)
 for row in fresh:
  if row['context']['id']=='80:C272:E0M0X0':row['successors']=[{'kind':'return','target':'80:9C70:E0M0X0','proof_id':'ROM-9C6D-JSR-C119-C11E-TAIL'}]
 finite=sorted(known|{r['context']['id'] for r in fresh})
 def lit(s):b,pc,f=s.split(':');return f'JS_V05C_KEY_CONST(0x{b}u,0x{pc}u,{f[1]}u,{f[3]}u,{f[5]}u)'
 lines=['/* Offline immutable-ROM alternate-vehicle closure. No runtime decoding. */','#include "static_core_compact_generated.h"']
 for h in ['cpu_v08c_internal','cpu_v10_3_internal','cpu_v10_27_internal','cpu_v10_36_internal','cpu_v10_45_internal','cpu_dispatch_v10_100','status_v10_11','vehicle_closure']:lines.append(f'#include "jungle/{h}.h"')
 for i,row in enumerate(fresh):
  lines += [f"/* {row['context']['id']} {row['bytes']} {row['mnemonic']} */",f'static js_stop_reason vehicle_body_{i}(js_machine_v05c *m) {{']
  lines += ['    '+q.replace('js_v10_46_scpu_context_known','js_v10_100_scpu_context_known') for q in emit_body(row,finite)];lines.append('}')
 lines+=['int jungle_vehicle_context_known(js_static_context_key key){switch(js_v05c_pack_key(key)){']
 lines += [f"case {lit(r['context']['id'])}:return 1;" for r in fresh];lines+=['default:return 0;}}','int jungle_vehicle_dispatch(js_machine_v05c*m,js_static_context_key key,js_stop_reason*out){switch(js_v05c_pack_key(key)){']
 lines += [f"case {lit(r['context']['id'])}:*out=vehicle_body_{i}(m);return 1;" for i,r in enumerate(fresh)];lines+=['default:return 0;}}','int jungle_vehicle_return_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);']
 lines += [f'if(f=={lit(f)}&&t=={lit(t)})return 1;' for f,t in returns];lines+=['return 0;}','int jungle_vehicle_indirect_allowed(js_static_context_key from,js_static_context_key to){uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);']
 dispatch=[('80:ACAF:E0M0X0',f'80:{pc:04X}:E0M0X0') for pc in [0xB055,0xB107,0xB091]]+[('80:C11E:E0M0X0',f'80:{pc:04X}:E0M0X0') for pc in [0xC17B,0xC1CE,0xC220]]
 lines += [f'if(f=={lit(f)}&&t=={lit(t)})return 1;' for f,t in dispatch];lines+=['return 0;}']
 code=(chr(10).join(lines)+chr(10)).encode()
 (src/'runtime/vehicle_closure.c').write_bytes(code)
 offsets=set()
 for row in fresh:offsets.update(row['file_offsets'])
 original=set()
 for k in known:
  b,pc,flags=k.split(':');b=int(b,16);pc=int(pc,16)
  if pc<0x8000 or (b&127)>=64:continue
  off=(b&127)*32768+(pc&32767);n=instruction_length(rom[off],int(flags[1]),int(flags[3]),int(flags[5]));original.update(range(off,off+n))
 proof={'rom_sha256':digest,'roots':[f'80:{pc:04X}:E0M0X0' for pc in roots],'new_contexts':len(fresh),'new_unique_rom_bytes':len(offsets-original),'production_contexts':len(finite),'production_rom_bytes':status['production_rom_bytes']+len(offsets-original),'indirect_tables':{'80:ACB2':['80:AF8F','80:B055','80:B107','80:B091'],'80:C121':['80:C129','80:C17B','80:C1CE','80:C220']},'dispatch_edges':dispatch,'return_edges':returns,'paired_return_callsite_proofs':sorted(set(paired_proofs)),'return_proof':{'player':'80:9C58 JSR A85F -> ACA1/ACAF tail -> ADD3 RTS ->9C5B','weapons':'80:9C6D JSR C119 -> C11E table tail -> native RTS ->9C70'},'frontiers':p['frontiers'],'rows':fresh,'runtime_decoding':False,'native_source_sha256':hashlib.sha256(code).hexdigest()}
 (src/'generator/vehicle_closure_proof.json').write_bytes((json.dumps(proof,indent=2)+chr(10)).encode())
 print('PASS vehicle closure',len(fresh),'contexts',proof['new_unique_rom_bytes'],'newROMbytes',len(dispatch),'dispatchpairs',len(returns),'returnpairs')
if __name__=='__main__':main()
