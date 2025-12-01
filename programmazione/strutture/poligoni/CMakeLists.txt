cmake_minimum_required(VERSION 4.0)
project(poligoni C)

set(CMAKE_C_STANDARD 11)

add_executable(poligoni main.c)

target_link_libraries(${PROJECT_NAME} m)

