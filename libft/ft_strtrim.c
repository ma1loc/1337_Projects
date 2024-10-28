/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:27:40 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/28 18:49:11 by yanflous         ###   ########.fr       */
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

static	int check_NULL(const char *s1, char const *set)
{
	if (s1 == NULL || set == NULL)
		return (1);
	return (0);
}

static	size_t start_trim(const char *s1, const char *set)
{
	size_t start_len;

	start_len = 0;
	while (s1[start_len] && find_trim(s1[start_len], set) == 1)
		start_len++;
	return (start_len);
}

static	size_t end_trim(const char *s1, const char *set, size_t start_len)
{
	size_t end_len;

	end_len = ft_strlen(s1);
	while (end_len >= start_len && find_trim(s1[end_len], set) == 1)
		end_len--;
	return (end_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_len;
	size_t	end_len;
	size_t	t_len;
	char	*ptr;
	size_t	i;
	
	if (check_NULL(s1, set) == 1)
		return (NULL);
	start_len = start_trim(s1, set);
	end_len = end_trim(s1, set, start_len);
	t_len = end_len - start_len;
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (!ptr)
		return (NULL);

	i = 0;
	while (i < t_len)
	{
		ptr[i] = s1[start_len];
		i++;
		start_len++;
	}
	ptr[i] = 0;
	return (ptr);
}

#include <stdio.h>
int main()
{
	char s1[] = "abchellocba";
	char trim[] = "abc";
    printf("-> %s\n", ft_strtrim(s1, trim));
}

