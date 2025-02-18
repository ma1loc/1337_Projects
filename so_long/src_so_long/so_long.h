# ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
# endif

#define UP_KEY XK_Up
#define DOWN_KEY XK_Down
#define LEFT_KEY XK_Left
#define RIGHT_KEY XK_Right
#define ESC_KEY XK_Escape

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
#include <X11/keysym.h>

size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *str, char *to_find, size_t len);
void	ft_putstr_fd(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_perror(char *str);
void	is_there_extension(char *map);
char	**read_map(char *map);
int		count_lines(char *map);
int		count_cols(char **map);
void	map_free(char **readed_map);

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	int			rows;
	int			cols;
	int			player_row;
	int			player_col;
	int			exit_row;
	int			exit_col;
	int			collectibles;
	int			collected;
	int			moves;
	int			player_count;
	int			exit_count;
	void		*mlx;			// -- done free
	void		*win;			// -- done free
	void		*wall;			// -- done
	void		*coin;			// -- done
	void		*free_space;	// -- done
	void		*player[6];		// -- done
	void		*exit_door[3];	// -- done
}	t_game;

typedef struct s_direction
{
	int new_row;
	int new_col;
} t_direction;


t_game	*pars_the_map(char *map);
t_game	*map_processing(char *map);
int		count_lines(char *map);
char    **read_map(char *map);
void	is_map_valid(t_game *game);
void	wall_check(t_game *game);
void	cleanup_and_exit(char *str, t_game *game, int msg);
void	count_duplicate_char_in_the_map(t_game *game);
void	check_is_valid_dup_char(t_game *game);
void	finding_player_position(t_game *map);
void	finding_player_exit(t_game *game);
void	map_validation_path(t_game *game, int row, int col);
void	is_reach_all_map(t_game *game);
void	process_the_map_rendering(t_game *game);
void	load_img_to_win(t_game *game);
void	load_player_images(t_game *game);
void	load_space_and_wall_images(t_game *game);
void	load_doors_images(t_game *game);
void	load_coin_images(t_game *game);
void	init_the_map(t_game *game);
int		confirmed_press_key(t_game *game, t_direction move);
void	do_press_key(t_game *game, t_direction move, int keycode);
int		press_key(int keycode, t_game *game);

#endif