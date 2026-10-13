cmake_minimum_required(VERSION 4.3)
project(coseno C)

set(CMAKE_C_STANDARD 11)

add_executable(coseno main.c)

target_link_libraries(coseno m)
