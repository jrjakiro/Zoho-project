#include "doubly_linked_list.h"
using namespace std;
int main() //drivercode
{
    doubly_linked_list_node *head = new doubly_linked_list_node();
    doubly_linked_list dll;


    dll.push(10); //pushing values at the front
    dll.push(25);
    dll.push(10); //pushing values at the front
    dll.push(25);
    dll.push(10); //pushing values at the front
    dll.push(25);
    dll.push(10); //pushing values at the front
    dll.push(25);
    dll.push(10); //pushing values at the front
    dll.push(25);


    dll.append(24); //pushing elements at the back

    dll.insert(33,1); //Inseting at a location


    cout << "Before Deletion,Values are ";
    dll.print_values(); //printing all values before deletion

    cout << "\nList Empty : " << dll.is_empty()<<"\n"; //checking whether the list is empty or not return 1 if it is empty

    dll.delete_node(25); //deleting the first node
    dll.delete_nodes(10); //deleting the first node


    cout << "\n After Deletion, Values are "; //Printing the values after deletion
    dll.print_values();

}