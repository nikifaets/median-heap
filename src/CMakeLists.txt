cmake_minimum_required(VERSION 3.14)


add_library(MedianHeap_lib INTERFACE
    MedianHeap.h
)

add_executable(MedianHeap
    main.cpp
)

target_link_libraries(MedianHeap MedianHeap_lib)
