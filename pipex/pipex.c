/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:35:20 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/03 17:34:05 by yanflous         ###   ########.fr       */
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

void	child_process(char **argv, int *fd, char **env)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
		error_msg("Error: failed \"open()\" to open a file descriptor\n", 2);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	cmd_executed(argv[2], env);
	close(fd[1]);
	close(in_file);
}

void	parent_process(char **argv, int *fd, char **env)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		error_msg("Error: failed \"open()\" to open a file descriptor\n", 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	cmd_executed(argv[3], env);
	close(fd[0]);
	close(out_file);
}

void	check_fork_pipe(char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		perror("Error: pipe() failed.");
	pid = fork();
	if (pid == -1)
		perror("Error: fork() failed.");
	if (pid == 0)
		child_process(argv, fd, env);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			parent_process(argv, fd, env);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	if (!env || !*env || check_path_exists(env) == 0)
		error_msg("command not found.\n", 2);
	if (argc == 5)
		check_fork_pipe(argv, env);
	else
	{
		error_msg("Error: Incorrect number of arguments.\n", STDERR_FILENO);
		error_msg("Syntax: ./pipex file1 cmd1 cmd2 file2.\n", STDOUT_FILENO);
	}
	return (0);
}
