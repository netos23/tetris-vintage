cmake_minimum_required(VERSION 3.17)
project(tetris_vintage C)

set(CMAKE_C_STANDARD 99)

add_executable(tetris_vintage main.c tetris_core.c tetris_core.h math.c math.h)