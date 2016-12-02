cmake_minimum_required(VERSION 3.6)
project(sorting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c sorting_commons.h sorting_commons.c sortings.h sortings.c)
add_executable(sorting ${SOURCE_FILES})