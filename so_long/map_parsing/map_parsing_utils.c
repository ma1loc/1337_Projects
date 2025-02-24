/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:13:14 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 11:15:16 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	is_valid_screen_size(t_game *game)
{
	int	screen_hight;
	int	screen_wight;

	screen_hight = 3840;
	screen_wight = 2160;
	if (screen_hight <= (game->cols * 64)
		|| screen_wight <= (game->rows * 64))
		cleanup_and_exit("Error\nThe Map provided is bigger" \
			"then screen size \"3840x2160\"\n", game, 2, 0);
}

void	game_init(t_game *game)
{
	int	i;

	game->player_count = 0;
	game->moves = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	game->collected = 0;
	game->map = NULL;
	game->map_copy = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->coin = NULL;
	game->free_space = NULL;
	game->mlx = NULL;
	i = 0;
	while (i < 6)
		game->player[i++] = NULL;
	i = 0;
	while (i < 3)
		game->exit_door[i++] = NULL;
}

int	count_lines(char *map, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_perror("Error\nOpen\n", game);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(char *map, t_game *game)
{
	char	*line;
	char	**split_map;
	int		i;
	int		fd;

	if (!map)
		return (NULL);
	split_map = malloc(sizeof(char *) * (count_lines(map, game) + 1));
	if (!split_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (free(split_map), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		split_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	split_map[i] = NULL;
	close(fd);
	return (close(fd), split_map[i] = NULL, split_map);
}
