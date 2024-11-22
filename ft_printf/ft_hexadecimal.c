#include "ft_printf.h"

void ft_hexadecimal(int hex)
{    
    // First remainder (14) → E
    // Second remainder (15) → F
    int num;
    char c;
    
    // int num = 254;
    // printf("%d\n", num / 16);
    // num = num % 16;
    // printf("%d\n", num);
    
    //  A  B  C  D  E  F
    //  10 11 12 13 14 15
    if (num >= 0 && num <= 9)
    {
        c = num + '0';
        ft_putchar(c);
    }

    if (hex == 10)
        ft_putchar('a');
    if (hex == 11)
        ft_putchar('b');
    if (hex == 12)
        ft_putchar('c');
    if (hex == 13)
        ft_putchar('d');
    if (hex == 14)
        ft_putchar('e');
    if (hex == 15)
        ft_putchar('f');

    if (hex > 15)
    {
        ft_hexadecimal(hex)
    }
}

int main()
{
    ft_hexadecimal(16);
    printf("\nprintf => %x", 16);
}