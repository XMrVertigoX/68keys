cmake_minimum_required(VERSION 3.15)

project(mf68)

include(commands.cmake)

set(CPU_OPTIONS -mthumb -mcpu=cortex-m0)
set(OPTIMIZATION_OPTIONS -Os)

add_compile_options(
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-fdata-sections
	-ffunction-sections
	-fno-exceptions
	-fno-rtti)

add_link_options(
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS})

add_subdirectory(lib)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/matrix.cpp
	src/board_init.c
	src/usb_callbacks.c)
target_link_libraries(${PROJECT_NAME}
	asf
	rtt)
target_link_options(${PROJECT_NAME}
	PRIVATE
	-Wl,--gc-sections
	-Wl,--entry=Reset_Handler
	-Wl,--script=${CMAKE_CURRENT_LIST_DIR}/samd21g18au.ld)
