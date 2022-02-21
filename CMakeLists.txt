cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
 
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
 
pico_sdk_init()
project(blink)
add_executable(blink blink.c)
 
# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(blink pico_stdlib)
  
# create map/bin/hex file etc.
pico_add_extra_outputs(blink)