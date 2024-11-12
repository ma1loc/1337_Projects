#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
# endif //-> check
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strlcpy(char *dst, char *src, int nbyte);

# endif
