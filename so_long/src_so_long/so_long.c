#include "so_long.h"

void	build_window(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
}

void image(void)
{
	void	*img;
	void	*mlx;

	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);

}

// int	main(int argc, char **argv)
// {

// 	if (argc < 2)
// 		ft_putstr_fd("Error\nA few args, put the map to play\n");
// 	if (argc == 2)
// 		pars_the_map(argv[1]);
// 	else
// 		ft_putstr_fd("Error\nToo many arguments.\
// 		\nUsage => \"./so_long map.ber\"");


int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     width, height;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long"); // here a open the fucking window.
	// initalize the img of the window (put image to the window)
    img.img = mlx_xpm_file_to_image(mlx, "/home/yanflous/Desktop/Project_/so_long/images/mny.xpm", &width, &height);

	int	h;

	h = 0;
	while (h != 1080)
	{
    	mlx_put_image_to_window(mlx, mlx_win, img.img, h, 0);
		h += 64;
	}

    mlx_loop(mlx);
}
