#include "ft_printf.h"

void    ft_putadd(void *ptr)
{
    //    46666664664666
    //    0x545af5454dd
    //  { 0x-----------}
    unsigned long add;
    char *hex_based;

    add = (unsigned long)ptr;
    hex_based = "0123456789abcdef";

    // put the 0x........
    if (add == (unsigned long)ptr) // check the tha address is the same?
        ft_putstr("0x");
    
    // if (add >= 0 && add <= 15)
    //     ft_putchar(hex_based[add]);
    // else
    // {
    //     putadd(add / 16);
    //     ft_putadd(add % 16);
    // }
    printf("%lu", add);
}

int main()
{
    char a = 'a';

    // printf("printf->%p\n", &a);
    ft_putadd(&a);
}