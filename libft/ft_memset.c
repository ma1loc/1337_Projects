/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:58 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/24 08:30:49 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (s);
}
