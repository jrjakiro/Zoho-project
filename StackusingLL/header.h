#include<iostream>
using namespace std;

//Creating a class to represent the structure and methods
class StackNode {
	int data;
	StackNode* next;
    public:
        StackNode* newNode(int data);            //for creating new node
        int isEmpty(StackNode* root);            //for checking whether the stack is empty or not
        void push(StackNode** root, int data);   //for pushing data inside stack
        int pop(StackNode** root);               //for deleting node and return it
        int peek(StackNode* root);               //for returning the top most element 

};
StackNode* root = NULL;


