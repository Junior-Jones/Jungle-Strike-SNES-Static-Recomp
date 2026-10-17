cmake_minimum_required(VERSION 3.20)
project(JungleStrikeStaticRecomp VERSION 1.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("${CMAKE_CURRENT_SOURCE_DIR}/generated/scpu/static_core_compact_sources.cmake")

# Keep the compact base immutable; the ROM-proven Status closure supplies
# additive exact contexts through the canonical public dispatch functions.
set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/generated/scpu/static_core_compact_dispatch.c"
  PROPERTIES COMPILE_DEFINITIONS
  "js_v10_100_scpu_context_known=js_compact_base_context_known;js_static_dispatch_v10_100=js_compact_base_dispatch;js_static_step_v10_100=js_compact_base_step")

add_library(jungle_static_core STATIC
  runtime/v09c_cpu_support.c
  runtime/v06c_bus.c
  runtime/v09c_scheduler.c
  runtime/v09c_bus.c
  runtime/v09c_dma.c
  runtime/v09c_ppu.c
  runtime/v10_40_machine.c
  runtime/v10_40_dispatch_bridge.c
  runtime/status_closure.c
  runtime/v10_40_core_api.c
  runtime/v10_40_status.c
  runtime/widescreen.c
  runtime/v10_40_renderer.c
  runtime/v10_28_renderer.c
  runtime/v10_28_status.c
  runtime/v10_29_renderer.c
  runtime/v10_29_status.c
  runtime/v10_30_renderer.c
  runtime/v10_30_status.c
  runtime/v10_3_cpu_support.c
  runtime/v10_27_cpu_support.c
  runtime/v10_36_cpu_support.c
  runtime/v10_45_cpu_support.c
  runtime/v10_33_dsp.c
  runtime/v10_33_apu.c
  runtime/v10_33_status.c
  runtime/v10_32_status.c
  runtime/v10_31_status.c
  runtime/v10_2_input.c
  runtime/v10_1_status.c
  runtime/v10_2_status.c
  runtime/v10_9_status.c
  runtime/v10_10_status.c
  runtime/v10_11_status.c
  runtime/v10_3_smp.cpp
  ${JUNGLE_COMPACT_SCPU_GENERATED_SOURCES}
)

target_include_directories(jungle_static_core PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/generated/scpu"
  "${CMAKE_CURRENT_SOURCE_DIR}/generated/audio"
)

# Developer-only headless gameplay/visual regression harness.
add_executable(jungle-widescreen-verify EXCLUDE_FROM_ALL tools/widescreen/verify.c)
add_executable(jungle-snapshot-display-test EXCLUDE_FROM_ALL tools/widescreen/snapshot_restore_test.c)
target_link_libraries(jungle-snapshot-display-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-snapshot-display-test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
target_link_libraries(jungle-widescreen-verify PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-widescreen-verify PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-widescreen-checkpoint EXCLUDE_FROM_ALL tools/widescreen/checkpoint.c)
target_link_libraries(jungle-widescreen-checkpoint PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-widescreen-checkpoint PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-widescreen-hud-test EXCLUDE_FROM_ALL tools/widescreen/hud_test.c)
target_link_libraries(jungle-widescreen-hud-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-widescreen-hud-test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-natural-hud-test EXCLUDE_FROM_ALL tools/widescreen/natural_hud_test.c)
target_link_libraries(jungle-natural-hud-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-natural-hud-test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-overlay-audit EXCLUDE_FROM_ALL tools/widescreen/overlay_audit.c)
target_link_libraries(jungle-overlay-audit PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-overlay-audit PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-corner-test EXCLUDE_FROM_ALL tools/widescreen/corner_test.c)
target_link_libraries(jungle-corner-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-corner-test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

add_executable(jungle-edge-weapon-test EXCLUDE_FROM_ALL tools/widescreen/edge_weapon_test.c)
target_link_libraries(jungle-edge-weapon-test PRIVATE jungle_static_core)
add_executable(jungle-display-switch-test EXCLUDE_FROM_ALL tools/widescreen/mode_switch_test.c)
target_link_libraries(jungle-display-switch-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_definitions(jungle-edge-weapon-test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
