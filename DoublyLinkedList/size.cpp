#include "doubly_linked_list.h"
//to find the size
int doubly_linked_list ::FindSize()
{
    doubly_linked_list *x = head;

    int count = 0;
    while (x != NULL)
    {
        count++;
        x = x->next;
    }
    return count;
}
//to check for empty or not
bool doubly_linked_list ::isEmpty()
{
    return (!(FindSize()));
}
