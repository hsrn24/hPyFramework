set(CMAKE_SYSTEM_NAME "Generic")
get_filename_component(CURRENT_LIB_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

include_directories("${CURRENT_LIB_DIR}/include/")
include_directories("${CURRENT_LIB_DIR}/micropython/")
include_directories("${CURRENT_LIB_DIR}/micropython-port/")

include(${CURRENT_LIB_DIR}/include)

set(HPYFRAMEWORK_SOURCES ${CURRENT_LIB_DIR}/src/hPyFramework.cpp)

set(PY_GENERATED qstrdefs.generated.h)

add_custom_command(OUTPUT ${PY_GENERATED}
  COMMAND python2.7 qstrdefs > ${PY_GENERATED}
  DEPENDS qstrdefs)
