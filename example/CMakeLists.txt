add_executable(${example_name}
    main.cpp
)
target_link_libraries(${example_name}
    ${lib_name}
)

pico_set_program_description(${example_name} ${desc})
pico_set_program_version(${example_name} ${version})
pico_set_program_url(${example_name} ${url})
pico_set_program_name(${example_name} ${example_name})
pico_set_program_url(${example_name} ${url})
pico_enable_stdio_usb(${example_name} 1)
pico_enable_stdio_uart(${example_name} 1)
pico_add_extra_outputs(${example_name})