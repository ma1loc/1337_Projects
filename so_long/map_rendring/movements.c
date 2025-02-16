#include "../src_so_long/so_long.h"

// path -> /home/yanflous/Desktop/Project_/so_long/map_rendring/img_resource/
// void    player_directions(char *str);

int	press_key(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
		game->player_row += 1;
	else if (keycode == DOWN_KEY)
		game->player_row -= 1;
	else if (keycode == LEFT_KEY)
		game->player_col -= 1;
	else if (keycode == RIGHT_KEY)
		game->player_col += 1;
	else if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

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
