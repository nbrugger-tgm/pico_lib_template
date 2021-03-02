SET(name test)
SET(display_name "Test Programm")
SET(version "0.0.0")
SET(desc "This program is just for testing and bliks the LED")
SET(url "https://github.com/nbrugger")
SET(mainFile src/main.cpp)
SET(RUN_LOCAL 0)
SET(usb 1)
SET(uart 1)
SET(libs
        #hardware_i2c
        #hardware_adc
        #hardware_irq
        #hardware_rtc
        #hardware_spi
        #hardware_timer
        #hardware_uart
        #pico_multicore
        #pico_time
        #tinyusb_device
        #tinyusb_host
)