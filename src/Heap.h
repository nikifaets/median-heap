#pragma once

#include <vector>
#include <assert.h>
#include <iostream>

/*
    A binary heap class, can be both min heap and max heap, depending on the Comp template argument.
    Comp has to be a type that supports the () operator taking two arguments with type T and returns a boolean.
    Comp provides an ordering where Comp(a, b) is true if a appears before b.

    The top element of the heap is the first in the order provided by Comp.

    Indexing in the heap starts from 1. 
    This is to preserve the property that for an element with position i, its parent is i/2 and its children are i*2 and i*2 + 1.

*/

template<class T, class Comp>
class Heap{

public:

    // Default nullary constructor, copy constructor, copy-assignment operator and destructor work fine for this class.
    const T& top() const{ 
        
        assert(m_storage.size() > 1);

        return m_storage[1]; 
    }

    void pop(){

        assert(m_storage.size() > 1);

        m_storage[1] = m_storage.back();
        m_storage.erase(std::prev(m_storage.end()));
        heapify_down(1);
    }

    void push(const T& n){

        if(m_storage.size() < 1) m_storage.push_back(0); // Start counting from the 1st element.

        m_storage.push_back(n);
        heapify_up(m_storage.size()-1);
    }

    size_t size() const{

        return m_storage.size();
    }

    void clear(){

        m_storage.clear();
    }

    void print(){

        for(int i=1; i<m_storage.size(); i++){

            std::cout << m_storage[i] << " Children : ";

            if(get_left(i) < m_storage.size()) std::cout << m_storage[get_left(i)] << " ";
            if(get_right(i) < m_storage.size()) std::cout << m_storage[get_right(i)] << " ";

            std::cout << "\n";
        }
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

        while( m_comp(m_storage[i], m_storage[get_parent(i)]) && i > 1 ){

            std::swap(m_storage[i], m_storage[get_parent(i)]);
            i = get_parent(i);
        }
    }

    void heapify_down(int i){

        while( m_comp(m_storage[get_comp_child(i)], m_storage[i]) ){

            int new_pos = get_comp_child(i);
            std::swap(m_storage[i], m_storage[new_pos]);
            i = new_pos;
        }
    }
    
private:

    std::vector<T> m_storage;
    Comp m_comp;

};

template <class T>
using MinHeap = Heap<T, std::less<T>>;

template <class T>
using MaxHeap = Heap<T, std::greater<T>>;