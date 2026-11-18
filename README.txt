Jungle Strike (SNES) Static Recompilation - Source
Version 1.2.1

This package contains the Jungle Strike-specific static core and its native
Windows Launcher frontend. The original game ROM is not included.

Window drawing update
---------------------

Version 1.2.1 composes Windows repaint operations in a reusable off-screen
buffer, then copies the completed image to the window. This removes the
intermediate black clear that can contribute to redraw flashes. The buffer
is replaced safely on resize and released when the window closes. Controls,
gameplay timing and the normal/widescreen image remain unchanged.

RecompLauncher and command-line use
---------------------------------

Get it on RecompLauncher:
https://recomplauncher.com/game/jungle-strike-snes-static-recomp

The included recomplauncher.json goes beside Launcher.exe. It describes the
supported ROM, existing fullscreen/widescreen/60 FPS/input-source settings,
Saves backups and Logs. The launcher writes only the declared INI keys.

Direct launch (also suitable for Steam shortcuts):
  Launcher.exe --game "Rom\Jungle Strike.sfc" --port-widescreen --60fps

--game accepts a quoted ROM path, or --game=PATH. It skips the Welcome/Run
steps for that launch and still verifies the complete supported ROM identity.
Relative paths are resolved before the app changes its working directory.
--port-widescreen / --no-port-widescreen select wide/original presentation;
--port-wide-canvas is an alias for widescreen. --60fps / --no-60fps and
--fullscreen / --windowed override those saved options. Arguments can be
combined or reordered; the last selection wins. Values use the normal saved
settings behavior. Opening without arguments retains the existing frontend.
Invalid options exit2; invalid ROMs exit3; loader failures exit4; direct-launch
static-core failures exit5. Failures do not block on a dialog in direct mode;
runtime diagnostics use .log files in Logs. No new frontend controls are added.

Input verification for1.2.1 includes all nine mission starts, 36 paired
movement/turning/firing routes in4:3/16:9 with60 FPS off/on, and complete
state/pixel comparisons. All12 keyboard and12 default SDL virtual-pad actions
pass per mission. All20 supported controller controls and hot-plug/reconnect
were checked. No physical controller was detected, so hardware-specific
compatibility is not claimed. Default keyboard Start/Select are G/T.

Running the application
-----------------------

Place the verified Jungle Strike ROM in the Rom folder beside Launcher.exe,
then run Launcher.exe. Browse ROM can select the verified file elsewhere.
The application checks the complete ROM identity before enabling play.

Escape switches between live gameplay and the launcher without resetting the
machine. 1/2 save/load the current snapshot. F1 opens the Welcome and shortcut
guide, F2/F3 open the Save/Load Snapshot windows, F4 opens Settings, F5 opens
Controller Bindings, F6 opens Audio Settings, F7 runs the selected ROM and F8
captures a screenshot. Accepted settings and controller bindings are written
to settings.ini beside Launcher.exe whenever Apply is used and again on exit.
The file is created automatically; it is not shipped in the release archive.

Experimental 60 FPS - normal and widescreen
-------------------------------------------

Select 60 FPS using the toolbar checkbox or Settings > 60 FPS before loading
the ROM. Both controls share one saved setting and are disabled while a ROM
is loaded. The one-time experimental Notice is remembered in settings.ini.
The same conversion runs in normal 4:3 and 16:9 Widescreen, in a window or
full screen. Changing display size does not change simulation speed.

Changes made for this mode:

- Projectile contact checks previously sampled on alternate fields now run
  on every eligible field. Static-object contact checks previously sampled
  one field in four also run every eligible field. Target ordering, projectile
  consumption and damage per hit remain native. More frequent checks can catch
  a hit that originally passed between checks, so outcomes can differ.
- A redundant wait after a completed gameplay publication was removed only
  when the native ready bit had already cleared. Movement is not run twice.
