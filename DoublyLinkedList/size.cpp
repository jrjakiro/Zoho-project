#include "DLL.h"
//to find the size
int NodeDLL ::FindSize(NodeDLL *node)
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
bool NodeDLL :: isEmpty(NodeDLL *node)
{
    return(!(FindSize(node)));
}
