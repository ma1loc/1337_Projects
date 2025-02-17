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

int	press_key(int keycode, t_game *game)
{
    t_direction row;
	t_direction col;

	row.new_row = game->player_row;
	col.new_col = game->player_col;
	
	int new_row = game->player_row;
    int new_col = game->player_col;

    if (keycode == UP_KEY)
		row.new_row -= 1;
    else if (keycode == DOWN_KEY)
        row.new_row += 1;
    else if (keycode == LEFT_KEY)
		col.new_col -= 1;
    else if (keycode == RIGHT_KEY)
		col.new_col += 1;
    else if (keycode == ESC_KEY)
        exit(0);
	return (keycode)
}

void	do_press_key(t_game *game)
{


	if (game->map[row.new_row][col.new_col] == '1')
		return ;
    mlx_put_image_to_window(game->mlx, game->win, game->free_sapce, game->player_col * 64, game->player_row * 64);

    if (keycode == UP_KEY)
        mlx_put_image_to_window(game->mlx, game->win, game->player.up, game->player_col * 64, game->player_row * 64);
    else if (keycode == DOWN_KEY)
        mlx_put_image_to_window(game->mlx, game->win, game->player.down,  game->player_col * 64, game->player_row * 64);
    else if (keycode == LEFT_KEY)
        mlx_put_image_to_window(game->mlx, game->win, game->player.left,  game->player_col * 64, game->player_row * 64);
    else if (keycode == RIGHT_KEY)
        mlx_put_image_to_window(game->mlx, game->win, game->player.right, game->player_col * 64, game->player_row * 64);
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
