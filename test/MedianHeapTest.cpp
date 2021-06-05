#include "gtest/gtest.h"
#include <vector>
#include "../src/MedianHeap.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <random>

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

TEST(MedianHeapTest, test_float) {

    MedianHeap<float> median_heap_float;
    double median = get_random_vec_median<float>(1000, median_heap_float);
    ASSERT_FLOAT_EQ(median, median_heap_float.get_median());

    median_heap_float = MedianHeap<float>();

    median = get_random_vec_median<float>(10001, median_heap_float);
    ASSERT_FLOAT_EQ(median, median_heap_float.get_median());

}

TEST(MedianHeapTest, test_ull) {

    MedianHeap<unsigned long long> median_heap_ull;

    double median = get_random_vec_median<unsigned long long>(1000, median_heap_ull);
    ASSERT_FLOAT_EQ(median, median_heap_ull.get_median());

    median_heap_ull = MedianHeap<unsigned long long>();

    median = get_random_vec_median<unsigned long long>(10001, median_heap_ull);
    ASSERT_FLOAT_EQ(median, median_heap_ull.get_median());

}


TEST(MedianHeapTest, test_int) {

    MedianHeap<int> median_heap_int;

    double median = get_random_vec_median<int>(1000, median_heap_int);
    ASSERT_FLOAT_EQ(median, median_heap_int.get_median());

    median_heap_int = MedianHeap<int>();

    median = get_random_vec_median<int>(10001, median_heap_int);
    ASSERT_FLOAT_EQ(median, median_heap_int.get_median());

}

TEST(MedianHeapTest, test_get_median_empty){

    MedianHeap<int> median_heap_int;

    ASSERT_DEATH({

        double median = median_heap_int.get_median();
    }, "");
}


