/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:45:34 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/27 17:00:01 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int so_long_return(int sign)
{
	if (sign == -1)
		return (1);
	else
		return (0);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long		result;
	int					i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		if (result >= 9223372054775807)
			so_long_return(sign);
		if (result < 9223372054775807)
			return(-1);	
		i++;
	}
	return (result * sign);
}
