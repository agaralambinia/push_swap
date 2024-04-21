#include "../incs/push_swap.h"

void    base_case_sort(t_stack **a)
{
    t_stack *max;

    max = st_find_minmax(*a, 1);
    if (*a == max)
        ra_rb(a, "ra");
    else if ((*a)->next == max)
        rra_rrb(a, "rra");
    if ((*a)->data > (*a)->next->data)
        sa_sb(a, "sa");
}

void	local_rotate(t_stack **ab, t_stack *first, int stack)
{
	while (*ab != first)
	{
        if (first->sector == 0)
        {
        	if (stack == 0)
		        ra_rb(ab, "ra");
			else
				rra_rrb(ab, "rb");
        }
	    else
        {
        	if (stack == 0)
		        ra_rb(ab, "rra");
			else
				rra_rrb(ab, "rrb");
        }
    }
}

void    st_push_a(t_stack **a, t_stack **b)
{
	t_stack	*best;

	best = st_best(*b);
	if ((best->sector == 0) && (best->place->sector == 0))
    {
		while (!((*a == best->place) || (*b == best)))
		    rr(a, b);
	    fill_index_sector(*a);
	    fill_index_sector(*b);
    }
	else if ((best->sector == 1) && (best->place->sector == 1))
    {
		while (!((*a != best->place) || (*b != best)))
		    rrr(a, b);
        fill_index_sector(*a);
	    fill_index_sector(*b);
    }
    local_rotate(a, best->place, 0);
	local_rotate(b, best, 1);
	pa_pb(a, b, "pa");
}

void    sorter(t_stack **a, t_stack **b)
{
    t_stack *min;
    long len;

    len = st_len(*a);
    while (len > 3)
    {
        pa_pb(b, a, "pb");
        len--;
    }
    base_case_sort(a);
	while (*b != NULL)
	{
		fill_meta(*a, *b);
		st_push_a(a, b);
	}
	fill_index_sector(*a);
	min = st_find_minmax(*a, 0);
	if (min->sector == 0)
		while (*a != min)
			ra_rb(a, "ra");
	else
		while (*a != min)
			rra_rrb(a, "rra");
}