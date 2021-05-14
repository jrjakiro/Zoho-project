//for deleting elements in stack since LL is dynamic can shrink when deleting

int StackNode :: pop(StackNode** root)
{
	if (isEmpty(*root))
    {
        return 0;
    }
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}
