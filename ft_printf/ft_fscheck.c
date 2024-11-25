#include "ft_printf.h"
#include <stdio.h>
int ft_fscheck(va_list arg, char c)
{
    int count;
    
    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(arg, int)); // done %c
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(arg, int)); // done %d, %i
    else if (c == 'x' || c == 'X')
        count += ft_puthex(va_arg(arg, unsigned int), c); // done %x, %X
    else if (c == 'u')
        count += ft_putuint(va_arg(arg, unsigned int));
    else if (c == 'p')
        count += ft_putadd(va_arg(arg, void *));
    else if (c == 's')
    {
         printf("[%d]", c);
        count += ft_putstr(va_arg(arg, char *)); // done %s
    }
    // else
    //     count += ft_putchar(c);
    return (count);
}