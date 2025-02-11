#include "../src_so_long/so_long.h"

int	count_lines(char *map)
{
    int		fd;
    int		count;
    char	*line;

    count = 0;
    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_perror("Error\nOpen");
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
        // check here the the collacts.
}

void    count_duplicate_char_in_the_map(char **map)
{
    int     p;
    int     e;
    int     c;
    int     i;
	int		j;

    p = 0;
    e = 0;
    c = 0;
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
            else if (map[i][j] == 'C') // add the check of the collacts.
                c++;
            j++;
        }
		i++;
    }
	check_is_valid_dup_char(map, p, e);
}



void last_row(char **map)
{
    char *_last_row;
    int i;

    i = 0;
    while (map[i])
        i++;
    i--;
    _last_row = map[i];
    i = 0;
	while (_last_row[i])
	{
		if (_last_row[i] != '1')
            cleanup_and_exit("Error\n\"Bottom Walls\" not set as it expected.", map);
		i++;
	}
}

void	wall_check(char **map)
{
    int		i;
	size_t	len_of_line;

    i = 0;
    while (map[0][i] && map[0][i] != '\n')
    {
        if (map[0][i] != '1')
            cleanup_and_exit("Error\n\"Top Walls\" not set as it expected.", map);
        i++;
    }
	i = 0;
    len_of_line = ft_strlen(map[0]);
	while (map[i])
	{
        if (map[i][len_of_line - 1] == '\n')
            len_of_line -= 1;

		if (map[i][0] != '1' || map[i][len_of_line - 1] != '1')
            cleanup_and_exit("Error\n\"Left or Right Walls\" not set as it expected.", map);
		i++;
	}
    last_row(map);
}
