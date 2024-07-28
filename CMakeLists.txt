cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(EXECUTABLE_OUTPUT_PATH "bin")

# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(SOURCES "src/main.c"
    "src/defs.h"
    "src/draw.h"
    "src/draw.c"
"src/input.h"
"src/input.c")


project(BFight VERSION 0.1)

include(FetchContent)
FetchContent_Declare(SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.5)
FetchContent_Declare(SDL2_IMAGE
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.2)
FetchContent_MakeAvailable(SDL2 SDL2_IMAGE)

set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2 SDL2_image)
# find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

# include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
add_executable(BFight ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
# target_link_libraries(BFight SDL2 SDL2_image)
target_link_libraries(BFight ${SDL_LIBRARIES})