- Busy combat now gives verified pure contact-geometry and classification
  work a smaller software instruction budget. A building-destruction case
  that previously missed publication deadlines now publishes each field in
  both display modes. Damage, spawning, timers and hardware waits retain
  their native owners; this does not increase weapon firing rates.
- Select presses are accepted every field instead of only one phase in four.
  Original resource capture, panel entry, fades and return still run.
- Map processing increased from about 30 to 60 updates per second. Pure marker,
  text and OAM-buffer construction was given a smaller instruction budget so
  the next upload reaches its native blanking deadline. Marker animation
  counters and persistent marker records retain their original timing.
- Mission information processing now batches compatible graphics transfers
  during native blanking, with ROM-checked decompression and tile conversion.
  Aligned remaining tiles are handled after a busy-hardware fallback too.
  Page clears and pure text/number construction avoid repeated blocked fields.
  Authored diagram cycles retain their timing; required initial asset-loading
  and hardware-transfer fields are retained.
- Options, password editing and copilot selection process input/redraw work
  each field. Password-error duration, portrait transfers and scripted holds
  are preserved. The main menu already processed input at the native field
  rate and was not accelerated.
- Game Over graphics use coherent transfer batches while keeping the original
  fire-animation and fade durations. Report return paths remain native.
- Water colours gain intermediate RGB values each field rather than changing
  only at the original eight-field palette steps. The complete colour cycle
  retains its original duration. Light/fire palette effects also gain
  intermediate updates without shortening their cycle.
- Native and widescreen rendering use guarded row/tile/colour caches and
  off-screen sprite rejection to reduce host work. Unknown-memory/error
  behavior and final pixel selection are preserved.

Original aircraft, NPC and projectile movement already integrated once per
native NTSC field, about 60.10 times per second. Those movements were retained,
not doubled. Fuel charging still uses its original 256-field clock (where the
vehicle uses that clock); firing intervals, damage amounts and audio clocks
are not multiplied. Both display modes share these rules.

Additional fixes cover cartridge-proven alternate-vehicle, destruction-queue
and report-return paths. Widescreen saves now retain sprite-wrap history,
partial/completed images and latched water colours. Earlier V1/V2 saves still
load; no runtime interpreter, learning or fallback was added.

In-game controls and timing
--------------------------

SNES Select opens the Map/Mission/Status panel; Select closes it. SNES Start
pauses and another Start press resumes. Your keyboard/gamepad bindings may
map those buttons to different physical keys. Panel/pause checks confirm
movement and fuel stay frozen there, then normal field-rate gameplay resumes
once the game's original exit fade and restoration have completed.

Screenshot diagnostics
----------------------

F8 or File > Screenshot saves an image and a matching .json report in the
Screenshots folder beside Launcher.exe. Both files share the same name.
There is no additional control or setting. Screenshots taken with an external
Windows capture tool do not automatically receive this report.

The report links the actual image dimensions and file hash to the version,
display/60 FPS settings, completed display-frame number and current CPU frame,
scanline and master clock. The distinction matters: the CPU can already be
partway into the next raster while the image is the last completed display.
It also records mission, raw screen/pause state, aircraft position/heading,
camera, available armor/fuel/ammunition values, input, pending panel transfers,
CPU/PPU/audio diagnostics and memory hashes. Raw RAM values include validity
flags and are not guesses about the picture.

An in-memory history retains the last 120 advanced frames, including inputs,
positions/resources, measured host work time and pacing counters. It is written
only when capturing; paused capture does not advance the game. The history
clears on ROM replacement, reset and successful snapshot load. If logging
fails after an image is saved, the launcher reports that the image exists but
its diagnostic report failed. Older screenshots cannot gain past runtime logs
retroactively. Keep each image and its matching report together for review.

Widescreen
----------

The Widescreen toolbar checkbox and Settings > Widescreen menu item switch
live gameplay to 512 x 288 (16:9): 128 extra world pixels on the left/right and 32
above/below. The setting is saved beside Launcher.exe. No other frontend
widescreen controls are added. Screenshot export and scaling use both actual dimensions.
The first click on either Widescreen control shows a small experimental-feature
Notice. Its one-time flag is saved in settings.ini beside Launcher.exe.

