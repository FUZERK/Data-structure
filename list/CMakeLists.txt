cmake_minimum_required(VERSION 3.27)
project(list C)

set(CMAKE_C_STANDARD 99)

add_executable(list list.c
        list.h
        test.c)
