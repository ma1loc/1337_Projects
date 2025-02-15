#include "../src_so_long/so_long.h"

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
	
//     // check if the image is okay?
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

// // [[[[[[[ test to remove ]]]]]]
// int	i, j;
// i = 0;
// while ((game->cols * 64) != i)
// {
// 	j = 0;
// 	while ((game->rows) * 64 != j)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win, data.img, i, j);
// 		j+=64;
// 	}	
// 	i += 64;
// }