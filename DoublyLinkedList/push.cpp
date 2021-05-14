
void Node :: push(Node** head_ref,int value)
{
    Node* new_node=new Node();
    new_node->data=value;
    new_node->prev=NULL;
    new_node->next=(*head_ref);
    if(*head_ref!=NULL)
    {
       (*head_ref)->prev=new_node; 
    }
    *head_ref=new_node;

}
