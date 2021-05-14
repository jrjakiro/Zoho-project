#include<iostream>
#include<stdio.h>
#include "header.h"

int main()
{
    Node* head=new Node();

    head->push(&head,10);
    head->push(&head,25);
    head->append(&head,45);
    head->insertafter(head,55);
    head->insertbefore(&head,head,95);
    
    head->printvalues(head);
}