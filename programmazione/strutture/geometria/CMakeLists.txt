cmake_minimum_required(VERSION 4.0)
project(geometria)

set(CMAKE_CXX_STANDARD 20)

add_executable(geometria main.cpp)

target_link_libraries(${PROJECT_NAME} m)