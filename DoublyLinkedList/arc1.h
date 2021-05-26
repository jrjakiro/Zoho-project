/*Implementation of Adaptive replacement cache header file
A ARC Cache consisting of 4 Queues
* mrug (B1)- Most Recently Used Ghost
* mru (T1) - Most Recently Used
* mfu (T2) - Most Frequently Used
* mfug (B2) - Most Frequently Used Ghost
Contents : Implementation of Queue using Doubly Linked List
*/

//for preventing end user inclusion problems
#pragma once
#include <iostream>
#include <string>

#define PRINTDEBUGS 0
//defining the hash size
#define HASHSIZE 1000000

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//declaration of Global Variable
unsigned int iCacheSize = 0;
char *fileName;
unsigned int imiss_count = 0;
unsigned int ihit_count = 0;
unsigned int hash[HASHSIZE];

//Implementation of Queue using Doubly Linked List

//defining a  Queue Node
class QNode
{
public:
    //page number stored in the queue node must be positive
    unsigned int ipage_number;
    //declaration of pointers
    QNode *next;
    QNode *prev;
};
//Declaration of Queue(FIFO)
class Queue
{
public:
    //positive-frames that is filled
    unsigned int icount;
    //total number of frames
    unsigned int inumber_of_frames;
    //declaration of pointers
    QNode *front;
    QNode *rear;
    //Name of the Queue
    char *name;
};

//Declaration of Cache
class ARCCache
{
    unsigned int c;
    int p;
    Queue mrug, mru, mfu, mfug;

public:
    //to create a new node which will store the given page number
    QNode *new_qnode(unsigned int page_number);

    //for creating a new empty queue
    Queue *create_queue(unsigned int number_of_frames);
    // function to initialize values of variable of structure of the queue
    void arc_queue_init(Queue *queue, unsigned int number_of_frames, char *name);
    //function to initialize the cache structure
    void initARCCache(const unsigned int iCacheSize);

    //for checking whether the queue is full or not
    int is_queue_full(Queue *queue);
    //for checking whether the queue is empty or not
    int is_queue_empty(Queue *queue);
    //function to delete a frame from queue
    void dequeueNode(Queue *queue, QNode *req_page);
    //function to add a page with a given page_number to queue
    void enqueueMRU(Queue *queue, unsigned int page_number);
    //function to call when a page with given page_number is referenced from cache or memory
    QNode *ReferencePage(Queue *queue, unsigned int ipage_number);
    //function to move elements from one queue to another which needs to be inserted and to move the page
    void move_to(Queue *fromQueue, Queue *toQueue, QNode *req_page);
    //function to move the elements out from one list and add it to another list beginning
    void replace(const unsigned int ipage_number, const float p);
    //function to lookup for an object with the given key
    void arc_lookup(const unsigned int ikey_page_number);

    //function to print the entire contents of the pages currently present in all the lists of cache
    void printList();
};

//Global Declaration of cache structure
ARCCache cache;

//function to create a new Queue Node which will store the given 'page_number'
QNode *ARCCache::new_qnode(unsigned int page_number)
{
    //creating new node
    QNode *temp = new QNode();
    //assigning page number
    temp->ipage_number = page_number;

    //Initialize prev and next as NULL
    temp->prev = nullptr;
    temp->next = nullptr;

    return temp;
}

//function to create e new empty queue which can have at most number_of_frames nodes
Queue *ARCCache::create_queue(unsigned int number_of_frames)
{
    //initialization of new empty queue
    Queue *queue = new Queue();

    //The queue is empty
    queue->icount = 0;
    queue->front = nullptr;
    queue->rear = nullptr;

    /*Number of frames that can be stored in memory*/
    queue->inumber_of_frames = number_of_frames;

    return queue;
}

//function to check whether the queue is full or not
//to check whether there is slot available to bring in a new page into memory
int ARCCache::is_queue_full(Queue *queue)
{
    return queue->icount == queue->inumber_of_frames;
}

