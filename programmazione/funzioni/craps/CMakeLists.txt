cmake_minimum_required(VERSION 4.0)
project(craps C)

set(CMAKE_C_STANDARD 11)

add_executable(craps main.c)

target_link_libraries(craps m)
