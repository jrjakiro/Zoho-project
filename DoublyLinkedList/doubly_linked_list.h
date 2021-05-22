#include <iostream>
using namespace std;
// Node Creation
template <class T>
class node
{
public:
    T data;
    node *next;
    node *prev;
    node(node *x, T value, node *y);
};
template <typename T>
node<T>::node(node *x, T value, node *y)
{
    data = value;
    prev = x;
    next = y;
};
template <typename T>
class doubly_linked_list
{ //class
    node<T> *head = nullptr;
    node<T> *tail = nullptr;
    int length = 0;
    //for finding node
    node<T> *find_node(int location);

public:
    // insertion of value at front & back
    void push_front(T value);
    void push_back(T value);

    //for inserting at location
    void insert(T value, int location);

    //for removing values at front and back
    T remove_front();
    T remove_back();

    //for removing at a location and from a range
    T remove(int location);
    void remove(int start, int end);

    //for finding the size
    size_t size();

    //check whether empty or not
    bool is_empty();

    //Printing of values
    void print_values();

    //to clear all the elements in the list
    void clear();
};
//for  finding node at a position
template <typename T>
node<T> *doubly_linked_list<T>::find_node(int location)
{
    node<T> *temp = head;
    int count = 1;
    //iterating to insert at a position
    while (count != location)
    {
        // to check whether the location is present or not
        //traversal till the condition is satisfied
        temp = temp->next;
        count++;
    }
    return (temp);
}

//adding element at the front
template <typename T>
void doubly_linked_list<T>::push_front(T value)
{
    insert(value, 0);
}
//add the element at the back
template <typename T>
void doubly_linked_list<T>::push_back(T value)
{
    insert(value, length);
}
//for inserting at a location
template <typename T>
void doubly_linked_list<T>::insert(T value, int location)
{
    if (location > length || location < 0)
    {
        cout << "Invalid Location specified to Insert" << endl;
        return;
    }

    if (location == 0)
    {
        //new node creation
        node<T> *new_node = new node<T>(nullptr, value, head);

        //if head node is not empty then prev of head node will be assigned to the new node
        if (head != nullptr)
        {
            head->prev = new_node;
        }
        //if the node is empty then both head and tail will point to the new node
        else
        {
            tail = new_node;
        }
        //now the new node becomes the first node
        head = new_node;
        length++;
        return;
    }
    if (location == length)
    {
        //new node creation
        node<T> *new_node = new node<T>(tail, value, nullptr);

        //if the list is not empty then tail node is not empty then next of tail node will be assigned to the new node
        if (tail != nullptr)
        {
            tail->next = new_node;
        }
        else
        {
            head = new_node;
        }
        //now the new node becomes the last node
        tail = new_node;
        length++;
        return;
    }

    //created temporary nodes which will point to previous and next node
    node<T> *temp1 = find_node(location);
    //new node has to be inserted after the temp1 node then temp1 is the previous node
    //temp2 node will be next node
    node<T> *temp2 = temp1->next;
    //as the new node is inserted between two temp nodes,
    node<T> *new_node = new node<T>(temp1, value, temp2);
    //assigning values for the two before and after node.
    temp1->next = new_node;
    temp2->prev = new_node;
    length++;
    return;
}

//for removing a node at front in the list
template <typename T>
T doubly_linked_list<T>::remove_front()
{
    return remove(0);
}
//for removing last item in the list
template <typename T>
T doubly_linked_list<T>::remove_back()
{
    return remove(length - 1);
}
//for removing node at a position
template <typename T>
T doubly_linked_list<T>::remove(int location)
{
    if (location >= length || location < 0)
    {
        cout << "Invalid Location Specified to Remove" << endl;
        return 0;
    }
    if (location == 0)
    {
        //to check whether the list is empty or not
        if (head == nullptr)
        {
            cout << "No items in the list to delete" << endl;
            return 0;
        }
        //if the list has only one item
        if (head == tail)
        {
            T value = head->data;
            delete (head);
            head = tail = nullptr;
            length--;
            return value;
        }
        //if the list has two or more item

        // creating a temporary variable to store head node
        node<T> *temp = head;
        //assigning the data to value in order to return
        T value = temp->data;
        //assigning the second nodes's prev pointer to null and change change head pointing to it
        temp->next->prev = nullptr;
        head = temp->next;
        //clearing the node and decreasing the size
        delete (temp);
        length--;
        //returning the value which is deleted
        return value;
    }
    if (location == length - 1)
    {
        if (tail == nullptr)
        {
            cout << "No items in the list to delete" << endl;
            return 0;
        }
        if (head == tail)
        {
            T value;
            delete (head);
            head = tail = nullptr;
            length--;
            return value;
        }
        //if the list has two or more item
        // creating a temporary variable to store tail node
        node<T> *temp = tail;
        //assigning the data to value in order to return
        T value = temp->data;
        //assigning the last second nodes's next pointer to null and change tail pointing to it
        temp->prev->next = nullptr;
        tail = temp->prev;
        //clearing the node and decreasing the size
        delete (temp);
        length--;
        //returning the value which is deleted
        return value;
    }

    node<T> *temp = find_node(location);
    (temp->next)->prev = temp->prev;
    (temp->prev)->next = temp->next;
    //deleting the memory occupied
    delete (temp);
    length--;
    return 0;
}
template <typename T>
//for deleting the nodes between from and two
void doubly_linked_list<T>::remove(int start, int end)
{
    //checking whether the range is able to delete or not
    if (start < 0 || start > end || end > length)
    {
        cout << "Invalid Range to Remove" << endl;
        return;
    }
    node<T> *current = head;
    int count = start;
    while (start <= end)
    {
        remove(count);
        start++;
    }
}

//clearing all the contents
template <typename T>
void doubly_linked_list<T>::clear()
{
    //iterate till the last node
    while (head != nullptr)
    {
        remove_front();
    }
    cout << "The List is Cleared" << endl;
}

//prints the values in list
template <class T>
void doubly_linked_list<T>::print_values()
{
    cout << "\n";
    node<T> *x = head;
    if (head == nullptr)
    {
        cout << "\nNo Items in the list and it is empty" << endl;
    }

    while (x != nullptr) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\nsize is " << doubly_linked_list::size() << endl; //prints the size for reference
};

//to find the size
template <typename T>
size_t doubly_linked_list<T>::size()
{
    return length;
}

//to check for empty or not
template <typename T>
bool doubly_linked_list<T>::is_empty()
{
    return (length == 0);
}
