#include "../src_so_long/so_long.h"

void    cleanup_and_exit(char *str, char **readed_map)
{
    if (readed_map)
        map_free(readed_map);
    ft_putstr_fd(str);
}