#include "push_swap.h"

int	ft_lst_size(t_stack *stack)
{
	int	c_size;
	t_list	*head;

	head = stack->head;
	if (!head)
		return (0);
	c_size = 0;
	while (head)
	{
		head = head->next;
		c_size++;
	}
	return (c_size);
}

void	put_index(t_stack *stack_a)
{
	t_list	*node;
	int		index;
	int		stack_size;
	int		*array;
	int 	i;

	node = stack_a->head;
	array = sorted_array(stack_a);
	stack_size = ft_lst_size(stack_a) - 1;

	while (node)
	{
		i = 0;
		index = 0; 
		while (i < stack_size)
		{
			if (node->value > array[index])
				index++;
			i++;
		}
		node->index = index;
		node = node->next;
	}
}


void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		*array;
	int		index;
	int		stack_a_size;

	array = sorted_array(stack_a);
	put_index(stack_a);
	t_list *header;
	stack_a_size = stack_a->size;

	t_list *header1;
	header1 = stack_b->head;
	


	while (stack_a)
	{
		while (array[index] < header->value)
			index++;
		if (index < stack_b->size)
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
		}
		else if (index < stack_b->size + count_chunk(stack_a_size))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
	}
	// header = stack_a->head;
	// while (header)
	// {
	// 	printf("%d\n", header->index);
	// 	header = header->next;
	// }
	// index = 0;
}
// 		0 1 2	
// 3 9 8   3 8 9 stuct ->0 2 1
