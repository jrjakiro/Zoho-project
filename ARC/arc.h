/*
Implementation of Adaptive Replacement Cache Algorithm 
contents: Implementation of queues using linked list
class name :arc,qnode,Queue

types of queues:    
    * mrug (B1)- Most Recently Used Ghost
    * mru (T1) - Most Recently Used
    * mfu (T2) - Most Frequently Used
    * mfug (B2) - Most Frequently Used Ghost
*/
//prevention of end user multiple inclusion
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
//for calculating time
#include <time.h>
#include <math.h>
using namespace std;

#define HASHSIZE 1000
//for finding maximum and minimum in the calculation of p
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//global declarations of variable
unsigned int icache_size = 0;
unsigned int imiss_count = 0;
unsigned int ihit_count = 0;
unsigned int hash[HASHSIZE];
//declaration of Queue node using doubly linked list
class qnode
{
public:
    //for storing page number
    unsigned int ipage_number;
    //node pointers
    qnode *next;
    qnode *prev;
    qnode(unsigned int page_number)
    {
        ipage_number = page_number;
        next = nullptr;
        prev = nullptr;
    }
};
//declaration of FIFO queue using doubly linked list
class Queue
{
public:
    //no of frames filled
    unsigned int icount;
    //total number of frames
    unsigned int inumber_of_frames;
    //queue pointers
    qnode *front = nullptr;
    qnode *rear = nullptr;
    /*
    for storing name of queue which are
    * mrug (B1)- Most Recently Used Ghost
    * mru (T1) - Most Recently Used
    * mfu (T2) - Most Frequently Used
    * mfug (B2) - Most Frequently Used Ghost
    */
    char *name;
    Queue(unsigned int number_of_frames)
    {
        //since The queue is empty
        icount = 0;
        //Number of frames that can be stored in memory
        inumber_of_frames = number_of_frames;
    }
};
class arc
{
public:
    //capacity
    unsigned int c;
    //for adaptive replacement
    float p = 0;
    //initialization of queue
    Queue *mrug, *mru, *mfu, *mfug;

