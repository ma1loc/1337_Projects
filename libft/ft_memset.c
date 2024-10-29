/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:58 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/29 13:53:58 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

int main()
{
	printf("%s\n", ft_memset(NULL, 'n', 10));
	printf("%s\n", memset(NULL, 'n', 10));
}
