#include "header.h"

void Node :: printvalues(Node* x)
{
    while(x!=NULL)
    {
        cout<<x->data<<" ";
        x=x->next;
    }
    cout<<"\n";
};
