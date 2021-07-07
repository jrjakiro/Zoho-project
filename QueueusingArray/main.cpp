#include "queue_using_array.h"



//Driver code
int main()
{
	// Create a queue of capacity 4
	Queue q(10);

	// print Queue elements
	q.queueDisplay();

	// inserting elements in the queue
	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);
	cout<<"\nSize of queue is "<<q.find_size()<<endl;

	// print Queue elements
	q.queueDisplay();

	// insert element in the queue
	q.queueEnqueue(60);

	// print Queue elements
	q.queueDisplay();

	q.queueDequeue();
	q.queueDequeue();

	cout<<"\n\nafter two node deletion"<<endl;

	// print Queue elements
	q.queueDisplay();

	// print front of the queue
	q.queueFront();

	return 0;
}
