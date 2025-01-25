#include "push_swap.h"


void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		*array;
	int		index;
	t_list *head;

	index = 0;
	head = stack_a->head;
	array  = sorted_array(stack_a);

	while (head)
	{
		while (array[index] < head->value)
			index++;
		if (index < head->value)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
		}
		else if (index < head->value + count_chunk)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		head = head->next;
	}
	
	index = 0;
	head = stack_b->head;
	while (head)
	{
		// in this loop i have to put the element of the stack_b to a with the best move
		// here i have to work with the size / 2 to see the best move to stack a
		if (index <= stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		pb(stack_a, stack_b);
		head = stack_b->head;
	}
	free(array);
}

	
	// if (j <= stack_a->size / 2)
	// 	ra(stack_a, 1);
	// else
	// 	rra(stack_a, 1);
	// pb(stack_a, stack_b);
	// free(array);