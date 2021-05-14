#include <iostream>

using namespace std;
// Node Creation
class Node{                                                     //class
        int data;
        Node* next;
        Node* prev;
        public:                                                 //Access specifier

        void push(Node** head_ref,int value);                   // Insertion of value at front

        void append(Node** head_ref,int value);                 //Insertion of value at end

        void Insert(Node* start,int value, int location);       //for inserting at location

        void DeleteNode(Node** head_ref, Node* del);            //for deleting a node

        int FindSize(Node *head_ref);                           //for finding the size

        bool isEmpty(Node* head_ref);                           //check whether empty or not

        void PrintVal(Node* x);                                 //Printing of values


};


