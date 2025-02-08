/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:14:04 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:14:06 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lst_add_back(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = ft_lst_new(value);
	if (!new_node)
		cleanup_and_exit(stack_a, stack_b, NULL);
	if (!stack_a->head)
		stack_a->head = new_node;
	else
	{
		last_node = ft_last_node(stack_a->head);
		last_node->next = new_node;
	}
	stack_a->size++;
}

int	is_sorted(t_stack *stack)
{
	t_list	*header;

	header = stack->head;
	if (!header || !header->next)
		return (1);
	while (header->next)
	{
		if (header->value > header->next->value)
			return (0);
		header = header->next;
	}
	return (1);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

t_list	*ft_last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
