cmake_minimum_required(VERSION 3.27)
project(Slist C)

set(CMAKE_C_STANDARD 99)

add_executable(Slist main.c
        slist.h
        TEST.c
        contact.h
        contact.c)
