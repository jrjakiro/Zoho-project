//Stack implementation Using Array
#include<iostream>
using namespace std;
#define MAX 1000

class Stack {
	int top;

public:
	//Maximum size of Stack 
	int a[MAX];                 
	//Stack initialization
	Stack() { top = -1; }       
	//for inserting data at the front
	bool push(int x);  
	//for deleting and printing the top most data          
	int pop();  
	//for printing the top most element
	int peek();   
	//for checking whether the stack is empty or not              
	bool is_empty();   
	//for finding the size of the list
	size_t find_size();        
} s;

//push element into stack when the stack is not full 
bool Stack::push(int x)
{
	//checking whether the stack is full or not
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";		
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

// return a deleted element if stack is not empty
int Stack::pop()
{
	//to check whether the stack is empty or not
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

//returns the top most element when stack is not empty
int Stack::peek()
{	
	//to check whether the stack is empty or not
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

//returns true if the stack is empty
bool Stack::is_empty()
{
	return (top < 0);
}

size_t Stack::find_size()
{
	return top+1 ;
}


