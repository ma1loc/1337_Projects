#include "ft_printf.h"

// -basic:
// hello my name is %c -> hello my name is Y.
// with the variadic function (...) ellipses).
// -ex:
// -------------> printf("hello, my name is %c", 'Y') <------------------- Done
// --------------------> sum(4, 10, 20, 30, 40); <------------------------ Done
// ---> printf("hello, my name is %c and my age is %d", "youness", 22) <-- Done
// -info:
// char is promoted to int.
// with the va_list -> va_start, va_arg, va_end
// va_list  ->	Holds the state of the variable arguments.
// va_start ->  Initializes the va_list to point to the first argument.
// va_arg   ->  Retrieves the next argument of the specified type.
// va_end	->  Cleans up the va_list.

int    ft_printf(char *s, ...)
{
    va_list arg;
    va_start(arg, s);
    // printf("gp offset: %u\n", arg->gp_offset);
    // printf("fp offset: %u\n", arg->fp_offset);
    // printf("reg: %p\n", arg->reg_save_area);
    // printf("stack: %p\n", arg->overflow_arg_area);
    int idx = 0;
    // int count = 0;
    while (s[idx])
    {
        if (s[idx] == '%')
        {
            idx++;
            // count++;
            if (s[idx] == 'c')                    // if it char   -> %c
                ft_putchar(va_arg(arg, int));
            if (s[idx] == 's')                    // if it string -> %s
                ft_putstr(va_arg(arg, char *));
            // if (s[idx] == 'p')                 // if the string -> %p
            // noting yet   
            if (s[idx] == 'd' || s[idx] == 'i')   // if it digit  -> %d or %i
                ft_putnbr(va_arg(arg, int));
            // the hexadecimal (base 16) -> {0-9, A-F}
            if (s[idx] == 'x' || s[idx] == 'X')                    // if it hexadecimal lower -> %x
                ft_put_hex(va_arg(arg, int), s[idx]);
            // if (s[idx] == 'X')                 // if it hexadecimal lower -> %x
            // noting yet
            if (s[idx] == 'u')                    // if it udigit -> %u
                ft_put_unint(va_arg(arg, int));
            
            
            // the (%%) ?
        }
        else
            ft_putchar(s[idx]);
        idx++;
        // count++;
    }
    // return (count);
}

int main()
{

    int count = ft_printf("char -> %c name -> %sage -> %d",'Y', "youness", 21);
    //printf("\nthe length -> %d\n", count);
    // ft_printf("[%d]--[%i]", 21, 12);
    // ft_printf("char -> %cname -> %s\nage -> %d",'Y', "youness", 21);
    // printf_c("hello, the first litter in my name is {%d}.", 100);
}