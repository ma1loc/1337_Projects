/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:34:49 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/25 15:15:04 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	t_len;
	char	ch;

	t_len = ft_strlen(s);
	ch = (char)c;
	if (c == 0)
		return ((char *)s + t_len);
	while (t_len > 0)
	{
		t_len--;
		if (s[t_len] == ch)
			return ((char *)s + t_len);
	}
	return (NULL);
}
