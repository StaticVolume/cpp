cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)

include(FindPkgConfig)
pkg_check_modules(SDL2_Mixer REQUIRED IMPORTED_TARGET SDL2_mixer)
pkg_check_modules(SDL2_Image REQUIRED IMPORTED_TARGET SDL2_image)
include_directories (

                        ${SDL2_INCLUDE_DIRS}
                        ${SDL2mixer_INCLUDE_DIRS}
                        ${SDL2image_INCLUDE_DIRS}
                     )



add_executable(SDL2Test main.cpp sdl2.cpp sdl2.h colour.cpp colour.h game.cpp game.h)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2mixer_LIBRARIES} ${SDL2image_INCLUDE_DIRS})
target_link_libraries(SDL2Test PkgConfig::SDL2_Mixer)
target_link_libraries(SDL2Test PkgConfig::SDL2_Image)
