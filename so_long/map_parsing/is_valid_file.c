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

void    is_map_valid(int fd)
{
    char	*line;
	size_t	line_len;

    line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_putstr_fd("Error\nMap is empty."); // check
	}
	line_len = ft_strlen(line);
    while (line)
    {
		// if (line[line_len - 1] == '\n')
		// 	line_len--;
        if (ft_strlen(line) != line_len)
		{
			close(fd);
			free(line);
			ft_putstr_fd("Error\nMap is not \"Rectangular\".\n"); // check
		}
		free(line);
        line = get_next_line(fd);
    }
	close(fd);
}

void	process_the_map(char *map)
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

void	pars_the_file(char *map)
{
	is_there_extension(map); // valid.
	process_the_map(map); // valid.
}
