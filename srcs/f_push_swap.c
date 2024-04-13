#include "../incs/push_swap.h"

void	sa_sb(t_stack **ab, char *output)
{
	if ((*ab) == NULL || ab == NULL || (*ab)->next == NULL)
		return ;
	*ab = (*ab)->next;
	(*ab)->prev->prev = *ab;
	(*ab)->prev->next = (*ab)->next;
	if ((*ab)->next)
		(*ab)->next->prev = (*ab)->prev;
	(*ab)->next = (*ab)->prev;
	(*ab)->prev = NULL;
	if (output)
		ft_printf("%s\n", output);
}

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a, NULL);
	sa_sb(b, NULL);
	ft_printf("ss\n");
}

void	pa_pb(t_stack **dst, t_stack **src, char *output)
{
	t_stack	*migrant;

	if ((*src) == NULL)
		return ;
	migrant = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	//migrant->prev = NULL;
	if (*dst == NULL)
	{
		*dst = migrant;
		migrant->next = NULL;
	}
	else
	{
		migrant->next = *dst;
		migrant->next->prev = migrant;
		*dst = migrant;
	}
	if (output)
		ft_printf("%s\n", output);
}