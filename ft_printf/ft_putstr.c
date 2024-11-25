#include "ft_printf.h"

int ft_putstr(char *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (write(1, "(null)", 6));
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}
