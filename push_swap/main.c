#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	stack_a = stack_init();
	stack_b = stack_init();
	split_input(argv, stack_a, stack_b);
	if(is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	else
	{
		if (stack_a->size == 2)
			sa(stack_a, 1);
		else	
			sort_stacks(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}