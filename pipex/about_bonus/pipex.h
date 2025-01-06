/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:37:25 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/06 09:41:18 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split(char *str, char c);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	cmd_executed(char *argv, char **env);
int		check_path_exists(char **env);

#endif
