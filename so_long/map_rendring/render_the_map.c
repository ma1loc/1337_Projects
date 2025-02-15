#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int height;
	int width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failed.", game);
	height = game->cols * 64;
	width = game->rows * 64;
	game->win = mlx_new_window(game->mlx, height, width, "so_long");
	if (!game->mlx)
		cleanup_and_exit("Error\nWindow failed to open.", game); // here have to free the [game->mlx]
	mlx_loop(game->mlx); // this is for what?
}

void    process_the_map_rendering(t_game *game)
{
    // 0# initializeation with the mlx_init()
    // 1# the first thing first i have to create a window (i don't think i have to be same size of the map?)
	init_and_window(game);
}

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data  img;
//     int     width, height;

//     mlx = mlx_init();
// 	// reso based on the map
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long"); // here a open the fucking window.
// 	// initalize the img of the window (put image to the window)
// 	// check if the image is okay?
//     img.img = mlx_xpm_file_to_image(mlx, "/home/yanflous/Desktop/Project_/so_long/images/mny.xpm", &width, &height); // check null
// 	if (!img.img)
// 		return (0);
// 	int	h= 0;
// 	while (h != 1080)
// 	{
//     	mlx_put_image_to_window(mlx, mlx_win, img.img, h, 0);
// 		h += 64;
// 	}

//     mlx_loop(mlx);
// }
