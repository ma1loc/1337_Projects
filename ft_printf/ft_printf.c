#include "ft_printf.h"

// -basic:
// hello my name is %c -> hello my name is Y.
// with the variadic function (...) ellipses).
// -ex:
// -------------> printf("hello, my name is %c", 'Y') <------------------- Done
// --------------------> sum(4, 10, 20, 30, 40); <------------------------ not yet
// ---> printf("hello, my name is %c and my age is %d", "youness", 22) <-- not yet
// -info:
// char is promoted to int.
// with the va_list -> va_start, va_arg, va_end
// va_list  ->	Holds the state of the variable arguments.
// va_start ->  Initializes the va_list to point to the first argument.
// va_arg   ->  Retrieves the next argument of the specified type.
// va_end	->  Cleans up the va_list.

void    printf_c(char *s, ...)
{
    va_list arg;
    va_start(arg, s);

    int i = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == 'd')
                ft_putnbr(va_arg(arg, int));
        }
        else
            putchar(s[i]);
        i++;
    }
}

int main()
{
    printf_c("hello, the first litter in my name is {%d}.", 1);
    // printf_c("hello, the first litter in my name is {%d}.", 100);
}