/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:10:52 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:10:55 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_push_swap/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	t_list	*tmp;

	if (!stack_b || !stack_b->head)
		return ;
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	tmp->next = stack_a->head;
	stack_a->head = tmp;
	stack_a->size++;
	stack_b->size--;
	if (print_flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	t_list	*tmp;

	if (!stack_a || !stack_a->head)
		return ;
	tmp = stack_a->head;
	stack_a->head = stack_a->head->next;
	tmp->next = stack_b->head;
	stack_b->head = tmp;
	stack_a->size--;
	stack_b->size++;
	if (print_flag)
		write(1, "pb\n", 3);
}
