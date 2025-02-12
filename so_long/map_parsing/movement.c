#include "../src_so_long/so_long.h"

// up, down, left, right
// valid think so! (is checkd)
void	up(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		if (copy_of_map[position->row - 1][position->col] == '1')
			return ;
		position->row--;
	}
}

// not valid have some thing on it! -> check it?
void	down(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		position->row++;
	}
}
void	left(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (position->col != 0)
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		else if (copy_of_map[position->row][position->col + 1] == '1')
			return ;
		position->col--;
	}
}


void	right(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		if (copy_of_map[position->row][position->col + 1] == '1')
			return ;
		position->col++;
	}
}