//Queue using Linkedlist
#include<iostream>
using namespace std;

//creation of class

class Queue
{
    int data,front,rear,capacity;
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
    //for insertion of data
	void queueEnqueue(int data); 
    //for deletion of data   
    void queueDequeue();
    //for display of elements                    
    void queueDisplay(); 
    //for printing the element at the front                     
     void queueFront();   
	 //for knowing the size of array
	 size_t find_size();
	 //for checking is empty of not
	 bool is_empty(); 
	 //for checking is full or not
	 bool is_full();                  

};
	// function to insert an element at the rear end if queue is not full

    
	void Queue::queueEnqueue(int data)
	{
		// check queue is full or not
		if (is_full()) {
			cout<<"\nQueue is full"<<endl;
			return;
		}

		// insert element at the rear
		else {
			queue[rear] = data;
			rear++;
		}
		return;
	}


	//for deleting the elements
    void Queue::queueDequeue()
	{
		// if queue is empty
		if (is_empty()) {
			cout<<"\nQueue is empty"<<endl;
			return;
		}

		// shift all the elements from index 2 till rear
		// to the left by one
		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}

			// decrement rear
			rear--;
		}
		return;
	}

    	//for displaying the elements of queue
	
	void Queue::queueDisplay()
	{
		int i;
		if (is_empty()) {
			cout<<"\nQueue is Empty\n";
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			cout<<queue[i]<<" <-- ";
		}
		return;
	}

    	// print front of queue
	void Queue::queueFront()
	{
		if (is_empty()) {
			cout<<"\nQueue is Empty\n";
			return;
		}
		cout<<"\nFront Element is: " <<queue[front];
		return;
	}
	//for finding the size
	size_t Queue::find_size()
	{
		return(rear+1);
	}

	//for checking whether the list is empty or not
	bool Queue::is_empty(){

		return(front == rear);
	};

	//for checking whether the list is full or not
	bool Queue::is_full(){

		return(capacity == rear);
	};



