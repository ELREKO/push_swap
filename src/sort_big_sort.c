#include "../includes/push_swap.h"

// Alle bis auf 3 nach B Scheiben 
int ft_push_stack_b(t_stack **stack_a, t_stack **stack_b, int *error)
{
    int i_size;
    int i_count;

    i_size = ft_lstsize(*stack_a);
    i_count = 0;
    while (i_size-- > 3)
    {
        ft_pb(stack_a, stack_b, error);
        i_count++;
    }
    i_count = i_count + ft_sort_three(stack_a, error);
    i_count = i_count + ft_sort_back(stack_b,stack_a,error);
    return (i_count);
}

int ft_search_index_befor(t_stack *lst, int index)
{
    int i_count;
    int i_check;

    i_count = 1;
    i_check = 0;
    while (lst)
    {
        if (lst ->index == (index + 1))
        {
            i_check = 1; 
            break;
        }
        lst = lst ->next;
        i_count++;
    }
    if (!i_check)
    {
        printf (" Fehler Index suche \"ft_search_index_befor\"");
        exit(0);
    }
    return (i_count);
}

// Pruefe index b und sort ein 
int ft_sort_back(t_stack **stack_b, t_stack **stack_a, int *error)
{
    int i_pos = 0;
    int i_size = 0;
    int i_tmp = 0;
    int i_count = 0;

    while ((*stack_b))
    {
        i_pos = ft_search_index_befor(*stack_b, (*stack_a)->value);
        i_size = ft_lstsize(*stack_b);
        if (i_pos - 1 < ((i_size - i_pos) + 1)) //ra
        {
            i_tmp = i_pos;
            while (i_pos - 1 > 0)
            {
                
                ft_ra(stack_b,error); //position a 
                i_pos--;
            }
            ft_pa(stack_b,stack_a,error);
        }
        else
        {
            i_pos = (i_size - i_pos) + 1;
            i_tmp = i_pos;
            while (i_pos - 1 > 0)
            {
                
                ft_rra(stack_b,error); //position a 
                i_pos--;
            }
            ft_pa(stack_b,stack_a,error);
        }
    i_count++;
    }
    return (i_count);
}

