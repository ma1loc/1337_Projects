#include <stdio.h>

int static_var()
{
	static int count;
	// count = 0;
	count++;
	return (count);
}

int	main()
{
	printf("%d\n", static_var());	
	printf("%d\n", static_var());	
	printf("%d\n", static_var());	
	printf("%d\n", static_var());		
}