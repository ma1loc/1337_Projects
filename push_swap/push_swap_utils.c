#include "push_swap.h"

t_list	*new_node(int data ,int idx)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = data;
	node->index = idx;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
