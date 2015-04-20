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

include(${HFRAMEWORK_PATH}/robocore_common.cmake)

include(${HPYTHON_PATH}/hPython.cmake)
include(${CURRENT_DIR}/hPyFramework.cmake)

add_library(hPyFramework ${HPYFRAMEWORK_SOURCES})
