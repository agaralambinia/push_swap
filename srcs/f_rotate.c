#include "../incs/push_swap.h"

void	ra_rb(t_stack **ab, char *output)
{
	t_stack	*last;

	if (*ab == NULL || ab == NULL)
		return ;
	last = st_find_last(*ab);
	last->next = *ab;
	*ab = (*ab)->next;
	(*ab)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	if ((*ab)->next == NULL)
	if (output)
		ft_printf("%s\n", output);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	ra_rb(a, NULL);
	ra_rb(b, NULL);
}

void	rra_rrb(t_stack **ab, char *output)
{
	t_stack	*last;

	if (*ab == NULL || ab == NULL)
		return ;
		if ((*ab)->next == NULL)
	if ((*ab)->next == NULL)
	{
		if (output)
			ft_printf("%s\n", output);
		return ;
	}
	last = st_find_last(*ab);
	last->prev->next = NULL;
	last->next = *ab;
	last->prev = NULL;
	*ab = last;
	last->next->prev = last;
	if (output)
		ft_printf("%s\n", output);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	rra_rrb(a, NULL);
	rra_rrb(b, NULL);
}