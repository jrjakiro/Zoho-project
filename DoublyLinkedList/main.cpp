
#include "doubly_linked_list.h"
using namespace std;
int main() //drivercode
{
    doubly_linked_list dll;

    dll.push_front(10); //push_fronting values at the front
    dll.push_front(25);
    dll.push_front(10); //push_fronting values at the front
    dll.push_front(25);
    dll.push_front(10); //push_fronting values at the front
    dll.push_front(25);
    dll.push_front(10); //push_fronting values at the front
    dll.push_front(25);
    dll.push_front(10); //push_fronting values at the front
    dll.push_front(25);

    dll.push_back(24); //push_fronting elements at the back

    dll.insert(33,1); //Inseting at a location

    cout << "Before Deletion,Values are ";
    dll.print_values(); //printing all values before deletion

    cout << "\nAfter removing the first value "<<dll.remove_front()<<endl;
    dll.print_values();

    cout << "\nAfter removing the last value "<<dll.remove_back()<<endl;
    dll.print_values();

    dll.remove_at(2);
    cout << "\nAfter removing the second value ";
    dll.print_values();


    dll.remove(3,5);
    cout << "\nAfter removing the 3rd-5th  value ";
    dll.print_values();

    cout << "\nList Empty : " << dll.is_empty()<<"\n"; //checking whether the list is empty or not return 1 if it is empty

    cout << "\nAfter Deletion, Values are "; //Printing the values after deletion
    dll.print_values();

    //clearing the list
    dll.clear();
    cout<< "\nAfter Clearing size of list is "<<dll.size();
    dll.print_values();

    cout << "\nList Empty : " << dll.is_empty()<<"\n"; //checking whether the list is empty or not return 1 if it is empty



}