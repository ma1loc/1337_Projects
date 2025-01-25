#include "push_swap.h"

void	bubble_sort(int	*array, int	stack_size)
{
	int	i;
	int j;
	int tmp;

	i = 0;
	while (i < stack_size - 1)
	{
		j = 0;
		while (j < stack_size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_array(t_stack *stack)
{
	t_list	*node;
	int		*array;
	int		i;


	node = stack->head;
	array = malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	i = 0;
	while (node)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	bubble_sort(array, stack->size);
	return (array);
}

int count_chunk(int stack_size)
{
    if (stack_size <= 50)
        return (5);
    else if (stack_size <= 100)
        return (8);
	else if (stack_size <= 250)
		return (12);
    else if (stack_size <= 500)
        return (20);
    else
        return (35);
}
