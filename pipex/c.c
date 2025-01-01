#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv, char **env)
{
	int pid = fork();
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		printf("this is a child\n");
	else
		printf("this is a parent\n");
}
