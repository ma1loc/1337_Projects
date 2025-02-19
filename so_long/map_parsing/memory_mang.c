/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:15:45 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 11:42:19 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_so_long/so_long.h"

void	map_free(char **map)
{
	int	i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	image_cleanup(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->player[i])
			mlx_destroy_image(game->mlx, game->player[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (game->exit_door[i])
			mlx_destroy_image(game->mlx, game->exit_door[i]);
		i++;
	}
}

void	cleanup_and_exit(char *str, t_game *game, int std)
{
	if (game)
	{
		if (game->map)
			map_free(game->map);
		if (game->map_copy)
			map_free(game->map_copy);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->coin)
			mlx_destroy_image(game->mlx, game->coin);
		if (game->free_space)
			mlx_destroy_image(game->mlx, game->free_space);
		image_cleanup(game);
		mlx_destroy_display(game->mlx); // i have a segfult here
		free(game->mlx);
		free(game);
	}
	ft_putstr_fd(str, std);
}
