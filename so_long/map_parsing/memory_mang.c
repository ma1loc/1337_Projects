#include "../src_so_long/so_long.h"

void    map_free(char **readed_map)
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
    free(readed_map);
}

void    cleanup_and_exit(char *str, char **readed_map)
{
    if (readed_map)
        map_free(readed_map);
    ft_putstr_fd(str);
}

int *allocate_for_row_and_col(int row, int col, char **map)
{
    int *row_and_col;

    row_and_col = malloc(sizeof(int) * 2);
    if (!row_and_col)
        cleanup_and_exit("Error\nAllocation faild.", map);
    row_and_col[0] = row;
    row_and_col[1] = col;
    return (row_and_col);
}