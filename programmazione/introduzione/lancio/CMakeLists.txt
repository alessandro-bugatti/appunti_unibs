cmake_minimum_required(VERSION 4.3)
project(lancio C)

set(CMAKE_C_STANDARD 11)

add_executable(lancio main.c)

target_link_libraries(lancio m)
