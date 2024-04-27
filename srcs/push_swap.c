#include "../incs/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if ((argc < 2 || (argc == 2 && argv[1][0] == '\0')))
		ft_exit_error();
	a = NULL;
	b = NULL;
	st_fill(&a, argv);
	if (dubl_checker(a) == -1)
	{
		st_free(&a);
		ft_exit_error();
	}
	st_index(&a);
	if (st_sorted(a) == 0)
		sorter(&a, &b);
	st_free(&a);
	st_free(&b);
	return (0);
}
