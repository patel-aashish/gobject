cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(shape_gobject LANGUAGES C)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GOBJECT REQUIRED gobject-2.0)

include_directories(${GOBJECT_INCLUDE_DIRS})

set(LIBSHAPE shape.c shape.h)
add_library(shape ${LIBSHAPE})

add_executable(shape_test main.c)
target_link_libraries(shape_test shape ${GOBJECT_LIBRARIES})