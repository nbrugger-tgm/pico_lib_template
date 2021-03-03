include(settings.cmake)
IF(NOT ${RUN_LOCAL})
    #set(PICO_PLATFORM host)
    include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
ENDIF()

cmake_minimum_required(VERSION 3.13)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FOLDER CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
add_executable(
        ${name}
        ${SRC_FOLDER}
        ${mainFile}
)
IF(${RUN_LOCAL})
    #set(PICO_PLATFORM host)
    add_compile_definitions(runLocal=true)
    set(CXX_STANDARD 23)
    set(C_STANDARD 11)
ELSE()
    add_compile_definitions(runLocal=false)
    pico_sdk_init()
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
ENDIF()


