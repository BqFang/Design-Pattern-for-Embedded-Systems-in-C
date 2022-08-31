cmake_minimum_required(VERSION 3.21)
project(04_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(04_
        main.c
        queue.c
        queue.h)
