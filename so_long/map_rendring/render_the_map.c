#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{	// done so !!!
	int		height;
	int 	width;
	
	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failed.", game);
	height = game->cols * 64;
	width = game->rows * 64;
	game->win = mlx_new_window(game->mlx, height, width, "so_long");
	if (!game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		cleanup_and_exit("Error\nWindow failed to open.", game);
	}
}

void	put_img_to_win(t_game *game)
{	// done so !!!
	load_player_images(game);
	load_enemy_images(game);

	player_directions(game, 0);
}



// void    process_the_map_rendering(t_game *game)
// {
// 	// set the textures (space, wall, playser, ) what if i have more then one in the player for example i have to put all the textures of it
// 	init_and_window(game); // done!!! (Create a new window.)
// 	put_img_to_win(game);

// 	mlx_key_hook(game->mlx, press_key, game);

// 	mlx_loop(game->mlx); // this is for what? (is keep the window open, i think so !!!)
// }

// #include <mlx.h>

// int press_key(int keycode, t_game *game)
// {
//     if (keycode == 65361)  // Left arrow key
//         game->player_col -= 1;
//     else if (keycode == 65363)  // Right arrow key
//         game->player_col += 1;
//     else if (keycode == 65362)  // Up arrow key
//         game->player_row -= 1;
//     else if (keycode == 65364)  // Down arrow key
//         game->player_row += 1;
//     else if (keycode == 65307)  // ESC key
//         exit(0);  // Exit the game

//     return 0;
// }

void process_the_map_rendering(t_game *game)
{
    init_and_window(game); // Create a new window.
    put_img_to_win(game);  // Draw the initial state of the map.

    mlx_key_hook(game->win, press_key, game);  // Register the key event handler.
    mlx_loop(game->mlx);  // Enter the event loop, keeping the window open and responsive.
}
