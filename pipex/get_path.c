#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	delim_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*get_the_word(char *str, int *index, char c)
{
	int		start;
	char	*word;
	int		count;
	int		i;

	start = *index;
	count = 0;
	while (str[start] && str[start] == c)
		start++;
	*index = start;
	while (str[*index] && str[*index] != c)
	{
		(*index)++;
		count++;
	}
	word = malloc(sizeof(char) * (count + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < count)
		word[i++] = str[start + i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**new_str;
	int		word_count;
	int		start;
	int		index;
	int		i;

	word_count = delim_count(str, c);
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		new_str[i] = get_the_word(str, &index, c);
		if (!new_str[i])
		{
			while (i > 0)
				free(new_str[--i]);
			return (free(new_str), NULL);
		}
		i++;
	}
	new_str[i] = NULL;
	return (new_str);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	if (n == 0)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[i];
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	main(int argc, char **argv, char **env)
{
	size_t	i;
	char *path;	
	char **split_path;
	
	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	path = env[i] + 5;
	split_path = ft_split(path, ':');
	
	char **new_path;
	size_t	j;
	char **cmd_path;
	j = 0;
	while (split_path[j])
	{
		new_path[i] = ft_strjoin(split_path[j], "/");
		j++;
	}
	size_t k = 0;
	char *cmd;

	cmd = "ls";
	while (new_path[k])
	{
		cmd_path[k] = ft_strjoin(new_path[k], cmd);
		printf("%s\n", cmd_path[k]);
		k++;
	}
	return (0);
}













