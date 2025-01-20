#include "push_swap.h"

int	main(int argc, char **argv)
{
	// headers of the nodes.
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	
	stack_a = NULL;
	stack_b = NULL;
	
	// 1# split the input first
	char **split_input;
	// 2# check if there's a non num.
	// 3# check if there's a num more then ones ["11 11"] -> "Error"
	// 4# check if the numbers is alrady sorted.
	// 5# number range INT_MIN -> INT_MAX
	// 6# empty lines
}
