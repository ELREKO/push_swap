#include "../includes/push_swap.h"

int main(int argc, char **arg)
{
   
    t_stack *stack_a;
    t_stack *stack_b = NULL;
    char *str_tmp;

    stack_a = ft_read_arg(argc, arg);
    ft_set_index(&stack_a);

    //ft_lst_print(stack_a);

    if (ft_lstsize(stack_a) <= 4)
        str_tmp = ft_itoa(ft_sort_three(&stack_a, &stack_b));   
    else 
        str_tmp = ft_itoa(ft_big_sort(&stack_a, &stack_b));
    //ft_str_print(str_tmp);

   
    free(str_tmp);
    //printf("-----|%s|-------------\n", str_tmp);
    


    // printf("\n Stack_a \n");
    // ft_lst_print(stack_a);

    // printf("\n Stack_b \n");
    // ft_lst_print(stack_b);
    
    ft_free_lst(stack_a);
    ft_free_lst(stack_b);

}
