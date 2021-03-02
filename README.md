# Raspberry PICO Project template

*This project uses conventional commits and the `cz` command line utility*

## Requirements

* cmake > 3.14
* make
* gcc
* openssl
* libssl-dev
* doxygen

## PICO Setup (only needed once)

You will need a folder to permanently store the PICO SDK. In this tutorial we assume its `/lib/mcu/pico`

> Tested in:
> * Ubuntu
> * WSL Ubuntu

```bash
clone https://github.com/raspberrypi/pico-sdk /lib/mcu/pico
echo export PICO_SDK_PATH=/lib/mcu/pico > ~/.bashrc
clone https://github.com/raspberrypi/picotool /tmp/picotool
cd /tmp/picotool
mkdir build
cd build
cmake ..
make
cp picotool /usr/bin/picotool
```

## Project Structure

For use with **CLion**

* `SETTINGS > Build, Execution, Deployment > CMake > Debug` 
  * Build Type: **Release**
  * (*wsl only*) Environment: *PICO_SDK_PATH=/lib/mcu/pico*

### Code

`src` : Sourcecode just belongs here
`settings.cmake` : Change project build settings, include libraries
`src/pins.h` : Define all used pins in here
`src/main.cpp` : The main execution point (can be changed in settings.cmake)
`compile.sh` : compiles the program into `elf`,`bin` and `uf2` for drag and drop
`flash.sh` : compiles & flashes the attached pico 
`out` : contains the binaries after compiling

