cmake_minimum_required(VERSION 3.26)
project(complessi C)

set(CMAKE_C_STANDARD 11)

add_executable(complessi main.c
        complessi.c
        complessi.h
)
