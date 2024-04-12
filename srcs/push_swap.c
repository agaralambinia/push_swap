#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	a = NULL;
	//b = NULL;
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
	return (0);
}
