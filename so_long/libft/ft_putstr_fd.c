/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:46:05 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 10:46:34 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	ft_putstr_fd(char *str, int std)
{
	if (std == 1)
	{
		if (str)
			write(STDOUT_FILENO, str, ft_strlen(str));
		exit(0);
	}
	else if (std == 2)
	{
		if (str)
			write(STDERR_FILENO, str, ft_strlen(str));
		exit(1);
	}
}
