	// function to insert an element at the rear end if queue is not full

    
	void Queue :: queueEnqueue(int data)
	{
		// check queue is full or not
		if (capacity == rear) {
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
