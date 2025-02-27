// Your shell must implement the following builtins:
// ◦ pwd with no options
// ◦ export with no options
// ◦ unset with no options
// ◦ env with no options or arguments
// ◦ exit with no options

#include "../mini_shell/mini_shell.h"

// ◦ echo with option -n
void    echo_msg(char *args, char *opt)
{
    char    str;

    str = NULL;
    // echo && echo -n !!!
    if (!opt)
    {
        if (ft_strncmp(args, "-n", ft_strlen(args)) == 0)
        {
            str = ft_strjoin(args, "\n");
            write(1, str, ft_strlen(str));
        }
        else
            write(2, );
    }
    else
        write(1, args, ft_strlen(args));
}

// ◦ cd with only a relative or absolute path

