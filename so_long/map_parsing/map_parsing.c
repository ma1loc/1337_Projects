#include "../src_so_long/so_long.h"

void    wall_check(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\n')
    {
        if (line[i] != '1')
            ft_putstr_fd("Error\nWalls not set as it expected.");
        i++;
    }
}
void    is_duplicate_char(char *map)
{
    char    *line;
    int     p;
    int     e;
    int     i;
    int     fd;

    p = 0;
    e = 0;
    i = 0;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        ft_perror("Error\nopen");
    line = get_next_line(fd);
    while (line)
    {
        while(line[i])
        {
            if (line[i] == 'P')
                p += 1;
            else if (line[i] == 'E')
                e += 1;
            i++;
        }
        line = get_next_line(fd);
    }

    if (p == 0)
        ft_putstr_fd("Error\nThere's no \"PLAYER_POSITOIN\" in provided MAP.");
    if (e == 0)
        ft_putstr_fd("Error\nThere's no \"EXIT_DOR\" in provided MAP.");
    if (p > 1)
        ft_putstr_fd("Error\nThere's a \"DUP_POSITOIN\" of the player in the MAP");
    if (e > 1)
        ft_putstr_fd("Error\nThere's a duplicated \"EXIT DORS\" in provided MAP");
}

void    is_map_valid(int fd)
{
    char *line;

    line = get_next_line(fd);
    wall_check(line);

    line = get_next_line(fd);
    while (line)
    {
        if (line[0] != '1')
            ft_putstr_fd("Error\nWalls not set as it expected.");
        line = get_next_line(fd);
    }
}