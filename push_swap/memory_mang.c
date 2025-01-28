#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_stack(t_stack *stack)
{
	t_list	*node;
	t_list	*next;

	node = stack->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack);
}

void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b, char **split)
{
	if (split)
		free_split(split);
	if (stack_a)
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
	ft_putstr_fd("Error\n", STDERR_FILENO);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
