cmake_minimum_required(VERSION 3.13)
project(cpp_ar_condicionado_project VERSION 0.1.0)

include(CTest)

include(pico_sdk_import.cmake)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

enable_testing()

add_executable(cpp_ar_condicionado_project dhc.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

pico_enable_stdio_usb(test 1)
pico_enable_stdio_uart(test 1)
pico_add_extra_outputs(test)
target_link_libraries(test pico_stdlib)
