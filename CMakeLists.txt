cmake_minimum_required(VERSION 3.26)
project(h_basic)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(h_basic src/main.cpp src/vector.cpp)
