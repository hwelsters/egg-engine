cmake_minimum_required(VERSION 3.15)
project(egg)

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES "src/*.cc")
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/eggpch.h)

# Include external dependencies
add_subdirectory( vendor )