#include "../src_so_long/so_long.h"

void	ft_putstr_fd(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}
