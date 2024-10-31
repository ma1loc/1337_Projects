/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:03:18 by yanflous          #+#    #+#             */
/*   Updated: 2024/10/30 15:19:09 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	t_len;
	char	*ptr;
	size_t	i;

	i = 0;
	t_len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (!ptr)
		return (NULL);
	while (i < t_len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
