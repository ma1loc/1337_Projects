#include "../src_so_long/so_long.h"

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data  img;
//     int     width, height;

//     mlx = mlx_init();
// 	// reso based on the map
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long"); // here a open the fucking window.
// 	// initalize the img of the window (put image to the window)
	
//     // check if the image is okay?
//     img.img = mlx_xpm_file_to_image(mlx, "/home/yanflous/Desktop/Project_/so_long/images/mny.xpm", &width, &height); // check null
// 	if (!img.img)
// 		return (0);
// 	int	h= 0;
// 	while (h != 1080)
// 	{
//     	mlx_put_image_to_window(mlx, mlx_win, img.img, h, 0);
// 		h += 64;
// 	}
//     mlx_loop(mlx);
// }

// // [[[[[[[ test to remove ]]]]]]
// int	i, j;
// i = 0;
// while ((game->cols * 64) != i)
// {
// 	j = 0;
// 	while ((game->rows) * 64 != j)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win, data.img, i, j);
// 		j+=64;
// 	}	
// 	i += 64;
// }

// int press_key(int keycode, t_game *game)
// {
//     int new_row = game->player_row;
//     int new_col = game->player_col;

//     if (keycode == UP_KEY)
//         new_row -= 1;
//     else if (keycode == DOWN_KEY)
//         new_row += 1;
//     else if (keycode == LEFT_KEY)
//         new_col -= 1;
//     else if (keycode == RIGHT_KEY)
//         new_col += 1;
//     else if (keycode == ESC_KEY)
//         exit(0);

//     if (game->map[new_row][new_col] != '1')
//     {
//         mlx_put_image_to_window(game->mlx, game->win, game->free_sapce, game->player_col * 64, game->player_row * 64);

//         // Update player's position
//         game->player_row = new_row;
//         game->player_col = new_col;

//         // Draw the new player position with the correct sprite
//         if (keycode == UP_KEY)
//             mlx_put_image_to_window(game->mlx, game->win, game->player.up, new_col * 64, new_row * 64);
//         else if (keycode == DOWN_KEY)
//             mlx_put_image_to_window(game->mlx, game->win, game->player.down, new_col * 64, new_row * 64);
//         else if (keycode == LEFT_KEY)
//             mlx_put_image_to_window(game->mlx, game->win, game->player.left, new_col * 64, new_row * 64);
//         else if (keycode == RIGHT_KEY)
//             mlx_put_image_to_window(game->mlx, game->win, game->player.right, new_col * 64, new_row * 64);
//     }
//     return (0);
// }


	// player def	-> player[0]
	// player up 	-> player[1];
	// player down 	-> player[2];
	// player left 	-> player[3];
	// player right -> player[4];



// void load_player_images(t_game *game)
// {
//     int width, height;

//     // Correct allocation for storing image pointers
//     game->player = malloc(sizeof(void *) * 6); // Allocate space for 5 images and NULL pointer
//     if (!game->player)
//     {
//         printf("Allocation failed for player images\n");
//         cleanup_and_exit("Error: Memory allocation failed for player images\n", game, 1); // Exit on failure
//     }

//     game->player[0] = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/player/defult.xpm", &width, &height);
//     game->player[1] = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/player/up.xpm", &width, &height);
//     game->player[2] = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/player/down.xpm", &width, &height);
//     game->player[3] = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/player/left.xpm", &width, &height);
//     game->player[4] = mlx_xpm_file_to_image(game->mlx, "map_rendring/img_resource/player/right.xpm", &width, &height);
//     game->player[5] = NULL; // Ensure the array is NULL-terminated

//     // Check if any image failed to load
//     if (!game->player[0] || !game->player[1] || !game->player[2] || !game->player[3] || !game->player[4])
//     {
//         // If any image loading fails, free previously loaded images and exit
//         free_player_images(game); 
//         cleanup_and_exit("Error: Failed to load player images\n", game, 1);
//     }
// }

// // Function to free allocated player images
// void free_player_images(t_game *game)
// {
//     int i;

//     if (!game->player)
//         return;
    
//     for (i = 0; i < 5; i++)
//     {
//         if (game->player[i])
//             mlx_destroy_image(game->mlx, game->player[i]); // Free each image
//     }
//     free(game->player); // Free the array itself
// }
