/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:40:05 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/24 15:24:23 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			--n;
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dst);
}
