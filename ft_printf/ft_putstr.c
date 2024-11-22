#include "ft_printf.h"

void    ft_putstr(char *s)
{
    size_t i;

    i = 0;
    // if (!s)
    //     return ;
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
}