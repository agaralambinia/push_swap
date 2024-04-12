#include "../incs/push_swap.h"

int	dubl_checker(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		//ft_printf("DUBL %i\n", nbr);
		if (nbr == a->data)
			return (1);
		a = a->next;
	}
	//ft_printf("DUBL EXIT %i\n", nbr);
	return (0);
}

int	arg_unit_checker(char *uargv)
{
    int sign;

	sign = 0;
	if ((uargv[0] == '-' || uargv[0] == '+') && uargv[1] == '\0')
		return (-1);
	while (*uargv)
	{
    	if ((*uargv == '-' || *uargv == '+'))
    	{
    	    if (sign == 0)
    	        sign++;
    	    else
			    return (-1);
    	}
		else if (*uargv > '9' || *uargv < '0')
			return (-1);
		uargv++;
	}
	return (0);
}
