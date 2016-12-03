cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME piotrowy_sorting_stats)
project(${PROJECT_NAME})

file(GLOB SOURCE_FILES *.c *.h)

add_subdirectory(sorting_algorithms)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} piotrowy_sorting)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)