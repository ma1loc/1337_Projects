/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:20:33 by yanflous          #+#    #+#             */
/*   Updated: 2024/11/15 20:20:41 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

//char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dst, const char *src, int nbyte);
char	*ft_strchr(const char *str, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif