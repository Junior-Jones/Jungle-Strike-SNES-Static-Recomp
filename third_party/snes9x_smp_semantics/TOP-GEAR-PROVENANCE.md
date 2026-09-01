# Top Gear static S-SMP/S-DSP AOT provenance

Version 27 uses the same fail-closed AOT transformation pattern proven by the
SimCity static-recomp project. The underlying SPC700/S-DSP semantic sources in
this directory retain their original Snes9x / snes_spc licenses, but the normal
Top Gear build compiles them only with `SC_SMP_AOT`: the generic SPC700 opcode
switch is excluded and execution is restricted to the generated Top Gear exact
PC/opcode authority in `smp/sc_smp_aot_lookup.inc` and the finite used-opcode
dispatch in `smp/sc_smp_aot_dispatch.inc`.

The authority is generated offline from Top Gear's exact ROM-derived APU upload
and development-oracle PC/opcode coverage. Unknown PCs, opcode mismatches,
unemitted opcodes, and writes to statically owned driver code fail closed. There
is no automatic fallback to the historical hybrid backend. The S-DSP portion is
a hardware model, not guest-code interpretation; its 32-phase signal path emits
BRR/envelope/noise/echo PCM from the Top Gear ARAM/DSP state.

The historical hybrid backend remains a development comparison/oracle only and
is excluded from the default Version 27 production link.
