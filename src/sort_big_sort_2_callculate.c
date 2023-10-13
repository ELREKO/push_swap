#include "../includes/push_swap.h"

static int ft_callculate_steps_StackA(t_stack **stack_A, int index);

// set in stack B the coast for rotating in front
// -> in "diff" die guenstigsten Kosten aus Stack A gespeichert!
// -> in "coast" die Schritte fuer die Rotation an die push position 
// -> in "max_coast" wird die Differnce zwichen den beiden gespeichert
int ft_callculate_rotate_StackB(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *lst_tmp;
    int i_count;
    int i_size;

    i_size = ft_lstsize(*stack_b);
    lst_tmp = *stack_b;
    i_count = 0;
    while (lst_tmp)
    {
        lst_tmp ->diff = ft_callculate_steps_StackA(stack_a, lst_tmp ->index);
        if (i_count < i_size/2 || i_size == 1)
            lst_tmp ->coast = i_count;
        else
            lst_tmp ->coast = i_count - i_size;
        lst_tmp = lst_tmp ->next;
        i_count++;
    }
    return (ft_set_Choise(stack_b));
}

// search next postion in stack A-> "return" the lowast coast to bring Stack_A in Postion for pushing form B with the given index
static int ft_callculate_steps_StackA(t_stack **stack_A, int index)
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



// return the minmal coast wehre you could search for
int ft_set_Choise(t_stack **stack_b)
{
    t_stack *lst_tmp;
    int i_min;

    lst_tmp = *stack_b;
    while (lst_tmp)
    {
        // gleiche Vorzeichen 
        if (lst_tmp ->diff <= 0 &&  lst_tmp ->coast <= 0)
        {
            if (lst_tmp->coast <= lst_tmp->diff)
                lst_tmp ->max_coast = (lst_tmp ->coast) * (-1);
            else
                lst_tmp ->max_coast = (lst_tmp ->diff * (-1));
        }
        else if (lst_tmp ->diff >= 0 &&  lst_tmp ->coast >= 0)
        {
            if ((lst_tmp->coast >= lst_tmp->diff))
                lst_tmp ->max_coast = lst_tmp -> coast;
            else
                lst_tmp ->max_coast = lst_tmp ->diff;
        }
        else if (lst_tmp ->diff < 0)
            lst_tmp -> max_coast = (lst_tmp ->diff * (-1)) + (lst_tmp ->coast);
        else
            lst_tmp -> max_coast = (lst_tmp ->coast * (-1)) + (lst_tmp ->diff);
        lst_tmp = lst_tmp ->next;
    }
    lst_tmp = *stack_b;
    i_min = 2147483647;
    while (lst_tmp)
    {
        if (lst_tmp ->max_coast < i_min)
            i_min = lst_tmp ->max_coast;
        lst_tmp = lst_tmp ->next;
    }
    return (i_min);
}



