#include<iostream>
#include<stdio.h>
#include "header.h"

int main()                                                       //drivercode
{
    Node* head=new Node();                                       //head Node creation

    head->push(&head,10);                                        //pushing elements at the front
    head->push(&head,25);

    head->append(&head,45);                                      //pushing elements at the back

    head->Insert(head,33,10);                                    //Inseting at a location

    cout<<"\nsize is "<<(head->FindSize(head))<<endl;                 //printing the size

    cout<<"Before Deletion,Values are ";                                            
    head->PrintVal(head);                                         //printing all values before deletion

    cout<<"List Empty : "<<head->isEmpty(head);                     //checking whether the list is empty or not return 1 if it is empty


    head->DeleteNode(&head,head);                                  //deleting the first node 

    cout<<"\n After Deletion, Values are ";                        //Printing the values after deletion
    head->PrintVal(head);


}