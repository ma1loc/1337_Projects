#include "push_swap.h"

void    ft_putstr_fd(char *str)
{
    write(STDERR_FILENO, str, ft_strlen(str));
    exit(1);
}