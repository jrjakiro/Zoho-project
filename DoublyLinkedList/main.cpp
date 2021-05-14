#include<iostream>
#include<stdio.h>
#include "header.h"

int main()
{
    Node* head=new Node();

    head->push(&head,10);
    head->push(&head,25);
    head->append(&head,45);
    head->insertAfter(head,33,10);
    cout<<"size is"<<head->findSize(head)<<endl;
    cout<<"Values are ";
    head->printvalues(head);
    head->deleteNode(&head,head);
    cout<<"\n After Deletion, Values are ";
    head->printvalues(head);
    cout<<"List Empty:"<<head->isempty(head);


}