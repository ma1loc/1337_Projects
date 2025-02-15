#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int		height;
	int 	width;
	t_data 	data;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failed.", game);
	height = game->cols * 64;
	width = game->rows * 64;
	game->win = mlx_new_window(game->mlx, height, width, "so_long"); // return win instance pointer ?
	if (!game->mlx) // use the [mlx_destroy_window]
		cleanup_and_exit("Error\nWindow failed to open.", game); // here have to free the [game->mlx]
	data.height = height;
	data.width = width;
}

// ------------ i have to work for this part now  -------------
void	put_img_to_win(t_game *game)
{
    t_data	data; // there remove?

	// set the textures (space, wall, playser, ) what if i have more then one in the player for example i have to put all the textures of it
	// why the mlx_xpm_file_to_image take at the end & of int?
	data.img = mlx_xpm_file_to_image(game->mlx, "/home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/player/1_up.xpm", &data.width, &data.height);
	if (!data.img) // here have to clear and msg the error
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error\nFailed to reach the image path", game);
	}

	// have i put it in a functoin to set the all images to the map ??? 
	//					   [  init	 , 	 window ,  image , ?, ?]
	load_player_images(game);
	
	int i = 0;
	while (i <= 4)
	{
		if (i == 4)
			i = 0;
		player_directions(game, i);
		i++;
	}
    // mlx_put_image_to_window(game->mlx, game->win, data.img, game->player_col, game->player_row);
}

void    process_the_map_rendering(t_game *game)
{
	init_and_window(game); // done!!! (Create a new window.)
	put_img_to_win(game);
	mlx_loop(game->mlx); // this is for what? (is keep the window open, i think so !!!)
}
