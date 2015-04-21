set(CMAKE_SYSTEM_NAME "Generic")
get_filename_component(CURRENT_LIB_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

include_directories("${CURRENT_LIB_DIR}/include/")

set(HPYFRAMEWORK_SOURCES
	${CURRENT_LIB_DIR}/src/hPyFramework.h
	${CURRENT_LIB_DIR}/src/hPyFramework.c
	${CURRENT_LIB_DIR}/src/hPyFramework.cpp)

add_custom_command(OUTPUT ${HPYFRAMEWORK_SOURCES}
	COMMAND python2.7 ${CURRENT_LIB_DIR}/tools/generate.py
  DEPENDS ${CURRENT_LIB_DIR}/src/exports)
