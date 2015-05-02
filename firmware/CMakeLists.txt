cmake_minimum_required(VERSION 2.6)
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

project(hPyFramework C CXX ASM)

if(NOT HFRAMEWORK_PATH)
	set(HFRAMEWORK_PATH "${CURRENT_DIR}/../")
endif()

include(${HFRAMEWORK_PATH}/hFramework.cmake)

add_component_lib(hPyFramework "")
add_component_lib(hPython "${HPYTHON_PATH}")
add_component_lib(hPySensors "${HSENSORS_PATH}")
add_component_lib(hSensors "${HSENSORS_PATH}")

add_hexecutable(hPyFramework main.cpp)
