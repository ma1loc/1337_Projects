#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!argv[1] || !argv[1][0]) // the first argument is null
			ft_putstr_fd("Error\n");
		// check if there's some thing else rather then 0 - 9 numbers.
		// if there's any number is duplicate.
		// you have to check to if the numbers have before - or +;
		// if something like -- or ++ or +1+ ... return "Error".
		// check the charcters if there reutnr "Error".
		// ./push_swap " 1" is invalid.?
		is_valid_num(argv);
	}
	else
		ft_putstr_fd("Error\n");
}