//Stack implementation Using Array
#include<iostream>
using namespace std;
#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX];                 // Maximum size of Stack

	Stack() { top = -1; }       //stack initialization
	bool push(int x);           //for inserting data at the front 
	int pop();                  //for deleting and printing the data
	int peek();                 //for printing the top most element
	bool isEmpty();             //for checking whether the stack is empty or not
};
class Stack s;