//function to check if queue is empty
int ARCCache::is_queue_empty(Queue *queue)
{
    return queue->rear == nullptr;
}
//function to delete a frame from queue
void ARCCache::dequeueNode(Queue *queue, QNode *req_page)
{
    // if the page is not available
    if (req_page == nullptr)
    {
        printf("Requested Page is Not Available\n");
        return;
    }
    //If the queue has only one node which need to be removed
    if ((queue->front == req_page) && (queue->rear == req_page))
    {
        queue->front = nullptr;
        queue->rear = nullptr;
    }
    //If the node to be removed is the node at the front of the queue
    else if ((queue->front == req_page) && (queue->rear != req_page))
    {
        queue->front = req_page->next;
        queue->front->prev = nullptr;
    }
    //If the node to be removed is the node at the end of the queue
    else if ((queue->front != req_page) && (queue->rear == req_page))
    {
        queue->rear = req_page->prev;
        queue->rear->next = nullptr;
    }
    //If the node to be removed is the node in the some other location other than front and rear end
    else
    {
        req_page->prev->next = req_page->next;
        req_page->next->prev = req_page->prev;
    }

    //Free the node after dequeuing it from the queue
    free(req_page);
    // decrement the number of full frames by 1
    queue->icount--;
}
//function to print the entire contents of the pages currently present in all the lists of cache
void ARCCache::printList()
{
    Queue *queue = &cache.mru;
    printf("T1 ::: %s(%u/%u):::", queue->name, queue->icount, cache.p);
    QNode *node = queue->front;
    while (node != NULL)
    {
        printf("%d ", node->ipage_number);
        node = node->next;
    }
    if (queue->front)
        printf("\tFront=%u", queue->front->ipage_number);
    if (queue->rear)
        printf("\tRear=%u", queue->rear->ipage_number);

    printf("\n");
    queue = &cache.mrug;
    printf("B1 ::: %s(%u/%u):::", queue->name, queue->icount, (cache.c - cache.p));
    node = queue->front;
    while (node != NULL)
    {
        printf("%d ", node->ipage_number);
        node = node->next;
    }
    if (queue->front)
        printf("\tFront=%u", queue->front->ipage_number);
    if (queue->rear)
        printf("\tRear=%u", queue->rear->ipage_number);
    printf("\n");
    queue = &cache.mfu;
    printf("T2 ::: %s(%u/%u):::", queue->name, queue->icount, (cache.c - cache.p));
    node = queue->front;
    while (node != NULL)
    {
        printf("%d ", node->ipage_number);
        node = node->next;
    }
    if (queue->front)
        printf("\tFront=%u", queue->front->ipage_number);
    if (queue->rear)
        printf("\tRear=%u", queue->rear->ipage_number);
    printf("\n");
    queue = &cache.mfug;
    printf("B2 ::: %s(%u/%u):::", queue->name, queue->icount, (cache.c - cache.p));
    node = queue->front;
    while (node != NULL)
    {
        printf("%d ", node->ipage_number);
        node = node->next;
    }
    if (queue->front)
        printf("\tFront=%u", queue->front->ipage_number);
    if (queue->rear)
        printf("\tRear=%u", queue->rear->ipage_number);
    printf("\n");
}
//function to add a page with a given page_number to queue
void ARCCache::enqueueMRU(Queue *queue, unsigned int page_number)
{
    //Create a new node with given page number
    QNode *temp = new_qnode(page_number);
    //add the new node to the front of queue
    temp->next = queue->front;

    //If queue is empty, change both front and rear pointers
    if (is_queue_empty(queue))
    {
        queue->front = temp;
        queue->rear = queue->front;
    }
    //Else change the front
    else
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    //increment number of full frames
    queue->icount++;
}
//function to call when a page with given page_number is referenced from cache or memory
QNode *ARCCache::ReferencePage(Queue *queue, unsigned int ipage_number)
{
    // case 1: Frame is not there in memory, then it returns NULL
    //case 2: Frame is there in memory, then return the pointer to the node

    QNode *req_page = nullptr;
    //Check if the page or the frame being referenced is already present in the queue of nodes
    struct QNode *tempreq_page = nullptr;
    for (tempreq_page = queue->front; tempreq_page; tempreq_page = tempreq_page->next)
    {
        if (tempreq_page->ipage_number == ipage_number)
        {
            req_page = tempreq_page;
            return req_page;
        }
    }
    return req_page;
}

