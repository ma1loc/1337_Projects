#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	t_list	*current;
	int		min_index;

	current = stack->head;
	if (!current)
		return (0);
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	get_max_index(t_stack *stack)
{
	t_list	*current;
	int		max_index;

	current = stack->head;
	if (!current)
		return (0);
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}
