cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME piotrowy_sorting)
project(${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

file(GLOB HEADERS inc/*.h)
file(GLOB SOURCE_FILES src/*.c)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})


bubble_sort
comb_sort
commons
heap_sort
insert_sort.h
merge_sort.h
quick_sort.h
select_sort.h