//function to move elements from one queue to another which needs to be inserted and to move the page
void ARCCache::move_to(Queue *fromQueue, Queue *toQueue, QNode *req_page)
{
    //Remove the requested page from fromQueue Check if this the only element in the fromQueue
    if ((fromQueue->front == req_page) && (fromQueue->rear == req_page))
    {
        fromQueue->front = nullptr;
        fromQueue->rear = nullptr;
    }
    //Remove the requested page from fromQueue, Check if this the first element in the fromQueue
    else if ((fromQueue->front == req_page) && (fromQueue->rear != req_page))
    {
        fromQueue->front = req_page->next;
        fromQueue->front->prev = nullptr;
    }
    //Remove the requested page from fromQueue, Check if this the last element in the fromQueue
    else if ((fromQueue->front != req_page) && (fromQueue->rear == req_page))
    {
        fromQueue->rear = req_page->prev;
        fromQueue->rear->next = nullptr;
    }
    //Remove the requested page from fromQueue, Check if this is not the first/last element in the fromQueue
    else
    {
        req_page->prev->next = req_page->next;
        req_page->next->prev = req_page->prev;
    }
    //decrement the number of pages in fromQueue by 1
    fromQueue->icount--;

    req_page->next = toQueue->front;

    //If queue is empty, change both front and rear pointers
    if (is_queue_empty(toQueue))
    {
        toQueue->front = req_page;
        toQueue->rear = toQueue->front;
    }
    //Else change the front
    else
    {
        toQueue->front->prev = req_page;
        toQueue->front = req_page;
    }

    //Increment the number of pages in toQueue by 1
    toQueue->icount++;
}
//function to move the elements out from one list and add it to another list beginning
void ARCCache::replace(const unsigned int ipage_number, const float p)
{
    if ((cache.mru.icount >= 1) && ((cache.mru.icount > p) || ((nullptr != ReferencePage(&cache.mfug, ipage_number)) && (p == cache.mru.icount))))
    {
        if (cache.mru.rear)
        {
            move_to(&cache.mru, &cache.mrug, cache.mru.rear);
        }
    }
    else
    {
        if (cache.mfu.rear)
        {
            move_to(&cache.mfu, &cache.mfug, cache.mfu.rear);
        }
    }
}

