/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:53:27 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/21 10:21:53 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	mem_fill_join(const char *str, char *ptr, size_t idx)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ptr[idx] = str[i];
		idx++;
		i++;
	}
}

static	char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	t_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	t_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (t_len + 1));
	if (!ptr)
		return (NULL);
	mem_fill_join(s1, ptr, 0);
	mem_fill_join(s2, ptr, ft_strlen(s1));
	ptr[t_len] = '\0';
	free(s1);
	return (ptr);
}

static char	*extracted_line(char **left_ch)
{
	char	*line;
	char	*tmp;
	char	*new_line;

	if (!*left_ch)
		return (NULL);
	new_line = ft_strchr(*left_ch, '\n');
	if (new_line)
	{
		line = ft_substr(*left_ch, 0, new_line - *left_ch + 1);
		tmp = ft_strdup(new_line + 1);
		free(*left_ch);
		*left_ch = tmp;
		if (!*left_ch || **left_ch == '\0')
		{
			free(*left_ch);
			*left_ch = NULL;
		}
	}
	else
	{
		line = *left_ch;
		*left_ch = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left_ch[FD_MAX];
	char		*buffer	;
	int			read_bytes;
	char		*new_len;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 0;
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(left_ch[fd], '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(left_ch[fd]), left_ch[fd] = NULL, NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		left_ch[fd] = ft_strjoin(left_ch[fd], buffer);
	}
	free(buffer);
	new_len = extracted_line(&left_ch[fd]);
	return (new_len);
}

