/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:35:20 by yanflous          #+#    #+#             */
/*   Updated: 2024/12/29 15:25:30 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex	infile "grep a1"

int main(int argc, char **argv)
{
	if (argc == 3)
		perror("argument error.");

	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (perror("pipe error"), 1);

	pid = fork();
	
	// open the infile to read from it.
	int ch_fd = open(argv[1], O_RDONLY);
	if (ch_fd < 0)
		perror("ch_fd error");

	if (pid > 0)  // _____________________________________parent pid (write(1))
	{
		close(fd[0]);
		wait();
		//what's next
		
		
		close(fd[1]);
	}
	else if (pid == 0) // _______________________________child pid (read(1))
	{
		close(fd[1]);


		close(fd[0]);
	}
}
