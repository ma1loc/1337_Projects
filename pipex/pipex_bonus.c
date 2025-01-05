/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:57:37 by yanflous          #+#    #+#             */
/*   Updated: 2025/01/05 16:13:29 by yanflous         ###   ########.fr       */
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

void    child_process(char **argv, int cmd_index, int cmd_count, int pipes[][2], char **env)
{
    if (cmd_index == 0)  // First command
    {
        int in_file = open(argv[1], O_RDONLY);
        if (in_file == -1)
            ft_putstr_fd("Error: failed to open input file\n");
        dup2(in_file, STDIN_FILENO);
        dup2(pipes[0][1], STDOUT_FILENO);
        close(in_file);
    }
    else if (cmd_index == cmd_count - 1)  // Last command
    {
        int out_file = open(argv[cmd_count + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (out_file == -1)
            ft_putstr_fd("Error: failed to open output file\n");
        dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
        dup2(out_file, STDOUT_FILENO);
        close(out_file);
    }
    else  // Middle commands
    {
        dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
        dup2(pipes[cmd_index][1], STDOUT_FILENO);
    }

    // Close all pipe fds in child
    for (int i = 0; i < cmd_count - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    cmd_executed(argv[cmd_index + 2], env);
    exit(1);
}

void    check_fork_pipe(char **argv, int cmd_count, char **env)
{
    int     pipes[cmd_count - 1][2];
    pid_t   pids[cmd_count];
    int     status;
    for (int i = 0; i < cmd_count - 1; i++)
    {
        if (pipe(pipes[i]) == -1)
            ft_putstr_fd("Error: pipe() failed.");
    }
    for (int i = 0; i < cmd_count; i++)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            ft_putstr_fd("Error: fork() failed.");
        if (pids[i] == 0)
            child_process(argv, i, cmd_count, pipes, env);
    }
    for (int i = 0; i < cmd_count - 1; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
    for (int i = 0; i < cmd_count; i++)
    {
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            exit(WEXITSTATUS(status));
    }
}

int	main(int argc, char **argv, char **env)
{
	int	cmd_count;

	if (!env || !*env || check_path_exists(env) == 0)
		ft_putstr_fd("command not found.\n");
	cmd_count = argc - 3;
	if (argc >= 5)
		check_fork_pipe(argv, cmd_count, env);
	else
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\n"
		"Syntax $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n"
		"Syntax $> ./pipex here_doc LIMITER cmd1 cmd2 ... file\n");
	}
	return (0);
}
