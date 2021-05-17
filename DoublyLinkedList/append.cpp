#include "doubly_linked_list.h" //included the header file

void doubly_linked_list ::append(int value) //add the element at the back
{
    doubly_linked_list *new_node = new doubly_linked_list(); //creation of new node

    new_node->data = value; //since it will become the last node we are adding data as value and next as Null
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL; //if head is null then it means the list is empty
        head = new_node;       //so making new node as the first node
        return;
    }

    doubly_linked_list *last = (head); //for finding the last node

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node; //assign next value of last node as new node and new node of prev as last node
    new_node->prev = last;
    return;
}
