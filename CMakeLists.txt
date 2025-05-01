cmake_minimum_required(VERSION 3.30)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(EXECUTABLE_OUTPUT_PATH "bin")
set(SOURCES "src/main.c"
    "src/defs.h"
    "src/draw.h"
    "src/draw.c"
    "src/input.h"
    "src/input.c"
    "src/widgets.h"
    "src/widgets.c")

project(BFight VERSION 0.1)

include(FetchContent)
FetchContent_Declare(SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.5)
FetchContent_Declare(SDL2_IMAGE
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-2.8.2)
FetchContent_Declare(SDL2_TTF
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-2.22.0)
FetchContent_MakeAvailable(SDL2 SDL2_IMAGE SDL2_TTF)

message("SDL libraries")
message("${SDL2_TTF}")
message("${SDL2_ttf}")

set(SDL_LIBRARIES ${SDL_LIBRARIES} SDL2 SDL2_image SDL2_ttf)

message("${SDL_LIBRARIES}")

add_executable(BFight ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(BFight PRIVATE ${SDL_LIBRARIES})
