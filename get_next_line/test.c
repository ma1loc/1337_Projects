#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

// Helper function to join strings and handle memory
char *ft_strjoin_free(char *s1, char *s2)
{
    char *result;
    size_t len1;
    size_t len2;

    if (!s1)
        return (ft_strdup(s2));
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return (NULL);
    ft_strncpy(result, s1, len1);
    ft_strncpy(result + len1, s2, len2);
    result[len1 + len2] = '\0';
    free(s1);
    return (result);
}

// Helper function to extract line from buffer
char *extract_line(char **left_c)
{
    char *line;
    char *temp;
    char *newline_pos;

    if (!*left_c)
        return (NULL);
    newline_pos = ft_strchr(*left_c, '\n');
    if (newline_pos)
    {
        // Found newline - split the string
        line = ft_substr(*left_c, 0, newline_pos - *left_c + 1);
        temp = ft_strdup(newline_pos + 1);
        free(*left_c);
        *left_c = temp;
        if (**left_c == '\0')
        {
            free(*left_c);
            *left_c = NULL;
        }
    }
    else
    {
        // No newline - return entire string
        line = *left_c;
        *left_c = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *left_c;
    char *buffer;
    char *line;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    // Read from file until newline is found or EOF
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    
    while (!ft_strchr(left_c, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        left_c = ft_strjoin_free(left_c, buffer);
    }
    free(buffer);
    
    // Extract line from left_c
    line = extract_line(&left_c);
    return (line);
}