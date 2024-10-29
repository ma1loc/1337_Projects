/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:24:51 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/29 12:36:20 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_count_word(const char *s, char c)
{
	size_t i;
	size_t count;

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

static void ft_mem_fill(char *to_fill, const char *s, size_t length, size_t start)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		to_fill[i] = s[start];
		i++;
		start++;
	}
	to_fill[i] = '\0';
}

static char *ft_split_words(const char *s, char c, size_t *index)
{
	size_t start;
	size_t i;
	size_t length;
	char *s_word;

	start = *index;
	i = 0;
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
	ft_mem_fill(s_word, s, length, start);
	return (s_word);
}

char **ft_split(char const *s, char c)
{
	size_t index;
	char **ptr;
	size_t c_word;
	size_t i;

	index = 0;
	c_word = ft_count_word(s, c);
	ptr = malloc(sizeof(char *) * (c_word + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < c_word)
	{
		ptr[i] = ft_split_words(s, c, &index);
		if (!ptr[i])
		{
			while (i > 0)
				free(ptr[--i]);
			free(ptr);
			return (NULL);
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

#include <stdio.h>

int	main()
{
	char str[] = "";
	//printf("str"", NULL -> %s\n", ft_split(str, NULL));
	printf("NULL, str"" -> %s\n", ft_split(NULL, str));
	//printf("NULL, NULL -> %s\n", ft_split(NULL, NULL));
	printf("\" \",\" \"-> %s\n", ft_split("", ""));

}
