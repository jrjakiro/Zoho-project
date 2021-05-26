/*
Implementation of Least Recently used catche algorithm 
class name :lru
class members: list dq, capacity, iterator 
class methods: void refer(int),void display(),int size()
*/

//for preventing end user inclusion problems
#pragma once
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
template <typename T>
class lru
{
    //for storing keys initializing a deque
    list<int> dq;
    //for storing the capacity of list
    int capacity;
    // store references of key in cache for easier and faster accessing of addresses
    unordered_map<int, list<int>::iterator> ma;

public:
    //designing methods of class lru
    void refer(int);
    //for displaying elements
    void display();
    //for returning the size
    int size();

    //initializing constructor for declaring capacity
    lru(int n);
};
//constructor definition which initializes the capacity
template <typename T>
lru<T>::lru(int n)
{
    capacity = n;
}
//definition of refer function
// Refers key x with in the lru algorithm
template <typename T>
void lru<T>::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end())
    {
        // cache is full
        if (dq.size() == capacity)
        {
            // delete least recently used element
            int last = dq.back();

            // Pops the last elment
            dq.pop_back();

            // Erase the last
            ma.erase(last);
        }
    }
    // present in cache
    else
        dq.erase(ma[x]);

    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}

// Function to display contents of cache
template <typename T>
void lru<T>::display()
{

    // Iterate in the deque and print
    // all the elements in it
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";

    cout << endl;
}

//for returning the size
template <typename T>
int lru<T>::size()
{
    return dq.size();
}
