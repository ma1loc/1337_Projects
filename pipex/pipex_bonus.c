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

void    check_fork_pipe(char **argv, int cmd_count, char **env)
{
    int     pip    
}

int	main(int argc, char **argv, char **env)
{
	int	cmd_count;

	if (!env || !*env || check_path_exists(env) == 0)
		ft_putstr_fd("command not found.\n");
	cmd_count = argc - 3;
	
        if (argc >= 5)
        {
            if () // check if the argv[1] is it here_doc using strncmp
            {
                /*
                    here mean's you need the here_doc, it means there is no input file
                    becuase the here_doc repalce the infile
                    put you steel need the output file the reach the output file at the end
                    of the argv just use the "argv[argc - 1]"
                    then call the here_doc function you create.
                */
            }
            else
            {
                // here you have to create both input and output file.
                check_fork_pipe(argv, cmd_count, env);
            }
        }
        else
	{
		ft_putstr_fd("Error: Incorrect number of arguments.\n"
		"Syntax $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n"
		"Syntax $> ./pipex here_doc LIMITER cmd1 cmd2 ... file\n");
	}
	return (0);
}
