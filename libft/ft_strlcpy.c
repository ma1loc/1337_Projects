/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:38:40 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/01 09:23:19 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t d_size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(src);
	if (d_size > 0)
	{
		while (src[i] && i < d_size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (s_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	//char src[] = "world";
	char src[] = "world";
	char dst[15] = "hello";
	printf("%zu\n", ft_strlcpy(dst, src, 0));
	printf("%zu\n", strlcpy(dst, src, 0));

	return (0);
}
*/
