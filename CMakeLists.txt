cmake_minimum_required(VERSION 3.27)
project(trees C)

set(CMAKE_C_STANDARD 11)

add_executable(trees main.c
        bintree.c
        bintree.h)
