/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:51:15 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 11:37:16 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	finding_player_position(t_game *game)
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
			{
				game->player_row = row;
				game->player_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	finding_player_exit(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'E')
			{
				game->exit_row = row;
				game->exit_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	is_reach_all_map(t_game *game)
{
	if (game->exit_count == 0)
		cleanup_and_exit("Error\
		\nPlayer can't reach the exit door.", game, 2, 0);
	else if (game->collected != game->collectibles)
		cleanup_and_exit("Error\
		\nPlayer can't reach all the collectibles in the MAP", game, 2, 0);
}

void	init_directions(int dir[4][2])
{
	dir[0][0] = -1;
	dir[0][1] = 0;
	dir[1][0] = 1;
	dir[1][1] = 0;
	dir[2][0] = 0;
	dir[2][1] = 1;
	dir[3][0] = 0;
	dir[3][1] = -1;
}

void	map_validation_path(t_game *game, int row, int col)
{
	int	i;
	int	dir[4][2];

	i = 0;
	init_directions(dir);
	if (row < 0 || col < 0 || row >= game->rows || col >= game->cols)
		return ;
	if (game->map_copy[row][col] == '1' || game->map_copy[row][col] == 'V')
		return ;
	else if (game->map_copy[row][col] == 'E')
	{
		game->map_copy[row][col] = 'V';
		game->exit_count++;
		return ;
	}
	else if (game->map_copy[row][col] == 'C')
		game->collected++;
	game->map_copy[row][col] = 'V';
	while (i < 4)
	{
		map_validation_path(game, row + dir[i][0], col + dir[i][1]);
		i++;
	}
}
