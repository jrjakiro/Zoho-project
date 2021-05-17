#include <iostream>
using namespace std;
// Node Creation
class doubly_linked_list
{ //class
        int data;
        doubly_linked_list *next;
        doubly_linked_list *prev;
        doubly_linked_list *head=nullptr;


public:                                                      //Access specifier
        void push(int value); // insertion of value at front

        void append(int value); //insertion of value at end

        void insert(int value, int location); //for inserting at location

        void delete_node(int value); //for deleting a node

        int find_size(); //for finding the size

        bool empty(); //check whether empty or not

        void print_values(); //Printing of values
};


void doubly_linked_list::push(int value)
{
    doubly_linked_list *new_node = new doubly_linked_list(); //new node creation

    new_node->data = value; //assigning argument value to new node data

    new_node->prev = nullptr; //assigning the prev of new node as NULL because it becomes the first node

    new_node->next = (head); //new node will point to the head node

    if (head != nullptr)
    {
        head->prev = new_node; //if head node is not empty then prev of head node will be assigned to the new node
    }

    head = new_node; //now the new node becomes the first node
}

//to find the size
int doubly_linked_list ::find_size()
{
    doubly_linked_list *x = head;

    int count = 0;
    while (x != nullptr)
    {
        count++;
        x = x->next;
    }
    return count;
}
//to check for empty or not
bool doubly_linked_list ::empty()
{
    return (!(find_size()));
}

void doubly_linked_list ::append(int value) //add the element at the back
{
    doubly_linked_list *new_node = new doubly_linked_list(); //creation of new node

    new_node->data = value; //since it will become the last node we are adding data as value and next as nullptr
    new_node->next = nullptr;

    if (head == nullptr)
    {
        new_node->prev = nullptr; //if head is null then it means the list is empty
        head = new_node;       //so making new node as the first node
        return;
    }

    doubly_linked_list *last = (head); //for finding the last node

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = new_node; //assign next value of last node as new node and new node of prev as last node
    new_node->prev = last;
    return;
}
void doubly_linked_list ::insert(int value, int location) //for inserting at a location
{
   doubly_linked_list *new_node = new doubly_linked_list(); //new doubly_linked_list creation

   new_node->data = value; //new value is assigned to new node

   if (location == 0)
   {
     push(value);
     return;
   }
   else
   {
      doubly_linked_list *temp1 = head; //created temporary nodes
      doubly_linked_list *temp2;
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


void doubly_linked_list ::delete_node(int value) //for deletion of elements
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
        free(head);
        head = head->next;
        return;
    }

    doubly_linked_list *temp = head;
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

void doubly_linked_list ::print_values() //prints the values in list
{
    doubly_linked_list *x = head;
    if (head == nullptr)
    {
        cout << "No Items in the list and it is empty";
    }

    while (x != nullptr) //iterate till the last
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << "\n size is " << doubly_linked_list::find_size() ; //prints the size for reference
};

