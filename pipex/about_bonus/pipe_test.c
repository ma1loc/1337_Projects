#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd[2]; // array of two integers
	char *str;

	if (pipe(fd) == -1) // create a pipe between two fd
		perror("pipe");
	
	write(fd[1], "ma1loc", 6); // write to the fd[1] write only

	str = malloc(sizeof(char) * 6);
	if (!str)
		return (1);

	int readed = read(fd[0], str, 6); // read from the fd[0], read only
	if (readed < 0)
		printf("readed is < 0");

	printf("%s", str); // print what you read fron the fd[0]

	free(str);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
