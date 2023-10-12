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


// search next postion in stack -> return 
int ft_search_index_befor(t_stack **lst, int index)
{
    t_stack *lst_tmp;
    int i_max_coast = 0;
    int i_min_coast = 0;
    int i_max = 2147483647;
    int i_min = -2147483648;
    int i_ret = 0;
    int i_count = 0;
    int i_size = ft_lstsize(*lst);


    lst_tmp = *lst;
    // calculate the diff
    while (lst_tmp)
    {
        //printf ("int lst |%i| and given index |%i|\n", (lst_tmp ->index), index);
        lst_tmp ->diff = index - (lst_tmp ->index); 

        if ((lst_tmp ->diff < 0) && (i_count < (i_size/2)))
            lst_tmp ->coast = i_count;
        else if ((lst_tmp ->diff < 0) && (i_count >= (i_size/2)))
            lst_tmp ->coast = (i_count - i_size) + 1;
        else if ((lst_tmp ->diff > 0) && (i_count < (i_size/2)))
            lst_tmp ->coast = i_count + 1;
        else if ((lst_tmp ->diff > 0) && (i_count >= (i_size/2)))
            lst_tmp ->coast = (i_count - i_size) + 1;


        if (lst_tmp ->diff <= 0 && lst_tmp ->diff > i_min)
        {
            i_min = lst_tmp ->diff;
            //printf ("\n\n --- imin |%i| ----\n\n", i_min );
            i_min_coast = lst_tmp ->coast;
        }
        if (lst_tmp ->diff > 0 && lst_tmp ->diff < i_max)
        {
            i_max = lst_tmp ->diff;
            //printf ("\n\n ----imax |%i|\n\n", i_max);
            i_max_coast = lst_tmp ->coast;
        }
        lst_tmp = lst_tmp ->next;
        i_count++;
    }



    printf ("\n\nimin |%i| imax |%i|\n\n", i_min * -1 , i_max);
    if ((i_min * (-1)) < i_max && i_min != -2147483648)
        i_ret = i_min;
    else
        i_ret = i_max; 



    lst_tmp = *lst;

    //printf ("\n\nimin |%i| imax |%i|\n\n", i_min  , i_max);
    while (lst_tmp)
    {
        //printf ("i ret |%i|  -- i diff |%i| ", i_ret, lst_tmp ->diff);
        if (i_ret == lst_tmp ->diff)
        {
            lst_tmp -> direction = 1;
            i_ret = lst_tmp ->coast;
            
        }
        else 
            lst_tmp -> direction = 0;
        lst_tmp = lst_tmp ->next;
    } 

    printf ("\n\nDie Coasten sind |%i| \n\n", i_ret);
    return (i_ret);
}

// Pruefe index b und sort ein 
int ft_sort_back(t_stack **stack_b, t_stack **stack_a, int *error)
{
    int i_pos = 0;
    int i_tmp = 0
    int i_count = 0;

    while (*stack_b)
    {    
        i_pos = ft_search_index_befor(stack_a, (*stack_b)->index);
        printf (" \n\n ---die Position ist -- |%i| \n", i_pos);
        printf ("Stack a\n");
        ft_lst_print(*stack_a);
        printf ("Stack b\n");
        ft_lst_print(*stack_b);

        if (i_pos < 0)
        {
            //i_tmp = i_pos - 1;
            while (i_pos++ < 0)
                ft_rra(stack_a, error);
            // while (i_tmp++ <0)
            //     ft_ra(stack_a, error);
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

