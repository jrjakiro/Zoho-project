//Will return the top most element in the linkedlist

int StackNode :: peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}
