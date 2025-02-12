#include "../src_so_long/so_long.h"

t_position  *put_row_and_col(int _row, int _col)
{
    t_position  *row_and_col;

    row_and_col = malloc(sizeof(t_position));
    if (!row_and_col)
        return (NULL);

    row_and_col->row = _row;
    row_and_col->col = _col;
    return (row_and_col);
}
