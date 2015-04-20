cmake_minimum_required (VERSION 2.6)
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

project(hPyFramework C CXX ASM)

option(DEBUG "Enable debug informations" OFF)

if(NOT HFRAMEWORK_PATH)
	set(HFRAMEWORK_PATH ${CURRENT_DIR}/../hFramework/)
endif()

if(NOT HPYTHON_PATH)
	set(HPYTHON_PATH ${CURRENT_DIR}/../hPython/)
endif()

set(debug_flags "")

if(DEBUG)
	set(debug_flags "${debug_flags} -DDEBUG")
endif()

include(${HFRAMEWORK_PATH}/robocore_common.cmake)

include_directories("${CURRENT_DIR}/include/")
include_directories("${HPYTHON_PATH}/include/")

add_library(hPyFramework
	src/hPyFramework.cpp)
