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

void    is_there_extension(char *map);
void	pars_the_file(char *map);
char    **read_map(char *map);
int     count_lines(char *map);
void	process_the_map(char *map);

// map_parsing fun
void    map_free(char **readed_map);
void	is_map_valid(char **map);
void    cleanup_and_exit(char *str, char **readed_map);

void	wall_check(char **map);
void	count_duplicate_char_in_the_map(char **map);
void	check_is_valid_dup_char(char **map, int p, int e);
int     *finding_player_position(char **map);
int     *allocate_for_row_and_col(int row, int col, char **map);

# endif
