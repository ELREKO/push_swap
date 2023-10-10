#include "../includes/push_swap.h"

int ft_sort_three(t_stack **stack_a, int *error)
{
    t_stack *lst_last;
    t_stack *lst_first;
    t_stack *lst_second;

    lst_first = *stack_a;
    lst_second = lst_first ->next;
    lst_last = ft_lastlst(lst_first);

    if(ft_check_range(*stack_a)) // (1, 2, 3)
        return (0);
    if (lst_first ->value > lst_second ->value && lst_second ->value < lst_last -> value && lst_first ->value > lst_last ->value) //(3, 1, 2)
        ft_ra(stack_a, error);
    else if(lst_first ->value < lst_second ->value && lst_second ->value > lst_last -> value && lst_first ->value > lst_last ->value) //(2, 3, 1)
        ft_rra(stack_a, error);
    else if (lst_first ->value > lst_second ->value && lst_second ->value < lst_last -> value) //(2, 1 ,3)
        ft_sa(stack_a, error);
    else
    {
        ft_sa(stack_a, error);
        if (lst_first ->value > lst_second ->value)
            ft_ra(stack_a, error); //(1. 3, 2)
        else
            ft_rra(stack_a, error); //(3. 2, 1)
        return (2);
    }
    return (1);
}

int ft_sort_stack(t_stack **stack_a, int *error)
{
    //t_stack *lst_first;
    //t_stack *lst_next;
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
        // if (i_count >  50)
        //     break;
    }
    return (i_count);
}