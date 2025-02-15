#include "../src_so_long/so_long.h"

// here the charcters_movements
// void    player_directions(char *str);
// directions
// path -> /home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/player.
void	load_player_images(t_game *game)
{
	int	width;
	int	height;

	game->player.up = mlx_xpm_file_to_image(game->mlx, \
	"/home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/player/1_up.xpm", \
	&width, &height);
	game->player.down = mlx_xpm_file_to_image(game->mlx, \
	"/home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/coin/coin.xpm", \
	&width, &height);
	game->player.left = mlx_xpm_file_to_image(game->mlx, \
	"/home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/space.xpm", \
	&width, &height);
	game->player.right = mlx_xpm_file_to_image(game->mlx, \
	"/home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/enemy/enemy.xpm", \
	&width, &height);

	if (!game->player.up || !game->player.down || !game->player.left || !game->player.right)
		cleanup_and_exit("Error: Failed to load player images\n", game); // have free some resurses here !!!
}

// move function.
void	player_directions(t_game *game, int key_move)
{
	if (key_move == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->player.up, game->player_col, game->player_row);
	else if (key_move == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->player.down, game->player_col, game->player_row);
	else if (key_move == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->player.left, game->player_col, game->player_row);
	else if (key_move == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.right, game->player_col, game->player_row);
}