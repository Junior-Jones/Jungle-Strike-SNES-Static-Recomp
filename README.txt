Jungle Strike (SNES) Static Recompilation - Source
Version 1.0.0

This package contains the Jungle Strike-specific static core and its native
Windows Launcher frontend. The original game ROM is not included.

Running the application
-----------------------

Place the verified Jungle Strike ROM in the Rom folder beside Launcher.exe,
then run Launcher.exe. Browse ROM can select the verified file elsewhere.
The application checks the complete ROM identity before enabling play.

Escape switches between live gameplay and the launcher without resetting the
machine. F1 opens the Welcome and shortcut guide, F2/F3 open the Save/Load
Snapshot windows, 1/2 save/load the current snapshot, F4 opens Settings, F5 opens
Controller Bindings, F6 opens Audio Settings, F7 runs the selected ROM and F8
captures a screenshot. Accepted settings and controller bindings are written
to settings.ini beside Launcher.exe whenever Apply is used and again on exit.
The file is created automatically; it is not shipped in the release archive.

What fully static recompilation means
-------------------------------------

Jungle Strike is executed through ahead-of-time native code generated from
the supported cartridge. Executable W65C816/S-CPU instructions were analysed
before the application was built and lowered into fixed C source. Production
authority contains 27,835 exact processor contexts covering 64,330 unique ROM
code bytes, plus 46,386 bytes of separately proved immutable cartridge data.

At runtime there is no general-purpose SNES CPU interpreter, opcode decoder,
JIT compiler, dynamic recompiler, runtime learning system or emulator
fallback. Dynamic control-flow sites use finite, source-proved target domains.
Interrupt, return, re-entry and executable-WRAM routes are guarded by the same
fail-closed authority. An unknown route stops and reports the exact missing
state instead of guessing or silently interpreting it.

Fully static does not mean that graphics, sound, missions or player actions
are prerecorded. The application computes every machine event, frame and
audio sample live from current state and player input. It means executable
game and audio-driver instructions are compiled ahead of time.

Compact static authority
------------------------

The 27,835 exact S-CPU contexts are stored as 219 shared semantic templates,
frozen per-context parameters and 77 address shards. This is representation
compaction only: each PBR:PC:E:M:X entry, instruction effect, resume point and
proved successor is unchanged. The generated semantic manifest reconstructs
to the same SHA-256 as the predecessor authority. Runtime code performs an
exact context lookup; it does not decode ROM opcodes, learn targets or fall
back to an emulator.

Generated S-CPU source fell from 22,264,321 to 4,285,677 bytes (80.75%). The
clean MSVC static core library fell from 9,038,916 to 2,388,546 bytes (73.57%)
and Launcher.exe from 8,224,256 to 4,864,512 bytes (40.85%). The compaction
generator and semantic manifest remain in the source package so the compact
production representation stays inspectable without adding release files.

Static machine coverage
-----------------------

The production core includes:

- Ahead-of-time W65C816/S-CPU game-code execution.
- LoROM mapping, 128 KiB WRAM, open-bus behavior and cartridge/machine bus.
- SNES CPU I/O, timers, NMI, IRQ, auto-joypad and controller serial ports.
- Native DMA and HDMA with scanline scheduling.
- NTSC master-clock, scanline, H-clock, refresh and frame scheduling.
- Native PPU register state, VRAM, CGRAM, OAM, backgrounds, objects, Mode 1,
  Mode 7, windows, color math, forced blank and completed framebuffers.
- Exact-PC ahead-of-time SPC700/S-SMP audio-driver execution.
- Exact 32-phase S-DSP execution and deterministic stereo PCM.
- Opaque lifecycle API for ROM inspection, power-on/reset, headed or headless
  natural frames, input, framebuffer, PCM, status and failure evidence.
- Complete same-build snapshot state for S-CPU, scheduler, DMA, PPU, input,
  S-SMP, S-DSP, ARAM and rendered output. Host pointers and callbacks are
  excluded from the payload and rebound on load; payloads are versioned and
  integrity checked.
- Deterministic JSON diagnostics containing CPU, SMP, DSP, scheduler, PPU,
  input and state hashes.

Static audio core
-----------------

Audio is fully produced inside the static core. The game's own SPC700 program
is ahead-of-time compiled and runs against project-owned 64 KiB audio RAM,
timers, CPU/APU ports and DSP registers. There is no SPC700 interpreter and no
Snes9x, Mesen or other emulator audio library linked into the application.

