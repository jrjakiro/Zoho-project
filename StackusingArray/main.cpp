// Driver program to test above functions
#include "stack_using_array.h"

int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
    s.push(10);
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);
    cout << s.find_size() << " is the size of array\n";

	cout << s.pop() << " Popped from stack\n";
	//print all elements in stack :
	cout<<"Elements present in stack : ";
	while(!s.is_empty())
	{
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}
