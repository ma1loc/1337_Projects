/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:01:33 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 13:01:35 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	init_and_window(t_game *game)
{
	int	height;
	int	width;

	game->mlx = mlx_init();
	if (!game->mlx)
		cleanup_and_exit("Error\nInitialization of the mlx failedn\n", \
		game, 2, 0);
	width = game->cols * 64;
	height = game->rows * 64;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		cleanup_and_exit("Error\nWindow failed to open.\n", game, 2, 0);
}

void	load_img_to_win(t_game *game)
{
	load_player_images(game);
	load_space_and_wall_images(game);
	load_coin_images(game);
	load_doors_images(game);
	init_the_map(game);
}

void	process_the_map_rendering(t_game *game)
{
	game->collected = 0;
	init_and_window(game);
	load_img_to_win(game);
	mlx_key_hook(game->win, press_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
