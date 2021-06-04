#pragma once

#include <iostream>
#include <queue>

using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

using MaxHeap = std::priority_queue<int, std::vector<int>>; // Uses std::less<T> by default.

class MedianHeap{

public:

    void insert(const int n);
    float get_median() const;

private:

    void switch_tops();
    void rebalance();

private:

    MinHeap right;
    MaxHeap left;


};