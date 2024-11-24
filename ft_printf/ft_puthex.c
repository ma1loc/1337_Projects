#include "ft_printf.h"

void ft_put_hex(int n, char c)
{    
    char *hex_based;

    // printf("the hex -> %d\n", n);
    if (c == 'x')
        hex_based = "0123456789abcdef";
    if (c == 'X')
        hex_based = "0123456789ABCDEF";
    if (n >= 0 && n <= 15)
        ft_putchar(hex_based[n]);
    else
    {
        ft_hexadecimal(n / 16);
        ft_hexadecimal(n % 16);
    }
}