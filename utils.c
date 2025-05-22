#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	check_number_overflow(long long num, int sign)
{
	if ((sign == 1 && num > INT_MAX)
		|| (sign == -1 && num > (long long)INT_MAX + 1))
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if (!check_number_overflow(num, sign))
			return (0);
		i++;
	}
	return (1);
}
