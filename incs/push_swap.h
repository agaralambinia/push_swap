#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

/* 
	Аргументы структуры t_stack:
	- data - значение в ноде;
	- index - желаемый порядковый номер ноды в стеке
	- next - указатель на следующую ноду
*/
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
} t_stack;

/* Функции основного алгоритма */
void    sorter(t_stack **a, t_stack **b);
void    base_case_sort(t_stack **a);
void	little_sort(t_stack **a, t_stack **b, int len);
void	butterfly_sort(t_stack **a, t_stack **b);

/* Вспомогательные функции основного алгоритма */
int		top_distance(t_stack **b, int data);
void	bring_to_top(t_stack **b, t_stack *temp);
void	st_select_max(t_stack **b);
void	st_fill_b(t_stack **a, t_stack **b, int *i, int magic);
int		magic_number(int len);

/* Операции над стеком */
void	sa_sb(t_stack **ab, char *output);
void	ss(t_stack **a, t_stack **b);
void	pa_pb(t_stack **dst, t_stack **src, char *output);
void	ra_rb(t_stack **ab, char *output);
void	rr(t_stack **a, t_stack **b);
void	rra_rrb(t_stack **ab, char *output);
void	rrr(t_stack **a, t_stack **b);

/* Функции изменения стека */
void	st_fill(t_stack **a, char **argv);
void	st_free(t_stack **ab);
void	st_insert(t_stack **a, t_stack *new);
t_stack	*st_newnode(int data);

/* Функции заполнения метаданных стека */
void	st_index(t_stack **a);
int		*fill_index(t_stack *a, int len);
void	st_set_index(t_stack **a, int *index, int len);

/* Функции, возвращающие метаданные стека */
t_stack	*st_find_last(t_stack *a);
t_stack	*st_find_prelast(t_stack *a);
int		st_len(t_stack *a);
int		st_sorted(t_stack *a);
t_stack	*st_find_minmax(t_stack *a, int minmax);

/* Функции проверки вызова */
void	arg_unit_checker(char *uargv);
int		dubl_checker(t_stack *a);

/* Функции общего назначения */
int		isspace_check(const char a);
long	ft_atol(const char *str);
void	free_free(char **str);
void	ft_exit_error(void);
void	pointer_swap(int *a, int *b);

#endif