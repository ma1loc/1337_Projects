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

size_t	size_node(t_list *list)
{
	size_t	len;
	
	if (!list)
		return (0);

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

t_list	*last_node(t_list *header)
{
	if (!header)
		return (NULL);
	while (header->next)
		header = header->next;
	return (header);
}
