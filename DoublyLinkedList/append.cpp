#include "header.h"                                     //included the header file

void Node :: append(Node** head_ref,int value)          //add the element at the back
{
    Node* new_node=new Node();                          //creation of new node

    new_node->data=value;                               //since it will become the last node we are adding data as value and next as Null
    new_node->next=NULL;

    if(*head_ref==NULL)
    {
        new_node->prev=NULL;                            //if head is null then it means the list is empty
        (*head_ref)=new_node;                           //so making new node as the first node
        return;
    }

    Node* last=(*head_ref);                             //for finding the last node
    while(last->next!=NULL)
    {
        last=last->next;
    }

    last->next=new_node;                                //assign next value of last node as new node and new node of prev as last node
    new_node->prev=last;
    return;

}
