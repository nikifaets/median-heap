#pragma once

#include <vector>
#include <assert.h>

template<class T, class Comp>

class Heap{

public:

    const T& top() const{ 
        
        assert(m_storage.size() > 0);
        return m_storage[0]; 
    }

    void pop(){

        assert(m_storage.size() > 0);
        m_storage[0] = m_storage.back();
        heapify_down(0);
    }

    void push(const T& n){

        m_storage.push_back(n);
        heapify_up(n);
    }

    size_t size() const{

        return m_storage.size();
    }

private:

    int get_parent(const int i) const { return i / 2; }
    int get_left(const int i) const { return 2 * i; }
    int get_right(const int i) const {return 2 * i + 1; }
    int get_comp_child(const int i) const{

        int left = get_left(i);
        int right = get_right(i);

        if(left >= size()) return i;

        if(right >= size()) return left;

        return m_comp(m_storage[left], m_storage[right]) ? left : right;
    }

    void heapify_up(int i){

        while( m_comp(m_storage[i], m_storage[get_parent(i)]) ){

            std::swap(m_storage[i], m_storage[get_parent(i)]);
            i = get_parent(i);
        }
    }

    void heapify_down(int i){

        while( m_comp(m_storage[i], m_storage[get_comp_child(i)]) ){

            std::swap(m_storage[i], m_storage[get_comp_child(i)]);
            i = get_comp_child(i);
        }
    }
    
private:

    std::vector<T> m_storage;
    Comp m_comp;

};