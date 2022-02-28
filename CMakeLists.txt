cmake_minimum_required(VERSION 3.16)
project(Advent_of_Code_2021)

set(CMAKE_CXX_STANDARD 14)

include_directories(dayOne)

add_executable(Advent_of_Code_2021
        dayOne/main.cpp
        )
