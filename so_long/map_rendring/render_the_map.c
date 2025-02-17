#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int		height;
	int 	width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failed.", game);
	width = game->cols * 64;
	height = game->rows * 64;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error\nWindow failed to open.", game);
	}
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
	{
		game->player_row += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.up, game->player_col *64, game->player_row *64);
	}
	else if (keycode == DOWN_KEY)
	{
		game->player_row -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.down, game->player_col *64, game->player_row *64);
	}
	else if (keycode == LEFT_KEY)
	{
		game->player_col -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.left, game->player_col *64, game->player_row *64);
	}
	else if (keycode == RIGHT_KEY)
	{
		game->player_col += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.right, game->player_col *64, game->player_row *64);
	}
	else if (keycode == ESC_KEY)
		exit(0);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, game->player_col, game->player_row); // this will replace the player movment to the wall
	return (0);
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
				mlx_put_image_to_window(game->mlx, game->win, game->player.right, col *64, row *64);
			else if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, col *64, row *64);
			else if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->free_sapce, col *64, row *64);
			else if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coin, col *64, row *64);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_door[0], col *64, row *64);
			// if (game->map[row][col] == 'N')
			// 	mlx_put_image_to_window(game->mlx, game->win, game->wall, game->player_col *64, game->player_row *64);
			col++;
		}
		row++;
	}
}

void	put_img_to_win(t_game *game)
{
	// load the images
	load_player_images(game);
	load_enemy_images(game);
	load_space_and_wall_images(game);
	load_coin_images(game);
	load_doors_images(game);

	// Render the Initial Map
	init_the_map(game);
}


// -------------- main func -----------------
void process_the_map_rendering(t_game *game)
{
    init_and_window(game);
    put_img_to_win(game);
    mlx_key_hook(game->win, press_key, game);
    mlx_loop(game->mlx);
}
