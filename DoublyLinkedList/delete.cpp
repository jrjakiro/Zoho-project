#include "doubly_linked_list.h" //including doubly_linked_list.h

void doubly_linked_list ::DeleteNode(int value) //for deletion of elements
{

    // base case that list is empty
    if (head == NULL)
    {
        cout << "The List contains no item to delete" << endl;
        return;
    }
    //if the node to be deleted is head node
    if (head->data == value)
    {
        free(head);
        head = head->next;
        return;
    }

    doubly_linked_list *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == value)
        {
            // Change next only if node to be deleted is NOT the last node
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            //Change prev only if node to be deleted is NOT the first node */
            if (temp->prev != NULL)
                temp->prev->next = temp->next;

            // Finally, free the memory occupied by del
            free(temp);
            return;
        }
        else
        {
            //move to the next node
            temp = temp->next;
        }
    }

    cout << "Given item is not found in the list";
    return;
}