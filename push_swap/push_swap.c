#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	split_input(char **argv, t_stack *stack)
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
			if (!split_argv)
				ft_putstr_fd("Error\n", STDERR_FILENO);
			while (split_argv[j])
			{
				if (is_digit(split_argv[j]) == 1)
				{
					free_split(split_argv);
					ft_putstr_fd("Error\n", STDERR_FILENO);
				}
				else
				{
					if (is_valid_atoi(argv[i]) == 1)
						ft_putstr_fd("Error\n", STDERR_FILENO);
					nbr = ft_atoi(split_argv[j]);
					ft_lst_add_back(stack, nbr);
				}
				j++;
			}
			free_split(split_argv);
		}
		else
		{
			if (is_valid_atoi(argv[i]) == 1)
				ft_putstr_fd("Error\n", STDERR_FILENO);
			nbr = ft_atoi(argv[i]);
			ft_lst_add_back(stack, nbr);
		}
		i++;
	}
}
