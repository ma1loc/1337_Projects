#include "push_swap.h"

static int	ft_lstsize(t_list *lst)
{
	int	c_size;

	if (!lst)
		return (0);
	c_size = 0;
	while (lst)
	{
		lst = lst->next;
		c_size++;
	}
	return (c_size);
}

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		*array;
	int		index;
	t_list *head;
	int max = find_largest(stack_b);
	index = 0;
	head = stack_a->head;
	array  = sorted_array(stack_a);


	while (ft_lstsize(stack_a->head))
	{
		while (array[index] < head->value)
			index++;
		if (index < stack_b->size)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
		}
		else if (index < stack_b->size + count_chunk(stack_a->size))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}

	head = stack_b->head;
	while (ft_lstsize(stack_b->head))
	{
		index = 0;
		while(array[index] != max)
			index++;
		if (index <= stack_b->size / 2)
					rb(stack_b, 1);
		else
					rrb(stack_b, 1);
		pa(stack_a, stack_b);
	}
	free(array);
}