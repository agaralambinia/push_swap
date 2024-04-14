#include "../incs/push_swap.h"

void    base_case_sort(t_stack **a)
{
    t_stack *max;

    max = st_find_max(*a);
    if (*a == max)
        ra_rb(a, "ra");
    else if ((*a)->next == max)
        rra_rrb(a, "rra");
    if ((*a)->data > (*a)->next->data)
        sa_sb(a, "sa");
}

void    choose_target(t_stack *a, t_stack *b)
{
    t_stack *near_var;
    t_stack *place;
    long    match;

    while (b != NULL)
    {
        match = LONG_MAX;
        near_var = a;
        while (near_var != NULL)
        {
            if (near_var->value > b->value && near_var->value < match)
            {
                match = near_var->value;
                place = near_var;
            }
            near_var = near_var->next;
        }
        if (match == LONG_MAX)
            b->place = st_find_min(a);
        else
            b->place = place;
        b = b->next;
    }
}
