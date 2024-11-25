/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fscheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:36:48 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/25 21:39:45 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fscheck(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		count += ft_putuint(va_arg(arg, unsigned int));
	else if (c == 'p')
		count += ft_putadd(va_arg(arg, void *));
	else
		count += ft_putchar(c);
	return (count);
}
