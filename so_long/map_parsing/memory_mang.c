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

void    cleanup_and_exit(char *str, t_game *game, int msg)
{
    int i;

    i = 0;
    while (game->player[i])
    {
        if (game->player[i])
        {
            printf("image P -> %d\n", i);
	    	mlx_destroy_image(game->mlx, game->player[i]);
        }
        i++;
    }
    i = 0;
    while (game->exit_door[i])
    {
        if (game->exit_door[i])
        {
            printf("image E -> %d\n", i);
	    	mlx_destroy_image(game->mlx, game->exit_door[i]);
        }
        i++;
    }
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->free_sapce)
		mlx_destroy_image(game->mlx, game->free_sapce);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit_door[0])
		mlx_destroy_image(game->mlx, game->exit_door[0]);
    if (game->map)
        map_free(game->map);
    if (game->map_copy)
        map_free(game->map_copy);
    if (game->win)
	    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    if (game->wall)
        free(game->wall);
    if (game->coin)
        free(game->coin);
    if (game->free_sapce)
        free(game->free_sapce);
    free(game->mlx);
    free(game);
    if (msg)
        ft_putstr_fd(str);
}
