# ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// libft functions
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *str, char *to_find, size_t len);
void	ft_putstr_fd(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void    ft_perror(char *str);

// file checking fun
void     is_have_dot(char *str);
void    is_there_anything_before_dot(char *map);
int     is_there_extension(char *map);
void	file_check(char *map);

// map_parsing fun
void    wall_check(char *line);
void    is_duplicate_char(char *map);
void    is_map_valid(int fd);

# endif