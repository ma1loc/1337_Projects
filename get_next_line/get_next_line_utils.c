#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

// strncpy for copy to number byte
char	*ft_strncpy(char *dst, char *src, int nbyte)
{
	int i;

	i = 0;
	while (src[i] && nbyte > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	dst[i++] = '\0';
	return (dst);
}

char	*ft_strchr(char *str, char c)
{
	size_t i;

	i = 0;
	// check this?
	//if (!str)
	//	return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	// i don't think can use this any more ?
	//if (c == '\0')
	//	return ((char *)str + i);
	return (NULL);
}

// strdup for the strjoin funtion.
char	*ft_strdup(char *str)
{
	size_t s_len;
	size_t i;
	char *ptr;

	if (!str)
		return (NULL);
	
	s_len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s_len > i)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// extarnal functon for strjoin.
static void	mem_fill_join(char *str, char *ptr, size_t idx)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ptr[idx] = str[i];
		idx++;
		i++;
	}
}

// strjoin. 
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	t_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		ptr = ft_strdup(s2);
		return (ptr);
	}
	if (!s2)
	{
		ptr = ft_strdup(s1);
		return (ptr);
	}
	t_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (!ptr)
		return (NULL);
	mem_fill_join(s1, ptr, 0);
	mem_fill_join(s2, ptr, ft_strlen(s1));
	ptr[t_len] = '\0';
	return (ptr);
}
// strchr
// strjoin
// free the allocation
// ithink i can do read syscall in the conditon in the first. to check the == 0;
//ft_strncpy(line, buffer, BUFFER_SIZE);
	
// condition
	//	n_line = ft_strchr(line, '\n');
	//	if (n_line)
	//		l_line = n_line - line + 1;
	//	else
	//		l_line = ft_strlen(line);