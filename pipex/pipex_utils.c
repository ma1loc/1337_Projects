/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:37:58 by yanflous          #+#    #+#             */
/*   Updated: 2024/12/30 18:38:00 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pipex.h"

// get_command_path;
// access.
// syntax -> int access(const char *pathname, int mode);
// have mode;
// F_OK | W_OK | R_OK | X_OK -> i need F_OK | X_OK

char	**get_command_path(char *command)
{
	char	*path;
	char	**split_path;
	
	path = "/home/yanflous/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	split_path = ft_split(path, ':');

	return (split_path);
}
