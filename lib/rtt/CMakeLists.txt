add_library(rtt STATIC
	src/SEGGER_RTT.c
	src/SEGGER_RTT_printf.c)
target_include_directories(rtt
	PUBLIC
	inc)
