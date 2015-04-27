cmake_minimum_required(VERSION 2.6)
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

if(NOT RELEASE)
	set(TARGET_NAME hPyFrameworkd)
else()
	set(TARGET_NAME hPyFramework)
endif()

add_library(${TARGET_NAME} bindir ${HPYFRAMEWORK_SOURCES})

set(BINDIR "${CURRENT_DIR}/libs/RoboCORE_${ROBOCORE_VERSION}_${ROBOCORE_TYPE}")
add_custom_command(OUTPUT bindir COMMAND mkdir -p ${BINDIR})
set_target_properties(${TARGET_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${BINDIR})
