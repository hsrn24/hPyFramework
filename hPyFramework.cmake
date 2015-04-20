set(CMAKE_SYSTEM_NAME "Generic")
get_filename_component(CURRENT_LIB_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

include_directories("${CURRENT_LIB_DIR}/include/")

set(HPYFRAMEWORK_SOURCES
	${CURRENT_LIB_DIR}/src/gen.h
	${CURRENT_LIB_DIR}/src/gen.c
	${CURRENT_LIB_DIR}/src/gen.cpp
	${CURRENT_LIB_DIR}/src/hPyFramework.cpp)

# add_custom_command(OUTPUT ${PY_GENERATED}
	# COMMAND python2.7 ${HPYTHON_PATH}/tools/makeqstrdata.py ${CURRENT_LIB_DIR}/src/qstrdefs > ${PY_GENERATED}
  # DEPENDS ${CURRENT_LIB_DIR}/src/qstrdefs)
