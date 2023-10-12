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

// return the minmal coast wehre you could search for
int ft_set_Choise(t_stack **stack_b)
{
    t_stack *lst_tmp;
    int i_min = 2147483647; 

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
    while (lst_tmp)
    {
        if (lst_tmp ->max_coast < i_min)
            i_min = lst_tmp ->max_coast;
        lst_tmp = lst_tmp ->next;
    }
    return (i_min);
}

// set in stack B the coast for rotating in front
// -> in diff wird die costen von A gespeichert!
// -> in coast die Schritte fuer die Rotation an die push position 
// -> in direction best Chouise
void ft_callculate_rotate_StackB(t_stack **stack_a, t_stack **stack_b)
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
        if (i_count < i_size/2)
            lst_tmp ->coast = i_count;
        else
            lst_tmp ->coast = i_count - i_size ;
        lst_tmp = lst_tmp ->next;
        i_count++;
    }
    ft_set_Choise(stack_b);
    return;
}




// Pruefe index b und sort ein 
int ft_sort_back(t_stack **stack_b, t_stack **stack_a, int *error)
{

    t_stack *lst_tmp;
    int i_pos = 0;
    int i_count = 0;

    lst_tmp = *stack_b;
    ft_callculate_rotate_StackB(stack_a, stack_b);
    while (*stack_b)
    {    
        i_pos = ft_callculate_steps_StackA(stack_a, (*stack_b)->index);
        ft_callculate_rotate_StackB(stack_a, stack_b);

        printf (" \n\n ---die Position ist -- |%i| \n", ft_set_Choise(stack_b));

       // printf (" \n\n ---die Position ist -- |%i| \n", i_pos);
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
        //printf("done\n");
        //ft_lst_print(*stack_b);
    }

    printf("--- Out ---\n");
    return (i_count);
}

/*

Teste mit 

./push_swap 3 -8 8 -7 -1 -5 7 -2 6 -19 -12

intressante Punkte 

---> geht auch mit |-2| schritten

 ---die Position ist -- |3| 
Stack a
Value: |8| -- index |11| -- diff: |-3| -- coast |0|-- direction |0|
Value: |-19| -- index |1| -- diff: |7| -- coast |2|-- direction |0|
Value: |-12| -- index |2| -- diff: |6| -- coast |3|-- direction |0|
Value: |-7| -- index |4| -- diff: |4| -- coast |4|-- direction |0|
Value: |-5| -- index |5| -- diff: |3| -- coast |-4|-- direction |0|
Value: |-2| -- index |6| -- diff: |2| -- coast |-3|-- direction |0|
Value: |-1| -- index |7| -- diff: |1| -- coast |-2|-- direction |1|
Value: |6| -- index |9| -- diff: |-1| -- coast |-2|-- direction |0|
Value: |7| -- index |10| -- diff: |-2| -- coast |-1|-- direction |0|
Stack b
Value: |-8| -- index |3| -- diff: |3| -- coast |0|-- direction |0|
Value: |3| -- index |8| -- diff: |-2| -- coast |-1|-- direction |0|


OR 


------> geht auch mit einr rotation 

 ---die Position ist -- |2| 
Stack a
Value: |-2| -- index |6| -- diff: |2| -- coast |1|-- direction |0|
Value: |6| -- index |9| -- diff: |-1| -- coast |1|-- direction |1|
Value: |-19| -- index |1| -- diff: |7| -- coast |-1|-- direction |0|
Value: |-12| -- index |2| -- diff: |6| -- coast |0|-- direction |0|
Stack b
Value: |7| -- index |10| -- diff: |2| -- coast |0|-- direction |0|
Value: |-5| -- index |5| -- diff: |0| -- coast |1|-- direction |0|
Value: |-1| -- index |7| -- diff: |1| -- coast |2|-- direction |0|
Value: |-7| -- index |4| -- diff: |0| -- coast |-4|-- direction |0|
Value: |8| -- index |11| -- diff: |2| -- coast |-3|-- direction |0|
Value: |-8| -- index |3| -- diff: |0| -- coast |-2|-- direction |0|
Value: |3| -- index |8| -- diff: |1| -- coast |-1|-- direction |0|





*/

