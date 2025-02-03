#include "so_long.h"

// check if the file is there and have the right permission.
// check if the file have the right extension.
int     is_have_dot(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '.')
            return (0);
        i++;
    }
    return (1);
}
int     is_there_extansion(char *map)
{
    int     i;
    int     j;
    char    *extension;

    i = 0;
    extension = ".ber";

    if (is_have_dot(map))
        ft_putstr_fd("Error\nThere's no extension in the file you provide.");
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
            }
        }
        i++;
    }
    return (1);
}

void	is_valid_map(char *map)
{
    int fd;

	if (is_there_extansion(map))
        ft_putstr_fd("Error\nThe extenstion not valid.");
    
    // if the fils is there 
    fd = open("map.ber", O_RDONLY);
    if (fd == -1)
        perror("Error\n");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr_fd("Error\nA few args, put the map to play\n");
	else if (argc > 1)
		is_valid_map(argv[1]);

	return (0);
}