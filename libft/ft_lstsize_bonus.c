/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:56:06 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/05 09:23:14 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c_size;

	if (!lst)
		return (0);
	c_size = 0;
	while (lst)
	{
		lst = lst->next;
		c_size++;
	}
	return (c_size);
}
