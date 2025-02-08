/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:12:35 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:12:37 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack *stack)
{
	t_list	*node;
	int		max_index;
	int		position;
	int		max_position;

	node = stack->head;
	if (!node)
		return (0);
	max_index = node->index;
	position = 0;
	max_position = 0;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_position = position;
		}
		node = node->next;
		position++;
	}
	return (max_position);
}

void	push_max(t_stack *stack_a, t_stack *stack_b)
{
	int	max_pos;

	while (stack_b->size > 0)
	{
		max_pos = find_max_pos(stack_b);
		if (max_pos <= stack_b->size / 2)
		{
			while (max_pos)
			{
				rb(stack_b, 1);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < stack_b->size)
			{
				rrb(stack_b, 1);
				max_pos++;
			}
		}
		pa(stack_a, stack_b, 1);
	}
}

void	sort_num(t_stack *stack_a, t_stack *stack_b)
{
	int		chunk_size;
	int		current_index;
	t_list	*node;

	chunk_size = count_chunk(stack_a->size);
	current_index = 0;
	put_index(stack_a);
	while (stack_a->size > 0)
	{
		node = stack_a->head;
		if (node->index <= (current_index + 1) * chunk_size)
		{
			pb(stack_a, stack_b, 1);
			if (node->index <= current_index * chunk_size + (chunk_size / 2))
				rb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
		if (get_min_index(stack_a) > (current_index + 1) * chunk_size)
			current_index++;
	}
	push_max(stack_a, stack_b);
}
