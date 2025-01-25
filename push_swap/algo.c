#include "push_swap.h"

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		*array;
	int		index;
	t_list *head;
	int		stack_size;
	int max = find_largest(stack_b);
	index = 0;
	head = stack_a->head;
	array  = sorted_array(stack_a);


	while (stack_a)
	{
		stack_size = stack_a->size;
		while (array[index] < head->value)
			index++;
		if (index < stack_b->size)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
		}
		else if (index < stack_b->size + count_chunk)
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}

	head = stack_b->head;
	while (stack_b)
	{
		index = 0;
		while(array[index]!= max)
			index++;
		// in this loop i have to put the element of the stack_b to a with the best move
		// here i have to work with the size / 2 to see the best move to stack a
		if (index <= stack_b->size / 2)
					rb(stack_b, 1);
		else
					rrb(stack_b, 1);
		pa(stack_a, stack_b);
	}
	free(array);
}