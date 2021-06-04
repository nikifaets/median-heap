#pragma once

#include <vector>
#include <assert.h>

template<class T, class Comp>

class Heap{

public:

    const T& top() const{ 
        
        assert(v.size() > 0);
        return v[0]; 
    }

    void pop(){

        assert(v.size > 0);
        v[0] = v.back();
        heapify_down(0);
    }

    void push(const T& n){

        v.push_back(n);
        heapify_up(n);
    }

    size_t size() const{

        return v.size();
    }

private:

    int get_parent(const int i) { return i / 2; }
    int get_left(const int i) { return 2 * i; }
    int get_right(const int i) {return 2 * i + 1; }

    void heapify_up(int& i){

        while( Comp(i, get_parent(i)) ){

            swap(v[i], v[get_parent[i]]);
            i = get_parent(i);
        }
    }
    void heapify_down(int& i){}
    
private:

    std::vector<T> v;

};