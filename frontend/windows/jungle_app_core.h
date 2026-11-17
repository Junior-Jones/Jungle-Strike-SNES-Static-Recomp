#ifndef JUNGLE_APP_CORE_H
#define JUNGLE_APP_CORE_H

#include "jungle_static_recomp.h"
#include "jungle/jungle_static_core.h"

#ifdef __cplusplus
extern "C" {
#endif

int jungle_recomp_write_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity);
int jungle_recomp_append_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity);
int jungle_recomp_capture_sample(const JungleStrikeRecomp *instance,JungleCoreCaptureSample *out);
size_t jungle_recomp_diagnostic_json_size(const JungleStrikeRecomp *instance);
int jungle_recomp_diagnostic_json(const JungleStrikeRecomp *instance,void *dst,size_t size);

#ifdef __cplusplus
}
#endif
#endif
