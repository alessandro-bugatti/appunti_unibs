cmake_minimum_required(VERSION 4.3)
project(radici2 C)

set(CMAKE_C_STANDARD 11)

add_executable(radici2 main.c)
target_link_libraries(radici2 m)
