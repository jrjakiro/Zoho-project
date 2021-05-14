#include <iostream>

using namespace std;
// Node Creation
class Node{                             //class
        int data;
        Node* next;
        Node* prev;
        public:      //Access specifier

        // Insertion of value at front
        void push(Node** head_ref,int value); 
        //Insertion of value at end
        void append(Node** head_ref,int value);
        //Insertion of value after some element
        void insertafter(Node* prevnode,int value);
        //Insertion of value before some element
        void insertbefore(Node** head_ref,Node* afternode,int value);
        //Printing of values
        void printvalues(Node* x);

};
Node* head=new Node();


