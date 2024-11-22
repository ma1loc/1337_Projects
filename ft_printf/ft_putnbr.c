#include "ft_printf.h"

void    ft_putnbr(int nbr)
{
    char c;
    // use putstr
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nbr < 0)
    {
        putchar('-');
        nbr = -nbr;
    }
    if (nbr <= 9)
    {
        c = nbr + 0;
        putchar(c);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

int main()
{
    ft_putnbr(10);
}