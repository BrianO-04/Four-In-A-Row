cmake_minimum_required(VERSION 3.10.0)
project(FourInARow VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)
include_directories(src)

add_executable(FourInARow 
    src/board.cpp
    src/main.cpp)

