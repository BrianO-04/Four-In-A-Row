cmake_minimum_required(VERSION 3.10.0)
project(FourInARow VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include)
include_directories(src)

add_executable(FourInARow 
    src/main.cpp
    src/gamedata.cpp
    src/controller.cpp
    src/input.cpp
    src/board.cpp
    src/layer.cpp
    src/network.cpp
    src/funcs.cpp)

add_executable(dataTester
    src/gamedata.cpp
    src/dataTester.cpp)

add_executable(NetworkTrainer
    src/trainer.cpp
    src/network.cpp
    src/layer.cpp
    src/funcs.cpp
    src/gamedata.cpp)

find_package(Eigen3 REQUIRED)
target_link_libraries(FourInARow PRIVATE Eigen3::Eigen)
target_link_libraries(NetworkTrainer PRIVATE Eigen3::Eigen)