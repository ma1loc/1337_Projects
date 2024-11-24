#include "ft_printf.h"

void    ft_putadd(unsigned long add)
{
    //    46666664664666
    //    0x545af5454dd
    //  { 0x-----------}

    printf("%lu", add);
    char *hex_based;

    hex_based = "0123456789abcdef";

    // put the 0x........
    ft_putstr("0x");
    
    if (add >= 0 && add <= 15)
        ft_putchar(hex_based[add]);
    else
    {
        ft_putadd(add / 16);
        // use putchar
        ft_putadd(add % 16);
    }
}


int main()
{
    int a = 1;

    printf("%p\n", &a);
    ft_putadd(&a);
}