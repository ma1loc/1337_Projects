/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:34:49 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/02 18:50:12 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	ch;

	s_len = ft_strlen(s);
	ch = (char)c;
	if (ch == '\0')
		return ((char *)s + s_len);
	while (s_len > 0)
	{
		s_len--;
		if (s[s_len] == ch)
			return ((char *)s + s_len);
	}
	return (NULL);
}