The S-DSP implementation advances its authentic 32 internal phases and eight
voices. It implements source-directory reads, BRR block decode and filters,
Gaussian interpolation, pitch and pitch modulation, ADSR and GAIN envelopes,
key-on/key-off timing, noise generation, per-voice and master volume, ENDX,
echo address/length handling, the eight-tap FIR echo path, echo feedback,
echo writes, clamping and mute/reset behavior. The scheduler derives DSP work
from the SNES NTSC master clock and produces native 32,040 Hz signed 16-bit
stereo PCM.

PCM carries knownness metadata. If a sample depends on hardware-indeterminate
cold audio RAM, that fact remains explicit in diagnostics rather than being
invented. The verified cold start contains one bounded 39-frame echo-knownness
interval; it does not grow during gameplay. Any executable audio route or
required data dependency outside the compiled authority stops fail-closed.

The Windows frontend drains completed DSP batches during each emulated frame,
queues them in a bounded FIFO, and sends them to a DirectSound circular buffer.
Speaker output is resampled from native 32,040 Hz to the selected device rate
with Hermite interpolation by default. Real play-cursor queue measurement,
bounded drift correction, underrun recovery and optional latency controls keep
the host device synchronized without changing machine-time ownership. See
VERSION.txt for every user-facing audio option.

How Mesen was used
------------------

Mesen/MesenCE was used as an independent development oracle and comparison
tool. Its headless SNES output helped compare cartridge boot routes,
framebuffers, input timing, PCM captures, device-queue behavior and expected
SNES timing at selected checkpoints. It was also consulted as mature reference
source when repairing frontend pacing and audio delivery.

Mesen is not included, linked or called by the release. It never executes a
production frame and it does not provide a fallback core. Static authority was
established from the supported ROM and finite source analysis; Mesen results
were used to corroborate behavior and find disagreements that then had to be
repaired in the Jungle Strike core itself.

ROM requirements
----------------

Title: Jungle Strike
Region: USA/Canada NTSC
Format: unheadered .sfc
Size: 2,097,152 bytes
SHA-256: 8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159

Place the legally obtained ROM in the Rom folder beside Launcher.exe, or use
Browse ROM. The filename may be different; size, mapping metadata and SHA-256
must match. The ROM is never included in source or release archives.

Windows build
-------------

Requirements:

- CMake 3.20 or newer
- Visual Studio 2022 with the x64 C/C++ toolchain
- Internet access during first configuration so CMake can obtain SDL 3.4.10

From the source root:

  cmake -S frontend\windows -B build -G "Visual Studio 17 2022" -A x64
  cmake --build build --config Release --target jungle-strike-launcher

The resulting application is build\release\Launcher.exe. Release builds use
the static Visual C++ runtime and statically link SDL3 gamepad support. Video
and dialogs use Win32/GDI; speaker output uses DirectSound.

Verification
------------

The production test targets cover core reset, input latching, settings and
gamepad contracts, audio resampling, audio settings and byte-identical snapshot
continuation. The frontend-core test can also load an externally supplied
same-build snapshot and advance it through the streamed-audio path.

Version 1.0.0 was exercised through every campaign password. Missions 1-9
were each accepted and reached live gameplay. The completed runs reported no
S-CPU machine stop, renderer stop, failure evidence or PPU renderer-domain
violation.

Frontend and release behavior
-----------------------------

See VERSION.txt for launcher controls, five snapshot slots, settings,
full-screen screenshot behavior, NTSC frame lock, FPS display, gamepad
support, DirectSound output, live audio diagnostics and failure-log behavior.

Package contents
----------------

The Windows release contains Launcher.exe, README.txt, VERSION.txt,
THIRD-PARTY-NOTICES.txt, SDL-LICENSE.txt and SNES9X-LICENSE.txt at its root,
plus Rom and Screenshots folders with their short instruction files.
The archive does not contain the game ROM, settings.ini, snapshots, captured
screenshots, logs, development monitors, test evidence or a separate
controller-mapping database.

Rom and Screenshots are the only clean-package subfolders. Saves and Logs are
created beside Launcher.exe only when the application is about to write the
first corresponding file. Opening or viewing a feature does not create an
empty folder.

SDL3 supplies statically linked gamepad support. Mesen/MesenCE and Snes9x were
consulted as open-source development references; neither emulator is included,
linked, called at runtime or used as a fallback. Jungle Strike, its ROM and
original assets are not distributed.
