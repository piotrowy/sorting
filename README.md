# PiotrowySorting
Sorting project serves to make measurements of different sorting algorithms. It contains library with various, common sorting algorithms.

You can use this project, see implementation of various sorting algorithms and measure time of executing such algorithm.

#Algorithms
* HeapSort (in progress)
* QuickSort
* QuickSort Iterative
* MergeSort
* SelectSort
* InsertSort
* CombSort
* BubbleSort
* ShellSort

Iterative quick sort contains dummy stack implementation. It is needed and I want only show how iterative quick sort works, not a stack. Stack is not resistant to overflowing integer.

#How to use?
* in main.c file I defined two functions which map enums to functions. It allows to easy configure main function and what you want to measure.
* sorting_algorithms directory contains only implementations of sorting algorithms and other functions (like swap) which were necessary to implement sorting. It contains also enum with all implemented algorithms names.
* stats_utils.h is an interface which provides functions to fill arrays with values (there are 3 modes: RANDOM, INCREASING and DECREASING), to check if array is sorted and to measure time of sorting.

#Build
Possible ways (it means provided by me or already existing tool):
* Preferable way - use Clion it's the best.
* CMake - yes, there are already defined files. 

#Future works
I work on implementation of setting timeouts on algorithms execution.
