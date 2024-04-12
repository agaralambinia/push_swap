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
			{
				//ft_printf("arg_unit_checker\n");
				return (-1);
			}
			nbr = ft_atol(*uargv);
			if (nbr < -2147483648 || nbr > 2147483647)
			{
				//ft_printf("MAXINTMININT\n");
				return (-1);
			}
			if (dubl_checker(*a, (int)nbr))
			{
				//ft_printf("dubl_checker\n");
				return (-1);
			}
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