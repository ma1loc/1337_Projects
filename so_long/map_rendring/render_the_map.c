#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{	// done so !!!
	int		height;
	int 	width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failed.", game);
	height = game->cols * 64;
	width = game->rows * 64;
	game->win = mlx_new_window(game->mlx, height, width, "so_long");
	if (!game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error\nWindow failed to open.", game);
	}
}

// ------------ i have to work for this part now  -------------
void	put_img_to_win(t_game *game)
{
	// void *img;
	// int h, w;
	// img = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/door/door_open.xpm", &h, &w);
	// if (!img)
	// {
	// 	printf("not such file");
	// 	exit(1);
	// }
    // mlx_put_image_to_window(game->mlx, game->win, img, game->player_col, game->player_row);

	load_player_images(game);
	load_enemy_images(game);

	// player_directions(game, 0);
	// enemy_directions(game);
}

void    process_the_map_rendering(t_game *game)
{
	// set the textures (space, wall, playser, ) what if i have more then one in the player for example i have to put all the textures of it
	// init_and_window(game); // done!!! (Create a new window.)
	put_img_to_win(game);
	// mlx_loop(game->mlx); // this is for what? (is keep the window open, i think so !!!)
}
