#include <iostream>
#include <stdio.h>
using namespace std;
// Node Creation
class doubly_linked_list
{ //class
        int data;
        doubly_linked_list *next;
        doubly_linked_list *prev;
        doubly_linked_list *head=NULL;


public:                                                      //Access specifier
        void push(int value); // Insertion of value at front

        void append(int value); //Insertion of value at end

        void Insert(int value, int location); //for inserting at location

        void DeleteNode(int value); //for deleting a node

        int FindSize(); //for finding the size

        bool isEmpty(); //check whether empty or not

        void PrintVal(); //Printing of values
};


void doubly_linked_list ::push(int value)
{
    doubly_linked_list *new_node = new doubly_linked_list(); //new node creation

    new_node->data = value; //assigning argument value to new node data

    new_node->prev = NULL; //assigning the prev of new node as NULL because it becomes the first node

    new_node->next = (head); //new node will point to the head node

    if (head != NULL)
    {
        head->prev = new_node; //if head node is not empty then prev of head node will be assigned to the new node
    }

    head = new_node; //now the new node becomes the first node
}

//to find the size
int doubly_linked_list ::FindSize()
{
    doubly_linked_list *x = head;

    int count = 0;
    while (x != NULL)
    {
        count++;
        x = x->next;
    }
    return count;
}
//to check for empty or not
bool doubly_linked_list ::isEmpty()
{
    return (!(FindSize()));
}

void doubly_linked_list ::append(int value) //add the element at the back
{
    doubly_linked_list *new_node = new doubly_linked_list(); //creation of new node

    new_node->data = value; //since it will become the last node we are adding data as value and next as Null
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL; //if head is null then it means the list is empty
        head = new_node;       //so making new node as the first node
        return;
    }

    doubly_linked_list *last = (head); //for finding the last node

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node; //assign next value of last node as new node and new node of prev as last node
    new_node->prev = last;
    return;
}
void doubly_linked_list ::Insert(int value, int location) //for inserting at a location
{
   doubly_linked_list *newNode = new doubly_linked_list(); //new doubly_linked_list creation

   newNode->data = value; //new value is assigned to new node

   if (location == 0)
   {
     push(value);
     return;
   }
   else
   {
      doubly_linked_list *temp1 = head; //created temporary nodes
      doubly_linked_list *temp2;
      int count=1;

      while (count != location) //iterating to insert at a position
      {
         if (temp1->next == NULL) // to check whether the location is present or not
         {
            cout << "Given node is not found in the list!!!" << endl;
            return;
         }
         else
         {
            temp1 = temp1->next;
            count++; //traversal till the condition is satisfied
         }
      }
      temp2 = temp1->next;   //as the new node is inserted between two temp nodes,
      temp1->next = newNode; // assigning the prev node of new node as temp1 and next node as temp2
      newNode->prev = temp1; //similarly in temp1 node next as new node and in temp2 node previous as new node
      newNode->next = temp2;
      temp2->prev = newNode;

      cout << "\nInsertion success!!!" << endl;
   }
}


void doubly_linked_list ::DeleteNode(int value) //for deletion of elements
{

    // base case that list is empty
    if (head == NULL)
    {
        cout << "The List contains no item to delete" << endl;
        return;
    }
    //if the node to be deleted is head node
    if (head->data == value)
    {
        free(head);
        head = head->next;
        return;
    }

    doubly_linked_list *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == value)
        {
            // Change next only if node to be deleted is NOT the last node
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            //Change prev only if node to be deleted is NOT the first node */
            if (temp->prev != NULL)
                temp->prev->next = temp->next;

            // Finally, free the memory occupied by del
            free(temp);
            return;
        }
        else
        {
            //move to the next node
            temp = temp->next;
        }
    }

    cout << "Given item is not found in the list";
    return;
}

void doubly_linked_list ::PrintVal() //prints the values in list
{
    doubly_linked_list *x = head;
    if (head == NULL)
    {
        cout << "No Items in the list and it is empty";
    }

    while (x != NULL) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\n size is " << doubly_linked_list::FindSize() << endl; //prints the size for reference
};

