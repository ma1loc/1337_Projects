/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:14:34 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:14:37 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	t_list	*node;
	int		nbr;

	node = stack->head;
	nbr = node->value;
	while (node)
	{
		if (nbr > node->value)
			nbr = node->value;
		node = node->next;
	}
	return (nbr);
}

int	find_largest(t_stack *stack)
{
	t_list	*node;
	int		nbr;

	if (!stack || !stack->head)
		return (-1);
	node = stack->head;
	nbr = node->value;
	while (node)
	{
		if (nbr < node->value)
			nbr = node->value;
		node = node->next;
	}
	return (nbr);
}

void	move_to_top(t_stack *stack, int smallest)
{
	t_list	*head;
	int		position;

	head = stack->head;
	position = 0;
	while (head && head->value != smallest)
	{
		head = head->next;
		position++;
	}
	if (position <= stack->size / 2)
	{
		while (position-- > 0)
			ra(stack, 1);
	}
	else
	{
		position = stack->size - position;
		while (position-- > 0)
			rra(stack, 1);
	}
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first > second && first > third && second < third)
		ra(stack_a, 1);
	else if (first < second && first > third)
		rra(stack_a, 1);
	else if (first > second && first < third)
		sa(stack_a, 1);
	else if (first < second && second > third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;

	smallest = find_smallest(stack_a);
	move_to_top(stack_a, smallest);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
}
