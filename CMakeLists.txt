cmake_minimum_required(VERSION 3.15)

project(mf68)

# Shared options
set(CPU_OPTIONS -mthumb -mcpu=cortex-m0)
set(OPTIMIZATION_OPTIONS -Os)


# #############################################################################
# Advanced Software Framework (ASF)

add_library(asf STATIC
	$ENV{ASF}/common/services/sleepmgr/samd/sleepmgr.c
	$ENV{ASF}/common/services/usb/class/hid/device/kbd/udi_hid_kbd.c
	$ENV{ASF}/common/services/usb/class/hid/device/kbd/udi_hid_kbd_desc.c
	$ENV{ASF}/common/services/usb/class/hid/device/udi_hid.c
	$ENV{ASF}/common/services/usb/udc/udc.c
	$ENV{ASF}/common/utils/interrupt/interrupt_sam_nvic.c
	$ENV{ASF}/common2/services/delay/sam0/systick_counter.c
	$ENV{ASF}/sam0/drivers/extint/extint_callback.c
	$ENV{ASF}/sam0/drivers/extint/extint_sam_d_r_h/extint.c
	$ENV{ASF}/sam0/drivers/port/port.c
	$ENV{ASF}/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c
	$ENV{ASF}/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c
	$ENV{ASF}/sam0/drivers/system/interrupt/system_interrupt.c
	$ENV{ASF}/sam0/drivers/system/pinmux/pinmux.c
	$ENV{ASF}/sam0/drivers/system/system.c
	$ENV{ASF}/sam0/drivers/tc/tc_interrupt.c
	$ENV{ASF}/sam0/drivers/tc/tc_sam_d_r_h/tc.c
	$ENV{ASF}/sam0/drivers/tcc/tcc.c
	$ENV{ASF}/sam0/drivers/tcc/tcc_callback.c
	$ENV{ASF}/sam0/drivers/usb/stack_interface/usb_device_udd.c
	$ENV{ASF}/sam0/drivers/usb/stack_interface/usb_dual.c
	$ENV{ASF}/sam0/drivers/usb/usb_sam_d_r/usb.c
	$ENV{ASF}/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.c
	$ENV{ASF}/sam0/utils/cmsis/samd21/source/system_samd21.c
	$ENV{ASF}/sam0/utils/syscalls/gcc/syscalls.c)
target_include_directories(asf
	PUBLIC
	$ENV{ASF}/common/boards
	$ENV{ASF}/common/services/sleepmgr
	$ENV{ASF}/common/services/usb
	$ENV{ASF}/common/services/usb/class/hid
	$ENV{ASF}/common/services/usb/class/hid/device
	$ENV{ASF}/common/services/usb/class/hid/device/kbd
	$ENV{ASF}/common/services/usb/udc
	$ENV{ASF}/common/utils
	$ENV{ASF}/common2/services/delay
	$ENV{ASF}/sam0/drivers/extint
	$ENV{ASF}/sam0/drivers/extint/extint_sam_d_r_h
	$ENV{ASF}/sam0/drivers/port
	$ENV{ASF}/sam0/drivers/system
	$ENV{ASF}/sam0/drivers/system/clock
	$ENV{ASF}/sam0/drivers/system/clock/clock_samd21_r21_da_ha1
	$ENV{ASF}/sam0/drivers/system/interrupt
	$ENV{ASF}/sam0/drivers/system/interrupt/system_interrupt_samd21
	$ENV{ASF}/sam0/drivers/system/pinmux
	$ENV{ASF}/sam0/drivers/system/power
	$ENV{ASF}/sam0/drivers/system/power/power_sam_d_r_h
	$ENV{ASF}/sam0/drivers/system/reset
	$ENV{ASF}/sam0/drivers/system/reset/reset_sam_d_r_h
	$ENV{ASF}/sam0/drivers/tc
	$ENV{ASF}/sam0/drivers/tcc
	$ENV{ASF}/sam0/drivers/usb
	$ENV{ASF}/sam0/drivers/usb/usb_sam_d_r
	$ENV{ASF}/sam0/utils
	$ENV{ASF}/sam0/utils/cmsis/samd21/include
	$ENV{ASF}/sam0/utils/cmsis/samd21/source
	$ENV{ASF}/sam0/utils/header_files
	$ENV{ASF}/sam0/utils/preprocessor
	$ENV{ASF}/thirdparty/CMSIS/Include)
target_include_directories(asf
	PUBLIC
	src/config)
target_compile_definitions(asf
	PUBLIC
	__SAMD21G18AU__
	BOARD=USER_BOARD
	EXTINT_CALLBACK_MODE=true
	SYSTICK_MODE
	TC_ASYNC=true
	TCC_ASYNC=true)
target_compile_options(asf
	PRIVATE
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-fdata-sections
	-ffunction-sections)


# #############################################################################
# SEGGER Real Time Terminal (RTT)

add_library(rtt STATIC
	lib/RTT/SEGGER_RTT.c
	lib/RTT/SEGGER_RTT_printf.c)
target_include_directories(rtt
	PUBLIC
	lib/RTT)
target_compile_options(rtt
	PRIVATE
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-fdata-sections
	-ffunction-sections)


# #############################################################################
# Project

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/matrix.cpp
	src/board_init.c
	src/usb_callbacks.c)
target_compile_options(${PROJECT_NAME}
	PRIVATE
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-fdata-sections
	-ffunction-sections
	-fno-exceptions
	-fno-rtti)
target_link_libraries(${PROJECT_NAME} asf)
target_link_libraries(${PROJECT_NAME} rtt)
target_link_options(${PROJECT_NAME}
	PRIVATE
	${CPU_OPTIONS}
	${OPTIMIZATION_OPTIONS}
	-Wl,--entry=Reset_Handler
	-Wl,--gc-sections
	-Wl,--script=${CMAKE_CURRENT_LIST_DIR}/samd21g18au.ld)

include(commands.cmake)
