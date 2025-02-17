#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int		height;
	int 	width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nnInitialization of the mlx failedn\n", game, 1);
	width = game->cols * 64;
	height = game->rows * 64;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		cleanup_and_exit("Error\nWindow failed to open.", game, 1);
}

void	init_the_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player[0], col *64, row *64);
			else if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, col *64, row *64);
			else if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->free_sapce, col *64, row *64);
			else if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coin, col *64, row *64);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_door[0], col *64, row *64);
			if (game->map[row][col] == 'N')		// here's the enemy !!!
				mlx_put_image_to_window(game->mlx, game->win, game->enemy[0], col *64, row *64);
			col++;
		}
		row++;
	}
}

int press_key(int keycode, t_game *game)
{
    t_direction move;

	move.new_row = game->player_row;
	move.new_col = game->player_col;

    if (keycode == UP_KEY)
		move.new_row -= 1;
    else if (keycode == DOWN_KEY)
        move.new_row += 1;
    else if (keycode == LEFT_KEY)
		move.new_col -= 1;
    else if (keycode == RIGHT_KEY)
		move.new_col += 1;
	else if (keycode == ESC_KEY)
		exit(0);
	else
		return (0);
	do_press_key(game, move, keycode);
	return (0);
}

int	confirmed_press_key(t_game *game, t_direction move)
{
	if (game->map[move.new_row][move.new_col] == '1' || 
		game->map[move.new_row][move.new_col] == 'E')
		return (1);
	if (game->map[move.new_row][move.new_col] == 'N')
	{
		printf("Game Over, you loss\n");
		exit(0);
	}
	if (game->map[move.new_row][move.new_col] == 'C')
	{
		printf("collected -> %d\n", game->collected);
		printf("collectebles -> %d\n", game->collectibles);
		if (game->collected == game->collectibles)
			mlx_put_image_to_window(game->mlx, game->win, game->exit_door[1],\
				game->exit_col *64, game->exit_row *64);
		game->collected += 1;
	}
	return (0);
}

void	do_press_key(t_game *game, t_direction move, int keycode)
{
	if (confirmed_press_key(game, move) == 1)
		return;
	game->map[game->player_row][game->player_col] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->free_sapce,\
		game->player_col * 64, game->player_row * 64);
	game->player_col = move.new_col;
	game->player_row = move.new_row;
	if (keycode == UP_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[1],\
			game->player_col * 64, game->player_row * 64);
	else if (keycode == DOWN_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[2],\
			game->player_col * 64, game->player_row * 64);
	else if (keycode == LEFT_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[3],\
			game->player_col * 64, game->player_row * 64);
	else if (keycode == RIGHT_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[4],\
			game->player_col * 64, game->player_row * 64);
}	

void	load_img_to_win(t_game *game)
{
	load_player_images(game);
	load_enemy_images(game);
	load_space_and_wall_images(game);
	load_coin_images(game);
	load_doors_images(game);
	init_the_map(game);
}


// -------------- main func -----------------
void process_the_map_rendering(t_game *game)
{
	game->collected = 1;
    init_and_window(game);
    load_img_to_win(game);
    mlx_key_hook(game->win, press_key, game);
    mlx_loop(game->mlx);
}
