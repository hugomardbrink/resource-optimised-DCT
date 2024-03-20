# Set minimum version of CMake
cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
include(${CMAKE_TOOLCHAIN_FILE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    dct 
    LANGUAGES C)

add_executable(dct main.c)


