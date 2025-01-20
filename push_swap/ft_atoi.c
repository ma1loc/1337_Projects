#include "push_swap.h"

int	is_valid_digit(char *str)
{
	long int nbr;
	
	if (!is_digit(str))
		return (1);
		//ft_putstr_fd("Error\n", STDERR_FILENO);
	nbr = ft_atoi(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
		//ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

long int ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	
	if (is_valid_digit(str) == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
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
