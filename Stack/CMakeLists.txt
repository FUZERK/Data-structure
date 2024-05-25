cmake_minimum_required(VERSION 3.27)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack stack.c
        stack.h
        test.c)
