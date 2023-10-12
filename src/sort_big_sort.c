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


void ft_set_diff_and_coasts(t_stack **lst, int *i_max, int *i_min, int index)
{
    t_stack *lst_tmp;
    int i_count;
    int i_size;

    i_size = ft_lstsize(*lst);
    i_count = 0;
    lst_tmp = *lst;
    while (lst_tmp)
    {
        lst_tmp ->diff = index - (lst_tmp ->index); 
        if ((lst_tmp ->diff < 0) && (i_count < (i_size/2)))
            lst_tmp ->coast = i_count;
        else if ((lst_tmp ->diff < 0) && (i_count >= (i_size/2)))
            lst_tmp ->coast = (i_count - i_size);
        else if ((lst_tmp ->diff > 0) && (i_count < (i_size/2)))
            lst_tmp ->coast = i_count + 1;
        else if ((lst_tmp ->diff > 0) && (i_count >= (i_size/2)))
            lst_tmp ->coast = (i_count - i_size) + 1;
        if (lst_tmp ->diff <= 0 && lst_tmp ->diff > *i_min)
            *i_min = lst_tmp ->diff;
        if (lst_tmp ->diff > 0 && lst_tmp ->diff < *i_max)
            *i_max = lst_tmp ->diff;
        lst_tmp = lst_tmp ->next;
        i_count++;
    }
    return;
}

// search next postion in stack -> "return" the loast coast for bring Stack_A in Postion 
int ft_callculate_steps_StackA(t_stack **stack_A, int index)
{
    t_stack *lst_tmp;
    int i_max;
    int i_min;
    int i_count;

    i_max = 2147483647;
    i_min = -2147483648;
    i_count = 0;
    ft_set_diff_and_coasts(stack_A, &i_max, &i_min, index);
    if ((i_min * (-1)) < i_max && i_min != -2147483648)
        i_max = i_min;
    lst_tmp = *stack_A;
    while (lst_tmp)
    {
        if (i_max == lst_tmp ->diff)
        {
            lst_tmp -> direction = 1;
            i_count = lst_tmp ->coast;    
        }
        else 
            lst_tmp -> direction = 0;
        lst_tmp = lst_tmp ->next;
    } 
    return (i_count);
}


// set in stack B the coast for rotating in front
// -> in diff wird die costen von A gespeichert!
// -> in coast die Schritte fuer die Rotation an die push position 
// -> spaeter Auswertung 
void ft_callculate_rotate_StackB(t_stack **stack_B)
{
    t_stack *lst_tmp;
    int i_count;
    int i_size;

    i_size = ft_lstsize(*stack_B);
    lst_tmp = *stack_B;
    i_count = 0;
    while (lst_tmp)
    {
        //ft_callculate_steps_StackA
        //printf ("i am her \n")
        if (i_count < i_size/2)
            lst_tmp ->coast = i_count;
        else
            lst_tmp ->coast = i_count - i_size ;
        lst_tmp = lst_tmp ->next;
        i_count++;
    }      
    return;
}




// Pruefe index b und sort ein 
int ft_sort_back(t_stack **stack_b, t_stack **stack_a, int *error)
{
    int i_pos = 0;
    int i_count = 0;

    while (*stack_b)
    {    
        i_pos = ft_callculate_steps_StackA(stack_a, (*stack_b)->index);
        ft_callculate_rotate_StackB(stack_b);
        printf (" \n\n ---die Position ist -- |%i| \n", i_pos);
        printf ("Stack a\n");
        ft_lst_print(*stack_a);
        printf ("Stack b\n");
        ft_lst_print(*stack_b);

        if (i_pos < 0)
        {
            
            while (i_pos++ < 0)
                ft_rra(stack_a, error);
        }
        else
        {
            while (i_pos-- > 0)
                ft_ra(stack_a, error);
        }
        ft_pa(stack_a, stack_b, error);
        i_count++;
        printf("done\n");
        ft_lst_print(*stack_b);
    }

     printf("--- Out ---\n");
    return (i_count);
}

