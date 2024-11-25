#include "ft_printf.h"

int ft_putuint(unsigned int n)
{
    char    c;
    int     count;

    count = 0;
    if (n <= 9)
    {
        c = (n + '0');
        count += ft_putchar(c);
    }
    else
    {
        count += ft_putuint(n / 10);
        count += ft_putuint(n % 10);
    }
    return (count);

}