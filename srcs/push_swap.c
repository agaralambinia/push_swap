#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (st_fill(&a, argv + 1) == -1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	//if (!st_sorted(a))
	//{
	//	if (st_len(a) == 2)
	//		sa_sb(&a, 'sa');
	//	else if (st_len(a) == 3)
	//		tiny_sort(&a);
	//	else
	//		push_swap(&a, &b);
	//}
	//free_stack(&a);
	t_stack	*at;
	t_stack	*bt;
	at = a;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	pa_pb(&b, &a, "pb");
	pa_pb(&b, &a, "pb");
	pa_pb(&b, &a, "pb");
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	pa_pb(&a, &b, "pa");
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	sa_sb(&a, "sa");
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	sa_sb(&b, "sb");
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	ss(&a, &b);
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	rr(&a, &b);
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");
	rrr(&a, &b);
	at = a;
	bt = b;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
	ft_printf("\n");
	while (bt != NULL)
	{
		ft_printf("%i; ", bt->data);
		bt = bt->next;
	}
	ft_printf("\n");

	return (0);
}
