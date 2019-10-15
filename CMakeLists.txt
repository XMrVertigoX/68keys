cmake_minimum_required(VERSION 3.15)

project(mf68)

set(CPU_OPTIONS -mthumb -mcpu=cortex-m0)
set(OPTIMIZATION_OPTIONS -Og -g)

add_compile_options(
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-fdata-sections
	-ffunction-sections
	-fno-exceptions
	-fno-rtti
	-Werror=implicit-function-declaration)

add_link_options(
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS})

add_subdirectory(lib)

add_executable(${PROJECT_NAME}.elf
	src/main.cpp
	src/matrix.cpp
	src/board_init.cpp
	src/usb_callbacks.cpp)
target_link_libraries(${PROJECT_NAME}.elf
	asf
	rtt)
target_link_options(${PROJECT_NAME}.elf
	PRIVATE
	-Wl,--gc-sections
	-Wl,--entry=Reset_Handler
	-Wl,--script=${CMAKE_CURRENT_LIST_DIR}/samd21g18au.ld)

add_custom_target(${PROJECT_NAME}.hex ALL
	COMMAND ${CMAKE_OBJCOPY} -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(${PROJECT_NAME}.bin ALL
	COMMAND ${CMAKE_OBJCOPY} -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(${PROJECT_NAME}.lst ALL
	COMMAND ${CMAKE_OBJDUMP} -S ${PROJECT_NAME}.elf > ${PROJECT_NAME}.lst
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(${PROJECT_NAME}.sym ALL
	COMMAND ${CMAKE_NM} -C -l -n -S ${PROJECT_NAME}.elf > ${PROJECT_NAME}.sym
	DEPENDS ${PROJECT_NAME}.elf)
add_custom_target(${PROJECT_NAME}.uf2 ALL
	COMMAND python2 ${CMAKE_CURRENT_LIST_DIR}/tools/uf2/utils/uf2conv.py -c -o ${PROJECT_NAME}.uf2 ${PROJECT_NAME}.hex
	DEPENDS ${PROJECT_NAME}.hex)
