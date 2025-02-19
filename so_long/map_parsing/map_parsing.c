/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:02:19 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 11:11:42 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	check_is_valid_dup_char(t_game *game)
{
	if (game->player_count == 0)
		cleanup_and_exit("Error\nThere's no \"PLAYER_POSITOIN\"\
		in provided MAP.", game, 1);
	if (game->exit_count == 0)
		cleanup_and_exit("Error\nThere's no \"EXIT_DOOR\"\
		in provided MAP.", game, 1);
	if (game->player_count > 1)
		cleanup_and_exit("Error\nThere's a \"DUP_POSITOIN\"\
		in provided MAP", game, 1);
	if (game->exit_count > 1)
		cleanup_and_exit("Error\nThere's a \"DUP_EXIT DOORS\"\
		in provided MAP", game, 1);
	if (game->collectibles == 0)
		cleanup_and_exit("Error\nThere's no \"COLLECTIBLES\"\
		in provided MAP", game, 1);
}

void	count_duplicate_char_in_the_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j] != '\n')
				cleanup_and_exit("Error\nWrong char in the MAP.", game, 2); // here seg
			else if (game->map[i][j] == 'P')
				game->player_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

int	count_cols(char **map)
{
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	len--;
	return (len);
}

void	last_row(t_game *game)
{
	char	*_last_row;
	int		i;

	i = 0;
	while (game->map[i])
		i++;
	i--;
	_last_row = game->map[i];
	i = 0;
	while (_last_row[i])
	{
		if (_last_row[i] != '1')
			cleanup_and_exit("Error\n\"Bottom Walls\"\
			not set as it expected.", game, 2);
		i++;
	}
}

void	wall_check(t_game *game)
{
	int		i;
	size_t	len_of_line;

	i = 0;
	while (game->map[0][i] && game->map[0][i] != '\n')
	{
		if (game->map[0][i] != '1')
			cleanup_and_exit("Error\n\"Top Walls\"\
			not set as it expected.", game, 2);
		i++;
	}
	i = 0;
	len_of_line = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (game->map[i][len_of_line - 1] == '\n')
			len_of_line -= 1;
		if (game->map[i][0] != '1' || game->map[i][len_of_line - 1] != '1')
			cleanup_and_exit("Error\n\"Left or Right Walls\"\
			not set as it expected.", game, 2);
		i++;
	}
	last_row(game);
}
