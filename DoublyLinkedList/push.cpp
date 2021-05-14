#include "header.h"                                     //Includes header.h file

void Node :: push(Node** head_ref,int value)
{
    Node* new_node=new Node();                          //new node creation

    new_node->data=value;                               //assigning argument value to new node data

    new_node->prev=NULL;                                //assigning the prev of new node as NULL because it becomes the first node

    new_node->next=(*head_ref);                         //new node will point to the head node 

    if(*head_ref!=NULL)
    {
          (*head_ref)->prev=new_node;                   //if head node is not empty then prev of head node will be assigned to the new node
    }

    *head_ref=new_node;                                 //now the new node becomes the first node

}
