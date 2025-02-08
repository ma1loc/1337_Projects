/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:24:51 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/08 10:27:28 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	mem_fill(char *ptr, const char *s, \
		size_t length, size_t start)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
}

static char	*split_words(const char *s, char c, size_t *index)
{
	size_t	start;
	size_t	length;
	char	*s_word;

	start = *index;
	while (s[start] && s[start] == c)
		start++;
	*index = start;
	length = 0;
	while (s[*index] && s[*index] != c)
	{
		length++;
		(*index)++;
	}
	s_word = malloc(sizeof(char) * (length + 1));
	if (!s_word)
		return (NULL);
	mem_fill(s_word, s, length, start);
	return (s_word);
}

static char	**mem_free(int i, char **ptr)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**ptr;
	int		c_word;
	int		i;

	if (!s)
		return (NULL);
	index = 0;
	c_word = count_word(s, c);
	ptr = malloc(sizeof(char *) * (c_word + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < c_word)
	{
		ptr[i] = split_words(s, c, &index);
		if (!ptr[i])
			return (mem_free(i, ptr));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
