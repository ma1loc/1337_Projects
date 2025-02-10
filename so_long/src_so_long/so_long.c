#include "so_long.h"

void	map_check(char *map)
{
	int		fd;
	char	**readed_map;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_perror("Error\nopen");
	is_map_valid(fd);
	readed_map = read_map(map);
	if (!readed_map)
	{
		close(fd);
		ft_putstr_fd("Error\nMap can not be readed.");
	}
	count_duplicate_char_in_the_map(readed_map);
	wall_check(readed_map);
}

int	main(int argc, char **argv)
{

	// args up 2?
	if (argc < 2)
		ft_putstr_fd("Error\nA few args, put the map to play\n");
	if (argc == 2)
	{
		file_check(argv[1]);
		map_check(argv[1]);
	}
	else
		ft_putstr_fd("Error\nToo many arguments.\
		\nUsage => \"./so_long map.ber\"");
}
