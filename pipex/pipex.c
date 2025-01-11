/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:35:20 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/11 09:26:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, int *fd, char **env)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
		ft_putstr_fd("Error: failed \"open()\" to open input file.\n", 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(in_file);
	cmd_executed(argv[2], env);
	exit(1);
}

void	child2_process(char **argv, int *fd, char **env)
{
	int	out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		ft_putstr_fd("Error: failed \"open()\" to open output file.\n", 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(out_file);
	cmd_executed(argv[3], env);
	exit(1);
}

void	check_fork_pipe(char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(fd) == -1)
		ft_putstr_fd("Error: pipe() failed.", 1);
	pid1 = fork();
	if (pid1 == -1)
		ft_putstr_fd("Error: fork() failed.", 1);
	if (pid1 == 0)
		child1_process(argv, fd, env);
	pid2 = fork();
	if (pid2 == 0)
		child2_process(argv, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		check_fork_pipe(argv, env);
	else
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\n"
			"Syntax $> ./pipex file1 cmd1 cmd2 file2.\n", 1);
	}
	return (0);
}