//function to lookup for an object with the given key
void ARCCache::arc_lookup(const unsigned int ikey_page_number)
{
    struct QNode *req_page = nullptr;
    if (hash[ikey_page_number % HASHSIZE] > 0)
    {
        //Case 1: Part A: Page Found in MRU (T1)
        if (NULL != (req_page = ReferencePage(&cache.mru, ikey_page_number)))
        {
#if PRINTDEBUGS == 1
            //printf("HIT :: Case 1: Part A: Page Found in MRU (T1)\n");
#endif
            //Increment the hit counter
            ihit_count++;

            //Move xt to MRU position in T2
            move_to(&cache.mru, &cache.mfu, req_page);
        }
        //Case 1: Part B: Page Found in MFU (T2)
        else if (NULL != (req_page = ReferencePage(&cache.mfu, ikey_page_number)))
        {
#if PRINTDEBUGS == 1
            //printf("HIT :: Case 1: Part B: Page Found in MFU (T2)\n");
#endif
            //Increment the hit counter
            ihit_count++;

            //Move xt to MRU position in T2
            move_to(&cache.mfu, &cache.mfu, req_page);
        }
        /*Case 2: Page Found in MRUG (B1).*/
        else if (NULL != (req_page = ReferencePage(&cache.mrug, ikey_page_number)))
        {
#if PRINTDEBUGS == 1
            //printf("MISS :: Case 2: Page Found in MRUG (B1).\n");
#endif
            imiss_count++;
            cache.p = (float)MIN((float)cache.c, (cache.p + MAX((cache.mfug.icount * 1.0) / cache.mrug.icount, 1.0)));
            replace(ikey_page_number, cache.p);

            /*Move xt from B1 to the MRU position in T2.*/
            move_to(&cache.mrug, &cache.mfu, req_page);
        }
        /*Case 3: Page Found in MFUG (B2).*/
        else if (NULL != (req_page = ReferencePage(&cache.mfug, ikey_page_number)))
        {
#if PRINTDEBUGS == 1
            //printf("MISS :: Case 3: Page Found in MFUG (B2).\n");
#endif
            imiss_count++;
            cache.p = (float)MAX(0.0, (float)(cache.p - MAX((cache.mrug.icount * 1.0) / cache.mfug.icount, 1.0)));
            replace(ikey_page_number, cache.p);

            /*Move xt from B2 to the MRU position in T2.*/
            move_to(&cache.mfug, &cache.mfu, req_page);
        }
        /*Case 4: Page Not Found in MRU, MRUG, MFU, MFUG.*/
        else
        {
#if PRINTDEBUGS == 1
            //printf("Case 4: Page Not Found in MRU, MRUG, MFU, MFUG.\n");
#endif
            imiss_count++;
            /*Case 4: Part A: L1 has c pages*/
            if ((cache.mru.icount + cache.mrug.icount) == cache.c)
            {
                if (cache.mru.icount < cache.c)
                {
                    hash[cache.mrug.rear->ipage_number % HASHSIZE]--;

                    /*Delete LRU page in B1.*/
                    dequeueNode(&cache.mrug, cache.mrug.rear);
                    replace(ikey_page_number, cache.p);
                }
                else
                {
                    /*Here B1 is empty. Delete LRU page in T1 (also remove it from the cache).*/
                    hash[cache.mru.rear->ipage_number % HASHSIZE]--;

                    /*Delete LRU page in T1.*/
                    dequeueNode(&cache.mru, cache.mru.rear);
                }
            }
            /*Case 4: Part B: L1 has less than c pages*/
            else if ((cache.mru.icount + cache.mrug.icount) < cache.c)
            {
                if ((cache.mru.icount + cache.mfu.icount + cache.mrug.icount + cache.mfug.icount) >= cache.c)
                {
                    if ((cache.mru.icount + cache.mfu.icount + cache.mrug.icount + cache.mfug.icount) == (2 * cache.c))
                    {
                        hash[cache.mfug.rear->ipage_number % HASHSIZE]--;

                        /*Delete LRU page in B2.*/
                        dequeueNode(&cache.mfug, cache.mfug.rear);
                    }
                    replace(ikey_page_number, cache.p);
                }
            }
            /*Fetch xt to the cache and move it to MRU position in T1.*/
            enqueueMRU(&cache.mru, ikey_page_number);
            hash[ikey_page_number % HASHSIZE]++;
        }
    }
    else
    {
#if PRINTDEBUGS == 1
        //printf("Case 4: Page Not Found in MRU, MRUG, MFU, MFUG.\n");
#endif
        imiss_count++;
        /*Case 4: Part A: L1 has c pages*/
        if ((cache.mru.icount + cache.mrug.icount) == cache.c)
        {
            if (cache.mru.icount < cache.c)
            {
                hash[cache.mrug.rear->ipage_number % HASHSIZE]--;

                /*Delete LRU page in B1.*/
                dequeueNode(&cache.mrug, cache.mrug.rear);
                replace(ikey_page_number, cache.p);
            }
            else
            {
                /*Here B1 is empty. Delete LRU page in T1 (also remove it from the cache).*/
                hash[cache.mru.rear->ipage_number % HASHSIZE]--;

                /*Delete LRU page in T1.*/
                dequeueNode(&cache.mru, cache.mru.rear);
            }
        }
        /*Case 4: Part B: L1 has less than c pages*/
        else if ((cache.mru.icount + cache.mrug.icount) < cache.c)
        {
            if ((cache.mru.icount + cache.mfu.icount + cache.mrug.icount + cache.mfug.icount) >= cache.c)
            {
                if ((cache.mru.icount + cache.mfu.icount + cache.mrug.icount + cache.mfug.icount) == (2 * cache.c))
                {
                    hash[cache.mfug.rear->ipage_number % HASHSIZE]--;

                    /*Delete LRU page in B2.*/
                    dequeueNode(&cache.mfug, cache.mfug.rear);
                }
                replace(ikey_page_number, cache.p);
            }
        }

        /*Fetch xt to the cache and move it to MRU position in T1.*/
        enqueueMRU(&cache.mru, ikey_page_number);
        hash[ikey_page_number % HASHSIZE]++;
    }
}

// function to initialize values of variable of structure of the queue
void ARCCache::arc_queue_init(Queue *queue, unsigned int number_of_frames, char *name)
{
    queue->name = name;
    // The queue is empty
    // Count is set to 0, front and rear are set to NULL.

    queue->icount = 0;
    queue->front = nullptr;
    queue->rear = nullptr;

    // Number of frames that can be stored in memory
    queue->inumber_of_frames = number_of_frames;
}

//function to initialize the cache structure
void ARCCache::initARCCache(const unsigned int iCacheSize)
{
    /* In the structure, the cache size is set, the adaptation page is set to 0.
* and then a call to function is made to initialize all the queues as part of
* the structure of cache.*/

    cache.c = iCacheSize;
    cache.p = 0;

     char* mrug = "MRUG";
    char* mru = "MRU";
    char* mfu = "MFU";
    char* mfug = "MFUG";

    /*Initialize the queue for each of the list*/
    arc_queue_init(&cache.mrug, iCacheSize, mrug);
    arc_queue_init(&cache.mru, iCacheSize, mru);
    arc_queue_init(&cache.mfu, iCacheSize, mfu);
    arc_queue_init(&cache.mfug, iCacheSize, mfug);
}
