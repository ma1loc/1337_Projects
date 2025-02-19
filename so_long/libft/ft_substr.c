/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:48:47 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 10:48:52 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	s1_len;
	char	*ptr;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	if (start >= s1_len)
		return (ft_strdup(""));
	if (len > s1_len - start)
		len = s1_len - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
