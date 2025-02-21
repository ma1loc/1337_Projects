/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:38 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/20 13:24:41 by yanflous         ###   ########.fr       */
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
		\nUsage => \"./so_long *.ber\".\n", 2);
}

void	edges_loop(t_game *game, size_t _line_len)
{
	size_t	line_len;
	char	*line;
	int		i;

	i = 0;
	while (game->map[i])
	{
		line = game->map[i];
		if (line[0] == '\n' && line[1] == '\0')
			cleanup_and_exit("Error\n" \
			"Provided map has empty line.\n", game, 2, 0);
		line_len = ft_strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line_len--;
		if (line_len != _line_len)
			cleanup_and_exit("Error\n" \
			"Map is not \"Rectangular\".\n", game, 2, 0);
		i++;
	}
}

void	is_map_valid(t_game *game)
{
	size_t	line_len;
	int		i;

	i = 0;
	line_len = ft_strlen(game->map[i]);
	if (game->map[i])
	{
		if (game->map[i][line_len - 1] == '\n')
			line_len--;
	}
	else
		cleanup_and_exit("Error\nMap is empty.\n", game, 2, 0);
	edges_loop(game, line_len);
}

t_game	*map_processing(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_putstr_fd("Error\nAllocation faild.\n", 2);
	game_init(game);
	game->map = read_map(map, game);
	if (!game->map)
		cleanup_and_exit("Error\nParsing Faild!!!\n", game, 2, 0);
	is_map_valid(game);
	count_duplicate_char_in_the_map(game);
	check_is_valid_dup_char(game);
	wall_check(game);
	game->rows = count_lines(map, game);
	game->cols = count_cols(game->map);
	finding_player_position(game);
	finding_player_exit(game);
	game->map_copy = read_map(map, game);
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
