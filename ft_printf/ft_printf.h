#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *s, ...); // done
int ft_fscheck(va_list arg, char c); // done
int ft_putchar(char c); // done
int ft_putstr(char *s); // done
int ft_putnbr(int n); // done 
int ft_puthex(unsigned int, char c); // done
int ft_putuint(unsigned int un); // done

int ft_putadd(void *add); // not yet

#endif