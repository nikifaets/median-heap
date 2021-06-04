#include "gtest/gtest.h"
#include <vector>
#include "../src/MedianHeap.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>

TEST(MedianHeapTest, test1) {

    MedianHeap h;

    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    for(int& a : v){

        h.insert(a);
    }

    ASSERT_FLOAT_EQ(h.get_median(), 5.f);

    h.insert(10);
    ASSERT_FLOAT_EQ(h.get_median(), 5.5);

    

    srand(time(0));
    const int ARRAY_LEN = 10000;
    const int TESTS_NUM = 100;

    for(int i=0; i<TESTS_NUM; i++){

        std::vector<int> v1;
        MedianHeap h1;
        for(int j=0; j<ARRAY_LEN; j++){

            int element = rand() % 100000;
            v1.push_back(element);
            h1.insert(element);
        }

        std::sort(v1.begin(), v1.end());

        ASSERT_FLOAT_EQ(h1.get_median(), (float) (v1[5000] + v1[4999]) / 2.f);
    }
}
