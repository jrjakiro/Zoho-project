#include "header.h"
//to find the size
int Node::findSize(Node *node)
{
   int res = 0;
   while (node != NULL)
   {
       res++;
       node = node->next;
   }
   return res;
}
bool Node:: isempty(Node *node)
{
    return(!(findSize(node)));
}
