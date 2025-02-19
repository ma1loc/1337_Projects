/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:36:40 by yanflous          #+#    #+#             */
/*   Updated: 2025/02/19 10:36:43 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2)
		ft_putstr_fd("Error\nA few args, put the map to play\n", 2);
	if (argc == 2)
	{
		game = pars_the_map(argv[1]);
		process_the_map_rendering(game);
	}
	else
		ft_putstr_fd("Error\nToo many arguments.\
		\nUsage => \"./so_long map.ber\"", 2);
	cleanup_and_exit(NULL, game, 1);
}
