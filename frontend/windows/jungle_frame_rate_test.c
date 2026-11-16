#include "../common/jungle_frame_rate.h"
#include "jungle_audio_resampler.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#x);return 1;}}while(0)
static int test_clock(void) {
    static const uint64_t frequencies[]={3u,3579545u,10000000u,1000000000u};
    unsigned f,mode,n;
    for(f=0;f<4;f++)for(mode=0;mode<2;mode++) {
        JungleFrameClock clock;
        uint64_t scaled=frequencies[f]*(mode?1u:JUNGLE_NATIVE_FPS_DENOMINATOR);
        CHECK(jungle_frame_clock_init(&clock,frequencies[f],123u,(int)mode));
        for(n=1;n<=216000u;n++) {
            uint64_t expected=123u+(scaled/clock.numerator)*n+
                ((scaled%clock.numerator)*n)/clock.numerator;
            jungle_frame_clock_advance(&clock);
            CHECK(clock.deadline==expected);
        }
        if(mode)CHECK(clock.deadline==123u+frequencies[f]*3600u);
    }
    {JungleFrameClock clock={0},old=clock;
     CHECK(!jungle_frame_clock_init(&clock,0,0,1));
     CHECK(!jungle_frame_clock_init(&clock,UINT64_MAX,0,0));
     CHECK(!memcmp(&clock,&old,sizeof(clock)));}
    puts("PASS exact60 and native NTSC rational deadlines: one hour without accumulated drift at four QPC frequencies");
    return 0;
}
static int test_audio(void) {
    unsigned profile,n,i;
    for(profile=0;profile<2;profile++) {
        JungleAudioHermiteResampler resampler;
        uint64_t input_total=0,output_total=0;
        int16_t input[1100*2],output[2200*2];
        double source=jungle_frame_rate_audio_source(32040.0,1,(int)profile);
        memset(&resampler,0,sizeof(resampler));
        jungle_audio_resampler_set_rates(&resampler,source,48000.0);
        for(n=1;n<=7200;n++) {
            uint64_t cumulative=(uint64_t)n*32040u*JUNGLE_NATIVE_FPS_DENOMINATOR/JUNGLE_NATIVE_FPS_NUMERATOR;
            size_t frames=(size_t)(cumulative-input_total),got;
            CHECK(frames<=1100);
            for(i=0;i<frames;i++){input[2*i]=(int16_t)((input_total+i)%2000u);input[2*i+1]=(int16_t)(-input[2*i]);}
            got=jungle_audio_resampler_process(&resampler,input,frames,output,2200);
            input_total=cumulative;output_total+=got;
        }
        CHECK(fabs((double)output_total-(double)input_total*48000.0/source)<12.0);
        if(profile)CHECK(fabs((double)output_total-120.0*48000.0)<12.0);
    }
    CHECK(jungle_frame_rate_audio_source(32040.0,0,1)==32040.0);
    puts("PASS 120-second native and exact60 speaker-rate conversion: no accumulating production/consumption mismatch; unlocked mode retains native audio rate");
    return 0;
}
int main(void){return test_clock()||test_audio();}