    //Methods
    //for creating new node
    qnode *new_node(unsigned int page_number);
    //for creating new queue
    Queue *create_queue(unsigned int number_of_frames);
    //function to check the queue is full or not
    bool isqueue_full(Queue *queue);
    //function to check the queue is empty or not
    bool isqueue_empty(Queue *queue);
    //function to delete a node from queue
    void delete_node(Queue *queue, qnode *req_page);
    //for printing elements in all lists of cache
    void print_values();
    //function to add a page with given 'page_number' to queue.
    void enqueue(Queue *queue, unsigned int page_number);
    //function to refer page from cache
    qnode *reference_page(Queue *queue, unsigned int ipage_number);
    //function to move page_number from one queue to another
    void move(Queue *from_queue, Queue *to_queue, qnode *req_page);
    //function to move the elements from T2 to B2 or T1 to B1
    void replace(const unsigned int ipage_number, const float p);
    //function to find an object with given key
    void find(const unsigned int ikey_page_number);
    //function to initialize values of vairable structure of queue
    void arc_queue_init(Queue *queue, unsigned int number_of_frames, char *name);
    //function to initialize the cache structure
    void arc_cache_init(const unsigned int icache_size);
};
//function to create a new node and store page number in it
qnode *arc::new_node(unsigned int page_number)
{
    //creating a new node
    qnode *temp = new qnode(page_number);
    return temp;
}
//for creating empty queue
Queue *arc::create_queue(unsigned int number_of_frames)
{
    //creation of queue
    Queue *queue = new Queue(number_of_frames);
    return queue;
}
//function to check the queue is full or not
bool arc::isqueue_full(Queue *queue)
{
    return queue->icount == queue->inumber_of_frames;
}
//function to check the queue is empty or not
bool arc::isqueue_empty(Queue *queue)
{
    
    return queue->front==nullptr;
}
//function to delete a node from queue
void arc::delete_node(Queue *queue, qnode *req_page)
{
    //availability check
    if (req_page == nullptr)
    {
        cout << "Requested Page is Not Available" << endl;
        return;
    }
    //case 1: only one node is present in the queue
    if ((queue->front == req_page) && (queue->rear == req_page))
    {
        queue->front = nullptr;
        queue->rear = nullptr;
    }
    //case 2:required node is at front
    else if (queue->front == req_page)
    {
        queue->front = req_page->next;
        queue->front->prev = nullptr;
    }
    //case 3:required node is at rear
    else if (queue->rear == req_page)
    {
        queue->rear = req_page->prev;
        queue->rear->next = nullptr;
    }
    //default case
    else
    {
        req_page->prev->next = req_page->next;
        req_page->next->prev = req_page->prev;
    }

    free(req_page);
    // decrement the number of filled frames
    queue->icount--;
}
//for printing elements in all lists of cache
void arc::print_values()
{
    //printing the elements in Most Recently Used Queue
    Queue *queue = mru;
    cout << "T1 :-"
         << " name: " << queue->name << " count: " << queue->icount << "/" << p;
    qnode *head = queue->front;
    while (head != nullptr)
    {
        printf("%d ", head->ipage_number);
        head = head->next;
    }
    if (queue->front)
        cout << "\tFront : " << queue->front->ipage_number;
    if (queue->rear)
        cout << "\tRear : " << queue->rear->ipage_number;
    cout << endl;

    //printing the elements in Most Recently used Ghost Queue
    queue = mrug;
    cout << "B1 :-"
         << " name: " << queue->name << " count: " << queue->icount << "/" << p;
    head = queue->front;
    while (head != nullptr)
    {
        printf("%d ", head->ipage_number);
        head = head->next;
    }
    if (queue->front)
        cout << "\tFront : " << queue->front->ipage_number;
    if (queue->rear)
        cout << "\tRear : " << queue->rear->ipage_number;
    cout << endl;

    //printing the elements in Most Frequently Used Queue
    queue = mfu;
    cout << "T2 :-"
         << " name: " << queue->name << " count: " << queue->icount << "/" << p;
    head = queue->front;
    while (head != nullptr)
    {
        printf("%d ", head->ipage_number);
        head = head->next;
    }
    if (queue->front)
        cout << "\tFront : " << queue->front->ipage_number;
    if (queue->rear)
        cout << "\tRear : " << queue->rear->ipage_number;
    cout << endl;

    //printing the elements in Most Frequently used Ghost Queue
    queue = mfug;
    cout << "B2 :-"
         << " name: " << queue->name << " count: " << queue->icount << "/" << p;
    head = queue->front;
    while (head != nullptr)
    {
        printf("%d ", head->ipage_number);
        head = head->next;
    }
    if (queue->front)
        cout << "\tFront : " << queue->front->ipage_number;
    if (queue->rear)
        cout << "\tRear : " << queue->rear->ipage_number;
    cout << endl;
}
//function to add a page with given 'page_number' to queue.
void arc::enqueue(Queue *queue, unsigned int page_number)
{
    //Create a new node with given page number
    qnode *temp = new_node(page_number);
    // add the new node to the front of queue
    temp->next = queue->front;
    //case 1:queue is empty
    if (isqueue_empty(queue))
    {
        queue->front = temp;
        queue->rear = queue->front;
    }
    //case 2 : default
    else
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    //increment number of filled frames
    queue->icount++;
}
//function to refer page from cache
qnode *arc::reference_page(Queue *queue, unsigned int ipage_number)
{
    //initializing an empty node
    qnode *req_page = nullptr;

    //Check if the page being referenced is already present in the queue of nodes or not
    qnode *temp_req_page = nullptr;
    for (temp_req_page = queue->front; temp_req_page; temp_req_page = temp_req_page->next)
    {
        if (temp_req_page->ipage_number == ipage_number)
        {
            req_page = temp_req_page;
            //returns pointer to the node if page is present
            return req_page;
        }
    }
    //returns null if page is not there
    return req_page;
}
//function to move page_number from one queue to another
void arc::move(Queue *from_queue, Queue *to_queue, qnode *req_page)
{
    //removing element from the from_queue
    //case 1: only one node is present in the queue
    if ((from_queue->front == req_page) && (from_queue->rear == req_page))
    {
        from_queue->front = nullptr;
        from_queue->rear = nullptr;
    }
    //case 2:required node is at front
    else if (from_queue->front == req_page)
    {
        from_queue->front = req_page->next;
        from_queue->front->prev = nullptr;
    }
    //case 3:required node is at rear
    else if (from_queue->rear == req_page)
    {
        from_queue->rear = req_page->prev;
        from_queue->rear->next = nullptr;
    }
    //default case
    else
    {
        req_page->prev->next = req_page->next;
        req_page->next->prev = req_page->prev;
    }
    //decrement the number of pages in from_queue
    from_queue->icount--;
    //adding the req_page at the front of to_queue
    req_page->next = to_queue->front;
    //changing the front of to_queue
    //case 1:  queue is empty
    if (isqueue_empty(to_queue))
    {
        to_queue->front = req_page;
        to_queue->rear = to_queue->front;
    }
    //default case
    else
    {
        to_queue->front->prev = req_page;
        to_queue->front = req_page;
    }
    //Increment the number of pages in to_queue
    to_queue->icount++;
}
//function to move the elements from T2 to B2 or T1 to B1
void arc::replace(const unsigned int ipage_number, const float p)
{
    if ((mru->icount >= 1) && ((mru->icount > p) || ((nullptr != reference_page(mfug,ipage_number)) && (p == mru->icount))))
    {
        if (mru->rear)
        {
            move(mru, mrug, mru->rear);
        }
    }
    else
    {
        if (mfu->rear)
        {
            move(mfu, mfug, mfu->rear);
        }
    }
}
//function to find an object with given key
void arc::find(const unsigned int ikey_page_number)
{
    qnode *req_page = nullptr;
    //Case 1: Part A: Page Found in MRU
    if (nullptr != (req_page = reference_page(mru, ikey_page_number)))
    {
        cout << "HIT Page found in MRU(T1)" << endl;
        //Increment the hit count
        ihit_count++;

        //Move element to MRU position in T2
        move(mru, mfu, req_page);
    }
    //Case 2: Part B: Page Found in MFU (T2)
    else if (nullptr != (req_page = reference_page(mfu, ikey_page_number)))
    {
        cout << "HIT : Page found in MRU(T1)" << endl;
        //Increment the hit count
        ihit_count++;

        //Move element to MRU position in T2
        move(mfu, mfu, req_page);
    }
    //Case 3: Page Found in MRUG (B1)
    else if (nullptr != (req_page = reference_page(mrug, ikey_page_number)))
    {
        cout << "MISS : Page found in MRUG" << endl;
        //increment the miss count
        imiss_count++;
        //assigning as per the formula
        p = (float)MIN((float)c, (p + MAX((mfug->icount * 1.0) / mrug->icount, 1.0)));
        replace(ikey_page_number, p);

        //Move element from B1 to the MRU position in T2
        move(mrug, mfu, req_page);
    }
    //Case 4: Page Found in MFUG (B2)
    else if (nullptr != (req_page = reference_page(mfug, ikey_page_number)))
    {
        cout << "MISS : Page found in MFUG " << endl;
        imiss_count++;
        //assigning as per the formula
        p = (float)MAX(0.0, (float)(p - MAX((mrug->icount * 1.0) / mfug->icount, 1.0)));
        replace(ikey_page_number, p);

        //Move element from B2 to the MRU position in T2
        move(mfug, mfu, req_page);
    }
    //Case 5: Page Not Found in MRU, MRUG, MFU, MFUG
    else
    {
        cout << "Page not Found" << endl;
        imiss_count++;
        //Case 1: L1 has c pages
        if ((mru->icount + mrug->icount) == c)
        {
            if (mru->icount < c)
            {
                ::hash[mrug->rear->ipage_number % HASHSIZE]--;

                //Delete LRU page in B1
                delete_node(mrug, mrug->rear);
                replace(ikey_page_number, p);
            }
            else
            {
                //Here B1 is empty. Delete LRU page in T1 (also remove it from the cache).
                ::hash[mru->rear->ipage_number % HASHSIZE]--;

                //Delete LRU page in T1
                delete_node(mru, mru->rear);
            }
        }
        //Case 2: L1 has less than c pages
        else if ((mru->icount + mrug->icount) < c)
        {
            if ((mru->icount + mfu->icount + mrug->icount + mfug->icount) >= c)
            {
                if ((mru->icount + mfu->icount + mrug->icount + mfug->icount) == (2 * c))
                {
                    ::hash[mfug->rear->ipage_number % HASHSIZE]--;

                    //Delete LRU page in B2
                    delete_node(mfug, mfug->rear);
                }
                replace(ikey_page_number, p);
            }
        }
        //Fetch xt to the cache and move it to MRU position in T1
        enqueue(mru, ikey_page_number);
        ::hash[ikey_page_number % HASHSIZE]++;
    }

    //Fetch element to the cache and move it to MRU position in T1
    enqueue(mru, ikey_page_number);
    ::hash[ikey_page_number % HASHSIZE]++;
}
//function to initialize values of vairable structure of queue
void arc::arc_queue_init(Queue *queue, unsigned int number_of_frames, char* name)
{
    queue->name = name;
    // The queue is empty
    queue->icount = 0;
    queue->front = nullptr;
    queue->rear = nullptr;
    cout << name << endl;
    cout << number_of_frames << endl;
    cout << queue << endl;

    // Number of frames that can be stored in memory
    queue->inumber_of_frames = number_of_frames;
}
//function to initialize the cache structure
void arc::arc_cache_init(const unsigned int icache_size)
{
    cout << "entered";
    c = icache_size;
    p = 0;

    char* MRUG = "MRUG";
    char* MRU = "MRU";
    char* MFU = "MFU";
    char* MFUG = "MFUG";

    //Initialize the queue for each of the list
    arc_queue_init(mrug, icache_size, MRUG);
    arc_queue_init(mru, icache_size, MRU);
    arc_queue_init(mfu, icache_size, MFU);
    arc_queue_init(mfug, icache_size, MFUG);
}
