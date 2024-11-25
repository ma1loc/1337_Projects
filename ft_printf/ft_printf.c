#include "ft_printf.h"

int    ft_printf(const char *s, ...)
{
    va_list arg;
    int count;
    int i;

    va_start(arg, s);
    i = 0;
    count = 0;
    
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            if (s[i] == '\0')
                return (count);
            count += ft_fscheck(arg, s[i]);
        }
        else
            count += ft_putchar(s[i]);
        i++;
    }
    va_end(arg);
    return (count);
}