#include "push_swap.h"

void	single_arg(char *arg, t_stack *stack)
{
	int	nbr;

	if (is_digit(arg) || is_valid_atoi(arg))
		cleanup_and_exit(stack, NULL);
	nbr = ft_atoi(arg);
	if (is_duplicate(stack, nbr))
		cleanup_and_exit(stack, NULL);
	ft_lst_add_back(stack, nbr);
}

void	split_nbr(t_stack *stack, char *number, char **split_argv)
{
	int	nbr;

	if (is_digit(number) || is_valid_atoi(number))
		cleanup_and_exit(stack, split_argv);
	nbr = ft_atoi(number);
	if (is_duplicate(stack, nbr))
		cleanup_and_exit(stack, split_argv);
	ft_lst_add_back(stack, nbr);
}

void	space_arg(char *arg, t_stack *stack)
{
	char	**split_argv;
	int	i;

	split_argv = ft_split(arg, ' ');
	if (!split_argv)
		cleanup_and_exit(stack, NULL);
	i = 0;
	while (split_argv[i])
	{
		split_nbr(stack, split_argv[i], split_argv);
		i++;
	}
	free_split(split_argv);
}

void	split_input(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (has_space(argv[i]))
			space_arg(argv[i], stack);
		else
			single_arg(argv[i], stack);
		i++;
	}
}
