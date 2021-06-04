#pragma once

#include <iostream>
#include <queue>
#include <algorithm>
#include <assert.h>
#include "Heap.h"

template <class T>
using MinHeap = Heap<T, std::greater<T>>;

template <class T>
using MaxHeap = std::priority_queue<T, std::vector<T>>; // Uses std::less<T> by default.

template <class T>
class MedianHeap{

public:

    MedianHeap(){}

    void insert(const T& n){

        if(m_left.size() < 1) m_left.push(n);

        else if(m_right.size() < 1){

            m_right.push(n);
            if(m_right.top() < m_left.top()) switch_tops();
        }

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