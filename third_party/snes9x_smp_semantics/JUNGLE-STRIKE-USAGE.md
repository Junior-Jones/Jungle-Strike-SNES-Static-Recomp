# Jungle Strike 1.0.0 S-SMP semantic-source provenance

The five `oppseudo_*.cpp` case libraries and `algorithms.cpp` in this directory
were carried from the user-supplied completed Top Gear static core.  That core
identifies these S-SMP semantic routines as derived from Snes9x/byuu S-SMP
sources; the complete Snes9x license and copyright notice is preserved in the
release and source `README.txt`.

Jungle Strike does **not** compile these complete 256-opcode case libraries into
production. They were used offline to emit only the finite opcode forms required
by Jungle Strike's exact statically discovered S-SMP PC authority. Production
execution is additionally guarded by an exact PC/opcode lookup and executable-
ARAM ownership bitmap. Unknown PCs, opcode mismatches and writes to owned code
fail closed; there is no generic SPC700 runtime decoder or fallback interpreter.
