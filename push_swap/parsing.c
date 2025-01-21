#include "push_swap.h"

int	is_digit(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_duplicate(t_stack *stack, int nbr)
{
	t_list *node;

	node = stack->head;
	while (node)
	{
		if (node->value == nbr)
			return (1);
		node = node->next;
	}
	return (0);
}

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
