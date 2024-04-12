#include "../incs/push_swap.h"

void	ra_rb(t_stack **ab, char *output)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*ab)->next == NULL)
		return ;
	last = st_find_last((*ab));
	temp = (*ab)->next;
	if (temp == NULL)
		return ;
	(*ab)->next = NULL;
	last->next = (*ab);
	(*ab) = temp;
	if (output)
		ft_printf("%s\n", output);
}

void	rra_rrb(t_stack **ab, char *output)
{
	t_stack	*last;
	t_stack	*temp;

	last = st_find_last((*ab));
	temp = (*ab);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = (*ab);
	(*ab) = last;
	if (output)
		ft_printf("%s\n", output);
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a, NULL);
	ra_rb(b, NULL);
	ft_printf("rr");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, NULL);
	rra_rrb(b, NULL);
	ft_printf("rrr");
}