/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:13:05 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:13:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort_num(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2 && !argv[1][0])
		ft_putstr_fd("Error\n", STDERR_FILENO);
	stack_a = stack_init();
	stack_b = stack_init();
	if (!stack_a || !stack_b)
		return (0);
	split_input(argv, stack_a, stack_b);
	if (is_sorted(stack_a))
		return (free_stacks(stack_a, stack_b), 0);
	else
	{
		if (stack_a->size == 2)
			sa(stack_a, 1);
		else
			sort_stacks(stack_a, stack_b);
	}
	return (free_stacks(stack_a, stack_b), 0);
}
