#include "push_swap.h"

int	is_valid_atoi(char *str)
{
	long int	nbr;

	nbr = ft_atoi(str);
	if (is_digit(str) || (nbr > 2147483647 || nbr < -2147483648))
		return (1);
	return (0);
}

long int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
