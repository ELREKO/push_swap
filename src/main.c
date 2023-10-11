#include "../includes/push_swap.h"

int main(int argc, char **arg)
{
   
    t_stack *stack_a;
    t_stack *stack_b = NULL;
    int error = 0;


    stack_a = ft_read_arg(argc, arg);
    
    printf("\n SET -- HIGH NUMMER \n");
    ft_set_index(&stack_a);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);

    printf("\n----- Stack Sort a \n");

    if (argc <= 4)
        printf ("%i\n", ft_sort_three(&stack_a, &error));   
    else 
        ft_push_stack_b(&stack_a, &stack_b, &error);
    printf("\n Stack_a \n");
    ft_lst_print(stack_a);

    printf("\n Stack_b \n");
    ft_lst_print(stack_b);
    
    ft_free_lst(stack_a);
    ft_free_lst(stack_b);





    printf("\n\n");


    
    



    

}
