/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:47:21 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/06 10:26:25 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	open_input_file(int *in_fd, char *input_file)
{
	*in_fd = open(input_file, O_RDONLY);
	if (*in_fd == -1)
	{
		ft_putstr_fd("Error: failed to open input file.\n");
		exit(1);
	}
}

void	open_output_file(int *out_fd, char *output_file)
{
	*out_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*out_fd == -1)
	{
		ft_putstr_fd("Error: failed to open output file.\n");
		exit(1);
	}
}

void	execute_child(int in_fd, int *fd, char *cmd, char **env, int is_last, char *output_file)
{
	if (in_fd != STDIN_FILENO)
		dup2(in_fd, STDIN_FILENO);
	if (!is_last)
		dup2(fd[1], STDOUT_FILENO);
	else
	{
		int out_fd;
		open_output_file(&out_fd, output_file);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	close(fd[0]);
	close(fd[1]);
	cmd_executed(cmd, env);
	exit(1);
}

void	spawn_process(int *in_fd, int *fd, char *cmd, char **env, int is_last, char *output_file)
{
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Error: pipe() failed.\n");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error: fork() failed.\n");
		exit(1);
	}
	if (pid == 0)
		execute_child(*in_fd, fd, cmd, env, is_last, output_file);
	close(fd[1]);
	if (*in_fd != STDIN_FILENO)
		close(*in_fd);
	*in_fd = fd[0];
}

void	check_fork_pipe(char **argv, int argc, char **env)
{
	int	in_fd;
	int	fd[2];
	int	status;
	int	i;

	open_input_file(&in_fd, argv[1]);
	for (i = 2; i < argc - 1; i++)
		spawn_process(&in_fd, fd, argv[i], env, i == argc - 2, argv[argc - 1]);
	while (wait(&status) > 0)
		;
}

int	main(int argc, char **argv, char **env)
{
	if (!env || !*env || check_path_exists(env) == 0)
	{
		ft_putstr_fd("Error: PATH not found.\n");
		exit(1);
	}
	if (argc >= 5)
		check_fork_pipe(argv, argc, env);
	else
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\n"
			"Syntax $> ./pipex file1 cmd1 cmd2 ... cmdN file2.\n");
	}
	return (0);
}
