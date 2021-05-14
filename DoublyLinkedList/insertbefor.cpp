#include "header.h"

void Node::insertbefore(Node** head_ref,Node* afternode,int value)
{
    if(afternode==NULL)
    {
        cout<<"afternode should not be null";
        return;
    }
    Node* new_node=new Node();
    new_node->data=value;
    new_node->prev=afternode->prev;
    afternode->prev=new_node;
    new_node->next=afternode;
    if(new_node->prev!=NULL)
    {
        new_node->prev->next=new_node;
    }
    else
    {
        (*head_ref)=new_node;
    }
    
}
