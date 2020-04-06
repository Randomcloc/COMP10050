cmake_minimum_required(VERSION 3.15)
project(Focus C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-lncurses")

add_executable(Focus main.c input_output.c game_init.c game_init.h input_output.h)