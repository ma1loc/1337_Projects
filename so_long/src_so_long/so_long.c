#include "so_long.h"

int	main(int argc, char **argv)
{

	if (argc < 2)
		ft_putstr_fd("Error\nA few args, put the map to play\n");
	if (argc == 2)
		pars_the_file(argv[1]);
	else
		ft_putstr_fd("Error\nToo many arguments.\
		\nUsage => \"./so_long map.ber\"");
}
