#include "../src_push_swap/push_swap.h"

int	delim_count(char *str, char separator)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i] && str[i] != separator)
			count++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (count);
}

char	*get_the_word(char *str, int *index, char separator)
{
	int		start;
	char	*word;
	int		count;
	int		i;

	start = *index;
	count = 0;
	while (str[start] && str[start] == separator)
		start++;
	*index = start;
	while (str[*index] && str[*index] != separator)
	{
		(*index)++;
		count++;
	}
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < count)
	{
		word[i] = str[start + i];
		i++;
	}
	return (word[i] = '\0', word);
}

char	**ft_split(char *str, char separator)
{
	char	**new_str;
	int		word_count;
	int		index;
	int		i;

	word_count = delim_count(str, separator);
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		new_str[i] = get_the_word(str, &index, separator);
		if (!new_str[i])
		{
			while (i > 0)
				free(new_str[--i]);
			return (free(new_str), NULL);
		}
		i++;
	}
	return (new_str[i] = NULL, new_str);
}
