/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:50:01 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/31 11:41:41 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	j = dst_len;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && i < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}

#include <stdio.h>
#include <string.h>

int	main()
{
//	printf("%zu\n", strlcat("pqrs", "abcdefghi", 12));
	printf("%zu\n", ft_strlcat("pqrs", "abcdefghi", 12));
}
