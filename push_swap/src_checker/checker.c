#include "checker.h"

int	execute_command(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pa", 2) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = stack_init();
	stack_b = stack_init();
	if (!stack_a || !stack_b)
		return (0);
	split_input(argv, stack_a, stack_b);
	line = get_next_line(0);
	while (line)
	{
		if (execute_command(stack_a, stack_b, line))
			return (free_stacks(stack_a, stack_b), free(line), 0);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stacks(stack_a, stack_b), 0);
}
