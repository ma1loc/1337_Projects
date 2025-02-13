#include "../src_so_long/so_long.h"

// here the algo of the flood fill algorithm
// Breadth First Search (BFS)

// find the {row & col}
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
				game->player_y = row;
				game->player_x = col;
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
				game->exit_y = row;
				game->exit_x = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
// flood fill algo 
// (y + 1)
// (y - 1)
// (x + 1)
// (x - 1)
// valid the path of the player !!!
void	map_validation_path()
{
}