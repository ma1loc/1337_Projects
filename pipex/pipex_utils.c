/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:37:58 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/02 13:21:32 by yanflous         ###   ########.fr       */
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

void	free_memory(char **split_path)
{
	int i;

	i = 0;
	while (split_path[i])
		free(split_path[i++]);
	free(split_path);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**split_path;
	char	*add_to_path;
	char	*new_path;
	
	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
		return (NULL);
	split_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (split_path[i])
	{
		add_to_path = ft_strjoin(split_path[i], "/");
		new_path = ft_strjoin(add_to_path, cmd);
		free(add_to_path);
		if (access(new_path, F_OK | X_OK) == 0)
		{
			free_memory(split_path);
			return (new_path);
		}
		free(new_path);
		i++;
	}
	free_memory(split_path);
	return (NULL);
}

void	cmd_executed(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error_msg("command not found.\n", STDERR_FILENO);
	}
	if (execve(path, cmd, env) == -1)
		error_msg("field to execute the command.\n", 1);
}
