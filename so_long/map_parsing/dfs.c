#include "../src_so_long/so_long.h"

// here the algo of the flood fill algorithm
// Breadth First Search (BFS)

// find the {row & col}
int	*finding_player_position(char **map)
{
	int	i;
	int j;
	int	*row_and_col;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				// have i do the structure here instde
				row_and_col = allocate_for_row_and_col(i, j, map);
				if (row_and_col == NULL)
        			cleanup_and_exit("Error\nAllocation faild.", map);
				return (row_and_col);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
