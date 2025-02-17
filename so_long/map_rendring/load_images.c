#include "../src_so_long/so_long.h"

// check that file later for inhancing !!!
void	load_player_images(t_game *game)
{
	int	width = 0;
	int	height = 0;
	
	game->player = malloc(sizeof(void *) * 6);
	if (!game->player)
	{
   		printf("Allocation failed for player images\n");
   		cleanup_and_exit("Error: Memory allocation failed for player images\n", game, 1);
	}
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

void	load_enemy_images(t_game *game)
{
    int width;
    int height;

    game->enemy[0] = mlx_xpm_file_to_image(game->mlx,\
    	"map_rendring/img_resource/enemy/enemy_0.xpm", &width, &height);
    game->enemy[1] = mlx_xpm_file_to_image(game->mlx,\
    	"map_rendring/img_resource/enemy/enemy_1.xpm", &width, &height);
    game->enemy[2] = mlx_xpm_file_to_image(game->mlx,\
    	"map_rendring/img_resource/enemy/enemy_2.xpm", &width, &height);
    game->enemy[3] = mlx_xpm_file_to_image(game->mlx,\
    	"map_rendring/img_resource/enemy/enemy_3.xpm", &width, &height);
    game->enemy[4] = mlx_xpm_file_to_image(game->mlx,\
    	"map_rendring/img_resource/enemy/enemy_4.xpm", &width, &height);
	if (!game->enemy[0] || !game->enemy[1] || !game->enemy[2] || !game->enemy[3] || !game->enemy[4])
		cleanup_and_exit("Error: Failed to load enemy images\n", game, 1); // have free some resurses here !!!
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
		cleanup_and_exit("Error: Failed to load free_sapce or wall images\n", game, 1); // have free some resurses here !!!
}

void	load_doors_images(t_game *game)
{
	int	width;
	int	height;

	game->exit_door[0] = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/door/door_close.xpm", &width, &height);
	game->exit_door[1] = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/door/door_open.xpm", &width, &height);
	if (!game->exit_door[0] || !game->exit_door[1])
		cleanup_and_exit("Error: Failed to load doors images\n", game, 1); // have free some resurses here !!!	
}

void load_coin_images(t_game *game)
{
	int width;
	int height;

	// have an update in the future !!!
	game->coin = mlx_xpm_file_to_image(game->mlx,\
		"map_rendring/img_resource/coin/coin.xpm", &width, &height);

	if (!game->coin)
		cleanup_and_exit("Error: Failed to load coins images\n", game, 1); // have free some resurses here !!!	
}
