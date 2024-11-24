#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>


#include <stdio.h>


int     ft_printf(char *s, ...);
void    ft_putchar(char c);
void    ft_putstr(char *s);
void    ft_putadd(unsigned long add);
void    ft_putnbr(int n);
void    ft_putunbr(unsigned int n);
void    ft_puthex(int n, char c);

#endif