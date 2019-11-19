cmake_minimum_required(VERSION 3.10)
project(Smash)

set(CMAKE_CXX_STANDARD 11)

add_executable(Smash main.cpp Commands.cpp Commands.h signals.cpp signals.h)