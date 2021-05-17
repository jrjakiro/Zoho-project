#include "doubly_linked_list.h" //Includes doubly_linked_list.h file

void doubly_linked_list ::push(int value)
{
    doubly_linked_list *new_node = new doubly_linked_list(); //new node creation

    new_node->data = value; //assigning argument value to new node data

    new_node->prev = NULL; //assigning the prev of new node as NULL because it becomes the first node

    new_node->next = (head); //new node will point to the head node

    if (head != NULL)
    {
        head->prev = new_node; //if head node is not empty then prev of head node will be assigned to the new node
    }

    head = new_node; //now the new node becomes the first node
}
