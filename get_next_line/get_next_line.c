#include "get_next_line.h"

#include <stdio.h>

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	int		rd_count;
	char	*line;
	char	*n_line;

//	rd_count = read(fd, buffer, BUFFER_SIZE);
	if (rd_count <= 0)
		return (NULL);

	line = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	ft_strncpy(line, buffer, BUFFER_SIZE);

	// check for new_line in the buffer.
	if (!ft_strchr(buffer, '\n'))
		left_c = ft_strchr(buffer, '\n');

	return (left_c);
}

// main function.
char *get_next_line(int fd)
{
	// why is it static or not ???.
	static char	*left_c; // check ? i think that's way i use strchr ???.
	char 		*buffer; // i will use it to store data
	char 		*line;
 	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// fouces on this part.
	// hande the leftover content.
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // why +2 or +1 ???
	if (!buffer)
		return (NULL);
	// while loop;
	// read; the read_bytes and check in the while if the read_bytes has a '\n' charcter.
	// check if the read_bytes is <= 0.
	// how do i check the buffer, without nothing on it ???
	// in the condition -> (left_c) or (buffer) ???.
	while (!ft_strchr(buffer, '\n')) // check if the buffer has any '\n' charc.
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE); 
		//printf("(read_bytes) the read_bytes that read -> %d\n", read_bytes);
		//printf("(buffer) this is the buffer current char -> %s\n", buffer);
		if (read_bytes <= 0)
			break ;
		left_c = ft_strjoin(left_c, buffer);
		//printf("(left_c) the left_c (%s)\n", left_c);
	}
	// i think i have to free the buffer here.  = h
	free(buffer);
	
	return (left_c);
}

// main test
#include <stdio.h>
int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);

	printf("the return of GNL -> %s", get_next_line(fd));
	printf("the return of GNL -> %s", get_next_line(fd));
	printf("the return of GNL -> %s", get_next_line(fd));

	return (0);
}