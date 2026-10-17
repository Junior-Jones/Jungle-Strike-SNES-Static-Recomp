Widescreen verification tools
=============================

These developer tools open no visible window and are not linked into Launcher.
A supplied, verified ROM is required for gameplay checks; it is not packaged.

The jungle-snapshot-display-test target accepts ROM, SNAPSHOT, OUTPUT_DIRECTORY.
It checks immediate 512x288 output after a paused load and mode toggles, without
running an emulated frame. Native crop/HUD/console pixels and serialized guest
state must remain unchanged. Existing snapshot files remain compatible.

Build the root jungle-widescreen-verify target in Release. Invoke it with:
  jungle-widescreen-verify.exe ROM GAMEPLAY_SNAPSHOT OUTPUT_DIRECTORY
The output directory must exist. The snapshot must be a natural flight state.
An optional fourth argument limits the run to a 60-frame smoke check.

The full 3,248-frame route compares two production cores receiving identical
input. It checks every expanded frame's original crop, serialized guest state,
movement, individual X/A/Y weapon firing input, diagonal flight, map transitions,
eight firing headings, snapshot reload and mode disabling. It writes matched
native/wide PPM frames and the first frames with OAM sprites on expanded edges.
Edge counts record actual final visible OBJ pixels, after priority and HUD
occlusion. Projectile graphics are counted separately from other sprites.

The jungle-widescreen-checkpoint target replays a text input route for 9,000
natural frames and saves a snapshot. Text lines are first-frame last-frame
hex-button-mask. Supplying a snapshot instead of a route loads it, taps Select,
and advances 240 frames. Verify the resulting screen before treating it as a
mission checkpoint; old password routes can remain in briefings or mission 1.

The Windows frontend build includes jungle-widescreen-ui-test in ctest. This
uses the actual launcher command handlers in a hidden window and checks the
two controls, saved settings and minimum-window layout. Optional ROM, snapshot
and output-directory arguments also check live core mode switching and BMP
export dimensions, and capture the real toolbar controls without showing an
application window.

Manual screenshot review should compare roads, terrain, scenery and shadows
across the original crop boundary while moving through tile crossings. The
view is 512 x 288 and exposes all four sides. Visible BG3 messages
move to the bottom edge; scenery fills the former blanking footer. In wide
mode the information console fills the canvas while preserving its original
text, digits, map and markers at native pixel size. Normal mode is unchanged.
Guest object spawning/culling, collision and weapon range remain unchanged.

The renderer records final visible OBJ pixels by OAM index on each edge.
Edge screenshots use these pixel counts, excluding pixels covered by the HUD.
The frozen entity-return amendment is regression-tested separately, including
rejection of unknown target/source/mode and an unverified ROM.

The root jungle-widescreen-hud-test target accepts the same three arguments.
It creates a high-priority BG3 message-strip fixture in a host-only PPU copy,
checks opaque pixels move from native rows 208..219 to expanded rows 272..283,
and checks transparent pixels and the world behind the old strip are preserved.
Its screenshots are marked synthetic; they are not natural gameplay messages.

The root jungle-natural-hud-test target accepts ROM, GAMEPLAY_SNAPSHOT and
OUTPUT_DIRECTORY. It uses only normal inputs (Up for 180 frames, then hovering)
to drain fuel and reach the real warning, rendering samples every 16 frames.
A read-only PPU observer measures visible BG3 bounds over the full gameplay
screen. It captures matched native/wide frames, compares relocated HUD pixels
and guest snapshots, and checks a further 240 rendered frames. The known
mission-1 flight snapshot reaches WARNING! LOW FUEL! at replay frame 20,592.
The natural text occupies native rows 209..216 and expanded rows 273..280.
Loading the saved real-hud.snapshot repeats the warning/continuation checks
immediately. No guest memory or graphics are changed by this test.

The jungle-overlay-audit target accepts the same arguments and captures pause,
map, mission and status transitions in two production cores. The console repair
compiles the previously missing entry/poll regions A0:8452/A0:84CF and A0:8387/A0:83FB, plus
their source-proven shared returns. Each settled console screen is held for 360 frames. Both Mission-to-Status and Map-to-Status transitions pass and the
final return asserts that live flight resumes at 512x288. Failure diagnostics
remain enabled; unknown context/target/mode/ROM is still rejected.

Controlled player-weapon proof
-----------------------------
Build jungle-edge-weapon-test in the root Release build. Invoke:
  jungle-edge-weapon-test.exe ROM SNAPSHOT weapon-proof.route OUTPUT SIDE
SIDE is 0=left, 1=right, 2=top, 3=bottom. OUTPUT must already exist. Supply a
natural helicopter checkpoint with the player in the requested expanded band.
The fixture clears old projectiles, fires X, A and Y separately and coasts.
Each firing phase must decrease the corresponding ammunition counter. The
final gate requires actual visible player-body pixels and all three player
projectile types on the requested side; a missing type fails the test.
Native/wide crops compare every frame and guest snapshots compare per phase.

Controlled quiet-corner firing identified player chain-gun graphics as name
select 0 / palette 0 / tile 223, and missile graphics as name select 0 /
palette 1 / tiles 192..222. Earlier name-select 1 / palette 1 or 3 / tiles
64..111 counts were not player-weapon proof and must not be used as such.
The helper also checks the translated native region at clamped map edges,
where native pixels legitimately occupy the fixed outer screen bands. Final
pixel colors/priority are verified from a host PPU copy without guest edits.
These graphics and ammo assertions are for the tested helicopter configuration.
They do not establish vehicle-specific projectile coverage.

The jungle-corner-test developer target also accepts a fixed input route:
  jungle-corner-test.exe ROM SNAPSHOT console-cycle.route OUTPUT
This fixture exercises Map/Mission selections 24 times in each direction,
Status 8 times each way, then returns to flight. Every actual frame is rendered
headlessly in both modes. Its optional 'go' navigator is experimental and
must report REACHED for an accepted destination; a stalled or unsafe route
is not corner evidence. Input-only routes do not use that navigator.

The Windows jungle-widescreen-presentation-test target accepts ROM, SNAPSHOT,
OUTPUT and LABEL. It runs the production fullscreen paint path against a
1920x1080 memory DIB in normal and wide modes. No desktop window is opened.
It advances three frames after loading, validates sampled destination pixels,
and saves BMPs. OS monitor-mode switching is outside this offscreen test.
