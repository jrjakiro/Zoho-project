#include "DLL.h"                         //including header file

void NodeDLL :: PrintVal(NodeDLL* x)              //prints the values in list
{
    int count=0;
    if(x==NULL)
    {
        cout<<"No Items in the list and it is empty";
    }

    while(x!=NULL)                          //iterate till the last
    {
        cout<<x->data<<" ";
        x=x->next;
        count++;
    }
    cout<<"\n size is "<<count<<endl;       //prints the size for reference
};
