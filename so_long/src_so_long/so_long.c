#include "so_long.h"

// int	main(int argc, char **argv)
// {

// 	if (argc < 2)
// 		ft_putstr_fd("Error\nA few args, put the map to play\n");
// 	if (argc == 2)
// 		pars_the_map(argv[1]);
// 	else
// 		ft_putstr_fd("Error\nToo many arguments.\
// 		\nUsage => \"./so_long map.ber\"");
// }

// #include <mlx.h>

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
