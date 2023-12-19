cmake_minimum_required(VERSION 3.15)
project(egg)

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
add_compile_options(-W4)

# find_package(SDL2 REQUIRED CONFIG)
# find_package(SDL2_image REQUIRED CONFIG)
# find_package(SDL2_ttf REQUIRED CONFIG)

file(GLOB_RECURSE SOURCES "src/*.cc")
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

# Include external dependencies
add_subdirectory( vendor )

# target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)
# target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image-static)
# target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_ttf::SDL2_ttf)