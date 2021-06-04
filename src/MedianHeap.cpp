#include "MedianHeap.h"
#include <iostream>
#include <algorithm>
#include <assert.h>

void MedianHeap::insert(const int n){

    if(left.size() < 1) left.push(n);

    else if(right.size() < 1){
        right.push(n);
        if(right.top() < left.top()) switch_tops();
    }

    else{

        float median = get_median();

        if(n <= median) left.push(n);
        else right.push(n);

        rebalance();
    }
    
}

float MedianHeap::get_median() const{

    if(left.size() == right.size()) return (float)(left.top() + right.top()) /2.f;

    else return left.top();
}
void MedianHeap::switch_tops(){

    int right_top = right.top();
    right.pop();

    int left_top = left.top();
    left.pop();

    left.push(right_top);
    right.push(left_top);
}

void MedianHeap::rebalance(){


    assert(left.size() > 0 && right.size() > 0);

    while(left.size() > right.size() + 1){

        right.push(left.top());
        left.pop();
    }

    while(right.size() > left.size()){

        left.push(right.top());
        right.pop();
    }
}