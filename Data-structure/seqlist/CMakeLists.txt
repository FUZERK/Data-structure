cmake_minimum_required(VERSION 3.27)
project(seqlist C)

set(CMAKE_C_STANDARD 99)

add_executable(seqlist test.c
        seqlist.c
        contact.h
        contact.c)
