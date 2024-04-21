#include "../incs/push_swap.h"

t_stack	*st_find_last(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*st_find_minmax(t_stack *a, int minmax)
{
	int			data;
	t_stack	*s_minmax;

	if (a == NULL)
		return (NULL);
	if (minmax == 0)
		data = INT_MAX;
	else
		data = INT_MIN;
	while (a != NULL)
	{
		if (((a->data <= data) && (minmax == 0)) ||
			(((a->data >= data) && (minmax == 1))))
		{
			data = a->data;
			s_minmax = a;
		}			
		a = a->next;
	}
	return (s_minmax);
}

long	st_len(t_stack *a)
{
	int	cnt;

	cnt = 0;
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		a = a->next;
		cnt++;
	}
	return (cnt);
}

int	st_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*st_best(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (a->best == 1)
			return (a);
		a = a->next;
	}
	return (NULL);
}