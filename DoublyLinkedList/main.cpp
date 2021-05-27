
#include "doubly_linked_list.h"
#include "string.h"
using namespace std;
int main() //drivercode
{
    doubly_linked_list<int> dli;
    doubly_linked_list<float> dlf;
    doubly_linked_list<char> dlc;
    doubly_linked_list<string> dls;
    doubly_linked_list<long> dll;
    doubly_linked_list<double> dld;
    dls.push_front("HELLO");
    dls.print_values();

    dli.push_front(10); //push_fronting values at the front
    dli.push_front(25);
    dli.push_front(10); //push_fronting values at the front
    dli.push_front(25);
    dli.push_front(10); //push_fronting values at the front
    dli.push_front(25);
    dli.push_front(10); //push_fronting values at the front
    dli.push_front(25);
    dli.push_front(10); //push_fronting values at the front
    dli.push_front(25);

    dli.push_back(24); //push_fronting elements at the back

    dli.insert(33, 1); //Inseting at a location

    cout << "Before Deletion,Values are ";
    dli.print_values(); //printing all values before deletion

    cout << "\nAfter removing the first value " << dli.remove_front() << endl;
    dli.print_values();

    cout << "\nAfter removing the last value " << dli.remove_back() << endl;
    dli.print_values();

    dli.remove(2);
    cout << "\nAfter removing the second value ";
    dli.print_values();

    dli.remove(3, 5);
    cout << "\nAfter removing the 3rd-5th  value ";
    dli.print_values();

    cout << "\nList Empty : " << dli.is_empty() << "\n"; //checking whether the list is empty or not return 1 if it is empty

    cout << "\nAfter Deletion, Values are "; //Printing the values after deletion
    dli.print_values();

    //clearing the list
    dli.clear();
    cout << "\nAfter Clearing size of list is " << dli.size();
    dli.print_values();

    cout << "\nList Empty : " << dli.is_empty() << "\n"; //checking whether the list is empty or not return 1 if it is empty
}