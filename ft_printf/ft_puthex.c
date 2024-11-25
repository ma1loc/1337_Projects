#include "ft_printf.h"

int ft_puthex(unsigned long n, char c)
{    
    char *hex_based;
    int count;

    count = 0;
    if (c == 'x')
        hex_based = "0123456789abcdef";
    if (c == 'X')
        hex_based = "0123456789ABCDEF";

    if (n >= 0 && n <= 15)
        count += ft_putchar(hex_based[n]);
    else
    {
        count += ft_puthex(n / 16, c);
        count += ft_puthex(n % 16, c);
    }
    return (count);
}