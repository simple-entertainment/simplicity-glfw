cmake_minimum_required(VERSION 3.2)

include(../simplicity/simplicity-common.cmake)

# Project
#########################
project(simplicity-glfw)

# Project Dependencies
#########################

# GLEW
set(GLEW_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/lib/libGLEW.a)
set(GLEW32_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/lib/glew32.lib)
add_custom_command(
	OUTPUT ${GLEW_PATH}
	COMMAND make extensions
	COMMAND make
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew
	COMMENT "Building GL Extension Wrangler")
add_custom_target(glew-glfw DEPENDS ${GLEW_PATH})

# GLFW
add_subdirectory(lib/glfw)

# Source
#########################
file(GLOB_RECURSE SRC_FILES src/main/c++/*.cpp src/main/c++/*.h)

# Target
#########################
add_library(simplicity-glfw ${SIMPLE_LINK_TYPE} ${SRC_FILES})
target_include_directories(simplicity-glfw PUBLIC src/main/c++)

# Target Dependencies
#########################

# GLEW
add_dependencies(simplicity-glfw glew-glfw)
target_include_directories(simplicity-glfw PUBLIC lib/glew/include)
IF(WIN32)
    target_link_libraries(simplicity-glfw ${GLEW32_PATH})
ENDIF(WIN32)
IF(UNIX)
	target_link_libraries(simplicity-glfw ${GLEW_PATH})
ENDIF(UNIX)

# GLFW
target_include_directories(simplicity-glfw PUBLIC lib/glfw/include)
target_link_libraries(simplicity-glfw glfw)
target_link_libraries(simplicity-glfw glfw ${GLFW_LIBRARIES})

# Simplicity
target_link_libraries(simplicity-glfw simplicity)
