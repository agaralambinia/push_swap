#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				position;
	int				end_index;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

int     main(int argc, char **argv);
int		isspace_check(const char a);
long	ft_atol(const char *str);
int		free_free(char **str);
int		dubl_checker(t_stack *a, int nbr);
int		arg_unit_checker(char *uargv);
void	st_insert(t_stack **a, int data);
int		st_fill(t_stack **a, char **argv);
t_stack	*st_find_last(t_stack *a);
void	sa_sb(t_stack **ab, char *output);
void	ss(t_stack **a, t_stack **b);
void	pa_pb(t_stack **src, t_stack **target, char *output);
void	ra_rb(t_stack **ab, char *output);
void	rra_rrb(t_stack **ab, char *output);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif