"""Offline Status-screen closure lowering using the historic SNES analysis tools.

Builds use the checked-in native C and need no analysis reference or game ROM.
For regeneration, supply --reference pointing at the full historic Jungle
Strike analysis/generator source and --rom pointing at the verified USA ROM.
"""
from pathlib import Path
import argparse, hashlib, json, re, sys

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--reference',type=Path,required=True)
    ap.add_argument('--rom',type=Path,required=True)
    args=ap.parse_args()
    src=Path(__file__).resolve().parents[1]
    sys.path.insert(0,str(args.reference.resolve()))
    import analysis.scpu_extension_v10_2 as cf
    from analysis.cpu65816_spec_v02c import instruction_length
    from generator.generate_v10_46_cpu_current import emit_body
    rom=args.rom.read_bytes()
    digest=hashlib.sha256(rom).hexdigest()
    assert digest=='8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159'
    producers={0xA011:bytes.fromhex('A952848D200D850B'),0xA0AC:bytes.fromhex('A952848D200D850B'),0x84C7:bytes.fromhex('A9CF84850B'),0x9FFD:bytes.fromhex('A987838D200D850B'),0xA0EB:bytes.fromhex('A987838D200D850B'),0x83F3:bytes.fromhex('A9FB83850B')}
    for pc,data in producers.items():assert rom[0x100000+pc-0x8000:0x100000+pc-0x8000+len(data)]==data
    assert rom[0x53fa:0x53fd]==bytes.fromhex('2032BB')
    assert rom[0x3b3d:0x3b41]==bytes.fromhex('61BB82BC')
    assert rom[0x3d00:0x3d02]==bytes.fromhex('7A60')
    cf.ROOTS=(("status_console",0xA0,0x8452,"ROM-STATUS-CONSOLE"),("status_poll",0xA0,0x84CF,"ROM-STATUS-STATE-A084C7"),("mission_console",0xA0,0x8387,"ROM-MISSION-CONSOLE"),("mission_poll",0xA0,0x83FB,"ROM-MISSION-STATE-A083F3"),("damage_return",0x80,0xD3FD,"ROM-JSR-80D3FA-BB32"),("collision_return",0x80,0xD47B,"ROM-JSR-80D478-BB32"))
    damage_targets=tuple(int.from_bytes(rom[at:at+2],'little') for at in range(0x5ada,0x5afa,2))
    assert damage_targets==(0xdafc,0xdb01,0xdb12,0xdb29,0xdb40,0xdb5b,0xdb79,0xdb88,0xdb9c,0xdbb5,0xdafc,0xdafc,0xdafc,0xdafc,0xdafc,0xdafc)
    assert rom[0x5ace:0x5ada]==bytes.fromhex('B90000290F00DA0AAA7CDADA')
    callers=(0x8827,0x8832,0x883d,0x8848)
    for pc in callers:assert rom[pc-0x8000:pc-0x8000+3]==bytes.fromhex('20C4DA')
    cf.ROOTS+=tuple((f'damage_{pc:04X}',0x80,pc,'ROM-DAD7-16-WORD-TABLE') for pc in sorted(set(damage_targets)))
    entity_targets=tuple(int.from_bytes(rom[at:at+2],'little') for at in range(0x3b3d,0x3b5d,2))
    assert entity_targets==(0xbb61,0xbc82,0xbca0,0xbcbe,0xbd02,0xbbe6,0xbbaa,0xbd97,0xb92e,0xb947,0xbc61,0xbc26,0xbb5f,0xbb5f,0xbb5f,0xbb5f)
    entity_roots=tuple((f'entity_{pc:04X}',0x80,pc,'ROM-BB32-TAIL-DISPATCH') for pc in sorted(set(entity_targets)))
    all_roots=cf.ROOTS+entity_roots
    cf._widths=lambda e:[(0,0)] if e==0 else [(1,1)]
    cf.ROOTS=entity_roots
    entity_analysis=cf.analyze(rom)
    entity_returns={r['at_context'] for r in entity_analysis['frontiers'] if r['type']=='RETURN_UNPAIRED'}
    assert entity_returns=={'80:B996:E0M0X0','80:BB60:E0M0X0','80:BBA9:E0M0X0','80:BBBB:E0M0X0','80:BBF7:E0M0X0','80:BC37:E0M0X0','80:BD01:E0M0X0','80:BD96:E0M0X0','80:BE01:E0M0X0'}
    cf.ROOTS=all_roots
    p=cf.analyze(rom)
    for row in p['instructions']:
        if row['context']['id']=='80:DB11:E0M0X0':
            row['successors']=[{'kind':'return','target':f'80:{pc+3:04X}:E0M0X0','proof_id':f'ROM-JSR-80{pc:04X}-DAC4'} for pc in callers]
    assert {r['at_context'] for r in p['frontiers']}=={'A0:95EA:E0M0X0','A0:B8C6:E0M0X0','80:D40F:E0M0X0','80:DAD7:E0M0X0','80:DB00:E0M0X0','80:DB11:E0M0X0','80:D484:E0M0X0'}|entity_returns
    text=(src/'generated/scpu/static_core_compact_dispatch.c').read_text().split('int js_v10_100_scpu_context_known')[0]
    knownhex=set(re.findall(r'0x([0-9A-F]{8})u',text));assert len(knownhex)==27835
    def identity(k):return f'{k[:2]}:{k[2:6]}:E{(int(k[-2:],16)>>2)&1}M{(int(k[-2:],16)>>1)&1}X{int(k[-2:],16)&1}'
    known={identity(k) for k in knownhex}
    bb32_calls=tuple(sorted(int(k[2:6],16) for k in knownhex if k[:2]=='80' and k[-2:]=='00' and rom[int(k[2:6],16)-0x8000:int(k[2:6],16)-0x8000+3]==bytes.fromhex('2032BB')))
    assert bb32_calls==(0xA312,0xA74F,0xBB2E,0xD3FA,0xD478)
    ca82_calls=tuple(sorted(int(k[2:6],16) for k in knownhex if k[:2]=='80' and k[-2:]=='00' and rom[int(k[2:6],16)-0x8000:int(k[2:6],16)-0x8000+3]==bytes.fromhex('2082CA')))
    assert len(ca82_calls)==30
    # D410 is called by the D25E collision loop. On a hit, D44D PLA
    # discards that local JSR return before BB32, so D484 returns through
    # the outer CA82 tail-dispatch frame, just like the D3E1/D40F path.
    assert rom[0x3B2B:0x3B2E]==bytes.fromhex('4C5ED2')
    assert rom[0x4116:0x4119]==bytes.fromhex('4C5ED2')
    assert rom[0x544D]==0x68 and rom[0x5478:0x547B]==bytes.fromhex('2032BB')
    collision_calls=tuple(sorted(int(k[2:6],16) for k in knownhex if k[:2]=='80' and k[-2:]=='00' and rom[int(k[2:6],16)-0x8000:int(k[2:6],16)-0x8000+3]==bytes.fromhex('2010D4')))
    assert collision_calls==tuple(range(0xD315,0xD376,8))
    for row in p['instructions']:
        if row['context']['id']=='80:D484:E0M0X0':
            row['successors']=[{'kind':'return','target':f'80:{pc+3:04X}:E0M0X0','proof_id':f'ROM-CA82-TAIL-80{pc:04X}-D44D-PLA'} for pc in ca82_calls]
    fresh=[r for r in p['instructions'] if r['context']['id'] not in known]
    assert len(fresh)==801
    original=set()
    for s in knownhex:
        bank=int(s[:2],16);pc=int(s[2:6],16);mode=int(s[6:],16)
        if pc<0x8000 or (bank&0x7f)>=0x40:continue
        off=(bank&0x7f)*0x8000+(pc&0x7fff)
        original.update(range(off,off+instruction_length(rom[off],(mode>>2)&1,(mode>>1)&1,mode&1)))
    offsets={x for r in fresh for x in r['file_offsets']}
    assert len(offsets-original)==1847 and not offsets&original
    finite=sorted(known|{r['context']['id'] for r in fresh})
    def lit(s):
        bank,pc,flags=s.split(':')
        return f'JS_V05C_KEY_CONST(0x{bank}u,0x{pc}u,{flags[1]}u,{flags[3]}u,{flags[5]}u)'
    ids={r['context']['id'] for r in fresh}
    edges=sorted({(r['context']['id'],s['target']) for r in p['instructions'] if r['mnemonic'] in ('RTS','RTL') for s in r.get('successors',[]) if s.get('target') in ids})
    edges=sorted(set(edges)|{('80:BD01:E0M0X0','80:D3FD:E0M0X0')})
    edges=sorted(set(edges)|{('80:DB11:E0M0X0',f'80:{pc+3:04X}:E0M0X0') for pc in callers})
    edges=sorted(set(edges)|{(source,f'80:{pc+3:04X}:E0M0X0') for source in entity_returns for pc in bb32_calls})
    edges=sorted(set(edges)|{('80:D484:E0M0X0',f'80:{pc+3:04X}:E0M0X0') for pc in ca82_calls})
    lines=['/* Offline immutable-ROM Status-screen closure; no runtime decoding. */','#include "static_core_compact_generated.h"']
    for h in ['cpu_v08c_internal','cpu_v10_3_internal','cpu_v10_27_internal','cpu_v10_36_internal','cpu_v10_45_internal','cpu_dispatch_v10_100','status_v10_11','status_closure']:
        lines.append(f'#include "jungle/{h}.h"')
    for i,r in enumerate(fresh):
        lines.extend([f"/* {r['context']['id']} {r['bytes']} {r['mnemonic']} */",f'static js_stop_reason status_body_{i}(js_machine_v05c *m) {{'])
        lines.extend('    '+s.replace('js_v10_46_scpu_context_known','js_v10_100_scpu_context_known') for s in emit_body(r,finite))
        lines.append('}')
    lines.extend(['int jungle_status_context_known(js_static_context_key key) {','switch(js_v05c_pack_key(key)) {'])
    lines.extend(f"case {lit(r['context']['id'])}:return 1;" for r in fresh)
    lines.extend(['default:return 0;}}','int jungle_status_dispatch(js_machine_v05c *m,js_static_context_key key,js_stop_reason *out) {','switch(js_v05c_pack_key(key)) {'])
    lines.extend(f"case {lit(r['context']['id'])}:*out=status_body_{i}(m);return 1;" for i,r in enumerate(fresh))
    lines.extend(['default:return 0;}}','int jungle_status_return_allowed(js_static_context_key from,js_static_context_key to) {','uint32_t f=js_v05c_pack_key(from),t=js_v05c_pack_key(to);'])
    lines.extend(f'if(f=={lit(a)}&&t=={lit(b)})return 1;' for a,b in edges)
    lines.extend(['return 0;}'])
    lines.extend(['int jungle_damage_dispatch_allowed(js_static_context_key from,js_static_context_key to) {',
                  f'if(js_v05c_pack_key(from)!={lit("80:DAD7:E0M0X0")})return 0;',
                  'switch(js_v05c_pack_key(to)){'])
    lines.extend(f'case {lit(f"80:{pc:04X}:E0M0X0")}:return 1;' for pc in sorted(set(damage_targets)))
    lines.extend(['default:return 0;}}'])
    code=('\n'.join(lines)+'\n').encode()
    (src/'runtime/status_closure.c').write_bytes(code)
    proof={'rom_sha256':digest,'roots':['A0:8452:E0M0X0','A0:84CF:E0M0X0','A0:8387:E0M0X0','A0:83FB:E0M0X0','80:D3FD:E0M0X0','80:D47B:E0M0X0'],'damage_return_proof':{'call':'80:D3FA JSR BB32','table':'80:BB3D = BB61,BC82','return':'80:BD00 PLY; 80:BD01 RTS -> 80:D3FD'},'entity_return_proof':{'entry':'80:BB32','table':'80:BB3D-BB5C','targets':entity_targets,'root_returns':sorted(entity_returns),'compiled_JSR_BB32_callers':bb32_calls,'collision_loop_JSR_D410_callers':collision_calls,'outer_JSR_CA82_callers':ca82_calls,'collision_return':'80:D44D PLA discards local D410 call return; D484 returns through outer CA82 tail-dispatch frame'},'damage_dispatch_proof':{'source':'80:DAD7:E0M0X0','mask':15,'table':'80:DADA-DAF9','targets':damage_targets,'DAC4_callers':callers},'state_producers':{f'A0:{pc:04X}':data.hex().upper() for pc,data in producers.items()},'new_contexts':801,'new_unique_rom_bytes':1847,'production_contexts':28636,'production_rom_bytes':66177,'return_edges':edges,'rows':fresh,'analysis_summary':p['summary'],'frontiers':p['frontiers'],'runtime_decoding':False,'native_source_sha256':hashlib.sha256(code).hexdigest()}
    (src/'generator/status_closure_proof.json').write_text(json.dumps(proof,indent=2)+'\n')
    print(f'PASS: 801 native contexts, 1847 new ROM code bytes, {len(edges)} frozen return edges')

if __name__=='__main__':main()
