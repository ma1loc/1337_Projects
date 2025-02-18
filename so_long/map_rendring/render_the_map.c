#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int		height;
	int 	width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nnInitialization of the mlx failedn\n", game, 1);
	width = game->cols * 64;
	height = game->rows * 64;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		cleanup_and_exit("Error\nWindow failed to open.", game, 1);
}

void	load_img_to_win(t_game *game)
{
	load_player_images(game);
	load_space_and_wall_images(game);
	load_coin_images(game);
	load_doors_images(game);
	init_the_map(game);
}

void process_the_map_rendering(t_game *game)
{
	game->collected = 0;
    init_and_window(game);
    load_img_to_win(game);
    mlx_key_hook(game->win, press_key, game);
    mlx_loop(game->mlx);
}
