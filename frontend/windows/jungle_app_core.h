#ifndef JUNGLE_APP_CORE_H
#define JUNGLE_APP_CORE_H

#include "jungle_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

int jungle_recomp_write_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity);
int jungle_recomp_append_diagnostic_log(
    const JungleStrikeRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity);

#ifdef __cplusplus
}
#endif
#endif
