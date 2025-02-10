#include "../src_so_long/so_long.h"

void    is_map_valid(int fd)
{
    char	*line;
	size_t	line_len;

    line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_putstr_fd("Error\nMap is empty.");
	}
	line_len = ft_strlen(line);
    while (line)
    {
		if (line[line_len - 1] == '\n')
			line_len--;
        if (ft_strlen(line) != line_len)
		{
			close(fd);
			free(line);
			ft_putstr_fd("Error\nMap is not \"Rectangular\".\n");
		}
		free(line);
        line = get_next_line(fd);
    }
	close(fd);
}

char    **read_map(char *map)
{
    char    *line;
    char    **split_map;
    int     i;
    int     fd;

	if (!map)
        return (NULL);
	split_map = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (!split_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (free(split_map), NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		split_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	split_map[i] = NULL;
	close(fd);
	return (split_map);
}

void	check_is_valid_dup_char(char **map, int p, int e)
{
    if (p == 0)
        cleanup_and_exit("Error\nThere's no \"PLAYER_POSITOIN\" in provided MAP.", map);
    if (e == 0)
        cleanup_and_exit("Error\nThere's no \"EXIT_DOR\" in provided MAP.", map);
    if (p > 1)
        cleanup_and_exit("Error\nThere's a \"DUP_POSITOIN\" of the player in the MAP", map);
    if (e > 1)
        cleanup_and_exit("Error\nThere's a duplicated \"EXIT DORS\" in provided MAP", map);
}

void    count_duplicate_char_in_the_map(char **map)
{
    int     p;
    int     e;
    int     i;
	int		j;

    p = 0;
    e = 0;
    i = 0;

    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'P')
                p++;
            else if (map[i][j] == 'E')
                e++;
            j++;
        }
		i++;
    }
	check_is_valid_dup_char(map, p, e);
}

int	count_lines(char *map)
{
    int		fd;
    int		count;
    char	*line;

    count = 0;
    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_perror("Error\nopen");
    line = get_next_line(fd);
    while (line)
    {
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}


void	wall_check(char **map)
{
    int i;
	int	len_of_line;

    i = 0;
    len_of_line = ft_strlen(map[0]);
	while (map[0][i] && map[0][i] != '\n')
    {
        if (map[0][i] != '1')
            cleanup_and_exit("Error\n\"Top Walls\" not set as it expected.", map);
        i++;
    }
	i = 0;
	while (map[i][0] && map[i][len_of_line - 1])
	{
		if (map[i][0] != '1' || map[i][len_of_line - 1] != '1')
            cleanup_and_exit("Error\n\"Left or Right Walls\" not set as it expected.", map);
		i++;
	}
	i = 0;
	while (map[len_of_line - 1][i] && map[len_of_line - 1][i] != '\n')
	{
		if (map[len_of_line -1][i] != '1')
            cleanup_and_exit("Error\n\"Bottom Walls\" not set as it expected.", map);
		i++;
	}
}
