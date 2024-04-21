#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

/* 
	Аргументы структуры t_stack:
	- data - значение в ноде;
	- index - порядковый номер ноды в стеке
	- p_distance - условное количества операций для перемещения ноды в стек а
	- sector - положение ноды в стеке: 0 выше середины, 1 - ниже
	- best - флаг того, что нода является предпочтительной для пуша
	- prev - указатель на предыдущую ноду
	- next - указатель на следующую ноду
	- place - указатель на ноду стека а, над которой мы хотим разместить ноду
*/
typedef struct s_stack
{
	int				data;
	int				index;
	int				p_distance;
	int				sector;
	int				best;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*place;
} t_stack;

/* Функции основного алгоритма */
void    sorter(t_stack **a, t_stack **b);
void    base_case_sort(t_stack **a);
void    st_push_a(t_stack **a, t_stack **b);
void	local_rotate(t_stack **ab, t_stack *first, int stack);

/* Операции над стеком */
void	sa_sb(t_stack **ab, char *output);
void	ss(t_stack **a, t_stack **b);
void	pa_pb(t_stack **dst, t_stack **src, char *output);
void	ra_rb(t_stack **ab, char *output);
void	rr(t_stack **a, t_stack **b);
void	rra_rrb(t_stack **ab, char *output);
void	rrr(t_stack **a, t_stack **b);

/* Функции изменения стека */
void	st_insert(t_stack **a, int data);
int		st_fill(t_stack **a, char **argv);
void	st_free(t_stack **ab);

/* Функции заполнения метаданных стека */
void	fill_meta(t_stack *a, t_stack *b);
void	fill_index_sector(t_stack *ab);
void	fill_place(t_stack *a, t_stack *b);
void	fill_p_distance(t_stack *a, t_stack *b);
void	fill_best(t_stack *b);

/* Функции, возвращающие метаданные стека */
t_stack	*st_find_last(t_stack *a);
t_stack	*st_find_minmax(t_stack *a, int minmax);
long	st_len(t_stack *a);
int		st_sorted(t_stack *a);
t_stack	*st_best(t_stack *a);

/* Функции проверки вызова */
int		arg_unit_checker(char *uargv);
int		dubl_checker(t_stack *a, int nbr);

/* Функции общего назначения */
int		isspace_check(const char a);
long	ft_atol(const char *str);
int		free_free(char **str);




#endif