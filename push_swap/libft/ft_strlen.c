/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:09:48 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/02 09:09:52 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_push_swap/push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
