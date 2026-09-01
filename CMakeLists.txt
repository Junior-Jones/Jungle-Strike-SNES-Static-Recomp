cmake_minimum_required(VERSION 3.20)
project(JungleStrikeStaticRecomp VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("${CMAKE_CURRENT_SOURCE_DIR}/generated/scpu/static_core_compact_sources.cmake")

add_library(jungle_static_core STATIC
  runtime/v09c_cpu_support.c
  runtime/v06c_bus.c
  runtime/v09c_scheduler.c
  runtime/v09c_bus.c
  runtime/v09c_dma.c
  runtime/v09c_ppu.c
  runtime/v10_40_machine.c
  runtime/v10_40_dispatch_bridge.c
  runtime/v10_40_core_api.c
  runtime/v10_40_status.c
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
