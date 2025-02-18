#include "../src_so_long/so_long.h"



void map_free(char **map)
{
    if (map) 
    {
        int i = 0;
        while (map[i]) {
            free(map[i]);
            i++;
        }
        free(map);
    }
}

void cleanup_and_exit(char *str, t_game *game, int msg)
{
    if (game) 
    {
        if (game->map)
        {
            map_free(game->map);
            game->map = NULL;
        }
        if (game->map_copy) {
            map_free(game->map_copy);
            game->map_copy = NULL;
        }
        if (game->win) {
            mlx_destroy_window(game->mlx, game->win);
            game->win = NULL; 
        }
        if (game->wall) {
            mlx_destroy_image(game->mlx, game->wall);
            game->wall = NULL;
        }
        if (game->coin) {
            mlx_destroy_image(game->mlx, game->coin);
            game->coin = NULL;
        }
        if (game->free_space) {
            mlx_destroy_image(game->mlx, game->free_space);
            game->free_space = NULL;
        }
        int i = 0;
        while (i < 6)
        {
            if (game->player[i])
            {
                mlx_destroy_image(game->mlx, game->player[i]);
                game->player[i] = NULL;
            }
            i++;
        }
        i = 0;
        while (i < 3)
        {
            if (game->exit_door[i])
            {
                mlx_destroy_image(game->mlx, game->exit_door[i]);
                game->exit_door[i] = NULL;
            }
            i++;
        }
        free(game);
        game = NULL;
    }
    if (msg) {
        ft_putstr_fd(str);
    }
}