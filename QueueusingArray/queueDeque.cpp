	//for deleting the elements
    void Queue :: queueDequeue()
	{
		// if queue is empty
		if (front == rear) {
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
