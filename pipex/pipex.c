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
#include <fcntl.h>
#include <unistd.h>
/*
	divide them to a functions.
	function in the utils shows error ext(exit_failure); 
	function -> fork && pipe.
	function -> child.
	function -> parent.
*/
void	child_process(char **argv, char **envp, int *fd)
{
	int	in_file;

	in_file = open(argv[1], O_RDONLY);
	if (in_file == -1)
		perror("hollla");//replace write a function shows an error
	dup2(fd[1], STDOUT_FILENO);
	dup2(in_file, STDIN_FILENO);
	close(fd[0]);
	// here i will be execute the command.
	char *cmd1[] = {"grep", "a1", NULL};
	execve("/usr/bin/grep", cmd1, NULL);
	perror("Execve error");
}

void	parent_process(char **argv, char **env, int *fd)
{
	int out_file;

	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_file == -1)
		perror("hoola");
	dup2(fd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(fd[1]);
	// here to execve
	char *cmd2[] = {"grep", "a1", NULL};
	execve("/usr/bin/grep", cmd1, NULL)
	perror("Execve error");

}
		if (pid == 0) // child
		{
			dup2(in_file, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(fd[0]);
			close(in_file);	
			char *cmd1[] = {"grep", "a1", NULL};
			execve("/usr/bin/grep", cmd1, NULL);
		    perror("Execve error");
		}
		else // parent
		{
			wait(NULL);
			dup2(fd[0], STDIN_FILENO);
			dup2(out_file, STDOUT_FILENO);
			close(fd[0]);
			close (fd[1]);
			close (out_file);
			char *cmd2[] = {"wc", "-w", NULL};
			execve("/usr/bin/wc", cmd2, NULL);
			perror("Execve error");

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
