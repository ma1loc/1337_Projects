#include "../src_so_long/so_long.h"

void    map_free(char **readed_map)
{
    int i;

    i = 0;
    while (readed_map[i])
    {
        free(readed_map[i]);
        i++;
    }
    free(readed_map);
}

void    cleanup_and_exit(char *str, char **readed_map)
{
    if (readed_map)
        map_free(readed_map);
    ft_putstr_fd(str);
}