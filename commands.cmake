# cmake script for generating binary and hex format and for flashing

add_custom_command(OUTPUT ${PROJECT_NAME}.hex
	DEPENDS ${PROJECT_NAME}
	COMMAND ${CMAKE_OBJCOPY} -Oihex ${PROJECT_NAME} ${PROJECT_NAME}.hex)
add_custom_command(OUTPUT ${PROJECT_NAME}.bin
	DEPENDS ${PROJECT_NAME}
	COMMAND ${CMAKE_OBJCOPY} -Obinary ${PROJECT_NAME} ${PROJECT_NAME}.bin)
add_custom_command(OUTPUT ${PROJECT_NAME}.lst
	DEPENDS ${PROJECT_NAME}
	COMMAND ${CMAKE_OBJDUMP} -S ${PROJECT_NAME} > ${PROJECT_NAME}.lst)
add_custom_command(OUTPUT ${PROJECT_NAME}.sym
	DEPENDS ${PROJECT_NAME}
	COMMAND ${CMAKE_NM} -C -l -n -S ${PROJECT_NAME} > ${PROJECT_NAME}.sym)
add_custom_command(OUTPUT ${PROJECT_NAME}.uf2
	DEPENDS ${PROJECT_NAME}.hex
	COMMAND python2 ${CMAKE_CURRENT_LIST_DIR}/tools/uf2/utils/uf2conv.py -c -o ${PROJECT_NAME}.uf2 ${PROJECT_NAME}.hex)

add_custom_target(hex
	DEPENDS ${PROJECT_NAME}.hex)
add_custom_target(bin
	DEPENDS ${PROJECT_NAME}.bin)
add_custom_target(lst
	DEPENDS ${PROJECT_NAME}.lst)
add_custom_target(sym
	DEPENDS ${PROJECT_NAME}.sym)
add_custom_target(uf2
	DEPENDS ${PROJECT_NAME}.uf2)
