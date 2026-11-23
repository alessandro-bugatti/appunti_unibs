cmake_minimum_required(VERSION 4.4)
project(complessi C)

set(CMAKE_C_STANDARD 11)

add_executable(complessi main.c)

target_link_libraries(complessi m)
