# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // delete this.
#include <unistd.h>
#include <stdlib.h>

int     main(int argc, char **argv);

// libft
long	ft_atoi(char *str);
size_t  ft_strlen(char *str);
char    **ft_split(char *str, char separator);
void    ft_putstr_fd(char *str);

// push_swap
void    is_valid_num(char **argv);

# endif
