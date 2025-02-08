/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:12:46 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:12:48 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array, int stack_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack_size - 1)
	{
		j = 0;
		while (j < stack_size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_array(t_stack *stack)
{
	t_list	*node;
	int		*array;
	int		i;

	node = stack->head;
	array = malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	i = 0;
	while (node)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	bubble_sort(array, stack->size);
	return (array);
}

void	put_index(t_stack *stack_a)
{
	t_list	*node;
	int		index;
	int		stack_size;
	int		*array;
	int		i;

	node = stack_a->head;
	array = sorted_array(stack_a);
	stack_size = ft_lst_size(stack_a) - 1;
	while (node)
	{
		i = 0;
		index = 0;
		while (i < stack_size)
		{
			if (node->value > array[index])
				index++;
			i++;
		}
		node->index = index;
		node = node->next;
	}
	free(array);
}

int	ft_lst_size(t_stack *stack)
{
	int		c_size;
	t_list	*head;

	head = stack->head;
	if (!head)
		return (0);
	c_size = 0;
	while (head)
	{
		head = head->next;
		c_size++;
	}
	return (c_size);
}

int	count_chunk(int stack_size)
{
	if (stack_size <= 100)
		return (stack_size / 6);
	else if (stack_size <= 500)
		return (stack_size / 10);
	else
		return (stack_size / 25);
}
