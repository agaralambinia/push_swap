/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:35:28 by defimova          #+#    #+#             */
/*   Updated: 2024/04/28 20:35:31 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	base_case_sort(t_stack **a)
{
	t_stack	*max;

	max = st_find_minmax(*a, 1);
	if (*a == max)
		ra_rb(a, "ra");
	else if ((*a)->next == max)
		rra_rrb(a, "rra");
	if ((*a)->data > (*a)->next->data)
		sa_sb(a, "sa");
}

void	little_sort(t_stack **a, t_stack **b, int len)
{
	int		i;
	int		min;

	i = 0;
	min = st_find_minmax(*a, 0)->data;
	while (i < len - 3)
	{
		if ((*a)->data == min)
		{
			pa_pb(b, a, "pb");
			i++;
			min = st_find_minmax(*a, 0)->data;
		}
		else
		{
			if (top_distance(a, min) > (len - i) / 2)
				rra_rrb(a, "rra");
			else
				ra_rb(a, "ra");
		}
	}
	base_case_sort(a);
	while (*b)
		pa_pb(a, b, "pa");
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	int		magic;
	int		i;
	int		lena;

	i = 0;
	lena = st_len(*a);
	magic = magic_number(lena);
	while (i < lena)
		st_fill_b(a, b, &i, magic);
	while (*b)
	{
		st_select_max(b);
		pa_pb(a, b, "pa");
	}
}

void	sorter(t_stack **a, t_stack **b)
{
	int	len;

	len = st_len(*a);
	if (len == 2 && (*a)->data > (*a)->next->data)
		sa_sb(a, "sa");
	else if (len == 3)
		base_case_sort(a);
	else if (len >= 4 && len <= 5)
		little_sort(a, b, len);
	else if (len >= 6)
		butterfly_sort(a, b);
}
