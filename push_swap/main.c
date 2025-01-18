#include "push_swap.h"

int	main(int argc, char **argv)
{
	// headers of the nodes.
	t_stack *stack_a;
	t_stack *stack_b;
	
	// check if there's some thing else rather then 0 - 9 numbers.
	// if there's any number is duplicate.
	// you have to check to if the numbers have before - or +;
	// if something like -- or ++ or +1+ ... return "Error".
	// check the charcters if there reutnr "Error".
	// ./push_swap " 1" is invalid.?

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	
	stack_a = NULL;
	stack_b = NULL;
	
	// 1# split the input first
	// 2# check if there's a non num.
	// 3# check if there's a num more then ones ["11 11"] -> "Error"
}
