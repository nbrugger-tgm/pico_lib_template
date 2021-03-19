#!/bin/bash

if [ -n "$PICO_SDK_PATH"] && [ ! -d "$PICO_SDK_PATH" ]
then
	echo "environment variable PICO_SDK_PATH not found. Please setup the pico-sdk regarding to the README.md"
	exit 1
fi

mkdir build -p
cd build
cmake ..
make
[ -f ../out ] && rm ../out/*
mkdir ../out -p
cp ./example/*.elf ../out/example.elf
cp ./example/*.uf2 ../out/example.uf2
cp ./example/*.bin ../out/example.bin
cp ./src/*.a ../out/
cd ..