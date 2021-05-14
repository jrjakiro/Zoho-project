#include "header.h"                     //Including the header file
#include "push.cpp"
#include "pop.cpp"
#include "peek.cpp"
#include "isempty.cpp"


int main()
{
	s.push(123);
	s.push(0);
	s.push(3012);
	cout << s.pop() << " Popped from stack\n";
	//print all elements in stack :
	cout<<"Elements present in stack : ";
	while(!s.isEmpty())
	{
		// print top element in stack
		cout<<s.peek()<<" ";
		// remove top element in stack
		s.pop();
	}

	return 0;
}
