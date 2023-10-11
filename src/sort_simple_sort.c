#include "../includes/push_swap.h"

int ft_find_highest_value (t_stack *lst)
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

int ft_sort_three(t_stack **stack_a, int *error)
{
    int i_heigst_value;
    int i_count;

    i_heigst_value = ft_find_highest_value(*stack_a);
    i_count = 0;

    while (!ft_check_range(*stack_a))
    {
        if (i_heigst_value == (*stack_a) ->value)
            ft_ra(stack_a, error); 
        else if (i_heigst_value == (*stack_a) ->next ->value)
            ft_rra(stack_a, error);
        else if ((*stack_a) ->next ->value > (*stack_a) ->value)
            ft_sa(stack_a, error);
        else if ((*stack_a) ->next ->value < (*stack_a) ->value)
            ft_sa(stack_a, error);
        i_count++;
        if (i_count > 7)
            break;
    }
    return (i_count);
}


// Teste ob ich einen Stack nur mit Swap und rotate sortieren kann 
int ft_sort_stack(t_stack **stack_a, int *error)
{
    int i_check;
    int i_count;

    i_check = 0;
    i_count = 0;
    while (i_check == 0)
    {
        if (((*stack_a) ->index) > ((*stack_a) ->next ->index))
            ft_ra(stack_a, error);
        else
            ft_sa(stack_a, error);
        if ((*stack_a) ->index == 1)
            i_check = ft_check_range(*stack_a);
        i_count++;
    }
    return (i_count);
}