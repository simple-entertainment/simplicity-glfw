cmake_minimum_required(VERSION 3.2)

include(../simplicity/simplicity-common.cmake)

# Project
#########################
project(simplicity-glfw)

# Project Dependencies
#########################

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

# GLFW
target_include_directories(simplicity-glfw PUBLIC lib/glfw/include)
target_link_libraries(simplicity-glfw glfw)
target_link_libraries(simplicity-glfw glfw ${GLFW_LIBRARIES})

# Simplicity
target_link_libraries(simplicity-glfw simplicity)
