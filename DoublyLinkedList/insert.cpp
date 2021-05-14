#include "header.h"
void Node :: insertAfter(Node *head,int value, int location)
{
   Node *newNode=new Node();
   newNode -> data = value;
   if(head == NULL)
   {
      newNode -> prev = newNode -> next = NULL;
      head = newNode;
   }
   else
   {
      Node *temp1 = head;
      Node *temp2;
      while(temp1 -> data != location)
      {
         if(temp1 -> next == NULL)
         {
            cout<<"Given node is not found in the list!!!"<<endl;
            return;
         }
         else
         {
            temp1 = temp1 -> next;
         }
      }
      temp2 = temp1 -> next;
      temp1 -> next = newNode;
      newNode -> prev = temp1;
      newNode -> next = temp2;
      temp2 -> prev = newNode;
      printf("\nInsertion success!!!");
   }
}