Terrain and scenery come from live camera state, cartridge map data and
scenery records. Sprite coordinates are tracked across their horizontal and
vertical wraps; unused ($E0,$E0) OAM entries are excluded from the expanded
world. With 60 FPS disabled, original movement, weapons, collision, spawning and
range remain intact. The optional 60 FPS contact changes are described above.
At map edges, the expanded viewport shifts toward valid terrain while keeping
the complete native world view. This avoids exposing unused map-border tiles.

The bottom gameplay message layer is anchored to the new bottom edge. Its
visible pixels move from original rows 208..219 to expanded rows 272..283;
world scenery fills the vacated area, both sides of the messages and the
bottom four rows. In wide mode, the Map/Mission/Status console fills the
512 x 288 canvas with its original text, digits, map and markers at native
pixel size. Statistics sit on the far right and navigation along the bottom.
Normal mode retains the original console and 4:3 presentation.

Original snapshots remain compatible. Widescreen remains a host display
choice when loading a snapshot or resetting. Paused snapshot loads and display
toggles rebuild the widescreen presentation immediately without advancing the
game. New snapshots also retain exact widescreen history and palette state. Firing tests also exposed an
omitted static return domain: the cartridge-proven entity-dispatcher returns
through $80:D40F now accept their 30 frozen, compiled caller continuations.
All other return contexts still fail closed; no runtime decoding or learning
has been introduced.

The information console's Mission and Status screens and their polling states are
also compiled. Their omitted ROM routines previously stopped both display
modes. An additive source-proven closure supplies 801 native instruction
contexts, including ROM-proven damage dispatch and entity returns discovered
while testing corners. Its 168 frozen return edges admit no unknown target.

What fully static recompilation means
-------------------------------------

Jungle Strike is executed through ahead-of-time native code generated from
the supported cartridge. Executable W65C816/S-CPU instructions were analysed
before the application was built and lowered into fixed C source. Production
authority contains 28,636 exact processor contexts covering 66,177 unique ROM
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

The original 27,835 exact S-CPU contexts are stored as 219 shared semantic templates,
frozen per-context parameters and 77 address shards. This is representation
compaction only: each PBR:PC:E:M:X entry, instruction effect, resume point and
proved successor is unchanged. The generated semantic manifest reconstructs
to the same SHA-256 as the predecessor authority. Runtime code performs an
exact context lookup; it does not decode ROM opcodes, learn targets or fall
back to an emulator.

The console repair adds 679 exact contexts covering 1,584 additional ROM
code bytes in runtime/status_closure.c. Its offline source proof and regeneration
script are in generator. Regeneration requires the historic analysis reference;
normal builds use the included native C and need neither that reference nor ROM.

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

Bounded local 60 FPS checks cover all nine mission starts, four vehicles,
movement and individual weapon inputs, contacts, resupply, death/respawn and
normal/wide presentation. Repeated and partial-frame saves compare complete
state, actual composed pixels and stereo PCM; older V1/V2 files still load.
Map/Mission/Status, Options, Password and Copilot have separate timing and
panel checks. Main-menu input already processes every native field. Authored
animation holds and necessary hardware transfer deadlines retain their timing.
These are focused conversion regressions, not a claim of campaign completion.
Additional genuine gameplay checks cover building destruction, bike ramming,
rescue/full cargo/drop-off, Quick Winch, armor and extra-life pickups, slow
ground collection versus hard item destruction, F117 boarding/takeoff/return
landing, hovering mines, bombs and destruction/recovery of all four vehicles.
A native table census classifies all 33 actor behaviors and 18 enemy weapon
definitions. Moving and stationary attackers also have actual projectile-birth
to player-damage traces. Table coverage does not mean every enemy encounter
has been played; deliberate firing intervals and movement steps are retained.
Developer test programs are included in the source package; captured images,
replay states, personal settings and test logs are excluded from both ZIPs.

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
