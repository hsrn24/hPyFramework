cmake_minimum_required(VERSION 2.6)
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

project(hPyFramework C CXX ASM)

if(NOT HFRAMEWORK_PATH)
	set(HFRAMEWORK_PATH "${CURRENT_DIR}/../")
endif()

include(${HFRAMEWORK_PATH}/hFramework.cmake)

add_component_lib(hPyFramework "")
add_component_lib(hPython "../../hPython")
add_component_lib(hPySensors "../../robocore-sensors")
add_component_lib(hSensors "../../robocore-sensors")

add_hexecutable(hPyFramework main.cpp)
