#include "header.h"

void Node::insertafter(Node* prevnode,int value)
{
    if(prevnode==NULL)
    {
                cout<<"The previous node should not be null";
                return;
    }
    Node* new_node=new Node();
    new_node->data=value;
    new_node->prev=prevnode;
    new_node->next=prevnode->next;
    prevnode->next=new_node;
    
}
