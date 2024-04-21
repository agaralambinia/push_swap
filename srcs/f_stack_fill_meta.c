#include "../incs/push_swap.h"

void	fill_index_sector(t_stack *ab)
{
	int	i;
	int	center;

	i = 0;
	if (ab == NULL)
		return ;
	center = st_len(ab) / 2;
	while (ab != NULL)
	{
		ab->index = i;
		if (i <= center)
			ab->sector = 0;
		else
			ab->sector = 1;
		ab = ab->next;
		i++;
	}
}

void	fill_place(t_stack *a, t_stack *b)
{
	t_stack	*iter_a;
	t_stack	*place;
	long    best_data;

	while (b != NULL)
	{
		best_data = LONG_MAX;
		iter_a = a;
		while (iter_a != NULL)
		{
			if (iter_a->data > b->data && iter_a->data < best_data)
			{
				best_data = iter_a->data;
				place = iter_a;
			}
			iter_a = iter_a->next;
		}
		if (best_data == LONG_MAX)
			b->place = st_find_minmax(a, 0);
		else
			b->place = place;
		b = b->next;
	}
}

void	fill_p_distance(t_stack *a, t_stack *b)
{
	long	len_a;
	long	len_b;

	len_a = st_len(a);
	len_b = st_len(b);
	while (b != NULL)
	{
		b->p_distance = b->index;
		if (b->sector == 1)
			b->p_distance = len_b - (b->index);
		if (b->place->sector == 0)
			b->p_distance += b->place->index;
		else
			b->p_distance += len_a - (b->place->index);
		b = b->next;
	}
}

void	fill_best(t_stack *b)
{
	long	best_data;
	t_stack	*best_node;

	if (b == NULL)
		return ;
	best_data = LONG_MAX;
	while (b != NULL)
	{
        b->best = 0;
		if (b->p_distance < best_data)
		{
			best_data = b->p_distance;
			best_node = b;
		}
		b = b->next;
	}
	best_node->best = 1;
}

void	fill_meta(t_stack *a, t_stack *b)
{
	fill_index_sector(a);
	fill_index_sector(b);
	fill_place(a, b);
	fill_p_distance(a, b);
	fill_best(b);
}