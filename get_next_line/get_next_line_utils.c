#include "get_next_line.h"
// just for the test.
#include <stdio.h>

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

char *ft_strncpy(char *dst, char *src, int nbyte)
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