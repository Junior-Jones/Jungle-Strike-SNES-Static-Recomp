cmake_minimum_required(VERSION 3.20)
project(JungleStrikeWindowsFrontend LANGUAGES C CXX)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

get_filename_component(JUNGLE_SOURCE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
set(JUNGLE_GAMEPAD_ADAPTER_DIR "${JUNGLE_SOURCE_ROOT}/third_party/jungle-gamepad")

add_subdirectory("${JUNGLE_SOURCE_ROOT}" "${CMAKE_BINARY_DIR}/static-core" EXCLUDE_FROM_ALL)

include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(jungle_sdl
  URL "https://github.com/libsdl-org/SDL/archive/refs/tags/release-3.4.10.zip"
  URL_HASH "SHA256=30DCE54890B17544A35E4521274762016AF6ED59C2183B896EF5E6693E97FB6C"
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(jungle_sdl)
# SDL's supported assertion-filename override keeps build-machine paths out
# of the portable binary while retaining assertions and subsystem behavior.
target_compile_definitions(SDL3-static PRIVATE "SDL_ASSERT_FILE=\"SDL\"")

add_executable(jungle-strike-launcher WIN32
  jungle_launcher_win32.c
  jungle_app_core.c
  launcher_version.rc
  jungle_audio_output_dsound_win32.c
  jungle_audio_resampler.c
  jungle_frontend_settings_win32.c
  ../common/jungle_input_latch.c
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}/jungle_gamepad_input_win32.c"
)

add_executable(jungle-frontend-core-test
  jungle_frontend_core_test.c
  jungle_app_core.c
)
target_include_directories(jungle-frontend-core-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${JUNGLE_SOURCE_ROOT}/include"
)
target_link_libraries(jungle-frontend-core-test PRIVATE jungle_static_core)
target_compile_definitions(jungle-frontend-core-test PRIVATE
  _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(jungle-frontend-core-test PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-frontend-core-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
enable_testing()
add_test(NAME jungle_frontend_core_reset COMMAND jungle-frontend-core-test)

add_executable(jungle-input-contract-test
  ../common/jungle_input_contract_test.c
  ../common/jungle_input_latch.c
)
target_include_directories(jungle-input-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${JUNGLE_SOURCE_ROOT}/include"
)
target_link_libraries(jungle-input-contract-test PRIVATE jungle_static_core)
if(MSVC)
  target_compile_options(jungle-input-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-input-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME jungle_input_contract COMMAND jungle-input-contract-test)

add_executable(jungle-settings-input-contract-test
  jungle_settings_input_contract_test.c
  jungle_frontend_settings_win32.c
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}/jungle_gamepad_input_win32.c"
)
target_include_directories(jungle-settings-input-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${JUNGLE_SOURCE_ROOT}/include"
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}"
)
target_link_libraries(jungle-settings-input-contract-test PRIVATE
  jungle_static_core SDL3::SDL3-static user32 comctl32
)
target_compile_definitions(jungle-settings-input-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(jungle-settings-input-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-settings-input-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME jungle_settings_input_contract
  COMMAND jungle-settings-input-contract-test)

add_executable(jungle-host-audio-route
  "${JUNGLE_SOURCE_ROOT}/tools/audio/jungle_host_audio_route_win32.c"
  jungle_app_core.c
  jungle_audio_output_dsound_win32.c
  jungle_audio_resampler.c
)
target_include_directories(jungle-host-audio-route PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${JUNGLE_SOURCE_ROOT}/include"
)
target_link_libraries(jungle-host-audio-route PRIVATE
  jungle_static_core user32 dsound dxguid winmm
)
target_compile_definitions(jungle-host-audio-route PRIVATE
  WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(jungle-host-audio-route PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-host-audio-route PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()

add_executable(jungle-audio-resampler-test
  jungle_audio_resampler_test.c
  jungle_audio_resampler.c
)
target_include_directories(jungle-audio-resampler-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
)
if(MSVC)
  target_compile_options(jungle-audio-resampler-test PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-audio-resampler-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME jungle_audio_resampler COMMAND jungle-audio-resampler-test)

add_executable(jungle-audio-settings-contract-test
  jungle_audio_settings_contract_test.c
  jungle_audio_output_dsound_win32.c
  jungle_audio_resampler.c
  jungle_app_core.c
)
target_include_directories(jungle-audio-settings-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${JUNGLE_SOURCE_ROOT}/include"
)
target_link_libraries(jungle-audio-settings-contract-test PRIVATE
  jungle_static_core user32 dsound dxguid winmm
)
target_compile_definitions(jungle-audio-settings-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(jungle-audio-settings-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(jungle-audio-settings-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME jungle_audio_settings_contract
  COMMAND jungle-audio-settings-contract-test)
target_include_directories(jungle-strike-launcher PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${JUNGLE_SOURCE_ROOT}/include"
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}"
)
target_link_libraries(jungle-strike-launcher PRIVATE
  jungle_static_core SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm
)
target_compile_definitions(jungle-strike-launcher PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(jungle-strike-launcher PRIVATE
    /W4 /WX /experimental:deterministic
  )
  target_link_options(jungle-strike-launcher PRIVATE
    $<$<CONFIG:Release>:/Brepro>
  )
else()
  target_compile_options(jungle-strike-launcher PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
set_target_properties(jungle-strike-launcher PROPERTIES
  OUTPUT_NAME "Launcher"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release"
)
add_custom_command(TARGET jungle-strike-launcher POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/Rom"
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/Screenshots"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/Rom/Readme.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/Rom/Readme.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/Screenshots/Readme.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/Screenshots/Readme.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/README.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/README.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/VERSION.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/VERSION.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/THIRD-PARTY-NOTICES.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/THIRD-PARTY-NOTICES.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/SDL-LICENSE.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/SDL-LICENSE.txt"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${JUNGLE_SOURCE_ROOT}/SNES9X-LICENSE.txt"
    "$<TARGET_FILE_DIR:jungle-strike-launcher>/SNES9X-LICENSE.txt"
  VERBATIM
)

# Hidden native-window integration check; never opens a visible app.
add_executable(jungle-widescreen-ui-test
  jungle_widescreen_ui_test.c jungle_app_core.c
  jungle_audio_output_dsound_win32.c jungle_audio_resampler.c
  jungle_frontend_settings_win32.c ../common/jungle_input_latch.c
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}/jungle_gamepad_input_win32.c")
target_include_directories(jungle-widescreen-ui-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${JUNGLE_SOURCE_ROOT}/include" "${JUNGLE_GAMEPAD_ADAPTER_DIR}")
target_link_libraries(jungle-widescreen-ui-test PRIVATE jungle_static_core SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm)
target_compile_definitions(jungle-widescreen-ui-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
if(MSVC)
  target_compile_options(jungle-widescreen-ui-test PRIVATE /W4 /WX)
endif()

add_test(NAME jungle_widescreen_ui COMMAND jungle-widescreen-ui-test)

add_executable(jungle-widescreen-presentation-test EXCLUDE_FROM_ALL
  jungle_widescreen_presentation_test.c jungle_app_core.c
  jungle_audio_output_dsound_win32.c jungle_audio_resampler.c
  jungle_frontend_settings_win32.c ../common/jungle_input_latch.c
  "${JUNGLE_GAMEPAD_ADAPTER_DIR}/jungle_gamepad_input_win32.c")
target_include_directories(jungle-widescreen-presentation-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${JUNGLE_SOURCE_ROOT}/include" "${JUNGLE_GAMEPAD_ADAPTER_DIR}")
target_link_libraries(jungle-widescreen-presentation-test PRIVATE jungle_static_core SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm)
target_compile_definitions(jungle-widescreen-presentation-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)

add_executable(jungle-return-domain-test "${JUNGLE_SOURCE_ROOT}/tools/widescreen/return_domain_test.c")
target_link_libraries(jungle-return-domain-test PRIVATE jungle_static_core)
add_test(NAME jungle_return_domain COMMAND jungle-return-domain-test)
