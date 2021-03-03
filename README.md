# Raspberry PICO Project template

*This project uses conventional commits and the `cz` command line utility*

> This template supports compilation for Linux so you can run your code on your host (example at the bottom)

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
cd ..
rm picotool -r
```

## Project Structure

For use with **CLion**

* `SETTINGS > Build, Execution, Deployment > CMake > Debug` 
  * Build Type: **Release**
  * (*wsl only*) Environment: *PICO_SDK_PATH=/lib/mcu/pico*

### Code

- `src` : Sourcecode just belongs here
- `settings.cmake` : Change project build settings, include libraries
- `src/pins.h` : Define all used pins in here
- `src/main.cpp` : The main execution point (can be changed in settings.cmake)
- `compile.sh` : compiles the program into `elf`,`bin` and `uf2` for drag and drop
- `flash.sh` : compiles & flashes the attached pico 
- `out` : contains the binaries after compiling

## Run on Host

This repo is configured to be compiled for Linux AND the Raspberry PICO.

**Warning:** Its not perfect. The MCU behaviours (GPIO) are NOT emulated, but you can replace them by host specific code

`printf()` is available for host c++ and Pico

### Tutorial

1. Change `RUN_LOCAL` (in `settings.cmake`) to `1`
2. Exclude *ALL* pico/host specific headers (example bellow)

```cpp
#if runLocal
	#include "unistd.h"      //host include
#else
	#include "pico/stdlib.h"  //pico include
	#include "hardware/i2c"   //same
#endif
```

3. Replace host/pico specific code

```cpp
#if runLocal
    sleep(time/1000); //host code
#else
    sleep_ms(time); //pico code
#endif
```

4. build the project for linux `./rebuild.sh`
5. Run the binary `./build/{name_configured_in_settings}`

