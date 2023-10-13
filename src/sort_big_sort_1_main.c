#include "../includes/push_swap.h"

static int ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *error);

int ft_big_sort(t_stack **stack_a, t_stack **stack_b, int *error)
{
    int i_count;

    i_count = ft_push_to_stack_b(stack_a,stack_b,error);
    i_count = i_count + ft_sort_three(stack_a, error);
    i_count = i_count + ft_sort_back(stack_a,stack_b,error);
    return (i_count);
}

// Alle bis auf 3 nach Stack B Scheiben 
static int ft_push_to_stack_b(t_stack **stack_a, t_stack **stack_b, int *error)
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
    return (i_count);
}
