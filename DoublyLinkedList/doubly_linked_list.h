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

class doubly_linked_list:private node
{ //class
        node *head;


public:      
        doubly_linked_list(){
            head=NULL;
        };   
         // insertion of value at front                                          
        void push_front(int value);
        //insertion of value at end
        void push_back(int value);

        //for inserting at location
        void insert(int value, int location); 
        
        //for deleting a node
        void delete_node(int value); 
        //for deleting several nodes
        void delete_nodes(int value); 

        //for finding the size
        size_t size(); 
        
        //check whether empty or not
        bool is_empty(); 
        
        //Printing of values
        void print_values(); 

        //for removing values at front and back
        void remove_front();
        void remove_back();

        //to clear all the elements in the list
        void clear();
};


void doubly_linked_list::push_front(int value)
{
    node *new_node = new node(); //new node creation

    new_node->data = value; //assigning argument value to new node data

    new_node->prev = nullptr; //assigning the prev of new node as NULL because it becomes the first node

    new_node->next = (head); //new node will point to the head node

    if (head != nullptr)
    {
        head->prev = new_node; //if head node is not empty then prev of head node will be assigned to the new node
    }

    head = new_node; //now the new node becomes the first node
}

void doubly_linked_list::push_back(int value) //add the element at the back
{
    node *new_node = new node(); //creation of new node

    new_node->data = value; //since it will become the last node we are adding data as value and next as nullptr
    new_node->next = nullptr;

    if (head == nullptr)
    {
        new_node->prev = nullptr; //if head is null then it means the list is empty
        head = new_node;       //so making new node as the first node
        return;
    }

    node *last = (head); //for finding the last node

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = new_node; //assign next value of last node as new node and new node of prev as last node
    new_node->prev = last;
    return;
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
   else
   {
      node *temp1 = head; //created temporary nodes
      node *temp2;
      int count=1;

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
      temp2 = temp1->next;   //as the new node is inserted between two temp nodes,
      temp1->next = new_node; // assigning the prev node of new node as temp1 and next node as temp2
      new_node->prev = temp1; //similarly in temp1 node next as new node and in temp2 node previous as new node
      new_node->next = temp2;
      temp2->prev = new_node;

      cout << "\ninsertion success!!!\n";
   }
}

void doubly_linked_list::delete_node(int value) //for deletion of elements
{

    // base case that list is empty
    if (head == nullptr)
    {
        cout << "The List contains no item to delete\n";
        return;
    }
    //if the node to be deleted is head node
    if (head->data == value)
    {
        head = head->next;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->data == value)
        {
            // Change next only if node to be deleted is NOT the last node
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            //Change prev only if node to be deleted is NOT the first node */
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;

            // Finally, free the memory occupied by del
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
void doubly_linked_list::delete_nodes(int value) //for deletion of elements
{
     node *x = head;
    while (x != nullptr) //iterate till the last
    {
        if(x->data==value)
        {
            delete_node(value);
        }
        x=x->next;
    }

}
void doubly_linked_list::remove_front()
{
    //assigning the prev of second node as NULL because it becomes the first node
    head->next->prev=nullptr;
    //new node will point to the head node
    head = head->next; //now the new node becomes the first node

}
void doubly_linked_list::remove_back()
{
    //for finding the last node
    node *last = (head); 


    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->prev->next = nullptr;    
     return;

}

void doubly_linked_list::clear()
{
    node *current= head;
    node *temp;
    while(current!=nullptr)
    {
        temp=current;
        current=current->next;
        delete(temp);
    }
    head=nullptr;
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
    cout << "\nsize is " << doubly_linked_list::size() ; //prints the size for reference
};

//to find the size
size_t doubly_linked_list::size()
{
    node *x = head;

    int count = 0;
    while (x != nullptr)
    {
        count++;
        x = x->next;
    }
    return count;
}
//to check for empty or not
bool doubly_linked_list::is_empty()
{
    return (!(size()));
}
