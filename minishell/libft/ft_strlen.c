/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:41:48 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/08 15:53:58 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mini_shell/mini_shell.h"

size_t	ft_strlen(const char *str)
{
	size_t	s_len;

	s_len = 0;
	while (str[s_len])
	{
		s_len++;
	}
	return (s_len);
}
