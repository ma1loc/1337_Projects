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
		\nPlayer can't reach the exit door.", game);
	else if (game->collected != game->collectibles)
		cleanup_and_exit("Error\
		\nPlayer can't reach all the collectibles in the MAP", game);
}

void	map_validation_path(t_game *game, int row, int col)
{
	int	i;
	int	dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

	i = 0;
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
