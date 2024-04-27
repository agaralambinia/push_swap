#include "../incs/push_swap.h"

t_stack	*st_newnode(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	st_insert(t_stack **a, t_stack *new)
{
	t_stack	*temp;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	st_fill(t_stack **a, char **argv)
{
	long	nbr;
	char	**uargv;
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		uargv = ft_split(argv[i], ' ');
		j = 0;
		while (uargv[j] != NULL)
		{
			arg_unit_checker(uargv[j]);
			nbr = ft_atol(uargv[j]);
			if (nbr < -2147483648 || nbr > 2147483647)
				ft_exit_error();
			st_insert(a, st_newnode((int)nbr));
			j++;
		}
		free_free(uargv);
		i++;
	}
}

void	st_free(t_stack **ab)
{
	t_stack	*tmp;

	if (ab == NULL)
		return ;
	while (*ab != NULL)
	{
		tmp = (*ab)->next;
		free(*ab);
		*ab = tmp;
	}
}