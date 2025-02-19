/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:30 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 13:06:20 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

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
				mlx_put_image_to_window(game->mlx, game->win, \
				game->player[0], col * 64, row * 64);
			else if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->wall, col * 64, row * 64);
			else if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->free_space, col * 64, row * 64);
			else if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->coin, col * 64, row * 64);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->exit_door[0], col * 64, row * 64);
			col++;
		}
		row++;
	}
}

int	confirmed_press_key(t_game *game, t_direction move)
{
	if (game->map[move.new_row][move.new_col] == '1')
		return (1);
	if (game->map[move.new_row][move.new_col] == 'E')
	{
		if (game->collected == game->collectibles)
			cleanup_and_exit("You WIN.\n", game, 1);
		return (1);
	}
	if (game->map[move.new_row][move.new_col] == 'C')
	{
		game->collected += 1;
		if (game->collected == game->collectibles)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->exit_door[1], \
				game->exit_col * 64, game->exit_row * 64);
	}
	return (0);
}
