/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:37:58 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/09 11:23:44 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path_exists(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	free_memory(char **mem_free)
{
	int	i;

	i = 0;
	while (mem_free[i])
		free(mem_free[i++]);
	free(mem_free);
}

char	*split_path(char *path, char *cmd)
{
	int		i;
	char	**split_path;
	char	*add_to_path;
	char	*new_path;

	split_path = ft_split(path + 5, ':');
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		add_to_path = ft_strjoin(split_path[i], "/");
		new_path = ft_strjoin(add_to_path, cmd);
		free(add_to_path);
		if (access(new_path, F_OK | X_OK) == 0)
			return (free_memory(split_path), new_path);
		free(new_path);
		i++;
	}
	return (free_memory(split_path), NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*path;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
		return (NULL);
	path = split_path(env[i], cmd);
	return (path);
}

void	cmd_executed(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		free_memory(cmd);
		ft_putstr_fd("Error: command parsing failed.\n", 1);
	}
	path = get_path(cmd[0], env);
	if (!path)
	{
		free_memory(cmd);
		ft_putstr_fd("command not found.\n", 127);
	}
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		free_memory(cmd);
		ft_putstr_fd("Failed to execute the command.\n", 1);
	}
}
