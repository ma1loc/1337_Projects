#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//	fork(); create a new process id
//	pipe(); one process writes, another reads.
//	dup(); dup the fd.
//	execve();
//	exit();
//	perror(); shows msg.
int main(int argc, char *argv[]) // enviroment
{
	// int fd[2] -> arry of two intergers, is used to store the fd for the pip
	
	fork();
	fork();
	fork();
	write(1,"hello", 5);
}
