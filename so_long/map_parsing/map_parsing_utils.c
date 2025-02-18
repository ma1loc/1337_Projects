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
	i = 0;
	line = get_next_line(fd);
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