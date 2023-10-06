#include "../includes/push_swap.h"

int main(int argc, char **arg)
{
   
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = ft_read_arg(argc, arg);
    printf("\n-------------- Rules Check ----------------- \n");
    printf("\n---Befor Swap \n");
    ft_lst_print(stack_a);
    printf("\n---After Swap \n");
    ft_swap_revers(&stack_a, 2);
    ft_lst_print(stack_a);
    printf("\n---Swap again \n");
    //ft_swap(&stack_a);
    ft_lst_print(stack_a);
    ft_free_lst(stack_a);
}
