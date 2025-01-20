#include "push_swap.h"

void    ft_putstr_fd(char *str, int std)
{
    write(std, str, ft_strlen(str));
    exit(1);
}
