/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:35:20 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/02 10:53:28 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *fd, char **env)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
		error_msg("Error: failed \"open()\" to open a file descriptor\n", STDERR_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	cmd_executed(argv[2], env);
}

void	parent_process(char **argv, int *fd, char **env)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		error_msg("Error: failed \"open()\" to open a file descriptor\n", STDERR_FILENO);
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	cmd_executed(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	
	if (!env || !*env)
	{
		error_msg("rah makaynch en a zabi\n", 2);
		exit(1);
	}

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("Error: pipe() failed.");
		pid = fork();
		if (pid == -1)
			perror("Error: fork() failed.");
		if (pid == 0)
			child_process(argv, fd, env);
		else
		{
			waitpid(pid, NULL, 0); // the , , 0->default, blocks until the child terminates.
			parent_process(argv, fd, env);
		}
	}
	else
	{
		error_msg("Error: Incorrect number of arguments.\n", STDERR_FILENO);
		error_msg("Syntax: ./pipex file1 cmd1 cmd2 file2.\n", STDOUT_FILENO);
	}
	return (0);
}
