#include "../incs/push_swap.h"

void	st_insert(t_stack **a, int data)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		free(new);
	new->data = data;
	new->next = NULL;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = st_find_last(*a);
		last->next = new;
		new->prev = last;
	}
}

int	st_fill(t_stack **a, char **argv)
{
	long	nbr;
	char **uargv;

	uargv = NULL;
	while (*argv)
	{
		uargv = ft_split(*argv, ' ');
		while (*uargv)
		{
			if (arg_unit_checker(*uargv) == -1)
				return (-1);
			nbr = ft_atol(*uargv);
			if (nbr < -2147483648 || nbr > 2147483647)
				return (-1);
			if (dubl_checker(*a, (int)nbr))
				return (-1);
			st_insert(a, (int)nbr);
			uargv++;
		}
		argv++;
	}
	return (0);
}

t_stack	*st_find_last(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*st_find_min(t_stack *a)
{
	int			min;
	t_stack_node	*s_min;

	if (a == NULL)
		return (NULL);
	min = INT_MAX;
	while (a != NULL)
	{
		if (a->value <= min)
		{
			min = a->value;
			s_min = a;
		}
		a = a->next;
	}
	return (s_min);
}


t_stack	*st_find_max(t_stack *a)
{
	int				max;
	t_stack			*s_max;

	if (a == NULL)
		return (NULL);
	max = INT_MIN;
	while (a != NULL)
	{
		if (a->value >= max)
		{
			max = a->value;
			s_max = a;
		}
		a = a->next;
	}
	return (s_max);
}