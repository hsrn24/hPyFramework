set(CMAKE_SYSTEM_NAME "Generic")
get_filename_component(CURRENT_LIB_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

include_directories("${CURRENT_LIB_DIR}/gen/")

set(HPYFRAMEWORK_SOURCES
	${CURRENT_LIB_DIR}/gen/gen_hPyFramework.h
	${CURRENT_LIB_DIR}/gen/gen_hPyFramework.c
	${CURRENT_LIB_DIR}/gen/gen_hPyFramework.cpp)

set(EXPORTS_FILE ${CURRENT_LIB_DIR}/src/exports)

add_custom_command(OUTPUT ${CURRENT_LIB_DIR}/gen/gen_hPyFramework.h
	COMMAND python2.7 ${CURRENT_LIB_DIR}/mpy-gen/generate.py --config ${EXPORTS_FILE} --outdir ${CURRENT_LIB_DIR}/gen
	DEPENDS ${EXPORTS_FILE})
