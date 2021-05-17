#include <stdio.h>
#include "doubly_linked_list.h"

int main() //drivercode
{
    doubly_linked_list dll;

    doubly_linked_list *head = new doubly_linked_list;

    dll.push(10); //pushing values at the front
    dll.push(25);

    dll.append(24); //pushing elements at the back

    dll.Insert(33,2); //Inseting at a location

    cout << "\nsize is " << (dll.FindSize()) << endl; //printing the size

    cout << "Before Deletion,Values are ";
    dll.PrintVal(); //printing all values before deletion

    cout << "List Empty : " << dll.isEmpty(); //checking whether the list is empty or not return 1 if it is empty

    dll.DeleteNode(25); //deleting the first node

    cout << "\n After Deletion, Values are "; //Printing the values after deletion
    dll.PrintVal();

}