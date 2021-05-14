#include "header.h"

void Node :: append(Node** head_ref,int value)
{
    Node* new_node=new Node();
    new_node->data=value;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        new_node->prev=NULL;
        (*head_ref)=new_node;
        return;
    }

    Node* last=(*head_ref);
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    new_node->prev=last;
    return;

}
