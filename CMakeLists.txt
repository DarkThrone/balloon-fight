cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(EXECUTABLE_OUTPUT_PATH "bin")

set(SOURCES "src/main.c"
    "src/defs.h"
    "src/draw.h"
    "src/draw.c")

project(BFight VERSION 0.1)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(BFight ${SOURCES})
target_link_libraries(BFight ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
