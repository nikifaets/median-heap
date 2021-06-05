#pragma once

#include <iostream>
#include <queue>
#include <algorithm>
#include <assert.h>
#include "Heap.h"
#include <type_traits>

template <class T>
using MinHeap = Heap<T, std::less<T>>;

template <class T>
using MaxHeap = Heap<T, std::greater<T>>;


/*
    A data structure that stores an array of data. 
    Supports element insertion in O(logN) time and median retrieval in O(1), where N is the number of elements.

    The frist half of the array is held in a max heap and the second in a min heap. 
    Thus, the size of the right heap is always N/2 and the size of the left heap is N/2 when N is even and N/2 + 1 when N is odd. (1)
    The median is the top element of the left heap when N is odd.
    The median is the average of the top element of each heap when N is even.

    A new element is pushed in the left heap in case it is less or equal to the median, or in the right heap if otherwise.
    After insertion, the two heaps are rebalanced -- elements are popped from one and pushed into the other until 
    the order in (1) is achieved.
    The rebalancing happens on every insertion, thus no more than one element would be transferred from one heap to the other.

*/

template <class T>
class MedianHeap{

public:

    MedianHeap(){}

    void insert(const T& n){

        // The insertions when size() < 2 need to be handled differently to preserve the MedianHeap properties.
        if(m_left.size() < 1) m_left.push(n);

        else if(m_right.size() < 1){

            m_right.push(n);
            if(m_right.top() < m_left.top()) switch_tops();
        }

        // If size() >= 2 proceed naturally.
        else{

            double median = get_median();

            if(n <= median) m_left.push(n);
            else m_right.push(n);

            rebalance();
        }
    
    }

    double get_median() const{

        if(m_left.size() == m_right.size()) return (double) (m_left.top() + m_right.top()) /2.f;

        else return m_left.top();
    };

private:

    /*
        Eventually gets called ONLY when inserting the second element in order to keep the MedianHeap properties.
    */
    void switch_tops(){

        int right_top = m_right.top();
        m_right.pop();

        int left_top = m_left.top();
        m_left.pop();

        m_left.push(right_top);
        m_right.push(left_top);
    }

    void rebalance(){

        assert(m_left.size() > 0 && m_right.size() > 0);

        while(m_left.size() > m_right.size() + 1){

            m_right.push(m_left.top());
            m_left.pop();
        }

        while(m_right.size() > m_left.size()){

            m_left.push(m_right.top());
            m_right.pop();
        }
    }

private:

    MinHeap<T> m_right;
    MaxHeap<T> m_left;


};
