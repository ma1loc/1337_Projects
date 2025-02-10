#include "../src_so_long/so_long.h"

// void     is_have_dot(char *str)
// {
//     int i;
//     int dot;

//     i = 0;
//     dot = 0;
//     while (str[i])
//     {
//         if (str[i] == '.')
//             dot++;
//         i++;
//     }

//     if (!dot)
//         ft_putstr_fd("Error\nThere's no extension in the file you provide.\
//             \nUsage => \"./so_long map.ber\"");
// }


// void    is_there_anything_before_dot(char *map)
// {
//     if (map[0] == '.')
//         ft_putstr_fd("Error\nPut a name of the file befor the extention.
//         \nUsage => \"./so_long map.ber\"");
// }

int     is_there_extension(char *map)
{
    int	len;

	len = ft_strlen(map);
	if (len < 4 || ft_strncmp(&map[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nThe extenstion not valid.\
		\nUsage => \"./so_long map.ber\".");
	}
    return (1);
}

void	file_check(char *map)
{
	is_there_extension(map); // valid.
    // is_have_dot(map); // valid.
    // is_there_anything_before_dot(map);

}
