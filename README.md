# Jungle Strike — Windows static recompilation 1.2.1

<a href="https://recomplauncher.com/game/jungle-strike-snes-static-recomp"><picture><source media="(prefers-color-scheme: dark)" srcset="https://recomplauncher.com/assets/press/launcher/badge-light.svg"><img alt="Get it on RecompLauncher" src="https://recomplauncher.com/assets/press/launcher/badge-dark.svg" height="48"></picture></a>

[![Windows CI](https://github.com/Junior-Jones/Jungle-Strike-SNES-Static-Recomp/actions/workflows/windows-ci.yml/badge.svg)](https://github.com/Junior-Jones/Jungle-Strike-SNES-Static-Recomp/actions/workflows/windows-ci.yml)

Download the portable Windows x64 ZIP from [Releases](https://github.com/Junior-Jones/Jungle-Strike-SNES-Static-Recomp/releases/latest), extract it and run Launcher.exe. Supply your own exact 2,097,152-byte USA/Canada NTSC ROM. No ROM or original assets are distributed.

The application supports normal 4:3, optional experimental 16:9 Widescreen and optional experimental 60 FPS processing. Version 1.2.1 buffers Windows drawing to remove intermediate black clears and adds RecompLauncher integration.

RecompLauncher can verify the player's ROM, start the game directly, expose existing settings, back up `Saves`, and find failure reports in `Logs`. The release includes `recomplauncher.json` beside Launcher.exe. Personal settings and game files are never shipped.

For Steam shortcuts or other launchers:

```text
Launcher.exe --game "Rom\Jungle Strike.sfc" --port-widescreen --60fps
```

Keyboard and SDL virtual-gamepad paths were tested across nine mission starts, including movement and firing. All 20 supported controller controls, connection handling and remapping paths were checked. Physical USB/Bluetooth hardware was not detected during those tests; this is not a hardware compatibility guarantee.

See [README.txt](README.txt) for controls, build instructions and detailed verification scope, and [VERSION.txt](VERSION.txt) for release notes. Report problems through [GitHub Issues](https://github.com/Junior-Jones/Jungle-Strike-SNES-Static-Recomp/issues).
