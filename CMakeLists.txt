cmake_minimum_required(VERSION 3.9)
project(Escape_from_MAZE)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Escape_from_MAZE ${SOURCES})

target_include_directories(Escape_from_MAZE PRIVATE includes)
