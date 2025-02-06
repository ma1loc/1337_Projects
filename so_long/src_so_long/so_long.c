#include "so_long.h"

int	main(int argc, char **argv)
{
    int fd;

	if (argc == 1)
		ft_putstr_fd("Error\nA few args, put the map to play\n");
    if (argc > 1)
		file_check(argv[1]);
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_perror("Error\nopen");
    is_map_valid(fd);
    is_duplicate_char(argv[1]);
    close(fd);
}
