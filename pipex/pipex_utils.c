/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:37:58 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/01 16:39:38 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str, int stdio)
{
	size_t	len;

	len = ft_strlen(str);
	write(stdio, str, len);
	exit(EXIT_FAILURE);
}

char	**get_path(char *cmd, char **env)
{
	int		i;
	char	**split_path;
	char	*add_to_path;
	char	*new_path;
	
	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	split_path = ft_split(env[i] + 5, ';');
	i = 0;
	while (split_path[i])
	{
		add_to_path = ft_strjoin(split_path[i], "/");
		new_path = ft_strjoin(add_to_path, cmd);
		free(add_to_path);
		/*
			the access syscall is a way to check if the path is exist and executable
			it will return 0 on successfully, -1 on unsuccessfully.
		*/
		if (access(new_path, F_OK | X_OK) == 0)
			return (new_path);
		free(new_path);
		i++;
	}
	i = 0;
	while (split_path[i])
		free(split_path[i++]);
	free(split_path);

	/*
		while (paths[++i])
			free(split_path[i]);
		free(split_path);
		return (0);
		return (NULL);
	*/
	return (split_path);
}

void	cmd_executed(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int	i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		// error massage.
	}
	if (execve(path, cmd, env) == -1)
		// error massage.

}
