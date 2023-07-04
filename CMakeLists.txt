cmake_minimum_required(VERSION 3.24)
project(csc357_assignment1_realrusssobti C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(csc357_assignment1_realrusssobti
        uniq.c
        word_count.c)
