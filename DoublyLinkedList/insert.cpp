#include "doubly_linked_list.h" //including header file

void doubly_linked_list ::Insert(int value, int location) //for inserting at a location
{
   doubly_linked_list *newNode = new doubly_linked_list(); //new doubly_linked_list creation

   newNode->data = value; //new value is assigned to new node

   if (head == NULL)
   {
      newNode->prev = newNode->next = NULL; //if head is Null then it means the new node will become the first node
      head = newNode;
   }
   else
   {
      doubly_linked_list *temp1 = head; //created temporary nodes
      doubly_linked_list *temp2;

      while (temp1->data != location) //iterating to insert at a position
      {
         if (temp1->next == NULL) // to check whether the location is present or not
         {
            cout << "Given node is not found in the list!!!" << endl;
            return;
         }
         else
         {
            temp1 = temp1->next; //traversal till the condition is satisfied
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