#include <iostream>
using namespace std;
// Node Creation
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(node *x, int value, node *y){
        data = value;
        prev = x;
        next = y;
    };

};

class doubly_linked_list
{ //class
    node *head=nullptr;
    node *tail=nullptr;
    int length = 0;

public:

    // insertion of value at front & back
    void push_front(int value);
    void push_back(int value);

    //for inserting at location
    void insert(int value, int location);

    //for removing values at front and back
    int remove_front();
    int remove_back();

    //for removing at a location and from a range
    void remove(int location);
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
//for  creating new node

//adding element at the front
void doubly_linked_list::push_front(int value){
    //new node creation
    node * new_node = new node(nullptr, value, head);

    //if head node is not empty then prev of head node will be assigned to the new node
    if (head != nullptr)
    {
        head->prev = new_node; 
    }
    //if the node is empty then both head and tail will point to the new node
    if (head == nullptr)
    {
        tail = new_node;
    }
    //now the new node becomes the first node
    head = new_node; 
    length++;
}
//add the element at the back
void doubly_linked_list::push_back(int value) {
    //new node creation
    node *new_node = new node(tail,value,nullptr);
    //if the list is not empty then tail node is not empty then next of tail node will be assigned to the new node
    if (tail!=nullptr)
    {
        tail->next = new_node; 
    }
    if (tail==nullptr)
    {
        head = new_node;
    }
    //now the new node becomes the last node
    tail = new_node; 
    length++;
}
//for inserting at a location
void doubly_linked_list::insert(int value, int location){
    if(location > length || location <0)
    {
        cout << "Invalid Location specified to Insert"<<endl;
    }
    else
    {
        if (location == 0){
            push_front(value);
            return;
        }
        else if (location == length){
            push_back(value);
            return;
        }
        else
        {
                //created temporary nodes which will point to previous and next node
            node *temp1 = head; 
            node *temp2;
            int count = 1;
                //iterating to insert at a position 
            while (count != location) {
                        // to check whether the location is present or not
                        //traversal till the condition is satisfied
                    temp1 = temp1->next;
                    count++; 
            }
                //new node has to be inserted after the temp1 node then temp1 is the previous node
                //temp2 node will be next node
            temp2 = temp1->next;
                //as the new node is inserted between two temp nodes,
            node* new_node=new node(temp1, value, temp2);
                //assigning values for the two before and after node.
            temp1->next = new_node; 
            temp2->prev = new_node;
            length++;
            return;
        }
    }
}

//for removing a node at front in the list
int doubly_linked_list::remove_front(){
    //to check whether the list is empty or not
    if (head == nullptr){
        cout << "No items in the list to delete"<<endl;
        return 0;
    }
    //if the list has only one item
    else if(head==tail){
        int value = head->data;
        delete (head);
        head = tail = nullptr;
        return value;
    }
    //if the list has two or more item
    else{
            // creating a temporary variable to store head node
        node *temp = head;
            //assigning the data to value in order to return
        int value = temp->data;
            //assigning the second nodes's prev pointer to null and change change head pointing to it
        temp->next->prev = nullptr;
        head = temp->next;
            //clearing the node and decreasing the size
        delete (temp);
        length--;
            //returning the value which is deleted 
        return value;
    }
}
//for removing last item in the list
int doubly_linked_list::remove_back(){
    if(tail==nullptr){
        cout << "No items in the list to delete"<<endl;
        return 0;
    }
    else if(head==tail){
        int value;
        delete (head);
        head = tail = nullptr;
        return value;
    }
    //if the list has two or more item
    else{
            // creating a temporary variable to store tail node
        node *temp = tail;
            //assigning the data to value in order to return
        int value = temp->data;
            //assigning the last second nodes's next pointer to null and change tail pointing to it
        temp->prev->next = nullptr;
        tail = temp->prev;
            //clearing the node and decreasing the size
        delete (temp);
        length--;
            //returning the value which is deleted 
        return value;
    }
}
//for removing node at a position
void doubly_linked_list::remove(int location){
    if(location>=length || location <0)
    {
        cout << "Invalid Location Specified to Remove"<<endl;
    }
    else
    {
        if (location == 0){
            remove_front();
            return;
        }
        else if (location == length-1){
            remove_back();
            return;
        }
        else{
            node *temp = head;
            int count = 1;
            //iterate to reach the right location
            while(count<=location){
                temp = temp->next;
                count++;
            }
            (temp->next)->prev = temp->prev;
            (temp->prev)->next = temp->next;
            //deleting the memory occupied
            delete (temp);
            length--;
            return;
        }
    }
}
//for deleting the nodes between from and two
void doubly_linked_list::remove(int start, int end){
    //checking whether the range is able to delete or not 
    if(start<0 || start>end || end>length){
        cout << "Invalid Range to Remove"<<endl;
    }
    else{
        node *current = head;
        int count = start;
        while (start <= end){
            remove(count);
            start++;
        }
    }
}

//clearing all the contents
void doubly_linked_list::clear(){
    //iterate till the last node
    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete (temp);
    }
    cout << "The List is Cleared" << endl;
    head = tail = nullptr;
    length = 0;
}

//prints the values in list
void doubly_linked_list::print_values() 
{
    cout << "\n";
    node *x = head;
    if (head == nullptr)
    {
        cout << "\nNo Items in the list and it is empty"<<endl;
    }

    while (x != nullptr) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\nsize is " << doubly_linked_list::size()<<endl; //prints the size for reference
};

//to find the size
size_t doubly_linked_list::size()
{
    return length;
}

//to check for empty or not
bool doubly_linked_list::is_empty()
{
    return (!(length));
}
