#include "../src_so_long/so_long.h"

// valid job (have some cases for memory have to be handeld)
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
	game->win = mlx_new_window(game->mlx, height, width, "so_long");
	if (!game->mlx)
		cleanup_and_exit("Error\nWindow failed to open.", game); // here have to free the [game->mlx]
	data.height = height;
	data.width = width;
}

void	put_img_to_win(t_game *game)
{
    t_data	data;

	// set the textures (space, wall, playser, ) what if i have more then one in the player for example i have to put all the textures of it
	data.img = mlx_xpm_file_to_image(game->mlx, "/home/yanflous/Desktop/Project_/so_long/map_rendring/images/wall.xpm", &data.width, &data.height); // check null
	if (!data.img) // here have to clear and msg the error
		cleanup_and_exit("Error\nFailed to reach the image path", game);
	
	// have i put it in a functoin to set the all images to the map ??? 
	//					   [  init	 , 	 window ,  image , ?, ?]
    // mlx_put_image_to_window(game->mlx, game->win, data.img, 0, 0);
	// [[[[[[[ test to remove ]]]]]]
	int	i, j;
	i = 0;
	while ((game->cols * 64) != i)
	{
		j = 0;
		while ((game->rows) * 64 != j)
    	{
			mlx_put_image_to_window(game->mlx, game->win, data.img, i, j);
			j+=64;
		}	
		i += 64;
	}
}

void    process_the_map_rendering(t_game *game)
{
    // 0# initializeation with the mlx_init()
    // 1# the first thing first i have to create a window (i don't think i have to be same size of the map?)
	init_and_window(game); // done!!!
	put_img_to_win(game);
	mlx_loop(game->mlx); // this is for what? (is keep the window open, i think so !!!)
}
