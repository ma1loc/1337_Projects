#include "../src_so_long/so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	s_len;

	s_len = 0;
	while (str[s_len])
		s_len++;
	return (s_len);
}
