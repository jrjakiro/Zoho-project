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
        //Printing of values
        void printvalues(Node* x);
        //for inserting at location
        void insertAfter(Node* start,int value, int location);
        //for finding the size
        int findSize(Node *node);
        //for deleting a node
        void deleteNode(Node** head_ref, Node* del);
        //check whether empty or not
        bool isempty(Node* head);




};


