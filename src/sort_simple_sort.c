#include "../includes/push_swap.h"

static int ft_find_highest_value (t_stack *lst);




int ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
    int i_heigst_value;
    int i_count;
    int error;

    error = 0;
    i_heigst_value = ft_find_highest_value(*stack_a);
    i_count = 0;

    while (!ft_check_range(*stack_a))
    {
        if (i_heigst_value == (*stack_a) ->value)
            ft_ra(stack_a, &error); 
        else if (i_heigst_value == (*stack_a) ->next ->value)
            ft_rra(stack_a, &error);
        else if ((*stack_a) ->next ->value > (*stack_a) ->value)
            ft_sa(stack_a, &error);
        else if ((*stack_a) ->next ->value < (*stack_a) ->value)
            ft_sa(stack_a, &error);
        i_count++;
    }
    if (error)
        ft_throw_error(error, stack_a, stack_b);
    return (i_count);
}

static int ft_find_highest_value (t_stack *lst)
{
    int i_max;
    t_stack *lst_head;

    i_max = -2147483648;
    lst_head = lst;
    while (lst)
    {
        if (lst ->value > i_max)
            i_max = lst ->value;
        lst = lst ->next;
    }
    lst = lst_head;
    return (i_max);
}