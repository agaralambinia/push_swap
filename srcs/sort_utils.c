/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:37:36 by defimova          #+#    #+#             */
/*   Updated: 2024/04/28 20:37:39 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	top_distance(t_stack **b, int data)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *b;
	while ((*b)->data != data)
	{
		*b = (*b)->next;
		i++;
	}
	*b = temp;
	return (i);
}

void	bring_to_top(t_stack **b, t_stack *temp)
{
	int		len;

	len = st_len(*b);
	if (top_distance(b, temp->data) <= len / 2)
		while ((*b)->data != temp->data)
			ra_rb(b, "rb");
	else
		while ((*b)->data != temp->data)
			rra_rrb(b, "rrb");
}

void	st_select_max(t_stack **b)
{
	t_stack	*temp;
	int		max;

	temp = *b;
	max = temp->data;
	while (*b)
	{
		if ((*b)->data > max)
			max = (*b)->data;
		*b = (*b)->next;
	}
	*b = temp;
	while (temp->data != max)
		temp = temp->next;
	bring_to_top(b, temp);
}

void	st_fill_b(t_stack **a, t_stack **b, int *i, int magic)
{
	if ((*a)->index <= *i)
	{
		pa_pb(b, a, "pb");
		(*i)++;
	}
	else if ((*a)->index > *i && (*a)->index <= *i + magic)
	{
		pa_pb(b, a, "pb");
		if (*i != 0)
			ra_rb(b, "rb");
		(*i)++;
	}
	else
		ra_rb(a, "ra");
}

int	magic_number(int len)
{
	int	magic;

	magic = 1;
	while (magic < len / magic)
		magic++;
	return (magic);
}
