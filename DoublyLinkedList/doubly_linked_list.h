#include <iostream>

using namespace std;
// Node Creation
class doubly_linked_list
{ //class
        int data;
        doubly_linked_list *next;
        doubly_linked_list *prev;
        doubly_linked_list *head;


public:                                                      //Access specifier
        void push(int value); // Insertion of value at front

        void append(int value); //Insertion of value at end

        void Insert(int value, int location); //for inserting at location

        void DeleteNode(int value); //for deleting a node

        int FindSize(); //for finding the size

        bool isEmpty(); //check whether empty or not

        void PrintVal(); //Printing of values
};

