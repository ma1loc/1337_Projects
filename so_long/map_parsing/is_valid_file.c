#include "../src_so_long/so_long.h"

void	is_there_extension(char *map)
{
    int	len;
	
	len = ft_strlen(map);
	if (len < 4 || ft_strncmp(&map[len - 4], ".ber", 4) != 0 ||
	(ft_strncmp(map, ".ber", 4) == 0))
		ft_putstr_fd("Error\nThe extenstion not valid.\
		\nUsage => \"./so_long *.ber\".");
}

void    is_map_valid(char **map)
{
	size_t	len_line;
	char	*line;
	int		i;

	i = 0;
	if (map[i])
		len_line = ft_strlen(map[i]);
	else
		cleanup_and_exit("Error\nMap is empty.", map);
    while (map[i])
    {
		line = map[i];
		if (line[len_line - 1] != '\n')
 			len_line--;
		if (ft_strlen(line) != len_line)
            cleanup_and_exit("Error\nMap is not \"Rectangular\".\n", map);
		i++;
    }
}

t_game	*map_processing(char *map)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_putstr_fd("Error\nAllocation faild.");

	game->map = read_map(map);
	is_map_valid(game->map);
	count_duplicate_char_in_the_map(game);
	wall_check(game->map);
	game->rows = count_lines(map);
	game->cols = count_cols(game->map);
	finding_player_position(game);
	finding_player_exit(game);	
	game->map_copy = read_map(map);
	return (game);
}


void	pars_the_map(char *map)
{
	t_game *game;

	is_there_extension(map);
	game = map_processing(map);

	// free resu.
	map_free(game->map);
	map_free(game->map_copy);
	free(game);
}
