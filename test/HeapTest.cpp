#include "gtest/gtest.h"
#include <algorithm>
#include "../src/Heap.h"

TEST(HeapTest, test_push){

    MinHeap<int> min_heap_int;

    min_heap_int.push(1);
    min_heap_int.push(1);
    min_heap_int.push(2);

    ASSERT_EQ(min_heap_int.top(), 1);

    min_heap_int.push(0);
    ASSERT_EQ(min_heap_int.top(), 0);

    min_heap_int.push(-1);

    min_heap_int.push(4);
    ASSERT_EQ(min_heap_int.top(), -1);

    min_heap_int.push(-1000);
    min_heap_int.push(-500);
    min_heap_int.push(1000);

    ASSERT_EQ(min_heap_int.top(), -1000);

}

TEST(HeapTest, test_pop){

    MinHeap<int> min_heap_int;

    min_heap_int.push(5);
    min_heap_int.push(4);
    min_heap_int.push(3);
    min_heap_int.push(17);
    min_heap_int.push(200);

    ASSERT_EQ(min_heap_int.top(), 3);

    min_heap_int.pop();
    ASSERT_EQ(min_heap_int.top(), 4);

    min_heap_int.pop();
    ASSERT_EQ(min_heap_int.top(), 5);

    min_heap_int.push(-200);
    min_heap_int.push(-300);

    ASSERT_EQ(min_heap_int.top(), -300);

    min_heap_int.pop();
    min_heap_int.pop();
    min_heap_int.pop();

    ASSERT_EQ(min_heap_int.top(), 17);

}

TEST(HeapTest, test_sort){

    MinHeap<int> min_heap_int;

    min_heap_int.clear();

    std::vector<int> v{5,6,7,8,1,2,3,4,5,6,1,2,3,8,9,0,11,45,456,567,234,1134324,234};

    for(const int n : v){
        
        min_heap_int.push(n);
    }

    std::sort(v.begin(), v.end());

    for(const int n : v){

        ASSERT_EQ(min_heap_int.top(), n);
        min_heap_int.pop();
    }
}

TEST(HeapTest, test_pop_empty){

    MinHeap<int> min_heap_int;

    ASSERT_DEATH({
        min_heap_int.pop();
    }, "");
}

TEST(HeapTest, test_get_top_empty){

    MinHeap<int> min_heap_int;

    ASSERT_DEATH({

        int top = min_heap_int.top();
    }, "");
}
