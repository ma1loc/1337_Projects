#include "../src_so_long/so_long.h"

void	load_player_images(t_game *game)
{
	int	width = 0;
	int	height = 0;

	game->player[0] = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/defult.xpm", \
	&	width, &height);
	game->player[1] = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/up.xpm", \
	&	width, &height);
	game->player[2] = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/down.xpm", \
		&width, &height);
	game->player[3] = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/left.xpm", \
		&width, &height);
	game->player[4] = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/right.xpm", \
		&width, &height);
	game->player[5] = NULL;
	if (!game->player[0] || !game->player[1] || !game->player[2] \
		|| !game->player[3] || !game->player[4])
		cleanup_and_exit("Error: Failed to load player images\n", game, 1);
}

void load_space_and_wall_images(t_game *game)
{
	int	width;
	int	height;
	
	game->free_sapce = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/background/space.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/wall/wall.xpm", &width, &height);
	if (!game->free_sapce || !game->wall)
		cleanup_and_exit("Error: Failed to load free_sapce or wall images\n", game, 1);
}

void	load_doors_images(t_game *game)
{
	int	width;
	int	height;

	game->exit_door[0] = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/door/door_close.xpm", &width, &height);
	game->exit_door[1] = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/door/door_open.xpm", &width, &height);
	game->exit_door[2] = NULL;
	if (!game->exit_door[0] || !game->exit_door[1])
		cleanup_and_exit("Error: Failed to load doors images\n", game, 1);
}

void load_coin_images(t_game *game)
{
	int width;
	int height;

	game->coin = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/coin/coin.xpm", &width, &height);
	if (!game->coin)
		cleanup_and_exit("Error: Failed to load coins images\n", game, 1);
}
