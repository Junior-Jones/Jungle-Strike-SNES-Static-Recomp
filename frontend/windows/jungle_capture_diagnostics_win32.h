/* Included by the launcher after its globals and path helpers. No emulated
   state, persistent setting, UI control or per-frame disk writes are added. */
#define JUNGLE_CAPTURE_HISTORY 120u
typedef struct JungleCaptureTrace {
    JungleCoreCaptureSample state;
    uint64_t qpc, skipped_deadlines, resyncs;
    double work_ms;
    unsigned input, success;
} JungleCaptureTrace;
static JungleCaptureTrace g_capture_history[JUNGLE_CAPTURE_HISTORY];
static unsigned g_capture_history_next, g_capture_history_count;
static unsigned long g_capture_sequence;
static JungleStrikeRecomp *g_capture_history_game;
static void reset_capture_history(void) {
    g_capture_history_next=g_capture_history_count=0;
    g_capture_history_game=g_game;
}
static void record_capture_history(uint16_t input,LARGE_INTEGER started,int success) {
    JungleCaptureTrace entry;
    LARGE_INTEGER ended;
    memset(&entry,0,sizeof(entry));
    if(!jungle_recomp_capture_sample(g_game,&entry.state))return;
    if(g_capture_history_game!=g_game || (g_capture_history_count&&
       entry.state.master_clock<g_capture_history[(g_capture_history_next+JUNGLE_CAPTURE_HISTORY-1u)%JUNGLE_CAPTURE_HISTORY].state.master_clock))
        reset_capture_history();
    QueryPerformanceCounter(&ended);entry.qpc=(uint64_t)ended.QuadPart;
    entry.work_ms=g_qpc_frequency.QuadPart>0?
        (double)(ended.QuadPart-started.QuadPart)*1000.0/(double)g_qpc_frequency.QuadPart:0.0;
    entry.input=input;entry.success=(unsigned)(success!=0);
    entry.skipped_deadlines=g_pacing_skipped_deadlines;entry.resyncs=g_pacing_resyncs;
    g_capture_history[g_capture_history_next]=entry;
    g_capture_history_next=(g_capture_history_next+1u)%JUNGLE_CAPTURE_HISTORY;
    if(g_capture_history_count<JUNGLE_CAPTURE_HISTORY)g_capture_history_count++;
}
static uint64_t capture_bytes_hash(const void *data,size_t size) {
    const unsigned char *p=(const unsigned char*)data;
    uint64_t hash=UINT64_C(14695981039346656037);
    while(size--){hash^=*p++;hash*=UINT64_C(1099511628211);}return hash;
}
static int capture_file_hash(const wchar_t *path,uint64_t *hash) {
    unsigned char bytes[8192];size_t size;
    FILE *file=_wfopen(path,L"rb");
    uint64_t value=UINT64_C(14695981039346656037);
    if(!file)return 0;
    while((size=fread(bytes,1,sizeof(bytes),file))!=0){
        size_t i;for(i=0;i<size;i++){value^=bytes[i];value*=UINT64_C(1099511628211);}
    }
    if(ferror(file)){fclose(file);return 0;}
    if(fclose(file)!=0)return 0;*hash=value;return 1;
}
static int capture_json_string(FILE *file,const char *text) {
    const unsigned char *p=(const unsigned char*)text;
    if(fputc('"',file)==EOF)return 0;
    for(;*p;p++){
        if(*p=='"'||*p=='\\'){if(fputc('\\',file)==EOF)return 0;}
        if(*p<32){if(fprintf(file,"\\u%04x",(unsigned)*p)<0)return 0;}
        else if(fputc(*p,file)==EOF)return 0;
    }
    return fputc('"',file)!=EOF;
}
static int capture_sample_json(FILE *file,const JungleCoreCaptureSample *s) {
    return fprintf(file,
        "{\"machine_frame\":%" PRIu64 ",\"displayed_frame\":%" PRIu64 ",\"master_clock\":%" PRIu64
        ",\"retired\":%" PRIu64 ",\"scanline\":%u,\"hclock\":%u,\"mission\":%u,\"gameplay_mode_raw\":%u,\"ui_scene_raw\":%u,"
        "\"actor_available\":%s,\"resources_available\":%s,\"player_pointer_7f\":%u,\"resource_pointer_7f\":%u,"
        "\"vehicle_class\":%u,\"heading\":%u,\"x_fixed_16_16\":%" PRId32 ",\"y_fixed_16_16\":%" PRId32 ",\"z_fixed_16_16\":%" PRId32
        ",\"camera_x_raw\":%u,\"camera_y_raw\":%u,\"armor_raw\":%u,\"fuel\":%u,\"hellfire\":%u,\"hydra\":%u,\"gun\":%u,\"lives\":%u,"
        "\"physical_counter_raw\":%u,\"publication_counter\":%u,\"contact_phase\":%u,\"input_serial\":%u,\"input_auto\":%u,"
        "\"experimental_60fps\":%s,\"widescreen\":%s,\"water_valid\":%s,\"water_phase\":%u,\"pending_ui_packets\":%u}",
        s->machine_frame,s->displayed_frame,s->master_clock,s->retired,
        (unsigned)s->scanline,(unsigned)s->hclock,(unsigned)s->mission,(unsigned)s->gameplay_mode,(unsigned)s->ui_scene,
        s->actor_available?"true":"false",s->resources_available?"true":"false",(unsigned)s->player_pointer,(unsigned)s->resource_pointer,
        (unsigned)s->vehicle_class,(unsigned)s->heading,s->x_fixed,s->y_fixed,s->z_fixed,
        (unsigned)s->camera_x,(unsigned)s->camera_y,(unsigned)s->armor,(unsigned)s->fuel,(unsigned)s->hellfire,(unsigned)s->hydra,(unsigned)s->gun,(unsigned)s->lives,
        (unsigned)s->physical_counter,(unsigned)s->publication_counter,(unsigned)s->contact_phase,(unsigned)s->input_serial,(unsigned)s->input_auto,
        s->experimental_60fps?"true":"false",s->widescreen?"true":"false",s->water_valid?"true":"false",(unsigned)s->water_phase,(unsigned)s->pending_ui_packets)>=0;
}
static int capture_double_order(const void *a,const void *b) {
    double x=*(const double*)a,y=*(const double*)b;return (x>y)-(x<y);
}
static int capture_output_path(wchar_t *path,const wchar_t *directory,uint32_t frame,
                               unsigned width,unsigned height,int fullscreen) {
    SYSTEMTIME now;unsigned tries;
    GetLocalTime(&now);
    for(tries=0;tries<256u;tries++){
        wchar_t log_path[PATH_CAPACITY];size_t length;
        ++g_capture_sequence;
        if(fullscreen)
            (void)_snwprintf(path,PATH_CAPACITY,L"%s\\jungle-fullscreen-%ux%u-frame-%08u-%04u%02u%02u-%02u%02u%02u-%03u-%lu-%lu.bmp",
                directory,width,height,frame,(unsigned)now.wYear,(unsigned)now.wMonth,(unsigned)now.wDay,
                (unsigned)now.wHour,(unsigned)now.wMinute,(unsigned)now.wSecond,(unsigned)now.wMilliseconds,
                (unsigned long)GetCurrentProcessId(),g_capture_sequence);
        else
            (void)_snwprintf(path,PATH_CAPACITY,L"%s\\jungle-frame-%08u-%04u%02u%02u-%02u%02u%02u-%03u-%lu-%lu.bmp",
                directory,frame,(unsigned)now.wYear,(unsigned)now.wMonth,(unsigned)now.wDay,
                (unsigned)now.wHour,(unsigned)now.wMinute,(unsigned)now.wSecond,(unsigned)now.wMilliseconds,
                (unsigned long)GetCurrentProcessId(),g_capture_sequence);
        path[PATH_CAPACITY-1u]=L'\0';length=wcslen(path);
        if(length<4u||length+2u>=PATH_CAPACITY)return 0;
        copy_wide(log_path,PATH_CAPACITY,path);copy_wide(log_path+length-4u,PATH_CAPACITY-length+4u,L".json");
        if(GetFileAttributesW(path)==INVALID_FILE_ATTRIBUTES&&GetFileAttributesW(log_path)==INVALID_FILE_ATTRIBUTES)return 1;
    }
    return 0;
}
/* Result2 means the image exists but its diagnostic report could not be saved. */
static int write_capture_report(const wchar_t *image_path,unsigned width,unsigned height,int fullscreen) {
    wchar_t path[PATH_CAPACITY];
    char basename[PATH_CAPACITY*3u];
    const wchar_t *name=wcsrchr(image_path,L'\\');
    JungleCoreCaptureSample state;
    JungleStrikeAudioDiagnostics audio;
    SYSTEMTIME utc;
    uint64_t file_hash,frame_hash=0;
    size_t json_size,length=wcslen(image_path);
    char *runtime=NULL;
    const uint32_t *pixels;
    unsigned fw,fh,i,count,first;
    double sorted[JUNGLE_CAPTURE_HISTORY],sum=0.0;
    FILE *file=NULL;
    int ok=0;
    if(length<4u||length+2u>=PATH_CAPACITY||!jungle_recomp_capture_sample(g_game,&state)||
       !wide_to_utf8(name?name+1:image_path,basename,sizeof(basename))||!capture_file_hash(image_path,&file_hash))return 2;
    if(g_capture_history_game!=g_game || (g_capture_history_count&&state.master_clock<
       g_capture_history[(g_capture_history_next+JUNGLE_CAPTURE_HISTORY-1u)%JUNGLE_CAPTURE_HISTORY].state.master_clock))reset_capture_history();
    copy_wide(path,PATH_CAPACITY,image_path);copy_wide(path+length-4u,PATH_CAPACITY-length+4u,L".json");
    json_size=jungle_recomp_diagnostic_json_size(g_game);runtime=(char*)malloc(json_size);
    if(!runtime||!jungle_recomp_diagnostic_json(g_game,runtime,json_size))goto cleanup;
    fw=jungle_recomp_frame_width(g_game);fh=jungle_recomp_frame_height(g_game);
    pixels=jungle_recomp_frame_bgra(g_game);
    if(pixels)frame_hash=capture_bytes_hash(pixels,(size_t)fw*fh*4u);
    jungle_audio_output_get_diagnostics(&g_audio_output,&audio);GetSystemTime(&utc);
    count=g_capture_history_count;first=(g_capture_history_next+JUNGLE_CAPTURE_HISTORY-count)%JUNGLE_CAPTURE_HISTORY;
    for(i=0;i<count;i++){sorted[i]=g_capture_history[(first+i)%JUNGLE_CAPTURE_HISTORY].work_ms;sum+=sorted[i];}
    qsort(sorted,count,sizeof(sorted[0]),capture_double_order);
    file=_wfopen(path,L"wb");if(!file)goto cleanup;
    if(fprintf(file,"{\n\"schema\":\"JungleStrikeScreenshot1\",\n\"version\":\"%s\",\n\"image\":{\"file\":",JUNGLE_STATIC_CORE_VERSION_STRING)<0||
       !capture_json_string(file,basename)||fprintf(file,
       ",\"width\":%u,\"height\":%u,\"file_hash_fnv1a64\":\"%016" PRIx64 "\",\"fullscreen\":%s,"
       "\"game_width\":%u,\"game_height\":%u,\"game_bgra_hash_fnv1a64\":\"%016" PRIx64 "\",\"displayed_frame\":%" PRIu64 "},\n"
       "\"captured_at_utc\":\"%04u-%02u-%02uT%02u:%02u:%02u.%03uZ\",\n\"paused\":%s,\"integer_scale\":%d,\"ntsc_frame_lock\":%s,\n"
       "\"pause_scope\":\"paused is the frontend pause state; native SNES Start pause is separate and its CPU context is recorded.\",\n"
       "\"hash_notes\":\"Image hashes use standard FNV-1a64 offset cbf29ce484222325; legacy runtime hashes retain offset 14650fb0739d0383.\",\n"
       "\"state_alignment\":\"Image is the last completed display; current CPU state may be in the following raster. Capturing advances no emulated time.\",\n"
       "\"ram_notes\":\"Raw UI scene can persist during transitions; scene alone does not prove active gameplay. Fixed positions are signed16.16; actor/resource fields require availability flags; armor may contain death sentinel.\",\n"
       "\"current\":",width,height,file_hash,fullscreen?"true":"false",fw,fh,frame_hash,state.displayed_frame,
       (unsigned)utc.wYear,(unsigned)utc.wMonth,(unsigned)utc.wDay,(unsigned)utc.wHour,(unsigned)utc.wMinute,(unsigned)utc.wSecond,(unsigned)utc.wMilliseconds,
       g_paused?"true":"false",g_frontend_settings.integer_scale,g_frontend_settings.ntsc_frame_lock?"true":"false")<0||
       !capture_sample_json(file,&state))goto cleanup;
    if(fprintf(file,
       ",\n\"host\":{\"qpc_frequency\":%lld,\"timer_ticks\":%" PRIu64 ",\"skipped_deadlines\":%" PRIu64 ",\"resyncs\":%" PRIu64
       ",\"last_emulation_fps_estimate\":%.6f,\"last_presented_fps_estimate\":%.6f,\"recent_count\":%u,\"recent_capacity\":%u,"
       "\"work_mean_ms\":%.6f,\"work_p95_ms\":%.6f,\"work_max_ms\":%.6f},\n"
       "\"audio\":{\"open\":%s,\"native_frames_queued\":%" PRIu64 ",\"underruns\":%" PRIu64 ",\"queue_failures\":%" PRIu64
       ",\"recoveries\":%" PRIu64 ",\"queue_depth_frames\":%u,\"device_sample_rate\":%d,\"playback_ratio\":%.9g},\n\"recent_frames\":[\n",
       (long long)g_qpc_frequency.QuadPart,g_pacing_timer_ticks,g_pacing_skipped_deadlines,g_pacing_resyncs,g_audio_host_fps,g_presented_host_fps,
       count,JUNGLE_CAPTURE_HISTORY,count?sum/count:0.0,count?sorted[(count*95u+99u)/100u-1u]:0.0,count?sorted[count-1u]:0.0,
       jungle_audio_output_is_open(&g_audio_output)?"true":"false",audio.native_frames_queued,audio.underruns,audio.queue_failures,audio.queue_recoveries,
       audio.queue_depth_frames,audio.device_sample_rate,(double)audio.playback_ratio)<0)goto cleanup;
    for(i=0;i<count;i++){
        const JungleCaptureTrace *entry=&g_capture_history[(first+i)%JUNGLE_CAPTURE_HISTORY];
        if(fprintf(file,"%s{\"qpc\":%" PRIu64 ",\"work_ms\":%.6f,\"input\":%u,\"success\":%s,\"skipped_deadlines\":%" PRIu64 ",\"resyncs\":%" PRIu64 ",\"state\":",
           i?",\n":"",entry->qpc,entry->work_ms,entry->input,entry->success?"true":"false",entry->skipped_deadlines,entry->resyncs)<0||
           !capture_sample_json(file,&entry->state)||fputc('}',file)==EOF)goto cleanup;
    }
    if(fprintf(file,"\n],\n\"runtime\":%s\n}\n",runtime)<0||ferror(file))goto cleanup;
    ok=1;
cleanup:
    if(file&&fclose(file)!=0)ok=0;
    if(!ok)DeleteFileW(path);
    free(runtime);return ok?1:2;
}
