/*Beginning of the doubly linked list code header file
class name:doubly_linked_list 
list elements : head & tail of node *type,length of int type
node elements : data , next & prev of node* type
list methods  : (public) print_values(),push_front(),push_back(),insert(),remove_front(),remove_back(),remove(),size(),is_empty(),clear()
                (private) find_node()*/
//for preventing end user errors of multiple inclusion
#pragma once
#include <iostream>
//for including smart pointers
#include <memory>
using namespace std;
// Node Creation
template <class T>
class node
{
public:
    //making data as constant because it shouldn't be modified
    T data;
    //declaring as unique pointer because every next and prev varies
    std::shared_ptr<node<T>> next;
    std::shared_ptr<node<T>> prev;
    node(std::shared_ptr<node<T>> x, const T value,std::shared_ptr<node<T>> y);
    ~node();
};
//initialization of constructor
template <typename T>
node<T>::node(std::shared_ptr<node<T>> x, const T value,std::shared_ptr<node<T>> y)
{
    data = value;
    prev = x;
    next = y;
};
//initialization of destructor for ouput reference
template <typename T>
node<T>::~node()
{
    cout << "Destructor is called" << endl;
}

template <typename T>
class doubly_linked_list
{ //class
    int length = 0;
    //for finding node
    std::shared_ptr<node<T>> head;
    std::shared_ptr<node<T>> tail;

    std::shared_ptr<node<T>> find_node(const int location) const;

public:

    // constructor function
    doubly_linked_list() = default;
    //destructor function
    ~doubly_linked_list() = default;
    //initializing copy constructor with constant list
    doubly_linked_list(doubly_linked_list const &other) = default;
    // insertion of value at front & back
    void push_front(const T value);
    void push_back(const T value);

    //for inserting at location
    void insert(const T value, const int location);

    //for removing values at front and back
    T remove_front();
    T remove_back();

    //for removing at a location and from a range
    T remove(const int location);
    void remove(const int start, const int end);

    //for finding the size
    size_t size() const;

    //check whether empty or not
    bool is_empty() const;

    //Printing of values
    void print_values() const;

    //to clear all the elements in the list
    void clear();
};
//for  finding node at a position
template <typename T>
//made it as a const because no data should be modified because its purpose is to find a node
std::shared_ptr<node<T>> doubly_linked_list<T>::find_node(const int location) const
{
    std::shared_ptr<node<T>> temp = head;
    int count = 1;
    //iterating to insert at a position
    while (count <= location)
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
void doubly_linked_list<T>::push_front(const T value)
{
    insert(value, 0);
}
//add the element at the back
template <typename T>
void doubly_linked_list<T>::push_back(const T value)
{
    insert(value, length);
}
//for inserting at a location
template <typename T>
void doubly_linked_list<T>::insert(const T value, const int location)
{
    if (location > length || location < 0)
    {
        cout << "Invalid Location specified to Insert" << endl;
        return;
    }

    if (location == 0)
    {
        //new node creation
        std::shared_ptr<node<T>> new_node = std::make_shared<node<T>>(nullptr, value, head);

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
        std::shared_ptr<node<T>> new_node = std::make_shared<node<T>>(tail, value, nullptr);

        //if the list is not empty then tail node is not empty then next of tail node will be assigned to the new node
        if (!tail)
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
    std::shared_ptr<node<T>> temp1 = find_node(location);
    //new node has to be inserted after the temp1 node then temp1 is the previous node
    //temp2 node will be next node
    std::shared_ptr<node<T>> temp2 = temp1->next;
    //as the new node is inserted between two temp nodes,
    std::shared_ptr<node<T>> new_node = std::make_shared<node<T>>(temp1, value, temp2);

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
    //checking for the invalid location
    if (location >= length || location < 0)
    {
        cout << "Invalid Location Specified to Remove" << endl;
        return 0;
    }
    //to check whether the list is empty or not
    if (head == nullptr)
    {
        cout << "No items in the list to delete" << endl;
        return 0;
    }
    std::shared_ptr<node<T>> temp = find_node(location);
    //if the list has only one item which is both head and tail node
    if (head == tail)
    {
        T value = temp->data;
        head = tail = nullptr;
        //delete (temp);
        length--;
        return value;
    }
    //it means to delete the head node
    if (temp->prev == nullptr)
    {
        head = head->next;
        head->prev = nullptr;
        T value = temp->data;
        //delete (temp);
        length--;
        return value;
    }
    //it means to delete the tail node
    if (temp->next == nullptr)
    {
        tail = tail->prev;
        tail->next = nullptr;
        T value = temp->data;
        //delete (temp);
        length--;
        return value;
    }
    //ususal case to delete the node
    (temp->next)->prev = temp->prev;
    (temp->prev)->next = temp->next;
    //deleting the memory occupied
    //delete (temp);
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
    std::shared_ptr<node<T>> current = head;
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

//prints the values in list and it is constant because it should not modify the contents of links
template <class T>
void doubly_linked_list<T>::print_values() const
{
    cout << "\n";
    std::shared_ptr<node<T>> x = head;
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
size_t doubly_linked_list<T>::size() const
{
    return length;
}

//to check for empty or not
template <typename T>
bool doubly_linked_list<T>::is_empty() const
{
    return (length == 0);
}

//end of doubly_linked_list header
