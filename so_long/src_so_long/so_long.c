#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		ft_putstr_fd("Error\nA few args, put the map to play\n");
	if (argc == 2)
	{
		game = pars_the_map(argv[1]);
		process_the_map_rendering(game);
	}
	else
		ft_putstr_fd("Error\nToo many arguments.\
		\nUsage => \"./so_long map.ber\"");
	// have a func to batter free the resurses.
	map_free(game->map);
	map_free(game->map_copy);
	free(game);
}
