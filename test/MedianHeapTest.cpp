#include "gtest/gtest.h"
#include <vector>
#include "../src/Heap.h"
#include "../src/MedianHeap.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>

class HeapTest : public ::testing::Test{

protected:

    Heap<int, std::less<int>> min_heap_int;
};

TEST_F(HeapTest, test_push){

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

TEST_F(HeapTest, test_pop){

    min_heap_int.clear();

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

TEST_F(HeapTest, test_sort){

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

class MedianHeapTest : public ::testing::Test{


protected:

    void SetUp() override{}

    MedianHeap<int> median_heap_int;
    MedianHeap<float> median_heap_float;
    MedianHeap<unsigned long long> median_heap_ull;

};

template <class T>
double get_random_vec_median(const int arr_len, MedianHeap<T>& h){

    const int ARR_MAX = 100000;
    const int ARR_MIN = 0;

    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_real_distribution<float> distr(ARR_MIN, ARR_MAX);

    std::vector<T> v;

    for(int i=0; i<arr_len; i++){
        
        T num = (T) distr(eng);
        v.push_back(num);
        h.insert(num);
    }

    std::sort(v.begin(), v.end());

    if(arr_len % 2 == 0){

        return (double) (v[arr_len/2] + v[arr_len/2 - 1]) / 2.f;
    }

    return double(v[arr_len/2]);

}

TEST_F(MedianHeapTest, test_float) {

    double median = get_random_vec_median<float>(1000, median_heap_float);
    ASSERT_FLOAT_EQ(median, median_heap_float.get_median());

    median_heap_float = MedianHeap<float>();

    median = get_random_vec_median<float>(10001, median_heap_float);
    ASSERT_FLOAT_EQ(median, median_heap_float.get_median());

}

TEST_F(MedianHeapTest, test_ull) {

    double median = get_random_vec_median<unsigned long long>(1000, median_heap_ull);
    ASSERT_FLOAT_EQ(median, median_heap_ull.get_median());

    median_heap_ull = MedianHeap<unsigned long long>();

    median = get_random_vec_median<unsigned long long>(10001, median_heap_ull);
    ASSERT_FLOAT_EQ(median, median_heap_ull.get_median());

}


TEST_F(MedianHeapTest, test_int) {

    double median = get_random_vec_median<int>(1000, median_heap_int);
    ASSERT_FLOAT_EQ(median, median_heap_int.get_median());

    median_heap_int = MedianHeap<int>();

    median = get_random_vec_median<int>(10001, median_heap_int);
    ASSERT_FLOAT_EQ(median, median_heap_int.get_median());

}


