#include "../incs/push_swap.h"

int	*fill_index(t_stack *a, int len)
{
	int	*index;
	int	i;
	int	j;

	index = malloc(sizeof(int) * st_len(a));
	i = 0;
	while (a)
	{
		index[i] = a->data;
		a = a->next;
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (index[j] > index[j + 1])
				pointer_swap(&index[j], &index[j + 1]);
			j++;
		}
		i++;
	}
	return (index);
}

void	st_set_index(t_stack **a, int *ind, int len)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (ind[i] == tmp->data)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	st_index(t_stack **a)
{
	int	*index;
	int	len;

	len = st_len(*a);
	index = fill_index(*a, len);
	st_set_index(a, index, len);
	free(index);
}