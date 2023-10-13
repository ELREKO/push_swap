#include "../includes/push_swap.h"

int main(int argc, char **arg)
{
   
    t_stack *stack_a;
    t_stack *stack_b = NULL;

    stack_a = ft_read_arg(argc, arg);
    ft_set_index(&stack_a);

    if (argc <= 4)
        printf ("%i\n", ft_sort_three(&stack_a, &stack_b));   
    else 
        printf ("%i\n", ft_big_sort(&stack_a, &stack_b));
    
    printf("\n Stack_a \n");
    ft_lst_print(stack_a);

    printf("\n Stack_b \n");
    ft_lst_print(stack_b);
    
    ft_free_lst(stack_a);
    ft_free_lst(stack_b);

}
