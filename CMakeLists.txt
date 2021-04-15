cmake_minimum_required(VERSION 3.16)
project(Observer_Pattern)

set(CMAKE_CXX_STANDARD 20)

add_executable(Observer_Pattern main.cpp observers_.h interface_.h functions_.h)