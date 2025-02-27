# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define HELLO "hello"

size_t  ft_strlen(const char *str);
int     delim_count(char *str, char separator);
void    echo_msg(char *args);
