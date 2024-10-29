/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:27:40 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/29 07:59:32 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_trim(char const ch, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

static void	mem_fill(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	t_len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && find_trim(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && find_trim(s1[end - 1], set) == 1)
		end--;
	t_len = end - start;
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (!ptr)
		return (NULL);
	mem_fill(ptr, s1 + start, t_len + 1);
	return (ptr);
}
