#include "../src_so_long/so_long.h"

void     is_have_dot(char *str)
{
    int i;
    int dot;

    i = 0;
    dot = 0;
    while (str[i])
    {
        if (dot == 0 && str[i + 1] == '\n')
            ft_putstr_fd("Error\nThere's no extension in the file you provide.\
            \nUsage => \"./so_long map.ber\"");
        i++;
    }
}

void    is_there_anything_before_dot(char *map)
{
    if (map[0] == '.')
        ft_putstr_fd("Error\nPut a name of the file befor the extention.\
        \nUsage => \"./so_long map.ber\"");
}

int     is_there_extension(char *map)
{
    int     i;
    int     j;
    char    *extension;

    i = 0;
    extension = ".ber";
    
    while (map[i])
    {
        if (map[i] == '.')
        {
            j = 0;
            while (map[i] == extension[j])
            {
                if (map[i] == 'r' && map[i + 1] == '\0')
                    return (0);
                i++;
                j++;
            }
        }
        i++;
    }
    return (1);
}

void	file_check(char *map)
{
	if (is_there_extension(map))
        ft_putstr_fd("Error\nThe extenstion not valid.");
    is_have_dot(map);
    is_there_anything_before_dot(map);

}

