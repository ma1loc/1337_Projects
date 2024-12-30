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

// divide them to a functions.
// function -> fork && pipe.
// function -> child.
// function -> parent.
int main(int argc, char **argv)
{
	int		in_file;
	int		out_file;
	int		fd[2];
	pid_t	pid;
	
	if (argc == 5)
	{
		in_file = open(argv[1], O_RDONLY);
		if (in_file < 0)
			ft_putstr_fd("Error: failed to opening the file.", 1);
	
		out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_file < 0)
			ft_putstr_fd("Error: failed to opening the file.", 1);

		if (pipe(fd) == -1)
			ft_putstr_fd("Error: pipe failed", 1);
	
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("Error: frok failed", 1);

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
		}
	}
	else
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\nvalid arguments ./pipex file1 cmd1 cmd2 file2", 1);
	}
	return (0);	
}
