# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/luis/pi/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(uart_test1 C CXX ASM)

set(PICO_EXAMPLES_PATH ${SOURCE_DIR})

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(uart_test1 uart_test1.cpp )

# pico_set_program_name(uart_test1 "uart_test1")
# pico_set_program_version(uart_test1 "0.1")

# pico_enable_stdio_uart(uart_test1 1)
# pico_enable_stdio_usb(uart_test1 0)

# Add the standard library to the build
target_link_libraries(uart_test1 pico_stdlib)

# # Add any user requested libraries
# target_link_libraries(uart_test1
#         hardware_spi
#         hardware_pio
#         hardware_clocks
#         )

pico_add_extra_outputs(uart_test1)

