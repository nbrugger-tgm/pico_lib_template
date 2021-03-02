include(settings.cmake)
cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
IF(${RUN_LOCAL})
    set(PICO_PLATFORM host)
ENDIF()
pico_sdk_init()
add_executable(
    ${name}
    ${mainFile}
)
pico_set_program_name(${name} ${display_name})
pico_set_program_description(${name} ${desc})
pico_set_program_version(${name} ${version})
pico_set_program_url(${name} ${url})
pico_enable_stdio_usb(${name} ${usb})
pico_enable_stdio_uart(${name} ${uart})
pico_add_extra_outputs(${name})
target_link_libraries(${name}
        pico_stdlib
        ${libs}
)