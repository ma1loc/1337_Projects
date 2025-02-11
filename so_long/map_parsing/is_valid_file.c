#include "../src_so_long/so_long.h"

void	is_there_extension(char *map)
{
    int	len;

	len = ft_strlen(map);
	if (len < 4 || ft_strncmp(&map[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nThe extenstion not valid.\
		\nUsage => \"./so_long map.ber\".");
	}
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

void	process_the_map(char *map)
{
	char		**readed_map;
	t_position	*player_position;

	readed_map = read_map(map);
	if (!readed_map)
		ft_putstr_fd("Error\nMap can not be readed.");
	is_map_valid(readed_map);
	count_duplicate_char_in_the_map(readed_map);
	wall_check(readed_map);
	player_position = finding_player_position(readed_map);
	if (!player_position)
		cleanup_and_exit("Error\nFailed to reach the player position.", readed_map);
	map_free(readed_map);
	free(player_position);
}

void	pars_the_file(char *map)
{
	is_there_extension(map);
	process_the_map(map);
}
