cmake_minimum_required(VERSION 3.10)

project(avr VERSION 1.0)

set(MCU atmega328p)
set(PROG demo_prog)
set(WARN "-Wall -Wextra -pedantic")

set(CMAKE_C_COMPILER "avr-gcc")
set(CMAKE_C_FLAGS "-mmcu=${MCU} ${WARN}")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "avr-g++")
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} ${WARN}")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

add_compile_definitions(${PROG} PUBLIC F_CPU=16000000)

include_directories(./)
include_directories(./AtmegaXX-I2C-Library)

add_executable(${PROG}
	./main.cpp
	./SSD1306.c
	./AtmegaXX-I2C-Library/i2c.c)

add_custom_command(
	TARGET ${PROG} POST_BUILD
	COMMAND avr-size -A ${PROG}
	VERBATIM)

add_custom_target(flash avrdude -p ${MCU} -c usbtiny -U flash:w:${PROG}:e)
