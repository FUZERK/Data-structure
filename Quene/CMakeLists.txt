cmake_minimum_required(VERSION 3.27)
project(Quene C)

set(CMAKE_C_STANDARD 99)

add_executable(Quene quene.c
        quene.h
        test.c)
