cmake_minimum_required(VERSION 3.6)
project(sorting)

set(SOURCE_FILES main.c sorting_commons.h sorting_commons.c sorting/sorting.h)
add_executable(sorting ${SOURCE_FILES})