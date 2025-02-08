/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:15:10 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:15:12 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_move_five(t_stack *stack_a, t_stack *stack_b)
{
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
	pa(stack_b, stack_a, 1);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	first_smallest;
	int	second_smallest;

	first_smallest = find_smallest(stack_a);
	move_to_top(stack_a, first_smallest);
	pb(stack_a, stack_b, 1);
	second_smallest = find_smallest(stack_a);
	move_to_top(stack_a, second_smallest);
	pb(stack_a, stack_b, 1);
	to_move_five(stack_a, stack_b);
}
