#include "../incs/push_swap.h"

void	sa_sb(t_stack **ab, char *output)
{
	t_stack	*temp;

	if ((*ab) == NULL || (*ab)->next == NULL)
		return ;
	temp = (*ab)->next;
	(*ab)->next = (*ab)->next->next;
	temp->next = (*ab);
	(*ab) = temp;
	if (output)
		ft_printf("%s\n", output);
}

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a, NULL);
	sa_sb(b, NULL);
	ft_printf("ss\n");
}

void	pa_pb(t_stack **src, t_stack **target, char *output)
{
	t_stack	*temp;

	if ((*src) == NULL)
		return ;
	temp = (*src)->next;
	if ((*target) == NULL)
		(*src)->next = NULL;
	else
		(*src)->next = (*target);
	(*target) = (*src);
	(*src) = temp;
	ft_printf("%s\n", output);
}