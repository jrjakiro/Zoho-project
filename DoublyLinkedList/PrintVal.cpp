#include "doubly_linked_list.h" //including header file

void doubly_linked_list ::PrintVal() //prints the values in list
{
    doubly_linked_list *x = head;
    if (head == NULL)
    {
        cout << "No Items in the list and it is empty";
    }

    while (x != NULL) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\n size is " << doubly_linked_list::FindSize() << endl; //prints the size for reference
};
