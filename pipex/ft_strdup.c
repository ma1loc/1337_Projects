/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:03:30 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/08 10:11:39 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s1);
	dup = malloc(sizeof(char) * (s_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s_len > i)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
