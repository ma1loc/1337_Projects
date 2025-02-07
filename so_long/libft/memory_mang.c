#include "../src_so_long/so_long.h"

void    mem_free(char **readed_map)
{
    int i;

    i = 0;
    if (readed_map)
    {
        while (readed_map[i])
        {
            free(readed_map[i]);
            i++;
        }
    }
}