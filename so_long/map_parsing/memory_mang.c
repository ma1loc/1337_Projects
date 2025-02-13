#include "../src_so_long/so_long.h"

void    map_free(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void    cleanup_and_exit(char *str, t_game *game)
{
    if (game->map)
        map_free(game->map);
    if (game->map_copy)
        map_free(game->map_copy);
    free(game);
    ft_putstr_fd(str);
}
