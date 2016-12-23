# Project Name
Piano using beaglebone without SO

# Overview
This is just a project I did just to exercise and practice the concepts of embedded linux and programming, it does not have any professional purpose, but with small changes can be much more robust and more useful. Because it is a project without an operating system, it is very difficult to understand, but I did the same project using embedded linux: https://github.com/emanuel36/piano_linux_embedded

## Platform
Beaglebone

## Architecture
ARM - 32 bits

## Compilation
- make debug
- note: The makefile is programmed to compile on the pc (x86) and send the binary to the linux root directory.

## Usage
- Connect the components according to the mapping of the GPIOs that are in the gpioLED.h file.
- Run the binary (EMANUEL.bin)

## Components
- Buttons
- LEDs
- Buzzer
