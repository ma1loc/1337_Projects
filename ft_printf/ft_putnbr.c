#include "ft_printf.h"

void    ft_putnbr(int nbr)
{
    char c;
    if (nbr == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
    }
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr <= 9)
    {
        c = (nbr + '0');
        ft_putchar(c);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}