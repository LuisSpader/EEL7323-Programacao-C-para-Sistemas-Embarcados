cmake_minimum_required(VERSION 3.13)
file(GLOB projeto_C CONFIGURE_DEPENDS "*.h" "*.cpp")

project(projeto_C VERSION 0.1.0)

include(CTest)

include(pico_sdk_import.cmake)
#project(projeto_C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})
pico_sdk_init()

enable_testing()

#add_executable(cpp_ar_condicionado_project dhc.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries( pico_stdlib hardware_uart hardware_adc)

pico_enable_stdio_usb(projeto_C 1)
pico_enable_stdio_uart(projeto_C 1)
pico_add_extra_outputs(projeto_C)


