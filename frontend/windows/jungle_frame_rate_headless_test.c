/* Real production timer, stepping, audio and paint path, using a hidden owner
   and memory DIB. This does not claim a physical monitor scanout measurement. */
#define main unused_presentation_main
#include "jungle_widescreen_presentation_test.c"
#undef main
#include <math.h>
static int check_lifecycle(unsigned exact) {
    PROCESS_POWER_THROTTLING_STATE policy;
    unsigned profile;
    uint32_t before=jungle_recomp_current_frame(g_game);
    for(profile=0;profile<2;profile++) {
        g_paused=0;g_frontend_settings.exact_60_fps=(int)profile;
        reset_pacing_clock();
        if(g_frame_clock.numerator!=(profile?60u:JUNGLE_NATIVE_FPS_NUMERATOR)||
           fabs(g_audio_output.source_rate_hz-jungle_frame_rate_audio_source(
               JUNGLE_RECOMP_AUDIO_SAMPLE_RATE,1,(int)profile))>0.000001)return 0;
        ZeroMemory(&policy,sizeof(policy));policy.Version=PROCESS_POWER_THROTTLING_CURRENT_VERSION;
        if(GetProcessInformation(GetCurrentProcess(),ProcessPowerThrottling,&policy,sizeof(policy))&&
           (!(policy.ControlMask&PROCESS_POWER_THROTTLING_EXECUTION_SPEED)||
            (policy.StateMask&PROCESS_POWER_THROTTLING_EXECUTION_SPEED)))return 0;
        jungle_audio_output_pause(&g_audio_output);g_paused=1;reset_pacing_clock();
        ZeroMemory(&policy,sizeof(policy));policy.Version=PROCESS_POWER_THROTTLING_CURRENT_VERSION;
        if(GetProcessInformation(GetCurrentProcess(),ProcessPowerThrottling,&policy,sizeof(policy))&&
           policy.ControlMask)return 0;
        jungle_audio_output_flush(&g_audio_output);jungle_audio_output_resume(&g_audio_output);
    }
    g_frontend_settings.exact_60_fps=(int)exact;g_paused=0;reset_pacing_clock();
    if(jungle_recomp_current_frame(g_game)!=before)return 0;
    puts("PASS profile switching, pause/flush/resume, speaker source rate and active/paused Windows power policy; zero guest fields advanced.");
    return 1;
}
int main(int argc,char **argv) {
    FILE *file,*csv;
    uint8_t *rom;
    char error[512],path[2048];
    unsigned count,i,exact,wide,audio,input,fullscreen;
    WNDCLASSEXW wc;
    BITMAPINFO bmi;
    HBITMAP bitmap;
    HGDIOBJ previous;
    uint32_t *pixels,*sample_pixels,*source_pixels;
    unsigned source_width=0,source_height=0;
    LARGE_INTEGER started,now;
    uint64_t first_present=0,last_present=0,audio_frames=0;
    wchar_t output[PATH_CAPACITY],image_path[PATH_CAPACITY];
    if(argc<8||argc>10){puts("ROM SNAPSHOT FRAMES EXACT60 WIDE OUTPUT_DIRECTORY AUDIO [HEX_INPUT [FULLSCREEN]]");return 2;}
    count=(unsigned)strtoul(argv[3],NULL,10);exact=(unsigned)strtoul(argv[4],NULL,10);
    wide=(unsigned)strtoul(argv[5],NULL,10);audio=(unsigned)strtoul(argv[7],NULL,10);
    input=argc>=9?(unsigned)strtoul(argv[8],NULL,16):0u;
    fullscreen=argc>=10?(unsigned)strtoul(argv[9],NULL,10):1u;
    if(count<2||input>65535u)return 2;
    file=fopen(argv[1],"rb");rom=(uint8_t*)malloc(JUNGLE_RECOMP_ROM_SIZE);
    if(!file||!rom||fread(rom,1,JUNGLE_RECOMP_ROM_SIZE,file)!=JUNGLE_RECOMP_ROM_SIZE)return 2;
    fclose(file);
    if(!jungle_recomp_create(&g_game,rom,JUNGLE_RECOMP_ROM_SIZE,error,sizeof(error)))return 2;
    free(rom);
    if(!jungle_recomp_snapshot_load(g_game,argv[2],error,sizeof(error))||
       !jungle_recomp_set_widescreen(g_game,(int)wide,error,sizeof(error)))return 2;
    jungle_frontend_settings_win32_defaults(&g_frontend_settings);
    jungle_audio_settings_defaults(&g_audio_settings);
    jungle_audio_output_initialize(&g_audio_output);
    g_frontend_settings.exact_60_fps=(int)exact;
    g_frontend_settings.widescreen=(int)wide;
    g_frontend_settings.integer_scale=0;
    g_audio_settings.enabled=(int)audio;
    if(audio>1)g_audio_settings.drift_correction_enabled=0;
    g_audio_settings.volume_percent=0;
    g_instance=GetModuleHandleW(NULL);
    QueryPerformanceFrequency(&g_qpc_frequency);
    audit_bounds=(RECT){0,0,1920,1080};
    ZeroMemory(&wc,sizeof(wc));wc.cbSize=sizeof(wc);wc.hInstance=g_instance;
    wc.lpfnWndProc=window_proc;wc.lpszClassName=L"JungleFrameRateHeadless";
    if(!RegisterClassExW(&wc))return 2;
    g_menu=create_menu_bar();
    g_window=CreateWindowExW(0,wc.lpszClassName,L"Headless FPS verification",
        WS_OVERLAPPEDWINDOW,0,0,1920,1080,NULL,g_menu,g_instance,NULL);
    if(!g_window||IsWindowVisible(g_window))return 2;
    g_presentation_hidden=(int)fullscreen;g_fullscreen_active=(int)fullscreen;
    ZeroMemory(&bmi,sizeof(bmi));bmi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth=1920;bmi.bmiHeader.biHeight=-1080;
    bmi.bmiHeader.biPlanes=1;bmi.bmiHeader.biBitCount=32;
    audit_dc=CreateCompatibleDC(NULL);
    bitmap=CreateDIBSection(audit_dc,&bmi,DIB_RGB_COLORS,(void**)&pixels,NULL,0);
    if(!audit_dc||!bitmap)return 2;
    previous=SelectObject(audit_dc,bitmap);
    sample_pixels=(uint32_t*)malloc(1920u*1080u*4u);
    source_pixels=(uint32_t*)malloc(512u*288u*4u);
    if(!sample_pixels||!source_pixels)return 2;
    g_frame_timer=CreateWaitableTimerExW(NULL,NULL,HOST_TIMER_HIGH_RESOLUTION,HOST_TIMER_ACCESS);
    if(!g_frame_timer)g_frame_timer=CreateWaitableTimerW(NULL,FALSE,NULL);
    if(!g_frame_timer)return 2;
    if(audio&&!open_audio(0)){fputs("Audio device unavailable\n",stderr);return 3;}
    if(!check_lifecycle(exact))return 6;
    jungle_input_latch_press(&g_keyboard_input,(uint16_t)input,0,0);
    g_paused=0;
    if(audio)jungle_audio_output_resume(&g_audio_output);
    snprintf(path,sizeof(path),"%s/pacing.csv",argv[6]);csv=fopen(path,"w");if(!csv)return 2;
    fputs("sample,guest_frame,present_qpc,painted,skipped_deadlines,resyncs,audio_queue,audio_underruns,core_ms,paint_ms\n",csv);
    reset_pacing_clock();QueryPerformanceCounter(&started);
    for(i=0;i<count;) {
        uint32_t before=jungle_recomp_current_frame(g_game);
        LARGE_INTEGER step_start,step_end;
        JungleStrikeAudioDiagnostics diagnostics;
        if(WaitForSingleObject(g_frame_timer,2000)!=WAIT_OBJECT_0)return 4;
        QueryPerformanceCounter(&step_start);service_host_timer();QueryPerformanceCounter(&step_end);
        if(g_paused){fprintf(stderr,"Core stopped: %s\n",jungle_recomp_last_error(g_game));return 5;}
        if(jungle_recomp_current_frame(g_game)==before)continue;
        paint_window(NULL);GdiFlush();QueryPerformanceCounter(&now);
        if(!first_present)first_present=(uint64_t)now.QuadPart;
        last_present=(uint64_t)now.QuadPart;
        if(!audio)audio_frames+=jungle_recomp_audio_discard(g_game);
        ZeroMemory(&diagnostics,sizeof(diagnostics));
        jungle_audio_output_get_diagnostics(&g_audio_output,&diagnostics);
        fprintf(csv,"%u,%u,%llu,%llu,%llu,%llu,%u,%llu,%.6f,%.6f\n",++i,
            jungle_recomp_current_frame(g_game),(unsigned long long)last_present,
            (unsigned long long)g_presented_frame_count,
            (unsigned long long)g_pacing_skipped_deadlines,
            (unsigned long long)g_pacing_resyncs,diagnostics.queue_depth_frames,
            (unsigned long long)diagnostics.underruns,
            (step_end.QuadPart-step_start.QuadPart)*1000.0/g_qpc_frequency.QuadPart,
            (now.QuadPart-step_end.QuadPart)*1000.0/g_qpc_frequency.QuadPart);
        /* Copy only while timed; perform screenshot file I/O after the run. */
        if(i==60u) {
            memcpy(sample_pixels,pixels,1920u*1080u*4u);
            source_width=jungle_recomp_frame_width(g_game);
            source_height=jungle_recomp_frame_height(g_game);
            if(source_width*source_height>512u*288u)return 2;
            memcpy(source_pixels,jungle_recomp_frame_bgra(g_game),source_width*source_height*4u);
        }
    }
    fclose(csv);
    utf8_to_wide(argv[6],output,ARRAY_COUNT(output));
    join_wide_path(image_path,ARRAY_COUNT(image_path),output,L"realtime-final.bmp");
    if(!save_bgra_bmp(image_path,(const uint8_t*)pixels,1920,1080,1920*4))return 2;
    if(source_width) {
        join_wide_path(image_path,ARRAY_COUNT(image_path),output,L"frame60-presented.bmp");
        if(!save_bgra_bmp(image_path,(const uint8_t*)sample_pixels,1920,1080,1920*4))return 2;
        join_wide_path(image_path,ARRAY_COUNT(image_path),output,L"frame60-source.bmp");
        if(!save_bgra_bmp(image_path,(const uint8_t*)source_pixels,source_width,source_height,source_width*4))return 2;
    }
    free(sample_pixels);free(source_pixels);
    printf("RESULT frames=%u painted=%llu measured_fps=%.6f target=%.6f resyncs=%llu skipped=%llu source_audio_rate=%.9f captured_pcm=%llu input=%04X fullscreen=%u\n",
        count,(unsigned long long)g_presented_frame_count,
        (count-1)*(double)g_qpc_frequency.QuadPart/(last_present-first_present),
        exact?60.0:(double)JUNGLE_NATIVE_FPS_NUMERATOR/JUNGLE_NATIVE_FPS_DENOMINATOR,
        (unsigned long long)g_pacing_resyncs,(unsigned long long)g_pacing_skipped_deadlines,
        g_audio_output.source_rate_hz,(unsigned long long)audio_frames,input,fullscreen);
    SelectObject(audit_dc,previous);DeleteObject(bitmap);DeleteDC(audit_dc);
    CancelWaitableTimer(g_frame_timer);CloseHandle(g_frame_timer);g_frame_timer=NULL;
    g_paused=1;set_playback_power_policy(0);
    g_shutting_down=1;jungle_audio_output_close(&g_audio_output);
    jungle_recomp_destroy(g_game);g_game=NULL;DestroyWindow(g_window);
    return 0;
}
