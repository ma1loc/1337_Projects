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

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
    int stack_a_size;
    int chunk_size;
    int current_chunk;
    
    stack_a_size = stack_a->size;
    chunk_size = count_chunk(stack_a_size);
    current_chunk = 0;

    put_index(stack_a);
    while (stack_a->size > 0)
    {
        t_list *current = stack_a->head;
        if (current->index <= (current_chunk + 1) * chunk_size)
        {
            pb(stack_a, stack_b);
            if (current->index <= current_chunk * chunk_size + (chunk_size / 2))
                rb(stack_b, 1);
        }
        else
            ra(stack_a, 1);
        if (get_min_index(stack_a) > (current_chunk + 1) * chunk_size)
            current_chunk++;
    }
	// this while loop i have to put it in a function.
    while (stack_b->size > 0)
    {
        int max_pos = find_max_pos(stack_b);
        
        if (max_pos <= stack_b->size / 2)
            while (max_pos--)
                rb(stack_b, 1);
        else
            while (max_pos++ < stack_b->size)
                rrb(stack_b, 1);
                
        pa(stack_a, stack_b);
    }
}
