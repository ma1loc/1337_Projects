#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	stack_a = stack_init(); // initalization of the stack;
	stack_b = stack_init();

	split_input(argv, stack_a);
	if(is_sorted(stack_a))
		return (0);
	else
		sort_stacks(stack_a);
		// sort_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}
