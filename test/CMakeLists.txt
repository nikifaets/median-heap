cmake_minimum_required(VERSION 3.14)


set(This MedianHeapTests)
                    
add_executable (${This} MedianHeapTest.cpp)

target_link_libraries(${This}

    gtest_main
    MedianHeap_lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)


