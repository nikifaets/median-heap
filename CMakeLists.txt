cmake_minimum_required(VERSION 3.14)
project(MedianHeap)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(test)