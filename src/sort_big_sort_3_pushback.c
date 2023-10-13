#include "../includes/push_swap.h"
static void ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b, int i_pos, int *error);
static void ft_both_negativ(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error);
static void ft_both_positv(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error);
static void ft_both_different(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error);

// Pruefe index b und sort ein 
int ft_sort_back(t_stack **stack_a, t_stack **stack_b, int *error)
{
    int i_pos = 0;
    int i_count = 0;

    while ((*stack_b))
    {    
        i_pos = ft_callculate_rotate_StackB(stack_a, stack_b);
        ft_pushback_to_a(stack_a, stack_b, i_pos, error);
        i_count = i_count + i_pos + 1;
    }
    return (i_count);
}

static void ft_pushback_to_a(t_stack **stack_a, t_stack **stack_b, int i_pos, int *error)
{
    t_stack *lst_tmp;

    lst_tmp = *stack_b;
    while (lst_tmp)
    {
        if (i_pos == (lst_tmp->max_coast))
        {
            if (lst_tmp ->diff <= 0 &&  lst_tmp ->coast <= 0)
                ft_both_negativ(stack_a, stack_b, lst_tmp ->diff, lst_tmp ->coast, error);
            else if (lst_tmp ->diff >= 0 &&  lst_tmp ->coast >= 0)
                ft_both_positv(stack_a, stack_b, lst_tmp ->diff, lst_tmp ->coast, error);
            else
                ft_both_different(stack_a, stack_b, lst_tmp ->diff, lst_tmp ->coast, error);
            break;
        }
        lst_tmp = lst_tmp ->next;
    }
    ft_pa(stack_a, stack_b, error);
}

static void ft_both_negativ(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error)
{
    int i_tmp;

    if (diff <= coast)
    {
        i_tmp = coast;
        while (i_tmp++ < 0)
            ft_rrr(stack_a, stack_b, error);
        i_tmp =  diff + (coast * (-1));
        while (i_tmp++ < 0)
            ft_rra(stack_a, error);                                
    }
    else
    {
        i_tmp = diff;
        while (i_tmp++ < 0)
            ft_rrr(stack_a, stack_b, error);
        i_tmp =  coast + (diff * (-1));
        while (i_tmp++ < 0)
            ft_rrb(stack_b, error);    
    }
}

static void ft_both_positv(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error)
{
    int i_tmp;
    if (diff >= coast)
    {
        i_tmp = coast;
        while (i_tmp-- > 0)
            ft_rr(stack_a, stack_b, error);
        i_tmp =  diff - coast;
        while (i_tmp-- > 0)
            ft_ra(stack_a, error);                                
    }
    else
    {

        i_tmp = diff;
        while (i_tmp-- > 0)
            ft_rr(stack_a, stack_b, error);
        i_tmp =  coast - diff;
        while (i_tmp-- > 0)
            ft_rb(stack_b, error);    
    }
}

static void ft_both_different(t_stack **stack_a, t_stack **stack_b, int diff, int coast, int *error)
{
    int i_tmp;

    if (coast <= 0)
    {
        i_tmp = coast;
        while (i_tmp++ < 0)
            ft_rrb(stack_b, error);
        i_tmp =  diff;
        while (i_tmp-- > 0)
            ft_ra(stack_a, error);                                
    }
    else
    {
        i_tmp = coast;
        while (i_tmp-- > 0)
            ft_rb(stack_b, error);
        i_tmp =  diff;
        while (i_tmp++ < 0)
            ft_rra(stack_a, error);     
    }
}