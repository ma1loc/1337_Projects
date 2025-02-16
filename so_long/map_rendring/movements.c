#include "../src_so_long/so_long.h"

// path -> /home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/
// void    player_directions(char *str);


void	player_directions(t_game *game, int key_move)
{
	if (key_move == 0)		//	[ init	 , 	window ,    image        ,        ?,                 ?]			
		mlx_put_image_to_window(game->mlx, game->win, game->player.up, game->player_col, game->player_row);
	else if (key_move == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->player.down, game->player_col, game->player_row);
	else if (key_move == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->player.left, game->player_col, game->player_row);
	else if (key_move == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.right, game->player_col, game->player_row);
}

void	enemy_directions(t_game *game)
{
	int i;

	i = 0;
	while (i <= 4)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy[0], game->player_col, game->player_row);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy[1], game->player_col, game->player_row);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy[2], game->player_col, game->player_row);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy[3], game->player_col, game->player_row);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy[4], game->player_col, game->player_row);
		if (i == 4)
			i = 0;
	}
}