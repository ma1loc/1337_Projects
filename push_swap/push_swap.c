#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) // the first argument is null
		return (1);
	// check if there's some thing else rather then 0 - 9 numbers.
	// if there's any number is duplicate.
	// you have to check to if the numbers have before - or +;
	// if something like -- or ++ or +1+ ... return "Error".
	// check the charcters if there reutnr "Error".
	// ./push_swap " 1" is invalid.?
	is_valid_num(argv);
	ft_putstr_fd("Error\n");
}
