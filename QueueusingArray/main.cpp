#include "header.h"
#include "queueEnque.cpp"
#include "queueDisplay.cpp"
#include "queueFront.cpp"
#include "queueDeque.cpp"



//Driver code
int main()
{
	// Create a queue of capacity 4
	Queue q(4);

	// print Queue elements
	q.queueDisplay();

	// inserting elements in the queue
	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);

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
