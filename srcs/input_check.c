#include "../incs/push_swap.h"

int	dubl_checker(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	if (!a)
		return (1);
	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->data == j->data)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	arg_unit_checker(char *uargv)
{
	int i;

	i = 0;
	if ((uargv[i] == '-' || uargv[i] == '+') && (uargv[i + 1] <= '9' || uargv[i + 1] >= '0'))
	{
		if (uargv[i + 1] == '\0')
			ft_exit_error();
		else
			i++;
	}
	while (uargv[i])
	{
    	if (uargv[i] > '9' || uargv[i] < '0')
			ft_exit_error();
		i++;
	}
}
