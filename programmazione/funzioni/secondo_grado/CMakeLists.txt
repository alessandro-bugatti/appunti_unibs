cmake_minimum_required(VERSION 4.0)
project(secondo_grado C)

set(CMAKE_C_STANDARD 11)

add_executable(secondo_grado main.c)

target_link_libraries(secondo_grado m)
