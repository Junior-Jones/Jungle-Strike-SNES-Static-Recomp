#include "jungle_launch_options.h"
#include <stdio.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"FAIL line %d\n",__LINE__); return 1; } } while(0)
int main(void) {
    JungleLaunchOptions o;
    wchar_t *plain[]={L"Launcher.exe"};
    wchar_t *mixed[]={L"Launcher.exe",L"--port-widescreen",L"--game",L"C:\\Games\\Jungle Strike.sfc",L"--60fps",L"--fullscreen"};
    wchar_t *reverse[]={L"Launcher.exe",L"--game=C:\\Games\\Jungle Strike.sfc",L"--fullscreen",L"--windowed",L"--60fps",L"--no-60fps",L"--port-wide-canvas",L"--no-port-widescreen"};
    wchar_t *missing[]={L"Launcher.exe",L"--game"};
    wchar_t *flagpath[]={L"Launcher.exe",L"--game",L"--port-widescreen"};
    wchar_t *empty[]={L"Launcher.exe",L"--game="};
    wchar_t *unknown[]={L"Launcher.exe",L"--not-an-option"};
    CHECK(!jungle_parse_launch_options(1,plain,&o));
    CHECK(!o.game_path&&o.widescreen==-1&&o.fps60==-1&&o.fullscreen==-1);
    CHECK(!jungle_parse_launch_options(6,mixed,&o));
    CHECK(!wcscmp(o.game_path,mixed[3])&&o.widescreen==1&&o.fps60==1&&o.fullscreen==1);
    CHECK(!jungle_parse_launch_options(8,reverse,&o));
    CHECK(!wcscmp(o.game_path,L"C:\\Games\\Jungle Strike.sfc")&&o.widescreen==0&&o.fps60==0&&o.fullscreen==0);
    CHECK(jungle_parse_launch_options(2,missing,&o));
    CHECK(jungle_parse_launch_options(3,flagpath,&o));
    CHECK(jungle_parse_launch_options(2,empty,&o));
    CHECK(jungle_parse_launch_options(2,unknown,&o));
    puts("PASS saved defaults, combined/reordered options, quoted-path values, last-option precedence and invalid arguments");
    return 0;
}
