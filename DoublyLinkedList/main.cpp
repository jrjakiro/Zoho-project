#include<iostream>
#include<stdio.h>
#include "header.h"
#include "printvalues.cpp"
#include "push.cpp"
#include "insertbefor.cpp"
#include "insertafter.cpp"
#include "append.cpp"


int main()
{
    head->push(&head,10);
    head->push(&head,25);
    head->append(&head,45);
    head->insertafter(head,55);
    head->insertbefore(&head,head,95);
    
    head->printvalues(head);
}