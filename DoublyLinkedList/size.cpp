#include "header.h"
//to find the size
int Node::FindSize(Node *node)
{
   int res = 0;
   while (node != NULL)
   {
       res++;
       node = node->next;
   }
   return res;
}
//to check for empty or not
bool Node:: isEmpty(Node *node)
{
    return(!(FindSize(node)));
}
