#include "push_swap.h"

void	is_valid_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (!argv[i][j])
	{
		j = 0;
		while (!argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || (argv[i][j] == ' '))
				j++;
			else
				ft_putstr_fd("Error\n");
		}
		i++;
	}
}