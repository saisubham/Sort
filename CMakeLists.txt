cmake_minimum_required(VERSION 3.0)

project(Sort)

set(CMAKE_BUILD_TYPE Debug)

include_directories(includes)
find_library(NCURSES_LIB ncurses)

set(SOURCES
	graph-utils/menu.c
	graph-utils/response.c
	graph-utils/status.c
	helper/swap.c
	main/Main.c
	src/BubbleSort.c
	src/InsertionSort.c
	src/MergeSort.c
	src/QuickSort.c
	src/SelectionSort.c
	includes/sort.h
	)

add_executable(Sort ${SOURCES})

target_link_libraries(Sort ${NCURSES_LIB})
