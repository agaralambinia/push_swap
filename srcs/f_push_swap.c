#include "../incs/push_swap.h"

void	sa_sb(t_stack **ab, char *output)
{
	t_stack	*temp;

	if (output)
		ft_printf("%s\n", output);
	if (!(*ab) || (*ab)->next == NULL)
		return ;
	temp = malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->data = (*ab)->data;
	(*ab)->data = (*ab)->next->data;
	(*ab)->next->data = temp->data;
	temp->index = (*ab)->index;
	(*ab)->index = (*ab)->next->index;
	(*ab)->next->index = temp->index;
	free(temp);
}

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a, NULL);
	sa_sb(b, NULL);
	ft_printf("ss\n");
}

void	pa_pb(t_stack **dst, t_stack **src, char *output)
{
	t_stack	*temp;

	if (output)
		ft_printf("%s\n", output);
	if (!*src || !(*src))
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
}