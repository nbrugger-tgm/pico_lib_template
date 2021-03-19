include(settings.cmake)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

cmake_minimum_required(VERSION 3.13)
project(${lib_name} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(src)
target_include_directories(${lib_name}
        PUBLIC src
)
add_subdirectory(example)
target_link_libraries(${lib_name}
        pico_stdlib
)
target_link_libraries(${example_name}
        pico_stdlib
)
