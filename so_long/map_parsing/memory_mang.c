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

// void    img_free(t_game *game)
// {
//     int i;

//     i = 0;
//     while (game->player[i])
//     {
//         free(game->player[i]);
//         i++;
//     }
//     free(game->player);
//     i = 0;
//     while (game->enemy[i])
//     {
//         free(game->enemy[i]);
//         i++;
//     }
//     free(game->enemy);
//     i = 0;
//     while (game->exit_door[i])
//     {
//         free(game->exit_door[i]);
//         i++;
//     }
//     free(game->exit_door);
// }

void    cleanup_and_exit(char *str, t_game *game, int msg)
{
    if (game->map)
        map_free(game->map);
    if (game->map_copy)
        map_free(game->map_copy);
    if (game->win)
	    mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        free(game->mlx);

    // if (game->wall)
    //     free(game->wall);
    // if (game->free_sapce)
    //     free(game->free_sapce);
    
    free(game);
    if (msg)
        ft_putstr_fd(str);
}
