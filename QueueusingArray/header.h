#include<iostream>
using namespace std;

//creation of class

class Queue
{
    private:
    int data;
    int front,rear,capacity;
    int* queue;
    public:
    Queue(int c){
        front=rear=0;
        capacity=c;
        queue=new int;
    };
    ~Queue(){
        delete[] queue;
    };

	void queueEnqueue(int data);            //for insertion of data
    void queueDequeue();                    //for deletion of data
    void queueDisplay();                    //for display of elements
    void queueFront();                      //for printing the element at the front

};