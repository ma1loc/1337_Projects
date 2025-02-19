/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:38 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 10:57:42 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	is_there_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 4 || ft_strncmp(&map[len - 4], ".ber", 4) != 0
		|| (ft_strncmp(map, ".ber", 4) == 0))
		ft_putstr_fd("Error\nThe extenstion not valid.\
		\nUsage => \"./so_long *.ber\".", 2);
}

void	is_map_valid(t_game *game)
{
	size_t	len_line;
	char	*line;
	int		i;

	i = 0;
	if (game->map[i])
		len_line = ft_strlen(game->map[i]);
	else
		cleanup_and_exit("Error\nMap is empty.", game, 2);
	while (game->map[i])
	{
		if (game->map[i][0] == '\n' && game->map[i][1] == '\0')
			cleanup_and_exit("Error\nProvided map has empty line.", game, 2);
		line = game->map[i];
		if (line[len_line - 1] != '\n')
			len_line--;
		if (ft_strlen(line) != len_line)
			cleanup_and_exit("Error\nMap is not \"Rectangular\".", game, 2);
		i++;
	}
}

t_game	*map_processing(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_putstr_fd("Error\nAllocation faild.", 2);
	game->map = read_map(map);
	if (!game->map)
		cleanup_and_exit("Error\nParsing Faild!!!", game, 2);
	game->exit_count = 0;
	game->collected = 0;
	is_map_valid(game);
	count_duplicate_char_in_the_map(game); // here the seg
	check_is_valid_dup_char(game);
	wall_check(game);
	game->rows = count_lines(map);
	game->cols = count_cols(game->map);
	finding_player_position(game);
	finding_player_exit(game);
	game->map_copy = read_map(map);
	return (game);
}

t_game	*pars_the_map(char *map)
{
	t_game	*game;

	is_there_extension(map);
	game = map_processing(map);
	map_validation_path(game, game->player_row, game->player_col);
	is_reach_all_map(game);
	return (game);
}
