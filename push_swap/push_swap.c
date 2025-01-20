#include "push_swap.h"

// split the input.
char	**split_input(char *argv)
{
	// ["1 2 3", 5, "6 7 8 9"]
	//     1     2      3
	int	i;
	int	j;
	char	**split_argv;

	i = 1;
	while (argv[i])
	{
		j = 0;
		// before the split i check if there's a space in the argument;
		if ((has_space(argv[i])) == 1)
		{
			split_argv = ft_split(argv[i], " ");
		}
		else
			

	}
}
