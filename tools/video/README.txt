Renderer and frame-rate verification
====================================

Configure and build the Windows frontend, then run its ROM-free checks:

  cmake -S frontend/windows -B build -A x64
  cmake --build build --config Release --parallel
  ctest --test-dir build -C Release --output-on-failure

jungle-video-decode-test compares the optimized decoder with an independent
bit-by-bit oracle, exhaustively for 2bpp plane pairs and randomly for 2/4/8bpp
rows including address wrap. Prepared scanlines are also compared against the
uncached single-pixel renderer with scroll wrap, flips, palettes, priority,
OBJ and changes between scanlines.

jungle-frame-rate-test checks one hour of exact60/native rational deadlines
and two minutes of native PCM production through the actual speaker resampler.
jungle-frame-rate-ui-test exercises the real Settings frame lock in hidden
windows, checking label fit, Apply and persistence. jungle-widescreen-ui-test
also checks the 60 FPS toolbar/menu controls: off by default, synchronized,
one-time Notice with fitted text and bottom Close, and persisted dismissal.

Optional real-core timing test (requires an external verified ROM and a
compatible gameplay snapshot; neither is distributed):

  cmake --build build --config Release --target jungle-frame-rate-headless-test

Run build/Release/jungle-frame-rate-headless-test.exe with these arguments:

  ROM SNAPSHOT FRAMES EXACT60 WIDE OUTPUT_DIRECTORY AUDIO [HEX_INPUT [FULLSCREEN]]

Create OUTPUT_DIRECTORY before running. FRAMES must be at least 2. EXACT60=1
selects exact 60 FPS, 0 selects native NTSC. WIDE selects the expanded image.
AUDIO=0 disables speaker output, 1 uses muted DirectSound with audio defaults,
2 also disables drift correction. HEX_INPUT holds a SNES controller mask;
FULLSCREEN=0 tests the windowed paint layout, 1 the full-screen layout.

The test uses the production core, timer service, audio backend and GDI paint
code in a hidden native window with a 1920x1080 memory DIB. It also checks
profile switching and pause/flush/resume without advancing guest fields. CSV
timestamps, deadline resets, audio queue/underrun counts and screenshots are
written only to OUTPUT_DIRECTORY. Screenshot file I/O happens after timing.
The first field can have cold-cache latency; use a long run and inspect the
timestamp distribution, rather than treating a short-run average as proof.

This tests software pacing and painting, not physical display scanout. A
60 FPS presentation clock does not make every original animation or static
menu redraw update every field. See the source README for native UI rates.
