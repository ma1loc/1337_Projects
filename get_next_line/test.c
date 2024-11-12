#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0, buffer_size = 0;
    char *line = NULL;
    int line_len = 0;

    // Check for a valid file descriptor and buffer size
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    // Allocate initial memory for the line
    line = malloc(BUFFER_SIZE);
    if (!line)
        return NULL;j 

    // Read until a newline or EOF
    while (1) {
        // If buffer is empty or all characters have been processed, read new data
        if (buffer_pos >= buffer_size) {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;

            // If nothing was read, end of file or error
            if (buffer_size <= 0) {
                free(line);
                return NULL;
            }
        }

        // Append characters to line until newline or buffer is exhausted
        line[line_len++] = buffer[buffer_pos++];

        // Resize line if necessary (handling cases where the line exceeds initial size)
        if (line_len >= BUFFER_SIZE) {
            char *temp = realloc(line, line_len + BUFFER_SIZE);
            if (!temp) {
                free(line);
                return NULL;
            }
            line = temp;
        }

        // Stop if newline is found
        if (line[line_len - 1] == '\n')
            break;
    }

    // Null-terminate the line
    line[line_len] = '\0';

    return line;
}
