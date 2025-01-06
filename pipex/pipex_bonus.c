#include "pipex.h"

void	Syntax_Error()
{
	ft_putstr_fd("Syntax Error: ")
}

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_putstr_fd("Error: pipe failed.");
	pid = fork();
	if (pid == -1)
		ft_putstr_fd("Error: pipe failed.");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	in_file;
	int	out_file;
	int	cmd_count;
	
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			cmd_count = 3;
			in_file = open(argv[argc], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			here_doc(argv[2], argc);
		}
		else
		{
			cmd_count = 2;
			in_file = open(argv[argc], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			out_file = open(argv[1], O_RDONLY);
			dup2(in_file, STDIN_FILENO);
		}
		while (cmd_count < argc - 2)
			child_process(argv[cmd_count++], env);
		dup2(out_file, STDOUT_FILENO);
		execute(argv[argc - 2], env);
	}
	
}
