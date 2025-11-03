cmake_minimum_required(VERSION 4.0)
project(ipotenusa C)

set(CMAKE_C_STANDARD 11)

add_executable(ipotenusa main.c)

target_link_libraries(ipotenusa m)