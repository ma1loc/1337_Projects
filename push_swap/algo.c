#include "push_swap.h"

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		*array;
	int		chunk_num;
	int		chunk_size;
	int		i;
	int		j;
	int		start;
	int		end;

	array = sorted_array(stack_a);
	chunk_num = count_chunk(stack_a->size);
	chunk_size = (stack_a->size / chunk_num);

	i = 0;
	while (i < chunk_num)
	{
		start = i * chunk_size;
		end = (i + 1) * chunk_size;

		t_list *node = stack_a->head;
		j = 0;
		while (j < stack_a->size)
		{
			if (node->value >= array[start] && node->value < array[end])
			{
				if (j <= stack_a->size / 2)
					ra(stack_a, 1);
				else
					rra(stack_a, 1);
				pb(stack_a, stack_b);
				node = stack_a->head;
			}
			else
				node = node->next;
			j++;
		}
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);

	free(array);
}