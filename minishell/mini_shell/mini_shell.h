# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define HELLO "hello"

size_t  ft_strlen(const char *str);
int     delim_count(char *str, char separator);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);


void    echo_msg(char *args, char *opt);