#include <iostream>
using namespace std;
// Node Creation
class node
{
public:
    int data;
    node *next;
    node *prev;
};

class doubly_linked_list : private node
{ //class
    node *head;
    node *tail;
    int length = 0;

public:
    doubly_linked_list()
    {
        head = NULL;
    };
    // insertion of value at front
    void push_front(int value);
    //insertion of value at end
    void push_back(int value);

    //for removing values at front and back
    int remove_front();
    int remove_back();

    //for inserting at location
    void insert(int value, int location);

    //for removing at a location
    void remove_at(int location);
    void remove(int start, int end);

    //for finding the size
    size_t size();

    //check whether empty or not
    bool is_empty();

    //Printing of values
    void print_values();

    //to clear all the elements in the list
    void clear();

    int printtail();
};

void doubly_linked_list::push_front(int value)
{
    //new node creation
    node *new_node = new node();
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = (head);

    if (head != nullptr)
    {
        head->prev = new_node; //if head node is not empty then prev of head node will be assigned to the new node
    }
    if (head == nullptr)
    {
        tail = new_node;
    }
    length++;
    head = new_node; //now the new node becomes the first node
}
void doubly_linked_list::push_back(int value) //add the element at the back
{
    //new node creation
    node *new_node = new node();
    new_node->data = value;
    new_node->prev = tail;
    new_node->next = nullptr;

    if (tail != nullptr)
    {
        tail->next = new_node; //if tail node is not empty then prev of head node will be assigned to the new node
    }
    if (head == tail)
    {
        head = new_node;
    }
    length++;
    tail = new_node; //now the new node becomes the last node
}

int doubly_linked_list::remove_front()
{
    int temp = head->data;
    //assigning the prev of second node as NULL because it becomes the first node
    head->next->prev = nullptr;
    //new node will point to the head node
    head = head->next;
    //now the new node becomes the first node
    length--;
    return temp;
}
int doubly_linked_list::remove_back()
{
    //for finding the last node
    int temp=tail->data;
    tail->prev->next = nullptr;
    length--;
    tail=tail->prev;
    return temp;
}

void doubly_linked_list::insert(int value, int location) //for inserting at a location
{
    node *new_node = new node(); //new doubly_linked_list creation

    new_node->data = value; //new value is assigned to new node

    if (location == 0)
    {
        push_front(value);
        return;
    }
    else if(location==length)
    {
        push_back(value);
        return;
    }
    else
    {
        node *temp1 = head; //created temporary nodes
        node *temp2;
        int count = 1;

        while (count != location) //iterating to insert at a position
        {
            if (temp1->next == nullptr) // to check whether the location is present or not
            {
                cout << "Given node is not found in the list!!! \n";
                return;
            }
            else
            {
                temp1 = temp1->next;
                count++; //traversal till the condition is satisfied
            }
        }
        temp2 = temp1->next;    //as the new node is inserted between two temp nodes,
        temp1->next = new_node; // assigning the prev node of new node as temp1 and next node as temp2
        new_node->prev = temp1; //similarly in temp1 node next as new node and in temp2 node previous as new node
        new_node->next = temp2;
        temp2->prev = new_node;
        length++;
        return;
    }
}

void doubly_linked_list::remove_at(int location) //for inserting at a location
{
    if (location == 0)
    {
        int q = remove_front();
        return;
    }
    else if(location==length)
    {
        int q=remove_back();
        return;
    }
    // base case that list is empty
    if (head == nullptr)
    {
        cout << "The List contains no item to delete\n";
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp->next != nullptr)
    {
        if (count == location)
        {
            // Change next only if node to be deleted is NOT the last node
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            //Change prev only if node to be deleted is NOT the first node */
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;
            length--;
            // Finally, free the memory occupied by del
            return;
        }
        else
        {
            //move to the next node
            temp = temp->next;
            count++;
        }
    }

    return;
}

//for deleting the nodes between from and two
void doubly_linked_list::remove(int start, int end)
{
    node *current = head;
    int count = start;
    while (start <= end)
    {
        remove_at(count);
        start++;
    }
}

void doubly_linked_list::clear()
{
    node *current = head;
    node *temp;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        length--;
        delete (temp);
    }
    head = nullptr;
}

void doubly_linked_list::print_values() //prints the values in list
{
    node *x = head;
    if (head == nullptr)
    {
        cout << "\nNo Items in the list and it is empty";
    }

    while (x != nullptr) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\nsize is " << doubly_linked_list::size(); //prints the size for reference
};

//to find the size
size_t doubly_linked_list::size()
{
    return length;
}
//to check for empty or not
bool doubly_linked_list::is_empty()
{
    return (!(size()));
}
