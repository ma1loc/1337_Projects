#include "ft_printf.h"

int    ft_putadd(void *ptr)
{
     unsigned long add;
    add = (unsigned long)ptr;
    
    ft_putstr("0x");
    ft_puthex(add, 'x');
    return 1;
}