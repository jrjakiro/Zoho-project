#include <iostream>

using namespace std;
// Node Creation
class NodeDLL{                                                     //class
        int data;
        NodeDLL* next;
        NodeDLL* prev;
        public:                                                 //Access specifier

        void push(NodeDLL** head_ref,int value);                   // Insertion of value at front

        void append(NodeDLL** head_ref,int value);                 //Insertion of value at end

        void Insert(NodeDLL* start,int value, int location);       //for inserting at location

        void DeleteNode(NodeDLL** head_ref, NodeDLL* del);            //for deleting a node

        int FindSize(NodeDLL *head_ref);                           //for finding the size

        bool isEmpty(NodeDLL* head_ref);                           //check whether empty or not

        void PrintVal(NodeDLL* x);                                 //Printing of values


};


