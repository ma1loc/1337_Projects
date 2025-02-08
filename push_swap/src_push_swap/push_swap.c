/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:13:36 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:13:38 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_nbr(t_stack *stack_a, t_stack *stack_b,
	char *number, char **split_argv)
{
	int	nbr;

	if (is_digit(number))
		cleanup_and_exit(stack_a, stack_b, split_argv);
	nbr = ft_atoi(number, stack_a, stack_b, split_argv);
	if (is_duplicate(stack_a, nbr))
		cleanup_and_exit(stack_a, stack_b, split_argv);
	ft_lst_add_back(stack_a, stack_b, nbr);
}

void	space_arg(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	char	**split_argv;
	int		i;

	if (all_space(arg))
		cleanup_and_exit(stack_a, stack_b, NULL);
	split_argv = ft_split(arg, ' ');
	if (!split_argv)
		cleanup_and_exit(stack_a, stack_b, NULL);
	i = 0;
	while (split_argv[i])
	{
		split_nbr(stack_a, stack_b, split_argv[i], split_argv);
		i++;
	}
	free_split(split_argv);
}

void	single_arg(char *number, t_stack *stack_a, t_stack *stack_b)
{
	int	nbr;

	if (is_digit(number))
		cleanup_and_exit(stack_a, stack_b, NULL);
	nbr = ft_atoi(number, stack_a, stack_b, NULL);
	if (is_duplicate(stack_a, nbr))
		cleanup_and_exit(stack_a, stack_b, NULL);
	ft_lst_add_back(stack_a, stack_b, nbr);
}

void	split_input(char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (has_space(argv[i]))
			space_arg(argv[i], stack_a, stack_b);
		else
			single_arg(argv[i], stack_a, stack_b);
		i++;
	}
}
