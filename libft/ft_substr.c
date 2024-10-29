/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:57:55 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/28 10:28:30 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t		s1_len;
	char		*ptr;
	size_t		i;

	s1_len = ft_strlen(s1);
	if (start > s1_len)
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
