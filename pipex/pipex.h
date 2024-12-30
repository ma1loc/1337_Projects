# ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

char	**ft_split(char *str, char c);
size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int exit_status);

char	**get_command_path(char *command);

# endif
