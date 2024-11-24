#include "ft_printf.h"

void    ft_put_unint(unsigned int n)
{
    char    c;

    if (n <= 9)
    {
        c = (n + '0');
        ft_putchar(c);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}