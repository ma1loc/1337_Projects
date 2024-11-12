#include "get_next_line.h"

#include <stdio.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];	// _check why (static)?
	int			rd_count; // the return of the read syscall
	char 		*line; // get the next line
	int 		l_word; // count the len of the word

	// _check the fd is -1 or -down, and the buffer is <= 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// add it to function.
	// read syscall return number of bytes it read.
	rd_count = read(fd, buff, BUFFER_SIZE);
	if (rd_count <= 0)
		return (NULL);

	// loop on the r_count.
	// count the l_word in other way
	l_word = 0;
	while (buff[l_word] != '\n')
		l_word++;
	// ^^^^^^^^^^^^^^^^^^^
	// test => printf("%d\n", ln_count);
	// allocation with malloc.
	// i have to allocate the line and + 2
	line = malloc(sizeof(char) * (l_word + 2));
	if (!line)
		return (NULL);

	// fill the memory allocation with malloc.
	// can i use strncpy?
	ft_strncpy(line, buff, l_word + 1);

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

	return (line);
}

// test //
#include <stdio.h>
int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return (0);
}