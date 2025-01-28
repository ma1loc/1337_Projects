#include "push_swap.h"

int	find_max_pos(t_stack *stack)
{
	t_list	*current;
	int		max_index;
	int		position;
	int		max_position;

	current = stack->head;
	if (!current)
		return (0);
	max_index = current->index;
	position = 0;
	max_position = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_position = position;
		}
		current = current->next;
		position++;
	}
	return (max_position);
}

int	find_min_pos(t_stack *stack)
{
	t_list	*current;
	int		min_index;
	int		position;
	int		min_position;

	current = stack->head;
	if (!current)
		return (0);
	min_index = current->index;
	position = 0;
	min_position = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

void	push_max(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	while (stack_b->size > 0)
	{
		max_pos = find_max_pos(stack_b);
		if (max_pos <= stack_b->size / 2)
			while (max_pos--)
				rb(stack_b, 1);
		else
			while (max_pos++ < stack_b->size)
				rrb(stack_b, 1);
		pa(stack_a, stack_b);
	}
}

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_a_size; // hold the stack size (i think i can remove this ?)
	int		chunk_size; // hold chunk size;
	int		current_index;  // the current index = 0
	t_list	*node;	// hold the node

	stack_a_size = stack_a->size; // initialize it with the size of the stack_a
	chunk_size = count_chunk(stack_a_size); // for example we have stack_a = 6 / 6 = 1
	current_index = 0; // current index use in the loop
	put_index(stack_a); // put the index to the element in stack_a
	while (stack_a->size > 0)	// loop all stack
	{
		node = stack_a->head;
		if (node->index <= (current_index + 1) * chunk_size)
		{
			pb(stack_a, stack_b);
			if (node->index <= current_index * chunk_size + (chunk_size / 2))
				rb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
		if (get_min_index(stack_a) > (current_index + 1) * chunk_size)
			current_index++;
	}
	push_max(stack_a, stack_b);
}
