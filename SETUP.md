# Setup
## Requirements

* cmake > 3.14
* make
* gcc
* openssl
* libssl-dev
* doxygen
* libusb  (might also be called: `libusb-1.0` `libusb-1.0-0` `libusb-1.0-dev` `libusb-1.0-0-dev` or `libusb-dev`)

## PICO stdlib setup 
> **do this if you get a 'PICO_SDK_PATH not set'**

You will need a folder to permanently store the PICO SDK. In this tutorial we assume its `/lib/mcu/pico`

> Tested in:
> * Ubuntu
> * WSL Ubuntu


This script will install `picotool` and `pico-sdk`. Make sure to run it as root OR make `/lib/mcu/pico` public `rwx`
```bash
export PICO_SDK_PATH=/lib/mcu/pico
git clone https://github.com/raspberrypi/pico-sdk $PICO_SDK_PATH
echo export PICO_SDK_PATH=$PICO_SDK_PATH >> ~/.bashrc
git clone https://github.com/raspberrypi/picotool /tmp/picotool
cd /tmp/picotool
mkdir build
cd build
cmake ..
make
cp picotool /usr/bin/picotool
cd ../..
rm picotool -r
```