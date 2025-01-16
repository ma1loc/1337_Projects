#include "push_swap.h"

int	is_valid_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || (argv[i][j] == ' '))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

//char *parsing(char **argv)
//{
	//check_if there is a charcter or not.
	// check to the - and +
	
//}
