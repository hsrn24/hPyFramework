set(CMAKE_SYSTEM_NAME "Generic")
get_filename_component(CURRENT_LIB_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

include_directories("${CURRENT_LIB_DIR}/include/")
include_directories("${CURRENT_LIB_DIR}/micropython/")
include_directories("${CURRENT_LIB_DIR}/micropython-port/")
include_directories("${CMAKE_SOURCE_DIR}")

include(${CURRENT_LIB_DIR}/include)

add_source_files(${CURRENT_LIB_DIR}/src/hPyFramework.cpp)
