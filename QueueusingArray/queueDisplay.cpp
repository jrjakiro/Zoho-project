	//for displaying the elements of queue
	
	void Queue :: queueDisplay()
	{
		int i;
		if (front == rear) {
			cout<<"\nQueue is Empty\n";
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			cout<<queue[i]<<" <-- ";
		}
		return;
	}
