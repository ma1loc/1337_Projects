#include "../src_so_long/so_long.h"

char	*ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}
