#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				place;
	int				p_distance;
	int				above_median;
	int				cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*place;
} t_stack;

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
void	pa_pb(t_stack **dst, t_stack **src, char *output);
void	ra_rb(t_stack **ab, char *output);
void	rra_rrb(t_stack **ab, char *output);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif