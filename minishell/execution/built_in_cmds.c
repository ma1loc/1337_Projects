// Your shell must implement the following builtins:
// ◦ cd with only a relative or absolute path
// ◦ pwd with no options
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options

#include "../mini_shell/mini_shell.h"

// ◦ echo with option -n
void    echo_msg(char *args)
{
    write(1, args, ft_strlen(args));
}