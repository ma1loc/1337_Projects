#include <stdio.h>

int static_var()
{
	static int count;
	count = 0;
	count++;
	return (count);
}

int	main()
{
	printf("this is after initialization -> %d\n", static_var());	
	printf("this is after initialization -> %d\n", static_var());	
	printf("this is after initialization -> %d\n", static_var());	
	printf("this is after initialization -> %d\n", static_var());	
}