/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:36:10 by defimova          #+#    #+#             */
/*   Updated: 2024/04/28 20:36:12 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ra_rb(t_stack **ab, char *output)
{
	t_stack	*temp;
	t_stack	*temp_two;

	if (output)
		ft_printf("%s\n", output);
	if (!ab || !*ab || !(*ab)->next)
		return ;
	temp = *ab;
	temp_two = (*ab)->next;
	*ab = st_find_last(*ab);
	(*ab)->next = temp;
	temp->next = NULL;
	*ab = temp_two;
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	ra_rb(a, NULL);
	ra_rb(b, NULL);
}

void	rra_rrb(t_stack **ab, char *output)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prelast;

	if (output)
		ft_printf("%s\n", output);
	if (!ab || !*ab || !(*ab)->next)
		return ;
	last = st_find_last(*ab);
	prelast = st_find_prelast(*ab);
	temp = *ab;
	*ab = last;
	(*ab)->next = temp;
	prelast->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	rra_rrb(a, NULL);
	rra_rrb(b, NULL);
}
