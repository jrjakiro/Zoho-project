#include "header.h"
#include "newNode.cpp"
#include "push.cpp"
#include "pop.cpp"
#include "peek.cpp"
#include "isempty.cpp"

int main()
{

	root->push(&root, 135);
	root->push(&root, 79);
	root->push(&root, 3);

	cout << root->pop(&root) << " popped from stack\n";

	cout << "Top element is " << root->peek(root) << endl;
	
	cout<<"Elements present in stack : ";
	//print all elements in stack :
	while(!root->isEmpty(root))
	{
		// print top element in stack
		cout<<root->peek(root)<<" ";
		// remove top element in stack
		root->pop(&root);
	}

	return 0;
}
