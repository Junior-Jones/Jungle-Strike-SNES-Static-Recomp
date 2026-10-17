# Contributing

Use GitHub Issues to report a problem or suggest an improvement. Include the
application version, Windows version, steps to reproduce, expected behavior,
and what happened. For display problems, say whether Widescreen and full screen
were enabled. Screenshots showing the affected area are helpful when available.

Widescreen is experimental. Reports about terrain, aircraft, weapons, messages,
and Map/Mission/Status placement are welcome. See README.txt for the current
verification scope; the project does not claim complete campaign coverage.

Do not upload a ROM, original game assets, personal settings, or files containing
private paths or information. Review logs and screenshots before sharing them.

For code changes, open a pull request describing the problem, the change, and
how it was checked. Keep changes focused and preserve the normal 4:3 mode.
Follow the build instructions in README.txt. Build all default targets and run:

```powershell
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

Windows CI runs the ROM-free checks on pull requests, main, and version tags.
Gameplay checks require your own supported ROM; test captures and replay states
must stay out of release packages. Retain the existing third-party notices and
license terms.
