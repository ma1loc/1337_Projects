#include "push_swap.h"

// split the input.
void	split_input(char **argv)
{
	int	i;
	int	j;
	int	nbr;
	char	**split_argv;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		if ((has_space(argv[i])) == 1)
		{
			split_argv = ft_split(argv[i], ' ');
			while (split_argv[j])
			{
				if (is_valid_digit(split_argv[j]) == 1)
				{
					while (split_argv[j])
						free(split_argv[j++]);
					free(split_argv);
					ft_putstr_fd("Error\n", STDERR_FILENO);
				}
				else
				{
					nbr = ft_atoi(split_argv[j]);
					ft_lst_add_back()
				}
				j++;
			}
			while (split_argv[j])
				free(split_argv[j++]);
			free(split_argv);
		}
		else
		{
			nbr = ft_atoi(argv[i]);
			// i thing here i have to allocate to the nbr;
			
		}
		i++;
	}
}
