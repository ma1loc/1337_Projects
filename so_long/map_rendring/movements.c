/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:50:55 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 11:50:59 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	do_press_key(t_game *game, t_direction move, int keycode)
{
	if (confirmed_press_key(game, move) == 1)
		return ;
	game->map[game->player_row][game->player_col] = '0';
	mlx_put_image_to_window(game->mlx, game->win, game->free_space, \
		game->player_col * 64, game->player_row * 64);
	game->player_col = move.new_col;
	game->player_row = move.new_row;
	if (keycode == UP_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[1], \
			game->player_col * 64, game->player_row * 64);
	else if (keycode == DOWN_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[2], \
			game->player_col * 64, game->player_row * 64);
	else if (keycode == LEFT_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[3], \
			game->player_col * 64, game->player_row * 64);
	else if (keycode == RIGHT_KEY)
		mlx_put_image_to_window(game->mlx, game->win, game->player[4], \
			game->player_col * 64, game->player_row * 64);
	game->moves += 1;
	printf("Player Moves -> %d\n", game->moves); // not done (printf)
}

int	press_key(int keycode, t_game *game)
{
	t_direction	move;

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
		cleanup_and_exit("EXIT THE GAME.\n", game, 1);
	else
		return (0);
	do_press_key(game, move, keycode);
	return (0);
}
