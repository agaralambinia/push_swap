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
		st_free(&a);
		st_free(&b);
		exit(EXIT_FAILURE);
	}
	if (st_fill(&a, argv + 1) == -1)
	{
		ft_printf("Error\n");
		st_free(&a);
		st_free(&b);
		exit(EXIT_FAILURE);
	}
	if (st_sorted(a) == 0)
		sorter(&a, &b);
	st_free(&a);
	st_free(&b);
	return (0);
}
