#include "../includes/push_swap.h"

int main(int argc, char **arg)
{
   
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *stack_tmp;
    int error = 0;


    stack_a = ft_read_arg(argc, arg);
    printf("\n-------------- Rules Check ----------------- \n");
   // printf("\n---Befor Swap \n");
   // ft_lst_print(stack_a);
    stack_b = ft_lst_new(12 , 1 , 1, &error);
    stack_tmp = ft_lst_new(13 , 1, 1, &error);
    ft_lst_add_front(&stack_b, stack_tmp);
    printf("\n--- before push \n");
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);

    printf("\n--- AFTER push --- \n");
    ft_pa(&stack_a, &stack_b, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    if (error != 0)
        ft_throw_error(error, &stack_a, &stack_b);
    printf("\n--- AFTER push --- \n");
    ft_pa(&stack_a, &stack_b, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    if (error != 0)
        ft_throw_error(error, &stack_a, &stack_b);


    printf("\n--- AFTER push --- \n");
    ft_pb(&stack_a, &stack_b, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    if (error != 0)
        ft_throw_error(error, &stack_a, &stack_b);
    printf("\n--- AFTER push --- \n");
    ft_pb(&stack_a, &stack_b, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    if (error != 0)
        ft_throw_error(error, &stack_a, &stack_b);
    printf("\n--- AFTER push --- \n");
    ft_pb(&stack_a, &stack_b, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    if (error != 0)
        ft_throw_error(error, &stack_a, &stack_b);

    printf("\n--- AFTER ROTATE BACKWARD --- \n");
    ft_rra(&stack_a, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    printf("\n BACKWARD Again a \n");
    ft_rra(&stack_a, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);

    printf("\n--- AFTER ROTATE FORWARD --- \n");
    ft_ra(&stack_a, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);
    printf("\n FORWARD AGAIN \n");
    ft_ra(&stack_a, &error);
    printf("\n---stack a \n");
    ft_lst_print(stack_a);
    printf("\n---stack b \n");
    ft_lst_print(stack_b);



    // printf("\n---Swap again \n");
    // ft_swap_revers(&stack_a, 3);
    // ft_lst_print(stack_a);
    // 
    // printf("\n--------after rotate fw \n");
    // ft_rotate_forw(&stack_a, &error);
    // ft_lst_print(stack_a);
    // printf("\n--- rotate fw \n");
    // ft_rotate_forw(&stack_a, &error);
    // ft_lst_print(stack_a);


    // printf("\n--------after backward fw \n");
    // ft_rotate_backw(&stack_a);
    // ft_lst_print(stack_a);
    // printf("\n---backward fw \n");
    // ft_rotate_backw(&stack_a);
    // ft_lst_print(stack_a);
    


    // printf("\n--------after push \n");
    // stack_b = ft_lst_new(12 , 1 , 1, &error);
    // ft_push(&stack_a, &stack_b, &error);
    // ft_push(&stack_a, &stack_b, &error);
    // printf("\n-Stack a\n");
    // ft_lst_print(stack_a);
    // printf("\n-Stack b\n");
    // ft_lst_print(stack_b);

    ft_free_lst(stack_a);
    ft_free_lst(stack_b);
    //ft_free_lst(stack_b);

    printf("\n\n");


    
    



    

}
