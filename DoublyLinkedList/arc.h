/*Implementation of Adaptive replacement cache header file*/

//for preventing end user inclusion problems
#pragma once
#include <iostream>
#include<list>
#include<unordered_map>

using namespace std;
template <typename T>
class arc
{
    //for storing keys initializing a deque
    list <int> dq;
    //for storing the capacity of list
    int capacity;
    // store references of key in cache
    unordered_map<int, list<int>::iterator> ma;
public:
    //designing methods of class arc
    void refer(int);
    //for displaying elements
    void display();

    //initializing constructor for declaring capacity
    arc(int n);
};
//constructor definition which initializes the capacity
template <typename T>
arc<T>::arc(int n)
{
    capacity = n;
}
//definition of refer function
// Refers key x with in the ARC algorithm
template <typename T>
void arc<T>::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end()) {
        // cache is full
        if (dq.size() == capacity) {
            // delete least recently used element
            int last = dq.back();
  
            // Pops the last elmeent
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
void arc<T>::display()
{
  
    // Iterate in the deque and print
    // all the elements in it
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";
  
    cout << endl;
}