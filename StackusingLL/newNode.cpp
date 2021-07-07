//for creating a new node


StackNode* StackNode :: newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
