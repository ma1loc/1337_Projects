#include "../src_so_long/so_long.h"

void	load_player_images(t_game *game)
{
	int	width;
	int	height;

	game->player.up = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/up.xpm", \
	&	width, &height);
	game->player.down = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/down.xpm", \
		&width, &height);
	game->player.left = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/left.xpm", \
		&width, &height);
	game->player.right = mlx_xpm_file_to_image(game->mlx, \
		"map_rendring/img_resource/player/right.xpm", \
		&width, &height);
	if (!game->player.up || !game->player.down || !game->player.left || !game->player.right)
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error: Failed to load player images\n", game); // have free some resurses here !!!
	}
}

void load_enemy_images(t_game *game)
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
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error: Failed to load enemy images\n", game); // have free some resurses here !!!
	}
}
