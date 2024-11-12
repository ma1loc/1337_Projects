#include "get_next_line.h"

#include <stdio.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	char 		*next_word;
	int			rd_count;
	int			i;

	// _check the fd is -1 or -down, and the buffer is <= 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// add it to function.
	// read syscall return number of bytes it read.
	rd_count = read(fd, buff, BUFFER_SIZE);
	if (rd_count < 0 || rd_count == 0)
		return (NULL);
	
	// loop on the r_count.
	int ln_count = 0;
	while (buff[ln_count] != '\n')
		ln_count++;
	// ^^^^^^^^^^^^^^^^^^^
	// test => printf("%d\n", ln_count);
	// allocation with malloc.
	next_word = malloc(sizeof(char) * (ln_count + 1));
	if (!next_word)
		return (NULL);
	// fill the memory allocation with malloc.
	while (i < ln_count)
	{
		next_word[i] = buff[i];
		i++;
	}

	// if the first line in the txt is nothing?
	// printf("strlen -> %d\n", ft_strlen(buff[BUFFER_SIZE]));
	// printf("the count -> %d\n", r_count);
	// end.
	// function to read from the file until it find  a \n or \0;

	/*
	ptr = malloc(sizeof(char) * nbyte);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, buff, nbyte);
	*/

	return (next_word);
}

// test //
#include <stdio.h>
int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	return (0);
}