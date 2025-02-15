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

void	put_img_to_win(t_game *game)
{
    t_data	data; // there remove?

	// set the textures (space, wall, playser, ) what if i have more then one in the player for example i have to put all the textures of it
	data.img = mlx_xpm_file_to_image(game->mlx, "/home/yanflous/Desktop/Project_/so_long/map_rendring/images/space.xpm", &data.width, &data.height);
	if (!data.img) // here have to clear and msg the error
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error\nFailed to reach the image path", game);
	}
	// have i put it in a functoin to set the all images to the map ??? 
	//					   [  init	 , 	 window ,  image , ?, ?]
    mlx_put_image_to_window(game->mlx, game->win, data.img, 0, 0);

}

void    process_the_map_rendering(t_game *game)
{
	init_and_window(game); // done!!! (Create a new window.)
	put_img_to_win(game);
	mlx_loop(game->mlx); // this is for what? (is keep the window open, i think so !!!)
}
