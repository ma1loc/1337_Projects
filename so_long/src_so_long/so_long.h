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
char    **read_map(char *map);
int     count_lines(char *map);

// map_parsing fun
void    map_free(char **readed_map);
void	is_map_valid(char **map);
void    cleanup_and_exit(char *str, char **readed_map);

void	wall_check(char **map);

typedef struct s_game
{
	char    **map;         // The original map
	char    **map_copy;    // Copy of the map for validation (BFS)
	int     rows;          // Number of rows in the map
	int     cols;          // Number of columns in the map
	int     player_y;      // Player's Y position (row) 		-- done
	int     player_x;      // Player's X position (column)		-- done
	int     exit_x;        // Exit's X position (column) 		-- done
	int     exit_y;        // Exit's Y position (row) 			-- done
	int     collectibles;  // Total collectibles count			-- done
	int     collected;     // Number of collected items
	int     moves;         // Number of moves taken by the player
	int		player_count;  // count the number of the P in the map
	int		exit_count;	   // count the number of the E in the map

    // void    *mlx;          
    // void    *win;          
    // void    *textures[5];
} t_game;

// typedef struct s_position
// {
//     int row;
//     int col;
// } t_position;

t_game	*map_process(char *map);
void	pars_the_map(char *map);
void	count_duplicate_char_in_the_map(t_game *game);
void	check_is_valid_dup_char(t_game *game);
void    finding_player_position(t_game *map);
void	finding_player_exit(t_game *game);

# endif
