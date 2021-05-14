	// print front of queue
	void Queue :: queueFront()
	{
		if (front == rear) {
			cout<<"\nQueue is Empty\n";
			return;
		}
		cout<<"\nFront Element is: " <<queue[front];
		return;
	}
