#include "pipex.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int	in_file;
	int	out_file;
	int	fd[2];
	pid_t	pid;
	// ./pipex infile "grep a1" "wc -l" outfile
	//     0     1        2        3       4
	if (argc != 5)
		perror("arguments error.");
	// first thing open the infile to read
	// and the outfile to wreate to it.
	in_file = open(argv[1], O_RDONLY); // input_file
	if (in_file < 0)
		perror("error opening file");
	out_file = open(argv[4], O_WRONLY | O_CREAT, 0644); // what is O_TRUNC for?
	if (out_file < 0)
		perror("error opening file");
	// create a pipe between two fd, fd[0] for read, fd[1] for write.
	if (pipe(fd) == -1)
		perror("pipe error");
	// after the pipe we have to fork the process, mean's create a child process
	// that have same copy of the parent memory.
	pid = fork(); // is the fork take no parameter?
	if (pid == -1) // why we use (pid == -1) not (pid < 0) like the fd check?
		perror("fork error");
	// if the pid == 0 mean's ur runing the program using the child pid.
	if (pid == 0) // in the child process
	{
		close(fd[1]); // close unused fd, child just reading.
		/*
			why i redirect the infile and outfile and i have a pipe
			that give me two file descroptors linked to each other?
			i know the quastion is dump but i don't have any idea why
			i have to do that?
		*/
		//dup2()  is the dup2 returns any thing to check if it sucess of not?
		// what is the STDIN_FILENO and STDOUT_FILENO is it the only why in pipex?
	        dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(infile);
		// and the execve i don't have any idea about it and how it works
		char *cmd[] = {"grep", "a1", NULL};
		execve("/usr/bin/grep", cmd, NULL);
		perror("Execve error");
		exit(1);
	}

}
