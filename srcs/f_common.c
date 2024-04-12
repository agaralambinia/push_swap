#include "../incs/push_swap.h"

int	isspace_check(const char a)
{
	if ((a == ' ') || (a == '\n') || (a == '\t') || (a == '\v')
		|| (a == '\f') || (a == '\r'))
	{
		return (1);
	}
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int     i;
	long	sign;
	long	res;

	sign = 1;
	i = 0;
	res = 0;
	while (isspace_check(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = (-1) * sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 - 48 + str[i];
		i++;
	}
	return (res * sign);
}

int	free_free(char **str)
{
	char	**temp;

	temp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(temp);
	return (-1);
}
