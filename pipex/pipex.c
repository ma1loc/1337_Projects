/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:35:20 by yanflous          #+#    #+#             */
/*   Updated: 2024/12/30 18:43:46 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *fd, char **env)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
		perror("hollla");//replace write a function shows an error
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	// here i will be execute the command.
	cmd_executed(argv[2], env);
}

void	parent_process(char **argv, int *fd, char **env)
{
	int out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		perror("hoola");
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	// here to execve
	cmd_executed(argv[3], env);

}

int	main(int argc, char **argv, char **env)
{
	int	fd[2]; // an arrary of two intergers.
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process();

	}
	else
		ft_putstr_fd("Error: Incorrect number of arguments.\n", 1);
	

	return (0);
}
