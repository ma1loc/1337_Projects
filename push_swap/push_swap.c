#include "push_swap.h"

int	main(int argc, char **argv)
{
	// check if there's char in the argument.
	// parsing the argument first.
	if (argc > 1)
	{
		if (is_valid_num(argv) == 1)
		{
			printf("there is a character.\n");
			exit(0);
		}
	}
}
